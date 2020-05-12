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
		~Mail(void);
    
		string address(void);
		void address(const string& address);
 };

#endif /*_MAIL_H_ */
