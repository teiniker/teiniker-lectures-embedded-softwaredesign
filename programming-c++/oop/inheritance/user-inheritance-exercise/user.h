#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		Mail* _mail;
 
	public:                
		User(int id, const std::string& username, Mail* mail);

		int id();
		void id(int id);
		
		std::string username(void);
		void username(const std::string& username);

		Mail* mail();
		void maild(Mail* mail);		
 };

#endif /*_USER_H_ */
