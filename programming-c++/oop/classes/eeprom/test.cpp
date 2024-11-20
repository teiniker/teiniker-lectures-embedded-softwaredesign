#include <gtest/gtest.h>

#include "eeprom.h"

TEST(EEPROMTest, ReadWriteTest) 
{
    // Setup
    EEPROM eeprom("AT28C64B", 1024*8); //64Kbit (8Kbit x 8) Parallel EEPROM

    // Exercise
    eeprom.write(0x0100, 0xaa);
    
    // Verify
    EXPECT_EQ(0xaa, eeprom.read(0x0100));

    // Teardown
}
