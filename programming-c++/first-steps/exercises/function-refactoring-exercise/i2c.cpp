#include <cstring>
#include <cassert>
#include <cstdint>

struct I2cModule
{
    uint8_t pin_scl;
    uint8_t pin_sda;
    uint8_t address;
    uint8_t memory[256];
    uint8_t size;
};

I2cModule i2c_module;

// Using default values for pin_scl and pin_sda
void i2c_init(uint8_t pin_scl, uint8_t pin_sda)
{
    i2c_module.pin_scl = pin_scl;
    i2c_module.pin_sda = pin_sda;
    i2c_module.address = 0x0f;
    memset(i2c_module.memory, 0, 256);
    i2c_module.size = 0;
}

void i2c_write_byte(uint8_t address, uint8_t data)
{
    i2c_module.address = address;
    i2c_module.size = 1;
    i2c_module.memory[0] = data;
}

void i2c_write_word16(uint8_t address, uint16_t data)
{
    i2c_module.address = address;
    i2c_module.size = 2;
    i2c_module.memory[0] = data & 0xFF;
    i2c_module.memory[1] = (data >> 8) & 0xFF;
}

void i2c_write_word32(uint8_t address, uint32_t data)
{
    i2c_module.address = address;
    i2c_module.size = 4;
    i2c_module.memory[0] = data & 0xFF;
    i2c_module.memory[1] = (data >> 8) & 0xFF;
    i2c_module.memory[2] = (data >> 16) & 0xFF;
    i2c_module.memory[3] = (data >> 24) & 0xFF;
}

void i2c_write_string(uint8_t address, const char *data)
{
    i2c_module.size = strlen(data);
    for (int i = 0; data[i] != '\0'; i++)
    {
        i2c_module.memory[i] = data[i];
    }
}

int main(void)
{
    {   // Test for I2C initialization
        i2c_init(1,0);

        assert(1 == i2c_module.pin_scl);
        assert(0 == i2c_module.pin_sda);
        assert(0x0f == i2c_module.address);
        assert(0 == i2c_module.size);
    }

    {   // Test for I2C write byte
        i2c_init(1,0);
        uint8_t data = 0xd2;
        i2c_write_byte(0x0f, data);

        assert(0x0f == i2c_module.address);
        assert(1 == i2c_module.size);
        assert(0xd2 == i2c_module.memory[0]);
    }

    {   // Test for I2C write 2 bytes
        i2c_init(1,0);
        uint16_t data = 0x2211;
        i2c_write_word16(0x0f, data);

        assert(0x0f == i2c_module.address);
        assert(2 == i2c_module.size);
        assert(0x11 == i2c_module.memory[0]);
        assert(0x22 == i2c_module.memory[1]);
    }

    {   // Test for I2C write 4 bytes
        i2c_init(1,0);
        uint32_t data = 0x44332211;
        i2c_write_word32(0x0f, data);

        assert(0x0f == i2c_module.address);
        assert(4 == i2c_module.size);
        assert(0x11 == i2c_module.memory[0]);
        assert(0x22 == i2c_module.memory[1]);
        assert(0x33 == i2c_module.memory[2]);
        assert(0x44 == i2c_module.memory[3]);
    }

    {  // Test for I2C write string
        i2c_init(1,0);
        const char *data = "Hello";
        i2c_write_string(0x0f, data);
 
        assert(0x0f == i2c_module.address);
        assert(5 == i2c_module.size);
        assert(strcmp("Hello", (char *)i2c_module.memory) == 0);
    }

    return 0;
}