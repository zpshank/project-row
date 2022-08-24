
add_executable(img2c)
target_include_directories(img2c PRIVATE .)
target_link_libraries(img2c
    PRIVATE
        stb
        m
        miniz
)
target_sources(img2c
    PRIVATE
        ./ImgToC.c
)