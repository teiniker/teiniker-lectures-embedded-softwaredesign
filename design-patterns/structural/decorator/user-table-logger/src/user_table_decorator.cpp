#include <stdexcept>
#include <iostream>
#include <user_table_decorator.h>

using namespace std;

// Decorator base class
UserTableDecorator::UserTableDecorator(std::shared_ptr<UserTable> table)
{
	_table = table;
}
	
void UserTableDecorator::insert(shared_ptr<User> user)
{
	// Delegation only
	_table->insert(user);	
}

shared_ptr<User> UserTableDecorator::findUserById(int id)
{	
	// Delegation only
	shared_ptr<User> user = _table->findUserById(id);
	return user;
}


// Concreate Decorator

UserTableLogger::UserTableLogger(std::shared_ptr<UserTable> table)
: UserTableDecorator(table)
{
}

void UserTableLogger::insert(shared_ptr<User> user)
{
	// Pre-Processing
	cout << "UserTableLogger::insert(" << user->id() << ", " << user->username() << ")" << endl;

	// Delegation to the base class
	UserTableDecorator::insert(user);	
	
	// Post-Processing
}

shared_ptr<User> UserTableLogger::findUserById(int id)
{	
	// Pre-Processing
	cout << "UserTableLogger::findUserById(" << id << ")" << endl;		
	
	// Delegation to the base class
	shared_ptr<User> user = UserTableDecorator::findUserById(id);
	
	// Post-Processing
	return user;
}
