#include <gtest/gtest.h>
#include "mail.h"

using namespace std;

TEST(UserTest, AssignmentOperatorMailTest)
{
    // Setup
    Mail* original = new Mail("homer.simpson@springfield.com");
    Mail* copy = new Mail();
    
    // Exercise
    *copy = *original;    
    delete original;   
    
    // Verify
     EXPECT_EQ("homer.simpson@springfield.com", copy->address());
    
    // Teardown
    delete copy;
}
