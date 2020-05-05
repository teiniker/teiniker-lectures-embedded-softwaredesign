#include <EEPROM.h>

using namespace std;
// classname::operationname()
EEPROM::EEPROM(const string& type, const size_t size)
{
	type_ = type;
	size_ = size;
	memory_ = new uint8_t[size]; // malloc(.. sizeof())
}

EEPROM::~EEPROM()
{
	delete[] memory_;  // free(memory_)
} 

string EEPROM::type(void) 
{
	return type_;
}

uint8_t EEPROM::read(uint32_t address)
{
	// 0 <= address < size
	return memory_[address]; 
}

void EEPROM::write(uint32_t address, uint8_t value)
{
	// 0 <= address < size
	memory_[address] = value;
}
