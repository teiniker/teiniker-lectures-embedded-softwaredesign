#include <sstream>
#include <iomanip>

#include "event.h"

using namespace std;

Event::Event(string name, int dd, int mm, int yyyy, int hh, int min, int sec)
    : _name{name}, _time(hh, min, sec), _date(dd,mm,yyyy) 
{
}

string Event::to_string(void) const
{
    // Event{'SW Design Lecture': Date[01.04.2020] Time[08:45:00]}

    char buffer[80];
    sprintf(buffer, "Event{'%s': Date[%02d.%02d.%4d] Time[%02d:%02d:%02d]}",
        _name.c_str(), _date.day(), _date.month(), _date.year(),
        _time.hours(), _time.minutes(), _time.seconds());  

    return string(buffer);
}
