# Test Fixtures: SetUp and TearDown

If we find ourself writing two or more tests that operate on similar data, 
we can use a test fixture. This allows us to reuse the same configuration 
of objects for several different tests.

To create a fixture:

* Derive a class from `testing::Test`. Start its body with `protected:`, as 
    we’ll want to access fixture members from sub-classes.

* Inside the class, we declare any objects we plan to use.

* If necessary, we write a **default constructor** or **SetUp()** function 
    to prepare the objects for each test. 

* If necessary, write a **destructor** or **TearDown()** function to release 
    any resources you allocated in `SetUp()`.

* If needed, we define **subroutines** for our tests to share.


_Example:_ Implementing a test fixture
```C++
class VectorTestFixture : public ::testing::Test 
{
protected:
    vector<int> numbers;

    void SetUp() override 
    {   
        // Initialize the vector before each test
        numbers = {7, 5, 16, 8}; 
    }

    void TearDown() override 
    {
        // Clean up after each test if necessary
    }
};
```

When using a fixture, we use **TEST_F()** instead of `TEST()` as it allows 
us to access objects and subroutines in the test fixture:
```C++
TEST_F(VectorTestFixture, Equals) 
{
    vector<int> expected = {7, 5, 16, 8};
    ASSERT_TRUE(expected == numbers);
}
```

Unlike `TEST()`, in `TEST_F()` the first argument must be the 
**name of the test fixture class** (`_F` stands for **Fixture**). 
No test suite name is specified for this macro.

We must first define a test fixture class before using it in a 
`TEST_F()`, or we will get the compiler error `virtual outside class declaration`.

For each test defined with `TEST_F()`, GoogleTest will create a 
**fresh test fixture** at runtime, immediately initialize it via `SetUp()`, 
run the test, clean up by calling `TearDown()`, and then delete the test 
fixture. 


## Build and Execute the Tests

To execute the test cases, we need to compile the test class and link the testing framework.

### Using GNU Make

_Example:_ Makefile to build the tests
```
CFLAGS= -g -Wall  
LIBS=-lgtest -lgtest_main -pthread
CC=g++

all: run_test

build:
	mkdir -p build

build/test: test.cpp 
	$(CC) $(CFLAGS) test.cpp -o build/test $(LIBS)

run_test: build build/test 
	build/test

clean:
	rm -rf build/
```

After building the test executable, the tests will be started automatically.


### Using CMake 

_Example:_ CMakeList.txt to build the tests
```
cmake_minimum_required(VERSION 3.25)

project(test-fixture LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE gtest gtest_main pthread)
```

Run build and run the tests type:
```
$ cmake -S . -B build
$ cmake --build build

$ ./build/test
```

## References
* [GoogleTest Primer](https://google.github.io/googletest/primer.html)
* [Assertions Reference](https://google.github.io/googletest/reference/assertions.html)


*Egon Teiniker, 2020-2024, GPL v3.0*