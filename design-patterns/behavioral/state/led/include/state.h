#pragma once

// Forward declaration of Led so LedState can reference it.
class Led;

class State
{
public:
    virtual ~State() = default;
    
    // Handler methods
    virtual void handleSwitchOn(Led& led) = 0;
    virtual void handleSwitchOff(Led& led) = 0;
};