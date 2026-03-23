cmake_minimum_required(VERSION 3.16)

project(OpenSRX
    VERSION 0.1.0
    DESCRIPTION "Basic CMake project scaffold"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIB "Build the shared library" ON)
option(BUILD_STATIC_LIB "Build the static library" OFF)
option(BUILD_EXAMPLES "Build example binaries" ON)
option(BUILD_TESTS "Build test targets" ON)

if(NOT BUILD_SHARED_LIB AND NOT BUILD_STATIC_LIB)
    message(FATAL_ERROR "At least one of BUILD_SHARED_LIB or BUILD_STATIC_LIB must be ON")
endif()

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()