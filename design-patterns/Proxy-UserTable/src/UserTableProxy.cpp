#include <UserTableProxy.h>
#include <stdexcept>
#include <iostream>

using namespace std;


UserTableProxy::UserTableProxy(std::shared_ptr<UserTable> table)
{
	table_ = table;
}
	
void UserTableProxy::insert(shared_ptr<User> user)
{
	cout << "UserTableProxy::insert()" << endl;

	// Pre-Processing
	if(user == NULL)
		throw invalid_argument("Invalid User (NULL)!");
		
	// Delegation" 
	table_->insert(user);	
	
	// Post-Processing"
}

shared_ptr<User> UserTableProxy::findUserById(int id)
{
	cout << "UserTableProxy::findById()" << endl;

	// Pre-Processing
	if(id < 0)
		throw invalid_argument("Invalid id (negative)!");

	// Delegation
	shared_ptr<User> user = table_->findUserById(id);

	// Post-Processing	
	return user;
}
