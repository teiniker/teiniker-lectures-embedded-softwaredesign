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
        user = new User(7, "homer", "c3R1ZGVudA");
        Mail* mail = new Mail("homer.simpson@springfield.com");
        user->addMail(mail);
        user->addMail(new Mail("homer.simpson@powerplant.com"));
    }

    void teardown()
    {
        delete user->mail(0);
        delete user->mail(1);
        delete user;
    }
};


TEST(UserTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());
    
    CHECK_EQUAL("homer.simpson@springfield.com", user->mail(0)->address());
    CHECK_EQUAL("homer.simpson@powerplant.com", user->mail(1)->address());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
