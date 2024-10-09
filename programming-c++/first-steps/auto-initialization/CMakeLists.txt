cmake_minimum_required(VERSION 3.25)

project(auto-initialization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(auto auto.cpp)
