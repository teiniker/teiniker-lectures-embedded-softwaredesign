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
		
		friend bool operator== (const Complex &c1, const Complex &c2);
		friend bool operator!= (const Complex &c1, const Complex &c2);				 
 };

#endif /*_COMPLEX_H_ */
