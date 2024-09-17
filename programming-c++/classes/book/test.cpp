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

TEST(BookTest, ToJson) 
{
    Book book("978-0131103627", "Brian W. Kernighan and Dennis Ritchie", "The C Programming Language");                         
    std::string json = book.toJson();
    std::cout << "json: " << json << std::endl;

    std::string expected = "{\"isbn\":\"978-0131103627\",\"author\":\"Brian W. Kernighan and Dennis Ritchie\",\"title\":\"The C Programming Language\"}";
    EXPECT_EQ(expected, json);
}


int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
