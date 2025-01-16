#ifndef _SUM_OF_SEQUENCE_H_
#define _SUM_OF_SEQUENCE_H_

#include <memory>
#include <vector>

class SumOfSequence
{
	public:                
		virtual ~SumOfSequence(void) {}

		virtual int calculateSum(const int n) = 0;
 };

#endif /*_SUM_OF_SEQUENCE_H_ */
