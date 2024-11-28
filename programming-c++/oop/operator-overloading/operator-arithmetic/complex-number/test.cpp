#include <gtest/gtest.h>
#include "complex.h"

TEST(ComplexNumberTest, AddOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    // Exercise
    Complex result = a + b;
    
    // Verify
    EXPECT_DOUBLE_EQ(1.0 + 3.0, result.real());
    EXPECT_DOUBLE_EQ(2.0 + 4.0, result.imag());
}

TEST(ComplexNumberTest, SubOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    // Exercise
    Complex result = a - b;
    
    // Verify
    EXPECT_DOUBLE_EQ(1.0 - 3.0, result.real());
    EXPECT_DOUBLE_EQ(2.0 - 4.0, result.imag());
}

