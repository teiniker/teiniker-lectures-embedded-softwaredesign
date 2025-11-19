#ifndef _UART_SERVICE_H_
#define _UART_SERVICE_H_

#include <string>
#include <cstdint>

enum class BaudRate 
{
	BR_9600   = 9600,
	BR_19200  = 19200,
	BR_38400  = 38400,
	BR_57600  = 57600,
	BR_115200 = 115200
};

enum class DataBits
{
	FIVE  = 5,
	SIX   = 6,
	SEVEN = 7,
	EIGHT = 8
};

enum class Parity
{
	NONE = 0,
	EVEN = 1,
	ODD  = 2
};

enum class StopBits
{
	ONE = 1,
	TWO = 2
};

class UartService 
{
	public:                
		virtual ~UartService(void) {}

		virtual void init(const BaudRate baudRate, DataBits dataBits, Parity parity, StopBits stopBits) = 0;
		virtual void send(const std::string &data) = 0;
		virtual std::string receive(void) = 0;

		virtual uint32_t baudRate(void) const = 0;
		virtual uint8_t dataBits(void) const = 0;
		virtual uint8_t parity(void) const = 0;
		virtual uint8_t stopBits(void) const = 0;
 };

#endif /* _UART_SERVICE_H_ */
