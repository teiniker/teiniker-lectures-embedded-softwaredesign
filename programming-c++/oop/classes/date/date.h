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

        int day() const;
        void day(const int d);
        
        int month() const; 
        void month(const int m);
        
        int year() const;
        void year(const int y);

        bool isLeapYear();
};

#endif // _DATE_H_