#include <gtest/gtest.h>
#include "sequence.h"

class IntegerSequenceTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        IntegerSequence::init(1);
    }
};


TEST_F(IntegerSequenceTest, StaticMembersTest) 
{
    // Exercise
    int value1 = IntegerSequence::next();
    int value2 = IntegerSequence::next();
    int value3 = IntegerSequence::next();
    
    // Verify
    EXPECT_EQ(1, value1);
    EXPECT_EQ(2, value2);
    EXPECT_EQ(3, value3);
}

TEST_F(IntegerSequenceTest, InstancesTest) 
{
    // Exercise
    IntegerSequence obj1;
    IntegerSequence obj2;
    IntegerSequence obj3;
    
    // Verify
    EXPECT_EQ(1, obj1.id());
    EXPECT_EQ(2, obj2.id());
    EXPECT_EQ(3, obj3.id());
}
