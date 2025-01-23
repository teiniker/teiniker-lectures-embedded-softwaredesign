#include <controller.h>
#include <state_bottom.h>
#include <state_upward.h>

using namespace std;

// Singleton 
shared_ptr<StateUpward> StateUpward::getInstance()
{
    static shared_ptr<StateUpward> instance(new StateUpward());
    return instance;
}


// Implement handler methods for StateBottom

void StateUpward::handlePushUpButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateUpward::handlePushDownButton(Controller& controller)
{
    controller.state(StateDownward::getInstance());
    controller.motorBackward();
}

void StateUpward::handleEndSwitchTop(Controller& controller)
{
    controller.state(StateTop::getInstance());
    controller.motorStop();
}

void StateUpward::handleEndSwitchBottom(Controller& controller)
{
    // Do nothing
    (void) controller;
}
