#include <GPIO.h>

#include <stdexcept>


GPIO::GPIO()
{
	throw std::runtime_error("No hardware in place!");
}

void GPIO::pinMode(const int pin, const bool mode)
{
	// TODO
}
void GPIO::digitalWrite(const int pin, const bool value)
{
	// TODO
}

bool GPIO::digitalRead(const int pin)
{
	// TODO
	return false;
}
