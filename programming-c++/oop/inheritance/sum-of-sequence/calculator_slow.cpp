#include <iostream>

#include "calculator_slow.h"

using namespace std;

CalculatorSlow::CalculatorSlow(void)
{
	cout << "CalculatorSlow() - constructor" << endl;
}

CalculatorSlow::~CalculatorSlow(void)
{
	cout << "CalculatorSlow() - destructor" << endl;
}
		
int CalculatorSlow::sumOfSequence(const int n)
{
	int result = 0;
	for(int i=1; i<=n; i++)
	{
		result += i;
	}
	return result;		
}
