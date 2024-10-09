#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

class Mail 
{
	private:
		std::string address_; 
 
	public:
		Mail(); // Default Constructor
		Mail(const std::string& address);
		Mail(const Mail& old);	// Copy Constructor   
		Mail& operator= (const Mail &orig);	// Assigment Operator
			 
		std::string address(void);
		void address(const std::string& address);
 };

#endif /*_MAIL_H_ */
