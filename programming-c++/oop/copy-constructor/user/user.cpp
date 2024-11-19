#include "user.h"

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: _id{id}, _username{username}, _password{password}, _mail{mail}
{
}

// Copy Constructor
User::User(const User& old)
{
	_id = old._id;
	_username = old._username;
	_password = old._password;
	_mail = new Mail(*old._mail);	// Deep Copy
	//_mail = old._mail;			// Shallow copy
}
	
	
int User::id() const
{
	return _id;
}
		
string User::username(void) const
{
	return _username;
}
		
string User::password() const
{
	return _password;
}

// ---[1]-> Mail		
Mail* User::mail()
{
	return _mail;
}
void User::mail(Mail* mail)
{
	_mail = mail;
}		
