#include <gtest/gtest.h>

#include <bubble_sort_asc.h>
#include <bubble_sort_des.h>

using namespace std;

TEST(SortTestGroup, AscendingTest)
{
    shared_ptr<SortAlgorithm> algorithm(new BubbleSortAsc());

    int data[10] = {7,3,9,1,4,2,8,0,5,6};

    algorithm->sort(data, 10);
    
    // Verify
    int expected[] = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 10; i++)
    {
        EXPECT_EQ(expected[i], data[i]);
    }
}

TEST(SortTestGroup, DescendingTest)
{
    shared_ptr<SortAlgorithm> algorithm(new BubbleSortDes());

    int data[10] = {7,3,9,1,4,2,8,0,5,6};
    algorithm->sort(data, 10);
    
    // Verify
    int expected[] = {9,8,7,6,5,4,3,2,1,0};
    for(int i = 0; i < 10; i++)
    {
        EXPECT_EQ(expected[i], data[i]);
    }
}
