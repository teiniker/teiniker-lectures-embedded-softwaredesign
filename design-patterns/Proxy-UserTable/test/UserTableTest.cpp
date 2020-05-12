#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <UserTableImpl.h>
#include <UserTableProxy.h>

using namespace std;

TEST_GROUP(ProxyTestGroup)
{
};

TEST(ProxyTestGroup, UserTableTest)
{
    shared_ptr<UserTable> table(new UserTableImpl());
    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));
    shared_ptr<User> marge(new User(13, "marge", "Ljd667bb%4"));

    table->insert(homer);
    table->insert(marge);

    shared_ptr<User> user = table->findUserById(7);
    
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());
}


TEST(ProxyTestGroup, UserTableProxyTest)
{
    // Setup: --->[:UserTableProxy]--->[:UserTableImpl]
    shared_ptr<UserTable> impl(new UserTableImpl());
    shared_ptr<UserTable> table(new UserTableProxy(impl));  

    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));
    shared_ptr<User> marge(new User(13, "marge", "Ljd667bb%4"));

    // Exercise
    table->insert(homer);
    table->insert(marge);
    shared_ptr<User> user = table->findUserById(7);
    
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());
}

TEST(ProxyTestGroup, ValidateUserTest)
{
    // Setup: --->[:UserTableProxy]--->[:UserTableImpl]
    shared_ptr<UserTable> impl(new UserTableImpl());
    shared_ptr<UserTable> table(new UserTableProxy(impl));  

    // Verify
    CHECK_THROWS(invalid_argument, table->insert(NULL));
}

TEST(ProxyTestGroup, ValidateIdTest)
{
    // Setup: --->[:UserTableProxy]--->[:UserTableImpl]
    shared_ptr<UserTable> impl(new UserTableImpl());
    shared_ptr<UserTable> table(new UserTableProxy(impl));  

    shared_ptr<User> homer(new User(7, "homer", "c3R1ZGVudA"));

    // Verify
    CHECK_THROWS(invalid_argument, table->findUserById(-1));
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
