#include <gtest/gtest.h>
#include "lcd.h"

LCD display(8, 2);

TEST(LCDTestGroup, ClearTest) 
{
    // Setup
    display.clear();

    // Verify
    char* buffer = display.buffer(); 
    
    EXPECT_EQ(0x00, buffer[0]);
    EXPECT_EQ(0x00, buffer[8]);
    EXPECT_EQ(0x00, buffer[15]);
}

TEST(LCDTestGroup, PrintCharTest) 
{
    // Setup
    display.clear();

    // Exercise
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');
    
    // Verify
    EXPECT_STREQ("Hello", display.buffer());
}

TEST(LCDTestGroup, PrintCharPtrTest) 
{
    // Setup
    display.clear();

    // Exercise
    display.print("Hello");
    
    // Verify
    EXPECT_STREQ("Hello", display.buffer());
}

TEST(LCDTestGroup, PrintTest) 
{
    // Setup
    display.clear();

    // Exercise
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');
    display.print(' ');
    display.print("Graz!");
    
    // Verify
    EXPECT_STREQ("Hello Graz!", display.buffer());    
}

TEST(LCDTestGroup, HeapTest) 
{
    // Setup
    LCD* disp = new LCD(40, 2); // Heap    
    disp->clear();
    
    // Exercise
    disp->print("Hallo!");
    char* buffer = disp->buffer();
    
    // Verify
    EXPECT_STREQ("Hallo!", buffer);
    
    // Teardown
    delete disp;
}
