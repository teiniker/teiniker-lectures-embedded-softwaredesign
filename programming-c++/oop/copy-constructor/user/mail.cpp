#include "mail.h"

using namespace std;

Mail::Mail(const string& address) 
    : _address{address} 
{
}

// Copy Constructor
Mail::Mail(const Mail& old)
{
    _address = old._address;
}
    
string Mail::address(void) const
{
    return _address;
}

void Mail::address(const std::string& address)
{
    _address = address;
}
