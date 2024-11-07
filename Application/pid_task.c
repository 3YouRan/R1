//
// Created by 陈瑜 on 24-11-7.
//

#include "all.h"
float Current=0;

void pid_task(void *arg)
{
    while(1)
    {
        xSemaphoreTake(g_SemaphoreHandle_For_Pid, portMAX_DELAY);
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5);
        Current= FW_PID_Realize(&pid_speed,Target_Speed,-gm3508_1.rotor_speed/19.0);
        GM3508_Current_Set(&hcan1,Current,0,0,0,0x200, GM_ID(1)|GM_ID(2));

    }
}