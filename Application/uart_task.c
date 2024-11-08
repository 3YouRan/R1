//
// Created by 陈瑜 on 24-11-7.
//

#include "all.h"
#include "PIDC.h"

extern  float Current;
void uart_tx_task(void *arg) {
//    int time1=0;
    while (1) {

        printf("R1:%.2f,%.2f,%.2f,%f\n\r", param_1.P_P, param_1.P_TAR, angle_total_1, PIDC1_U.target_Pos);
        vTaskDelay(100);


    }


}

void uart_rx_task(void *arg) {
    while (1) {

        xSemaphoreTake(g_UART_RX_Semaphore, portMAX_DELAY);
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5);
        USART_PID_Adjust(1);//鏁版嵁瑙ｆ瀽鍜屽弬鏁拌祴鍊煎嚱鏁?
//
        memset(DataBuff,0,sizeof(DataBuff));  //娓呯┖缂撳瓨鏁扮粍
        RxLine=0;  //娓呯┖鎺ユ敹闀垮害
    }


}