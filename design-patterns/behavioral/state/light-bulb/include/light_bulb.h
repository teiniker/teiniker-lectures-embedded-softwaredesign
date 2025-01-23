#pragma once

#include <memory>
#include <stdexcept>

#include <state_on.h>
#include <state_off.h>

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
    void state(std::shared_ptr<State> state);
    std::shared_ptr<State> state() const;

    bool isCurrentOn() const;

private:
    // We hold a pointer (often a smart pointer) to the current state
    std::shared_ptr<State> _state;
    bool _isCurrentOn = false;
};