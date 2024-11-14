#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "mail.h"

using namespace std;

class User 
{
	private:
		int _id; 
		string _username;
		string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		User(const int id, const string& username, const string& password, Mail* mail);

		int id();
		void id(int id);
		
		string username(void);
		void username(const string& username);
		
		string password();
		void password(const string& password);
		
		// ---[1]-> Mail
		Mail* mail();
		void mail(Mail* mail);
 };

#endif /*_USER_H_ */
