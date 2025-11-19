#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <file_service.h>
#include <file_service_impl.h>
#include <file_service_proxy.h>

using namespace std;

const string FILE_NAME = "../test/test.data";

TEST(ProxyTest, FileServiceTest) 
{
    // Setup
    FileService* service = new FileServiceProxy();

    // Exercise
    string data = service->readFile(FILE_NAME);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);

    // Teardown
    delete service;
}


TEST(ProxyTest, InvalidFileExtension) 
{
    // Setup
    FileService* service = new FileServiceProxy();

    // Exercise + Verify
    EXPECT_THROW(service->readFile("data.txt"), invalid_argument);

    // Teardown
    delete service;
}

