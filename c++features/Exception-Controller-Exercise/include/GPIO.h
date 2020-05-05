#ifndef _GPIO_H_
#define _GPIO_H_

#include <string>
#include <vector>

const bool OUTPUT = false;
const bool INPUT = true;

const bool HIGH = true;
const bool LOW = false;

class GPIO 
{
	private:
		
	public:                
		GPIO();

		void pinMode(const int pin, const bool mode);
		void digitalWrite(const int pin, const bool value);
		bool digitalRead(const int pin);
 };

#endif /*_GPIO_H_ */
