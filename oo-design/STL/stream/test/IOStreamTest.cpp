#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

TEST_GROUP(IOStreamTestGroup)
{
};


TEST(IOStreamTestGroup, OutputTest)
{
    // Setup
    string hello = "Hello"; 
    
    // Exercise
    cout << hello << " Graz!" << endl;
        
    // Verify
}


TEST(IOStreamTestGroup, OutputStringStreamTest)
{
    // Setup
    ostringstream oss;
    
    // Exercise
    oss << 1234 << ' ' << "abcdef";
       
    // Verify
    STRCMP_EQUAL("1234 abcdef", oss.str().c_str());
}


TEST(IOStreamTestGroup, OutputStringStreamFormatterTest)
{
    // Setup
    ostringstream oss;
    
    // Exercise
    oss << hex << uppercase << 1234;
    oss << ' ';
    oss << fixed << setprecision(2) << 3.1415;
    
    // Verify
    STRCMP_EQUAL("4D2 3.14", oss.str().c_str());
}


TEST(IOStreamTestGroup, InputStringStreamTest)
{
    // Setup
    string data = "1234 abcdef"; 
    istringstream iss(data);
    
    // Exercise
    int number;
    string text;
    iss >> number;
    iss >> text;
       
    // Verify
    CHECK_EQUAL(1234, number);
    STRCMP_EQUAL("abcdef", text.c_str());
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
