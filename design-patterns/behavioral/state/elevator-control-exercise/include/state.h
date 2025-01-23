#pragma once

// Forward declaration 
class Controller;

class State
{
public:
    virtual ~State() = default;
    
    // Handler methods
    virtual void handlePushUpButton(Controller& controller) = 0;
    virtual void handlePushDownButton(Controller& controller) = 0;
    virtual void handleEndSwitchTop(Controller& controller) = 0;
    virtual void handleEndSwitchBottom(Controller& controller) = 0;
};