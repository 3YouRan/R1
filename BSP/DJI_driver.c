//
// Created by 陈瑜 on 24-10-2.
//

#include "all.h"
DJI_motor gm3508_1;
DJI_motor gm3508_2;
/*
 * @brief GM6020_电压设置函数
 *
 * @param hcan CAN句柄
 * @param volt 电压值
 * @param motor_ID 电机ID
 *
 * @return None
 * */
void GM6020_Voltage_Set(CAN_HandleTypeDef *hcan, int16_t volt,uint8_t motor_ID){
    uint8_t tx_data[8];
    if (motor_ID == 1) {
        tx_data[0] = (volt>>8)&0xff;
        tx_data[1] = (volt)&0xff;
    }

    CAN_Transmit_DATA(hcan,0x201,tx_data,8);

}
/*
 * @brief GM3508_电流设置函数
 *
 * @param hcan CAN句柄
 * @param Current 电流值
 * @param id 控制器ID
 * @param motor_ID 电机ID
 *
 * @return None
 * */
void GM3508_Current_Set(CAN_HandleTypeDef *hcan, int16_t Current1,int16_t Current2,int16_t Current3,int16_t Current4,uint16_t id,uint8_t motor_ID){
    uint8_t tx_data[8];
    if (motor_ID&(1<<0)||motor_ID&(1<<4)) {
        tx_data[0] = (Current1>>8)&0xff;
        tx_data[1] = (Current1)&0xff;
    }
    if (motor_ID&(1<<1)||motor_ID&(1<<5)) {
        tx_data[2] = (Current2>>8)&0xff;
        tx_data[3] = (Current2)&0xff;
    }
    if (motor_ID&(1<<2)||motor_ID&(1<<6)) {
        tx_data[4] = (Current3>>8)&0xff;
        tx_data[5] = (Current3)&0xff;
    }
    if (motor_ID&(1<<3)||motor_ID&(1<<7)) {
        tx_data[6] = (Current4>>8)&0xff;
        tx_data[7] = (Current4)&0xff;
    }
    CAN_Transmit_DATA(hcan,id,tx_data,8);

}
/*
 * @brief GM2006电流设置函数
 *
 * @param hcan CAN句柄
 * @param Current1/2/3/4 对应电机的电流值
 * @param motor_ID 电机ID位,如0b0000 0001表示要向ID为1的电机发送电流设置数据
 *
 * @return None
 * */


void GM2006_Current_Set(CAN_HandleTypeDef *hcan, int16_t Current1,int16_t Current2,int16_t Current3,int16_t Current4,uint16_t id,uint8_t motor_ID){
    uint8_t tx_data[8];
    if (motor_ID&(1<<0)||motor_ID&(1<<4)) {
        tx_data[0] = (Current1>>8)&0xff;
        tx_data[1] = (Current1)&0xff;
    }
    if (motor_ID&(1<<1)||motor_ID&(1<<5)) {
        tx_data[2] = (Current2>>8)&0xff;
        tx_data[3] = (Current2)&0xff;
    }
    if (motor_ID&(1<<2)||motor_ID&(1<<6)) {
        tx_data[4] = (Current3>>8)&0xff;
        tx_data[5] = (Current3)&0xff;
    }
    if (motor_ID&(1<<3)||motor_ID&(1<<7)) {
        tx_data[6] = (Current4>>8)&0xff;
        tx_data[7] = (Current4)&0xff;
    }
    CAN_Transmit_DATA(hcan,id,tx_data,8);

}