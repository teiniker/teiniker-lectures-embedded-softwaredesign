#ifndef _DATE_H_
#define _DATE_H_

class Date 
{
	private:
		int dd_; 
		int mm_;
		int yyyy_;
 
	public:
		Date(int dd, int mm, int yyyy);
				
		int day(void);
		int month(void);
		int year(void);
 };

#endif /*_DATE_H_ */
