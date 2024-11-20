#include "user.h"
#include "mail.h"

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
	_mail = new Mail(*old._mail);
}

// Assignment Operator
User& User::operator =(const User& orig)
{
	_id=orig._id;
	_username=orig._username;
	_password=orig._password;
	
	if(_mail != NULL)
		delete _mail;
	_mail= new Mail(*orig._mail);
	
	return *this;	
}	
	
int User::id(void) const
{
	return _id;
}
		
string User::username(void) const
{
	return _username;
}
		
string User::password(void)	const
{
	return _password;
}

// ---[1]-> Mail		
Mail* User::mail(void)
{
	return _mail;
}
void User::mail(Mail* mail)
{
	_mail = mail;
}		
