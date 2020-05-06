#ifndef _EEPROM_H_
#define _EEPROM_H_

#include <string>
#include <cstdint>

using namespace std;

class EEPROM 
{
	private:
		string type_;
		size_t size_; 
		uint8_t* memory_;
 
	public:
		EEPROM(string& type, size_t size);
		~EEPROM(); 

		string type(void);
		
		uint8_t read(uint32_t address);
		void write(uint32_t address, uint8_t value);
 };

#endif /*_EEPROM_H_ */
