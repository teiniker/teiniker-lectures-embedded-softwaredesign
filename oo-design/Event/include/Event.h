#ifndef _EVENT_H_
#define _EVENT_H_

#include <Time.h>
#include <Date.h>

#include <string>

using namespace std;

class Event 
{
	private:
		string name_;
		Time time_; // Composition --[1]-> Time
		Date date_; // Composition --[1]-> Date
 
	public:
		// string is passed by value
		// hh=0, min=0, sec=0 are default values for parameters
		Event(string name, int dd, int mm, int yyy, int hh = 0, int min = 0, int sec = 0);
		
		string str(void);
		 
 };

#endif /*_EVENT_H_ */
