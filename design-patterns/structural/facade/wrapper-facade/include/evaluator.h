#ifndef _EVALUATOR_H_
#define _EVALUATOR_H_

#include <vector>

class Evaluator
{
	private:
		std::vector<double> _data;
	public:		
		Evaluator(const std::vector<double>& data);

		double min(void);
		double max(void);
		double mean(void);
		double sum(void);
};

#endif /*_EVALUATOR_H_ */
