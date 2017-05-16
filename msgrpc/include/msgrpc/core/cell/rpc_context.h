#ifndef PROJECT_RPC_CONTEXT_H
#define PROJECT_RPC_CONTEXT_H

#include <list>
#include <msgrpc/core/cell/updatable.h>

namespace msgrpc {

    struct RpcContext {
        ~RpcContext() {
            for (auto *r: release_list_) {
                delete r;
            }
        }

        template<typename T>
        T track(T cell) {
            release_list_.push_back(static_cast<Updatable *>(cell));
            return cell;
        }

        std::list<Updatable *> release_list_;
    };
}

#endif //PROJECT_RPC_CONTEXT_H
