cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
enable_testing()

project(project_row)

# Generate External Libraries
add_subdirectory(./extern/tigr)
add_subdirectory(./extern/stb)

# Generate Tools
add_subdirectory(./tools/ImgToC)

# Generate Resources
add_subdirectory(./resources/images)

# Generate Executable
add_subdirectory(./source)
add_subdirectory(./test)

