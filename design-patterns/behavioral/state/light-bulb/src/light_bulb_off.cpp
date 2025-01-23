#include <iostream>
#include "light_bulb.h"
#include "light_bulb_off.h"
#include "light_bulb_on.h"

using namespace std;

// Singleton 
shared_ptr<LightBulbOff> LightBulbOff::getInstance()
{
    static shared_ptr<LightBulbOff> instance(new LightBulbOff());
    return instance;
}

// Implement handler methods for state OFF

void LightBulbOff::handleSwitchOn(LightBulb& bulb)
{
    bulb.currentOn();
    bulb.state(LightBulbOn::getInstance());
}

void LightBulbOff::handleSwitchOff(LightBulb& bulb) 
{
    // do nothing
    (void) bulb;
}

    