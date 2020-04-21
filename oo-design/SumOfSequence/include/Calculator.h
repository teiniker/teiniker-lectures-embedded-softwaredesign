#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

// Abstract base class
// An abstract type completely insulates a user from implementation details.
// Note that this class is a pure interface to concrete implamentations (which 
// inherit from this abstract type).
class Calculator 
{
	public:  
		// This funny syntax "= 0" says that this method is "pure virtual"; 
		// that means that some clas derived from Calculator must implement the
		// method.
		// A class with a pure virtual method is called an "abstract class". 
		virtual int sumOfSequence(int n) = 0;
		
		// If the object that the pointer is pointing to is deleted, and the 
		// destructor is not set to "virtual", then the base class destructor 
		// will be called instead of the derived class destructor.		
		virtual ~Calculator(void) {}
 };

#endif /*_CALCULATOR_H_ */
