#include <gtest/gtest.h>

#include "book.h"

using namespace std;

TEST(BookTest, Constructor) 
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");

    EXPECT_EQ("978-0131103627", book.getIsbn());
    EXPECT_EQ("Brian W. Kernighan and Dennis Ritchie", book.getAuthor());
    EXPECT_EQ("The C Programming Language", book.getTitle());
}

TEST(BookTest, ConstructorWithNew) 
{
    Book* book = new Book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");

    EXPECT_EQ("978-0131103627", book->getIsbn());
    EXPECT_EQ("Brian W. Kernighan and Dennis Ritchie", book->getAuthor());
    EXPECT_EQ("The C Programming Language", book->getTitle());

    delete book;
}

TEST(BookTest, ToJson) 
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");
    string json = book.toJson();

    string expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    EXPECT_EQ(expected, json);
}

