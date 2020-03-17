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
		EEPROM(const string& type, const size_t size);
		~EEPROM(); 

		string type(void) const;
		
		uint8_t read(const uint32_t address);
		void write(const uint32_t address, uint8_t const value);
 };

#endif /*_EEPROM_H_ */
