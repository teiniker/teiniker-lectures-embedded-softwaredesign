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
    
		int hours(void);
		int minutes(void);
		int seconds(void);
 };

#endif /*_TIME_H_ */
