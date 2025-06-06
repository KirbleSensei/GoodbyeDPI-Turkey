#include "windivert_linux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int raw_fd = -1;

HANDLE WinDivertOpen(const char *filter, int layer, int priority, uint64_t flags)
{
    (void)filter; (void)layer; (void)priority; (void)flags;
    raw_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (raw_fd < 0)
        return INVALID_HANDLE_VALUE;
    return (HANDLE)1;
}

BOOL WinDivertRecv(HANDLE h, void *packet, UINT packetLen, UINT *recvLen, WINDIVERT_ADDRESS *addr)
{
    (void)h; (void)packet; (void)packetLen; (void)recvLen; (void)addr;
    return FALSE;
}

BOOL WinDivertSend(HANDLE h, const void *packet, UINT packetLen, const WINDIVERT_ADDRESS *sendAddr, const WINDIVERT_ADDRESS *recvAddr)
{
    (void)h; (void)sendAddr; (void)recvAddr; (void)packet; (void)packetLen;
    return FALSE;
}

void WinDivertShutdown(HANDLE h, int how)
{
    (void)h; (void)how;
}

void WinDivertClose(HANDLE h)
{
    (void)h;
    if (raw_fd >= 0) {
        close(raw_fd);
        raw_fd = -1;
    }
}

BOOL WinDivertHelperParsePacket(const void *packet, UINT packetLen,
                                void **ppIpHdr,
                                void **ppIpv6Hdr,
                                void **ppTcpHdr,
                                void **ppUdpHdr,
                                void **ppData,
                                UINT *pDataLen,
                                void **ppFragmentHdr,
                                void **ppExtHdrs)
{
    (void)ppIpHdr; (void)ppIpv6Hdr; (void)ppTcpHdr; (void)ppUdpHdr;
    (void)ppFragmentHdr; (void)ppExtHdrs;
    if (ppData) *ppData = (void *)packet;
    if (pDataLen) *pDataLen = packetLen;
    return TRUE;
}

void WinDivertHelperCalcChecksums(void *packet, UINT packetLen, const WINDIVERT_ADDRESS *addr, uint64_t flags)
{
    (void)packet; (void)packetLen; (void)addr; (void)flags;
    /* TODO: implement checksum recalculation if needed */
}
