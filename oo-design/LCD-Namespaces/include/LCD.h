#ifndef _LCD_H_
#define _LCD_H_

#include <cstdint>

namespace org
{
	namespace se
	{
		namespace lab
		{
			class LCD 
			{
				private:
					size_t cols_;
					size_t rows_; 
					
					char* buffer_;
					size_t index_;
			 
				public:
					LCD(size_t cols, size_t rows); // Constructor
					~LCD(void); // Destructor

					void clear(void);
					void print(char c);
					void print(const char * c_ptr);

					char* buffer(void)  // Inline-Operation
					{
						return buffer_;
					}
					
			 };
		} // end of lab
	} // end of se
} // end of org	

#endif /*_LCD_H_ */
