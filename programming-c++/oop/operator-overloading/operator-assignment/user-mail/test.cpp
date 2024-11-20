#include <gtest/gtest.h>
#include "user.h"
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


TEST(UserTest, AssignemntOperatorUserTest)
{
    // Setup
    User* original = new User(7, "homer", "c3R1ZGVudA", new Mail("homer.simpson@springfield.com"));
    User* copy = new User(3, "lisa", "Lk6JgF?6h", new Mail("lisa.simpson@springfield.com"));
    
    // Exercise
    *copy = *original;        
    delete original->mail();    
    delete original;
            
    // Verify
    EXPECT_EQ(7, copy->id());
    EXPECT_EQ("homer", copy->username());
    EXPECT_EQ("c3R1ZGVudA", copy->password());    
    EXPECT_EQ("homer.simpson@springfield.com", copy->mail()->address());    

    // Teardown
    delete copy->mail();
    delete copy;
}
