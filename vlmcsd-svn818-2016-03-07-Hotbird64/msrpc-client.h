/*
 * msrpc-client.h
 */

#ifndef MSRPC_CLIENT_H_
#define MSRPC_CLIENT_H_

#include "types.h"
#include <setjmp.h>

typedef int_fast8_t RpcCtx;
typedef RPC_STATUS RpcStatus;

RpcCtx connectToAddress(char *const addr, const int AddressFamily_unused, int_fast8_t showHostName);
int_fast8_t isDisconnected(const RpcCtx handle);
RpcStatus rpcBindClient(const RpcCtx handle, const int_fast8_t verbose);
RpcStatus rpcSendRequest(const RpcCtx handle, BYTE* KmsRequest, size_t requestSize, BYTE **KmsResponse, size_t *responseSize);
RpcStatus closeRpc(RpcCtx s);

#define INVALID_RPCCTX ((RpcCtx)~0)

#endif /* MSRPC_CLIENT_H_ */
