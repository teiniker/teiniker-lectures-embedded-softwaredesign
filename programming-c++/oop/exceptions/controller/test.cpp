#include <gtest/gtest.h>

#include "controller.h"
#include <iostream>

using namespace std;

TEST(ControllerTest, ConstructorThrowsException)
{
    EXPECT_THROW(Controller(), ControllerException);
}

TEST(ControllerTest, WhatTest)
{
    try
    {
        Controller();
        FAIL() << "Expected ControllerException";
    }
    catch(const ControllerException& e)
    {
        EXPECT_STREQ("Can't access GPIO! (because: No hardware in place!)", e.what());
    }
    catch(...)
    {
        FAIL() << "Expected ControllerException";
    }
}

TEST(ControllerTest, ExceptionBaseClassTest)
{
    try
    {
        Controller();
        FAIL() << "Expected std::exception";
    }
    catch(const std::exception& e)
    {
        EXPECT_STREQ("Can't access GPIO! (because: No hardware in place!)", e.what());
    }
    catch(...)
    {
        FAIL() << "Expected std::exception";
    }
}

TEST(ControllerTest, AnyExceptionTest)
{
    EXPECT_ANY_THROW(Controller());
}
