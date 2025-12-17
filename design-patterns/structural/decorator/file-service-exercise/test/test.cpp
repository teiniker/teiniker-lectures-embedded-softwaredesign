#include <gtest/gtest.h>
#include <string>
#include <memory>

#include <file_service.h>
#include <file_service_impl.h>

using namespace std;


// Assembler function to set up dependencies
shared_ptr<FileService> assemble(void)
{
    auto  impl = make_shared<FileServiceImpl>();
    return make_shared<FileServiceDecorator>(impl);
}

TEST(FileServiceTest, FileServiceTest) 
{
    // Setup using Dependency Injection
    shared_ptr<FileService> service = assemble();
    string filename = "../test/test";
    
    // Exercise
    string data = service->readFile(filename);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);
}

TEST(FileServiceTest, FileNotFoundTest) 
{
    // Setup using Dependency Injection
    shared_ptr<FileService> service = assemble();
    string filename = "non_existing_file";
    
    // Exercise & Verify
    EXPECT_THROW(service->readFile(filename), FileNotFound);
}

