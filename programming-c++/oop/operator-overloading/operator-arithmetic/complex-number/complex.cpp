#include "complex.h"

Complex::Complex(double re, double im) 
	: _re{re}, _im{im}
{
}	

double Complex::real(void) const
{
	return _re;
}

double Complex::imag(void) const
{
	return _im;	
}

Complex Complex::operator +(const Complex& c)
{
	Complex result(_re + c._re, _im + c._im);
	return result;
}

Complex Complex::operator -(const Complex& c)
{
	Complex result(_re - c._re, _im - c._im);
	return result;
}

