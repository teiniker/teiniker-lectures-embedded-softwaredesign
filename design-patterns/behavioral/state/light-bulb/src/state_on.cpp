#include <light_bulb.h>
#include <state_off.h>
#include <state_on.h>

using namespace std;

// Singleton 
shared_ptr<StateOn> StateOn::getInstance()
{
    static shared_ptr<StateOn> instance(new StateOn());
    return instance;
}

// Implement abstract methods
void StateOn::handleSwitchOn(LightBulb& bulb)
{
    // do nothing
    (void) bulb;
}

void StateOn::handleSwitchOff(LightBulb& bulb) 
{
    bulb.currentOff();
    bulb.state(StateOff::getInstance());
}
