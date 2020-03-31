#include <Time.h>

Time::Time(int hh, int min, int sec)
	: hh_{hh}, min_{min}, sec_{sec}
{
}


int Time::hours(void)
{
	return hh_;
}


int Time::minutes(void)
{
	return min_;
}


int Time::seconds(void)
{
	return sec_;
}
