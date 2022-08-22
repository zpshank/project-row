function(register_image target_dependency image)

    get_filename_component(image_name ${image} NAME_WLE)
    set(image_target img_${image_name})
    set(image_out ${image_name}.h)
    set(image_out_dir ${CMAKE_CURRENT_BINARY_DIR}/images)

    # Make Directory
    file(MAKE_DIRECTORY ${image_out_dir})

    # Execute img2c
    add_custom_target(
        ${image_target}
        $<TARGET_FILE:img2c> 
            ${CMAKE_CURRENT_LIST_DIR}/${image} 
            ${image_out_dir}/${image_out}
    )

    # Setup dependencies
    add_dependencies(${target_dependency} ${image_target})
    target_include_directories(${target_dependency}
        INTERFACE
            ${CMAKE_CURRENT_BINARY_DIR}
    )

endfunction()