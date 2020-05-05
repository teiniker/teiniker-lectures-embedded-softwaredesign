#include <User.h>
#include <Mail.h>

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: id_{id}, username_{username}, password_{password}, mail_{mail}
{
}

// Copy Constructor
User::User(const User& old)
{
	id_ = old.id_;
	username_ = old.username_;
	password_ = old.password_;
	mail_ = new Mail(*old.mail_);	// Deep Copy
	//mail_ = old.mail_;	// Shallow copy
}
	
	
int User::id()
{
	return id_;
}
		
string User::username(void)
{
	return username_;
}
		
string User::password()
{
	return password_;
}

// ---[1]-> Mail		
Mail* User::mail()
{
	return mail_;
}
void User::mail(Mail* mail)
{
	mail_ = mail;
}		
