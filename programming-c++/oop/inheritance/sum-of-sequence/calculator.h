#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

class Calculator // Interface 
{
	public:  
		virtual ~Calculator(void) {}

		virtual int sumOfSequence(const int n) = 0;
 };

#endif /*_CALCULATOR_H_ */
