#include <vector>
#include <evaluator_functions.h>
#include <evaluator.h>

using namespace std;

Evaluator::Evaluator(const std::vector<double>& data)
{
	_data = data;
}

double Evaluator::min(void)
{
	return eval_min(_data);
}

double Evaluator::max(void)
{
	return eval_max(_data);
}

double Evaluator::mean(void)
{
	return eval_mean(_data);
}

double Evaluator::sum(void)
{
	return eval_sum(_data);
}
