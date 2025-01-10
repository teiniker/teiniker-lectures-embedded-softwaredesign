#include <string>
#include <vector>
#include <memory>

#include <display.h>

using namespace std;

// Singleton  

shared_ptr<Display> Display::instance = nullptr;

shared_ptr<Display> Display::getInstance()
{
    if(instance == nullptr) 
    {
        instance = shared_ptr<Display>(new Display());
    }
    return instance;
}

// Operations 

void Display::print(const string& msg)
{
    _buffer.push_back(msg);
}

void Display::print(const int i)
{
    _buffer.push_back(to_string(i));
}

void Display::print(const double d)
{
    _buffer.push_back(to_string(d));
}

vector<string>& Display::getBuffer(void)
{
    return _buffer;
}