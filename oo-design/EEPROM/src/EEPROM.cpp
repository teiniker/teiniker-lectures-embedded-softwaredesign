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
				
string EEPROM::type(void) const
{
	return type_;
}

uint8_t EEPROM::read(const uint32_t address)
{
	// 0 <= address < size
	return memory_[address]; 
}

void EEPROM::write(const uint32_t address, const uint8_t value)
{
	// 0 <= address < size
	memory_[address] = value;
}

uint8_t& EEPROM::operator[](const uint32_t address)
{
	return memory_[address]; 
}
