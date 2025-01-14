#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <vector>

class Validator
{
    public:		
        bool isInRange(const std::vector<double>& data, const double min, const double max);
        bool isValid(const std::vector<double>& data);
};

#endif /*_VALIDATOR_H_ */
