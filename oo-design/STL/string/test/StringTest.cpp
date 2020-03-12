#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <string>

using namespace std;

// Test cases

TEST_GROUP(StringTestGroup)
{
};


TEST(StringTestGroup, StringLiteralTest)
{
    // Setup
    string hello = "Hello"; 
	
    // Verify
    CHECK_EQUAL(5, hello.length());
    
    CHECK_EQUAL("Hello", hello);
    STRCMP_EQUAL("Hello", hello.c_str());
    
    CHECK_EQUAL('H', hello[0]);
    CHECK_EQUAL('o', hello[4]);
}


TEST(StringTestGroup, StringConcatinationTest)
{
    // Setup
    string hello = "Hello"; 
	string name = "Graz";
    string greeting = hello + " " + name + "!";
    
    // Verify
    CHECK_EQUAL("Hello Graz!", greeting);
}


TEST(StringTestGroup, StringAppendTest)
{
    // Setup
    string hello = "Hello"; 
	string name = "Graz";
    
    // Exercise
    hello.append(" ");
    hello.append(name);
    hello.append("!");
    
    // Verify
    CHECK_EQUAL("Hello Graz!", hello);
}


TEST(StringTestGroup, SubStringTest)
{
    // Setup
    string hello = "Hello Graz!"; 

    // Exercise
	string name = hello.substr(6,4); // start, length
    
    // Verify
    CHECK_EQUAL("Graz", name);
}


TEST(StringTestGroup, ReplaceStringTest)
{
    // Setup
    string hello = "Hello Graz!"; 

    // Exercise
	string name = hello.replace(6,4, "Vienna"); // start, length, "new value"
    
    // Verify
    CHECK_EQUAL("Hello Vienna!", name);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
