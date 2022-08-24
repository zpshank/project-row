add_library(gamelib STATIC)
target_include_directories(gamelib 
    PUBLIC 
        ./include
)
target_sources(gamelib 
    PRIVATE
        src/boat.c
)
target_link_libraries(gamelib
    PUBLIC
        tigr
        images
        miniz
)

add_executable(game)
target_sources(game 
    PRIVATE 
        ./main.c
)
target_link_libraries(game
    PRIVATE
        gamelib
)
