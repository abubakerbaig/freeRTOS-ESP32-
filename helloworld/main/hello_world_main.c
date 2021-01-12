#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include"esp_log.h"

#include <stdio.h>
#include"sdkconfig.h"
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

int count;
TaskHandle_t Task1_handle;

void task1(void *data)   {
    
        ESP_LOGD("Msg from Task1:", "Task1 started\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    
    vTaskDelete(Task1_handle);
}


void app_main(void) {

    xTaskCreate(task1,"Mirza TASK", 2048, NULL, 5, &Task1_handle);
    while(1)    {
        ESP_LOGD("Msg from Main:", "Main Task started counting : %d\n ",count++);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}