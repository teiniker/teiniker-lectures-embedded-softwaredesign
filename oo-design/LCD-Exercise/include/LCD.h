#ifndef _LCD_H_
#define _LCD_H_

#include <string>
#include <cstdint>

using namespace std;

class LCD 
{
	private:
		size_t cols_;
		size_t rows_; 
		
		char* buffer_;
		size_t index_;
 
	public:
		LCD(size_t cols, size_t rows);
		~LCD(); 

		void clear(void);
		void print(char c);
		void print(const char * c_ptr);

		char* buffer(void);	
 };

#endif /*_LCD_H_ */
