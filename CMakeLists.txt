cmake_minimum_required(VERSION 3.16)

project(OpenSRX
    VERSION 0.1.0
    DESCRIPTION "C++ library for interfacing with Keyence SR series barcode readers"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_STATIC_LIB "Build the static library" OFF)
option(BUILD_EXAMPLES "Build example binaries" ON)
option(BUILD_TESTS "Build test targets" ON)

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
