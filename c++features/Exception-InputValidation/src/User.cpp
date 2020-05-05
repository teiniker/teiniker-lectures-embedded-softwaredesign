#include <User.h>

#include <stdexcept>

using namespace std;

User::User(const int id, const string& username, const string& password)
{
	// Input Validation (Pre-Conditions)
	if(id < 0)
		throw invalid_argument("Invalid id!");
		
	if(username.length() < 4 || username.length() > 40)
		throw invalid_argument("Invalid username!");
		
	if(password.length() < 10)
		throw invalid_argument("Invalid password!");
	
	// Implementation	
	id_ = id;	
	username_ = username;
	password_ = password;
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
