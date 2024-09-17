# GoogleTest Framework

GoogleTest is a testing framework developed by the Testing Technology team with 
Google’s specific requirements and constraints in mind. 

**Tests** use assertions to verify the tested code’s behavior. If a test crashes 
or has a failed assertion, then it fails; otherwise it succeeds.

**Assertions** are statements that check whether a condition is true. An assertion’s 
result can be success, nonfatal failure, or fatal failure. If a fatal failure occurs, 
it aborts the current function; otherwise the program continues normally.

A **test suite** contains one or many tests. You should group your tests into test 
suites that reflect the structure of the tested code. When multiple tests in a test 
suite need to share common objects and subroutines, you can put them into 
a **test fixture class**.

A **test program** can contain multiple test suites.


## Setup 

```
$ cd Downloads/
$ git clone https://github.com/google/googletest
$ cd googletest/
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ sudo make install 
```

```
/usr/local/lib/libgmock.a
/usr/local/include/gtest/gtest.h
```

## Using the Framework

```
$ g++ test.cpp -o test -lgtest -lgtest_main -pthread
```

### EXPECT_* vs. ASSERT_* in GoogleTest

GoogleTest provides two sets of macros for making assertions within tests:

1. **EXPECT_* Macros**:
    * When an `EXPECT_*` assertion fails, GoogleTest records the failure but 
        continues executing the rest of the test.

    * Ideal for situations where we want to check multiple conditions within 
        a single test, even if some of them fail. This allows you to see all 
        the failures in one test run rather than stopping at the first failure.

2. **ASSERT_* Macros**:
    * When an `ASSERT_*` assertion fails, GoogleTest records the failure and 
        immediately aborts the current test.

    * Best used when subsequent test steps depend on the success of the assertion. 
        If the assertion fails, continuing the test could lead to undefined behavior 
        or misleading results.



## References
* [GoogleTest User’s Guide](https://google.github.io/googletest/)

* [YouTube: Introduction to Google Test and Google Mock](https://youtu.be/N8a7IFPAPXs?si=zYIqGOk5jvBA_TX0)

* [YouTube (Google C++ Testing): GTest, GMock Framework Part- 1 : Introduction](https://youtu.be/nbFXI9SDfbk?si=aA0FZvMv6gr2yu7A)

