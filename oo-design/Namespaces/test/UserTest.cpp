#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <User.h>

// C++ offers namespaces as a mechanism for expressing that some declarations
// belong together and that their names should not clash with other names.
// By putting a class or function into a namespace (we can also nest namespaces) 
// we can ensure that our names do no conflict other names.
//
// The simplest way to access a name in another namespace is to qualify it with
// the namespace name:
// Example: org::se::lab::User()
//
// We can also bring the name into scope with a "using" declaration:  
// Example: using org::se::lab::User;
// Example: using namespace org::se::lab;

using namespace std;
using namespace org::se::lab;
//using org::se::lab::User;

//org::se::lab::User* user = NULL;
User* user = NULL;

TEST_GROUP(UserTestGroup)
{
    void setup()
    {
//        user = new org::se::lab::User(7, "homer", "c3R1ZGVudA");
        user = new User(7, "homer", "c3R1ZGVudA");
    }

    void teardown()
    {
        delete user;
    }
};


TEST(UserTestGroup, ConstructorTest)
{
    // Verify
    CHECK_EQUAL(7, user->id());
    CHECK_EQUAL("homer", user->username());
    CHECK_EQUAL("c3R1ZGVudA", user->password());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
