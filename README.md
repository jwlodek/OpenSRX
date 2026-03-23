# OpenSRX

Basic CMake project scaffold with:

- a root `CMakeLists.txt`
- separate shared and static library toggles for sources under `src/`
- public headers under `include/`
- example binaries under `examples/`
- a placeholder `tests/` directory

## Build

```bash
cmake -S . -B build
cmake --build build
./build/examples/opensrx_example
```

## Options

```bash
cmake -S . -B build -DBUILD_STATIC_LIB=ON
cmake -S . -B build -DBUILD_SHARED_LIB=OFF -DBUILD_STATIC_LIB=ON
cmake -S . -B build -DBUILD_TESTS=OFF
cmake -S . -B build -DBUILD_EXAMPLES=OFF
```

At least one of `BUILD_SHARED_LIB` or `BUILD_STATIC_LIB` must be `ON`.