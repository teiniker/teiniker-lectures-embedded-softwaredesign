#pragma once

#include <memory>
#include "light_bulb_state.h"

// Forward declaration of LightBulb so we can reference it here
class LightBulb;

class LightBulbOn : public LightBulbState
{
public:
    // Static "singleton-like" instance accessor (similar to LightBulbOff.INSTANCE in Java)
    static std::shared_ptr<LightBulbOn> getInstance();
    
    // Implement abstract methods
    void handleTurnOn(LightBulb& bulb) override;
    void handleTurnOff(LightBulb& bulb) override;
    
private:
    // Private constructor to enforce singleton usage
    LightBulbOn() = default;
};