#include <gtest/gtest.h>

#include "order.h"

using namespace std;

class OrderTest : public ::testing::Test 
{
protected:
    Order* order;

    void SetUp() override 
    {
        Product* p1 = new Product(1, "Pizza Frutti di Mare", 880);
        Product* p2 = new Product(2, "Pizza Quattro Formaggi", 820);
        
        OrderLine* line1 = new OrderLine(3, 10, p1);
        OrderLine* line2 = new OrderLine(4, 12, p2);
        
        order = new Order(5, "Special Order");
        order->addLine(line1);
        order->addLine(line2);
    }

    void TearDown() override 
    {
        OrderLine* line1 = order->line(0); 
        OrderLine* line2 = order->line(1); 
        Product* p1 = line1->product();
        Product* p2 = line2->product();
        
        delete p1;
        delete p2;
        delete line1;
        delete line2;
        delete order;
    }
};


TEST_F(OrderTest, OrderTest) {
    EXPECT_EQ(5, order->id());
    EXPECT_EQ("Special Order", order->name());
    EXPECT_EQ(2, order->numberOfLines());
}

TEST_F(OrderTest, OrderLine1Test) 
{
    OrderLine* line1 = order->line(0); 
    EXPECT_EQ(3, line1->id());
    EXPECT_EQ(10, line1->quantity());
}

TEST_F(OrderTest, OrderLine2Test) 
{
    OrderLine* line2 = order->line(1); 
    EXPECT_EQ(4, line2->id());
    EXPECT_EQ(12, line2->quantity());
}

TEST_F(OrderTest, Product1Test) 
{
    Product* p1 = order->line(0)->product();
    EXPECT_EQ(1, p1->id());
    EXPECT_EQ("Pizza Frutti di Mare", p1->description());
    EXPECT_EQ(880, p1->price());
}

TEST_F(OrderTest, Product2Test) 
{
    Product* p2 = order->line(1)->product();
    EXPECT_EQ(2, p2->id());
    EXPECT_EQ("Pizza Quattro Formaggi", p2->description());
    EXPECT_EQ(820, p2->price());
}
