#include <vector>
#include <evaluator.h>

using namespace std;

double Evaluator::min(const std::vector<double>& data)
{
    double min = data[0];
    for (double value : data)
    {
        if (value < min)
        {
            min = value;
        }
    }
    return min;
}

double Evaluator::max(const std::vector<double>& data)
{
    double max = data[0];
    for (double value : data)
    {
        if (value > max)
        {
            max = value;
        }
    }
    return max;
}

double Evaluator::sum(const std::vector<double>& data)
{
    double sum = 0;
    for (double value : data)
    {
        sum += value;
    }
    return sum;
}

double Evaluator::mean(const std::vector<double>& data)
{
    return sum(data) / data.size();
}
