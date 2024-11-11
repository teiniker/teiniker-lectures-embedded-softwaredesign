#ifndef _COMPLEX_H_
#define _COMPLEX_H_


class Complex 
{
	private:
		double real_;
		double imag_;
	
	public:       
		// Constructor
		Complex(double real, double imag);
		
		// Getter 
		double real(void);
		double imag(void);
		
		// Operator Overloading
		Complex operator +(const Complex& c);
		Complex operator -(const Complex& c);
		
		friend bool operator== (const Complex &c1, const Complex &c2);
		friend bool operator!= (const Complex &c1, const Complex &c2);				 
 };

#endif /*_COMPLEX_H_ */
