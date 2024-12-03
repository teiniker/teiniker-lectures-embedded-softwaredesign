#ifndef _CALCULATOR_SLOW_H_
#define _CALCULATOR_SLOW_H_

#include "calculator.h"

class CalculatorSlow : public Calculator 
{
	public:
		CalculatorSlow(void);
		~CalculatorSlow(void);
		
		int sumOfSequence(const int n) override;				
};
 
#endif /*_CALCULATOR_SLOW_H_ */
