#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <iostream>

using namespace std;

// SUT

class ComplexNumber
{
    private: 
        double re_;
        double im_;
 
    public:
        ComplexNumber(double re, double im) : re_{re}, im_{im}
        {
            cout << "constructor" << endl; 
            //re_ = re;
            //im_ = im;
        }
        ComplexNumber() : re_{0}, im_{0}
        {
            cout << "constructor - default" << endl;
        }
        ~ComplexNumber() 
        {
            cout << "destructor" << endl;            
        }
        
        double real()
        {
            return re_;
        }
        void real(double re)
        {
            // Input validation
            re_ = re;
        }
        
        double imag()
        {
            return im_;
        }
        void imag(double im)
        {
            im_ = im;
        }
        
        void add(ComplexNumber c);
        void sub(ComplexNumber c);
};

// Methods of a class can be implemented in a different place as well.

void ComplexNumber::add(ComplexNumber c)
{
    re_ += c.real();
    im_ += c.imag();
}

void ComplexNumber::sub(ComplexNumber c)
{
    re_ -= c.real();
    im_ -= c.imag();
}


// Test cases

TEST_GROUP(ClassTestGroup)
{
};


TEST(ClassTestGroup, ConstructorTest)
{
    // Setup & Exercise
    ComplexNumber c(1.0, 2.0); // stack

    // Verify
    DOUBLES_EQUAL(1.0, c.real(), 1E-3);
    DOUBLES_EQUAL(2.0, c.imag(), 1E-3) ;
}


TEST(ClassTestGroup, DefaultConstructorTest)
{
    // Setup & Exercise
    ComplexNumber c; // stack

    // Verify
    DOUBLES_EQUAL(0.0, c.real(), 1E-3);
    DOUBLES_EQUAL(0.0, c.imag(), 1E-3) ;
}


TEST(ClassTestGroup, ChangeValuesTest)
{
    // Setup & Exercise
    ComplexNumber c(1.0, 2.0); // stack 
    c.real(7.0);
    c.imag(3.0);

    // Verify
    DOUBLES_EQUAL(7.0, c.real(), 1E-3);
    DOUBLES_EQUAL(3.0, c.imag(), 1E-3) ;
}


TEST(ClassTestGroup, AddTest)
{
    // Setup
    ComplexNumber number(1.0, 2.0); 
    ComplexNumber c(3.0, 4.0);

    // Exercise
    number.add(c);
    
    // Verify
    DOUBLES_EQUAL(1.0 + 3.0, number.real(), 1E-3);
    DOUBLES_EQUAL(2.0 + 4.0, number.imag(), 1E-3) ;
}


TEST(ClassTestGroup, SubTest)
{
    // Setup
    ComplexNumber number(1.0, 2.0); 
    ComplexNumber c(3.0, 4.0);

    // Exercise
    number.sub(c);
    
    // Verify
    DOUBLES_EQUAL(1.0 - 3.0, number.real(), 1E-3);
    DOUBLES_EQUAL(2.0 - 4.0, number.imag(), 1E-3) ;
}


TEST(ClassTestGroup, HeapTest)
{
    // Setup & Exercise
    ComplexNumber *c_ptr = new ComplexNumber(1.0, 2.0); // heap

    // Verify
    DOUBLES_EQUAL(1.0, c_ptr->real(), 1E-3);
    DOUBLES_EQUAL(2.0, c_ptr->imag(), 1E-3) ;
    
    // Tear down
    delete c_ptr;
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
