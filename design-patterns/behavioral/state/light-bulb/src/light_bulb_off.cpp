#include <iostream>
#include "light_bulb.h"
#include "light_bulb_off.h"
#include "light_bulb_on.h"

using namespace std;

shared_ptr<LightBulbOff> LightBulbOff::getInstance()
{
    static shared_ptr<LightBulbOff> instance(new LightBulbOff());
    return instance;
}

// Implement abstract methods
void LightBulbOff::handleTurnOn(LightBulb& bulb)
{
    cout << "Turning the light on." << endl;
    bulb.setState(LightBulbOn::getInstance());
}

void LightBulbOff::handleTurnOff(LightBulb& bulb) 
{
    // do nothing
    (void) bulb;
}

    