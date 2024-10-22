# Define minimal required version of CMake.
cmake_minimum_required(VERSION "3.25")

# Project definition
project(
	blink_baremetal
	VERSION 1.0
	LANGUAGES C CXX ASM
)

# Include the definition of the slc_blink_baremetal target,
# which contains the content of the SLC project
include(blink_baremetal.cmake)

add_executable(blink_baremetal
    # Add additional sources here
)

target_include_directories(blink_baremetal PUBLIC
    # Add additional include paths here
)

target_compile_definitions(blink_baremetal PUBLIC
    # Add additional macros here
)

target_compile_options(blink_baremetal PUBLIC
    # Set additional compiler flags here
)

target_link_options(blink_baremetal PUBLIC
    # Set additional linker flags here
)

# Link with the content defined in the SLC project
target_link_libraries(blink_baremetal PRIVATE
    slc_blink_baremetal
)

# Include managed project content if available
include(blink_baremetal_project.cmake OPTIONAL RESULT_VARIABLE managed_project)
if(managed_project)
    message(STATUS "Using managed project content from ${managed_project}")
endif()

# Force the gcc linker command
set_target_properties(blink_baremetal PROPERTIES LINKER_LANGUAGE C)

# Create .bin, .hex and .s37 artifacts after building the project
add_custom_command(TARGET blink_baremetal
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O srec "$<TARGET_FILE:blink_baremetal>" "$<TARGET_FILE_DIR:blink_baremetal>/$<TARGET_FILE_BASE_NAME:blink_baremetal>.s37"
    COMMAND ${CMAKE_OBJCOPY} -O ihex "$<TARGET_FILE:blink_baremetal>" "$<TARGET_FILE_DIR:blink_baremetal>/$<TARGET_FILE_BASE_NAME:blink_baremetal>.hex"
    COMMAND ${CMAKE_OBJCOPY} -O binary "$<TARGET_FILE:blink_baremetal>" "$<TARGET_FILE_DIR:blink_baremetal>/$<TARGET_FILE_BASE_NAME:blink_baremetal>.bin" 
)

# Run post-build pipeline to perform additional post-processing
if(post_build_command)
add_custom_command(TARGET blink_baremetal
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
    COMMAND ${post_build_command}
)
endif()