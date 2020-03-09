#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

typedef struct complex_number
{
    double re;
    double im;
} complex;

extern complex complex_add(complex a, complex b);



#endif /*_COMPLEX_NUMBER_H_ */
