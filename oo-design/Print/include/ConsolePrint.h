#ifndef _CONSOLE_PRINT_H_
#define _CONSOLE_PRINT_H_

#include <Print.h>

class ConsolePrint : public Print 
{
	public:
		~ConsolePrint(void) {}
		
		size_t write(int c) override;				
};
 
#endif /*_CONSOLE_PRINT_H_ */
