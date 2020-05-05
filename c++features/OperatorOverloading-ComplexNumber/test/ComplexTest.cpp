#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Complex.h>

using namespace std;


TEST_GROUP(ComplexNumberTestGroup)
{
};


TEST(ComplexNumberTestGroup, AddOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    // Exercise
    Complex result = a + b;
    
    // Verify
    CHECK_EQUAL(1.0 + 3.0, result.real());
    CHECK_EQUAL(2.0 + 4.0, result.imag());
}

TEST(ComplexNumberTestGroup, SubOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    // Exercise
    Complex result = a - b;
    
    // Verify
    CHECK_EQUAL(1.0 - 3.0, result.real());
    CHECK_EQUAL(2.0 - 4.0, result.imag());
}

TEST(ComplexNumberTestGroup, EqualsOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(1.0, 2.0);

    // Verify
    CHECK_EQUAL(true, a == b);
    CHECK_EQUAL(false, a != b);
}

TEST(ComplexNumberTestGroup, NotEqualsOperatorTest)
{
    // Setup
    Complex a(1.0, 2.0);
    Complex b(2.0, 1.0);

    // Verify
    CHECK_EQUAL(false, a == b);
    CHECK_EQUAL(true, a != b);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
