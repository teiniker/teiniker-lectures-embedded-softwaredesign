#ifndef _SORT_ALGORITHM_H_
#define _SORT_ALGORITHM_H_

#include <memory>

class SortAlgorithm
{
	public:                
		virtual ~SortAlgorithm(void) {}

		virtual void sort(int data[], int len) = 0;
 };

#endif /*_SORT_ALGORITHM_H_ */
