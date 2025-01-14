#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <file_service.h>
#include <file_service_impl.h>
#include <factory_impl.h>

using namespace std;

const string FILE_NAME = "../test/test.data";

class FactoryTest : public ::testing::Test 
{
protected:
    shared_ptr<Factory> factory;

    void SetUp() override 
    {
        factory = make_shared<FactoryImpl>();
    }
};

TEST_F(FactoryTest, FactoryTest) 
{
    // Setup
    shared_ptr<FileService> service = factory->createFileService();

    // Exercise
    string data = service->readFile(FILE_NAME);
    
    // Verify
    EXPECT_EQ(29, data.size());
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", data);
}


TEST_F(FactoryTest, UnknownFile) 
{
    // Setup
    shared_ptr<FileService> service = factory->createFileService();

    // Exercise + Verify
    EXPECT_THROW(service->readFile("blah"), FileNotFound);
}
