#include <gtest/gtest.h>

#include "calculator_fast.h"
#include "calculator_slow.h"

using namespace std;


TEST(CalculatorTest, CalculatorSlowTest)
{
    // Setup
    Calculator* calc = new CalculatorSlow();    // Upcasting
    
    // Exercise + Verify
    EXPECT_EQ(1+2+3+4+5, calc->sumOfSequence(5));

    // Teardown 
    delete calc;
}

TEST(CalculatorTest, CalculatorFastTest)
{
    // Setup
    Calculator* calc = new CalculatorFast();    // Upcasting
    
    // Exercise + Verify
    EXPECT_EQ(1+2+3+4+5, calc->sumOfSequence(5));

    // Teardown 
    delete calc;
}

TEST(CalculatorTest, DynamicCastTest)
{
    // Setup
    Calculator* calc = new CalculatorFast();                    // Upcasting
    CalculatorFast* fast = dynamic_cast<CalculatorFast*>(calc); // Downcasting
    
    // Verify
    ASSERT_NE(nullptr, fast);
    EXPECT_EQ(1+2+3+4+5, fast->sumOfSequence(5));

    // Teardown 
    delete calc;
}
