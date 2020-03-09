#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

using namespace std;

class Mail 
{
	private:
		string address_; 
 
	public:
		Mail(const string& address);
		~Mail(); 
    
		string address();
		void address(const string& address);
 };

#endif /*_MAIL_H_ */
