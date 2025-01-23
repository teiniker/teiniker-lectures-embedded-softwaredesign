#include <gtest/gtest.h>
#include <memory>

#include <controller.h>
#include <state_bottom.h>
#include <state_upward.h>
#include <state_top.h>
#include <state_downward.h>

using namespace std;

class ControllerTest : public ::testing::Test
{
protected:
    // system under test
    Controller sm;
};

TEST_F(ControllerTest, testInitialState)
{
    shared_ptr<State> state = dynamic_pointer_cast<StateBottom>(sm.state());
    EXPECT_TRUE(state != nullptr);
}

/*
TEST_F(ControllerTest, testTurnOff)
{
    // Exercise
    sm.switchOff();

    // Verify
    shared_ptr<LightBulbState> state = dynamic_pointer_cast<LightBulbOff>(sm.state());
    EXPECT_TRUE(state != nullptr);

    bool isCurrentOn = sm.isCurrentOn();
    EXPECT_FALSE(isCurrentOn);
}

TEST_F(ControllerTest, testTurnOn)
{
    // Exercise 
    sm.switchOn();

    // Verify 
    shared_ptr<LightBulbState> state = dynamic_pointer_cast<LightBulbOn>(sm.state());
    EXPECT_TRUE(state != nullptr);

    bool isCurrentOn = sm.isCurrentOn();
    EXPECT_TRUE(isCurrentOn);
}

TEST_F(ControllerTest, testTurnOnAndTurnOn)
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

TEST_F(ControllerTest, testTurnOnAndTurnOff)
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
*/
