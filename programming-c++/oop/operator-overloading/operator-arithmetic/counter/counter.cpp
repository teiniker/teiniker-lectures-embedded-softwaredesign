#include "counter.h"

Counter::Counter(int value, int min, int max) 
	: _value{value}, _min{min}, _max{max}
{
}

int Counter::value(void) const
{
	return _value;
}

void Counter::operator ++(int)
{
	if(_value < _max)
		_value++;
}

void Counter::operator --(int)
{
	if(_value > _min)
		_value--;
}
