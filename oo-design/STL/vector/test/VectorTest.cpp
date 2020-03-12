#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <iostream>
#include <vector>

using namespace std;


TEST_GROUP(VectorTestGroup)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(VectorTestGroup, ReadElemetsTest)
{
    // Setup 
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(7);        

    // Verify
    CHECK_EQUAL(3, numbers.size());
    
    CHECK_EQUAL(1, numbers[0]);
    CHECK_EQUAL(3, numbers[1]);
    CHECK_EQUAL(7, numbers[2]);
    
    CHECK_EQUAL(3, numbers.at(1));
    
    CHECK_EQUAL(1, numbers.front());
    CHECK_EQUAL(7, numbers.back());
}


TEST(VectorTestGroup, ModifyElementsTest)
{    
    // Setup 
    vector<int> numbers(5);

    // Exercise    
    numbers[1] = 13;
    numbers[3] = 17;
        
    // Verify
    CHECK_EQUAL(5, numbers.size());
    
    CHECK_EQUAL(0, numbers[0]);
    CHECK_EQUAL(13, numbers[1]);
    CHECK_EQUAL(0, numbers[2]);
    CHECK_EQUAL(17, numbers[3]);
    CHECK_EQUAL(0, numbers[4]);
}


TEST(VectorTestGroup, RemoveElementsTest)
{    
    // Setup 
    vector<int> numbers(10);

    // Exercise    
    numbers.clear();

    // Verify
    CHECK_EQUAL(0, numbers.size());
    CHECK(numbers.empty());
}


TEST(VectorTestGroup, HeapTest)
{    
    // Setup 
    vector<int>* numbers = new vector<int>;
    numbers->push_back(1);
    numbers->push_back(3);
 
    // Verify
    CHECK_EQUAL(2, numbers->size());
 
    CHECK_EQUAL(1, numbers->at(0));
    CHECK_EQUAL(3, (*numbers)[1]);
 
    // Tear down
    delete numbers;
}    


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
