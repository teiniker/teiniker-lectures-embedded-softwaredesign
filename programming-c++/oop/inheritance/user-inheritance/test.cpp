#include <gtest/gtest.h>
#include <vector>

#include "user.h"
#include "admin.h"
#include "mail.h"

using namespace std;

TEST(UserTestGroup, UserTest) 
{
    // Setup 
    Mail* mail = new Mail("homer.simpson@springfield.com");
    User* user = new User(7, "homer", mail);

    // Exercise + Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("homer.simpson@springfield.com", user->mail()->address());

    // Teardown
    delete user->mail();
    delete user;
}

TEST(AdminTestGroup, AdminTest) 
{
    // Setup 
    Mail* mail = new Mail("monti.burns@springfield.com");
    Admin* admin = new Admin(7, "burns", "c3R1ZGVudA", mail);
    
    // Exercise + Verify
    EXPECT_EQ(7, admin->id());
    EXPECT_EQ("burns", admin->username());
    EXPECT_EQ("c3R1ZGVudA", admin->password());
    EXPECT_EQ("monti.burns@springfield.com", admin->mail()->address());

    // Teardown
    delete admin->mail();
    delete admin;
}

TEST(AdminTestGroup, PolymorphTest) 
{
    // Setup 
    Mail* mail = new Mail("monti.burns@springfield.com");
    User* admin = new Admin(7, "burns", "c3R1ZGVudA", mail); // Admin "is a" User
    
    // Exercise + Verify
    EXPECT_EQ(7, admin->id());
    EXPECT_EQ("burns", admin->username());
    EXPECT_EQ("monti.burns@springfield.com", admin->mail()->address());

    // For dynamic_cast<> to work correctly: The base class (User) must be polymorphic 
    // (i.e., have at least one virtual function).
    EXPECT_EQ("c3R1ZGVudA", static_cast<Admin*>(admin)->password());

    // Teardown
    delete admin->mail();
    delete admin;
}

TEST(PolymorphTestGroup, PolymorphVectorTest) 
{
    // Setup
    vector<User*> users;    // Admin "is a" User
    users.push_back(new User(3, "homer", new Mail("homer.simpson@springfield.com"))); 
    users.push_back(new Admin(7, "burns", "c3R1ZGVudA", new Mail("monti.burns@springfield.com")));
    
    // Exercise + Verify
    EXPECT_EQ(3, users[0]->id());
    EXPECT_EQ("homer", users[0]->username());
    EXPECT_EQ("homer.simpson@springfield.com", users[0]->mail()->address());

    EXPECT_EQ(7, users[1]->id());
    EXPECT_EQ("burns", users[1]->username());
    EXPECT_EQ("monti.burns@springfield.com", users[1]->mail()->address());
    
    Admin* admin = static_cast<Admin*>(users[1]); // Admin "is a" User
    EXPECT_EQ("c3R1ZGVudA", admin->password());
    
    // Teardown 
    delete users[0]->mail();
    delete users[0];
    delete users[1]->mail();
    delete users[1];
}
