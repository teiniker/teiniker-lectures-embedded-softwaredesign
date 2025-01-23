#pragma once

#include <memory>
#include <stdexcept>

#include "light_bulb_state.h"
#include "light_bulb_off.h"

// The C++ "LightBulb" class mirroring your Java version
class LightBulb
{
public:
    // Constructor sets initial state to "Off"
    LightBulb();

    // Trigger methods
    void switchOn();
    void switchOff();

    // Activity methods
    void currentOn();
    void currentOff();

    // Accessor methods
    void state(std::shared_ptr<LightBulbState> state);
    std::shared_ptr<LightBulbState> state() const;

    bool isCurrentOn() const;

private:
    // We hold a pointer (often a smart pointer) to the current state
    std::shared_ptr<LightBulbState> _state;
    bool _isCurrentOn = false;
};