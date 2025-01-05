#include <stdexcept>
#include <iostream>
#include <user_table_proxy.h>

using namespace std;


UserTableProxy::UserTableProxy(std::shared_ptr<UserTable> table)
{
	_table = table;
}
	
void UserTableProxy::insert(shared_ptr<User> user)
{
	cout << "UserTableProxy::insert()" << endl;

	// Pre-Processing
	if(user == NULL)
		throw invalid_argument("Invalid User (NULL)!");
		
	// Delegation" 
	_table->insert(user);	
	
	// Post-Processing
}

shared_ptr<User> UserTableProxy::findUserById(int id)
{
	cout << "UserTableProxy::findById()" << endl;

	// Pre-Processing
	if(id < 0)
		throw invalid_argument("Invalid id (negative)!");

	// Delegation
	shared_ptr<User> user = _table->findUserById(id);

	// Post-Processing	
	return user;
}
