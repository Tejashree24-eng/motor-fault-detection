/*
 * MotorFaultDeploy.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorFaultDeploy".
 *
 * Model version              : 1.1
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Sun Oct 25 13:06:37 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MotorFaultDeploy_h_
#define MotorFaultDeploy_h_
#ifndef MotorFaultDeploy_COMMON_INCLUDES_
#define MotorFaultDeploy_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* MotorFaultDeploy_COMMON_INCLUDES_ */

#include "MotorFaultDeploy_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  creal_T X[2048];
  real_T x[2048];
  real_T b_x[2048];
  real_T x0[2048];
  real_T b_x0[2048];
  real_T xp[2048];
  real_T b_x0_tmp[2048];
  real_T xp_m[2048];
  real_T P[1025];
} B_MotorFaultDeploy_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  c_classreg_learning_classif_C_T mdl; /* '<Root>/Detector' */
  real_T buf[2048];                    /* '<Root>/Detector' */
  real_T idx;                          /* '<Root>/Detector' */
  real_T lastLabel;                    /* '<Root>/Detector' */
  real_T cnt;                          /* '<Root>/Detector' */
  boolean_T buf_not_empty;             /* '<Root>/Detector' */
} DW_MotorFaultDeploy_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T accel;                        /* '<Root>/accel' */
} ExtU_MotorFaultDeploy_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T faultClass;                   /* '<Root>/faultClass' */
  real_T alarm;                        /* '<Root>/alarm' */
} ExtY_MotorFaultDeploy_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorFaultDeploy_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorFaultDeploy_T MotorFaultDeploy_B;

/* Block states (default storage) */
extern DW_MotorFaultDeploy_T MotorFaultDeploy_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_MotorFaultDeploy_T MotorFaultDeploy_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorFaultDeploy_T MotorFaultDeploy_Y;

/* Model entry point functions */
extern void MotorFaultDeploy_initialize(void);
extern void MotorFaultDeploy_step(void);
extern void MotorFaultDeploy_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorFaultDeploy_T *const MotorFaultDeploy_M;

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
 * '<Root>' : 'MotorFaultDeploy'
 * '<S1>'   : 'MotorFaultDeploy/Detector'
 */
#endif                                 /* MotorFaultDeploy_h_ */
