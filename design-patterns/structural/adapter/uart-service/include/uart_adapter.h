#ifndef _UART_ADAPTER_H_
#define _UART_ADAPTER_H_

#include <string>
#include <cstdint>

#include <uart.h>
#include <uart_service.h>


class UartAdapter : public UartService
{
	private :
		UartDevice *_uartDevice;

	public:      
		UartAdapter(void);          
		~UartAdapter(void);

		void init(const BaudRate baudRate, DataBits dataBits, Parity parity, StopBits stopBits);
		void send(const std::string &data);
		std::string receive(void);

		uint32_t baudRate(void) const;
		uint8_t dataBits(void) const;
		uint8_t parity(void) const;
		uint8_t stopBits(void) const;
};

#endif /* _UART_ADAPTER_H_ */
