//
// Created by 陈瑜 on 24-9-16.
//

#ifndef RC_WORK1_ALL_H
#define RC_WORK1_ALL_H

#include "retarget.h"

#include "tim.h"

#include "DJI_driver.h"

#include "PID_Adjust.h"

#include "string.h"

#include "main.h"

#include "PID_Adjust.h"

#include "PID.h"

#include "can.h"

#include "usart.h"

#include "my_can.h"

#include "my_can.h"

#include "FreeRTOS.h"

#include "task.h"

#include "semphr.h"

#include <stdbool.h>

#include "uart_task.h"

#include "pid_task.h"
#include "PIDC1.h"
#include "PIDC.h"


extern float Target_Speed;
extern float Target_Speed_actual;
extern float MIN_Spe_Increment;
extern float Target_Position;
extern float Target_Current;
extern PID pid_position;
extern PID pid_speed;
extern PID pid_current;


extern uint8_t RxBuffer[1];
extern uint16_t RxLine;
extern uint8_t DataBuff[200];


extern DJI_motor gm3508_1;
extern DJI_motor gm3508_2;
extern float angle_last_1, angle_now_1, angle_total_1;
extern float angle_last_2, angle_now_2, angle_total_2;
extern int16_t current;

extern TaskHandle_t g_uart_tx_task_handle;

extern SemaphoreHandle_t g_UART_RX_Semaphore;
extern SemaphoreHandle_t g_SemaphoreHandle_For_Pid;
extern void my_Init();
#define pi 3.1416
extern float angle;

/* Block states (default storage) */
extern DW_PIDC PIDC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PIDC PIDC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PIDC PIDC_Y;

#define param_1 PIDC_U
#define current_out_1 PIDC_Y.current
#define target_speed_1 PIDC_U.S_TAR

#define param_2 PIDC1_U
#define current_out_2 PIDC1_Y.Spe_out1
#define target_speed_2 PIDC1_U.S_TAR
#endif //RC_WORK1_ALL_H
