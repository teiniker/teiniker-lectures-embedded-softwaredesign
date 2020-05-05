#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <EEPROM.h>

#include <stdexcept>


const int SIZE = 1024*64;
EEPROM eeprom = EEPROM("AT28C64B", SIZE);

TEST_GROUP(EEPROMTestGroup)
{
};

TEST(EEPROMTestGroup, ReadWriteTest)
{
    // Exercise
    eeprom.write(0x0100, 0xaa);
    
    // Verify
    CHECK_EQUAL(0xaa, eeprom.read(0x0100));
}


TEST(EEPROMTestGroup, IllegalAddressWriteTest)
{
    // Verify
    CHECK_THROWS(std::invalid_argument, eeprom.write(SIZE, 0xaa));
}



TEST(EEPROMTestGroup, ArrayOperatorTest)
{
    // Exercise
    eeprom[0x0100] = 0xaa;
    
    // Verify
    CHECK_EQUAL(0xaa, eeprom[0x0100]);
}

TEST(EEPROMTestGroup, DifferentSizeEqualOperatorTest)
{
    // Setup
    EEPROM eep1 = EEPROM("EEP1", 8);
    EEPROM eep2 = EEPROM("EEP2", 16);
        
    // Verify
    CHECK_EQUAL(false, eep1 == eep2);
    CHECK_EQUAL(true, eep1 != eep2);
}

TEST(EEPROMTestGroup, EqualOperatorTest)
{
    // Setup
    EEPROM eep1 = EEPROM("EEP1", 8);
    EEPROM eep2 = EEPROM("EEP2", 8);
       
    eep1[0] = eep2[0] = 0xff;
    eep1[1] = eep2[1] = 0xee;
    eep1[2] = eep2[2] = 0xdd;
    eep1[3] = eep2[3] = 0xcc;
    eep1[4] = eep2[4] = 0xbb;
    eep1[5] = eep2[5] = 0xaa;
    eep1[6] = eep2[6] = 0x11;
    eep1[7] = eep2[7] = 0x22;    
        
    // Verify
    CHECK_EQUAL(true, eep1 == eep2);
    CHECK_EQUAL(false, eep1 != eep2);
}

TEST(EEPROMTestGroup, DifferentContentEqualOperatorTest)
{
    // Setup
    EEPROM eep1 = EEPROM("EEP1", 8);
    EEPROM eep2 = EEPROM("EEP2", 8);
       
    eep1[0] = eep2[0] = 0xff;
    eep1[1] = eep2[1] = 0xee;
    eep1[2] = eep2[2] = 0xdd;
    eep1[3] = eep2[3] = 0xcc;
    eep1[4] = eep2[4] = 0xbb;
    eep1[5] = eep2[5] = 0xaa;
    eep1[6] = eep2[6] = 0x11;
    eep1[7] = 0x22;    
    eep2[7] = 0x33; 
        
    // Verify
    CHECK_EQUAL(false, eep1 == eep2);
    CHECK_EQUAL(true, eep1 != eep2);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
