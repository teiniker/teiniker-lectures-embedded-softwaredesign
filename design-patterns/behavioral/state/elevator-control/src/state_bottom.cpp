#include <controller.h>
#include <state_bottom.h>
#include <state_upward.h>

using namespace std;

// Singleton 
shared_ptr<StateBottom> StateBottom::getInstance()
{
    static shared_ptr<StateBottom> instance(new StateBottom());
    return instance;
}

// Implement handler methods for StateBottom

void StateBottom::handlePushUpButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateBottom::handlePushDownButton(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateBottom::handleEndSwitchTop(Controller& controller)
{
    // Do nothing
    (void) controller;
}

void StateBottom::handleEndSwitchBottom(Controller& controller)
{
    // Do nothing
    (void) controller;
}
