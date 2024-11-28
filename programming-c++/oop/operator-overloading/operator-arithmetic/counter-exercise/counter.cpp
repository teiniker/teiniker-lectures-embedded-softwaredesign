#include "counter.h"

Counter::Counter(int value, int min, int max) 
	: _value{value}, _min{min}, _max{max}
{
}

int Counter::value(void) const
{
	return _value;
}
