#include <string>
#include <cstring>

#include <uart.h>

using namespace std;

// simulate a hardware buffer
char _buffer[1024];

void UartDevice::send(char *data)
{
	strncpy(_buffer, data, sizeof(_buffer)-1);
}

char *UartDevice::receive(void)
{
	return _buffer;
}
