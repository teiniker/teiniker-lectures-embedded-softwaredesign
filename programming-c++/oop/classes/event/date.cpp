#include "date.h"

Date::Date(int dd, int mm, int yyyy)
    : _dd{dd}, _mm{mm}, _yyyy{yyyy}
{
}

int Date::day(void)
{
    return _dd;
}

int Date::month(void)
{
    return _mm;
}

int Date::year(void)
{
    return _yyyy;
}
