#pragma once

#include <memory>
#include <state.h>

class StateOff : public State
{
public:
    // Singleton
    static std::shared_ptr<StateOff> getInstance();
    
    // Handler methods for state OFF
    void handleSwitchOn(LightBulb& bulb) override;
    void handleSwitchOff(LightBulb& bulb) override;
    
private:
    // Private constructor to enforce singleton usage
    StateOff() = default;
};