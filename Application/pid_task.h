//
// Created by 陈瑜 on 24-11-7.
//

#ifndef R1_PID_TASK_H
#define R1_PID_TASK_H


float Angle_Consecutive(float angle_now);
void pidc_task(void);

void pid_task(void *arg);
#endif //R1_PID_TASK_H
