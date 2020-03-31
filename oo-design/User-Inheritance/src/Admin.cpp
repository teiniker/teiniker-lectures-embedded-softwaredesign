#include <Admin.h>

Admin::Admin(const int id, const string& username, const string& password, Mail* mail)
	: User(id, username, mail), password_{password}
{
}
			
string Admin::password()
{
	return password_;
}
void Admin::password(const string& password)
{
	password_ = password;
}
		
