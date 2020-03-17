#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <LCD.h>

LCD display = LCD(8, 2);

TEST_GROUP(LCDTestGroup)
{
    void setup(void)
    {
        display.clear();
    }
};

TEST(LCDTestGroup, ClearTest)
{
    // Verify
    char* buffer = display.buffer(); 
    CHECK_EQUAL(0x00, buffer[0]);
    CHECK_EQUAL(0x00, buffer[8]);
    CHECK_EQUAL(0x00, buffer[15]);
}

TEST(LCDTestGroup, PrintCharTest)
{
    // Exercise
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');
    
    // Verify
    STRCMP_EQUAL("Hello", display.buffer());
}

TEST(LCDTestGroup, PrintCharPtrTest)
{
    // Exercise
    display.print("Hello");
    
    // Verify
    STRCMP_EQUAL("Hello", display.buffer());
}

TEST(LCDTestGroup, PrintTest)
{
    // Exercise
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');
    display.print(' ');
    display.print("Graz!");
    
    // Verify
    STRCMP_EQUAL("Hello Graz!", display.buffer());    
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
