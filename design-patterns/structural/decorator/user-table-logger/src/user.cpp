#include <user.h>

using namespace std;

User::User(const int id, const string& username, const string& password)
	: _id{id}, _username{username}, _password{password}
{
}
	
int User::id(void) const
{
	return _id;
}
		
string User::username(void) const
{
	return _username;
}
		
string User::password(void) const
{
	return _password;
}
