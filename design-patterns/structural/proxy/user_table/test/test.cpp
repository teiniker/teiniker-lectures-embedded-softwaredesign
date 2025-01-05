#include <gtest/gtest.h>

#include <user_table_impl.h>
#include <user_table_proxy.h>

using namespace std;

class ProxyTestGroup : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Setup: --->[:UserTableProxy]--->[:UserTableImpl]
        impl = make_shared<UserTableImpl>();
        proxy = make_shared<UserTableProxy>(impl);
    }

    shared_ptr<UserTable> impl;
    shared_ptr<UserTable> proxy;
};


TEST_F(ProxyTestGroup, UserTableTest)
{
    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));
    shared_ptr<User> marge(new User(13, "marge", "Ljd667bb%4"));

    impl->insert(homer);
    impl->insert(marge);

    shared_ptr<User> user = impl->findUserById(7);
    
    // Verify
    EXPECT_EQ(7, user->id());
    EXPECT_EQ("homer", user->username());
    EXPECT_EQ("c3R1ZGVudA", user->password());
}

TEST_F(ProxyTestGroup, UserTableProxyTest)
{
    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));
    shared_ptr<User> marge(new User(13, "marge", "Ljd667bb%4"));

    proxy->insert(homer);
    proxy->insert(marge);
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
    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));

    // Verify
    EXPECT_THROW(proxy->findUserById(-1), invalid_argument);
}
