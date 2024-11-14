#include <gtest/gtest.h>
#include "user.h"
#include "mail.h"

using namespace std;

User* user = NULL;

class UserTest : public ::testing::Test 
{
protected:
    User* user;

    void SetUp() override 
    {
        Mail* mail = new Mail("homer.simpson@springfield.com");
        user = new User(7, "homer", "c3R1ZGVudA", mail);
    }

    void TearDown() override 
    {
        delete user->mail();
        delete user;
    }
};

TEST_F(UserTest, ConstructorTest) 
{
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
    EXPECT_EQ("homer.simpson@springfield.com", user->mail()->address());
}
