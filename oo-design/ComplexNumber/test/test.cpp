#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <ComplexNumber.h>

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, ConstructorTest)
{
	ComplexNumber c = ComplexNumber(1.0, 2.0);
	DOUBLES_EQUAL(1.0, c.re(), 1E-3);
	DOUBLES_EQUAL(2.0, c.im(), 1E-3) ;
}

TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("hello", "hello");
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
