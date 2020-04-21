#ifndef _CALCULATOR_SLOW_H_
#define _CALCULATOR_SLOW_H_

#include <Calculator.h>

// Inherit from abstract base class Calculator
class CalculatorSlow : public Calculator 
{
	public:
		CalculatorSlow(void);
		~CalculatorSlow(void);
		
		// Declation of a concrete method:
		// The use of override is optional, but being explicit allows the 
		// compiler to catch mistakes (misspellings).
		int sumOfSequence(int n) override;				
};
 
#endif /*_CALCULATOR_SLOW_H_ */
