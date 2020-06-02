#ifndef _SORTALGORITHM_H_
#define _SORTALGORITHM_H_

#include <memory>

class SortAlgorithm
{
	public:                
		virtual ~SortAlgorithm(void) {}

		// Template Method
		void sort(int data[], int len);
		
	protected:	
		// Primitve Operations
		virtual bool compare(int a, int b) = 0;
 };

#endif /*_SORTALGORITHM_H_ */
