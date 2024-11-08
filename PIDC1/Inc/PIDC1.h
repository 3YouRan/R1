/*
 * File: PIDC1.h
 *
 * Code generated for Simulink model :PIDC1.
 *
 * Model version      : 1.3
 * Simulink Coder version    : 9.4 (R2020b) 29-Jul-2020
 * TLC version       : 9.4 (Aug 20 2020)
 * C/C++ source code generated on  : Fri Nov  8 21:15:28 2024
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#ifndef RTW_HEADER_PIDC1_h_
#define RTW_HEADER_PIDC1_h_
#include <math.h>
#include "STM32_Config.h"
#include "PIDC1_External_Functions.h"
#ifndef PIDC1_COMMON_INCLUDES_
#define PIDC1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PIDC1_COMMON_INCLUDES_ */

#include "PIDC1_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T FilterDifferentiatorTF_states;/* '<S31>/Filter Differentiator TF' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T FilterDifferentiatorTF_states_b;/* '<S83>/Filter Differentiator TF' */
  real_T Integrator_DSTATE_f;          /* '<S90>/Integrator' */
} DW_PIDC1;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T target_Pos;                   /* '<Root>/target_Pos' */
  real_T Pos_P;                        /* '<Root>/Pos_P' */
  real_T Pos_I;                        /* '<Root>/Pos_I' */
  real_T Pos_D;                        /* '<Root>/Pos_D' */
  real_T Spe_P;                        /* '<Root>/Spe_P' */
  real_T Spe_I;                        /* '<Root>/Spe_I' */
  real_T Spe_D;                        /* '<Root>/Spe_D' */
  real_T Pos_N;                        /* '<Root>/Pos_N' */
  real_T Spe_N;                        /* '<Root>/Spe_N' */
  real_T Pos_feed;                     /* '<Root>/Pos_feed' */
  real_T Spe_feed1;                    /* '<Root>/Spe_feed1' */
} ExtU_PIDC1;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Spe_out1;                     /* '<Root>/Spe_out1' */
  real_T Target_Spe;                   /* '<Root>/Target_Spe' */
} ExtY_PIDC1;

/* Real-time Model Data Structure */
struct tag_RTM_PIDC1 {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_PIDC1 PIDC1_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PIDC1 PIDC1_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PIDC1 PIDC1_Y;

/* Model entry point functions */
extern void PIDC1_initialize(void);
extern void PIDC1_step(void);

/* Real-time Model object */
extern RT_MODEL_PIDC1 *const PIDC1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S31>/Passthrough for tuning' : Eliminate redundant data type conversion
 * Block '<S83>/Passthrough for tuning' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PIDC1'
 * '<S1>'   : 'PIDC1/PID_Pos'
 * '<S2>'   : 'PIDC1/PID_Spe'
 * '<S3>'   : 'PIDC1/PID_Pos/Anti-windup'
 * '<S4>'   : 'PIDC1/PID_Pos/D Gain'
 * '<S5>'   : 'PIDC1/PID_Pos/Filter'
 * '<S6>'   : 'PIDC1/PID_Pos/Filter ICs'
 * '<S7>'   : 'PIDC1/PID_Pos/I Gain'
 * '<S8>'   : 'PIDC1/PID_Pos/Ideal P Gain'
 * '<S9>'   : 'PIDC1/PID_Pos/Ideal P Gain Fdbk'
 * '<S10>'  : 'PIDC1/PID_Pos/Integrator'
 * '<S11>'  : 'PIDC1/PID_Pos/Integrator ICs'
 * '<S12>'  : 'PIDC1/PID_Pos/N Copy'
 * '<S13>'  : 'PIDC1/PID_Pos/N Gain'
 * '<S14>'  : 'PIDC1/PID_Pos/P Copy'
 * '<S15>'  : 'PIDC1/PID_Pos/Parallel P Gain'
 * '<S16>'  : 'PIDC1/PID_Pos/Reset Signal'
 * '<S17>'  : 'PIDC1/PID_Pos/Saturation'
 * '<S18>'  : 'PIDC1/PID_Pos/Saturation Fdbk'
 * '<S19>'  : 'PIDC1/PID_Pos/Sum'
 * '<S20>'  : 'PIDC1/PID_Pos/Sum Fdbk'
 * '<S21>'  : 'PIDC1/PID_Pos/Tracking Mode'
 * '<S22>'  : 'PIDC1/PID_Pos/Tracking Mode Sum'
 * '<S23>'  : 'PIDC1/PID_Pos/Tsamp - Integral'
 * '<S24>'  : 'PIDC1/PID_Pos/Tsamp - Ngain'
 * '<S25>'  : 'PIDC1/PID_Pos/postSat Signal'
 * '<S26>'  : 'PIDC1/PID_Pos/preSat Signal'
 * '<S27>'  : 'PIDC1/PID_Pos/Anti-windup/Disc. Clamping Parallel'
 * '<S28>'  : 'PIDC1/PID_Pos/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S29>'  : 'PIDC1/PID_Pos/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S30>'  : 'PIDC1/PID_Pos/D Gain/External Parameters'
 * '<S31>'  : 'PIDC1/PID_Pos/Filter/Disc. Trapezoidal Filter'
 * '<S32>'  : 'PIDC1/PID_Pos/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S33>'  : 'PIDC1/PID_Pos/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S34>'  : 'PIDC1/PID_Pos/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'PIDC1/PID_Pos/I Gain/External Parameters'
 * '<S36>'  : 'PIDC1/PID_Pos/Ideal P Gain/Passthrough'
 * '<S37>'  : 'PIDC1/PID_Pos/Ideal P Gain Fdbk/Passthrough'
 * '<S38>'  : 'PIDC1/PID_Pos/Integrator/Discrete'
 * '<S39>'  : 'PIDC1/PID_Pos/Integrator ICs/Internal IC'
 * '<S40>'  : 'PIDC1/PID_Pos/N Copy/External Parameters'
 * '<S41>'  : 'PIDC1/PID_Pos/N Gain/External Parameters'
 * '<S42>'  : 'PIDC1/PID_Pos/P Copy/Disabled'
 * '<S43>'  : 'PIDC1/PID_Pos/Parallel P Gain/External Parameters'
 * '<S44>'  : 'PIDC1/PID_Pos/Reset Signal/Disabled'
 * '<S45>'  : 'PIDC1/PID_Pos/Saturation/Enabled'
 * '<S46>'  : 'PIDC1/PID_Pos/Saturation Fdbk/Passthrough'
 * '<S47>'  : 'PIDC1/PID_Pos/Sum/Sum_PID'
 * '<S48>'  : 'PIDC1/PID_Pos/Sum Fdbk/Enabled'
 * '<S49>'  : 'PIDC1/PID_Pos/Tracking Mode/Disabled'
 * '<S50>'  : 'PIDC1/PID_Pos/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'PIDC1/PID_Pos/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'PIDC1/PID_Pos/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'PIDC1/PID_Pos/postSat Signal/Feedback_Path'
 * '<S54>'  : 'PIDC1/PID_Pos/preSat Signal/Feedback_Path'
 * '<S55>'  : 'PIDC1/PID_Spe/Anti-windup'
 * '<S56>'  : 'PIDC1/PID_Spe/D Gain'
 * '<S57>'  : 'PIDC1/PID_Spe/Filter'
 * '<S58>'  : 'PIDC1/PID_Spe/Filter ICs'
 * '<S59>'  : 'PIDC1/PID_Spe/I Gain'
 * '<S60>'  : 'PIDC1/PID_Spe/Ideal P Gain'
 * '<S61>'  : 'PIDC1/PID_Spe/Ideal P Gain Fdbk'
 * '<S62>'  : 'PIDC1/PID_Spe/Integrator'
 * '<S63>'  : 'PIDC1/PID_Spe/Integrator ICs'
 * '<S64>'  : 'PIDC1/PID_Spe/N Copy'
 * '<S65>'  : 'PIDC1/PID_Spe/N Gain'
 * '<S66>'  : 'PIDC1/PID_Spe/P Copy'
 * '<S67>'  : 'PIDC1/PID_Spe/Parallel P Gain'
 * '<S68>'  : 'PIDC1/PID_Spe/Reset Signal'
 * '<S69>'  : 'PIDC1/PID_Spe/Saturation'
 * '<S70>'  : 'PIDC1/PID_Spe/Saturation Fdbk'
 * '<S71>'  : 'PIDC1/PID_Spe/Sum'
 * '<S72>'  : 'PIDC1/PID_Spe/Sum Fdbk'
 * '<S73>'  : 'PIDC1/PID_Spe/Tracking Mode'
 * '<S74>'  : 'PIDC1/PID_Spe/Tracking Mode Sum'
 * '<S75>'  : 'PIDC1/PID_Spe/Tsamp - Integral'
 * '<S76>'  : 'PIDC1/PID_Spe/Tsamp - Ngain'
 * '<S77>'  : 'PIDC1/PID_Spe/postSat Signal'
 * '<S78>'  : 'PIDC1/PID_Spe/preSat Signal'
 * '<S79>'  : 'PIDC1/PID_Spe/Anti-windup/Disc. Clamping Parallel'
 * '<S80>'  : 'PIDC1/PID_Spe/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S81>'  : 'PIDC1/PID_Spe/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S82>'  : 'PIDC1/PID_Spe/D Gain/External Parameters'
 * '<S83>'  : 'PIDC1/PID_Spe/Filter/Disc. Trapezoidal Filter'
 * '<S84>'  : 'PIDC1/PID_Spe/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S85>'  : 'PIDC1/PID_Spe/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S86>'  : 'PIDC1/PID_Spe/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'PIDC1/PID_Spe/I Gain/External Parameters'
 * '<S88>'  : 'PIDC1/PID_Spe/Ideal P Gain/Passthrough'
 * '<S89>'  : 'PIDC1/PID_Spe/Ideal P Gain Fdbk/Passthrough'
 * '<S90>'  : 'PIDC1/PID_Spe/Integrator/Discrete'
 * '<S91>'  : 'PIDC1/PID_Spe/Integrator ICs/Internal IC'
 * '<S92>'  : 'PIDC1/PID_Spe/N Copy/External Parameters'
 * '<S93>'  : 'PIDC1/PID_Spe/N Gain/External Parameters'
 * '<S94>'  : 'PIDC1/PID_Spe/P Copy/Disabled'
 * '<S95>'  : 'PIDC1/PID_Spe/Parallel P Gain/External Parameters'
 * '<S96>'  : 'PIDC1/PID_Spe/Reset Signal/Disabled'
 * '<S97>'  : 'PIDC1/PID_Spe/Saturation/Enabled'
 * '<S98>'  : 'PIDC1/PID_Spe/Saturation Fdbk/Passthrough'
 * '<S99>'  : 'PIDC1/PID_Spe/Sum/Sum_PID'
 * '<S100>' : 'PIDC1/PID_Spe/Sum Fdbk/Enabled'
 * '<S101>' : 'PIDC1/PID_Spe/Tracking Mode/Disabled'
 * '<S102>' : 'PIDC1/PID_Spe/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'PIDC1/PID_Spe/Tsamp - Integral/Passthrough'
 * '<S104>' : 'PIDC1/PID_Spe/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'PIDC1/PID_Spe/postSat Signal/Feedback_Path'
 * '<S106>' : 'PIDC1/PID_Spe/preSat Signal/Feedback_Path'
 */
#endif                                 /* RTW_HEADER_PIDC1_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] PIDC1.h
 */
