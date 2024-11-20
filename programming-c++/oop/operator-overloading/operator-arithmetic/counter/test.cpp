#include <gtest/gtest.h>
#include "counter.h"

TEST(CounterTestGroup, IncrementOperatorTest)
{
    // Setup
    Counter counter(5, 0, 10);

    // Exercise
    counter++;
    counter++;
    counter++;
    
    // Verify
    EXPECT_EQ(5+1+1+1, counter.value());
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
    EXPECT_EQ(5-1-1-1, counter.value());
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
    EXPECT_EQ(5, counter.value());
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
    EXPECT_EQ(0, counter.value());
}
