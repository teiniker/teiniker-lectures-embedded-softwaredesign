#pragma once

#include <memory>
#include <state.h>

class StateOff : public State
{
public:
    // Singleton
    static std::shared_ptr<StateOff> getInstance();
    
    // Handler methods for state OFF
    void handleSwitchOn(Led& led) override;
    void handleSwitchOff(Led& led) override;
    
private:
    // Private constructor to enforce singleton usage
    StateOff() = default;
};