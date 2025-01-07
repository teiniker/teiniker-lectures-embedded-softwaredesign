#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test 
{
protected:
    Stack* stack;

    void SetUp() override 
    {
        stack = new Stack();
        stack->push(1);
        stack->push(3);
        stack->push(5);
    }

    void TearDown() override 
    {
        delete stack;
    }
};


TEST_F(StackTest, IsNotEmpty) 
{
    EXPECT_FALSE(stack->isEmpty());
}

TEST_F(StackTest, IsEmpty) 
{
    stack->pop();
    stack->pop();
    stack->pop();
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, Pop) 
{
    EXPECT_EQ(5, stack->pop());
    EXPECT_EQ(3, stack->pop());
    EXPECT_EQ(1, stack->pop());
}

TEST_F(StackTest, Top) 
{
    EXPECT_EQ(5, stack->top()); // top element is not removed
    EXPECT_EQ(5, stack->top());
}
