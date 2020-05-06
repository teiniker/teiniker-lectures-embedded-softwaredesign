#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Controller.h>
#include <iostream>

using namespace std;


TEST_GROUP(ControllerTestGroup)
{
};


TEST(ControllerTestGroup, ConstructorTest)
{
    CHECK_THROWS(ControllerException, Controller());
}


TEST(ControllerTestGroup, WhatTest)
{
    try
    {
        Controller();
        FAIL("No exception!"); 
    }
    catch(ControllerException& e)
    {
        STRCMP_EQUAL("Can't access GPIO! (because: No hardware in place!)", e.what());
    }
}

TEST(ControllerTestGroup, ExceptionBaseClassTest)
{
    try
    {
        Controller();
        FAIL("No exception!"); 
    }
    catch(std::exception& e) // Catch subtypes of std::exception
    {
       STRCMP_EQUAL("Can't access GPIO! (because: No hardware in place!)", e.what());
    }
}


TEST(ControllerTestGroup, AnyExceptionTest)
{
    try
    {
        Controller();
        FAIL("No exception!"); 
    }
    catch(...) // Catch any exception
    {
        // Exception thrown
    }
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
