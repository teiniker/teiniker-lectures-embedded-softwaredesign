#include <gtest/gtest.h>
#include <vector>

#include "user.h"
#include "admin.h"
#include "mail.h"

using namespace std;


class UserTestGroup : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        mail = new Mail("homer.simpson@springfield.com");
        user = new User(7, "homer", mail);
    }

    void TearDown() override 
    {
        delete user->mail();
        delete user;
    }

    Mail* mail;
    User* user;
};

TEST_F(UserTestGroup, UserTest) 
{
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("homer.simpson@springfield.com", user->mail()->address());
}


class AdminTestGroup : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        mail = new Mail("monti.burns@springfield.com");
        admin = new Admin(7, "burns", "c3R1ZGVudA", mail);
    }

    void TearDown() override 
    {
        delete admin->mail();
        delete admin;
    }

    Mail* mail;
    Admin* admin;
};

TEST_F(AdminTestGroup, AdminTest) 
{
    // Verify
    EXPECT_EQ(7, admin->id());
    EXPECT_EQ("burns", admin->username());
    EXPECT_EQ("monti.burns@springfield.com", admin->mail()->address());
}

TEST(PolymorphTestGroup, PolymorphTest) 
{
    // Setup
    vector<User*> users;
    users.push_back(new User(3, "homer", new Mail("homer.simpson@springfield.com"))); 
    users.push_back(new Admin(7, "burns", "c3R1ZGVudA", new Mail("monti.burns@springfield.com")));
    
    // Verify
    EXPECT_EQ(3, users[0]->id());
    EXPECT_EQ(7, users[1]->id());
    EXPECT_EQ("homer", users[0]->username());
    EXPECT_EQ("burns", users[1]->username());
    EXPECT_EQ("homer.simpson@springfield.com", users[0]->mail()->address());
    EXPECT_EQ("monti.burns@springfield.com", users[1]->mail()->address());
    
    Admin* admin = static_cast<Admin*>(users[1]); // like (Admin*) cast 
    EXPECT_EQ("c3R1ZGVudA", admin->password());
    
    // Teardown 
    delete users[0]->mail();
    delete users[0];
    delete users[1]->mail();
    delete users[1];
}
