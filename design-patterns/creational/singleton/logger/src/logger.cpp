#include <iostream>
#include <logger.h>

using namespace std;

Logger* Logger::_INSTANCE= nullptr;;

// Return the static instance of Logger
Logger* Logger::getInstance()
{
	if(_INSTANCE == nullptr)
	{
		_INSTANCE = new Logger();
	}
	return _INSTANCE;
}

// Log an error message
void Logger::error(const std::string& msg)
{
    print("ERROR: " + msg);
}

// Log a warning message
void Logger::warning(const std::string& msg)
{
    print("WARNING: " + msg);
}

// Log an info message
void Logger::info(const std::string& msg)
{
    print("INFO: " + msg);
}

// Log a debug message
void Logger::debug(const std::string& msg)
{
    print("DEBUG: " + msg);
}

// Print the message to standard output
void Logger::print(const std::string& s)
{
    std::cout << s << std::endl;
}
