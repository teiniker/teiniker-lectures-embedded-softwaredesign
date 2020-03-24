#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <IntegerSequence.h>


TEST_GROUP(IntegerSequenceTestGroup)
{
};

TEST(IntegerSequenceTestGroup, StaticMembersTest)
{
    // Setup
    IntegerSequence::init(1);
    
    // Exercise
    int value1 = IntegerSequence::next();
    int value2 = IntegerSequence::next();
    int value3 = IntegerSequence::next();
    
    // Verify
    CHECK_EQUAL(1, value1);
    CHECK_EQUAL(2, value2);
    CHECK_EQUAL(3, value3);
}


TEST(IntegerSequenceTestGroup, InstancesTest)
{
    // Setup
    IntegerSequence::init(1);
    
    // Exercise
    IntegerSequence obj1 = IntegerSequence();
    IntegerSequence obj2 = IntegerSequence();
    IntegerSequence obj3 = IntegerSequence();
    
    // Verify
    CHECK_EQUAL(1, obj1.id());
    CHECK_EQUAL(2, obj2.id());
    CHECK_EQUAL(3, obj3.id());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
