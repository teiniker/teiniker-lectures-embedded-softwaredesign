#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

using namespace std;

class Mail 
{
	private:
		string _address; 
 
	public:
		Mail(const string& address);
		~Mail(void);
    
		string address(void) const;
		void address(const string& address);
 };

#endif /*_MAIL_H_ */
