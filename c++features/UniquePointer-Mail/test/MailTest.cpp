#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Mail.h>
#include <memory>

using namespace std;

TEST_GROUP(MailTestGroup)
{
};


TEST(MailTestGroup, PointerTest)
{
    // Setup
    Mail* mail = new Mail("homer.simpson@springfield.com");
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());
    
    // Teardown
    delete mail;
}


TEST(MailTestGroup, UniquePointerTest)
{
    // Setup
    std::unique_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());

    // Teardown
    // mail goes out of scope and deletes the Mail instance.
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
