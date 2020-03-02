#include <stdio.h>
#include <compare.h>

int main(void)
{
	int a = 13;
	int b = 17;
	
	printf("compare(%d,%d) => %d\n", a, b, compare(a,b));	
	return 0;
}
