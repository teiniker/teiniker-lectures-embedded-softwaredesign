#ifndef _USERTABLEPROXY_H_
#define _USERTABLEPROXY_H_

#include <user_table.h>

class UserTableProxy : public UserTable
{
	private:
		std::shared_ptr<UserTable> _table;
		 
	public:                
		UserTableProxy(std::shared_ptr<UserTable> table);
		
		void insert(std::shared_ptr<User> user) override;
		std::shared_ptr<User> findUserById(int id) override;
 };

#endif /*_USERTABLEPROXY_H_ */
