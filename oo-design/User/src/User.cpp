#include <User.h>
#include <Mail.h>

using namespace std;

User::User(int id, const string& username, const string& password, Mail* mail)
	: id_{id}, username_{username}, password_{password}, mail_{mail}
{
}
	
User::~User()
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
		
string User::username(void) const
{
	return username_;
}
void User::username(const string& username)
{
	username_ = username;	
}
		
string User::password() const
{
	return password_;
}
void User::password(const string& password)
{
	password_ = password;
}
		
Mail* User::mail()
{
	return mail_;
}
void User::maild(Mail* mail)
{
	mail_ = mail;
}		
