#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <file_service.h>
#include <file_service_impl.h>
#include <file_service_proxy.h>

using namespace std;

const string FILE_NAME = "../test/test.data";

class ProxyTest : public ::testing::Test 
{
protected:
    shared_ptr<FileService> impl;
    shared_ptr<FileService> service;

    void SetUp() override 
    {
        impl = make_shared<FileServiceImpl>();
        service = make_shared<FileServiceProxy>(impl);
    }
};

TEST_F(ProxyTest, FileServiceTest) 
{
    // Exercise
    string data = service->readFile(FILE_NAME);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);
}


TEST_F(ProxyTest, InvalidFileExtension) 
{
    // Exercise + Verify
    EXPECT_THROW(service->readFile("data.txt"), invalid_argument);
}

