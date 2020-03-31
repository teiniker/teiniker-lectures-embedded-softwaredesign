#include <User.h>
#include <Mail.h>

using namespace std;

User::User(const int id, const string& username, const string& password)
	: id_{id}, username_{username}, password_{password}
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

// ---[*]-> Mail
void User::addMail(Mail* mail)
{
	mails_.push_back(mail);
}

Mail* User::mail(int index)
{
	return mails_[index];
}

int User::numberOfMails(void)
{
	return mails_.size();
}	
