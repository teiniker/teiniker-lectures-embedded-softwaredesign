#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <uart.h>
#include <uart_adapter.h>

using namespace std;

// Assembler function to set up dependencies
std::shared_ptr<UartService> assemble(void)
{
    auto uartDevice = std::make_shared<UartDevice>();
    return std::make_shared<UartAdapter>(uartDevice);
}


TEST(UartServiceTest, SetUartParameters) 
{
    // Setup using Dependency Injection
    shared_ptr<UartService> service = assemble();

    // Exercise
    service->init(BaudRate::BR_115200, DataBits::EIGHT, Parity::NONE, StopBits::ONE);

    // Verify
    EXPECT_EQ(115200, service->baudRate());
    EXPECT_EQ(8, service->dataBits());
    EXPECT_EQ(0, service->parity());
    EXPECT_EQ(1, service->stopBits());
}

TEST(UartServiceTest, UartSendReceive) 
{
    // Setup using Dependency Injection
    shared_ptr<UartService> service = assemble();
    string testData = "Hello World!";

    // Exercise
    service->send(testData);
    string receivedData = service->receive();

    // Verify
    EXPECT_EQ(testData, receivedData);
}