#include<gtest/gtest.h>
#include <vector>

using namespace std;

TEST(VectorTest, Length) 
{
    vector<int> numbers = {7, 5, 16, 8};
    size_t len = numbers.size();

    ASSERT_EQ(4, len);
}

TEST(VectorTest, IndexOperator) 
{
    vector<int> numbers = {7, 5, 16, 8};

    EXPECT_EQ(7, numbers[0]);
    EXPECT_EQ(5, numbers[1]);
    EXPECT_EQ(16, numbers[2]);
    EXPECT_EQ(8, numbers[3]);
}

TEST(VectorTest, Equals) 
{
    vector<int> numbers = {7, 5, 16, 8};

    vector<int> expected = {7, 5, 16, 8};
    ASSERT_TRUE(expected == numbers);
}

TEST(VectorTest, PushBack) 
{
    vector<int> numbers = {7, 5, 16, 8};
    numbers.push_back(25);
    numbers.push_back(13);

    ASSERT_EQ(6, numbers.size());
    EXPECT_EQ(25, numbers[4]);
    EXPECT_EQ(13, numbers[5]);
}

// Use gtest_main library
/*
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/