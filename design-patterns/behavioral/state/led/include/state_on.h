#pragma once

#include <memory>
#include <state.h>

class StateOn : public State
{
public:
    // Singleton
    static std::shared_ptr<StateOn> getInstance();
    
    // // Handler methods for state ON
    void handleSwitchOn(Led& led) override;
    void handleSwitchOff(Led& led) override;
    
private:
    // Private constructor to enforce singleton usage
    StateOn() = default;
};