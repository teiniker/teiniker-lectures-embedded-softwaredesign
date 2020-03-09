#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

// SUT

typedef struct ComplexNumber_
{
    double re;
    double im;
    
} ComplexNumber;


void complex_init(ComplexNumber *self, double re, double im)
{
    self->re = re;
    self->im = im;    
}

void complex_add(ComplexNumber *self, ComplexNumber c)
{
    self->re += c.re;
    self->im += c.im;
}

void complex_sub(ComplexNumber *self, ComplexNumber c)
{
    self->re -= c.re;
    self->im -= c.im;
}


// Test cases

TEST_GROUP(StructTestGroup)
{
};

TEST(StructTestGroup, InitTest)
{
    // Setup
    ComplexNumber c; 
	
    // Exercise
    complex_init(&c, 1.0, 2.0);

    // Verify
    DOUBLES_EQUAL(1.0, c.re, 1E-3);
    DOUBLES_EQUAL(2.0, c.im, 1E-3) ;
}

TEST(StructTestGroup, AddTest)
{
    // Setup
    ComplexNumber number = {1.0, 2.0}; 
    ComplexNumber c = {3.0, 4.0};

    // Exercise
    complex_add(&number,c);
    
    // Verify
    DOUBLES_EQUAL(1.0 + 3.0, number.re, 1E-3);
    DOUBLES_EQUAL(2.0 + 4.0, number.im, 1E-3) ;
}

TEST(StructTestGroup, SubTest)
{
    // Setup
    ComplexNumber number = {1.0, 2.0}; 
    ComplexNumber c = {3.0, 4.0};

    // Exercise
    complex_sub(&number,c);
    
    // Verify
    DOUBLES_EQUAL(1.0 - 3.0, number.re, 1E-3);
    DOUBLES_EQUAL(2.0 - 4.0, number.im, 1E-3) ;
}


TEST(StructTestGroup, HeapTest)
{
    // Setup
    ComplexNumber *c_ptr = (ComplexNumber *)malloc(sizeof(ComplexNumber)); 
	
    // Exercise
    complex_init(c_ptr, 1.0, 2.0);

    // Verify
    DOUBLES_EQUAL(1.0, c_ptr->re, 1E-3);
    DOUBLES_EQUAL(2.0, c_ptr->im, 1E-3) ;
    
    // Tear down
    free(c_ptr);
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
