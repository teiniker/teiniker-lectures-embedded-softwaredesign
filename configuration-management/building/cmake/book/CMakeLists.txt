cmake_minimum_required(VERSION 3.25)

project(book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp book.cpp)

# Optional: Customizing the Build
# target_compile_options(main PRIVATE -Wall -g)
# include_directories(include)
# target_link_libraries(YourExecutableName PRIVATE SomeLibrary)
