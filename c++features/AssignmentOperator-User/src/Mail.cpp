#include <Mail.h>

using namespace std;

Mail::Mail(const string& address) 
    : address_{address} 
{
}

// Default Constructor
Mail::Mail() 
{
    address_ = "";
}

// Copy Constructor
Mail::Mail(const Mail& old)
{
    address_ = old.address_;
}
    
// Assigment Operator    
Mail& Mail::operator= (const Mail &orig)
{
    address_ = orig.address_;    
    return *this;
}	
    
string Mail::address(void)
{
    return address_;
}

void Mail::address(const std::string& address)
{
    address_ = address;
}
