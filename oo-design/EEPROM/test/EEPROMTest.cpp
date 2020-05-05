#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <EEPROM.h>

EEPROM eeprom = EEPROM("AT28C64B", 1024*64);

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

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
