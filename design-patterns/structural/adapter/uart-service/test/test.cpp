#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <uart.h>
#include <uart_adapter.h>

using namespace std;

TEST(UartTest, SetUartParameters) 
{
    // Setup
    UartDevice device;

    // Exercise
    device.baudRate(115200);
    device.dataBits(8);
    device.parity(0); // None
    device.stopBits(1);

    // Verify
    EXPECT_EQ(115200, device.baudRate());
    EXPECT_EQ(8, device.dataBits());
    EXPECT_EQ(0, device.parity());
    EXPECT_EQ(1, device.stopBits());
}

TEST(UartTest, UartSendReceive) 
{
    // Setup
    UartDevice device;
    char testData[] = "Hello World!";

    // Exercise
    device.send(testData);
    char *receivedData = device.receive();

    // Verify
    EXPECT_STREQ(testData, receivedData);
}


TEST(UartServiceTest, SetUartParameters) 
{
    // Setup
    UartService *service = new UartAdapter();

    // Exercise
    service->init(BaudRate::BR_115200, DataBits::EIGHT, Parity::NONE, StopBits::ONE);

    // Verify
    EXPECT_EQ(115200, service->baudRate());
    EXPECT_EQ(8, service->dataBits());
    EXPECT_EQ(0, service->parity());
    EXPECT_EQ(1, service->stopBits());

    delete service;
}

TEST(UartServiceTest, UartSendReceive) 
{
    // Setup
    UartService *service = new UartAdapter();
    string testData = "Hello World!";

    // Exercise
    service->send(testData);
    string receivedData = service->receive();

    // Verify
    EXPECT_EQ(testData, receivedData);

    delete service;
}