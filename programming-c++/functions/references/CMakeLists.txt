cmake_minimum_required(VERSION 3.25)

project(book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(references references.cpp)
