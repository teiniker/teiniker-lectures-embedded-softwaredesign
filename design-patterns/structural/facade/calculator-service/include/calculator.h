#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <vector>
#include <string>
#include <validator.h>
#include <evaluator.h>
#include <logger.h>

class CalculatorService
{
    private:
        Validator* _validator;
        Evaluator* _evaluator;
        Logger* _logger;
        
    public:		
        CalculatorService(void);
        ~CalculatorService(void);

        double calculateMeanValue(const std::vector<double>& data);
        //...
        std::vector<std::string> getLog(void);
};

#endif /*_CALCULATOR_H_ */
