#ifndef _EVALUATOR_H_
#define _EVALUATOR_H_

#include <vector>

class Evaluator
{
	public:		
		double min(const std::vector<double>& data);
		double max(const std::vector<double>& data);
		double mean(const std::vector<double>& data);
		double sum(const std::vector<double>& data);
};

#endif /*_EVALUATOR_H_ */
