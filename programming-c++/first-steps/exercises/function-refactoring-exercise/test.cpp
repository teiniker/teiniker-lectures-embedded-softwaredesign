// implement GTests for funtions defined in i2c.
#include <gtest/gtest.h>
#include "i2c.h"

// Test for I2C initialization
TEST(I2CTest, InitI2C) 
{
    io::i2c_init();

    EXPECT_EQ(1, io::i2c_module.pin_scl);
    EXPECT_EQ(0, io::i2c_module.pin_sda);
    EXPECT_EQ(0x0f, io::i2c_module.address);
    EXPECT_EQ(0, io::i2c_module.size);
}

// Test for I2C write byte
TEST(I2CTest, WriteByteTest) 
{
    io::i2c_init();
    uint8_t data = 0xd2;
    io::i2c_write(0x0f, data);

    EXPECT_EQ(0x0f, io::i2c_module.address);
    EXPECT_EQ(1, io::i2c_module.size);
    EXPECT_EQ(0xd2, io::i2c_module.memory[0]);
}

// Test for I2C write 2 bytes
TEST(I2CTest, WriteWord16Test) 
{
    io::i2c_init();
    uint16_t data = 0x2211;
    io::i2c_write(0x0f, data);

    EXPECT_EQ(0x0f, io::i2c_module.address);
    EXPECT_EQ(2, io::i2c_module.size);
    EXPECT_EQ(0x11, io::i2c_module.memory[0]);
    EXPECT_EQ(0x22, io::i2c_module.memory[1]);
}

// Test for I2C write 4 bytes
TEST(I2CTest, WriteWord32Test) 
{
    io::i2c_init();
    uint32_t data = 0x44332211;
    io::i2c_write(0x0f, data);

    EXPECT_EQ(0x0f, io::i2c_module.address);
    EXPECT_EQ(4, io::i2c_module.size);
    EXPECT_EQ(0x11, io::i2c_module.memory[0]);
    EXPECT_EQ(0x22, io::i2c_module.memory[1]);
    EXPECT_EQ(0x33, io::i2c_module.memory[2]);
    EXPECT_EQ(0x44, io::i2c_module.memory[3]);
}

// Test for I2C write string
TEST(I2CTest, WriteStringTest) 
{
    io::i2c_init();
    const char *data = "Hello";
    io::i2c_write(0x0f, data);
 
    EXPECT_EQ(0x0f, io::i2c_module.address);
    EXPECT_EQ(5, io::i2c_module.size);
    EXPECT_STREQ("Hello", (char *)io::i2c_module.memory);
}
