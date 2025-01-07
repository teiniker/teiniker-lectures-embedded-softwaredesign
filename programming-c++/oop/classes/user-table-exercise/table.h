#ifndef _USER_TABLE_H_
#define _USER_TABLE_H_

#include <string>
#include <vector>
#include "user.h"

class UserTable 
{
	private:
		std::vector<User> _table; 
 
	public:
		UserTable(void);
    
		void insertUser(const User& user);
		void updateUser(const User& user);
		User& findById(const int id);
		User& findByUsername(const std::string& username);
		size_t size() const;
 };

#endif /*_USER_TABLE_H_ */
