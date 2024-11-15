cmake_minimum_required(VERSION 3.25)

project(test-fixture LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable all compiler warnings globally
add_compile_options(-Wall -Wextra -Wpedantic)

# Enable Debugging
set(CMAKE_BUILD_TYPE Debug)

# Enable Verbose Output
set(CMAKE_VERBOSE_MAKEFILE ON)

# Check for Google Test
find_package(GTest REQUIRED)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE GTest::GTest GTest::Main pthread)
