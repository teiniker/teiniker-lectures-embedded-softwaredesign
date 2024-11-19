#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		User(const int id, const std::string& username, const std::string& password, Mail* mail);
		User(const User& old);	// Copy Constructor

		int id() const;	
		std::string username(void) const;
		std::string password() const;
		
		// ---[1]-> Mail
		Mail* mail();
		void mail(Mail* mail);
 };

#endif /*_USER_H_ */
