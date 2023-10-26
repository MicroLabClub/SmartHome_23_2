#include "sh_control.h"
#include "../dd_button/dd_button.h"
#include "../dd_fan/dd_fan.h"
#include "../dd_window/dd_window.h"

void sh_control_setup()
{
    dd_button_setup();
    dd_fan_setup();
}

float sh_temp_TH = 24.5;
float sh_temp_delta = 0.1;
float sh_temp_current = sh_temp_TH;

float sh_control_GetTempTH(){
    return sh_temp_TH;
}

void sh_control_loop()
{

    if (dd_button_IsPressed_Left())
    {
        // dd_fan_TurnOff();
        // dd_window_close();
        sh_temp_TH -= 0.1;
    }
    if (dd_button_IsPressed_Right())
    {
        // dd_fan_TurnOn();
        // dd_window_open();
        sh_temp_TH += 0.1;

    }

    if( sh_temp_current > (sh_temp_TH + sh_temp_delta)){

        dd_window_open();
        
    }  else  if( sh_temp_current < (sh_temp_TH - sh_temp_delta)){

        dd_window_close();
    }
    





}