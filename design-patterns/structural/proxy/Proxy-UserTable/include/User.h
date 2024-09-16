#ifndef _USER_H_
#define _USER_H_

#include <string>

class User 
{
	private:
		int id_; 
		std::string username_;
		std::string password_;
 
	public:                
		User(const int id, const std::string& username, const std::string& password);

		int id();	
		std::string username(void);		
		std::string password(void);
 };

#endif /*_USER_H_ */
