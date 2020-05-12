#ifndef _USERTABLEPROXY_H_
#define _USERTABLEPROXY_H_

#include <UserTable.h>

class UserTableProxy : public UserTable
{
	private:
		std::shared_ptr<UserTable> table_;
		 
	public:                
		UserTableProxy(std::shared_ptr<UserTable> table);
		void insert(std::shared_ptr<User> user);
		std::shared_ptr<User> findUserById(int id);
 };

#endif /*_USERTABLEPROXY_H_ */
