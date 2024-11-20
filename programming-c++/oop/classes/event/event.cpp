#include <sstream>
#include <iomanip>

#include "event.h"
#include "time.h"
#include "date.h"

using namespace std;

Event::Event(string name, int dd, int mm, int yyyy, int hh, int min, int sec)
    : _name{name}
{
    _date = new Date(dd, mm, yyyy);
    _time = new Time(hh, min, sec);
}

Event::~Event(void)
{
    delete _date;
    delete _time;
}

string Event::to_string(void) const
{
    char buffer[80];
    snprintf(buffer, sizeof(buffer),"Event{'%s': Date[%02d.%02d.%4d] Time[%02d:%02d:%02d]}",
        _name.c_str(), _date->day(), _date->month(), _date->year(),
        _time->hours(), _time->minutes(), _time->seconds());  

    return string(buffer);
}
