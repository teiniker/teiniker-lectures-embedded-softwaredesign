#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <memory>

class Logger
{
public:
    // Singleton
    static std::shared_ptr<Logger> instance;
    static std::shared_ptr<Logger> getInstance();

    // Operations
    void error(const std::string& msg);
    void warning(const std::string& msg);
    void info(const std::string& msg);
    void debug(const std::string& msg);

private:
    // Private constructor to prevent direct instantiation
    Logger() {};

    // Utility method
    void print(const std::string& s);

    // Singletons should not be cloneable.
    Logger(Logger &other) = delete;

    // Singletons should not be assignable.
    void operator=(const Logger &) = delete;
};

#endif // _LOGGER_H_