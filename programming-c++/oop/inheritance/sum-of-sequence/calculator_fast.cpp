#include <iostream>

#include "calculator_fast.h"

using namespace std;

CalculatorFast::CalculatorFast(void)
{
	cout << "CalculatorFast() - constructor" << endl;
}

CalculatorFast::~CalculatorFast(void)
{
	cout << "CalculatorFast() - destructor" << endl;
}
		
int CalculatorFast::sumOfSequence(const int n)
{
	return n*(n+1)/2;
}
