# Define minimal required version of CMake.
cmake_minimum_required(VERSION "3.25")

# Project definition
project(
	Z3Switch
	VERSION 1.0
	LANGUAGES C CXX ASM
)

# Include the definition of the slc_Z3Switch target,
# which contains the content of the SLC project
include(Z3Switch.cmake)

add_executable(Z3Switch
    # Add additional sources here
)

target_include_directories(Z3Switch PUBLIC
    # Add additional include paths here
)

target_compile_definitions(Z3Switch PUBLIC
    # Add additional macros here
)

target_compile_options(Z3Switch PUBLIC
    # Set additional compiler flags here
)

target_link_options(Z3Switch PUBLIC
    # Set additional linker flags here
)

# Link with the content defined in the SLC project
target_link_libraries(Z3Switch PRIVATE
    slc_Z3Switch
)

# Include managed project content if available
include(Z3Switch_project.cmake OPTIONAL RESULT_VARIABLE managed_project)
if(managed_project)
    message(STATUS "Using managed project content from ${managed_project}")
endif()

# Force the gcc linker command
set_target_properties(Z3Switch PROPERTIES LINKER_LANGUAGE C)

# Create .bin, .hex and .s37 artifacts after building the project
add_custom_command(TARGET Z3Switch
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O srec "$<TARGET_FILE:Z3Switch>" "$<TARGET_FILE_DIR:Z3Switch>/$<TARGET_FILE_BASE_NAME:Z3Switch>.s37"
    COMMAND ${CMAKE_OBJCOPY} -O ihex "$<TARGET_FILE:Z3Switch>" "$<TARGET_FILE_DIR:Z3Switch>/$<TARGET_FILE_BASE_NAME:Z3Switch>.hex"
    COMMAND ${CMAKE_OBJCOPY} -O binary "$<TARGET_FILE:Z3Switch>" "$<TARGET_FILE_DIR:Z3Switch>/$<TARGET_FILE_BASE_NAME:Z3Switch>.bin" 
)

# Run post-build pipeline to perform additional post-processing
if(post_build_command)
add_custom_command(TARGET Z3Switch
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
    COMMAND ${post_build_command}
)
endif()