#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <mail.h>
#include <factory_impl.h>

using namespace std;

class FactoryTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        factory = make_shared<FactoryImpl>();
    }

    shared_ptr<Factory> factory;
};


TEST_F(FactoryTest, CreateTest) 
{
    // Setup
    shared_ptr<Mail> mail = factory->createMail("homer.simpson@springfield.com");
    
    // Verify
    ASSERT_EQ("homer.simpson@springfield.com", mail->address());
}
