#ifndef _EVENT_H_
#define _EVENT_H_

#include <string>

#include "time.h"
#include "date.h"

class Event 
{
	private:
		std::string _name;
		Time* _time; // Composition --[1]-> Time
		Date* _date; // Composition --[1]-> Date
 
	public:
		// string is passed by value
		// hh=0, min=0, sec=0 are default values for parameters
		Event(std::string name, int dd, int mm, int yyy, int hh = 0, int min = 0, int sec = 0);
		~Event(void);

		std::string to_string(void) const;
 };

#endif /*_EVENT_H_ */
