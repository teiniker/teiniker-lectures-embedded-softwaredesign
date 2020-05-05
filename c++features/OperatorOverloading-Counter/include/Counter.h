#ifndef _COUNTER_H_
#define _COUNTER_H_


class Counter 
{
	private:
		int value_;
		int min_;
		int max_;
	
	public:       
		// Constructor
		Counter(int value, int min, int max);
		
		// Getter 
		int value(void);
		
		// Operator Overloading
		void operator ++(int);	// postfix increment operator
		
		void operator --(int);	// postfix decrement operator
 };

#endif /*_COUNTER_H_ */
