//
// Created by ��� on 24-6-5.
//

#include "all.h"
//#include "all.h"



/*
 * @brief CAN��ʼ������
 * @param hcan CAN���
 *
 * @return None
 * */
void CAN_Init(CAN_HandleTypeDef *hcan){
    HAL_CAN_Start(hcan);//����CAN
    __HAL_CAN_ENABLE_IT(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);//ʹ�ܽ���FIFO0�ж�
    __HAL_CAN_ENABLE_IT(hcan, CAN_IT_RX_FIFO1_MSG_PENDING);//ʹ�ܽ���FIFO1�ж�
    HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
    HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
}
/*
 * @brief CAN�������ݺ���
 *
 * @param hcan CAN���
 * @param id ID ֡ID
 * @param *data ����ָ��
 * @param len ���ݳ���
 *
 * @return ���ͳɹ�����0������ʧ�ܷ���1
 * */
uint8_t CAN_Transmit_DATA(CAN_HandleTypeDef *hcan, uint16_t id, uint8_t *data, uint8_t len)
{
    CAN_TxHeaderTypeDef TX_Header;
    uint32_t used_mailbox=CAN_TX_MAILBOX0;

    //���ؼ�����
    assert_param(hcan!= NULL);

    TX_Header.StdId = id;//��׼֡ID
    TX_Header.ExtId = 0;//��չ֡ID����ʹ��
    TX_Header.IDE=CAN_ID_STD;//��׼֡����ʹ����չ֡
    TX_Header.RTR=CAN_RTR_DATA;//��׼֡����ʹ��
    TX_Header.DLC=len;//���ݳ���

    return (HAL_CAN_AddTxMessage(hcan, &TX_Header, data, &used_mailbox));
}


/*
 * @brief ����CAN���˲���(32λ����ģʽ)
 *
 * @param hcan CAN���
 * @param Object_Para �˲������|FIFOx|ID����|֡���� (ʹ������:CAN_FILTER(0)|CAN_FIFO_1|CAN_STDID|CAN_DATA_TYPE)
 * @param ID ���յ�֡ID(32bit)
 * @param Mask_ID ����ID(0x7FF,0x1FFFFFFF)
 *
 * @return None
 * */
void CAN_Filter_Mask_Config_32bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID, uint32_t Mask_ID){

    CAN_FilterTypeDef CAN_Filter_Init_Structure;

    //���ؼ�����
    assert_param(hcan!= NULL);
    if ((Object_Para & 0x02)){
        //��չ֡
        //��չ��ʽID�ĸ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = ID<<3>>16;//�ó�Ա����ֻ�и�16bit��������
        //��չ��ʽID�ĵ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ID<<3|((Object_Para&0x03)<<1);//�ó�Ա����ֻ�е�16bit��������
        //�����16bit
        CAN_Filter_Init_Structure.FilterIdHigh = Mask_ID<<3>>16;
        //�����16bit
        CAN_Filter_Init_Structure.FilterIdLow = Mask_ID<<3|((Object_Para&0x03)<<1);
    }
    //0000 0010 0000 0101  <<3  0001 0000 0010 1000
    else{
        //��׼֡
        //ID�ĸ�16bit
        CAN_Filter_Init_Structure.FilterIdHigh = ID<<5;
        //ID�ĵ�16bit
        CAN_Filter_Init_Structure.FilterIdLow = ((Object_Para&0x03)<<1);
        //�����16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = Mask_ID<<5;
        //�����16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ((Object_Para&0x03)<<1);
    }
    //�˲������,0~27,28���˲���,can1(0~13),can2(14~27)
    CAN_Filter_Init_Structure.FilterBank=Object_Para>>3;
    //�˲����󶨵�FIFOx,ֻ�ܰ�һ��
    CAN_Filter_Init_Structure.FilterFIFOAssignment=(Object_Para>>2)&0x01;
    //ʹ���˲���
    CAN_Filter_Init_Structure.FilterActivation = ENABLE;
    //�˲���ģʽ������ID����ģʽ
    CAN_Filter_Init_Structure.FilterMode = CAN_FILTERMODE_IDMASK;
    //32λ�˲���
    CAN_Filter_Init_Structure.FilterScale = CAN_FILTERSCALE_32BIT;
    //�ӻ�ģʽѡ��ʼ��Ԫ
    CAN_Filter_Init_Structure.SlaveStartFilterBank=14;

    HAL_CAN_ConfigFilter(hcan, &CAN_Filter_Init_Structure);
}

/*
 * @brief ����CAN���˲���(32λ�б�ģʽ)
 *
 * @param hcan CAN���
 * @param Object_Para �˲������|FIFOx|ID����|֡���� (ʹ������:CAN_FILTER(0)|CAN_FIFO_1|CAN_STDID|CAN_DATA_TYPE)
 * @param ID_1 ���յĵ�һ��֡ID(32bit)
 * @param ID_2 ���յĵڶ���֡ID(32bit)
 *
 * @return None
 * */
void CAN_Filter_List_Config_32bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_1, uint32_t ID_2){

    CAN_FilterTypeDef CAN_Filter_Init_Structure;

    //���ؼ�����
    assert_param(hcan!= NULL);
    if ((Object_Para & 0x01)){
        //��չ֡
        //�����ID�ĸ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = ID_1<<3>>16;
        //�����ID�ĵ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ID_1<<3|((Object_Para&0x03)<<1);
        //ID����ֵ��16bit
        CAN_Filter_Init_Structure.FilterIdHigh = ID_2<<3>>16;
        //ID����ֵ��16bit
        CAN_Filter_Init_Structure.FilterIdLow = ID_2<<3|((Object_Para&0x03)<<1);
    }
        //0000 0010 0000 0101  <<3  0001 0000 0010 1000
    else{
        //��׼֡
        //ID�ĸ�16bit
        CAN_Filter_Init_Structure.FilterIdHigh = ID_1<<5;
        //ID�ĵ�16bit
        CAN_Filter_Init_Structure.FilterIdLow = ((Object_Para&0x03)<<1);
        //�����16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = ID_2<<5;
        //�����16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ((Object_Para&0x03)<<1);
    }
    //�˲������,0~27,28���˲���,can1(0~13),can2(14~27)
    CAN_Filter_Init_Structure.FilterBank=Object_Para>>3;
    //�˲����󶨵�FIFOx,ֻ�ܰ�һ��
    CAN_Filter_Init_Structure.FilterFIFOAssignment=(Object_Para>>2)&0x01;
    //ʹ���˲���
    CAN_Filter_Init_Structure.FilterActivation = ENABLE;
    //�˲���ģʽ������ID����ģʽ
    CAN_Filter_Init_Structure.FilterMode = CAN_FILTERMODE_IDLIST;
    //32λ�˲���
    CAN_Filter_Init_Structure.FilterScale = CAN_FILTERSCALE_32BIT;
    //�ӻ�ģʽѡ��ʼ��Ԫ
    CAN_Filter_Init_Structure.SlaveStartFilterBank=14;

    HAL_CAN_ConfigFilter(hcan, &CAN_Filter_Init_Structure);
}
/*
 * @brief ����CAN���˲���(16λ����ģʽ)
 *
 * @param hcan CAN���
 * @param Object_Para �˲������|FIFOx|ID����|֡���� (ʹ������:CAN_FILTER(0)|CAN_FIFO_1|CAN_STDID|CAN_DATA_TYPE) ID����ֻ������CAN_STDID
 * @param ID ���յ�֡ID��(��16bitһ������16bitһ������:(0x205<<16)|(0x201))
 * @param Mask_ID_set ������(��16bitһ������16bitһ������:(0x7FF<<16)|(0x444))
 *
 * @return None
 * */
void CAN_Filter_Mask_Config_16bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_set, uint32_t Mask_ID_set){

    CAN_FilterTypeDef CAN_Filter_Init_Structure;

    //����CAN_STDID|CAN_DATA_TYPE��˳��
    unsigned int bit1 = (Object_Para >> 0) & 1;  // �Ͷ˵�1λ
    unsigned int bit2 = (Object_Para >> 1) & 1;  // �Ͷ˵�2λ

    // �������λ
    Object_Para &= ~((1 << 0) | (1 << 1));

    // ��������λ�������ǷŻ�ȥ
    Object_Para |= (bit1 << 1) | (bit2 << 0);

    //���ؼ�����
    assert_param(hcan!= NULL);
    assert_param(!(Object_Para & 0x02)!= 0);

    if ((Object_Para & 0x01)){
        //��չ֡
        //����ĸ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = ID_set>>16<<5|(Object_Para&0x03)<<3;
        //����ĵ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ID_set<<5|(Object_Para&0x03)<<3;
        //ID��16bit��
        CAN_Filter_Init_Structure.FilterIdHigh = Mask_ID_set>>16<<5|(Object_Para&0x03)<<3;
        //ID��16bit
        CAN_Filter_Init_Structure.FilterIdLow = Mask_ID_set<<5|((Object_Para&0x03)<<3);
    }
    //�˲������,0~27,28���˲���,can1(0~13),can2(14~27)
    CAN_Filter_Init_Structure.FilterBank=Object_Para>>3;
    //�˲����󶨵�FIFOx,ֻ�ܰ�һ��
    CAN_Filter_Init_Structure.FilterFIFOAssignment=(Object_Para>>2)&0x01;
    //ʹ���˲���
    CAN_Filter_Init_Structure.FilterActivation = ENABLE;
    //�˲���ģʽ������ID����ģʽ
    CAN_Filter_Init_Structure.FilterMode = CAN_FILTERMODE_IDMASK;
    //32λ�˲���
    CAN_Filter_Init_Structure.FilterScale = CAN_FILTERSCALE_16BIT;
    //�ӻ�ģʽѡ��ʼ��Ԫ
    CAN_Filter_Init_Structure.SlaveStartFilterBank=14;

    HAL_CAN_ConfigFilter(hcan, &CAN_Filter_Init_Structure);
}
/*
 * @brief ����CAN���˲���(16λ�б�ģʽ)
 *
 * @param hcan CAN���
 * @param Object_Para �˲������|FIFOx|ID����|֡���� (ʹ������:CAN_FILTER(0)|CAN_FIFO_1|CAN_STDID|CAN_DATA_TYPE) ID����ֻ������CAN_STDID
 * @param ID_set1 ���յĵ�һ��֡ID(��16bit��һ��,��16bit��һ������:(0x205<<16)|(0x201))
 * @param ID_set2 ���յĵڶ���֡ID(��16bit��һ��,��16bit��һ������:(0x205<<16)|(0x201))
 *
 * @return None
 * */
void CAN_Filter_List_Config_16bit(CAN_HandleTypeDef *hcan, uint8_t Object_Para, uint32_t ID_set1, uint32_t ID_set2){

    CAN_FilterTypeDef CAN_Filter_Init_Structure;

    //����CAN_STDID|CAN_DATA_TYPE��˳��
    unsigned int bit1 = (Object_Para >> 0) & 1;  // �Ͷ˵�1λ
    unsigned int bit2 = (Object_Para >> 1) & 1;  // �Ͷ˵�2λ

    // �������λ
    Object_Para &= ~((1 << 0) | (1 << 1));

    // ��������λ�������ǷŻ�ȥ
    Object_Para |= (bit1 << 1) | (bit2 << 0);

    //���ؼ�����
    assert_param(hcan!= NULL);
    assert_param(!(Object_Para & 0x02)!= 0);

    if (!(Object_Para & 0x02)){
        //����ĸ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdHigh = ID_set1>>16<<5|(Object_Para&0x03)<<3;
        //����ĵ�16bit
        CAN_Filter_Init_Structure.FilterMaskIdLow = ID_set1<<5|(Object_Para&0x03)<<3;
        //ID��16bit��
        CAN_Filter_Init_Structure.FilterIdHigh = ID_set2>>16<<5|(Object_Para&0x03)<<3;
        //ID��16bit
        CAN_Filter_Init_Structure.FilterIdLow = ID_set2<<5|((Object_Para&0x03)<<3);
    }
    //�˲������,0~27,28���˲���,can1(0~13),can2(14~27)
    CAN_Filter_Init_Structure.FilterBank=Object_Para>>3;
    //�˲����󶨵�FIFOx,ֻ�ܰ�һ��
    CAN_Filter_Init_Structure.FilterFIFOAssignment=(Object_Para>>2)&0x01;
    //ʹ���˲���
    CAN_Filter_Init_Structure.FilterActivation = ENABLE;
    //�˲���ģʽ������ID����ģʽ
    CAN_Filter_Init_Structure.FilterMode = CAN_FILTERMODE_IDLIST;
    //32λ�˲���
    CAN_Filter_Init_Structure.FilterScale = CAN_FILTERSCALE_16BIT;
    //�ӻ�ģʽѡ��ʼ��Ԫ
    CAN_Filter_Init_Structure.SlaveStartFilterBank=14;

    HAL_CAN_ConfigFilter(hcan, &CAN_Filter_Init_Structure);
}
