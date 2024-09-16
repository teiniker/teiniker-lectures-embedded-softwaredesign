#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Mail.h>
#include <FactoryImpl.h>
#include <iostream>
#include <memory>

using namespace std;

TEST_GROUP(FactoryTestGroup)
{
};


TEST(FactoryTestGroup, CreateTest)
{
    // Setup
    shared_ptr<Factory> factory(new FactoryImpl()); 
    shared_ptr<Mail> mail = factory->createMail("homer.simpson@springfield.com");
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());
    
    // factory goes out of scope => delete
    // mail goes out of scope => delete
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
