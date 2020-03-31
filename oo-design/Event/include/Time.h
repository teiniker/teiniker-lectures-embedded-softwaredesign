#ifndef _TIME_H_
#define _TIME_H_

class Time 
{
	private:
		int hh_; 
		int min_;
		int sec_;
 
	public:
		Time(int hh, int min, int sec);
    
		int hours(void);
		int minutes(void);
		int seconds(void);
 };

#endif /*_TIME_H_ */
