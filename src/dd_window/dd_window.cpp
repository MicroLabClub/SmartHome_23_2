#include "dd_window.h"
#include "Arduino.h"

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

#define DD_WINDOW_SERVO_PIN 4
#define DD_WIN_CLOSE_POS 125
#define DD_WIN_OPEN_POS 0

Servo myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to store the servo position

int dd_window_target_pos = DD_WIN_CLOSE_POS;
int dd_window_current_pos = DD_WIN_CLOSE_POS;

void dd_window_setup()
{
    myservo.attach(DD_WINDOW_SERVO_PIN); // attaches the servo on pin 9 to the servo object
    dd_window_target_pos = DD_WIN_CLOSE_POS;
    dd_window_current_pos = dd_window_target_pos;
    myservo.write(dd_window_current_pos);
}

void dd_window_loop()
{
    dd_window_target_pos = constrain(dd_window_target_pos,
                                     DD_WIN_OPEN_POS,
                                     DD_WIN_CLOSE_POS);
    dd_window_current_pos = constrain(dd_window_current_pos,
                                      DD_WIN_OPEN_POS,
                                      DD_WIN_CLOSE_POS);

    if (dd_window_current_pos > dd_window_target_pos)
    {
        dd_window_current_pos--;
    }
    else if (dd_window_current_pos < dd_window_target_pos)
    {
        dd_window_current_pos++;
    }
    myservo.write(dd_window_current_pos);
}

int dd_window_open()
{
    dd_window_target_pos = DD_WIN_OPEN_POS;
    return dd_window_target_pos;
}
int dd_window_close()
{
    dd_window_target_pos = DD_WIN_CLOSE_POS;
    return dd_window_target_pos;
}

int dd_window_GetCurrentPosition()
{
    return dd_window_current_pos;
}

void dd_window_test()
{

    for (pos = 0; pos <= 180; pos += 1)
    { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);          // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {                       // goes from 180 degrees to 0 degrees
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);          // waits 15 ms for the servo to reach the position
    }
}
