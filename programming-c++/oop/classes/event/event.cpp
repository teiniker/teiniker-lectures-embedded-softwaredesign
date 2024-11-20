#include <sstream>
#include <iomanip>

#include "event.h"

using namespace std;

Event::Event(string name, int dd, int mm, int yyyy, int hh, int min, int sec)
    : _name{name}, _time{hh, min, sec}, _date{dd,mm,yyyy} 
{
}

string Event::to_string(void) const
{
    char buffer[80];
    snprintf(buffer, sizeof(buffer),"Event{'%s': Date[%02d.%02d.%4d] Time[%02d:%02d:%02d]}",
        _name.c_str(), _date.day(), _date.month(), _date.year(),
        _time.hours(), _time.minutes(), _time.seconds());  

    return string(buffer);
}
