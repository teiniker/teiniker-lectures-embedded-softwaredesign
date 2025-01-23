#include <controller.h>
#include <state_bottom.h>
#include <state_downward.h>

using namespace std;

// Singleton 
shared_ptr<StateDownward> StateDownward::getInstance()
{
    static shared_ptr<StateDownward> instance(new StateDownward());
    return instance;
}

// Implement handler methods for StateBottom

void StateDownward::handlePushUpButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateDownward::handlePushDownButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateDownward::handleEndSwitchTop(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateDownward::handleEndSwitchBottom(Controller& controller)
{
    // Do nothing
    (void) controller;
}
