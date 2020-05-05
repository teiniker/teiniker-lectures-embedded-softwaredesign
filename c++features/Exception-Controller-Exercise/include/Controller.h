#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <GPIO.h>


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
