#include <EEPROM.h>

using namespace std;

EEPROM::EEPROM(const string& type, const size_t size)
{
	type_ = type;
	size_ = size;
	memory_ = new uint8_t[size];
}

EEPROM::~EEPROM()
{
	delete[] memory_;  
} 

string EEPROM::type(void) 
{
	return type_;
}

uint8_t EEPROM::read(uint32_t address)
{
	return memory_[address]; 
}

void EEPROM::write(uint32_t address, uint8_t value)
{
	memory_[address] = value;
}
