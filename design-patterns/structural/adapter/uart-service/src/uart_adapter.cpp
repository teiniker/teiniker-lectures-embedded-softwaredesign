#include <string>
#include <cstring>

#include <uart_adapter.h>

using namespace std;

UartAdapter::UartAdapter(void)
{
	_uartDevice = new UartDevice();
}

UartAdapter::~UartAdapter(void)
{
	delete _uartDevice;
}

void UartAdapter::init(const BaudRate baudRate, DataBits dataBits, Parity parity, StopBits stopBits)
{
	_uartDevice->baudRate(static_cast<uint32_t>(baudRate));
	_uartDevice->dataBits(static_cast<uint8_t>(dataBits));
	_uartDevice->parity(static_cast<uint8_t>(parity));
	_uartDevice->stopBits(static_cast<uint8_t>(stopBits));
}

void UartAdapter::send(const std::string &data)
{
	_uartDevice->send((char*)data.c_str());
}

std::string UartAdapter::receive(void)
{
	return std::string(_uartDevice->receive());
}

uint32_t UartAdapter::baudRate(void) const
{
	return _uartDevice->baudRate();
}

uint8_t UartAdapter::dataBits(void) const
{
	return _uartDevice->dataBits();
}

uint8_t UartAdapter::parity(void) const
{
	return _uartDevice->parity();
}

uint8_t UartAdapter::stopBits(void) const
{
	return _uartDevice->stopBits();
}
