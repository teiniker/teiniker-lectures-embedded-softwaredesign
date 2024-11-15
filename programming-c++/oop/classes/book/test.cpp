#include <gtest/gtest.h>

#include "book.h"

using namespace std;

TEST(BookTest, Constructor) 
{
    // Setup
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    
    // Exercise + Verify
    EXPECT_EQ("978-0131103627", book.isbn());
    EXPECT_EQ("Brian W. Kernighan and Dennis Ritchie", book.author());
    EXPECT_EQ("The C Programming Language", book.title());

    // Teardown
}

TEST(BookTest, ToJson) 
{
    // Setup
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    
    // Exercise
    std::string json = book.toJson();
    printf("json: %s\n", json.c_str());

    // Verify
    std::string expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    EXPECT_EQ(expected, json);

    // Teardown
}

TEST(BookTest, Heap) 
{
    // Setup
    Book *book = new Book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    
    // Exercise + Verify 
    EXPECT_EQ("978-0131103627", book->isbn());
    EXPECT_EQ("Brian W. Kernighan and Dennis Ritchie", book->author());
    EXPECT_EQ("The C Programming Language", book->title());

    // Teardown 
    delete book;
}
