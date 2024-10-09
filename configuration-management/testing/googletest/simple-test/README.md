# Simple GoogleTest

To create a test:

* Use the **TEST()** macro to define and name a test function. These are 
    ordinary C++ functions that don’t return a value.
* In this function, along with any valid C++ statements we want to include, 
    we use the various GoogleTest **assertions** (`EXPECT_*`  and `ASSERT_*` 
    Macros) to check values.
* The test’s result is determined by the assertions; if any assertion in 
    the test fails (either fatally or non-fatally), or if the test crashes, 
    the entire **test fails**. Otherwise, it **succeeds**.


_Example:_ Implementing `TEST()` functions
```C++
TEST(VectorTest, Length) 
{
    vector<int> numbers = {7, 5, 16, 8};
    size_t len = numbers.size();

    ASSERT_EQ(4, len);
}

TEST(VectorTest, IndexOperator) 
{
    vector<int> numbers = {7, 5, 16, 8};

    EXPECT_EQ(7, numbers[0]);
    EXPECT_EQ(5, numbers[1]);
    EXPECT_EQ(16, numbers[2]);
    EXPECT_EQ(8, numbers[3]);
}
```

`TEST()` arguments go from general to specific: 
* The first argument is the **name of the test suite**,
* the second argument is the **test’s name** within the test suite. 

Both names must be valid C++ identifiers, and they should not contain any 
underscores `_`. A test’s full name consists of its containing test suite 
and its individual name.

GoogleTest groups the test results by test suites, so logically related 
tests should be in the same test suite - the first argument to their `TEST()` 
should be the same.


## EXPECT_* vs. ASSERT_* in GoogleTest

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

## Writing the main() Function

Most users should not need to write their own main function and instead link 
with **gtest_main**, which defines a suitable entry point. 

_Example:_ Link test with gtest_main library
```
$ g++ -g -Wall test.cpp -o build/test -lgtest -lgtest_main -pthread
```

If we write our own main function, it should return the value of 
`RUN_ALL_TESTS()`:

_Example:_ Implement a `main()` function
```
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

The `testing::InitGoogleTest()` function parses the command line for GoogleTest 
flags, and removes all recognized flags. This allows the user to control a test 
program’s behavior via various flags.
We must call this function **before calling `RUN_ALL_TESTS()`**, or the flags 
won’t be properly initialized.


## References
* [GoogleTest Primer](https://google.github.io/googletest/primer.html)
* [Assertions Reference](https://google.github.io/googletest/reference/assertions.html)

*Egon Teiniker, 2020-2024, GPL v3.0*