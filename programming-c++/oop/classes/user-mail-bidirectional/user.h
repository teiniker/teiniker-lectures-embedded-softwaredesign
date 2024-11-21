#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

// Forward declaration
class Mail;

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		// Constructor
		User(const int id, const std::string& username, const std::string& password, Mail* mail);

		// Accessors
		int id(void) const;
		std::string username(void) const;
		std::string password() const;
		
		// Association --[1]-> Mail
		Mail* mail(void) const;
		void mail(Mail* mail);
 };

#endif /*_USER_H_ */
