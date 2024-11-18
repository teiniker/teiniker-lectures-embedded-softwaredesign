#ifndef _TIME_H_
#define _TIME_H_

class Time 
{
	private:
		int _hh; 
		int _min;
		int _sec;
 
	public:
		Time(int hh, int min, int sec);
    
		int hours(void) const;
		int minutes(void) const;
		int seconds(void) const;
 };

#endif /*_TIME_H_ */
