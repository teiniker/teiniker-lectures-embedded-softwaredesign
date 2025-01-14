cmake_minimum_required(VERSION 3.25)

project(wrapper-facade LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the 'include' directory for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Enable compiler warnings globally, activate debugging, and check for gtest
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
find_package(GTest REQUIRED)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)


