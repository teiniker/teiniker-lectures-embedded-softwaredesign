#include <iostream>
#include <logger.h>

using namespace std;

// Singleton  

shared_ptr<Logger> Logger::instance = nullptr;

shared_ptr<Logger> Logger::getInstance()
{
    if(instance == nullptr) 
    {
        instance = shared_ptr<Logger>(new Logger());
    }
    return instance;
}

// Logger Methods 

void Logger::error(const string& msg)
{
    print("ERROR: " + msg);
}

void Logger::warning(const string& msg)
{
    print("WARNING: " + msg);
}

void Logger::info(const string& msg)
{
    print("INFO: " + msg);
}

void Logger::debug(const string& msg)
{
    print("DEBUG: " + msg);
}

void Logger::print(const string& s)
{
    cout << s << endl;
}
