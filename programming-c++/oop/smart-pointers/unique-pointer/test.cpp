#include <gtest/gtest.h>

#include <mail.h>
#include <memory>

using namespace std;


// Pointer Test for Mail
TEST(MailTestGroup, PointerTest) 
{
    // Setup
    Mail* mail = new Mail("homer.simpson@springfield.com");
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());
    
    // Teardown
    delete mail;
}

// Unique Pointer Test for Mail
TEST(MailTestGroup, UniquePointerTest) 
{
    // Setup
    std::unique_ptr<Mail> mail(new Mail("homer.simpson@springfield.com"));
    
    // Verify
    EXPECT_EQ("homer.simpson@springfield.com", mail->address());

    // Teardown
    // std::unique_ptr automatically cleans up when it goes out of scope.
}
