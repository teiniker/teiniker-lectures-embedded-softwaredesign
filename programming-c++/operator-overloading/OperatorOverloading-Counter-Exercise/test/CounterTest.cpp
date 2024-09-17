#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Counter.h>

#include <stdexcept>

TEST_GROUP(CounterTestGroup)
{
};


TEST(CounterTestGroup, InvalidLimitsTest)
{
    // Verify
    CHECK_THROWS(std::invalid_argument, Counter(5, 11, 10));    // value, min, max
}

TEST(CounterTestGroup, InvalidValueTooLargeTest)
{
    // Verify
    CHECK_THROWS(std::invalid_argument, Counter(11, 0, 10));    // value, min, max
}


TEST(CounterTestGroup, InvalidValueTooSmallTest)
{
    // Verify
    CHECK_THROWS(std::invalid_argument, Counter(-1, 0, 10));    // value, min, max
}


TEST(CounterTestGroup, IncrementOperatorTest)
{
    // Setup
    Counter counter(5, 0, 10);

    // Exercise
    counter++;
    counter++;
    counter++;
    
    // Verify
    CHECK_EQUAL(5+1+1+1, counter.value());
}


TEST(CounterTestGroup, DecrementOperatorTest)
{
    // Setup
    Counter counter(5, 0, 10);

    // Exercise
    counter--;
    counter--;
    counter--;
    
    // Verify
    CHECK_EQUAL(5-1-1-1, counter.value());
}


TEST(CounterTestGroup, MaxIncrementOperatorTest)
{
    // Setup
    Counter counter(3, 0, 5);

    // Exercise
    counter++;
    counter++;
    counter++;
    
    // Verify
    CHECK_EQUAL(5, counter.value());
}

TEST(CounterTestGroup, MinDecrementOperatorTest)
{
    // Setup
    Counter counter(3, 0, 5);

    // Exercise
    counter--;
    counter--;
    counter--;
    counter--;
    
    // Verify
    CHECK_EQUAL(0, counter.value());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
