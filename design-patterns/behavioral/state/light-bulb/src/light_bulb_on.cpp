#include <iostream>
#include "light_bulb.h"
#include "light_bulb_off.h"
#include "light_bulb_on.h"

using namespace std;

shared_ptr<LightBulbOn> LightBulbOn::getInstance()
{
    static shared_ptr<LightBulbOn> instance(new LightBulbOn());
    return instance;
}

// Implement abstract methods
void LightBulbOn::handleSwitchOn(LightBulb& bulb)
{
    // do nothing
    (void) bulb;
}

void LightBulbOn::handleSwitchOff(LightBulb& bulb) 
{
    bulb.currentOff();
    bulb.state(LightBulbOff::getInstance());
}
