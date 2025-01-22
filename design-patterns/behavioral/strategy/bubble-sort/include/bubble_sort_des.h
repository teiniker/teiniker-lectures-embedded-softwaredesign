#ifndef _BUBBLE_SORT_DES_H_
#define _BUBBLE_SORT_DES_H_

#include <sort_algorithm.h>

class BubbleSortDes : public SortAlgorithm
{
	public:                
		void sort(std::vector<int>& data) override;
 };

#endif /*BUBBLE_SORT_DES*/
