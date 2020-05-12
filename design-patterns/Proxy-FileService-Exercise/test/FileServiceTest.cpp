#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <FileServiceImpl.h>
#include <FileServiceProxy.h>
#include <FactoryImpl.h>

#include <string>
#include <memory>

using namespace std;

FileService* service = NULL;

TEST_GROUP(FileServiceTestGroup)
{
};

const string FILE_NAME = "./test/test.data";

TEST(FileServiceTestGroup, FileServiceTest)
{
    shared_ptr<FileService> service(new FileServiceImpl());
    
    string data = service->readFile(FILE_NAME);
    
    // Verify
    CHECK_EQUAL(29, data.size());
    CHECK_EQUAL("123,0,4567,99,66,1,777777,888", data);
}


TEST(FileServiceTestGroup, FileServiceProxyTest)
{
    shared_ptr<FileService> impl(new FileServiceImpl());
    shared_ptr<FileService> service(new FileServiceProxy(impl));
    
    string data = service->readFile(FILE_NAME);
    
    // Verify
    CHECK_EQUAL(29, data.size());
    CHECK_EQUAL("123,0,4567,99,66,1,777777,888", data);
}

TEST(FileServiceTestGroup, InvalidFilenameTest)
{
    shared_ptr<FileService> impl(new FileServiceImpl());
    shared_ptr<FileService> service(new FileServiceProxy(impl));

    // Verify    
    CHECK_THROWS(invalid_argument, service->readFile("./test/data.exe"));
}

TEST(FileServiceTestGroup, FileNotFoundTest)
{
    shared_ptr<FileService> impl(new FileServiceImpl());
    shared_ptr<FileService> service(new FileServiceProxy(impl));

    // Verify    
    CHECK_THROWS(FileNotFound, service->readFile("./test/other.data"));
}


TEST(FileServiceTestGroup, FactoryTest)
{   
    // Use the factory method to create: --->[:FileServiceProxy]--->[:FileServiceImpl] 
    shared_ptr<Factory> factory(new FactoryImpl()); 
    shared_ptr<FileService> service = factory->createFileService();
    
    string data = service->readFile(FILE_NAME);
    
    // Verify
    CHECK_EQUAL(29, data.size());
    CHECK_EQUAL("123,0,4567,99,66,1,777777,888", data);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
