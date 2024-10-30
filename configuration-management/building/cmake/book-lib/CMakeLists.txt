cmake_minimum_required(VERSION 3.25)

project(book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(book STATIC book.cpp)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE book)
