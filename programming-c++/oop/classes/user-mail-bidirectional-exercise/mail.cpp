#include "mail.h"
#include "user.h"

using namespace std;

Mail::Mail(const string& address) 
    : _address{address}
{
}
    
string Mail::address() const
{
    return _address;
}

