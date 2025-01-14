#include <gtest/gtest.h>
#include <vector>
#include <memory>

#include <calculator.h>

using namespace std;

class FacadeTest : public ::testing::Test 
{
protected:
    vector<double> data;
    shared_ptr<CalculatorService> calculator;

    void SetUp() override 
    {
        data = {19.0, 13.0, 11.0, 17.0, 23.0};
        calculator = make_shared<CalculatorService>();
    }
};

TEST_F(FacadeTest, MeanValue) 
{
    // Exercise
    double mean = calculator->calculateMeanValue(data);
    
    // Verify
    EXPECT_NEAR((19.0+13.0+11.0+17.0+23.0)/5.0, mean, 0.001);
    EXPECT_EQ("DEBUG: 19.000000 13.000000 11.000000 17.000000 23.000000 ", calculator->getLog().at(0));
}

// TODO: more tests