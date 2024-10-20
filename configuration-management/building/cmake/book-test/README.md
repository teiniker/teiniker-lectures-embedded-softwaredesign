# CMake: Example With GoogleTests

The given example shows the use of Google Test to test a class. It assumes that 
**GoogleTest is already installed** (header files and libraries are available).

See: [Setup GoogleTest](../../../testing/googletest/README.md)


## Create CMakeLists.txt
In order to build this simple project, we create a file named `CMakeLists.txt` 
in the root of your project directory with the following content:

```CMake
cmake_minimum_required(VERSION 3.25)
project(book-test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test test.cpp book.cpp)

target_link_libraries(test PRIVATE gtest gtest_main pthread)
```

Additional `CMakeLists.txt` components:

* **add_executable(test test.cpp book.cpp)**: Defines an executable target 
    to be built from the specified source files.
    * `test`: The name of the executable that will be generated.
    * `test.cpp`: Contains our GoogleTest-based test cases.
    * `book.cpp`: Contains the implementation of the `Book` class being tested.

* **target_link_libraries(test PRIVATE gtest gtest_main pthread)**: 
    Specifies which libraries to link against when building the target executable.
    * `test`: The target executable defined earlier that we want to link libraries to.
    * `PRIVATE`: means that the linked libraries are only used by the test target 
        and are not propagated to targets that depend on test.
    * Libraries being linked:
        * `gtest`: The main GoogleTest library containing the testing framework.
        * `gtest_main`: Provides the main function for GoogleTest, which initializes 
            and runs the tests. Linking this avoids having to define our own main 
            function in `test.cpp`.
        * `pthread`: The POSIX thread library. GoogleTest may use multithreading 
            features that require this library, especially on Unix-like systems. 
            Linking against `pthread` ensures that threading functionalities work 
            correctly.
        

## Build the Project

We can build our project using the following commands:

```
$ cmake -S . -B build
$ cmake --build build
```

## Run the Tests 

After a successful build, we can run our tests by executing the generated 
executable:

```
./build/test
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