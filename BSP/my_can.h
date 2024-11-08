//
// Created by ��� on 24-6-5.
//

#ifndef CAN_DEMO01_MY_CAN_H
#define CAN_DEMO01_MY_CAN_H

#include "main.h"
//�˲������
#define CAN_FILTER(x) ((x)<<3)
//���ն���
#define CAN_FIFO_0 (0<<2)
#define CAN_FIFO_1 (1<<2)
//��׼֡����չ֡
#define CAN_STDID (0<<1)
#define CAN_EXTID (1<<1)

//����֡��ң��֡
#define CAN_DATA_TYPE (0<<0)
#define CAN_REMOTE_TYPE (1<<0)



void CAN_Init(CAN_HandleTypeDef *hcan);
uint8_t CAN_Transmit_DATA(CAN_HandleTypeDef *hcan, uint16_t id, uint8_t *data, uint8_t len);
void CAN_Filter_Mask_Config_32bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID, uint32_t Mask_ID);
void CAN_Filter_List_Config_32bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_1, uint32_t ID_2);
void CAN_Filter_Mask_Config_16bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_set, uint32_t Mask_ID_set);
void CAN_Filter_List_Config_16bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_1, uint32_t ID_2);

#endif //CAN_DEMO01_MY_CAN_H

