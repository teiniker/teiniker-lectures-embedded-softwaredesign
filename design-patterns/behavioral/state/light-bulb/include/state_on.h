#pragma once

#include <memory>
#include <state.h>

class StateOn : public State
{
public:
    // Singleton
    static std::shared_ptr<StateOn> getInstance();
    
    // // Handler methods for state ON
    void handleSwitchOn(LightBulb& bulb) override;
    void handleSwitchOff(LightBulb& bulb) override;
    
private:
    // Private constructor to enforce singleton usage
    StateOn() = default;
};