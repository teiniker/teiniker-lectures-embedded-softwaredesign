#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#include "complex_numbers.h"

complex complex_add(complex a, complex b)
{
	complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}
