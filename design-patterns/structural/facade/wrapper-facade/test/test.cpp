#include <gtest/gtest.h>
#include <vector>
#include <memory>

#include <evaluator.h>

using namespace std;

class WrapperTest : public ::testing::Test 
{
protected:
    vector<double> data;
    shared_ptr<Evaluator> evaluator;

    void SetUp() override 
    {
        data = {19.0, 13.0, 11.0, 17.0, 23.0};
        evaluator = make_shared<Evaluator>(data);
    }
};

TEST_F(WrapperTest, MaxValue) 
{
    // Exercise
    double max = evaluator->max();
    
    // Verify
    EXPECT_NEAR(23.0, max, 0.001);
}

TEST_F(WrapperTest, MinValue) 
{
    // Exercise
    double min = evaluator->min();
    
    // Verify
    EXPECT_NEAR(11.0, min, 0.001);
}

TEST_F(WrapperTest, SumValue) 
{
    // Exercise
    double sum = evaluator->sum();
    
    // Verify
    EXPECT_NEAR(19.0+13.0+11.0+17.0+23.0, sum, 0.001);
}

TEST_F(WrapperTest, MeanValue) 
{
    // Exercise
    double mean = evaluator->mean();
    
    // Verify
    EXPECT_NEAR((19.0+13.0+11.0+17.0+23.0)/5.0, mean, 0.001);
}
