# Assumes corresponding test_name.c file exists in current directory
function(register_test test_name)

    add_executable(${test_name})
    target_include_directories(${test_name} 
        PRIVATE 
            ${CMAKE_CURRENT_LIST_DIR}
    )
    target_sources(${test_name} 
        PRIVATE 
            ${CMAKE_CURRENT_LIST_DIR}/${test_name}.c
    )
    target_link_libraries(${test_name} 
        PRIVATE 
            gamelib
    )
    add_test(NAME ${test_name} COMMAND ${test_name})

endfunction()