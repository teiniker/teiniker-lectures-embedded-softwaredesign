#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Event.h>

using namespace std;

TEST_GROUP(EventTestGroup)
{
};


TEST(EventTestGroup, TimeTest)
{
    Time t = Time(9,55,17);
    
    // Verify
    CHECK_EQUAL(9, t.hours());
    CHECK_EQUAL(55, t.minutes());
    CHECK_EQUAL(17, t.seconds());
}

TEST(EventTestGroup, DateTest)
{
    Date d = Date(1,4,2020);
    
    // Verify
    CHECK_EQUAL(1, d.day());
    CHECK_EQUAL(4, d.month());
    CHECK_EQUAL(2020, d.year());
}

TEST(EventTestGroup, EventTest)
{
    Event event = Event("SW Design Lecture", 1,4,2020, 8, 45); // sec=0
    
    // Verify
    CHECK_EQUAL("Event{'SW Design Lecture': Date[01.04.2020] Time[08:45:00]}", event.str());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
