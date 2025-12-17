#include <gtest/gtest.h>

#include <user_table_impl.h>
#include <user_table_proxy.h>

using namespace std;

class ProxyTestGroup : public ::testing::Test
{
protected:
    shared_ptr<UserTable> impl;
    shared_ptr<UserTable> proxy;

    void SetUp() override
    {
        // Dependency Injection: [:Test] --->[:UserTableProxy]--->[:UserTableImpl]
        impl = make_shared<UserTableImpl>();
        proxy = make_shared<UserTableProxy>(impl);  // Constructor injection 
    }
};


TEST_F(ProxyTestGroup, UserTableTest)   // Without Proxy
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

TEST_F(ProxyTestGroup, UserTableProxyTest)
{
    // Setup
    auto homer = make_shared<User>(7, "homer", "c3R1ZGVudA");
    auto marge = make_shared<User>(13, "marge", "Ljd667bb%4");
    proxy->insert(homer);
    proxy->insert(marge);

    // Exercise
    shared_ptr<User> user = proxy->findUserById(7);
    
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
}

TEST_F(ProxyTestGroup, ValidateUserTest)
{
    // Verify
    EXPECT_THROW(proxy->insert(nullptr), invalid_argument);
}

TEST_F(ProxyTestGroup, ValidateIdTest)
{
    // Verify
    EXPECT_THROW(proxy->findUserById(-1), invalid_argument);
}
