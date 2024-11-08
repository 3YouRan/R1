/*
 * File: test.h
 *
 * Code generated for Simulink model :test.
 *
 * Model version      : 1.0
 * Simulink Coder version    : 9.4 (R2020b) 29-Jul-2020
 * TLC version       : 9.4 (Aug 20 2020)
 * C/C++ source code generated on  : Fri Nov  8 17:54:25 2024
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

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <math.h>
#include "STM32_Config.h"
#include "test_External_Functions.h"
#ifndef test_COMMON_INCLUDES_
#define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"
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
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T FilterDifferentiatorTF_states;/* '<S84>/Filter Differentiator TF' */
  real_T Integrator_DSTATE;            /* '<S91>/Integrator' */
} DW_test;

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
  real_T S_TAR;                        /* '<Root>/S_TAR' */
  real_T S_FEED;                       /* '<Root>/S_FEED' */
  real_T FORW;                         /* '<Root>/FORW' */
} ExtU_test;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T current;                      /* '<Root>/current' */
} ExtY_test;

/* Real-time Model Data Structure */
struct tag_RTM_test {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_test test_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_test test_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_test test_Y;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_step(void);

/* Real-time Model object */
extern RT_MODEL_test *const test_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/AND3' : Unused code path elimination
 * Block '<S28>/Constant1' : Unused code path elimination
 * Block '<S28>/DataTypeConv1' : Unused code path elimination
 * Block '<S28>/DataTypeConv2' : Unused code path elimination
 * Block '<S30>/DeadZone' : Unused code path elimination
 * Block '<S28>/Equal1' : Unused code path elimination
 * Block '<S28>/NotEqual' : Unused code path elimination
 * Block '<S28>/SignPreIntegrator' : Unused code path elimination
 * Block '<S28>/SignPreSat' : Unused code path elimination
 * Block '<S28>/Switch' : Unused code path elimination
 * Block '<S28>/ZeroGain' : Unused code path elimination
 * Block '<S31>/DProd Out' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/DenCoefOut' : Unused code path elimination
 * Block '<S32>/Divide' : Unused code path elimination
 * Block '<S32>/Filter Differentiator TF' : Unused code path elimination
 * Block '<S32>/Passthrough for tuning' : Unused code path elimination
 * Block '<S32>/Reciprocal' : Unused code path elimination
 * Block '<S32>/SumDen' : Unused code path elimination
 * Block '<S32>/SumNum' : Unused code path elimination
 * Block '<S34>/Tsamp' : Unused code path elimination
 * Block '<S36>/IProd Out' : Unused code path elimination
 * Block '<S39>/Integrator' : Unused code path elimination
 * Block '<S42>/NProd Out' : Unused code path elimination
 * Block '<S44>/PProd Out' : Unused code path elimination
 * Block '<S46>/Saturation' : Unused code path elimination
 * Block '<S48>/Sum' : Unused code path elimination
 * Block '<S49>/Sum Fdbk' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Discrete Derivative'
 * '<S2>'   : 'test/P_POS'
 * '<S3>'   : 'test/S_PID'
 * '<S4>'   : 'test/P_POS/Anti-windup'
 * '<S5>'   : 'test/P_POS/D Gain'
 * '<S6>'   : 'test/P_POS/Filter'
 * '<S7>'   : 'test/P_POS/Filter ICs'
 * '<S8>'   : 'test/P_POS/I Gain'
 * '<S9>'   : 'test/P_POS/Ideal P Gain'
 * '<S10>'  : 'test/P_POS/Ideal P Gain Fdbk'
 * '<S11>'  : 'test/P_POS/Integrator'
 * '<S12>'  : 'test/P_POS/Integrator ICs'
 * '<S13>'  : 'test/P_POS/N Copy'
 * '<S14>'  : 'test/P_POS/N Gain'
 * '<S15>'  : 'test/P_POS/P Copy'
 * '<S16>'  : 'test/P_POS/Parallel P Gain'
 * '<S17>'  : 'test/P_POS/Reset Signal'
 * '<S18>'  : 'test/P_POS/Saturation'
 * '<S19>'  : 'test/P_POS/Saturation Fdbk'
 * '<S20>'  : 'test/P_POS/Sum'
 * '<S21>'  : 'test/P_POS/Sum Fdbk'
 * '<S22>'  : 'test/P_POS/Tracking Mode'
 * '<S23>'  : 'test/P_POS/Tracking Mode Sum'
 * '<S24>'  : 'test/P_POS/Tsamp - Integral'
 * '<S25>'  : 'test/P_POS/Tsamp - Ngain'
 * '<S26>'  : 'test/P_POS/postSat Signal'
 * '<S27>'  : 'test/P_POS/preSat Signal'
 * '<S28>'  : 'test/P_POS/Anti-windup/Disc. Clamping Parallel'
 * '<S29>'  : 'test/P_POS/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S30>'  : 'test/P_POS/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S31>'  : 'test/P_POS/D Gain/External Parameters'
 * '<S32>'  : 'test/P_POS/Filter/Disc. Trapezoidal Filter'
 * '<S33>'  : 'test/P_POS/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S34>'  : 'test/P_POS/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S35>'  : 'test/P_POS/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'test/P_POS/I Gain/External Parameters'
 * '<S37>'  : 'test/P_POS/Ideal P Gain/Passthrough'
 * '<S38>'  : 'test/P_POS/Ideal P Gain Fdbk/Passthrough'
 * '<S39>'  : 'test/P_POS/Integrator/Discrete'
 * '<S40>'  : 'test/P_POS/Integrator ICs/Internal IC'
 * '<S41>'  : 'test/P_POS/N Copy/External Parameters'
 * '<S42>'  : 'test/P_POS/N Gain/External Parameters'
 * '<S43>'  : 'test/P_POS/P Copy/Disabled'
 * '<S44>'  : 'test/P_POS/Parallel P Gain/External Parameters'
 * '<S45>'  : 'test/P_POS/Reset Signal/Disabled'
 * '<S46>'  : 'test/P_POS/Saturation/Enabled'
 * '<S47>'  : 'test/P_POS/Saturation Fdbk/Passthrough'
 * '<S48>'  : 'test/P_POS/Sum/Sum_PID'
 * '<S49>'  : 'test/P_POS/Sum Fdbk/Enabled'
 * '<S50>'  : 'test/P_POS/Tracking Mode/Disabled'
 * '<S51>'  : 'test/P_POS/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'test/P_POS/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'test/P_POS/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'test/P_POS/postSat Signal/Feedback_Path'
 * '<S55>'  : 'test/P_POS/preSat Signal/Feedback_Path'
 * '<S56>'  : 'test/S_PID/Anti-windup'
 * '<S57>'  : 'test/S_PID/D Gain'
 * '<S58>'  : 'test/S_PID/Filter'
 * '<S59>'  : 'test/S_PID/Filter ICs'
 * '<S60>'  : 'test/S_PID/I Gain'
 * '<S61>'  : 'test/S_PID/Ideal P Gain'
 * '<S62>'  : 'test/S_PID/Ideal P Gain Fdbk'
 * '<S63>'  : 'test/S_PID/Integrator'
 * '<S64>'  : 'test/S_PID/Integrator ICs'
 * '<S65>'  : 'test/S_PID/N Copy'
 * '<S66>'  : 'test/S_PID/N Gain'
 * '<S67>'  : 'test/S_PID/P Copy'
 * '<S68>'  : 'test/S_PID/Parallel P Gain'
 * '<S69>'  : 'test/S_PID/Reset Signal'
 * '<S70>'  : 'test/S_PID/Saturation'
 * '<S71>'  : 'test/S_PID/Saturation Fdbk'
 * '<S72>'  : 'test/S_PID/Sum'
 * '<S73>'  : 'test/S_PID/Sum Fdbk'
 * '<S74>'  : 'test/S_PID/Tracking Mode'
 * '<S75>'  : 'test/S_PID/Tracking Mode Sum'
 * '<S76>'  : 'test/S_PID/Tsamp - Integral'
 * '<S77>'  : 'test/S_PID/Tsamp - Ngain'
 * '<S78>'  : 'test/S_PID/postSat Signal'
 * '<S79>'  : 'test/S_PID/preSat Signal'
 * '<S80>'  : 'test/S_PID/Anti-windup/Disc. Clamping Parallel'
 * '<S81>'  : 'test/S_PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S82>'  : 'test/S_PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S83>'  : 'test/S_PID/D Gain/External Parameters'
 * '<S84>'  : 'test/S_PID/Filter/Disc. Trapezoidal Filter'
 * '<S85>'  : 'test/S_PID/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S86>'  : 'test/S_PID/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S87>'  : 'test/S_PID/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'test/S_PID/I Gain/External Parameters'
 * '<S89>'  : 'test/S_PID/Ideal P Gain/Passthrough'
 * '<S90>'  : 'test/S_PID/Ideal P Gain Fdbk/Passthrough'
 * '<S91>'  : 'test/S_PID/Integrator/Discrete'
 * '<S92>'  : 'test/S_PID/Integrator ICs/Internal IC'
 * '<S93>'  : 'test/S_PID/N Copy/External Parameters'
 * '<S94>'  : 'test/S_PID/N Gain/External Parameters'
 * '<S95>'  : 'test/S_PID/P Copy/Disabled'
 * '<S96>'  : 'test/S_PID/Parallel P Gain/External Parameters'
 * '<S97>'  : 'test/S_PID/Reset Signal/Disabled'
 * '<S98>'  : 'test/S_PID/Saturation/Enabled'
 * '<S99>'  : 'test/S_PID/Saturation Fdbk/Passthrough'
 * '<S100>' : 'test/S_PID/Sum/Sum_PID'
 * '<S101>' : 'test/S_PID/Sum Fdbk/Enabled'
 * '<S102>' : 'test/S_PID/Tracking Mode/Disabled'
 * '<S103>' : 'test/S_PID/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'test/S_PID/Tsamp - Integral/Passthrough'
 * '<S105>' : 'test/S_PID/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'test/S_PID/postSat Signal/Feedback_Path'
 * '<S107>' : 'test/S_PID/preSat Signal/Feedback_Path'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test.h
 */
