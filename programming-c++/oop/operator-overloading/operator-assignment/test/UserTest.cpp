#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <User.h>
#include <Mail.h>

using namespace std;

User* user = NULL;

TEST_GROUP(UserTestGroup)
{
};


TEST(UserTestGroup, AssignmentOperatorMailTest)
{
    // Setup
    Mail* original = new Mail("homer.simpson@springfield.com");
    Mail* copy = new Mail();
    
    // Exercise
    *copy = *original;    
    delete original;   
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", copy->address());
    
    // Teardown
    delete copy;
}


TEST(UserTestGroup, AssignemntOperatorUserTest)
{
    // Setup
    User* original = new User(7, "homer", "c3R1ZGVudA", new Mail("homer.simpson@springfield.com"));
    User* copy = new User(3, "lisa", "Lk6JgF?6h", new Mail("lisa.simpson@springfield.com"));
    
    // Exercise
    *copy = *original;        
    delete original->mail();    
    delete original;
            
    // Verify
    CHECK_EQUAL(7, copy->id());
    CHECK_EQUAL("homer", copy->username());
    CHECK_EQUAL("c3R1ZGVudA", copy->password());    
    CHECK_EQUAL("homer.simpson@springfield.com", copy->mail()->address());    

    // Teardown
    delete copy->mail();
    delete copy;
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
