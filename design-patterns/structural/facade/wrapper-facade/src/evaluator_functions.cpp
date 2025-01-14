#include <evaluator_functions.h>

using namespace std;

double eval_min(const std::vector<double>& data)
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

double eval_max(const std::vector<double>& data)
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

double eval_sum(const std::vector<double>& data)
{
	double sum = 0;
	for (double value : data)
	{
		sum += value;
	}
	return sum;
}

double eval_mean(const std::vector<double>& data)
{
	return eval_sum(data) / data.size();
}
