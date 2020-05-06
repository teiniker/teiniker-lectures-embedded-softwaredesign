#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <string>

#include <User.h>
#include <Mail.h>

using namespace std;

class Admin : public User
{
	private:
		string password_;
 
	public:                
		Admin(int id, const string& username, const string& password, Mail* mail);

		string password();
		void password(const string& password);
 };

#endif /*_USER_H_ */
