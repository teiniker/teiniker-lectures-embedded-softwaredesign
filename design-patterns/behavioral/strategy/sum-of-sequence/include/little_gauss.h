#ifndef _SUM_OF_SEQUENCE_GAUSS_H_
#define _SUM_OF_SEQUENCE_GAUSS_H_

#include <sum_of_sequence.h>

class SumOfSequenceGauss : public SumOfSequence
{
	public:                
		int calculateSum(const int n) override;
 };

#endif /*SUM_OF_SEQUENCE_GAUSS*/
