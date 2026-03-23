cmake_minimum_required(VERSION 3.16)

project(OpenSRX
    VERSION 0.1.0
    DESCRIPTION "C++ library for interfacing with Keyence SR series barcode readers"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_STATIC_LIB "Build a static library instead of a shared library" OFF)
option(BUILD_EXAMPLES "Build example binaries" ON)
option(BUILD_TESTS "Build test targets" ON)

set(OPENSRX_GENERATED_INCLUDE_DIR "${PROJECT_BINARY_DIR}/generated/include")
file(MAKE_DIRECTORY "${OPENSRX_GENERATED_INCLUDE_DIR}/opensrx")
configure_file(
    "${PROJECT_SOURCE_DIR}/include/opensrx/version.hpp.in"
    "${OPENSRX_GENERATED_INCLUDE_DIR}/opensrx/version.hpp"
    @ONLY
)

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
