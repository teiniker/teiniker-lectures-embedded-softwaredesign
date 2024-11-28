#include "range.h"

Range::Range(const int32_t min, const int32_t max)
	: min_(min), max_(max)
{
}

int32_t Range::value(void) const
{
	return value_;
}

void Range::value(const int32_t value)
{
	if (value < min_)
	{
		value_ = min_;
	}
	else if (value > max_)
	{
		value_ = max_;
	}
	else
	{
		value_ = value;
	}
}

// Operator overloading

bool Range::operator==(const Range& other) const
{
	return value_ == other.value_;
}

bool Range::operator!=(const Range& other) const
{
	return value_ != other.value_;
}

bool Range::operator<(const Range& other) const
{
	return value_ < other.value_;
}

bool Range::operator>(const Range& other) const
{
	return value_ > other.value_;
}

bool Range::operator<=(const Range& other) const
{
	return value_ <= other.value_;
}

bool Range::operator>=(const Range& other) const
{
	return value_ >= other.value_;
}
