cmake_minimum_required(VERSION 3.25)

project(counter LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable compiler warnings globally, activate debugging, and check for gtest
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
find_package(GTest REQUIRED)

add_executable(test test.cpp counter.cpp)

target_link_libraries(test PRIVATE gtest gtest_main pthread)
