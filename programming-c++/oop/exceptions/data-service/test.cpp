#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "data_service.h"

using namespace std;

class FileServiceTest : public ::testing::Test 
{
protected:
    FileService* service;
    DataService* dataService;

    void SetUp() override 
    {
        service = nullptr;
        dataService = nullptr;
    }

    void TearDown() override 
    {
        delete service;
        delete dataService;
    }
};

TEST_F(FileServiceTest, DataFileTest) 
{
    service = new FileService("../data.txt");
    dataService = new DataService(service);
    
    vector<int> data = dataService->readData();
    
    // Verify
    ASSERT_EQ(8, data.size());
    EXPECT_EQ(123, data[0]);
    EXPECT_EQ(0, data[1]);
    EXPECT_EQ(4567, data[2]);
    EXPECT_EQ(99, data[3]);
    EXPECT_EQ(66, data[4]);
    EXPECT_EQ(1, data[5]);
    EXPECT_EQ(777777, data[6]);
    EXPECT_EQ(888, data[7]);
}

TEST_F(FileServiceTest, InvalidDataFileTest) 
{
    service = new FileService("xxxx.txt");
    dataService = new DataService(service);
    
    // Verify
    EXPECT_THROW(dataService->readData(), DataProcessingException);
}

TEST_F(FileServiceTest, ReadFileTest) 
{
    FileService service("../data.txt");
    string content = service.readFile();
    
    // Verify
    EXPECT_EQ("123,0,4567,99,66,1,777777,888", content);
}

TEST_F(FileServiceTest, InvalidFilenameTest) 
{
    // Verify
    EXPECT_THROW(FileService(""), invalid_argument);
}

TEST_F(FileServiceTest, FileNotFoundTest) 
{
    FileService service("xxxx.txt");
    
    // Verify
    EXPECT_THROW(service.readFile(), FileNotFound);
}
