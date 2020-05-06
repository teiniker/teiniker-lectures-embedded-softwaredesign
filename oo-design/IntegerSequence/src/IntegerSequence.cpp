#include <IntegerSequence.h>

int IntegerSequence::value_ = 0; // static

IntegerSequence::IntegerSequence(void)
{
	id_ = IntegerSequence::next();
}
		
void IntegerSequence::init(int value) // static
{
	value_ = value;
}

int IntegerSequence::next(void)  // static
{
	return value_++;
}

int IntegerSequence::id(void)
{
	return id_;
}

