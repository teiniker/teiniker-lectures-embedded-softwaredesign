#include <sm_led.h>

void sm_led_handler_off(enum events event);
void sm_led_handler_on(enum events event);

// Default values
enum sm_states state = OFF; 
int is_current_on = false;

// State Machine 
void sm_led(enum events event)
{
    switch(state)
    {
        case OFF:
            sm_led_handler_off(event);
            break;

        case ON:
            sm_led_handler_on(event);
            break;
    }
}

// Handle Events in State: OFF
void sm_led_handler_off(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
            is_current_on = true;
            state = ON;
        break;

        case SWITCH_OFF:
        break;
    }
}

// Handle Events in State: ON
void sm_led_handler_on(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
        break;

        case SWITCH_OFF:
            is_current_on = false;
            state = OFF;
        break;
    }
}