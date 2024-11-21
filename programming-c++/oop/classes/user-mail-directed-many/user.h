#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		std::vector<Mail*> _mails;  // ---[*]-> OrderLine
 
	public:         
		// Constructor       
		User(const int id, const std::string& username, const std::string& password);

		// Accessors
		int id(void) const;
		std::string username(void) const;
		std::string password() const;
		
		// Association --[1]-> Mail
		void addMail(Mail* mail);
		Mail* mail(int index) const; 
		size_t numberOfMails(void) const;
 };

#endif /*_USER_H_ */
