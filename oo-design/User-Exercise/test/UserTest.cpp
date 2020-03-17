#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <User.h>
#include <Mail.h>

using namespace std;

User* user = NULL;
Mail* mail = NULL;

TEST_GROUP(UserTestGroup)
{
    void setup()
    {
        mail = new Mail("homer.simpson@springfield.com");
        user = new User(7, "homer", "c3R1ZGVudA", mail);
    }

    void teardown()
    {
        delete(mail);
        delete(user);
    }
};


TEST(UserTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL(7, user->id());
    STRCMP_EQUAL("homer", user->username().c_str());
    STRCMP_EQUAL("c3R1ZGVudA", user->password().c_str());
    
    STRCMP_EQUAL("homer.simpson@springfield.com", user->mail()->address().c_str());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
