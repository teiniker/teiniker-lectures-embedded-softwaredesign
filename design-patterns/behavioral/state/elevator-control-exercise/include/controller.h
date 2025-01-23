#pragma once

#include <memory>
#include <stdexcept>

#include <state_bottom.h>
#include <state_upward.h>
#include <state_downward.h>
#include <state_top.h>

enum class MotorDirection
{
    STOP,
    FORWARD,
    BACKWARD
}; 


class Controller
{
public:
    Controller();

    // Trigger methods
    void pushUpButton();
    void pushDownButton();
    void endSwitchTop();
    void endSwitchBottom();

    // Activity methods
    void motorStop();
    void motorForward();
    void motorBackward();

    // Accessor methods
    void state(std::shared_ptr<State> state);
    std::shared_ptr<State> state() const;

    MotorDirection motor() const;
    void motor(MotorDirection motor);

private:
    // We hold a pointer (often a smart pointer) to the current state
    std::shared_ptr<State> _state;
    MotorDirection _motor = MotorDirection::STOP;
};
