#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <cstdint>

using namespace std;

TEST_GROUP(IntegerTestGroup)
{
};


TEST(IntegerTestGroup, SizeOfTest)
{
    // Verify
    CHECK_EQUAL(1, sizeof(uint8_t));    
    CHECK_EQUAL(2, sizeof(uint16_t));
    CHECK_EQUAL(4, sizeof(uint32_t));
    CHECK_EQUAL(8, sizeof(uint64_t));
}

TEST(IntegerTestGroup, IntegerValuesTest)
{
    // Setup
    uint8_t byte = 0x11; 
	uint16_t int_16bit = 0x1122;
    uint32_t int_32bit = 0x11223344;
    uint64_t int_64bit = 0x1122334455667788;
    
    // Verify
    CHECK_EQUAL(0x11, byte);
    CHECK_EQUAL(0x1122, int_16bit);
    CHECK_EQUAL(0x11223344, int_32bit);
    CHECK_EQUAL(0x1122334455667788, int_64bit);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
