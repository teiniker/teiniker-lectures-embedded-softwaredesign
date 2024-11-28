#ifndef _LCD_H_
#define _LCD_H_

#include <cstdlib>
#include "display.h"

class LCD : public Display
{
	private:
		size_t _cols;
		size_t _rows; 		
		size_t _index;
		char* _buffer;
 
	public:
		LCD(size_t cols, size_t rows); 	// Constructor
		~LCD(void); 					// Destructor

		// Accessors
		char* buffer(void) const;

		// Methods
		void clear(void) override;
		void print(char c) override;
		void print(const char * c_ptr) override;
 };

#endif /*_LCD_H_ */
