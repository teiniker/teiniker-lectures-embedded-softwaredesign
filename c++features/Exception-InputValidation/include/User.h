#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

using namespace std;

class User 
{
	private:
		int id_; 
		string username_;
		string password_;
 
	public:                
		User(const int id, const string& username, const string& password);

		int id();
		string username(void);
		string password();
 };

#endif /*_USER_H_ */
