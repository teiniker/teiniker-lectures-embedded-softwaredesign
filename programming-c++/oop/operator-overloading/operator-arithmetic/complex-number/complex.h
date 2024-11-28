#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex 
{
	private:
		double _re;
		double _im;
	
	public:       
		// Constructor
		Complex(double re, double im);
		
		// Getter 
		double real(void) const;
		double imag(void) const;
		
		// Operator Overloading
		Complex operator +(const Complex& c);
		Complex operator -(const Complex& c);
 };

#endif /*_COMPLEX_H_ */
