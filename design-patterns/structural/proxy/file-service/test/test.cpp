#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <file_service.h>
#include <file_service_impl.h>
#include <file_service_proxy.h>

using namespace std;

const string FILE_NAME = "../test/test.data";


// Assembler function to set up dependencies
shared_ptr<FileService> assemble(void)
{
    auto  impl = make_shared<FileServiceImpl>();
    return make_shared<FileServiceProxy>(impl);
}

TEST(FileServiceTest, FileServiceTest) 
{
    // Setup using Dependency Injection
    shared_ptr<FileService> service = assemble();

    // Exercise
    string data = service->readFile(FILE_NAME);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);
}


TEST(ProxyTest, InvalidFileExtension) 
{
    // Setup using Dependency Injection
    shared_ptr<FileService> service = assemble();

    // Exercise + Verify
    EXPECT_THROW(service->readFile("data.txt"), invalid_argument);
}

