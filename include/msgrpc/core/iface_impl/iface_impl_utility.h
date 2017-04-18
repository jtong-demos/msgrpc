#ifndef MSGRPC_IFACE_IMPL_UTILITY_H
#define MSGRPC_IFACE_IMPL_UTILITY_H

#include <msgrpc/core/cell/cell.h>

namespace msgrpc {

    template<typename REQ, typename RSP>
    msgrpc::Cell<RSP>* call_sync_impl(void(*f)(const REQ &, RSP &), const REQ &req) {
        auto* rsp_cell = new msgrpc::Cell<RSP>();

        RSP rsp;
        f(req, rsp);

        rsp_cell->set_value(rsp);
        return rsp_cell;
    }

    template<typename T>
    Cell<T>* failed_cell_with_reason(RpcContext &ctxt, const RpcResult& failed_reason) {
        Cell<T>* cell = new Cell<T>();
        cell->set_failed_reason(failed_reason);
        ctxt.track(cell);
        return cell;
    }
}

#endif //MSGRPC_IFACE_IMPL_UTILITY_H
