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
		Mail* mail_;
 
	public:                
		User(int id, const string& username, Mail* mail);

		int id();
		void id(int id);
		
		string username(void);
		void username(const string& username);

		Mail* mail();
		void maild(Mail* mail);		
 };

#endif /*_USER_H_ */
