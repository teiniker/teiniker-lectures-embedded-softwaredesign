#include<validator.h>

bool Validator::isInRange(const std::vector<double>& data, const double min, const double max)
{
    for (double value : data)
    {
        if (value < min || value > max)
        {
            return false;
        }
    }
    return true;
}

bool Validator::isValid(const std::vector<double>& data)
{
    return !data.empty();
}
