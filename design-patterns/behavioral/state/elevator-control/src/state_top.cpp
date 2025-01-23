#include <controller.h>
#include <state_top.h>
#include <state_upward.h>

using namespace std;

// Singleton 
shared_ptr<StateTop> StateTop::getInstance()
{
    static shared_ptr<StateTop> instance(new StateTop());
    return instance;
}

// Implement handler methods for StateTop

void StateTop::handlePushUpButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateTop::handlePushDownButton(Controller& controller)
{
    controller.state(StateDownward::getInstance());
    controller.motorBackward();
}

void StateTop::handleEndSwitchTop(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateTop::handleEndSwitchBottom(Controller& controller)
{
    // Do nothing
    (void) controller;
}
