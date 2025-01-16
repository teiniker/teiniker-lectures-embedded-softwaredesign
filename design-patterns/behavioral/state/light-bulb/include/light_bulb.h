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
    void turnOn();

    void turnOff();

    // Protect the setter/getter as in Java
    void setState(std::shared_ptr<LightBulbState> state);
    std::shared_ptr<LightBulbState> getState() const;

private:
    // We hold a pointer (often a smart pointer) to the current state
    std::shared_ptr<LightBulbState> _state;
};