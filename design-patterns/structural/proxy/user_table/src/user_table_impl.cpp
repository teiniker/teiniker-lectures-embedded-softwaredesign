#include <user_table_impl.h>

using namespace std;

	
void UserTableImpl::insert(std::shared_ptr<User> user)
{
	_table.push_back(user);
}

std::shared_ptr<User> UserTableImpl::findUserById(int id)
{
	for(std::shared_ptr<User> user : _table)
	{
		if(user->id() == id)
			return user;
	}
	return NULL;
}
