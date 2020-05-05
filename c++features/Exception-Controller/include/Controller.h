#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <GPIO.h>
#include <iostream>


class ControllerException : public std::exception 
{
	private:
		std::string cause_;
		
	public:
		ControllerException(const std::string& cause) : cause_{cause} {}
		
		const char* what() const noexcept
		{
			return cause_.c_str();
		}
};


class Controller 
{
	private:
		GPIO* io_ = NULL;
		
	public:                
		Controller();		
		~Controller();
		
		// ...		
 };

#endif /*_CONTROLLER_H_ */
