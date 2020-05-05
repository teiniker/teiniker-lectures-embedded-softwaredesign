#include <Complex.h>

Complex::Complex(double real, double imag) 
	: real_{real}, imag_{imag}
{
}	

double Complex::real(void)
{
	return real_;
}

double Complex::imag(void)
{
	return imag_;	
}

Complex Complex::operator +(const Complex& c)
{
	Complex result(real_ + c.real_, imag_ + c.imag_);
	return result;
}

Complex Complex::operator -(const Complex& c)
{
	Complex result(real_ - c.real_, imag_ - c.imag_);
	return result;
}

// Friend Functions
// A friend function of a class is defined outside that class' scope but 
// it has the right to access all private and protected members of the class. 
// Even though the prototypes for friend functions appear in the class 
// definition, friends are not member functions.

bool operator== (const Complex &c1, const Complex &c2)
{
	return (c1.real_ == c2.real_ && c1.imag_ == c2.imag_);
}

bool operator!= (const Complex &c1, const Complex &c2)			 
{
	return !(c1==c2);
}
