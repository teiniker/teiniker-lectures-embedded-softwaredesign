#include <User.h>

using namespace std;

User::User(const int id, const string& username, const string& password)
	: id_{id}, username_{username}, password_{password}
{
}
	
int User::id(void)
{
	return id_;
}
		
string User::username(void)
{
	return username_;
}
		
string User::password(void)
{
	return password_;
}
