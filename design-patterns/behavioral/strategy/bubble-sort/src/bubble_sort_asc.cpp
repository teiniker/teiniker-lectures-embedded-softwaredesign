#include <bubble_sort_asc.h>
#include <iostream>

using namespace std;

void BubbleSortAsc::sort(vector<int>& data)
{
	int tmp = 0;
	int len = data.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = (len - 1); j >= (i + 1); j--)
		{
			if (data[j] < data[j-1])
			{
				tmp = data[j];
				data[j] = data[j-1];
				data[j-1] = tmp;
			}
		}
	}	
}
