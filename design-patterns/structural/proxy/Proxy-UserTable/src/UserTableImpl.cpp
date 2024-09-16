#include <UserTableImpl.h>

using namespace std;

	
void UserTableImpl::insert(std::shared_ptr<User> user)
{
	table_.push_back(user);
}

std::shared_ptr<User> UserTableImpl::findUserById(int id)
{
	for(std::shared_ptr<User> u : table_)
	{
		if(u->id() == id)
			return u;
	}
	return NULL;
}
