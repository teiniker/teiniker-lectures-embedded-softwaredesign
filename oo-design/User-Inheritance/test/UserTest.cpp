#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <vector>

#include <User.h>
#include <Admin.h>
#include <Mail.h>

using namespace std;

TEST_GROUP(UserTestGroup)
{
};


TEST(UserTestGroup, UserTest)
{
    // Setup
    Mail* mail = new Mail("homer.simpson@springfield.com");
    User* user = new User(7, "homer", mail);
    
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    
    CHECK_EQUAL("homer.simpson@springfield.com", user->mail()->address());

    // Teardown 
    delete user->mail();
    delete user;
}

TEST(UserTestGroup, AdminTest)
{
    // Setup
    Mail* mail = new Mail("monti.burns@springfield.com");
    Admin* admin = new Admin(7, "burns", "c3R1ZGVudA", mail);
    
    // Verify
    CHECK_EQUAL(7, admin->id());
    CHECK_EQUAL("burns", admin->username());
    
    CHECK_EQUAL("monti.burns@springfield.com", admin->mail()->address());

    // Teardown 
    delete admin->mail();
    delete admin;
}

TEST(UserTestGroup, PolymorphTest)
{
    // Setup
    vector<User*> users;
    users.push_back(new User(3, "homer", new Mail("homer.simpson@springfield.com"))); 
    users.push_back(new Admin(7, "burns", "c3R1ZGVudA", new Mail("monti.burns@springfield.com")));
    
    // Verify
    CHECK_EQUAL(3, users[0]->id());
    CHECK_EQUAL(7, users[1]->id());
    CHECK_EQUAL("homer", users[0]->username());
    CHECK_EQUAL("burns", users[1]->username());
    CHECK_EQUAL("homer.simpson@springfield.com", users[0]->mail()->address());
    CHECK_EQUAL("monti.burns@springfield.com", users[1]->mail()->address());
    
    Admin* admin = static_cast<Admin*>(users[1]); // like (Admin*) cast 
    CHECK_EQUAL("c3R1ZGVudA", admin->password());
    
    // Teardown 
    delete users[0]->mail();
    delete users[0];
    delete users[1]->mail();
    delete users[1];
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
