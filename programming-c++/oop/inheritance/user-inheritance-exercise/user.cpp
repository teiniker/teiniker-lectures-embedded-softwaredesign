#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, Mail* mail)
	: _id{id}, _username{username}, _mail{mail}
{
}
	
int User::id()
{
	return _id;
}
void User::id(int id)
{
	_id = id;
}
		
string User::username(void)
{
	return _username;
}
void User::username(const string& username)
{
	_username = username;	
}
		
Mail* User::mail()
{
	return _mail;
}
void User::maild(Mail* mail)
{
	_mail = mail;
}		
