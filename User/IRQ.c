//
// Created by ��� on 24-9-18.
//
#include "all.h"

/*
 * @brief CAN�������ݻص�����
 *
 * @param hcan CAN���
 *
 * @return None
 */

float cnt;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    if (hcan->Instance == CAN1)
    {
        HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data); //receive can data
        //        printf("CAN_get_id:%x\r\n",rx_header.StdId);
        switch (rx_header.StdId)
        {
        case 0x201:
            {
                if (cnt <= 50)
                {
                    gm3508_1.rotor_angle_first = ((rx_data[0] << 8) | rx_data[1]);
                    cnt++;
                }
                if (cnt == 51)
                {
                    gm3508_1.rotor_angle = ((rx_data[0] << 8) | rx_data[1]);
                    gm3508_1.rotor_angle -= gm3508_1.rotor_angle_first;
                    gm3508_1.rotor_speed = ((rx_data[2] << 8) | rx_data[3]);
                    gm3508_1.torque_current = ((rx_data[4] << 8) | rx_data[5]);
                }

                break;
            }
        case 0x202:
            {
                if (cnt <= 50)
                {
                    gm3508_2.rotor_angle_first = ((rx_data[0] << 8) | rx_data[1]);
                    cnt++;
                }


                if (cnt == 51)
                {
                    gm3508_2.rotor_angle = ((rx_data[0] << 8) | rx_data[1]);
                    gm3508_2.rotor_angle -= gm3508_2.rotor_angle_first;
                    gm3508_2.rotor_speed = ((rx_data[2] << 8) | rx_data[3]);
                    gm3508_2.torque_current = ((rx_data[4] << 8) | rx_data[5]);
                }


                break;
            }
        }
    }
}

/*
 * @brief UART�������ݻص�����
 *
 * @param huart UART���
 * @return None
 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart == &huart5)
    {
        RxLine++; //每接收到�?个数据，进入回调数据长度�?1
        DataBuff[RxLine - 1] = RxBuffer[0]; //把每次接收到的数据保存到缓存数组
        if (RxBuffer[0] == '!') //接收结束标志�?
        {
            printf("RXLen=%d\r\n", RxLine);
            for (int i = 0; i < RxLine; i++)
                printf("UART DataBuff[%d] = %c\r\n", i, DataBuff[i]);
            //            xEventGroupSetBitsFromISR(g_xEventGroup_Uart_Rx,(1<<0),NULL);


            xSemaphoreGiveFromISR(g_UART_RX_Semaphore, NULL); //ʹ���ź�������UART_Rx����
        }
        RxBuffer[0] = 0;
        HAL_UART_Receive_IT(&huart5, (uint8_t*)RxBuffer, 1); //每接收一个数据，就打�?�?次串口中断接�?
    }
}


/**
  * @brief ������ģʽ�µ� Period elapsed �ص�
  * @note �� TIM4 �жϷ���ʱ����
  * HAL_TIM_IRQHandler���� ����ֱ�ӵ��� HAL_IncTick���� �Ե���
  * ����Ӧ�ó���ʱ����ȫ�ֱ��� ��uwTick����
  * @param htim �� TIM ���
  * @retval ��
  */
uint8_t time1 = 0;
float angle_last_1 = 0, angle_now_1 = 0, angle_total_1 = 0;
float angle_last_2 = 0, angle_now_2 = 0, angle_total_2 = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    /* USER CODE BEGIN Callback 0 */

    /* USER CODE END Callback 0 */
    if (htim->Instance == TIM4)
    {
        HAL_IncTick();
    }
    /* USER CODE BEGIN Callback 1 */
    if (htim->Instance == TIM3)
    {
        time1++;
        angle_last_1 = angle_now_1;
        angle_last_2 = angle_now_2;

        angle_now_1 = transfer(gm3508_1.rotor_angle, 0, 8191, -pi / 19, pi / 19);
        angle_now_2 = transfer(gm3508_2.rotor_angle, 0, 8191, -pi / 19, pi / 19);
        if (angle_now_1 - angle_last_1 > (pi / 19))
        {
            angle_total_1 += (angle_now_1 - angle_last_1 - 2 * pi / 19);
        }
        else if (angle_now_1 - angle_last_1 < (-pi / 19))
        {
            angle_total_1 += (angle_now_1 - angle_last_1 + 2 * pi / 19);
        }
        else
        {
            angle_total_1 += (angle_now_1 - angle_last_1);
        }

        if (angle_now_2 - angle_last_2 > (pi / 19))
        {
            angle_total_2 += (angle_now_2 - angle_last_2 - 2 * pi / 19);
        }
        else if (angle_now_2 - angle_last_2 < (-pi / 19))
        {
            angle_total_2 += (angle_now_2 - angle_last_2 + 2 * pi / 19);
        }
        else
        {
            angle_total_2 += (angle_now_2 - angle_last_2);
        }

        if (time1 == 5)
        {
            time1 = 0;
            //            if((Target_Speed-Target_Speed_actual)>MIN_Spe_Increment){
            //               Target_Speed_actual+=MIN_Spe_Increment;
            //           } else if((Target_Speed-Target_Speed_actual)<-MIN_Spe_Increment){
            //               Target_Speed_actual-=MIN_Spe_Increment;
            //           }
            xSemaphoreGiveFromISR(g_SemaphoreHandle_For_Pid, NULL); //ʹ���ź�������PID����
        }
    }
    /* USER CODE END Callback 1 */
}
