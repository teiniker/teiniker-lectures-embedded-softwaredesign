#include <gtest/gtest.h>
#include <cmath>
#include "complex.h"

using namespace std;

TEST(ComplexNumberTest, CreateFromCartesian) 
{
    // Setup
    ComplexNumber* complex = ComplexNumber::createFromCartesian(1.0, 2.0);

    // Exercise + Verify
    EXPECT_NEAR(1.0, complex->re(), 0.0001);
    EXPECT_NEAR(2.0, complex->im(), 0.0001);

    // Teardown
    delete complex;
}

TEST(ComplexNumberTest, CreateFromPolar) 
{
    // Setup
    ComplexNumber* complex = ComplexNumber::createFromPolar(sqrt(2.0), M_PI/4.0);

    // Exercise + Verify
    EXPECT_NEAR(1.0, complex->re(), 0.0001);
    EXPECT_NEAR(1.0, complex->im(), 0.0001);

    // Teardown
    delete complex;
}
