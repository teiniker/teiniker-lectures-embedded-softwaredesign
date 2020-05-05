#include <EEPROM.h>

#include <stdexcept>

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
	if(address >= size_)
		throw invalid_argument("Invalid address!");
		
	return memory_[address]; 
}

void EEPROM::write(uint32_t address, uint8_t value)
{
	if(address >= size_)
		throw invalid_argument("Invalid address!");

	memory_[address] = value;
}

// Operator Overloading

uint8_t& EEPROM::operator[](uint32_t address)
{
	return memory_[address]; 
}

bool operator== (const EEPROM &eep1, const EEPROM &eep2)
{
	if(eep1.size_ != eep2.size_)
		return false;
	
	for(unsigned int i=0; i<eep1.size_; i++)
	{
		if(eep1.memory_[i] != eep2.memory_[i])
			return false;
	}	
	return true;
}		
		
bool operator!= (const EEPROM &eep1, const EEPROM &eep2)
{
	return !(eep1 == eep2);
} 
