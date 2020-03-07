#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class ComplexNumber 
{
	private:
		double _re; 
		double _im;
 
	public:
		ComplexNumber(double re, double im);
    	ComplexNumber(const ComplexNumber& c); 
		~ComplexNumber(); 
    
		double re();
		double im();
		void add(const ComplexNumber& c);
		void sub(const ComplexNumber& c);
 };

#endif /*_COMPLEX_NUMBER_H_ */
