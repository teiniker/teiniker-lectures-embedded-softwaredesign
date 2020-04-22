#include <cstdio>

#include <ConsolePrint.h>

size_t ConsolePrint::write(int c) 
{
	if(putchar(c) == c)
		return 1;
	else
		return 0;
}
