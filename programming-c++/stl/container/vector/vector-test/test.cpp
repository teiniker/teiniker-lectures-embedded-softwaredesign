#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

TEST(VectorTest, VectorLength) 
{
   vector<int> numbers = {7, 5, 16, 8};
   size_t len = numbers.size();

   EXPECT_EQ(4, len);
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

   EXPECT_EQ(expected, numbers);
}

TEST(VectorTest, VectorPushBack) 
{
   vector<int> numbers = {7, 5, 16, 8};
   numbers.push_back(25);
   numbers.push_back(13);

   EXPECT_EQ(6, numbers.size());
   EXPECT_EQ(25, numbers[4]);
   EXPECT_EQ(13, numbers[5]);
}

TEST(VectorTest, VectorForEach) 
{
   vector<int> numbers = {7, 5, 16, 8};

   for(int n : numbers) 
   {
      printf("%3d\n", n);
   }
}

TEST(VectorTest, VectorSort) 
{
   vector<int> numbers = {7, 5, 16, 8};
   sort(numbers.begin(), numbers.end());

   vector<int> expected = {5, 7, 8, 16};
   EXPECT_EQ(expected, numbers);
}

// Comparator function to sort in descending order
bool compareDesc(int a, int b) 
{
   return a > b;
}

TEST(VectorTest, VectorSortDescending) 
{
   vector<int> numbers = {7, 5, 16, 8};
   sort(numbers.begin(), numbers.end(), compareDesc);

   vector<int> expected = {16, 8, 7, 5};
   EXPECT_EQ(expected, numbers);
}
