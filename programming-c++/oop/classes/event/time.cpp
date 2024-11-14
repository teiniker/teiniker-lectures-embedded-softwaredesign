#include "time.h"

Time::Time(int hh, int min, int sec)
	: _hh{hh}, _min{min}, _sec{sec}
{
}


int Time::hours(void)
{
	return _hh;
}


int Time::minutes(void)
{
	return _min;
}


int Time::seconds(void)
{
	return _sec;
}
