#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <User.h>
#include <Mail.h>

using namespace std;

User* user = NULL;

TEST_GROUP(UserTestGroup)
{
    void setup()
    {
        Mail* mail = new Mail("homer.simpson@springfield.com");
        user = new User(7, "homer", "c3R1ZGVudA", mail);
    }

    void teardown()
    {
        delete user->mail();
        delete user;
    }
};


TEST(UserTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());
    
    CHECK_EQUAL("homer.simpson@springfield.com", user->mail()->address());
}

TEST(UserTestGroup, CopyConstructorMailTest)
{
    Mail original("homer.simpson@springfield.com");
    Mail copy(original);
    
    original.address("bart.simpson@springfield.com");   // change original
    
    // Verify
    CHECK_EQUAL("bart.simpson@springfield.com", original.address());
    CHECK_EQUAL("homer.simpson@springfield.com", copy.address());
    
}


TEST(UserTestGroup, CopyConstructorUserTest)
{
    User* copy = new User(*user);   // Copy: [User]-->[Mail]
    
    // Change original
    //user->mail()->address("bart.simpson@springfield.com");        
    delete user->mail();    
    user->mail(new Mail("lisa.simpson@springfield.com"));  
            
    // Verify
    CHECK_EQUAL(7, copy->id());
    CHECK_EQUAL("homer", copy->username());
    CHECK_EQUAL("c3R1ZGVudA", copy->password());    
    CHECK_EQUAL("homer.simpson@springfield.com", copy->mail()->address());    

    delete copy->mail();
    delete copy;
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
