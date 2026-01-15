#include <gtest/gtest.h>

#include <temp_sensor.h>
#include <observer.h>

using namespace std;


TEST(StockMarket, ObserverTest)
{
    // Setup
    shared_ptr<TempSensor> tempSensor = make_shared<TempSensor>();
    shared_ptr<Logger> logger = make_shared<Logger>();
    shared_ptr<Display> display = make_shared<Display>();
    tempSensor->attach(display);
    tempSensor->attach(logger);

    // Exercise
    tempSensor->temperature(25.5);
    tempSensor->humidity(60.0);
    
    // Verify
    EXPECT_DOUBLE_EQ(display->temperature(), 25.5);
    EXPECT_DOUBLE_EQ(display->humidity(), 60.0);    
}
