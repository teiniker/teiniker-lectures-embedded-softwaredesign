#ifndef _PRINT_H_
#define _PRINT_H_

#include <string>

class Print 
{
	public:  
		virtual ~Print(void) {}

		// Pure virtual method
		virtual size_t write(int c) = 0;
		
		// All print() methods use write() to output their parameters.
		size_t print(char c);
		size_t print(const char* s);
		size_t print(const std::string& s);
		//... 
 };

#endif /*_PRINT_H_ */
