#pragma once

#include <memory>
#include <state.h>

class StateTop : public State
{
public:
    // Singleton
    static std::shared_ptr<StateTop> getInstance();
    
    // // Handler methods for state ON
    void handlePushUpButton(Controller& controller) override;
    void handlePushDownButton(Controller& controller) override;
    void handleEndSwitchTop(Controller& controller) override;
    void handleEndSwitchBottom(Controller& controller) override;
    
private:
    // Private constructor to enforce singleton usage
    StateTop() = default;
};