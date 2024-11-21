#include "mail.h"
#include "user.h"

using namespace std;

Mail::Mail(const string& address) 
    : _address{address}
{
    _user = NULL;
}
    
string Mail::address() const
{
    return _address;
}

User* Mail::user()
{
    return _user;
}

void Mail::user(User* user)
{
    _user = user;
}