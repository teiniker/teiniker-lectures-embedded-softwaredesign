#include <gtest/gtest.h>

#include <list_to_lower.h>
#include <list_to_upper.h>

using namespace std;

// Common interface for all algorithms
shared_ptr<ListProcessor> algorithm = nullptr;

TEST(ListProcessorGroup, ToUpper)
{
    // Setup
    algorithm = make_shared<ListToUpper>();
    vector<string> data = {"Marge", "Homer", "Bart", "Lisa", "Maggie"};

    // Exercise
    algorithm->process(data);
    
    // Verify
    vector<string> expected = {"MARGE", "HOMER", "BART", "LISA", "MAGGIE"};
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], data[i]);
    }
}

TEST(ListProcessorGroup, ToLower)
{
    // Setup
    algorithm = make_shared<ListToLower>();
    vector<string> data = {"Marge", "Homer", "Bart", "Lisa", "Maggie"};

    // Exercise
    algorithm->process(data);
    
    // Verify
    vector<string> expected = {"marge", "homer", "bart", "lisa", "maggie"};
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], data[i]);
    }
}
