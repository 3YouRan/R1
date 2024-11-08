/*
 * File: PIDC.h
 *
 * Code generated for Simulink model :PIDC.
 *
 * Model version      : 2.1
 * Simulink Coder version    : 9.4 (R2020b) 29-Jul-2020
 * TLC version       : 9.4 (Aug 20 2020)
 * C/C++ source code generated on  : Fri Nov  8 21:29:07 2024
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

#ifndef RTW_HEADER_PIDC_h_
#define RTW_HEADER_PIDC_h_
#include <math.h>
#include "STM32_Config.h"
#include "PIDC_External_Functions.h"
#ifndef PIDC_COMMON_INCLUDES_
#define PIDC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PIDC_COMMON_INCLUDES_ */

#include "PIDC_types.h"
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
  real_T FilterDifferentiatorTF_states;/* '<S32>/Filter Differentiator TF' */
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T FilterDifferentiatorTF_states_o;/* '<S84>/Filter Differentiator TF' */
  real_T Integrator_DSTATE_p;          /* '<S91>/Integrator' */
} DW_PIDC;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T P_P;                          /* '<Root>/P_P' */
  real_T P_I;                          /* '<Root>/P_I' */
  real_T P_D;                          /* '<Root>/P_D' */
  real_T P_N;                          /* '<Root>/P_N' */
  real_T S_P;                          /* '<Root>/S_P' */
  real_T S_I;                          /* '<Root>/S_I' */
  real_T S_D;                          /* '<Root>/S_D' */
  real_T SN;                           /* '<Root>/S-N' */
  real_T P_TAR;                        /* '<Root>/P_TAR' */
  real_T P_FEED;                       /* '<Root>/P_FEED' */
  real_T S_FEED;                       /* '<Root>/S_FEED' */
  real_T FORW;                         /* '<Root>/FORW' */
} ExtU_PIDC;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T current;                      /* '<Root>/current' */
  real_T S_TAR;                        /* '<Root>/S_TAR' */
} ExtY_PIDC;

/* Real-time Model Data Structure */
struct tag_RTM_PIDC {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_PIDC PIDC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PIDC PIDC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PIDC PIDC_Y;

/* Model entry point functions */
extern void PIDC_initialize(void);
extern void PIDC_step(void);

/* Real-time Model object */
extern RT_MODEL_PIDC *const PIDC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Passthrough for tuning' : Eliminate redundant data type conversion
 * Block '<S84>/Passthrough for tuning' : Eliminate redundant data type conversion
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
 * '<Root>' : 'PIDC'
 * '<S1>'   : 'PIDC/Discrete Derivative'
 * '<S2>'   : 'PIDC/P_POS'
 * '<S3>'   : 'PIDC/S_PID'
 * '<S4>'   : 'PIDC/P_POS/Anti-windup'
 * '<S5>'   : 'PIDC/P_POS/D Gain'
 * '<S6>'   : 'PIDC/P_POS/Filter'
 * '<S7>'   : 'PIDC/P_POS/Filter ICs'
 * '<S8>'   : 'PIDC/P_POS/I Gain'
 * '<S9>'   : 'PIDC/P_POS/Ideal P Gain'
 * '<S10>'  : 'PIDC/P_POS/Ideal P Gain Fdbk'
 * '<S11>'  : 'PIDC/P_POS/Integrator'
 * '<S12>'  : 'PIDC/P_POS/Integrator ICs'
 * '<S13>'  : 'PIDC/P_POS/N Copy'
 * '<S14>'  : 'PIDC/P_POS/N Gain'
 * '<S15>'  : 'PIDC/P_POS/P Copy'
 * '<S16>'  : 'PIDC/P_POS/Parallel P Gain'
 * '<S17>'  : 'PIDC/P_POS/Reset Signal'
 * '<S18>'  : 'PIDC/P_POS/Saturation'
 * '<S19>'  : 'PIDC/P_POS/Saturation Fdbk'
 * '<S20>'  : 'PIDC/P_POS/Sum'
 * '<S21>'  : 'PIDC/P_POS/Sum Fdbk'
 * '<S22>'  : 'PIDC/P_POS/Tracking Mode'
 * '<S23>'  : 'PIDC/P_POS/Tracking Mode Sum'
 * '<S24>'  : 'PIDC/P_POS/Tsamp - Integral'
 * '<S25>'  : 'PIDC/P_POS/Tsamp - Ngain'
 * '<S26>'  : 'PIDC/P_POS/postSat Signal'
 * '<S27>'  : 'PIDC/P_POS/preSat Signal'
 * '<S28>'  : 'PIDC/P_POS/Anti-windup/Disc. Clamping Parallel'
 * '<S29>'  : 'PIDC/P_POS/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S30>'  : 'PIDC/P_POS/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S31>'  : 'PIDC/P_POS/D Gain/External Parameters'
 * '<S32>'  : 'PIDC/P_POS/Filter/Disc. Trapezoidal Filter'
 * '<S33>'  : 'PIDC/P_POS/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S34>'  : 'PIDC/P_POS/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S35>'  : 'PIDC/P_POS/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'PIDC/P_POS/I Gain/External Parameters'
 * '<S37>'  : 'PIDC/P_POS/Ideal P Gain/Passthrough'
 * '<S38>'  : 'PIDC/P_POS/Ideal P Gain Fdbk/Passthrough'
 * '<S39>'  : 'PIDC/P_POS/Integrator/Discrete'
 * '<S40>'  : 'PIDC/P_POS/Integrator ICs/Internal IC'
 * '<S41>'  : 'PIDC/P_POS/N Copy/External Parameters'
 * '<S42>'  : 'PIDC/P_POS/N Gain/External Parameters'
 * '<S43>'  : 'PIDC/P_POS/P Copy/Disabled'
 * '<S44>'  : 'PIDC/P_POS/Parallel P Gain/External Parameters'
 * '<S45>'  : 'PIDC/P_POS/Reset Signal/Disabled'
 * '<S46>'  : 'PIDC/P_POS/Saturation/Enabled'
 * '<S47>'  : 'PIDC/P_POS/Saturation Fdbk/Passthrough'
 * '<S48>'  : 'PIDC/P_POS/Sum/Sum_PID'
 * '<S49>'  : 'PIDC/P_POS/Sum Fdbk/Enabled'
 * '<S50>'  : 'PIDC/P_POS/Tracking Mode/Disabled'
 * '<S51>'  : 'PIDC/P_POS/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'PIDC/P_POS/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'PIDC/P_POS/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'PIDC/P_POS/postSat Signal/Feedback_Path'
 * '<S55>'  : 'PIDC/P_POS/preSat Signal/Feedback_Path'
 * '<S56>'  : 'PIDC/S_PID/Anti-windup'
 * '<S57>'  : 'PIDC/S_PID/D Gain'
 * '<S58>'  : 'PIDC/S_PID/Filter'
 * '<S59>'  : 'PIDC/S_PID/Filter ICs'
 * '<S60>'  : 'PIDC/S_PID/I Gain'
 * '<S61>'  : 'PIDC/S_PID/Ideal P Gain'
 * '<S62>'  : 'PIDC/S_PID/Ideal P Gain Fdbk'
 * '<S63>'  : 'PIDC/S_PID/Integrator'
 * '<S64>'  : 'PIDC/S_PID/Integrator ICs'
 * '<S65>'  : 'PIDC/S_PID/N Copy'
 * '<S66>'  : 'PIDC/S_PID/N Gain'
 * '<S67>'  : 'PIDC/S_PID/P Copy'
 * '<S68>'  : 'PIDC/S_PID/Parallel P Gain'
 * '<S69>'  : 'PIDC/S_PID/Reset Signal'
 * '<S70>'  : 'PIDC/S_PID/Saturation'
 * '<S71>'  : 'PIDC/S_PID/Saturation Fdbk'
 * '<S72>'  : 'PIDC/S_PID/Sum'
 * '<S73>'  : 'PIDC/S_PID/Sum Fdbk'
 * '<S74>'  : 'PIDC/S_PID/Tracking Mode'
 * '<S75>'  : 'PIDC/S_PID/Tracking Mode Sum'
 * '<S76>'  : 'PIDC/S_PID/Tsamp - Integral'
 * '<S77>'  : 'PIDC/S_PID/Tsamp - Ngain'
 * '<S78>'  : 'PIDC/S_PID/postSat Signal'
 * '<S79>'  : 'PIDC/S_PID/preSat Signal'
 * '<S80>'  : 'PIDC/S_PID/Anti-windup/Disc. Clamping Parallel'
 * '<S81>'  : 'PIDC/S_PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S82>'  : 'PIDC/S_PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S83>'  : 'PIDC/S_PID/D Gain/External Parameters'
 * '<S84>'  : 'PIDC/S_PID/Filter/Disc. Trapezoidal Filter'
 * '<S85>'  : 'PIDC/S_PID/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S86>'  : 'PIDC/S_PID/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S87>'  : 'PIDC/S_PID/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'PIDC/S_PID/I Gain/External Parameters'
 * '<S89>'  : 'PIDC/S_PID/Ideal P Gain/Passthrough'
 * '<S90>'  : 'PIDC/S_PID/Ideal P Gain Fdbk/Passthrough'
 * '<S91>'  : 'PIDC/S_PID/Integrator/Discrete'
 * '<S92>'  : 'PIDC/S_PID/Integrator ICs/Internal IC'
 * '<S93>'  : 'PIDC/S_PID/N Copy/External Parameters'
 * '<S94>'  : 'PIDC/S_PID/N Gain/External Parameters'
 * '<S95>'  : 'PIDC/S_PID/P Copy/Disabled'
 * '<S96>'  : 'PIDC/S_PID/Parallel P Gain/External Parameters'
 * '<S97>'  : 'PIDC/S_PID/Reset Signal/Disabled'
 * '<S98>'  : 'PIDC/S_PID/Saturation/Enabled'
 * '<S99>'  : 'PIDC/S_PID/Saturation Fdbk/Passthrough'
 * '<S100>' : 'PIDC/S_PID/Sum/Sum_PID'
 * '<S101>' : 'PIDC/S_PID/Sum Fdbk/Enabled'
 * '<S102>' : 'PIDC/S_PID/Tracking Mode/Disabled'
 * '<S103>' : 'PIDC/S_PID/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'PIDC/S_PID/Tsamp - Integral/Passthrough'
 * '<S105>' : 'PIDC/S_PID/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'PIDC/S_PID/postSat Signal/Feedback_Path'
 * '<S107>' : 'PIDC/S_PID/preSat Signal/Feedback_Path'
 */
#endif                                 /* RTW_HEADER_PIDC_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] PIDC.h
 */
