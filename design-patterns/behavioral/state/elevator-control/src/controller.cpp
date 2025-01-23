#include <controller.h>
#include <state.h>

using namespace std;

// Constructor sets initial state to OFF

Controller::Controller()
{
    state(StateBottom::getInstance());
}


// Trigger methods

void Controller::pushUpButton()
{
    _state->handlePushUpButton(*this);
}

void Controller::pushDownButton()
{
    _state->handlePushDownButton(*this);
}

void Controller::endSwitchTop()
{
    _state->handleEndSwitchTop(*this);
}

void Controller::endSwitchBottom()
{
    _state->handleEndSwitchBottom(*this);
}


// Activity methods

void Controller::motorStop()
{
    _motor = MotorDirection::STOP;   
}

void Controller::motorForward()
{
    _motor = MotorDirection::FORWARD;
}

void Controller::motorBackward()
{
    _motor = MotorDirection::BACKWARD;
}



// Accessor methods

void Controller::state(shared_ptr<State> state)
{
    _state = state;
}

shared_ptr<State> Controller::state() const
{
    return _state;
}

MotorDirection Controller::motor() const
{
    return _motor;
}

void Controller::motor(MotorDirection motor)
{
    _motor = motor;
}
