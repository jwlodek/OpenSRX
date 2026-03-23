add_executable(opensrx_example
    hello_opensrx.cpp
)

target_link_libraries(opensrx_example
    PRIVATE
        ${OPENSRX_EXAMPLE_LINK_TARGET}
)