cmake_minimum_required(VERSION 3.25)

project(default-arguments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(arguments arguments.cpp)
