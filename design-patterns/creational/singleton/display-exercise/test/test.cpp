#include <gtest/gtest.h>

#include <display.h>

using namespace std;

TEST(DisplayTest, testSingleObject)
{
    auto display1 = Display::getInstance();
    auto display2 = Display::getInstance();

    // Verify that both references refer to the same instance
    EXPECT_EQ(display1, display2);
}

TEST(DisplayTest, testPrintString)
{
    auto display = Display::getInstance();

    display->print("Hello");
    display->print("World");

    EXPECT_EQ(display->getBuffer().size(), 2);
    EXPECT_EQ(display->getBuffer()[0], "Hello");
    EXPECT_EQ(display->getBuffer()[1], "World");
}
