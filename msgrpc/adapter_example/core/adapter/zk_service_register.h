#ifndef PROJECT_ZK_SERVICE_REGISTER_H
#define PROJECT_ZK_SERVICE_REGISTER_H

#include <zookeeper/zookeeper.h>
#include <msgrpc/core/adapter/service_register.h>
#include <msgrpc/core/schedule/task_run_on_main_queue.h>
#include <msgrpc/core/adapter/logger.h>
#include <cstdlib>
#include <map>

#include <msgrpc/util/singleton.h>
#include <conservator/ConservatorFrameworkFactory.h>

//TODO: split into .h and .cpp
namespace demo {
    void close_zk_connection_at_exit();

    const string k_services_root = "/services";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    using msgrpc::InstanceInfo;
    using msgrpc::instance_vector_t;
    using msgrpc::instance_set_t;

    typedef ConservatorFramework ZKHandle;
    typedef std::map<std::string, instance_vector_t> services_cache_t;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    namespace {
        boost::optional<msgrpc::service_id_t> str_to_service_id(const string& endpoint) {
            size_t sep = endpoint.find(":");
            if (sep == string::npos) {
                return boost::none;
            }

            string ip = string(endpoint, 0, sep);
            unsigned short port = (unsigned short)strtoul(endpoint.c_str() + sep + 1, NULL, 0);

            return msgrpc::service_id_t(boost::asio::ip::address::from_string(ip), port);
        }


        void strings_to_instances(const vector<string>& instance_strings, instance_vector_t& instances) {
            instance_set_t instance_set;

            for (auto& si : instance_strings) {
                boost::optional<msgrpc::service_id_t> service_id = str_to_service_id(si);

                if (service_id) {
                    InstanceInfo ii;
                    ii.service_id_ = service_id.value();

                    instance_set.insert(ii);
                }
            }

            instances.assign(instance_set.begin(), instance_set.end());
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct ZkServiceRegister : msgrpc::ServiceRegister, msgrpc::Singleton<ZkServiceRegister> {
        bool is_zk_connected(const unique_ptr<ZKHandle> &zk) const {
            return zk && (zk->getState() == ZOO_CONNECTED_STATE);
        }

        static void session_watcher_fn(zhandle_t *zh, int type, int state, const char *path, void *watcher_ctxt) {
            if (type == ZOO_SESSION_EVENT) {

                if (ZOO_CONNECTING_STATE == state) {
                    ___log_warning("zookeeper connection status changed to: ZOO_CONNECTING_STATE");
                } else if (ZOO_CONNECTED_STATE == state) {
                    ___log_warning("zookeeper connection status changed to: ZOO_CONNECTED_STATE");
                } else {
                    ___log_warning("zookeeper connection status changed to: %d", state);
                }
            }
        }

        bool try_connect_zk() {
            if (is_zk_connected(zk_)) {
                return true;
            }

            if ( ! zk_) {
                std::atexit(close_zk_connection_at_exit);
            }

            //TODO: read zk server address from configuration
            auto zk = ConservatorFrameworkFactory().newClient("localhost:2181");
            try {
                zk->start();
            } catch (const char* msg) {
                zk->close();
                ___log_error("catched exception during zk_start: %s", msg);
                return false;
            }

            if ( ! is_zk_connected(zk)) {
                zk->close();
                return false;
            }

            zk->checkExists()->withWatcher(session_watcher_fn, this)->forPath("/");
            zk_ = std::move(zk);
            return true;
        }

        void wait_util_zk_is_connected() {
            bool connected;

            do {
                if ( ! (connected = try_connect_zk())) {
                    ___log_warning("connect to zookeeper failed, will continue retry.");
                }
            } while( ! connected);
        }

        //TODO: peroidically test existence of ephemeral node of service, and create the ephemeral node if need.
        //      should re-register into zk, if zk's data was accidentally deleted.

        //TODO: should periodically fetch services/instances info from zk,
        //      incase miss notifications between handling watch notification and set watch again.

        bool create_ephemeral_node_for_service_instance(const char* service_name, const char* version, const char *end_point) {
            int ret;
            ret = zk_->create()->forPath(k_services_root);
            ret = zk_->create()->forPath(k_services_root + "/" + service_name);

            const clientid_t* session_id = zoo_client_id(zk_->handle());
            if (session_id == nullptr) {
                return false;
            }

            string path = k_services_root + "/" + service_name + "/" + end_point + "@" + std::to_string(session_id->client_id) + "@" + version;
            ret = zk_->create()->withFlags(ZOO_EPHEMERAL)->forPath(path, end_point);

            bool result = (ZOK == ret || ZNODEEXISTS == ret);
            if (!result) {
                ___log_error("register service on zk failed, path: %s, zk_reuslt: %d", path.c_str(), ret);
            }

            return result;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static void service_child_watcher_fn(zhandle_t *zh, int type, int state, const char *path, void *watcher_ctxt) {
            if (type != ZOO_CHILD_EVENT) {
                return;
            }

            ZkServiceRegister* srv_register = (ZkServiceRegister*)watcher_ctxt;

            services_cache_t cache;

            //TODO: compare which services are changed and only fetch changed service
            //vector<string> latest_services = zh->getChildren()->withWatcher(service_child_watcher_fn, this)->forPath(k_services_root);

            vector<string> dummy_paramerters;
            bool fetch_ok = srv_register->try_fetch_services_from_zk(cache, dummy_paramerters);

            if (fetch_ok) {
                msgrpc::Task::dispatch_async_to_main_queue(
                    [srv_register, cache] {
                        srv_register->services_cache_ = cache;
                        //TODO: call user registered listeners
                    }
                );
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static void instance_child_watcher_fn(zhandle_t *zh, int type, int state, const char *path, void *watcher_ctxt) {
            if (type != ZOO_CHILD_EVENT) {
                return;
            }

            assert(strlen(path) > k_services_root.length() + 1 /* / */  && "should only handle path starts with /services/");

            auto* srv_register = (ZkServiceRegister*)watcher_ctxt;
            string service_name = path + k_services_root.length() + 1 /* / */;

            instance_vector_t instances;
            bool fetch_ok = srv_register->fetch_service_instances_from_zk(service_name, instances);

            msgrpc::Task::dispatch_async_to_main_queue(
                [srv_register, service_name, instances] {
                    srv_register->services_cache_[service_name] = instances;
                    //TODO: call user registered listeners
                }
            );
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool try_fetch_services(vector<string>& services) {
            services = zk_->getChildren()->withWatcher(service_child_watcher_fn, this)->forPath(k_services_root);
            return true;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool fetch_service_instances_from_zk(const string& service, instance_vector_t& instances) {
            bool connected = try_connect_zk();
            if (!connected) {
                ___log_error("fetch_service_instances_from_zk failed, can not connect to zk.");
                return false;
            }

            vector<string> instance_strings = zk_->getChildren()->withWatcher(instance_child_watcher_fn, this)->forPath(k_services_root + "/" + service);

            for (auto& service_instance : instance_strings) {
                ___log_debug("    %s instance : %s", service.c_str(), service_instance.c_str());
            }

            strings_to_instances(instance_strings, instances);
            return true;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool try_fetch_services_from_zk(services_cache_t& cache, vector<string>& services) {
            bool connected = try_connect_zk();
            if (!connected) {
                ___log_error("try_fetch_services_from_zk failed, can not connect to zk.");
                return false;
            }

            vector<string> latest_services = zk_->getChildren()->withWatcher(service_child_watcher_fn, this)->forPath(k_services_root);
            services = latest_services;

            for (auto& service : latest_services) {
                ___log_debug("service list: %s", service.c_str());

                instance_vector_t instances;
                bool fetch_ok = fetch_service_instances_from_zk(service, instances);
                if (fetch_ok) {
                    cache[service] = instances;
                }
            }

            return true;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool init() override {
            wait_util_zk_is_connected();
            return try_fetch_services_from_zk(services_cache_, old_services_);
        }

        virtual bool register_service(const char* service_name, const char* version, const char *end_point) override {
            if (service_name == nullptr || end_point == nullptr) {
                return false;
            }

            wait_util_zk_is_connected();

            return create_ephemeral_node_for_service_instance(service_name, version, end_point);
        }

        virtual msgrpc::optional_service_id_t service_name_to_id(const char* service_name, const char* req, size_t req_len) override {
            const auto& iter = services_cache_.find(service_name);
            if (iter == services_cache_.end()) {
                return boost::none;
            }

            instance_vector_t& instances = iter->second;
            if (instances.empty()) {
                return boost::none;
            }

            size_t size = instances.size();
            if (size == 1) {
                return instances[0].service_id_;
            }

            //using round-robin as default load-balance strategy
            size_t next_rr_index = round_robin_map_[service_name];
            round_robin_map_[service_name] = next_rr_index + 1;

            return instances[ next_rr_index % size ].service_id_;
        }

        std::map<string, size_t> round_robin_map_;

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //1. the zk client can only access this services_cache_ during init().
        //2. otherwise, all access to services_cache_ should schedule as task and dispatch into main_queue. like:
        //    msgrpc::Task::dispatch_async_to_main_queue(
        //        [srv_register, cache] {
        //            srv_register->services_cache_ = cache;
        //        }
        //    );
        services_cache_t services_cache_;      //owned by main queue thread

        static vector<string> old_services_;   //owned by zk client thread

        unique_ptr<ZKHandle> zk_;
    };

    void close_zk_connection_at_exit() {
        if (ZkServiceRegister::instance().zk_)
            ZkServiceRegister::instance().zk_->close();
    }
}

#endif //PROJECT_ZK_SERVICE_REGISTER_H
