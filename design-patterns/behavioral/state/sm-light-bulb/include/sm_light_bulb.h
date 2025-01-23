#pragma once

// Events 
enum events
{
    SWITCH_ON,
    SWITCH_OFF
};

// States
enum sm_states 
{
    OFF,
    ON
};
extern enum sm_states state; 

// Activities
extern int is_current_on;

// State Machine 
void sm_bulb(enum events event);

