#pragma once

#include <memory>
#include "light_bulb_state.h"

// Forward declaration of LightBulb so we can reference it here
class LightBulb;

class LightBulbOff : public LightBulbState
{
public:
    // Singleton
    static std::shared_ptr<LightBulbOff> getInstance();
    
    // Handler methods for state OFF
    void handleSwitchOn(LightBulb& bulb) override;
    void handleSwitchOff(LightBulb& bulb) override;
    
private:
    // Private constructor to enforce singleton usage
    LightBulbOff() = default;
};