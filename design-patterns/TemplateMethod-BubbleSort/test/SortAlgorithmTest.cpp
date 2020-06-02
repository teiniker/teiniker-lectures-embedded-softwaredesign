#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <BubbleSortAsc.h>
#include <BubbleSortDes.h>

using namespace std;

TEST_GROUP(SortTestGroup)
{
};

TEST(SortTestGroup, AscendingTest)
{
    shared_ptr<SortAlgorithm> algorithm(new BubbleSortAsc());

    int data[10] = {7,3,9,1,4,2,8,0,5,6};

    algorithm->sort(data, 10);
    
    // Verify
    CHECK_EQUAL(0, data[0]);
    CHECK_EQUAL(1, data[1]);
    CHECK_EQUAL(2, data[2]);
    CHECK_EQUAL(3, data[3]);
    CHECK_EQUAL(4, data[4]);
    CHECK_EQUAL(5, data[5]);
    CHECK_EQUAL(6, data[6]);
    CHECK_EQUAL(7, data[7]);
    CHECK_EQUAL(8, data[8]);
    CHECK_EQUAL(9, data[9]);
}

TEST(SortTestGroup, DescendingTest)
{
    shared_ptr<SortAlgorithm> algorithm(new BubbleSortDes());

    int data[10] = {7,3,9,1,4,2,8,0,5,6};

    algorithm->sort(data, 10);
    
    // Verify
    CHECK_EQUAL(9, data[0]);
    CHECK_EQUAL(8, data[1]);
    CHECK_EQUAL(7, data[2]);
    CHECK_EQUAL(6, data[3]);
    CHECK_EQUAL(5, data[4]);
    CHECK_EQUAL(4, data[5]);
    CHECK_EQUAL(3, data[6]);
    CHECK_EQUAL(2, data[7]);
    CHECK_EQUAL(1, data[8]);
    CHECK_EQUAL(0, data[9]);
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
