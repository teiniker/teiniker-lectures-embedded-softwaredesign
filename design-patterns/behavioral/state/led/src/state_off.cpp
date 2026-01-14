#include <led.h>
#include <state_off.h>
#include <state_on.h>

using namespace std;

// Singleton 
shared_ptr<StateOff> StateOff::getInstance()
{
    static shared_ptr<StateOff> instance(new StateOff());
    return instance;
}

// Implement handler methods for state OFF

void StateOff::handleSwitchOn(Led& bulb)
{
    bulb.currentOn();
    bulb.state(StateOn::getInstance());
}

void StateOff::handleSwitchOff(Led& bulb) 
{
    // do nothing
    (void) bulb;
}
