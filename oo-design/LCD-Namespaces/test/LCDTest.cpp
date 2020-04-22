#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <LCD.h>

using org::se::lab::LCD;

int i = 0;
LCD display = LCD(8, 2);
LCD display2 = LCD(40, 10);

TEST_GROUP(LCDTestGroup)
{
    void setup(void)
    {
        display.clear();
        display2.clear();
    }
};

TEST(LCDTestGroup, HeapTest)
{
    // Setup
    // 40 Zeichen [Hallo!......................40]
    // 2 Zeilen   [..............................] 
    LCD* disp = new LCD(40,2); // Heap    
    disp->clear();
    
    // Exercise
    disp->print("Hallo!");
    char* buffer = disp->buffer();
    
    // Verify
    STRCMP_EQUAL("Hallo!", buffer);
    
    // Teardown
    delete disp;
}


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

TEST(LCDTestGroup, PrintDisplay2Test)
{
    // Exercise
    display.print("1nd display!!");
    display2.print("2nd display!!");
    
    // Verify
    STRCMP_EQUAL("1nd display!!", display.buffer());
    STRCMP_EQUAL("2nd display!!", display2.buffer());
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
