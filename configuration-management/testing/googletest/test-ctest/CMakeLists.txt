cmake_minimum_required(VERSION 3.25)

project(simple-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test_executable test.cpp)
target_link_libraries(test_executable PRIVATE gtest gtest_main pthread)

# Enable testing for the project
enable_testing()

# Add a test, associating the test executable with CTest
add_test(NAME SimpleTest COMMAND test_executable)