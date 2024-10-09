cmake_minimum_required(VERSION 3.25)

project(classes-date LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test test.cpp date.cpp)

target_link_libraries(test PRIVATE gtest gtest_main pthread)
