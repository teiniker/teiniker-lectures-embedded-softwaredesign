#include <Event.h>

#include <sstream>
#include <iomanip>

Event::Event(string name, int dd, int mm, int yyyy, int hh, int min, int sec)
    : name_{name}, time_(hh, min, sec), date_(dd,mm,yyyy) 
{
}

string Event::str(void)
{
    ostringstream oss;
    oss << "Event{'" << name_ << "': ";
    oss << "Date[";
    oss << setfill('0') << setw(2) << date_.day() << '.';
    oss << setfill('0') << setw(2) << date_.month() << '.';
    oss << date_.year() << "] ";
    oss << "Time[";
    oss << setfill('0') << setw(2) << time_.hours() << ':' ;
    oss << setfill('0') << setw(2) << time_.minutes() << ':';
    oss << setfill('0') << setw(2) << time_.seconds() << ']';
    oss << '}';
    return oss.str();
}
