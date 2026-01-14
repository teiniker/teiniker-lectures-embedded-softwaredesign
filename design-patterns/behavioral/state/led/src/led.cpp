#include <led.h>

using namespace std;

// Constructor sets initial state to OFF

Led::Led()
{
    state(StateOff::getInstance());
}

// Trigger methods

void Led::switchOn()
{
    _state->handleSwitchOn(*this);
}

void Led::switchOff()
{
    _state->handleSwitchOff(*this);
}

// Activity methods

void Led::currentOn()
{
    _isCurrentOn = true;
}

void Led::currentOff()
{
    _isCurrentOn = false;
}


// Accessor methods
void Led::state(std::shared_ptr<State> state)
{
    _state = state;
}

std::shared_ptr<State> Led::state() const
{
    return _state;
}

bool Led::isCurrentOn() const
{
    return _isCurrentOn;
}
