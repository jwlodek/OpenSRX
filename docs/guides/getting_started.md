# Getting Started {#getting_started}

OpenSRX is a C++ library that lets you control Keyence SR-X series barcode
readers programmatically. It supports two communication backends:

- **SocketInterface** – TCP/IP over Ethernet (default port 9004)
- **SerialInterface** – RS-232 serial link

## Prerequisites

- A C++17 compiler (GCC ≥ 9, Clang ≥ 10, MSVC ≥ 19.20)
- CMake ≥ 3.16
- An internet connection during the first build (dependencies are fetched
  automatically via CMake `FetchContent`)

## Quick Start

```bash
git clone https://github.com/jwlodek/OpenSRX.git
cd OpenSRX
cmake -S . -B build
cmake --build build
```

After building, the example binary is at `build/examples/opensrx_example`.
