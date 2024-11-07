# Using GoogleTest with CTest

CTest is a testing tool integrated with CMake that simplifies the process 
of running and managing tests in C++ projects. It automates test execution,
provides detailed reporting, supports parallel test runs, and integrates 
well with continuous integration (CI) systems. 

CTest allows developers to organize tests, set up timeouts, and filter 
or selectively run tests, making it easier to handle complex testing 
environments while ensuring code quality and reliability.

_Example:_ Configure ctest in the `CMakeLists.txt` file
```
cmake_minimum_required(VERSION 3.25)
project(simple-test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(test_executable test.cpp)
target_link_libraries(test_executable PRIVATE gtest gtest_main pthread)

# Enable testing for the project
enable_testing()

# Add a test, associating the test executable with CTest
add_test(NAME SimpleTest COMMAND test_executable)
```

`CMakeLists.txt` components:

* **enable_testing()**: This command enables the testing functionality in CMake, which is necessary to run tests with ctest.

* **add_test(NAME SimpleTest COMMAND test_executable)**: This registers our executable as a test that ctest can run. We can replace `SimpleTest` with 
a more descriptive name, and `test_executable` refers to the binary created by the `add_executable()` command.


To build and run the tests, type:
```
$ cmake -S . -B build
$ cd build 
$ make
$ ctest
```

`ctest` can also be started in **verbose mode** using the `-V` flag.


## References
* [YouTube: Do you even test? (your code with CMake)](https://youtu.be/pxJoVRfpRPE?si=j6v2g1hNGbn0Rv3u)

* [Testing With CMake and CTest](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html)

*Egon Teiniker, 2020-2024, GPL v3.0*