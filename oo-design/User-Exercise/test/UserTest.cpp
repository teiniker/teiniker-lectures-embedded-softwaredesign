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


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
