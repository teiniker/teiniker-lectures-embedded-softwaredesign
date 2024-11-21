#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
 
	public:                
		// Constructor
		User(const int id, const std::string& username, const std::string& password);

		// Accessors
		int id(void) const;
		std::string username(void) const;
		std::string password() const;
 };

#endif /*_USER_H_ */
