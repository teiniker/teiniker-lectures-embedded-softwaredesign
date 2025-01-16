#ifndef _SORT_ALGORITHM_H_
#define _SORT_ALGORITHM_H_

#include <memory>
#include <vector>

class SortAlgorithm
{
	public:                
		virtual ~SortAlgorithm(void) {}

		virtual void sort(std::vector<int>& data) = 0;
 };

#endif /*_SORT_ALGORITHM_H_ */
