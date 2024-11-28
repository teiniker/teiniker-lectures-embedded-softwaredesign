#ifndef _EEPROM_H_
#define _EEPROM_H_

#include <string>
#include <cstdint>

class EEPROM 
{
	private:
		std::string type_;
		size_t size_; 
		uint8_t* memory_;
 
	public:
		EEPROM(const std::string& type, const size_t size);
		~EEPROM(); 

		std::string type(void);
		
		uint8_t read(uint32_t address);					// 0 <= address < size
		void write(uint32_t address, uint8_t value);	// 0 <= address < size
		
		// Operator overloading
		uint8_t& operator[]( const uint32_t address );
};

#endif /*_EEPROM_H_ */
