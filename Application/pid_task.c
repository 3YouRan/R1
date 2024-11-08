//
// Created by 陈瑜 on 24-11-7.
//

#include "all.h"
#include "PIDC.h"
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


//前馈pid结合抗积分饱和算法

float angle;
void pidc_task(void)
{



    angle=(float)gm3508_1.rotor_angle/8191.0f*360.0f;//精确的计算角度值
    angle= angle/19.0f;
    angle=Angle_Consecutive(angle);//角度连续化


    param_1.FORW=0.;

    // param_1.P_P=2.8;
    param_1.P_P=71.186;
    param_1.P_I=1.09202;

    param_2.Pos_P=71.186;
    param_2.Pos_I=1.09202;
//    param_1.P_D=0.01;
//    param_1.P_N=180;


    param_1.S_P=180;
    param_1.S_I=0;
    param_1.S_D=0;
//    param_1.SN=0;

    param_2.Spe_P=180;
    param_2.Spe_I=0;
    param_2.Spe_D=0;
//    param_2.Spe_N=0;

    param_1.P_FEED=angle_total_1;//外环位置环控制系统的反馈量
    param_1.S_FEED=gm3508_1.rotor_speed/19.0;//内环速度环控制系统的反馈量

    param_2.Pos_feed=angle_total_2;//外环位置环控制系统的反馈量
    param_2.Spe_feed1=gm3508_2.rotor_speed/19.0;//内环速度环控制系统的反馈量

    PIDC_step();
    PIDC1_step();
//    printf("angle_total_1:%f\n",current_out_1);
    GM3508_Current_Set(&hcan1, (int)current_out_1, (int)current_out_2, 0, 0, 0x200, GM_ID(1) | GM_ID(2));


}
float angle_last;
int rotate_times=0;
float Angle_Consecutive(float angle_now)
{
    float angle_this;//结合angle_last=angle_this;
    angle_this = angle_now;//将电机通过can传来的原始数据先保存在
    if ((angle_this - angle_last) > 300)//角度连续化的同时进行的角度积累，需要仔细想一想就很清楚的意思
        rotate_times--;
    if ((angle_this - angle_last) < -300)
        rotate_times++;
    angle_now = angle_this + rotate_times * 360.0f;
    angle_last=angle_this;//结合angle_this = angle_now;进行编码器读取的原始值的保存

    return angle_now;
}
