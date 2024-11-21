#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: _id{id}, _username{username}, _password{password}, _mail{mail}
{
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
Mail* User::mail() const
{
	return _mail;
}
void User::mail(Mail* mail)
{
	_mail = mail;
}		
