#include <gtest/gtest.h>

#include <loop.h>
#include <little_gauss.h>

using namespace std;

// Common interface for all algorithms
shared_ptr<SumOfSequence> algorithm = nullptr;

TEST(SumOfSequenceGroup, Loop)
{
    // Setup
    algorithm = make_shared<SumOfSequenceLoop>();

    // Exercise
    int sum = algorithm->calculateSum(10);
    
    // Verify
    EXPECT_EQ(1+2+3+4+5+6+7+8+9+10, sum);
}

TEST(SumOfSequenceGroup, LittleGauss)
{
    // Setup
    algorithm = make_shared<SumOfSequenceGauss>();

    // Exercise
    int sum = algorithm->calculateSum(10);
    
    // Verify
    EXPECT_EQ(1+2+3+4+5+6+7+8+9+10, sum);
}
