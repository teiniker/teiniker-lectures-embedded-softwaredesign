#include <gtest/gtest.h>
#include "lcd.h"


TEST(LCDTestGroup, ClearTest) 
{
    // Setup
    LCD display(8, 2);
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
    LCD display(8, 2);
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
    LCD display(8, 2);
    display.clear();

    // Exercise
    display.print("Hello");
    
    // Verify
    EXPECT_STREQ("Hello", display.buffer());
}

TEST(LCDTestGroup, PrintTest) 
{
    // Setup
    LCD display(8, 2);
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

TEST(LCDTestGroup, PolymorphismTest) 
{
    // Setup
    Display* display = new LCD(40, 2);  // LCD "is a" Display (Upcast: inherently safe) 
    display->clear();
    
    // Exercise
    display->print("Hallo!");

    LCD* lcd = dynamic_cast<LCD*>(display); // Explicit Downcast
    
    // Verify
    ASSERT_NE(nullptr, lcd);
    EXPECT_STREQ("Hallo!", lcd->buffer());
    
    // Teardown
    delete display;
}
