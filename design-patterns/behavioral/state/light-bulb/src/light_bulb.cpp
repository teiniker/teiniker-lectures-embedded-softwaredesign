#include <light_bulb.h>

using namespace std;

// Constructor sets initial state to OFF

LightBulb::LightBulb()
{
    state(LightBulbOff::getInstance());
}

// Trigger methods

void LightBulb::switchOn()
{
    _state->handleSwitchOn(*this);
}

void LightBulb::switchOff()
{
    _state->handleSwitchOff(*this);
}

// Activity methods

void LightBulb::currentOn()
{
    _isCurrentOn = true;
}

void LightBulb::currentOff()
{
    _isCurrentOn = false;
}


// Accessor methods
void LightBulb::state(std::shared_ptr<LightBulbState> state)
{
    _state = state;
}

std::shared_ptr<LightBulbState> LightBulb::state() const
{
    return _state;
}

bool LightBulb::isCurrentOn() const
{
    return _isCurrentOn;
}
