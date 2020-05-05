#include <Counter.h>

#include <stdexcept>

using namespace std;

Counter::Counter(int value, int min, int max) 
	: value_{value}, min_{min}, max_{max}
{
	if(min > max)
		throw invalid_argument("Invalid limits!");
		
	if(value < min || value > max)
		throw invalid_argument("value is out of range!");
		
}

int Counter::value(void)
{
	return value_;
}

void Counter::operator ++(int)
{
	if(value_ < max_)
		value_++;
}

void Counter::operator --(int)
{
	if(value_ > min_)
		value_--;
}
