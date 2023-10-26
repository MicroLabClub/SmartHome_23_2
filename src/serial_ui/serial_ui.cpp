#include <Arduino.h>
#include <stdint.h>

#include "serial_ui.h"
#include "dd_dht/dd_dht.h"
#include "dd_button/dd_button.h"
#include "dd_fan/dd_fan.h"
#include "dd_window/dd_window.h"
#include "sh_control/sh_control.h"

void serial_ui_setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Smart Home on-line");
}

void serial_ui_loop()
{
  // put your main code here, to run repeatedly:
  int8_t cmd;
  int16_t param1;

  if (Serial.available())
  {
    cmd = Serial.read();
    if (cmd == 'a')
    {
      Serial.println("SH : Am primit comanda 'a'");
      Serial.println("SH : Introdu valoares parametruluu A: ");
      delay(1000);
      param1 = Serial.parseInt();
      Serial.print("SH : Parametru A = ");
      Serial.println(param1);
    }
    else
    {
      Serial.println("SH : Am primit comada NECUNOSCUTA");
    }
  }

  Serial.println();
  Serial.println(" Smart Home is operating...");

  serial_ui_dht_report();
  serial_ui_button_report();
  serial_ui_fan_report();
  serial_ui_window_report();
  serial_ui_conrol_report();
  // delay(1000);
}

void serial_ui_dht_report()
{

  int err = dd_dht_GetError();
  if (err == 0)
  {

    Serial.print("SH DHT    |");
    float h = dd_dht_GetHumidity();
    Serial.print(F("  Humidity: "));
    Serial.print(h);
    Serial.print("  |");

    float t = dd_dht_GetTemperature();
    Serial.print(F("  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.println();
  }
  else
  {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
}

void serial_ui_button_report()
{

  Serial.print("SH BUTTON |");

  int btn_state = dd_button_IsPressed_Left();
  Serial.print(F("  Button Left : "));
  Serial.print(btn_state);
  Serial.print("  |");

  btn_state = dd_button_IsPressed_Right();
  Serial.print(F("  Button Right : "));
  Serial.print(btn_state);
  Serial.println();
}

void serial_ui_fan_report()
{

  Serial.print("SH FAN    | ");

  int fan_state = dd_fan_GetState();
  Serial.print(F(" FAN State : "));
  Serial.print(fan_state);
  Serial.println();
}

void serial_ui_window_report()
{

  Serial.print("SH WINDOW | ");

  int win_state = dd_window_GetCurrentPosition();
  Serial.print(F(" WIN State : "));
  Serial.print(win_state);
  Serial.println();
}

void serial_ui_conrol_report()
{

  Serial.print("SH WINDOW | ");

  float th_state = sh_control_GetTempTH();
  Serial.print(F(" TH State : "));
  Serial.print(th_state);
  Serial.println();
}
