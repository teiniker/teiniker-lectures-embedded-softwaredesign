#include <loop.h>

using namespace std;

int SumOfSequenceLoop::calculateSum(const int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}