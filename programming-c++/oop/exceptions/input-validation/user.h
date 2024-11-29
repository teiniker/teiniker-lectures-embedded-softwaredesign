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

		int id();
		std::string username(void);
		std::string password();
 };

#endif /*_USER_H_ */
