#include "date.h"

Date::Date(int dd, int mm, int yyyy)
    : _dd{dd}, _mm{mm}, _yyyy{yyyy}
{
}

int Date::day(void) const
{
    return _dd;
}

int Date::month(void) const
{
    return _mm;
}

int Date::year(void) const
{
    return _yyyy;
}
