#include <gtest/gtest.h>
#include <memory>

#include <led.h>
#include <state_on.h>
#include <state_off.h>

using namespace std;

class StateTest : public ::testing::Test
{
protected:
    // system under test
    Led sm;

    void SetUp() override
    {
        // sm is automatically constructed calling LightBulb() constructor
    }
};

TEST_F(StateTest, testInitialState)
{
    EXPECT_TRUE(dynamic_pointer_cast<StateOff>(sm.state()) != nullptr);
}

TEST_F(StateTest, testTurnOff)
{
    // Exercise
    sm.switchOff();

    // Verify
    EXPECT_TRUE(dynamic_pointer_cast<StateOff>(sm.state()) != nullptr);
    EXPECT_FALSE(sm.isCurrentOn());
}

TEST_F(StateTest, testTurnOn)
{
    // Exercise 
    sm.switchOn();

    // Verify 
    EXPECT_TRUE(dynamic_pointer_cast<StateOn>(sm.state()) != nullptr);
    EXPECT_TRUE(sm.isCurrentOn());
}

TEST_F(StateTest, testTurnOnAndTurnOn)
{
    // Exercise - Turn on once
    sm.switchOn();
    
    // Verify
    EXPECT_TRUE(dynamic_pointer_cast<StateOn>(sm.state()) != nullptr);
    EXPECT_TRUE(sm.isCurrentOn());
        
    // Exercise - Turn on again
    sm.switchOn();

    // Verify 
    EXPECT_TRUE(dynamic_pointer_cast<StateOn>(sm.state()) != nullptr);
    EXPECT_TRUE(sm.isCurrentOn());
}

TEST_F(StateTest, testTurnOnAndTurnOff)
{
    // Exercise - Turn on
    sm.switchOn();

    // Verify
    EXPECT_TRUE(dynamic_pointer_cast<StateOn>(sm.state()) != nullptr);
    EXPECT_TRUE(sm.isCurrentOn());

    // Exercise - Turn off
    sm.switchOff();

    // Verify
    EXPECT_TRUE(dynamic_pointer_cast<StateOff>(sm.state()) != nullptr);
    EXPECT_FALSE(sm.isCurrentOn());
}
