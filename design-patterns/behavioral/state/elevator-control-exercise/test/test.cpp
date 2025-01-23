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
    EXPECT_TRUE(dynamic_pointer_cast<StateBottom>(sm.state()) != nullptr);
}


TEST_F(ControllerTest, testUpwardTopDownwardBottom)
{
    // Exercise and Verify
    sm.pushUpButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateUpward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::FORWARD);

    sm.endSwitchTop();
    EXPECT_TRUE(dynamic_pointer_cast<StateTop>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::STOP);

    sm.pushDownButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateDownward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::BACKWARD);

    sm.endSwitchBottom();
    EXPECT_TRUE(dynamic_pointer_cast<StateBottom>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::STOP);
}


TEST_F(ControllerTest, testUpwardDownwardUpwardTop)
{
    // Exercise and Verify
    sm.pushUpButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateUpward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::FORWARD);

    sm.pushDownButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateDownward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::BACKWARD);

    sm.pushUpButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateUpward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::FORWARD);

    sm.endSwitchTop();
    EXPECT_TRUE(dynamic_pointer_cast<StateTop>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::STOP);


    // Exercise and Verify starting from TOP State
    sm.pushDownButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateDownward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::BACKWARD);

    sm.pushUpButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateUpward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::FORWARD);

    sm.pushDownButton();
    EXPECT_TRUE(dynamic_pointer_cast<StateDownward>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::BACKWARD);

    sm.endSwitchBottom();
    EXPECT_TRUE(dynamic_pointer_cast<StateBottom>(sm.state()) != nullptr);
    EXPECT_EQ(sm.motor(), MotorDirection::STOP);
}
