#pragma once

// Forward declaration of LightBulb so LightBulbState can reference it.
class LightBulb;

class LightBulbState
{
public:
    virtual ~LightBulbState() = default;
    
    // Handler methods
    virtual void handleSwitchOn(LightBulb& bulb) = 0;
    virtual void handleSwitchOff(LightBulb& bulb) = 0;
};