#include <gtest/gtest.h>
#include <memory>

#include <sm_led.h>

using namespace std;

TEST(StateTest, testInitialState)
{
    EXPECT_EQ(OFF, state); 
    EXPECT_FALSE(is_current_on);
}

TEST(StateTest, testTurnOff)
{
    // Exercise
    sm_led(SWITCH_OFF);

    // Verify
    EXPECT_EQ(OFF, state);
    EXPECT_FALSE(is_current_on);
}


TEST(StateTest, testTurnOn)
{
    // Exercise 
    sm_led(SWITCH_ON);

    // Verify 
    EXPECT_EQ(ON, state);
    EXPECT_TRUE(is_current_on);
}

TEST(StateTest, testTurnOnAndTurnOn)
{
    // Exercise - Turn on once
    sm_led(SWITCH_ON);
    
    // Verify
    EXPECT_EQ(ON, state);
    EXPECT_TRUE(is_current_on);
        
    // Exercise - Turn on again
    sm_led(SWITCH_ON);

    // Verify 
    EXPECT_EQ(ON, state);
    EXPECT_TRUE(is_current_on);
}

TEST(StateTest, testTurnOnAndTurnOff)
{
    // Exercise 
    sm_led(SWITCH_ON);

    // Verify
    EXPECT_EQ(ON, state);

    // Exercise
    sm_led(SWITCH_OFF);

    // Verify
    EXPECT_EQ(OFF, state);
}
