#include <string>
#include <cstring>

#include <Print.h>

size_t Print::print(char c)
{
	return write((int)c);
}

size_t Print::print(const char* s)
{
	size_t len=0;
	for(unsigned int i=0; i<strlen(s); i++)
	{
		len += print(s[i]);
	}
	return len;
}

size_t Print::print(const std::string& s)
{
	return print(s.c_str());
}
