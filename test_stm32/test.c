/*
 * File: test.c
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

#include "test.h"
#include "test_private.h"

/* Block states (default storage) */
DW_test test_DW;

/* External inputs (root inport signals with default storage) */
ExtU_test test_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test test_Y;

/* Real-time model */
static RT_MODEL_test test_M_;
RT_MODEL_test *const test_M = &test_M_;

/* Model step function */
void test_step(void)
{
  real_T denAccum;
  real_T rtb_IProdOut;
  real_T rtb_NProdOut;
  real_T rtb_SignPreIntegrator;
  real_T rtb_TSamp;
  real_T rtb_ZeroGain;
  boolean_T rtb_NotEqual;
  rtb_TSamp = test_U.FORW * test_U.P_TAR * 200.0;
  rtb_IProdOut = (test_U.S_TAR - test_U.S_FEED) + (rtb_TSamp - test_DW.UD_DSTATE);
  test_Y.current = rtb_IProdOut * test_U.S_P;
  rtb_SignPreIntegrator = test_U.SN * 0.0025;
  rtb_NProdOut = 1.0 / (rtb_SignPreIntegrator + 1.0);
  denAccum = rtb_IProdOut * test_U.S_D - (rtb_SignPreIntegrator - 1.0) *
    rtb_NProdOut * test_DW.FilterDifferentiatorTF_states;
  rtb_NProdOut = (denAccum + -test_DW.FilterDifferentiatorTF_states) *
    rtb_NProdOut * test_U.SN;
  rtb_SignPreIntegrator = (test_Y.current + test_DW.Integrator_DSTATE) +
    rtb_NProdOut;
  rtb_ZeroGain = 0.0 * rtb_SignPreIntegrator;
  if (rtb_SignPreIntegrator > 20.0) {
    rtb_SignPreIntegrator -= 20.0;
  } else if (rtb_SignPreIntegrator >= -20.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator -= -20.0;
  }

  rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreIntegrator);
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = (rtNaN);
  }

  rtb_IProdOut *= test_U.S_I;
  if (rtIsNaN(rtb_SignPreIntegrator)) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = fmod(rtb_SignPreIntegrator, 256.0);
  }

  if (rtb_IProdOut < 0.0) {
    rtb_ZeroGain = -1.0;
  } else if (rtb_IProdOut > 0.0) {
    rtb_ZeroGain = 1.0;
  } else if (rtb_IProdOut == 0.0) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = (rtNaN);
  }

  if (rtIsNaN(rtb_ZeroGain)) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = fmod(rtb_ZeroGain, 256.0);
  }

  if (rtb_NotEqual && ((rtb_SignPreIntegrator < 0.0 ? (int32_T)(int8_T)-(int8_T)
                        (uint8_T)-rtb_SignPreIntegrator : (int32_T)(int8_T)
                        (uint8_T)rtb_SignPreIntegrator) == (rtb_ZeroGain < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_ZeroGain : (int32_T)(int8_T)
        (uint8_T)rtb_ZeroGain))) {
    rtb_IProdOut = 0.0;
  }

  rtb_SignPreIntegrator = 0.0025 * rtb_IProdOut + test_DW.Integrator_DSTATE;
  test_Y.current = (test_Y.current + rtb_SignPreIntegrator) + rtb_NProdOut;
  if (test_Y.current > 20.0) {
    test_Y.current = 20.0;
  } else {
    if (test_Y.current < -20.0) {
      test_Y.current = -20.0;
    }
  }

  test_DW.UD_DSTATE = rtb_TSamp;
  test_DW.FilterDifferentiatorTF_states = denAccum;
  test_DW.Integrator_DSTATE = 0.0025 * rtb_IProdOut + rtb_SignPreIntegrator;
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test.c
 */
