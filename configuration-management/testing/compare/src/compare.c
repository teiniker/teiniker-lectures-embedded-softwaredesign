#include <compare.h>

int compare(int a, int b)
{
	if(a > b)
		return 1;
	else if(a < b)
		return -1;
	else
		return 0;
}
