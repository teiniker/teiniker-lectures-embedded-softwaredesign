#ifndef _USER_H_
#define _USER_H_

#include <string>

#include <Mail.h>

using namespace std;

class User 
{
	private:
		int id_; 
		string username_;
		string password_;
		Mail* mail_;
 
	public:
		User(int id, const string& username, const string& password, Mail* mail_ptr);
		~User(); 

		int id();
		void id(int id);
		
		string username(void) const;
		void username(const string& username);
		
		string password() const;
		void password(const string& password);
		
		Mail* mail();
		void maild(Mail* mail);		
 };

#endif /*_USER_H_ */
