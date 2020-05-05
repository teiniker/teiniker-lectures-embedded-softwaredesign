#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <Mail.h>

class User 
{
	private:
		int id_; 
		std::string username_;
		std::string password_;
		Mail* mail_ = NULL;			// ---[1]-> Mail
 
	public:                
		User(const int id, const std::string& username, const std::string& password, Mail* mail);
		User(const User& old);	// Copy Constructor
		User& operator =(const User& orig); // Assignment Operator

		int id();
		std::string username(void);
		std::string password();
		
		// ---[1]-> Mail
		Mail* mail();
		void mail(Mail* mail);
 };

#endif /*_USER_H_ */
