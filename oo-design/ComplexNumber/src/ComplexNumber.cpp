#include <ComplexNumber.h>

ComplexNumber::ComplexNumber(double re, double im)
{
	_re = re;
	_im = im;	
}

ComplexNumber::ComplexNumber(const ComplexNumber& c)
{
	_re = c._re;
	_im = c._im;		
}

ComplexNumber::~ComplexNumber()
{
	
} 
    
double ComplexNumber::re()
{
	return _re;
}

double ComplexNumber::im()
{
	return _im;
}
		    
void ComplexNumber::add(const ComplexNumber& c)
{
	_re += c._re;
	_im += c._im;
}
	
void ComplexNumber::sub(const ComplexNumber& c)
{
	_re -= c._re;
	_im -= c._im;
}
