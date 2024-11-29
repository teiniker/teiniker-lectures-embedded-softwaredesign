#include "user.h"

#include <stdexcept>

using namespace std;

User::User(const int id, const string& username, const string& password)
{
	// Input Validation (Pre-Condition Checks)
	if(id < 0)
		throw invalid_argument("Invalid id!");
		
	if(username.length() < 4 || username.length() > 40)
		throw invalid_argument("Invalid username!");
		
	if(password.length() < 10)
		throw invalid_argument("Invalid password!");
		
	// Object initialization	
	_id = id;	
	_username = username;
	_password = password;
}
	
int User::id()
{
	return _id;
}
		
string User::username(void)
{
	return _username;
}
		
string User::password()
{
	return _password;
}
