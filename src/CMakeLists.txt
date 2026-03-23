if(BUILD_SHARED_LIB)
    add_library(opensrx_shared SHARED
        app.cpp
    )

    target_include_directories(opensrx_shared
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
    )

    set_target_properties(opensrx_shared PROPERTIES
        OUTPUT_NAME opensrx
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )
endif()

if(BUILD_STATIC_LIB)
    add_library(opensrx_static STATIC
        app.cpp
    )

    target_include_directories(opensrx_static
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
    )

    set_target_properties(opensrx_static PROPERTIES
        OUTPUT_NAME opensrx
    )
endif()

if(BUILD_SHARED_LIB)
    set(OPENSRX_EXAMPLE_LINK_TARGET opensrx_shared PARENT_SCOPE)
else()
    set(OPENSRX_EXAMPLE_LINK_TARGET opensrx_static PARENT_SCOPE)
endif()