#include "i2c.h"
#include <cstring>

namespace io
{
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

    void i2c_write(uint8_t address, uint8_t data)
    {
        i2c_module.address = address;
        i2c_module.size = 1;
        i2c_module.memory[0] = data;
    }

    void i2c_write(uint8_t address, uint16_t data)
    {
        i2c_module.address = address;
        i2c_module.size = 2;
        i2c_module.memory[0] = data & 0xFF;
        i2c_module.memory[1] = (data >> 8) & 0xFF;
    }

    void i2c_write(uint8_t address, uint32_t data)
    {
        i2c_module.address = address;
        i2c_module.size = 4;
        i2c_module.memory[0] = data & 0xFF;
        i2c_module.memory[1] = (data >> 8) & 0xFF;
        i2c_module.memory[2] = (data >> 16) & 0xFF;
        i2c_module.memory[3] = (data >> 24) & 0xFF;
    }

    void i2c_write(uint8_t address, const char *data)
    {
        i2c_module.size = strlen(data);
        for (int i = 0; data[i] != '\0'; i++)
        {
            i2c_module.memory[i] = data[i];
        }
    }

} // namespace io
