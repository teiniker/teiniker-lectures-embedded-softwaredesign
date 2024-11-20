#include "mail.h"

using namespace std;

Mail::Mail(const string& address) 
    : _address{address} 
{
}

// Default Constructor
Mail::Mail() 
{
    _address = "";
}

// Copy Constructor
Mail::Mail(const Mail& old)
{
    _address = old._address;
}
    
// Assigment Operator    
Mail& Mail::operator= (const Mail &orig)
{
    _address = orig._address;    
    return *this;
}	
    
string Mail::address(void) const
{
    return _address;
}

void Mail::address(const string& address)
{
    _address = address;
}
