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

// Friend Functions

bool operator== (const Complex &c1, const Complex &c2)
{
	return (c1._re == c2._re && c1._im == c2._im);
}

bool operator!= (const Complex &c1, const Complex &c2)			 
{
	return !(c1==c2);
}
