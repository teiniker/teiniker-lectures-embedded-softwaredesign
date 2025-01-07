#include <gtest/gtest.h>
#include "table.h"

using namespace std;


class UserTableTest : public ::testing::Test 
{
protected:
    UserTable table;

    void SetUp() override 
    {
        User homer(7, "homer", "c3R1ZGVudA");
        table.insertUser(homer);
        User marge(8, "marge", "x8shjsGjws");
        table.insertUser(marge);
    }

    void TearDown() override 
    {
    }
};

TEST_F(UserTableTest, SizeTest) 
{
    size_t size = table.size();
    // Verify
    EXPECT_EQ(2, size);
}

TEST_F(UserTableTest, HomerFindByIdTest) 
{
    User user = table.findById(7);
    // Verify
    EXPECT_EQ(7, user.id());
    EXPECT_EQ("homer", user.username());
    EXPECT_EQ("c3R1ZGVudA", user.password());
}

TEST_F(UserTableTest, MargeFindByIdTest) 
{
    User user = table.findById(8);
    // Verify
    EXPECT_EQ(8, user.id());
    EXPECT_EQ("marge", user.username());
    EXPECT_EQ("x8shjsGjws", user.password());
}

TEST_F(UserTableTest, HomerFindByUsernameTest) 
{
    User user = table.findByUsername("homer");
    // Verify
    EXPECT_EQ(7, user.id());
    EXPECT_EQ("homer", user.username());
    EXPECT_EQ("c3R1ZGVudA", user.password());
}

TEST_F(UserTableTest, MargeFindByUsernameTest) 
{
    User user = table.findByUsername("marge");
    // Verify
    EXPECT_EQ(8, user.id());
    EXPECT_EQ("marge", user.username());
    EXPECT_EQ("x8shjsGjws", user.password());
}

TEST_F(UserTableTest, UpdateUserTest) 
{
    // Exercise
    User homer(7, "homer", "Loh76Gtsjkd?9()sjd6");
    table.updateUser(homer);

    // Verify
    User user = table.findById(7);
    EXPECT_EQ(7, user.id());
    EXPECT_EQ("homer", user.username());
    EXPECT_EQ("Loh76Gtsjkd?9()sjd6", user.password());
}