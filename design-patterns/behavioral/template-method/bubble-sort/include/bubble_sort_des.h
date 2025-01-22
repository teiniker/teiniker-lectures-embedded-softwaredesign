#ifndef _BUBBLE_SORT_DES_H_
#define _BUBBLE_SORT_DES_H_

#include <sort_algorithm.h>

class BubbleSortDes : public SortAlgorithm
{
	protected:                
		bool compare(int a, int b) override;
 };

#endif /*BUBBLE_SORT_DES*/
