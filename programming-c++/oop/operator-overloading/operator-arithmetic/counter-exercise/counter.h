#ifndef _COUNTER_H_
#define _COUNTER_H_


class Counter 
{
	private:
		int _value;
		int _min;
		int _max;
	
	public:       
		// Constructor
		Counter(int value, int min, int max);
		
		// Getter 
		int value(void) const;
 };

#endif /*_COUNTER_H_ */
