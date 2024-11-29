#include <gtest/gtest.h>
#include <stdexcept>

#include "user.h"

using namespace std;

class UserTest : public ::testing::Test 
{
protected:
    User* user;

    void SetUp() override 
    {
        user = new User(7, "homer", "c3R1ZGVudA");
    }

    void TearDown() override 
    {
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

TEST_F(UserTest, InvalidIdTest) 
{
    // Verify
    EXPECT_THROW(User(-1, "homer", "c3R1ZGVudA"), std::invalid_argument);
}

TEST_F(UserTest, InvalidUsernameTooShortTest) 
{
    // Verify
    string username = "1234567890123456789012345678901234567890X";
    EXPECT_THROW(User(1, username, "c3R1ZGVudA"), std::invalid_argument);
}

TEST_F(UserTest, InvalidPasswordTest) 
{
    // Verify
    EXPECT_THROW(User(1, "homer", "c3R1ZGVud"), std::invalid_argument);
}
