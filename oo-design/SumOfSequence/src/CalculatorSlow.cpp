#include <iostream>

#include <Calculator.h>
#include <CalculatorSlow.h>

using namespace std;

CalculatorSlow::CalculatorSlow(void)
{
	cout << "CalculatorSlow() - constructor" << endl;
}

CalculatorSlow::~CalculatorSlow(void)
{
	cout << "CalculatorSlow() - destructor" << endl;
}
		
int CalculatorSlow::sumOfSequence(int n)
{
	int result = 0;
	for(int i=1; i<=n; i++)
		result += i;
	return result;		
}
