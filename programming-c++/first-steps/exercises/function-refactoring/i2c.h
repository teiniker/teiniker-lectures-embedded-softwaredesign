#ifndef _I2C_H_
#define _I2C_H_

#include <cstdint>

namespace io
{
    struct I2cModule
    {
        uint8_t pin_scl;
        uint8_t pin_sda;
        uint8_t address;
        uint8_t memory[256];
        uint8_t size;
    };

    extern I2cModule i2c_module;

    // Function Overloading
    extern void i2c_init(uint8_t pin_scl = 1, uint8_t pin_sda = 0);
    extern void i2c_write(uint8_t address, uint8_t data);
    extern void i2c_write(uint8_t address, uint16_t data);
    extern void i2c_write(uint8_t address, uint32_t data);
    extern void i2c_write(uint8_t address, const char *data);
} 

#endif // I2C_H