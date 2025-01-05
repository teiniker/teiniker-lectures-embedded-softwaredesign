#include <iostream>
#include <mail.h>

using namespace std;

Mail::Mail(const string& address) 
    : _address{address} 
{
    cout << "Mail - constructor" << endl;
}
    
Mail::~Mail(void) 
{
    cout << "Mail - destructor" << endl;
}
    
string Mail::address() const
{
    return _address;
}

void Mail::address(const string& address)
{
    _address = address;
}
