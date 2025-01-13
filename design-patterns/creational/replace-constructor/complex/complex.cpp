#include <string>
#include <cmath>
#include "complex.h"

using namespace std;

// Constructor
ComplexNumber::ComplexNumber(double re, double im) : _re(re), _im(im)
{
}


ComplexNumber* ComplexNumber::createFromCartesian(double re, double im)
{
    return new ComplexNumber(re, im);
}

ComplexNumber* ComplexNumber::createFromPolar(double rho, double theta)
{
    return new ComplexNumber(rho * cos(theta), rho * sin(theta));
}



// Accessor methods 

double ComplexNumber::re(void) const
{
    return _re;
}

double ComplexNumber::im(void) const
{
    return _im;
}   
