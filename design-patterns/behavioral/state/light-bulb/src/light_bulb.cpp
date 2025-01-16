#include <light_bulb.h>

using namespace std;

// Constructor sets initial state to "Off"
LightBulb::LightBulb()
{
    setState(LightBulbOff::getInstance());
}

// Trigger methods
void LightBulb::turnOn()
{
    _state->handleTurnOn(*this);
}

void LightBulb::turnOff()
{
    _state->handleTurnOff(*this);
}


// Protect the setter/getter as in Java
void LightBulb::setState(std::shared_ptr<LightBulbState> state)
{
    _state = state;
}

std::shared_ptr<LightBulbState> LightBulb::getState() const
{
    return _state;
}
