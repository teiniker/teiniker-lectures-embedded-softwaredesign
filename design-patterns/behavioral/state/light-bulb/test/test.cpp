#include <gtest/gtest.h>
#include <memory>

#include <light_bulb.h>
#include <light_bulb_on.h>
#include <light_bulb_off.h>

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
    auto offState = std::dynamic_pointer_cast<LightBulbOff>(sm.getState());
    EXPECT_TRUE(offState != nullptr);
}

TEST_F(StateTest, testTurnOff)
{
    sm.turnOff();
    auto offState = std::dynamic_pointer_cast<LightBulbOff>(sm.getState());
    EXPECT_TRUE(offState != nullptr);
}

TEST_F(StateTest, testTurnOn)
{
    sm.turnOn();
    auto onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);
}

TEST_F(StateTest, testTurnOnAndTurnOn)
{
    // Turn on once
    sm.turnOn();
    auto onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);

    // Turn on again
    sm.turnOn();
    onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);
}

TEST_F(StateTest, testTurnOnAndTurnOff)
{
    sm.turnOn();
    auto onState = std::dynamic_pointer_cast<LightBulbOn>(sm.getState());
    EXPECT_TRUE(onState != nullptr);

    sm.turnOff();
    auto offState = std::dynamic_pointer_cast<LightBulbOff>(sm.getState());
    EXPECT_TRUE(offState != nullptr);
}
