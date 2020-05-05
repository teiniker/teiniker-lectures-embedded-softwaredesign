#include <Mail.h>

using namespace std;

Mail::Mail(const string& address) 
    : address_{address} 
{
}

// Copy Constructor
Mail::Mail(const Mail& old)
{
    address_ = old.address_;
}
    
string Mail::address(void)
{
    return address_;
}

void Mail::address(const std::string& address)
{
    address_ = address;
}
