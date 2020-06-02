#include <BubbleSortAsc.h>
#include <iostream>

using namespace std;


void SortAlgorithm::sort(int data[], int len)
{
	int tmp = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = (len - 1); j >= (i + 1); j--)
		{
			if (compare(data[j], data[j-1]))
			{
				tmp = data[j];
				data[j] = data[j-1];
				data[j-1] = tmp;
			}
		}
	}	
}
