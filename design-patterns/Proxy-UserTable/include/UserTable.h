#ifndef _USERTABLE_H_
#define _USERTABLE_H_

#include <User.h>
#include <memory>

class UserTable 
{
	public:                
		virtual ~UserTable(void) {}

		virtual void insert(std::shared_ptr<User> user) = 0;
		virtual std::shared_ptr<User> findUserById(int id) = 0;
 };

#endif /*_USERTABLE_H_ */
