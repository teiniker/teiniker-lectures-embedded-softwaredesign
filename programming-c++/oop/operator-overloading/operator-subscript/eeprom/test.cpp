#include <gtest/gtest.h>
#include "eeprom.h"

const int SIZE = 1024*64;
EEPROM eeprom("AT28C64B", SIZE);

TEST(EEPROMTest, ReadWriteTest) 
{
    // Exercise
    eeprom.write(0x0100, 0xaa);
    
    // Verify
    EXPECT_EQ(0xaa, eeprom.read(0x0100));
}

TEST(EEPROMTest, ArrayOperatorTest) 
{
    // Exercise
    eeprom[0x0100] = 0xaa;
    
    // Verify
    EXPECT_EQ(0xaa, eeprom[0x0100]);
}
