#include <led.h>
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
void StateOn::handleSwitchOn(Led& bulb)
{
    // do nothing
    (void) bulb;
}

void StateOn::handleSwitchOff(Led& bulb) 
{
    bulb.currentOff();
    bulb.state(StateOff::getInstance());
}
