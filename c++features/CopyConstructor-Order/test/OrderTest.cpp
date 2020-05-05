#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <Order.h>

using namespace std;

TEST_GROUP(OrderTestGroup)
{
};


TEST(OrderTestGroup, CopyConstructorProductTest)
{
    // Setup
    Product* original = new Product(1, "Pizza Frutti di Mare", 880);
    
    // Exercise
    Product* copy = new Product(*original);    
    delete original;
    
    // Verify
    CHECK_EQUAL(1, copy->id());
    CHECK_EQUAL("Pizza Frutti di Mare", copy->description());
    CHECK_EQUAL(880, copy->price());
    
    // Teardown
    delete copy;
}


TEST(OrderTestGroup, CopyConstructorOrderLineTest)
{
    // Setup
    OrderLine* original = new OrderLine(3, 10, new Product(1, "Pizza Frutti di Mare", 880));
    
    // Exercise
    OrderLine* copy = new OrderLine(*original);
    delete original->product();
    delete original;
    
    // Verify
    CHECK_EQUAL(3, copy->id());
    CHECK_EQUAL(10, copy->quantity());
    
    Product* p = copy->product();
    CHECK_EQUAL(1, p->id());
    CHECK_EQUAL("Pizza Frutti di Mare", p->description());
    CHECK_EQUAL(880, p->price());

    // Teardown
    delete copy->product();
    delete copy;
}


TEST(OrderTestGroup, CopyConstructorOrderTest)
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
    CHECK_EQUAL(5, copy->id());
    CHECK_EQUAL("Special Order", copy->name());
    
    OrderLine* line = copy->line(0);
    CHECK_EQUAL(3, line->id());
    CHECK_EQUAL(10, line->quantity());

    Product* p = line->product();
    CHECK_EQUAL(1, p->id());
    CHECK_EQUAL("Pizza Frutti di Mare", p->description());
    CHECK_EQUAL(880, p->price());

    // Teardown
    delete copy->line(0)->product();
    delete copy->line(0);
    delete copy;    
}


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
