#include <gtest/gtest.h>
#include "user.h"
#include "mail.h"

using namespace std;

class UserTest : public ::testing::Test 
{
protected:
    User* user;

    void SetUp() override 
    {
        user = new User(7, "homer", "c3R1ZGVudA");
        user->addMail(new Mail("homer.simpson@springfield.com"));
        user->addMail(new Mail("homer.simpson@powerplant.com"));
    }

    void TearDown() override 
    {
        delete user->mail(0);
        delete user->mail(1);
        delete user;
    }
};

TEST_F(UserTest, ConstructorTest) 
{
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
}

TEST_F(UserTest, NavigationTest) 
{
    // Verify
    EXPECT_EQ(2, user->numberOfMails());
    EXPECT_EQ("homer.simpson@springfield.com", user->mail(0)->address());
    EXPECT_EQ("homer.simpson@powerplant.com", user->mail(1)->address());
}
