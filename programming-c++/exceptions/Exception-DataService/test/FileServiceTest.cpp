#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <DataService.h>

#include <string>
#include <vector>

using namespace std;

FileService* service = NULL;

TEST_GROUP(FileServiceTestGroup)
{
};


TEST(FileServiceTestGroup, DataFileTest)
{
    FileService* fs = new FileService("./test/data.txt");
    DataService* ds = new DataService(fs);
    
    vector<int> data = ds->readData();
    
    // Verify
    CHECK_EQUAL(8, data.size());
    CHECK_EQUAL(123, data[0]);
    CHECK_EQUAL(0, data[1]);
    CHECK_EQUAL(4567, data[2]);
    CHECK_EQUAL(99, data[3]);

    CHECK_EQUAL(66, data[4]);
    CHECK_EQUAL(1, data[5]);
    CHECK_EQUAL(777777, data[6]);
    CHECK_EQUAL(888, data[7]);
    
    // Teardown
    delete fs;
    delete ds;
}


TEST(FileServiceTestGroup, InvalidDataFileTest)
{
    FileService* fs = new FileService("xxxx.txt");
    DataService* ds = new DataService(fs);
    
    // Verify
    CHECK_THROWS(DataProcessingException, ds->readData());
    
    // Teardown
    delete fs;
    delete ds;
}

TEST(FileServiceTestGroup, ReadFileTest)
{
    FileService service = FileService("./test/data.txt");
    string content = service.readFile();
    
    // Verify
    CHECK_EQUAL("123,0,4567,99,66,1,777777,888", content);
}


TEST(FileServiceTestGroup, InvalidFilenameTest)
{
    // Verify
    CHECK_THROWS(invalid_argument, FileService(""));
}

TEST(FileServiceTestGroup, FileNotFoundTest)
{
    FileService service = FileService("xxxx.txt");
    
    // Verify
    CHECK_THROWS(FileNotFound, service.readFile());
}



int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
