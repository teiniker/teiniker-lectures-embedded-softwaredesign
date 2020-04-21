#ifndef _CALCULATOR_FAST_H_
#define _CALCULATOR_FAST_H_

#include <Calculator.h>

// Inherit from abstract base class Calculator
// Remember: public inheritance means that all public and protected members 
// are derived.
class CalculatorFast : public Calculator 
{
	public: 
		CalculatorFast(void);
		~CalculatorFast(void);
		
		// Declation of a concrete method:
		// The use of override is optional, but being explicit allows the 
		// compiler to catch mistakes (misspellings).
		int sumOfSequence(int n) override;
};
 
#endif /*_CALCULATOR_FAST_H_ */
