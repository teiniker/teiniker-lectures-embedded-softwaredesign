#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

using namespace std;

/**
 * size() returns the number of elements in the string.
 **/
TEST(StringTest, SizeTest) 
{
   string str = "Hello World";
   size_t len = str.size();

   EXPECT_EQ(11, len);
}


/**
 * Operator[] returns a reference to the character at specified location pos 
 * if pos < size(), or a reference to CharT() if pos == size(). 
 * No bounds checking is performed.
 * 
 * at() returns a reference to the character at specified location pos. 
 * Bounds checking is performed, exception of type std::out_of_range will 
 * be thrown on invalid access.
 **/ 
TEST(StringTest, AtTest) 
{
   string str = "Hello World";
   char c1 = str[4];
   char c2 = str.at(4);

   EXPECT_EQ(c1, c2);

   str.at(4) = 'O';
   EXPECT_EQ('O', str[4]);
}


/**
 * c_str() returns a pointer to a null-terminated character array with data 
 * equivalent to those stored in the string.
 * Note that c_str() and data() perform the same function.
 **/
TEST(StringTest, CStrTest) 
{
   string str = "Hello World";
   const char* s = str.c_str();

   EXPECT_STREQ("Hello World", s);
   EXPECT_EQ(11, strlen(s));
   EXPECT_EQ('\0', s[11]);
}


/**
 * Comparison Operators (==, !=, <, >, <=, >=):
 * We can use the comparison operators directly with std::string objects. 
 * These operators compare the lexicographical order of the strings.
 **/
TEST(StringTest, ComparisonOperatorsTest) 
{
   string str1 = "Hello";
   string str2 = "World";

   EXPECT_FALSE(str1 == str2);
   EXPECT_TRUE(str1 != str2);
   EXPECT_TRUE(str1 < str2);
   EXPECT_FALSE(str1 > str2);
}


TEST(StringTest, ConcatenationTest) 
{
   string str1 = "Hello ";
   string str2 = "World";

   string str = str1 + str2;

   EXPECT_TRUE("Hello World" == str);
}

