#include <gtest/gtest.h>
#include "date.h"

TEST(DateTest, Constructor) 
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth

    EXPECT_EQ(23, birthday.day());
    EXPECT_EQ(6, birthday.month());
    EXPECT_EQ(1912, birthday.year());
}

TEST(DateTest, ConstructorWithNew) 
{
    Date* birthday = new Date(23, 6, 1912);

    EXPECT_EQ(23, birthday->day());
    EXPECT_EQ(6, birthday->month());
    EXPECT_EQ(1912, birthday->year());

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
    birthday.day(24);
    birthday.month(7);
    birthday.year(1913);

    EXPECT_EQ(24, birthday.day());
    EXPECT_EQ(7, birthday.month());
    EXPECT_EQ(1913, birthday.year());
}
