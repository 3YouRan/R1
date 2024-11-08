/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "all.h"
#include "pid_task.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
xTaskHandle g_uart_tx_task_handle;
xTaskHandle g_pid_task_handle;

SemaphoreHandle_t g_UART_RX_Semaphore;
SemaphoreHandle_t g_SemaphoreHandle_For_Pid;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for PIDTASK */
osThreadId_t PIDTASKHandle;
const osThreadAttr_t PIDTASK_attributes = {
  .name = "PIDTASK",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void pid_taskl(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  g_UART_RX_Semaphore = xSemaphoreCreateBinary();
  g_SemaphoreHandle_For_Pid = xSemaphoreCreateBinary();
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of PIDTASK */
  PIDTASKHandle = osThreadNew(pid_taskl, NULL, &PIDTASK_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
    xTaskCreate(uart_tx_task, "UART_TX_Task", 128, NULL, osPriorityNormal, &g_uart_tx_task_handle);
    xTaskCreate(uart_rx_task, "UART_RX_Task", 128, NULL, osPriorityNormal+2, &g_uart_tx_task_handle);
  // xTaskCreate(pid_task, "PID_Task", 512, NULL, osPriorityHigh, &g_pid_task_handle);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_pid_taskl */
/**
* @brief Function implementing the PIDTASK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_pid_taskl */
void pid_taskl(void *argument)
{
  /* USER CODE BEGIN pid_taskl */
  portTickType CurrentTime_PID;

  /* Infinite loop */
  for(;;)
  {
    CurrentTime_PID=xTaskGetTickCount();

    pidc_task();
    vTaskDelayUntil(&CurrentTime_PID,5);
  }
  /* USER CODE END pid_taskl */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

