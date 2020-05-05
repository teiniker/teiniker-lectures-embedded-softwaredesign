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
	mail_ = new Mail(*old.mail_);
}

// Assignment Operator
User& User::operator =(const User& orig)
{
	id_=orig.id_;
	username_=orig.username_;
	password_=orig.password_;
	
	if(mail_ != NULL)
		delete mail_;
	mail_= new Mail(*orig.mail_);
	
	return *this;	
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
