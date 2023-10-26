#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "serial_ui/serial_ui.h"
#include "dd_dht/dd_dht.h"
#include "dd_button/dd_button.h"
#include "sh_control/sh_control.h"
#include "dd_window/dd_window.h"

// define two tasks for Blink & AnalogRead
void TaskSerialUI(void *pvParameters);
void Task_DD_DHT(void *pvParameters);
void Task_SH_Control(void *pvParameters);
void Task_DD_Window(void *pvParameters);

// the setup function runs once when you press reset or power the board
void setup()
{

    // Now set up two tasks to run independently.
    xTaskCreate(TaskSerialUI, "TaskSerialUI", 2024, NULL, 2, NULL);
    // Now set up two tasks to run independently.
    xTaskCreate(Task_DD_DHT, "Task_DD_DHT", 512, NULL, 2, NULL);
    // Now set up two tasks to run independently.
    xTaskCreate(Task_SH_Control, "Task_SH_Control", 512, NULL, 2, NULL);
    // Now set up two tasks to run independently.
    xTaskCreate(Task_DD_Window, "Task_DD_Window", 512, NULL, 2, NULL);

    // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
    // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskSerialUI(void *pvParameters) // This is a task.
{
    (void)pvParameters;
    serial_ui_setup();
    for (;;) // A Task shall never return or exit.
    {
        serial_ui_loop();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}


void Task_DD_DHT(void *pvParameters) // This is a task.
{
    (void)pvParameters;
    dd_dht_setup();
    // Serial.println(F("DHTxx Started!"));
    for (;;) // A Task shall never return or exit.
    {
        dd_dht_loop();

        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void Task_SH_Control(void *pvParameters) // This is a task.
{
    (void)pvParameters;
    sh_control_setup();
    vTaskDelay(500/portTICK_PERIOD_MS);
    Serial.println(F("Task_SH_Control Started!"));
    for (;;) // A Task shall never return or exit.
    {
        sh_control_loop();
        vTaskDelay(100/portTICK_PERIOD_MS);

    }
}

void Task_DD_Window(void *pvParameters) // This is a task.
{
    (void)pvParameters;
    dd_window_setup();

    for (;;) // A Task shall never return or exit.
    {
        dd_window_loop();
        vTaskDelay(50/portTICK_PERIOD_MS);

    }
}




