#ifndef _USERTABLEIMPL_H_
#define _USERTABLEIMPL_H_

#include <UserTable.h>
#include <vector>

class UserTableImpl : public UserTable
{
	private:
		std::vector<std::shared_ptr<User>> table_;
		 
	public:                
		void insert(std::shared_ptr<User> user);
		std::shared_ptr<User> findUserById(int id);
 };

#endif /*_USERTABLEIMPL_H_ */
