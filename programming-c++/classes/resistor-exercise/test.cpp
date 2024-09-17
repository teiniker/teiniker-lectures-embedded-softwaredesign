#include <gtest/gtest.h>

#include "resistor.h"


TEST(ResistorTest, Constructor) 
{
    Resistor r(470, 2); // Stack

    EXPECT_EQ(470, r.value());
    EXPECT_EQ(2, r.tolerance());
}

TEST(ResistorTest, ConstructorWithNew) 
{
    Resistor* r = new Resistor(470, 2); // Heap

    ASSERT_NE(r, nullptr);
    EXPECT_EQ(470, r->value());
    EXPECT_EQ(2, r->tolerance());

    delete r;
}

TEST(ResistorTest, SerialConnection) 
{
    Resistor r1(270, 5);
    Resistor r2(120, 2);
    
    r1.serial(r2);

    EXPECT_EQ(270 + 120, r1.value());
    EXPECT_EQ(5, r1.tolerance());
}

TEST(ResistorTest, ParallelConnection) 
{
    Resistor r1(270, 5);
    Resistor r2(120, 2);
    
    r1.parallel(r2);
    EXPECT_EQ(270 * 120 / (270 + 120), r1.value());
    EXPECT_EQ(5, r1.tolerance());
}


int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}