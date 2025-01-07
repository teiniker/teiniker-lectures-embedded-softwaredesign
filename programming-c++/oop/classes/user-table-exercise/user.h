#ifndef _USER_H_
#define _USER_H_

#include <string>

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;

	public:                
		User(const int id, const std::string& username, const std::string& password);

		int id(void) const;
		void id(const int id);
		
		std::string username(void) const;
		void username(const std::string& username);
		
		std::string password() const;
		void password(const std::string& password);
 };

#endif /*_USER_H_ */
