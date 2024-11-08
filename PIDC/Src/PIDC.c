/*
 * File: PIDC.c
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

#include "PIDC.h"
#include "PIDC_private.h"

/* Block states (default storage) */
DW_PIDC PIDC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PIDC PIDC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PIDC PIDC_Y;

/* Real-time model */
static RT_MODEL_PIDC PIDC_M_;
RT_MODEL_PIDC *const PIDC_M = &PIDC_M_;

/* Model step function */
void PIDC_step(void)
{
  real_T Integrator;
  real_T denAccum;
  real_T denAccum_0;
  real_T rtb_IProdOut;
  real_T rtb_NProdOut;
  real_T rtb_SignPreIntegrator;
  real_T rtb_TSamp;
  real_T rtb_ZeroGain;
  real_T rtb_ZeroGain_h;
  real_T tmp;
  boolean_T rtb_NotEqual;
  rtb_SignPreIntegrator = PIDC_U.P_TAR - PIDC_U.P_FEED;
  PIDC_Y.S_TAR = rtb_SignPreIntegrator * PIDC_U.P_P;
  PIDC_Y.current = PIDC_U.P_N * 0.0025;
  rtb_IProdOut = 1.0 / (PIDC_Y.current + 1.0);
  denAccum = rtb_SignPreIntegrator * PIDC_U.P_D - (PIDC_Y.current - 1.0) *
    rtb_IProdOut * PIDC_DW.FilterDifferentiatorTF_states;
  rtb_IProdOut = (denAccum + -PIDC_DW.FilterDifferentiatorTF_states) *
    rtb_IProdOut * PIDC_U.P_N;
  PIDC_Y.current = (PIDC_Y.S_TAR + PIDC_DW.Integrator_DSTATE) + rtb_IProdOut;
  rtb_ZeroGain = 0.0 * PIDC_Y.current;
  if (PIDC_Y.current > 100.0) {
    PIDC_Y.current -= 100.0;
  } else if (PIDC_Y.current >= -100.0) {
    PIDC_Y.current = 0.0;
  } else {
    PIDC_Y.current -= -100.0;
  }

  rtb_NotEqual = (rtb_ZeroGain != PIDC_Y.current);
  if (PIDC_Y.current < 0.0) {
    PIDC_Y.current = -1.0;
  } else if (PIDC_Y.current > 0.0) {
    PIDC_Y.current = 1.0;
  } else if (PIDC_Y.current == 0.0) {
    PIDC_Y.current = 0.0;
  } else {
    PIDC_Y.current = (rtNaN);
  }

  rtb_SignPreIntegrator *= PIDC_U.P_I;
  if (rtIsNaN(PIDC_Y.current)) {
    rtb_ZeroGain_h = 0.0;
  } else {
    rtb_ZeroGain_h = fmod(PIDC_Y.current, 256.0);
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

  if (rtb_NotEqual && ((rtb_ZeroGain_h < 0.0 ? (int32_T)(int8_T)-(int8_T)
                        (uint8_T)-rtb_ZeroGain_h : (int32_T)(int8_T)(uint8_T)
                        rtb_ZeroGain_h) == (tmp < 0.0 ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp))) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = rtb_SignPreIntegrator;
  }

  Integrator = 0.0025 * rtb_ZeroGain + PIDC_DW.Integrator_DSTATE;
  PIDC_Y.S_TAR = (PIDC_Y.S_TAR + Integrator) + rtb_IProdOut;
  if (PIDC_Y.S_TAR > 100.0) {
    PIDC_Y.S_TAR = 100.0;
  } else {
    if (PIDC_Y.S_TAR < -100.0) {
      PIDC_Y.S_TAR = -100.0;
    }
  }

  rtb_TSamp = PIDC_U.FORW * PIDC_U.P_TAR * 200.0;
  rtb_IProdOut = (PIDC_Y.S_TAR - PIDC_U.S_FEED) + (rtb_TSamp - PIDC_DW.UD_DSTATE);
  PIDC_Y.current = rtb_IProdOut * PIDC_U.S_P;
  rtb_SignPreIntegrator = PIDC_U.SN * 0.0025;
  rtb_NProdOut = 1.0 / (rtb_SignPreIntegrator + 1.0);
  denAccum_0 = rtb_IProdOut * PIDC_U.S_D - (rtb_SignPreIntegrator - 1.0) *
    rtb_NProdOut * PIDC_DW.FilterDifferentiatorTF_states_o;
  rtb_NProdOut = (denAccum_0 + -PIDC_DW.FilterDifferentiatorTF_states_o) *
    rtb_NProdOut * PIDC_U.SN;
  rtb_SignPreIntegrator = (PIDC_Y.current + PIDC_DW.Integrator_DSTATE_p) +
    rtb_NProdOut;
  rtb_ZeroGain_h = 0.0 * rtb_SignPreIntegrator;
  if (rtb_SignPreIntegrator > 16000.0) {
    rtb_SignPreIntegrator -= 16000.0;
  } else if (rtb_SignPreIntegrator >= -16000.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= -16000.0;
  }

  rtb_NotEqual = (rtb_ZeroGain_h != rtb_SignPreIntegrator);
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  rtb_IProdOut *= PIDC_U.S_I;
  if (rtIsNaN(rtb_SignPreIntegrator)) {
    rtb_ZeroGain_h = 0.0;
  } else {
    rtb_ZeroGain_h = fmod(rtb_SignPreIntegrator, 256.0);
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

  if (rtb_NotEqual && ((rtb_ZeroGain_h < 0.0 ? (int32_T)(int8_T)-(int8_T)
                        (uint8_T)-rtb_ZeroGain_h : (int32_T)(int8_T)(uint8_T)
                        rtb_ZeroGain_h) == (tmp < 0.0 ? (int32_T)(int8_T)
        -(int8_T)(uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp))) {
    rtb_IProdOut = 0.0;
  }

  rtb_SignPreIntegrator = 0.0025 * rtb_IProdOut + PIDC_DW.Integrator_DSTATE_p;
  PIDC_Y.current = (PIDC_Y.current + rtb_SignPreIntegrator) + rtb_NProdOut;
  if (PIDC_Y.current > 16000.0) {
    PIDC_Y.current = 16000.0;
  } else {
    if (PIDC_Y.current < -16000.0) {
      PIDC_Y.current = -16000.0;
    }
  }

  PIDC_DW.FilterDifferentiatorTF_states = denAccum;
  PIDC_DW.Integrator_DSTATE = 0.0025 * rtb_ZeroGain + Integrator;
  PIDC_DW.UD_DSTATE = rtb_TSamp;
  PIDC_DW.FilterDifferentiatorTF_states_o = denAccum_0;
  PIDC_DW.Integrator_DSTATE_p = 0.0025 * rtb_IProdOut + rtb_SignPreIntegrator;
}

/* Model initialize function */
void PIDC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] PIDC.c
 */
