#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include <Mail.h>

using namespace std;

class User 
{
	private:
		int id_; 
		string username_;
		string password_;
		vector<Mail*> mails_;  	// ---[*]-> Mail
 
	public:                
		User(const int id, const string& username, const string& password);

		int id();
		void id(int id);
		
		string username(void);
		void username(const string& username);
		
		string password();
		void password(const string& password);
		
		// ---[*]-> Mail
		void addMail(Mail* mail);
		Mail* mail(int index);
		int numberOfMails(void);		
 };

#endif /*_USER_H_ */
