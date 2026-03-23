if(BUILD_STATIC_LIB)
    set(OPENSRX_LIBRARY_TYPE STATIC)
else()
    set(OPENSRX_LIBRARY_TYPE SHARED)
endif()

add_library(opensrx ${OPENSRX_LIBRARY_TYPE}
    app.cpp
)

target_include_directories(opensrx
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

if(NOT BUILD_STATIC_LIB)
    set_target_properties(opensrx PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )
endif()