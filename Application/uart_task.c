//
// Created by 陈瑜 on 24-11-7.
//

#include "all.h"
extern  float Current;
void uart_tx_task(void *arg) {
//    int time1=0;
    while (1) {

        printf("R1:%.2f,%.2f,%.2f\n\r",pid_speed.kp,gm3508_1.rotor_speed/19.0,Target_Speed);
        vTaskDelay(100);


    }


}

void uart_rx_task(void *arg) {
    while (1) {

        xSemaphoreTake(g_UART_RX_Semaphore, portMAX_DELAY);

        USART_PID_Adjust(1);//鏁版嵁瑙ｆ瀽鍜屽弬鏁拌祴鍊煎嚱鏁?
//
        memset(DataBuff,0,sizeof(DataBuff));  //娓呯┖缂撳瓨鏁扮粍
        RxLine=0;  //娓呯┖鎺ユ敹闀垮害
    }


}