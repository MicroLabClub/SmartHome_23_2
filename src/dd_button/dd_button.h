#ifndef DD_BUTTON_H_
#define DD_BUTTON_H_


#define DD_BUTTON_LEFT_PIN 2
#define DD_BUTTON_RIGHT_PIN 3

#define BUTTON_PRESSED LOW
#define BUTTON_RELEASED HIGH

int dd_button_IsPressed_Left(void);
int dd_button_IsPressed_Right(void);

void dd_button_setup();

#endif


