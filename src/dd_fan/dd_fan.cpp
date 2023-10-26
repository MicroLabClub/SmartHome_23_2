#include "dd_fan.h"
#include "Arduino.h"

int dd_fan_state = 0;

void dd_fan_setup()
{
    pinMode(DD_FAN_PIN, OUTPUT);
    digitalWrite(DD_FAN_PIN, DD_FAN_OFF);
    dd_fan_state = 0;
}

int dd_fan_GetState()
{
    return dd_fan_state;
}

int dd_fan_TurnOn()
{
    dd_fan_state = DD_FAN_ON;
    digitalWrite(DD_FAN_PIN, dd_fan_state);
    return dd_fan_state;
}

int dd_fan_TurnOff()
{
    dd_fan_state = DD_FAN_OFF;
    digitalWrite(DD_FAN_PIN, dd_fan_state);
    return dd_fan_state;
}