#ifndef _DATE_H_
#define _DATE_H_

class Date 
{
	private:
		int _dd; 
		int _mm;
		int _yyyy;
 
	public:
		Date(int dd, int mm, int yyyy);
				
		int day(void);
		int month(void);
		int year(void);
 };

#endif /*_DATE_H_ */
