#include "user.h"

using namespace std;

User::User(const int id, const string& username, const string& password)
	: _id{id}, _username{username}, _password{password}
{
}
	
int User::id() const
{
	return _id;
}
void User::id(const int id)
{
	_id = id;
}
		
string User::username(void) const
{
	return _username;
}
void User::username(const string& username)
{
	_username = username;	
}
		
string User::password() const
{
	return _password;
}
void User::password(const string& password)
{
	_password = password;
}

