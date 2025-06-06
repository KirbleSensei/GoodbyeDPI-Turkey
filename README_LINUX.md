# GoodbyeDPI Turkey - Linux Port

This repository contains a Linux-oriented build of GoodbyeDPI.
The original project targeted Windows and relied on the WinDivert
packet interception driver. The Linux version uses `libpcap` and
raw sockets instead.

## Building

Ensure `gcc` and `libpcap` development headers are installed. Then run:

```bash
cd src
make
```

The resulting binary `goodbyedpi` can be executed as root or with the
necessary capabilities to capture and inject packets.

## Status

This port provides the basic structure needed to run on Linux but does
not yet implement all features of the Windows version.
