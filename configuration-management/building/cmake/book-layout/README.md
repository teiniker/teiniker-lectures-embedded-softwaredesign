# CMake: Example with Project Layout

This example shows the use of a project layout as it is used in somewhat larger projects.

The project is divided into the following folders:
* `src`: Contains the implementations of C++ classes and functions (`*.cpp` files) 
    for the production code.

* `include`: Contains all header files used outside of `src' to declare the API 
    of the C++ implementations.

* `test`: Contains the implementations of the test cases. The tests are only of 
    interest during development and are not delivered with the product.

* `build`: As before, it contains all artifacts of the build process.
    This folder will not be checked into the source code repository.

```
.
├── build
├── CMakeLists.txt
├── include
│   └── book.h
├── README.md
├── src
│   ├── book.cpp
│   └── CMakeLists.txt
└── test
    ├── CMakeLists.txt
    └── test.cpp
```

A `docs` folder is also often used to store files that are used for documentation 
purposes. 

Both the `src`, `include`, and `test` folders can have additional subdirectories 
to separate modules from each other.

## Create CMakeLists.txt
In order to build this simple project, we create a file named `CMakeLists.txt` 
in the root of your project directory with the following content:

```CMake
cmake_minimum_required(VERSION 3.25)
project(book-test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)
```

Additional `CMakeLists.txt` components:

* **include_directories(${PROJECT_SOURCE_DIR}/include)**: Adds the include directory 
    located at the project's root to the list of directories that the compiler should 
    search for header files.
    `${PROJECT_SOURCE_DIR}` is a variable that points to the directory containing the 
    top-level `CMakeLists.txt` file.

* **add_subdirectory(src)** and **add_subdirectory(test)**:
    Incorporates the `src` and `test` subdirectories into the build process. Each 
    of these subdirectories is expected to contain its own `CMakeLists.txt` file 
    that defines how to build the components within them.

    CMake looks for a `CMakeLists.txt` file within each specified subdirectory 
    (`src/CMakeLists.txt` and `test/CMakeLists.txt`) and processes them accordingly.

### src/CMakeList.txt

```
add_library(book STATIC book.cpp)
```

All implementation files in `src` will be build into a static library named `book`.

### test/CMakeList.txt

```
add_executable(test test.cpp)
target_link_libraries(test PRIVATE book gtest gtest_main pthread)
```

The test cases will be compiled and linked with both the `book` library and the 
Google Test libraries (`gtest`, `gtest_main`, and `pthread`).


## Build the Project

We can build our project using the following commands:

```
$ cmake -S . -B build
$ cd build 
$ make
```

## Run the Tests 

After a successful build, we can run our tests by executing the generated 
executable:

```
$ ./test
Running main() from /home/student/Downloads/googletest/googletest/src/gtest_main.cc
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from BookTest
[ RUN      ] BookTest.Constructor
[       OK ] BookTest.Constructor (0 ms)
[ RUN      ] BookTest.ConstructorWithNew
[       OK ] BookTest.ConstructorWithNew (0 ms)
[ RUN      ] BookTest.ToJson
[       OK ] BookTest.ToJson (0 ms)
[----------] 3 tests from BookTest (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
```

GoogleTest will execute all defined test cases and provide a summary of the results, 
including any failures or errors.


## References

* Rafał Świdziński. **Modern CMake for C++: Discover a better approach to building, testing, and packaging your software**. Packt Publishing, 2022.
	
*Egon Teiniker, 2020-2024, GPL v3.0*