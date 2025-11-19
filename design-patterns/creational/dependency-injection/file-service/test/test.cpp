#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <file_service.h>
#include <file_service_impl.h>
#include <file_service_proxy.h>

using namespace std;

const string FILE_NAME = "../test/test.data";

// Assembler function for Dependency Injection
shared_ptr<FileService> assemble_proxy(void)
{
    auto impl = make_shared<FileServiceImpl>();
    shared_ptr<FileService> proxy = make_shared<FileServiceProxy>(impl);
    return proxy;
}


TEST(ProxyTest, FileServiceTest) 
{
    // Setup
    auto service = assemble_proxy();

    // Exercise
    string data = service->readFile(FILE_NAME);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);

    // Teardown
}


TEST(ProxyTest, InvalidFileExtension) 
{
    // Setup
    auto service = assemble_proxy();

    // Exercise + Verify
    EXPECT_THROW(service->readFile("data.txt"), invalid_argument);

    // Teardown
}

