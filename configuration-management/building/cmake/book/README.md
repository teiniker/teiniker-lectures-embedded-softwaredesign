# CMake: Simple Example

This example shows the minimal configuration for CMake. 
All source files are in one directory.

## Create CMakeLists.txt
In order to build this simple project, we create a file named `CMakeLists.txt` 
in the root of your project directory with the following content:

```CMake
cmake_minimum_required(VERSION 3.25)

project(book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp book.cpp)
```

`CMakeLists.txt` components:

* **cmake_minimum_required(VERSION 3.25)**: Specifies the minimum version of CMake 
    required to build your project. You can adjust this based on your needs.

* **project(YourProjectName LANGUAGES CXX)**: Defines the project name and specifies 
    that it's a C++ project.

* **set(CMAKE_CXX_STANDARD 17)**: Sets the C++ standard to C++17. You can change 
    this to 11, 14, 20, etc., depending on your requirements.

* **set(CMAKE_CXX_STANDARD_REQUIRED True)**: Ensures that the specified C++ standard 
    is strictly enforced.

* **add_executable(YourExecutableName main.cpp)**: Tells CMake to create an executable 
    named YourExecutableName from the `main.cpp` source file.

## Build the Project

Follow these steps to build your project using CMake:

```
$ cmake -S . -B build
$ cd build 
$ make
$ ./test
```

## Run the Executable

After a successful build, we can run the generated executable:

```
$ ./build/main
```

## References

* Rafał Świdziński. **Modern CMake for C++: Discover a better approach to building, testing, and packaging your software**. Packt Publishing, 2022.

*Egon Teiniker, 2020-2024, GPL v3.0*

