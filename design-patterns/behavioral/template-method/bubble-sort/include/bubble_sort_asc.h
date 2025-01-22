#ifndef _BUBBLE_SORT_ASC_H_
#define _BUBBLE_SORT_ASC_H_

#include <sort_algorithm.h>

class BubbleSortAsc : public SortAlgorithm
{
	protected:                
		bool compare(int a, int b) override;
 };

#endif /*BUBBLE_SORT_ASC*/
