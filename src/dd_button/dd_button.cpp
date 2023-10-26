#include "dd_button.h"
#include "Arduino.h"

void dd_button_setup(){
    pinMode(DD_BUTTON_LEFT_PIN,INPUT);
    pinMode(DD_BUTTON_RIGHT_PIN,INPUT);
}

int dd_button_IsPressed_Left(void){
    int button_state = digitalRead(DD_BUTTON_LEFT_PIN);
    return button_state == BUTTON_PRESSED;
}
int dd_button_IsPressed_Right(void){
    int button_state = digitalRead(DD_BUTTON_RIGHT_PIN);
    return button_state == BUTTON_PRESSED;
}