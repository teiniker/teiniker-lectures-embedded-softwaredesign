#include <sstream>
#include <iomanip>

#include "event.h"

using namespace std;

Event::Event(string name, int dd, int mm, int yyyy, int hh, int min, int sec)
    : _name{name}, _time(hh, min, sec), _date(dd,mm,yyyy) 
{
}

string Event::str(void)
{
    ostringstream oss;
    oss << "Event{'" << _name << "': ";
    oss << "Date[";
    oss << setfill('0') << setw(2) << _date.day() << '.';
    oss << setfill('0') << setw(2) << _date.month() << '.';
    oss << _date.year() << "] ";
    oss << "Time[";
    oss << setfill('0') << setw(2) << _time.hours() << ':' ;
    oss << setfill('0') << setw(2) << _time.minutes() << ':';
    oss << setfill('0') << setw(2) << _time.seconds() << ']';
    oss << '}';
    return oss.str();
}
