#include <gtest/gtest.h>
#include "date.h"

TEST(DateTest, Constructor) 
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth

    EXPECT_EQ(23, birthday.getDay());
    EXPECT_EQ(6, birthday.getMonth());
    EXPECT_EQ(1912, birthday.getYear());
}

TEST(DateTest, ConstructorWithNew) 
{
    Date* birthday = new Date(23, 6, 1912);

    EXPECT_EQ(23, birthday->getDay());
    EXPECT_EQ(6, birthday->getMonth());
    EXPECT_EQ(1912, birthday->getYear());

    delete birthday;
}

TEST(DateTest, IsLeapYear) 
{
    Date birthday(23, 6, 1912);

    EXPECT_TRUE(birthday.isLeapYear());
}

TEST(DateTest, Setters) 
{
    Date birthday(23, 6, 1912);

    // Using setter methods to modify the Date object
    birthday.setDay(24);
    birthday.setMonth(7);
    birthday.setYear(1913);

    EXPECT_EQ(24, birthday.getDay());
    EXPECT_EQ(7, birthday.getMonth());
    EXPECT_EQ(1913, birthday.getYear());
}

// Use gtest_main library
