#include <gtest/gtest.h>
#include <iostream>
#include <memory>

#include <mail.h>

using namespace std;

// Pointer Test for Mail
TEST(MailTestGroup, Pointer) 
{
    // Setup
    Mail* mail = new Mail("homer.simpson@springfield.com");
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());
    
    // Teardown
    delete mail;
}

TEST(MailTestGroup, SharedPointerNew) 
{
    // Setup
    shared_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));  
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}

TEST(MailTestGroup, SharedPointerMakeShared) 
{
    // Setup
    shared_ptr<Mail> mail = make_shared<Mail>("homer.simpson@springfield.com");
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}

TEST(MailTestGroup, SharedPointerAuto) 
{
    // Setup
    auto mail = make_shared<Mail>("homer.simpson@springfield.com");
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}

TEST(MailTestGroup, SharedPointerCopy) 
{
    // Setup
    shared_ptr<Mail>  mail = make_shared<Mail>("homer.simpson@springfield.com");   // use_count = 1
    
    {
        shared_ptr<Mail> copy = mail;  
        cout << "#counts(copy)=" << copy.use_count() << endl;   // use_count = 2
    }
    
    cout << "#counts(mail)=" << mail.use_count() << endl;       // use_count = 1
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());

    // Teardown
    // shared_ptr goes out of scope and deletes the Mail instance.
}
