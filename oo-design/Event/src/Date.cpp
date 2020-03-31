#include <Date.h>

Date::Date(int dd, int mm, int yyyy)
    : dd_{dd}, mm_{mm}, yyyy_{yyyy}
{
}

int Date::day(void)
{
    return dd_;
}

int Date::month(void)
{
    return mm_;
}

int Date::year(void)
{
    return yyyy_;
}
