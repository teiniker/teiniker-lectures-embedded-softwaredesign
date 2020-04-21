#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Calculator.h>
#include <CalculatorFast.h>
#include <CalculatorSlow.h>


using namespace std;

TEST_GROUP(CalculatorTestGroup)
{
};


TEST(CalculatorTestGroup, CalculatorSlowTest)
{
    // Setup:
    // Since we don't know anything about the concrete implementation, we must allocate
    // objects on the heap and access them through references and pointers. 
    // Note that the pointer calc is of type "Calculator" (abstract) while the object
    // the is of type "ClaculatorSlow" (concrete).
    Calculator* calc = new CalculatorSlow();
    
    // Verify
    CHECK_EQUAL(1+2+3+4+5, calc->sumOfSequence(5));

    // Teardown 
    delete calc;
}

TEST(CalculatorTestGroup, CalculatorFastTest)
{
    // Setup
    // Note that the pointer calc is of type "Calculator" (abstract) while the object
    // the is of type "ClaculatorFast" (concrete).
    Calculator* calc = new CalculatorFast();
    
    // Verify
    CHECK_EQUAL(1+2+3+4+5, calc->sumOfSequence(5));

    // Teardown 
    delete calc;
}


TEST(CalculatorTestGroup, DynamicCastTest)
{
    // Setup
    Calculator* calc = new CalculatorFast();
    
    // If we want to use a method whch is only provided by the subclass,
    // we can use the "dynamic_cast<>" operator.
    // We convert the type of the pointer (not the type of the object)!
    CalculatorFast* fast = dynamic_cast<CalculatorFast*>(calc);
    
    // Verify
    CHECK_EQUAL(1+2+3+4+5, fast->sumOfSequence(5));

    // Teardown 
    delete calc;
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
