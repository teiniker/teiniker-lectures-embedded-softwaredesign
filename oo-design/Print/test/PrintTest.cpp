#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <string>

#include <ConsolePrint.h>


using namespace std;

TEST_GROUP(PrintTestGroup)
{
};


TEST(PrintTestGroup, PrintCharTest)
{
    // Setup
    Print* console = new ConsolePrint();
    
    // Verify
    CHECK_EQUAL(1, console->print('A'));

    // Teardown 
    delete console;
}

TEST(PrintTestGroup, PrintCharArrayTest)
{
    // Setup
    Print* console = new ConsolePrint();
    
    // Verify
    CHECK_EQUAL(10, console->print("AAAAAAAAAA"));

    // Teardown 
    delete console;
}

TEST(PrintTestGroup, PrintStringTest)
{
    // Setup
    Print* console = new ConsolePrint();
    
    // Verify
    string s = "AAAAAAAAAAAAAAAAAAAA";
    CHECK_EQUAL(20, console->print(s));

    // Teardown 
    delete console;
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
