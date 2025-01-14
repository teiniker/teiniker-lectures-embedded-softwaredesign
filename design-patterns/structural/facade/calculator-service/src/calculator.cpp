#include <stdexcept>
#include <calculator.h>

using namespace std;

CalculatorService::CalculatorService(void)
{
    _logger = new Logger();
    _validator = new Validator();
    _evaluator = new Evaluator();
}

CalculatorService::~CalculatorService(void)
{
    delete _logger;
    delete _validator;
    delete _evaluator;
}

double CalculatorService::calculateMeanValue(const vector<double>& data)
{
    // Validate data
    if (!_validator->isValid(data))
        throw invalid_argument("Invalid data");

    // Log data
    _logger->debug(data);

    // Calculate mean value
    double mean = _evaluator->mean(data);
    return mean;
}

std::vector<std::string> CalculatorService::getLog(void)
{
    return _logger->getLog();
}
