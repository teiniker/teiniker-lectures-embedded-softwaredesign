#ifndef _SORT_ALGORITHM_H_
#define _SORT_ALGORITHM_H_

#include <memory>
#include <vector>

class SortAlgorithm
{
	public:                
		virtual ~SortAlgorithm(void) {}

		// Template Method
		void sort(std::vector<int>& data);
		
	protected:	
		// Primitve Operations
		virtual bool compare(int a, int b) = 0;
 };

#endif /*_SORT_ALGORITHM_H_ */
