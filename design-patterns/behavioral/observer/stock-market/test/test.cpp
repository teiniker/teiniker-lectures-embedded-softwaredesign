#include <gtest/gtest.h>

#include <stockmarket.h>
#include <observer.h>

using namespace std;


TEST(StockMarket, ObserverTest)
{
    // Setup
    shared_ptr<StockMarket> stockMarket = make_shared<StockMarket>();
    shared_ptr<DaxObserver> daxObserver = make_shared<DaxObserver>(stockMarket);
    shared_ptr<DowObserver> dowObserver = make_shared<DowObserver>(stockMarket);
    stockMarket->attach(daxObserver);
    stockMarket->attach(dowObserver);

    // Exercise
    stockMarket->dax(13000);
    stockMarket->dowJones(30000);
    
    // Verify
    EXPECT_EQ(daxObserver->lastDax(), 13000);
    EXPECT_EQ(dowObserver->lastDowJones(), 30000);    
}
