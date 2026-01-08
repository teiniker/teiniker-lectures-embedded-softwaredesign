#include <gtest/gtest.h>

#include <user_table_impl.h>
#include <user_table_decorator.h>

using namespace std;

class DecoratorTestGroup : public ::testing::Test
{
protected:
    shared_ptr<UserTable> impl;
    shared_ptr<UserTable> table;
    
    void SetUp() override
    {
        // Dependency Injection: [:Test] --->[:UserTableLogger]--->[:UserTableImpl]
        impl = make_shared<UserTableImpl>();
        table = make_shared<UserTableLogger>(impl); // Constructor injection
    }
};


TEST_F(DecoratorTestGroup, UserTableTest)
{
    // Setup
    auto homer = make_shared<User>(7, "homer", "c3R1ZGVudA");
    auto marge = make_shared<User>(13, "marge", "Ljd667bb%4");
    impl->insert(homer);
    impl->insert(marge);

    // Exercise
    auto user = impl->findUserById(7);
    
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
}

TEST_F(DecoratorTestGroup, UserTableDecoratorTest)
{
    // Setup
    auto homer = make_shared<User>(7, "homer", "c3R1ZGVudA");
    auto marge = make_shared<User>(13, "marge", "Ljd667bb%4");
    table->insert(homer);
    table->insert(marge);
    // Exercise
    shared_ptr<User> user = table->findUserById(7);
    
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
}

