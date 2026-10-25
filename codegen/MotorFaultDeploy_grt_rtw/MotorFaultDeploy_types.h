/*
 * MotorFaultDeploy_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorFaultDeploy".
 *
 * Model version              : 1.1
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Sun Oct 25 14:59:34 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MotorFaultDeploy_types_h_
#define MotorFaultDeploy_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<Root>/MechDetector' */
#ifndef typedef_c_classreg_learning_coderutil_T
#define typedef_c_classreg_learning_coderutil_T

typedef int32_T c_classreg_learning_coderutil_T;

#endif                             /* typedef_c_classreg_learning_coderutil_T */

#ifndef classreg_learning_coderutils_Transform_constants
#define classreg_learning_coderutils_Transform_constants

/* enum classreg_learning_coderutils_Transform */
#define Logit                          (0)
#define Doublelogit                    (1)
#define Invlogit                       (2)
#define Ismax                          (3)
#define Sign                           (4)
#define Symmetric                      (5)
#define Symmetricismax                 (6)
#define Symmetriclogit                 (7)
#define Identity                       (8)
#define Softmax                        (9)
#endif                    /* classreg_learning_coderutils_Transform_constants */

/* Custom Type definition for MATLAB Function: '<Root>/BearingDetector' */
#ifndef struct_tag_DqVcferuk7CCJnkFJ3kY6
#define struct_tag_DqVcferuk7CCJnkFJ3kY6

struct tag_DqVcferuk7CCJnkFJ3kY6
{
  boolean_T IsCached[50];
  real_T LearnerWeights[50];
  int32_T ClassNamesLength[4];
  c_classreg_learning_coderutil_T ScoreTransform;
  real_T Prior[4];
  boolean_T ClassLogicalIndices[4];
  real_T Cost[16];
};

#endif                                 /* struct_tag_DqVcferuk7CCJnkFJ3kY6 */

#ifndef typedef_c_classreg_learning_classif_C_T
#define typedef_c_classreg_learning_classif_C_T

typedef struct tag_DqVcferuk7CCJnkFJ3kY6 c_classreg_learning_classif_C_T;

#endif                             /* typedef_c_classreg_learning_classif_C_T */

/* Custom Type definition for MATLAB Function: '<Root>/MechDetector' */
#ifndef struct_tag_p0nXxQvHHYLSaQGbf1xiEH
#define struct_tag_p0nXxQvHHYLSaQGbf1xiEH

struct tag_p0nXxQvHHYLSaQGbf1xiEH
{
  boolean_T IsCached[50];
  real_T LearnerWeights[50];
  int32_T ClassNamesLength[3];
  c_classreg_learning_coderutil_T ScoreTransform;
  real_T Prior[3];
  boolean_T ClassLogicalIndices[3];
  real_T Cost[9];
};

#endif                                 /* struct_tag_p0nXxQvHHYLSaQGbf1xiEH */

#ifndef typedef_c_classreg_learning_classif_o_T
#define typedef_c_classreg_learning_classif_o_T

typedef struct tag_p0nXxQvHHYLSaQGbf1xiEH c_classreg_learning_classif_o_T;

#endif                             /* typedef_c_classreg_learning_classif_o_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_MotorFaultDeploy_T RT_MODEL_MotorFaultDeploy_T;

#endif                                 /* MotorFaultDeploy_types_h_ */
