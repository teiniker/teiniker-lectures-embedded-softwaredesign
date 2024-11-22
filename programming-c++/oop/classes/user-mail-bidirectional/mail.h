#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>
#include "user.h"

class Mail 
{
	private:
		std::string _address; 
		User* _user;			// ---[1]-> User
 
	public:
		// Constructor
		Mail(const std::string& address);
    
		// Accessors
		std::string address() const;

		// Association
		// ---[1]-> User
		User* user(void) const;
		void user(User* user);
 };

#endif /*_MAIL_H_ */
