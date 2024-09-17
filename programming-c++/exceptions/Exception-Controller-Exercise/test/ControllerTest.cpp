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
        cout << e.what() << endl;
    }
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
