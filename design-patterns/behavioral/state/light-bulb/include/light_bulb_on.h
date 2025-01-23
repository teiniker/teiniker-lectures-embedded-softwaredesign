#pragma once

#include <memory>
#include "light_bulb_state.h"

class LightBulbOn : public LightBulbState
{
public:
    // Singleton
    static std::shared_ptr<LightBulbOn> getInstance();
    
    // // Handler methods for state ON
    void handleSwitchOn(LightBulb& bulb) override;
    void handleSwitchOff(LightBulb& bulb) override;
    
private:
    // Private constructor to enforce singleton usage
    LightBulbOn() = default;
};