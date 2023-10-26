#ifndef DD_FAN_H_
#define DD_FAN_H_

#define DD_FAN_PIN 45
#define DD_FAN_ON HIGH
#define DD_FAN_OFF LOW

void dd_fan_setup();

int dd_fan_GetState();
int dd_fan_TurnOn();
int dd_fan_TurnOff();

#endif
