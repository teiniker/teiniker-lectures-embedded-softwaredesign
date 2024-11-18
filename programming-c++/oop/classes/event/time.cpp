#include "time.h"

Time::Time(int hh, int min, int sec)
	: _hh{hh}, _min{min}, _sec{sec}
{
}


int Time::hours(void) const
{
	return _hh;
}


int Time::minutes(void) const
{
	return _min;
}


int Time::seconds(void) const
{
	return _sec;
}
