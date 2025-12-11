/*
 * File: pid_model.h
 *
 * Code generated for Simulink model 'pid_model'.
 *
 * Model version                  : 26.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Dec 11 22:00:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pid_model_h_
#define RTW_HEADER_pid_model_h_
#ifndef pid_model_COMMON_INCLUDES_
#define pid_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pid_model_COMMON_INCLUDES_ */

#include "pid_model_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
  real_T Filter_DSTATE;                /* '<S28>/Filter' */
  int32_T clockTickCounter;            /* '<Root>/Setpoint (deg)' */
} D_Work_pid_model;

/* Real-time Model Data Structure */
struct tag_RTM_pid_model {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern D_Work_pid_model pid_model_DWork;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T In2;                     /* '<Root>/In2' */
extern real_T Out1;                    /* '<Root>/Saturation' */

/* Model entry point functions */
extern void pid_model_initialize(void);
extern void pid_model_step(void);
extern void pid_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pid_model *const pid_model_M;

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
 * '<Root>' : 'pid_model'
 * '<S1>'   : 'pid_model/Discrete PID  Controller'
 * '<S2>'   : 'pid_model/Discrete PID  Controller/Anti-windup'
 * '<S3>'   : 'pid_model/Discrete PID  Controller/D Gain'
 * '<S4>'   : 'pid_model/Discrete PID  Controller/Filter'
 * '<S5>'   : 'pid_model/Discrete PID  Controller/Filter ICs'
 * '<S6>'   : 'pid_model/Discrete PID  Controller/I Gain'
 * '<S7>'   : 'pid_model/Discrete PID  Controller/Ideal P Gain'
 * '<S8>'   : 'pid_model/Discrete PID  Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'pid_model/Discrete PID  Controller/Integrator'
 * '<S10>'  : 'pid_model/Discrete PID  Controller/Integrator ICs'
 * '<S11>'  : 'pid_model/Discrete PID  Controller/N Copy'
 * '<S12>'  : 'pid_model/Discrete PID  Controller/N Gain'
 * '<S13>'  : 'pid_model/Discrete PID  Controller/P Copy'
 * '<S14>'  : 'pid_model/Discrete PID  Controller/Parallel P Gain'
 * '<S15>'  : 'pid_model/Discrete PID  Controller/Reset Signal'
 * '<S16>'  : 'pid_model/Discrete PID  Controller/Saturation'
 * '<S17>'  : 'pid_model/Discrete PID  Controller/Saturation Fdbk'
 * '<S18>'  : 'pid_model/Discrete PID  Controller/Sum'
 * '<S19>'  : 'pid_model/Discrete PID  Controller/Sum Fdbk'
 * '<S20>'  : 'pid_model/Discrete PID  Controller/Tracking Mode'
 * '<S21>'  : 'pid_model/Discrete PID  Controller/Tracking Mode Sum'
 * '<S22>'  : 'pid_model/Discrete PID  Controller/Tsamp - Integral'
 * '<S23>'  : 'pid_model/Discrete PID  Controller/Tsamp - Ngain'
 * '<S24>'  : 'pid_model/Discrete PID  Controller/postSat Signal'
 * '<S25>'  : 'pid_model/Discrete PID  Controller/preSat Signal'
 * '<S26>'  : 'pid_model/Discrete PID  Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'pid_model/Discrete PID  Controller/D Gain/Internal Parameters'
 * '<S28>'  : 'pid_model/Discrete PID  Controller/Filter/Disc. Forward Euler Filter'
 * '<S29>'  : 'pid_model/Discrete PID  Controller/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'pid_model/Discrete PID  Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'pid_model/Discrete PID  Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'pid_model/Discrete PID  Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'pid_model/Discrete PID  Controller/Integrator/Discrete'
 * '<S34>'  : 'pid_model/Discrete PID  Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'pid_model/Discrete PID  Controller/N Copy/Disabled'
 * '<S36>'  : 'pid_model/Discrete PID  Controller/N Gain/Internal Parameters'
 * '<S37>'  : 'pid_model/Discrete PID  Controller/P Copy/Disabled'
 * '<S38>'  : 'pid_model/Discrete PID  Controller/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'pid_model/Discrete PID  Controller/Reset Signal/Disabled'
 * '<S40>'  : 'pid_model/Discrete PID  Controller/Saturation/Passthrough'
 * '<S41>'  : 'pid_model/Discrete PID  Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'pid_model/Discrete PID  Controller/Sum/Sum_PID'
 * '<S43>'  : 'pid_model/Discrete PID  Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'pid_model/Discrete PID  Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'pid_model/Discrete PID  Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'pid_model/Discrete PID  Controller/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'pid_model/Discrete PID  Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'pid_model/Discrete PID  Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'pid_model/Discrete PID  Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_pid_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
