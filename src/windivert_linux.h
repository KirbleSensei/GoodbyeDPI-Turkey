#ifndef WINDIVERT_LINUX_H
#define WINDIVERT_LINUX_H
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

typedef void* HANDLE;
#define INVALID_HANDLE_VALUE NULL

typedef struct {
    uint32_t IfIdx;
    uint32_t SubIfIdx;
} WINDIVERT_ADDRESS, *PWINDIVERT_ADDRESS;

typedef unsigned int UINT;
typedef unsigned char BYTE;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define WINDIVERT_LAYER_NETWORK 0
#define WINDIVERT_SHUTDOWN_BOTH 0

HANDLE WinDivertOpen(const char *filter, int layer, int priority, uint64_t flags);
BOOL WinDivertRecv(HANDLE handle, void *packet, UINT packetLen, UINT *recvLen, WINDIVERT_ADDRESS *addr);
BOOL WinDivertSend(HANDLE handle, const void *packet, UINT packetLen, const WINDIVERT_ADDRESS *sendAddr, const WINDIVERT_ADDRESS *recvAddr);
void WinDivertShutdown(HANDLE handle, int how);
void WinDivertClose(HANDLE handle);

BOOL WinDivertHelperParsePacket(const void *packet, UINT packetLen,
                                void **ppIpHdr,
                                void **ppIpv6Hdr,
                                void **ppTcpHdr,
                                void **ppUdpHdr,
                                void **ppData,
                                UINT *pDataLen,
                                void **ppFragmentHdr,
                                void **ppExtHdrs);

void WinDivertHelperCalcChecksums(void *packet, UINT packetLen, const WINDIVERT_ADDRESS *addr, uint64_t flags);

#endif
