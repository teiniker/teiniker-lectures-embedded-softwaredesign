#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <vector>
#include <string>

class Logger
{
    private:
        std::vector<std::string> _log;
    public:		
        Logger(void);
        void debug(const std::string& message);
        void debug(const std::vector<double>& data);

        void info(const std::string& message);
        
        void error(const std::string& message);

        std::vector<std::string> getLog(void);
};

#endif /*_VALIDATOR_H_ */
