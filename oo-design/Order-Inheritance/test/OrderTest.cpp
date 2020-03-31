#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Order.h>

using namespace std;

Order* order = NULL;

TEST_GROUP(OrderTestGroup)
{
    void setup()
    {
        Product* p1 = new Product(1, "Pizza Frutti di Mare", 880);
        Product* p2 = new Product(2, "Pizza Quattro Formaggi", 820);
        
        OrderLine* line1 = new OrderLine(3, 10, p1);
        OrderLine* line2 = new OrderLine(4, 12, p2);
        
        order = new Order(5, "Special Order");
        order->addLine(line1);
        order->addLine(line2);
    }

    void teardown()
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


TEST(OrderTestGroup, OrderTest)
{
    // Verify
    CHECK_EQUAL(5, order->id());
    CHECK_EQUAL("Special Order", order->name());
    CHECK_EQUAL(2, order->numberOfLines());
}

TEST(OrderTestGroup, OrderLine1Test)
{
    // Verify
    OrderLine* line1 = order->line(0); 
    CHECK_EQUAL(3, line1->id());
    CHECK_EQUAL(10, line1->quantity());
}

TEST(OrderTestGroup, OrderLine2Test)
{
    // Verify
    OrderLine* line2 = order->line(1); 
    CHECK_EQUAL(4, line2->id());
    CHECK_EQUAL(12, line2->quantity());
}

TEST(OrderTestGroup, Product1Test)
{
    // Verify
    Product* p1 = order->line(0)->product();
    CHECK_EQUAL(1, p1->id());
    CHECK_EQUAL("Pizza Frutti di Mare", p1->description());
    CHECK_EQUAL(880, p1->price());
}

TEST(OrderTestGroup, Product2Test)
{
    // Verify
    Product* p2 = order->line(1)->product();
    CHECK_EQUAL(2, p2->id());
    CHECK_EQUAL("Pizza Quattro Formaggi", p2->description());
    CHECK_EQUAL(820, p2->price());
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
