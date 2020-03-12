# C++ Unit Tests 

In order to be able to implement tests in C ++ Unit, we use the 
**CppUTest** framework.
CppUTest is written in C++ but is used in C and C++ projects and 
frequently used in embedded systems but it works for any C/C++ project.

## Write a Test Class

Each test class has the following structure:
* Include the test framework header files (**TestHarness.h** and **CommandLineTestRunner.h**)
* Define a test group using the **TEST_GROUP()** macro. Each suite has a unique name.
Within a test group we can define the **setup()** and **teardown()** methods. 
Every test group can have a setup and a teardown method. The setup method is called before each 
test and the teardown method is called after each test.	
* Test cases are implemented using a **TEST()** macro which are attached with the TEST_GROUP
via the TEST_GROUP's name. 
* The test runner that executes all test cases is called in the main () 
function. Thus, the test class can be executed from the console like a 
normal application.

```C++
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

TEST_GROUP(TestGroup)
{
    void setup()
    {
        // Setup
    }

    void teardown()
    {
        // Tear down
    }    
};

TEST(TestGroup, TestCaseName)
{
    // Exercise
		
    // Verify
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
```

## Verify the Results

The verification is carried out by assert macros, which carry out 
different types of checks:

* **CHECK(boolean condition)** - checks any boolean result.
* **FAIL(text)** - always fails
* **CHECK_TEXT(boolean condition, text)** - checks any boolean result and prints text on failure.   
* **CHECK_EQUAL(expected, actual)** - checks for equality between entities using ==. 
* **CHECK_THROWS(expected_exception, expression)** - checks if expression throws expected_exception (e.g. std::exception).

* **STRCMP_EQUAL(expected, actual)** - checks const char* strings for equality using strcmp().
* **STRNCMP_EQUAL(expected, actual, length)** - checks const char* strings for equality using strncmp(). 
* **STRCMP_NOCASE_EQUAL(expected, actual)** - checks const char* strings for equality, not considering case.
* **STRCMP_CONTAINS(expected, actual)** - checks whether const char* actual contains const char* expected.

* **LONGS_EQUAL(expected, actual)** - compares two numbers.
* **UNSIGNED_LONGS_EQUAL(expected, actual)** - compares two positive numbers.
* **BYTES_EQUAL(expected, actual)** - compares two numbers, eight bits wide.
* **POINTERS_EQUAL(expected, actual)** - compares two pointers.
* **DOUBLES_EQUAL(expected, actual, tolerance)** - compares two floating point numbers within some tolerance

* **MEMCMP_EQUAL(expected, actual, size)** - compares two areas of memory


## Memory Leak Detection
CppUTest has memory leak detection support on a per-test level. 
This means that it automatically checks whether the memory at the end of 
a test is the same as at the beginning of the test.

Explained another way:
* Pre-setup -> Record the amount of memory used
* Do setup
* Run test
* Do teardown
* Post-teardown -> Check whether the amount of memory is the same

```C++
TEST(TestGroup, MemoryLeakTest)
{
	// Setup
	int *array = new int[7];
	
	// Tear down
	//delete[] array;
}

```

If we run this test case we get something like:
```
test/CppTest.cpp:90: error: Failure in TEST(TestGroup, MemoryLeakTest)
	Memory leak(s) found.
Alloc num (4) Leak size: 28 Allocated at: test/CppTest.cpp and line: 93. Type: "new []"
	Memory: <0x5542c0> Content:
    0000: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 |................|
    0010: 00 00 00 00 00 00 00 00  00 00 00 00             |............|
```

## Setup

There are several ways to setup CppUTest. 
We simply use the package management:

```
$ apt-get install cpputest

$ pkg-config cpputest --libs --cflags
-lstdc++ -lCppUTest -lCppUTestExt
```

After installation we can compile and execute test classes with the 
following commands (which can be found in the Makefile):
```
$ g++ -g -Wall -I include -c test/SprintfTest.cpp -o build/SprintfTest.o
$ g++ build/SprintfTest.o -o build/SprintfTest -lstdc++ -lCppUTest -lCppUTestExt

$ build/SprintfTest
.....
OK (5 tests, 5 ran, 11 checks, 0 ignored, 0 filtered out, 1 ms)
```

## References
[CppUTest Framework](https://cpputest.github.io/)

*Egon Teiniker, 2020, GPL v3.0*
