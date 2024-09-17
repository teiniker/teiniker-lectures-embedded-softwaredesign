#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

class Mail 
{
	private:
		std::string address_; 
 
	public:
		Mail(const std::string& address);
		Mail(const Mail& old);	// Copy Constructor
    
		std::string address(void);
		void address(const std::string& address);
 };

#endif /*_MAIL_H_ */
