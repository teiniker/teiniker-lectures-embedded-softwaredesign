#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

using namespace std;

TEST(StringTest, SizeTest) 
{
   string str = "Hello World";
   size_t len = str.size();

   EXPECT_EQ(11, len);
}


TEST(StringTest, AtTest) 
{
   string str = "Hello World";
   char c1 = str[4];
   char c2 = str.at(4);

   EXPECT_EQ(c1, c2);

   str.at(4) = 'O';
   EXPECT_EQ('O', str[4]);
}


TEST(StringTest, CStrTest) 
{
   string str = "Hello World";
   const char* s = str.c_str();

   EXPECT_STREQ("Hello World", s);
   EXPECT_EQ(11, strlen(s));
   EXPECT_EQ('\0', s[11]);
}


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

