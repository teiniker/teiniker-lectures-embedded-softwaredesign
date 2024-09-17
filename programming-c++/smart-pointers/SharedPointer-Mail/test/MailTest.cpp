#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Mail.h>
#include <iostream>
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


TEST(MailTestGroup, SingleSharedPointerTest)
{
    // Setup
    shared_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}


TEST(MailTestGroup, SharedPointerTest)
{
    // Setup
    shared_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));   // use_count = 1
    
    {
        shared_ptr<Mail> copy = mail;  
        cout << "#counts(copy)=" << copy.use_count() << endl;    // use_count = 2            
    }
    
    cout << "#counts(mail)=" << mail.use_count() << endl;   // use_count = 1
    
    // Verify
    CHECK_EQUAL("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
