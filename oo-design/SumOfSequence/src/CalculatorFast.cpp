#include <iostream>

#include <Calculator.h>
#include <CalculatorFast.h>

using namespace std;

CalculatorFast::CalculatorFast(void)
{
	cout << "CalculatorFast() - constructor" << endl;
}

CalculatorFast::~CalculatorFast(void)
{
	cout << "CalculatorFast() - destructor" << endl;
}
		
// Implements the abstract method declared in Calculator.h		
int CalculatorFast::sumOfSequence(int n)
{
	return n*(n+1)/2;
}
