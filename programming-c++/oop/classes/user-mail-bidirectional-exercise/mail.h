#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

class Mail 
{
	private:
		std::string _address; 
 
	public:
		// Constructor
		Mail(const std::string& address);
    
		// Accessors
		std::string address() const;
};

#endif /*_MAIL_H_ */
