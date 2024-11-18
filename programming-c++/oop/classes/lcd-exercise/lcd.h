#ifndef _LCD_H_
#define _LCD_H_

#include <cstdint>
#include <cstdlib>

class LCD 
{
	private:
		size_t _cols;
		size_t _rows; 
		
		char* _buffer;
		size_t _index;
 
	public:
		LCD(size_t cols, size_t rows); // Constructor
		~LCD(void); // Destructor

		void clear(void);
		void print(char c);
		void print(const char * c_ptr);

		char* buffer(void) const // Inline-Operation
		{
			return _buffer;
		}
 };

#endif /*_LCD_H_ */
