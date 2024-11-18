#include <gtest/gtest.h>
#include "event.h"

using namespace std;

TEST(EventTestGroup, TimeTest)
{
    Time t = Time(9, 55, 17);
    
    // Verify
    EXPECT_EQ(9, t.hours());
    EXPECT_EQ(55, t.minutes());
    EXPECT_EQ(17, t.seconds());
}

TEST(EventTestGroup, DateTest)
{
    Date d = Date(1, 4, 2020);
    
    // Verify
    EXPECT_EQ(1, d.day());
    EXPECT_EQ(4, d.month());
    EXPECT_EQ(2020, d.year());
}

TEST(EventTestGroup, EventTest)
{
    Event event = Event("SW Design Lecture", 1, 4, 2020, 8, 45); // sec=0
    
    // Verify
    EXPECT_EQ("Event{'SW Design Lecture': Date[01.04.2020] Time[08:45:00]}", event.to_string());
}
