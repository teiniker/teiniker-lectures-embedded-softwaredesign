#include <gtest/gtest.h>
#include <User.h>
#include <Mail.h>

using namespace std;

User* user = NULL;

// Test fixture for User tests
class UserTestGroup : public ::testing::Test 
{
    protected:
    // Pointer to User object
    User* user;

    // SetUp is called before each test
    void SetUp() override {
        Mail* mail = new Mail("homer.simpson@springfield.com");
        user = new User(7, "homer", "c3R1ZGVudA", mail);
    }

    // TearDown is called after each test
    void TearDown() override {
        delete user->mail();
        delete user;
    }
};

// Test Case 1: ConstructorTest
TEST_F(UserTestGroup, ConstructorTest) {
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
    EXPECT_EQ("homer.simpson@springfield.com", user->mail()->address());
}

// Test Case 2: CopyConstructorMailTest
TEST(UserTestGroup_CopyConstructorMailTest, MailCopyConstructor) {
    Mail original("homer.simpson@springfield.com");
    Mail copy(original);

    original.address("bart.simpson@springfield.com");
    EXPECT_EQ("bart.simpson@springfield.com", original.address());
    EXPECT_EQ("homer.simpson@springfield.com", copy.address());
}



// Test Case 3: CopyConstructorUserTest
TEST_F(UserTestGroup, CopyConstructorUserTest) 
{
    User* copy = new User(*user);   

    // Modify the original User's Mail
    delete user->mail();
    user->mail(new Mail("lisa.simpson@springfield.com"));

    // Verify copied User's fields remain unchanged
    EXPECT_EQ(7, copy->id());
    EXPECT_EQ("homer", copy->username());
    EXPECT_EQ("c3R1ZGVudA", copy->password());
    EXPECT_EQ("homer.simpson@springfield.com", copy->mail()->address());

    // Clean up the copied User
    delete copy->mail();
    delete copy;
}

int main(int argc, char** argv)
{
     ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
