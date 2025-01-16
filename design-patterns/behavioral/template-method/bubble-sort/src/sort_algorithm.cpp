#include <bubble_sort_asc.h>
#include <vector>

using namespace std;

void SortAlgorithm::sort(vector<int>& data)
{
	int len = data.size();
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
