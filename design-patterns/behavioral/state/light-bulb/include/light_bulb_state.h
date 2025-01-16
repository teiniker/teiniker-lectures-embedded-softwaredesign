#pragma once

// Forward declaration of LightBulb so LightBulbState can reference it.
class LightBulb;

// Abstract base class for all LightBulb states.
class LightBulbState
{
public:
    virtual ~LightBulbState() = default;
    
    // Pure virtual "handler" methods:
    virtual void handleTurnOn(LightBulb& bulb) = 0;
    virtual void handleTurnOff(LightBulb& bulb) = 0;
};