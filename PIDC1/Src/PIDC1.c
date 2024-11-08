/*
 * File: PIDC1.c
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

#include "PIDC1.h"
#include "PIDC1_private.h"

/* Block states (default storage) */
DW_PIDC1 PIDC1_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PIDC1 PIDC1_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PIDC1 PIDC1_Y;

/* Real-time model */
static RT_MODEL_PIDC1 PIDC1_M_;
RT_MODEL_PIDC1 *const PIDC1_M = &PIDC1_M_;

/* Model step function */
void PIDC1_step(void)
{
  real_T Integrator;
  real_T denAccum;
  real_T denAccum_0;
  real_T rtb_IProdOut;
  real_T rtb_NProdOut;
  real_T rtb_SignPreIntegrator;
  real_T rtb_ZeroGain;
  real_T rtb_ZeroGain_p;
  real_T tmp;
  boolean_T rtb_NotEqual;
  rtb_SignPreIntegrator = PIDC1_U.target_Pos - PIDC1_U.Pos_feed;
  PIDC1_Y.Target_Spe = rtb_SignPreIntegrator * PIDC1_U.Pos_P;
  PIDC1_Y.Spe_out1 = PIDC1_U.Pos_N * 0.0025;
  rtb_IProdOut = 1.0 / (PIDC1_Y.Spe_out1 + 1.0);
  denAccum = rtb_SignPreIntegrator * PIDC1_U.Pos_D - (PIDC1_Y.Spe_out1 - 1.0) *
    rtb_IProdOut * PIDC1_DW.FilterDifferentiatorTF_states;
  rtb_IProdOut = (denAccum + -PIDC1_DW.FilterDifferentiatorTF_states) *
    rtb_IProdOut * PIDC1_U.Pos_N;
  PIDC1_Y.Spe_out1 = (PIDC1_Y.Target_Spe + PIDC1_DW.Integrator_DSTATE) +
    rtb_IProdOut;
  rtb_ZeroGain = 0.0 * PIDC1_Y.Spe_out1;
  if (PIDC1_Y.Spe_out1 > 100.0) {
    PIDC1_Y.Spe_out1 -= 100.0;
  } else if (PIDC1_Y.Spe_out1 >= -100.0) {
    PIDC1_Y.Spe_out1 = 0.0;
  } else {
    PIDC1_Y.Spe_out1 -= -100.0;
  }

  rtb_NotEqual = (rtb_ZeroGain != PIDC1_Y.Spe_out1);
  if (PIDC1_Y.Spe_out1 < 0.0) {
    PIDC1_Y.Spe_out1 = -1.0;
  } else if (PIDC1_Y.Spe_out1 > 0.0) {
    PIDC1_Y.Spe_out1 = 1.0;
  } else if (PIDC1_Y.Spe_out1 == 0.0) {
    PIDC1_Y.Spe_out1 = 0.0;
  } else {
    PIDC1_Y.Spe_out1 = (rtNaN);
  }

  rtb_SignPreIntegrator *= PIDC1_U.Pos_I;
  if (rtIsNaN(PIDC1_Y.Spe_out1)) {
    rtb_ZeroGain_p = 0.0;
  } else {
    rtb_ZeroGain_p = fmod(PIDC1_Y.Spe_out1, 256.0);
  }

  if (rtb_SignPreIntegrator < 0.0) {
    tmp = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    tmp = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  if (rtb_NotEqual && ((rtb_ZeroGain_p < 0.0 ? (int32_T)(int8_T)-(int8_T)
                        (uint8_T)-rtb_ZeroGain_p : (int32_T)(int8_T)(uint8_T)
                        rtb_ZeroGain_p) == (tmp < 0.0 ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp))) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = rtb_SignPreIntegrator;
  }

  Integrator = 0.0025 * rtb_ZeroGain + PIDC1_DW.Integrator_DSTATE;
  PIDC1_Y.Target_Spe = (PIDC1_Y.Target_Spe + Integrator) + rtb_IProdOut;
  if (PIDC1_Y.Target_Spe > 100.0) {
    PIDC1_Y.Target_Spe = 100.0;
  } else {
    if (PIDC1_Y.Target_Spe < -100.0) {
      PIDC1_Y.Target_Spe = -100.0;
    }
  }

  rtb_IProdOut = PIDC1_Y.Target_Spe - PIDC1_U.Spe_feed1;
  PIDC1_Y.Spe_out1 = rtb_IProdOut * PIDC1_U.Spe_P;
  rtb_SignPreIntegrator = PIDC1_U.Spe_N * 0.0025;
  rtb_NProdOut = 1.0 / (rtb_SignPreIntegrator + 1.0);
  denAccum_0 = rtb_IProdOut * PIDC1_U.Spe_D - (rtb_SignPreIntegrator - 1.0) *
    rtb_NProdOut * PIDC1_DW.FilterDifferentiatorTF_states_b;
  rtb_NProdOut = (denAccum_0 + -PIDC1_DW.FilterDifferentiatorTF_states_b) *
    rtb_NProdOut * PIDC1_U.Spe_N;
  rtb_SignPreIntegrator = (PIDC1_Y.Spe_out1 + PIDC1_DW.Integrator_DSTATE_f) +
    rtb_NProdOut;
  rtb_ZeroGain_p = 0.0 * rtb_SignPreIntegrator;
  if (rtb_SignPreIntegrator > 16000.0) {
    rtb_SignPreIntegrator -= 16000.0;
  } else if (rtb_SignPreIntegrator >= -16000.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= -16000.0;
  }

  rtb_NotEqual = (rtb_ZeroGain_p != rtb_SignPreIntegrator);
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  rtb_IProdOut *= PIDC1_U.Spe_I;
  if (rtIsNaN(rtb_SignPreIntegrator)) {
    rtb_ZeroGain_p = 0.0;
  } else {
    rtb_ZeroGain_p = fmod(rtb_SignPreIntegrator, 256.0);
  }

  if (rtb_IProdOut < 0.0) {
    tmp = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    tmp = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  if (rtb_NotEqual && ((rtb_ZeroGain_p < 0.0 ? (int32_T)(int8_T)-(int8_T)
                        (uint8_T)-rtb_ZeroGain_p : (int32_T)(int8_T)(uint8_T)
                        rtb_ZeroGain_p) == (tmp < 0.0 ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp))) {
    rtb_IProdOut = 0.0;
  }

  rtb_SignPreIntegrator = 0.0025 * rtb_IProdOut + PIDC1_DW.Integrator_DSTATE_f;
  PIDC1_Y.Spe_out1 = (PIDC1_Y.Spe_out1 + rtb_SignPreIntegrator) + rtb_NProdOut;
  if (PIDC1_Y.Spe_out1 > 16000.0) {
    PIDC1_Y.Spe_out1 = 16000.0;
  } else {
    if (PIDC1_Y.Spe_out1 < -16000.0) {
      PIDC1_Y.Spe_out1 = -16000.0;
    }
  }

  PIDC1_DW.FilterDifferentiatorTF_states = denAccum;
  PIDC1_DW.Integrator_DSTATE = 0.0025 * rtb_ZeroGain + Integrator;
  PIDC1_DW.FilterDifferentiatorTF_states_b = denAccum_0;
  PIDC1_DW.Integrator_DSTATE_f = 0.0025 * rtb_IProdOut + rtb_SignPreIntegrator;
}

/* Model initialize function */
void PIDC1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] PIDC1.c
 */
