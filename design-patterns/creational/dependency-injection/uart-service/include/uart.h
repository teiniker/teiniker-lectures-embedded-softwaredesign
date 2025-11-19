#ifndef _UART_DEVICE_H_
#define _UART_DEVICE_H_

#include <string>
#include <cstdint>

class UartDevice 
{
	private:
		uint32_t _baudRate;
		uint8_t _dataBits;
		uint8_t	_parity;
		uint8_t _stopBits;

	public:                
		void baudRate(uint32_t br) { _baudRate = br; }
		uint32_t baudRate(void) const { return _baudRate; }	

		void dataBits(uint8_t db) { _dataBits = db; }
		uint8_t dataBits(void) const { return _dataBits; }

		void parity(uint8_t p) { _parity = p; }
		uint8_t parity(void) const { return _parity; }

		void stopBits(uint8_t sb) { _stopBits = sb; }
		uint8_t stopBits(void) const { return _stopBits; }

		void send(char *data);
		
		char *receive(void);
 };

#endif /* _UART_DEVICE_H_ */
