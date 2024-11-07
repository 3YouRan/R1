//#include "debug.h"
//#include"stdint.h"
//#include "usart.h"
//#include <stdarg.h>
//#include <stdio.h>
//#include "pid.h"
////#include "init.h"
//#include "string.h"
//#include "stdlib.h"
////#include "drv_can.h"
//#include "FreeRTOS.h"
//#include "semphr.h"
//#define TX_BUF_SIZE 512
//uint8_t send_buf[TX_BUF_SIZE];
////float index_vec=0;
////extern Pid vec_pid;
////extern Pid pos_pid;
//extern int cnt_mood;
//extern SemaphoreHandle_t g_CAN_TASK_Semphr;
//
//
//uint8_t DataBuff[200];//指令内容
////原来写的u_int8_t,怪不得串口你接收不到数据呢，dyy你纯属傻逼啊
//
//
//uint8_t debugRvAll[DEBUG_RV_MXSIZE]={0};//存放要传入的数据
//
//
//
//char *pEnd;
//int start_flag = 0;//用vofa软件设计电机启动，start_flag为标志位
//
//
////串口发送
////重定向串口打印函数，在操作系统里打印的问题
////已解决
//void usart_printf(const char* format, ...)
//{
//    va_list args;
//    uint32_t length;
//    va_start(args, format);
//
//    length = vsnprintf((char*)send_buf, TX_BUF_SIZE, (const char*)format, args);
//
//    va_end(args);
//
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t*)send_buf, length);
//}
//
//
//
////串口接收
//void Set_Target_UartInit()
//{
//    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);//使能串口一的空闲中断,用于串口接收
//    HAL_UART_Receive_DMA(&huart1, (uint8_t*)&debugRvAll, DEBUG_RV_MXSIZE);//开启串口的DMA接收，debugRvAll存储串口接受的第一手数据
//}
//
//void Set_Target_UartIdleCallback(UART_HandleTypeDef *huart);
//void Set_Target_UartIrqHandler(UART_HandleTypeDef *huart)
//{
//    if(huart->Instance == huart1.Instance)//判断是否是串口1
//    {
//        if(RESET != __HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE))//判断是否是空闲中断
//        {
//            __HAL_UART_CLEAR_IDLEFLAG(huart);//清楚空闲中断标志，防止会一直不断进入中断
//            Set_Target_UartIdleCallback(huart);//调用中断处理函数
//        }
//    }
//}
//
//
