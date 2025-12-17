#ifndef _USERTABLE_DECORATOR_H_
#define _USERTABLE_DECORATOR_H_

#include <user_table.h>

// Decorator base class
class UserTableDecorator : public UserTable
{
	private:
		std::shared_ptr<UserTable> _table;
		 
	public:                
		UserTableDecorator(std::shared_ptr<UserTable> table);
		virtual ~UserTableDecorator(void) {}

		virtual void insert(std::shared_ptr<User> user) override;
		virtual std::shared_ptr<User> findUserById(int id) override;
 };


 // Concreate Decorator
class UserTableLogger : public UserTableDecorator
{
	public:                
		UserTableLogger(std::shared_ptr<UserTable> table);
		
		void insert(std::shared_ptr<User> user) override;
		std::shared_ptr<User> findUserById(int id) override;
 };


#endif /*_USERTABLE_DECORATOR_H_ */