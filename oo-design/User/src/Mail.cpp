#include <Mail.h>

Mail::Mail(const string& address) 
    : address_{address} 
{
}
    
string Mail::address()
{
	return address_;
}

void Mail::address(const string& address)
{
	address_ = address;
}
