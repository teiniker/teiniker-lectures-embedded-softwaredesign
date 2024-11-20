#include "date.h"

Date::Date(int day, int month, int year) 
    : _day{day}, _month{month}, _year{year}   
{
}

Date::~Date() 
{
}

int Date::day() const { return _day; }
void Date::day(const int day) { _day = day; }

int Date::month() const { return _month; }
void Date::month(const int month) { _month = month; }

int Date::year() const { return _year; }
void Date::year(const int year) { _year = year; }

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
    