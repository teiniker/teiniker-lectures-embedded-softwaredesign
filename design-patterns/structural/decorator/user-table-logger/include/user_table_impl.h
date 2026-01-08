#ifndef _USERTABLEIMPL_H_
#define _USERTABLEIMPL_H_

#include <vector>
#include <user_table.h>

class UserTableImpl : public UserTable
{
	private:
		std::vector<std::shared_ptr<User>> _table;
		 
	public:                
		void insert(std::shared_ptr<User> user) override;
		std::shared_ptr<User> findUserById(int id) override;
 };

#endif /*_USERTABLEIMPL_H_ */
