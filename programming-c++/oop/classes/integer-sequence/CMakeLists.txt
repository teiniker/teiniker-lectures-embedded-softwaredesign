cmake_minimum_required(VERSION 3.25)

project(integer-sequence LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test test.cpp sequence.cpp)

target_link_libraries(test PRIVATE gtest gtest_main pthread)
