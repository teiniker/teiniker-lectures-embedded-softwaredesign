#include <IntegerSequence.h>

int IntegerSequence::value_ = 0;

IntegerSequence::IntegerSequence(void)
{
	id_ = IntegerSequence::next();
}
		
void IntegerSequence::init(int value)
{
	value_ = value;
}

int IntegerSequence::next(void)
{
	return value_++;
}

int IntegerSequence::id(void)
{
	return id_;
}

