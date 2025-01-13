#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class ComplexNumber
{
private:
    double _re;
    double _im;

    // Constructor
    ComplexNumber(double re, double im);

public:
    // Creation methods
    static ComplexNumber* createFromCartesian(double re, double im);
    static ComplexNumber* createFromPolar(double rho, double theta);

    // Accessor methods 
    double re() const;
    double im() const;
};

#endif // _COMPLEX_NUMBER_H_
