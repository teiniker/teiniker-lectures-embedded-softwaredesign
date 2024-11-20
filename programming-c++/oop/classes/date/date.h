#ifndef _DATE_H_
#define _DATE_H_

#include <cstdint>

class Date 
{
    private:
        int _day;
        int _month;
        int _year;

    public:
        Date(int d, int m, int y);  // Constructor   
        ~Date();                    // Destructor

        // Getter and Setter Methods
        int Date::day() const { return _day; }          // inline function
        void Date::day(const int day) { _day = day; }   // inline function

        int month() const; 
        void month(const int m);
        
        int year() const;
        void year(const int y);

        // Operations
        bool isLeapYear();
};

#endif // _DATE_H_