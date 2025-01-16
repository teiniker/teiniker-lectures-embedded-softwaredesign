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
void LightBulbOn::handleTurnOn(LightBulb& bulb)
{
    // do nothing
    (void) bulb;
}

void LightBulbOn::handleTurnOff(LightBulb& bulb) 
{
    cout << "Turning the light off." << endl;
    bulb.setState(LightBulbOff::getInstance());
}

    