#ifndef _SORTALGORITHM_H_
#define _SORTALGORITHM_H_

#include <memory>

class SortAlgorithm
{
	public:                
		virtual ~SortAlgorithm(void) {}

		virtual void sort(int data[], int len) = 0;
 };

#endif /*_SORTALGORITHM_H_ */
