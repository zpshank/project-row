find_package(OpenGL REQUIRED)

add_library(tigr STATIC)
target_include_directories(tigr PUBLIC .)
target_link_libraries(tigr
    PUBLIC
        OpenGL::GL
        OpenGL::GLU
)

if(UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(tigr
        PUBLIC 
            ${X11_LIBRARIES}
    )
endif()

target_sources(tigr PRIVATE ./tigr.c)

