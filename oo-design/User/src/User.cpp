#include <User.h>
#include <Mail.h>

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: id_{id}, username_{username}, password_{password}, mail_{mail}
{
}
	
int User::id()
{
	return id_;
}
void User::id(int id)
{
	id_ = id;
}
		
string User::username(void)
{
	return username_;
}
void User::username(const string& username)
{
	username_ = username;	
}
		
string User::password()
{
	return password_;
}
void User::password(const string& password)
{
	password_ = password;
}

// ---[1]-> Mail		
Mail* User::mail()
{
	return mail_;
}
void User::maild(Mail* mail)
{
	mail_ = mail;
}		
