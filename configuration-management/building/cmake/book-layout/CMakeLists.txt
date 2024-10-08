cmake_minimum_required(VERSION 3.25)

project(book-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the 'include' directory for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)


