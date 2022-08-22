add_library(gamelib STATIC)
target_include_directories(gamelib 
    PUBLIC 
        ./include
)

target_sources(gamelib 
    PRIVATE
        src/boat.c
)

add_executable(game)
target_link_libraries(game 
    PRIVATE 
        tigr
        gamelib
        images
)

target_sources(game 
    PRIVATE 
        ./main.c
)
