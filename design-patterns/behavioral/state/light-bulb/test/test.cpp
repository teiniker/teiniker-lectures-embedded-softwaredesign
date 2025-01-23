#include <gtest/gtest.h>
#include <memory>

#include <light_bulb.h>
#include <light_bulb_on.h>
#include <light_bulb_off.h>

using namespace std;

class StateTest : public ::testing::Test
{
protected:
    // system under test
    LightBulb sm;

    void SetUp() override
    {
        // sm is automatically constructed calling LightBulb() constructor
    }
};

TEST_F(StateTest, testInitialState)
{
    shared_ptr<LightBulbState> state = dynamic_pointer_cast<LightBulbOff>(sm.state());
    EXPECT_TRUE(state != nullptr);
}

TEST_F(StateTest, testTurnOff)
{
    // Exercise
    sm.switchOff();

    // Verify
    shared_ptr<LightBulbState> state = dynamic_pointer_cast<LightBulbOff>(sm.state());
    EXPECT_TRUE(state != nullptr);

    bool isCurrentOn = sm.isCurrentOn();
    EXPECT_FALSE(isCurrentOn);
}

TEST_F(StateTest, testTurnOn)
{
    // Exercise 
    sm.switchOn();

    // Verify 
    shared_ptr<LightBulbState> state = dynamic_pointer_cast<LightBulbOn>(sm.state());
    EXPECT_TRUE(state != nullptr);

    bool isCurrentOn = sm.isCurrentOn();
    EXPECT_TRUE(isCurrentOn);
}

TEST_F(StateTest, testTurnOnAndTurnOn)
{
    // Exercise - Turn on once
    sm.switchOn();
    
    // Verify
    shared_ptr<LightBulbState> state1 = dynamic_pointer_cast<LightBulbOn>(sm.state());
    EXPECT_TRUE(state1 != nullptr);
    bool isCurrentOn1 = sm.isCurrentOn();
    EXPECT_TRUE(isCurrentOn1);
        
    // Exercise - Turn on again
    sm.switchOn();

    // Verify 
    shared_ptr<LightBulbState> state2 = dynamic_pointer_cast<LightBulbOn>(sm.state());
    EXPECT_TRUE(state2 != nullptr);

    bool isCurrentOn2 = sm.isCurrentOn();
    EXPECT_TRUE(isCurrentOn2);
}

TEST_F(StateTest, testTurnOnAndTurnOff)
{
    // Exercise - Turn on
    sm.switchOn();
    // Verify
    shared_ptr<LightBulbState> state1 = dynamic_pointer_cast<LightBulbOn>(sm.state());
    EXPECT_TRUE(state1 != nullptr);

    // Exercise - Turn off
    sm.switchOff();
    // Verify
    shared_ptr<LightBulbState> state2 = dynamic_pointer_cast<LightBulbOff>(sm.state());
    EXPECT_TRUE(state2 != nullptr);
}
