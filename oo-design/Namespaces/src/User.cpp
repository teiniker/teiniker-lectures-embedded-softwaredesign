#include <User.h>

using namespace std;
using namespace org::se::lab;

User::User(const int id, const string& username, const string& password)
	: id_{id}, username_{username}, password_{password}
{
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
