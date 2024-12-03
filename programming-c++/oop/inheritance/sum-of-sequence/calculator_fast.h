#ifndef _CALCULATOR_FAST_H_
#define _CALCULATOR_FAST_H_

#include "calculator.h"

class CalculatorFast : public Calculator 
{
	public: 
		CalculatorFast(void);
		~CalculatorFast(void);
		
		int sumOfSequence(const int n) override;
};
 
#endif /*_CALCULATOR_FAST_H_ */
