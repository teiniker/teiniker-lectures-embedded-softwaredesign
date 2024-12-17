#include <gtest/gtest.h>
#include <stdexcept>

#include "user.h"

using namespace std;

TEST(UserTest, ConstructorTest) 
{
    // Setup
    User* user = new User(7, "homer", "c3R1ZGVudA");
    
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());

    // Teardown
    delete user;
}

TEST(UserTest, InvalidIdTest) 
{
    // Verify
    EXPECT_THROW(User(-1, "homer", "c3R1ZGVudA"), std::invalid_argument);
}

TEST(UserTest, InvalidUsernameTooLongTest) 
{
    // Verify
    string username = "1234567890123456789012345678901234567890X";
    EXPECT_THROW(User(1, username, "c3R1ZGVudA"), std::invalid_argument);
}

TEST(UserTest, InvalidPasswordTest) 
{
    // Verify
    EXPECT_THROW(User(1, "homer", "123456789"), std::invalid_argument);
}
