/*
 * File: pid_model.c
 *
 * Code generated for Simulink model 'pid_model'.
 *
 * Model version                  : 26.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Dec  8 22:34:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pid_model.h"
#include "rtwtypes.h"

/* Exported block signals */
real_T In2;                            /* '<Root>/In2' */
real_T Out1;                           /* '<Root>/Saturation' */
real_T Out2;                           /* '<Root>/Pulse Generator' */

/* Block states (default storage) */
D_Work_pid_model pid_model_DWork;

/* Real-time model */
static RT_MODEL_pid_model pid_model_M_;
RT_MODEL_pid_model *const pid_model_M = &pid_model_M_;

/* Model step function */
void pid_model_step(void)
{
  real_T rtb_Add;
  real_T rtb_FilterCoefficient;

  /* DiscretePulseGenerator: '<Root>/Setpoint (deg)' */
  rtb_Add = (pid_model_DWork.clockTickCounter < 400) &&
    (pid_model_DWork.clockTickCounter >= 0) ? 1000.0 : 0.0;
  if (pid_model_DWork.clockTickCounter >= 799) {
    pid_model_DWork.clockTickCounter = 0;
  } else {
    pid_model_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Setpoint (deg)' */

  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtb_Add -= In2;

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Gain: '<S27>/Derivative Gain'
   *  Sum: '<S28>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Add - pid_model_DWork.Filter_DSTATE) *
    100.0;

  /* Sum: '<S42>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Gain: '<S38>/Proportional Gain'
   */
  Out1 = (0.005 * rtb_Add + pid_model_DWork.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (Out1 > 10.0) {
    /* Sum: '<S42>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Out1 = 10.0;
  } else if (Out1 < -10.0) {
    /* Sum: '<S42>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    Out1 = -10.0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Out2 = ((pid_model_DWork.clockTickCounter_c < 200) &&
          (pid_model_DWork.clockTickCounter_c >= 0));

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (pid_model_DWork.clockTickCounter_c >= 399) {
    pid_model_DWork.clockTickCounter_c = 0;
  } else {
    pid_model_DWork.clockTickCounter_c++;
  }

  /* Update for DiscreteIntegrator: '<S33>/Integrator' incorporates:
   *  Gain: '<S30>/Integral Gain'
   */
  pid_model_DWork.Integrator_DSTATE += 0.0001 * rtb_Add * 0.005;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  pid_model_DWork.Filter_DSTATE += 0.005 * rtb_FilterCoefficient;
}

/* Model initialize function */
void pid_model_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void pid_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
