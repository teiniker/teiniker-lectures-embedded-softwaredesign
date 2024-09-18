#include<gtest/gtest.h>
#include <vector>

using namespace std;

class VectorTestFixture : public ::testing::Test 
{
protected:
    vector<int> numbers;

    void SetUp() override 
    {
        // Initialize the vector before each test
        printf("SetUp()\n");
        numbers = {7, 5, 16, 8};
    }

    void TearDown() override 
    {
        // Clean up after each test if necessary
        printf("TearDown()\n");
    }
};


TEST_F(VectorTestFixture, VectorLength) 
{
    printf("VectorLength\n");
    size_t len = numbers.size();
    ASSERT_EQ(4, len);
}

TEST_F(VectorTestFixture, IndexOperator) 
{
    printf("IndexOperator\n");
    EXPECT_EQ(7, numbers[0]);
    EXPECT_EQ(5, numbers[1]);
    EXPECT_EQ(16, numbers[2]);
    EXPECT_EQ(8, numbers[3]);
}

TEST_F(VectorTestFixture, Equals) 
{
    printf("Equals\n");
    vector<int> expected = {7, 5, 16, 8};
    ASSERT_TRUE(expected == numbers);
}

TEST_F(VectorTestFixture, PushBack) 
{
    printf("PushBack\n");
    numbers.push_back(25);
    numbers.push_back(13);

    ASSERT_EQ(6, numbers.size());
    EXPECT_EQ(25, numbers[4]);
    EXPECT_EQ(13, numbers[5]);
}
