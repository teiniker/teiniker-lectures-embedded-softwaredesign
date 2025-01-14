#include <vector>
#include <logger.h>

using namespace std;

Logger::Logger(void)
{
    _log = vector<string>();
}   

void Logger::debug(const std::string& message)
{
    _log.push_back("DEBUG: " + message);
}

void Logger::debug(const std::vector<double>& data)
{
    string message = "DEBUG: ";
    for (size_t i = 0; i < data.size(); i++)
    {
        message += to_string(data[i]) + " ";
    }
    _log.push_back(message);
}

void Logger::info(const std::string& message)
{
    _log.push_back("INFO: " + message);
}

void Logger::error(const std::string& message)
{
    _log.push_back("ERROR: " + message);
}

std::vector<std::string> Logger::getLog(void)
{
    return _log;
}
