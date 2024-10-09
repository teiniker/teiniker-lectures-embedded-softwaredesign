#include <gtest/gtest.h>

#include <order.h>

using namespace std;

// Copy Constructor Test for Product
TEST(OrderTest, CopyConstructorProductTest) 
{
    // Setup
    Product* original = new Product(1, "Pizza Frutti di Mare", 880);
    
    // Exercise
    Product* copy = new Product(*original);
    delete original;
    
    // Verify
    EXPECT_EQ(1, copy->id());
    EXPECT_EQ("Pizza Frutti di Mare", copy->description());
    EXPECT_EQ(880, copy->price());
    
    // Teardown
    delete copy;
}

// Copy Constructor Test for OrderLine
TEST(OrderTest, CopyConstructorOrderLineTest) 
{
    // Setup
    OrderLine* original = new OrderLine(3, 10, new Product(1, "Pizza Frutti di Mare", 880));
    
    // Exercise
    OrderLine* copy = new OrderLine(*original);
    delete original->product();
    delete original;
    
    // Verify
    EXPECT_EQ(3, copy->id());
    EXPECT_EQ(10, copy->quantity());
    
    Product* p = copy->product();
    EXPECT_EQ(1, p->id());
    EXPECT_EQ("Pizza Frutti di Mare", p->description());
    EXPECT_EQ(880, p->price());
    
    // Teardown
    delete copy->product();
    delete copy;
}

// Copy Constructor Test for Order
TEST(OrderTest, CopyConstructorOrderTest) 
{
    // Setup
    Order* original = new Order(5, "Special Order");
    original->addLine(new OrderLine(3, 10, new Product(1, "Pizza Frutti di Mare", 880)));
    
    // Exercise
    Order* copy = new Order(*original);
    delete original->line(0)->product();
    delete original->line(0);
    delete original;
    
    // Verify
    EXPECT_EQ(5, copy->id());
    EXPECT_EQ("Special Order", copy->name());
    
    OrderLine* line = copy->line(0);
    EXPECT_EQ(3, line->id());
    EXPECT_EQ(10, line->quantity());
    
    Product* p = line->product();
    EXPECT_EQ(1, p->id());
    EXPECT_EQ("Pizza Frutti di Mare", p->description());
    EXPECT_EQ(880, p->price());
    
    // Teardown
    delete copy->line(0)->product();
    delete copy->line(0);
    delete copy;
}
