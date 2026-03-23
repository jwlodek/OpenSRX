include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(opensrx_tests
    TestOpenSRX.cpp
    app_test.cpp
)

target_link_libraries(opensrx_tests
    PRIVATE
        opensrx
        GTest::gtest
        GTest::gmock
        GTest::gtest_main
)
gtest_discover_tests(opensrx_tests)
