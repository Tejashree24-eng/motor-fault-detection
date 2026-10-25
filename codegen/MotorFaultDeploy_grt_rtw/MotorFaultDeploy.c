/*
 * MotorFaultDeploy.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorFaultDeploy".
 *
 * Model version              : 1.1
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Sun Oct 25 14:16:21 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorFaultDeploy.h"
#include "rtwtypes.h"
#include "MotorFaultDeploy_types.h"
#include <string.h>
#include <math.h>
#include "MotorFaultDeploy_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_MotorFaultDeploy_T MotorFaultDeploy_B;

/* Block states (default storage) */
DW_MotorFaultDeploy_T MotorFaultDeploy_DW;

/* External inputs (root inport signals with default storage) */
ExtU_MotorFaultDeploy_T MotorFaultDeploy_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MotorFaultDeploy_T MotorFaultDeploy_Y;

/* Real-time model */
static RT_MODEL_MotorFaultDeploy_T MotorFaultDeploy_M_;
RT_MODEL_MotorFaultDeploy_T *const MotorFaultDeploy_M = &MotorFaultDeploy_M_;

/* Forward declaration for local functions */
static void FFTImplementationCallback_doHal(const real_T x[2048], creal_T y[2048]);
static real_T MotorFaultDeploy_mean(const real_T x[2048]);
static real_T MotorFaultDeploy_maximum(const real_T x[2048]);
static void MotorFaultDeploy_minimum(const real_T x[4], real_T *ex, int32_T *idx);
static void CompactClassificationTree_predi(const real_T obj_CutPredictorIndex
  [49], const real_T obj_Children[98], const real_T obj_CutPoint[49], const
  boolean_T obj_NanCutPoints[49], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[196], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFaultDeploy_updateCache(const real_T learnerscore[4], real_T
  cachedScore[4], real_T *cachedWeights, boolean_T *cached, const char_T
  combinerName[15], real_T score[4]);
static void MotorFaultD_predictOneWithCache(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[49], const real_T weak_learner_Children[98],
  const real_T weak_learner_CutPoint[49], const boolean_T
  weak_learner_NanCutPoints[49], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[196], boolean_T *cached, boolean_T
  initCache, real_T score[4]);
static void CompactClassificationTree_pre_g(const real_T obj_CutPredictorIndex
  [31], const real_T obj_Children[62], const real_T obj_CutPoint[31], const
  boolean_T obj_NanCutPoints[31], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[124], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFaul_predictOneWithCache_o(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[31], const real_T weak_learner_Children[62],
  const real_T weak_learner_CutPoint[31], const boolean_T
  weak_learner_NanCutPoints[31], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[124], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_pr_gp(const real_T obj_CutPredictorIndex
  [29], const real_T obj_Children[58], const real_T obj_CutPoint[29], const
  boolean_T obj_NanCutPoints[29], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[116], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFau_predictOneWithCache_o2(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[29], const real_T weak_learner_Children[58],
  const real_T weak_learner_CutPoint[29], const boolean_T
  weak_learner_NanCutPoints[29], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[116], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_p_gps(const real_T obj_CutPredictorIndex
  [63], const real_T obj_Children[126], const real_T obj_CutPoint[63], const
  boolean_T obj_NanCutPoints[63], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[252], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFa_predictOneWithCache_o22(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[63], const real_T weak_learner_Children[126],
  const real_T weak_learner_CutPoint[63], const boolean_T
  weak_learner_NanCutPoints[63], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[252], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree__gpst(const real_T obj_CutPredictorIndex
  [33], const real_T obj_Children[66], const real_T obj_CutPoint[33], const
  boolean_T obj_NanCutPoints[33], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[132], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorF_predictOneWithCache_o22p(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[33], const real_T weak_learner_Children[66],
  const real_T weak_learner_CutPoint[33], const boolean_T
  weak_learner_NanCutPoints[33], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[132], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_gpst0(const real_T obj_CutPredictorIndex
  [47], const real_T obj_Children[94], const real_T obj_CutPoint[47], const
  boolean_T obj_NanCutPoints[47], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[188], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void Motor_predictOneWithCache_o22p4(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[47], const real_T weak_learner_Children[94],
  const real_T weak_learner_CutPoint[47], const boolean_T
  weak_learner_NanCutPoints[47], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[188], boolean_T *cached, real_T score[4]);
static void CompactClassificationTre_gpst0p(const real_T obj_CutPredictorIndex
  [41], const real_T obj_Children[82], const real_T obj_CutPoint[41], const
  boolean_T obj_NanCutPoints[41], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[164], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void Moto_predictOneWithCache_o22p4v(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[41], const real_T weak_learner_Children[82],
  const real_T weak_learner_CutPoint[41], const boolean_T
  weak_learner_NanCutPoints[41], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[164], boolean_T *cached, real_T score[4]);
static void CompactClassificationTr_gpst0p4(const real_T obj_CutPredictorIndex
  [37], const real_T obj_Children[74], const real_T obj_CutPoint[37], const
  boolean_T obj_NanCutPoints[37], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[148], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void Mot_predictOneWithCache_o22p4vs(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[37], const real_T weak_learner_Children[74],
  const real_T weak_learner_CutPoint[37], const boolean_T
  weak_learner_NanCutPoints[37], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[148], boolean_T *cached, real_T score[4]);
static void CompactClassificationT_gpst0p4p(const real_T obj_CutPredictorIndex
  [39], const real_T obj_Children[78], const real_T obj_CutPoint[39], const
  boolean_T obj_NanCutPoints[39], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[156], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void Mo_predictOneWithCache_o22p4vsu(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[39], const real_T weak_learner_Children[78],
  const real_T weak_learner_CutPoint[39], const boolean_T
  weak_learner_NanCutPoints[39], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[156], boolean_T *cached, real_T score[4]);
static void CompactClassification_gpst0p4p3(const real_T obj_CutPredictorIndex
  [53], const real_T obj_Children[106], const real_T obj_CutPoint[53], const
  boolean_T obj_NanCutPoints[53], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[212], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void M_predictOneWithCache_o22p4vsub(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[53], const real_T weak_learner_Children[106],
  const real_T weak_learner_CutPoint[53], const boolean_T
  weak_learner_NanCutPoints[53], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[212], boolean_T *cached, real_T score[4]);
static void CompactClassificatio_gpst0p4p3i(const real_T obj_CutPredictorIndex
  [59], const real_T obj_Children[118], const real_T obj_CutPoint[59], const
  boolean_T obj_NanCutPoints[59], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[236], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithCache_o22p4vsubw(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[59], const real_T weak_learner_Children[118],
  const real_T weak_learner_CutPoint[59], const boolean_T
  weak_learner_NanCutPoints[59], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[236], boolean_T *cached, real_T score[4]);
static void CompactClassificati_gpst0p4p3is(const real_T obj_CutPredictorIndex
  [45], const real_T obj_Children[90], const real_T obj_CutPoint[45], const
  boolean_T obj_NanCutPoints[45], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[180], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithCache_o22p4vsubwb(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[45], const real_T weak_learner_Children[90],
  const real_T weak_learner_CutPoint[45], const boolean_T
  weak_learner_NanCutPoints[45], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[180], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_Compa(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172]);
static void CompactClassificat_gpst0p4p3isq(const real_T obj_CutPredictorIndex
  [43], const real_T obj_Children[86], const real_T obj_CutPoint[43], const
  boolean_T obj_NanCutPoints[43], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[172], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithCach_o22p4vsubwbf(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[43], const real_T weak_learner_Children[86],
  const real_T weak_learner_CutPoint[43], const boolean_T
  weak_learner_NanCutPoints[43], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[172], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_Com_g(real_T obj_CutPredictorIndex[39],
  real_T obj_Children[78], real_T obj_CutPoint[39], boolean_T obj_NanCutPoints
  [39], boolean_T obj_InfCutPoints[39], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[156]);
static void CompactClassificationTree_Co_gk(real_T obj_CutPredictorIndex[53],
  real_T obj_Children[106], real_T obj_CutPoint[53], boolean_T obj_NanCutPoints
  [53], boolean_T obj_InfCutPoints[53], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[212]);
static void CompactClassificationTree_C_gkd(real_T obj_CutPredictorIndex[55],
  real_T obj_Children[110], real_T obj_CutPoint[55], boolean_T obj_NanCutPoints
  [55], boolean_T obj_InfCutPoints[55], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[220]);
static void CompactClassifica_gpst0p4p3isq4(const real_T obj_CutPredictorIndex
  [55], const real_T obj_Children[110], const real_T obj_CutPoint[55], const
  boolean_T obj_NanCutPoints[55], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[220], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithCac_o22p4vsubwbfs(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[55], const real_T weak_learner_Children[110],
  const real_T weak_learner_CutPoint[55], const boolean_T
  weak_learner_NanCutPoints[55], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[220], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree__gkd2(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196]);
static void CompactClassificationTree_gkd2u(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180]);
static void CompactClassificationTre_gkd2u4(real_T obj_CutPredictorIndex[47],
  real_T obj_Children[94], real_T obj_CutPoint[47], boolean_T obj_NanCutPoints
  [47], boolean_T obj_InfCutPoints[47], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[188]);
static void CompactClassificationTr_gkd2u4z(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[124]);
static void CompactClassificationT_gkd2u4zd(real_T obj_CutPredictorIndex[39],
  real_T obj_Children[78], real_T obj_CutPoint[39], boolean_T obj_NanCutPoints
  [39], boolean_T obj_InfCutPoints[39], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[156]);
static void CompactClassification_gkd2u4zdv(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassific_gpst0p4p3isq4m(const real_T obj_CutPredictorIndex
  [51], const real_T obj_Children[102], const real_T obj_CutPoint[51], const
  boolean_T obj_NanCutPoints[51], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[204], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithCa_o22p4vsubwbfsd(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[51], const real_T weak_learner_Children[102],
  const real_T weak_learner_CutPoint[51], const boolean_T
  weak_learner_NanCutPoints[51], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[204], boolean_T *cached, real_T score[4]);
static void CompactClassificatio_gkd2u4zdvp(real_T obj_CutPredictorIndex[53],
  real_T obj_Children[106], real_T obj_CutPoint[53], boolean_T obj_NanCutPoints
  [53], boolean_T obj_InfCutPoints[53], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[212]);
static void CompactClassificati_gkd2u4zdvpw(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassificat_gkd2u4zdvpwa(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180]);
static void CompactClassifica_gkd2u4zdvpwal(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassific_gkd2u4zdvpwala(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172]);
static void CompactClassifi_gkd2u4zdvpwalat(real_T obj_CutPredictorIndex[57],
  real_T obj_Children[114], real_T obj_CutPoint[57], boolean_T obj_NanCutPoints
  [57], boolean_T obj_InfCutPoints[57], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[228]);
static void CompactClassifi_gpst0p4p3isq4md(const real_T obj_CutPredictorIndex
  [57], const real_T obj_Children[114], const real_T obj_CutPoint[57], const
  boolean_T obj_NanCutPoints[57], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[228], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void predictOneWithC_o22p4vsubwbfsdz(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[57], const real_T weak_learner_Children[114],
  const real_T weak_learner_CutPoint[57], const boolean_T
  weak_learner_NanCutPoints[57], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[228], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_Com_k(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196]);
static void CompactClassificationTree_Com_o(real_T obj_CutPredictorIndex[47],
  real_T obj_Children[94], real_T obj_CutPoint[47], boolean_T obj_NanCutPoints
  [47], boolean_T obj_InfCutPoints[47], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[188]);
static void CompactClassificationTree_Com_e(real_T obj_CutPredictorIndex[37],
  real_T obj_Children[74], real_T obj_CutPoint[37], boolean_T obj_NanCutPoints
  [37], boolean_T obj_InfCutPoints[37], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[148]);
static void CompactClassificationTree_Co_ej(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180]);
static void CompactClassificationTree_Com_j(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassificationTree_Co_ea(real_T obj_CutPredictorIndex[41],
  real_T obj_Children[82], real_T obj_CutPoint[41], boolean_T obj_NanCutPoints
  [41], boolean_T obj_InfCutPoints[41], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[164]);
static void CompactClassificationTree_Com_a(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassificationTree_Com_c(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassificationTree_Co_gt(real_T obj_CutPredictorIndex[35],
  real_T obj_Children[70], real_T obj_CutPoint[35], boolean_T obj_NanCutPoints
  [35], boolean_T obj_InfCutPoints[35], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[140]);
static void CompactClassificationTree_pre_a(const real_T obj_CutPredictorIndex
  [35], const real_T obj_Children[70], const real_T obj_CutPoint[35], const
  boolean_T obj_NanCutPoints[35], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[140], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFaul_predictOneWithCache_e(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[35], const real_T weak_learner_Children[70],
  const real_T weak_learner_CutPoint[35], const boolean_T
  weak_learner_NanCutPoints[35], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[140], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_Com_i(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172]);
static void CompactClassificationTree_Com_h(real_T obj_CutPredictorIndex[41],
  real_T obj_Children[82], real_T obj_CutPoint[41], boolean_T obj_NanCutPoints
  [41], boolean_T obj_InfCutPoints[41], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[164]);
static void CompactClassificationTree_Com_n(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204]);
static void CompactClassificationTree_Co_kq(real_T obj_CutPredictorIndex[57],
  real_T obj_Children[114], real_T obj_CutPoint[57], boolean_T obj_NanCutPoints
  [57], boolean_T obj_InfCutPoints[57], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[228]);
static void CompactClassificationTree_Co_o2(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196]);
static void CompactClassificationTree_Com_b(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172]);
static void CompactClassificationTree_Co_cr(real_T obj_CutPredictorIndex[67],
  real_T obj_Children[134], real_T obj_CutPoint[67], boolean_T obj_NanCutPoints
  [67], boolean_T obj_InfCutPoints[67], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[268]);
static void CompactClassificationTree_pre_b(const real_T obj_CutPredictorIndex
  [67], const real_T obj_Children[134], const real_T obj_CutPoint[67], const
  boolean_T obj_NanCutPoints[67], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[268], const real_T Xin[10], real_T *labels, real_T
  scores[4]);
static void MotorFaul_predictOneWithCache_i(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[67], const real_T weak_learner_Children[134],
  const real_T weak_learner_CutPoint[67], const boolean_T
  weak_learner_NanCutPoints[67], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[268], boolean_T *cached, real_T score[4]);
static void CompactClassificationTree_Co_he(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172]);
static void CompactClassificationTree_Co_ci(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196]);
static void CompactEnsemble_ensemblePredict(const boolean_T obj_IsCached[50],
  const real_T X[10], real_T score[4]);
static real_T MotorFaultDeploy_mean_o(const real_T x[2400]);
static real_T MotorFaul_combineVectorElements(const real_T x[2400]);
static real_T MotorFaultDeploy_std(const real_T x[2400]);
static real_T MotorFaultDeploy_maximum_p(const real_T x[2400]);
static void MotorFaultDeploy_minimum_j(const real_T x[3], real_T *ex, int32_T
  *idx);
static void CompactClassificationTree_pre_n(const real_T obj_CutPredictorIndex
  [35], const real_T obj_Children[70], const real_T obj_CutPoint[35], const
  boolean_T obj_NanCutPoints[35], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[105], const real_T Xin[10], real_T *labels, real_T
  scores[3]);
static void MotorFaultDeploy_updateCache_k(const real_T learnerscore[3], real_T
  cachedScore[3], real_T *cachedWeights, boolean_T *cached, const char_T
  combinerName[15], real_T score[3]);
static void MotorFaul_predictOneWithCache_j(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[35], const real_T weak_learner_Children[70],
  const real_T weak_learner_CutPoint[35], const boolean_T
  weak_learner_NanCutPoints[35], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[105], boolean_T *cached, boolean_T initCache,
  real_T score[3]);
static void CompactClassificationTree_pr_na(const real_T obj_CutPredictorIndex
  [33], const real_T obj_Children[66], const real_T obj_CutPoint[33], const
  boolean_T obj_NanCutPoints[33], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[99], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void MotorFau_predictOneWithCache_jp(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[33], const real_T weak_learner_Children[66],
  const real_T weak_learner_CutPoint[33], const boolean_T
  weak_learner_NanCutPoints[33], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[99], boolean_T *cached, real_T score[3]);
static void CompactClassificationTree_p_nap(const real_T obj_CutPredictorIndex
  [25], const real_T obj_Children[50], const real_T obj_CutPoint[25], const
  boolean_T obj_NanCutPoints[25], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[75], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void MotorFa_predictOneWithCache_jpy(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[25], const real_T weak_learner_Children[50],
  const real_T weak_learner_CutPoint[25], const boolean_T
  weak_learner_NanCutPoints[25], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[75], boolean_T *cached, real_T score[3]);
static void CompactClassificationTree__napl(const real_T obj_CutPredictorIndex
  [45], const real_T obj_Children[90], const real_T obj_CutPoint[45], const
  boolean_T obj_NanCutPoints[45], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[135], const real_T Xin[10], real_T *labels, real_T
  scores[3]);
static void MotorF_predictOneWithCache_jpyz(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[45], const real_T weak_learner_Children[90],
  const real_T weak_learner_CutPoint[45], const boolean_T
  weak_learner_NanCutPoints[45], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[135], boolean_T *cached, real_T score[3]);
static void CompactClassificationTree_naplr(const real_T obj_CutPredictorIndex
  [27], const real_T obj_Children[54], const real_T obj_CutPoint[27], const
  boolean_T obj_NanCutPoints[27], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[81], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void Motor_predictOneWithCache_jpyzw(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[27], const real_T weak_learner_Children[54],
  const real_T weak_learner_CutPoint[27], const boolean_T
  weak_learner_NanCutPoints[27], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[81], boolean_T *cached, real_T score[3]);
static void CompactClassificationTre_naplrq(const real_T obj_CutPredictorIndex
  [29], const real_T obj_Children[58], const real_T obj_CutPoint[29], const
  boolean_T obj_NanCutPoints[29], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[87], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void Moto_predictOneWithCache_jpyzwe(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[29], const real_T weak_learner_Children[58],
  const real_T weak_learner_CutPoint[29], const boolean_T
  weak_learner_NanCutPoints[29], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[87], boolean_T *cached, real_T score[3]);
static void CompactClassificationTr_naplrqt(const real_T obj_CutPredictorIndex
  [21], const real_T obj_Children[42], const real_T obj_CutPoint[21], const
  boolean_T obj_NanCutPoints[21], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[63], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void Mot_predictOneWithCache_jpyzwef(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[21], const real_T weak_learner_Children[42],
  const real_T weak_learner_CutPoint[21], const boolean_T
  weak_learner_NanCutPoints[21], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[63], boolean_T *cached, real_T score[3]);
static void CompactClassificationT_naplrqtl(const real_T obj_CutPredictorIndex
  [31], const real_T obj_Children[62], const real_T obj_CutPoint[31], const
  boolean_T obj_NanCutPoints[31], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[93], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void Mo_predictOneWithCache_jpyzwefn(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[31], const real_T weak_learner_Children[62],
  const real_T weak_learner_CutPoint[31], const boolean_T
  weak_learner_NanCutPoints[31], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[93], boolean_T *cached, real_T score[3]);
static void CompactClassification_naplrqtlh(const real_T obj_CutPredictorIndex
  [23], const real_T obj_Children[46], const real_T obj_CutPoint[23], const
  boolean_T obj_NanCutPoints[23], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[69], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void M_predictOneWithCache_jpyzwefnb(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[23], const real_T weak_learner_Children[46],
  const real_T weak_learner_CutPoint[23], const boolean_T
  weak_learner_NanCutPoints[23], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[69], boolean_T *cached, real_T score[3]);
static void CompactClassificationTree_Co_gn(real_T obj_CutPredictorIndex[33],
  real_T obj_Children[66], real_T obj_CutPoint[33], boolean_T obj_NanCutPoints
  [33], boolean_T obj_InfCutPoints[33], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[99]);
static void CompactClassificationTree_C_gne(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree__gnex(real_T obj_CutPredictorIndex[17],
  real_T obj_Children[34], real_T obj_CutPoint[17], boolean_T obj_NanCutPoints
  [17], boolean_T obj_InfCutPoints[17], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[51]);
static void CompactClassificatio_naplrqtlhi(const real_T obj_CutPredictorIndex
  [17], const real_T obj_Children[34], const real_T obj_CutPoint[17], const
  boolean_T obj_NanCutPoints[17], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[51], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void predictOneWithCache_jpyzwefnbj(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[17], const real_T weak_learner_Children[34],
  const real_T weak_learner_CutPoint[17], const boolean_T
  weak_learner_NanCutPoints[17], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[51], boolean_T *cached, real_T score[3]);
static void CompactClassificationTree_gnexe(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassificationTre_gnexe4(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassificationTr_gnexe4e(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57]);
static void CompactClassificati_naplrqtlhie(const real_T obj_CutPredictorIndex
  [19], const real_T obj_Children[38], const real_T obj_CutPoint[19], const
  boolean_T obj_NanCutPoints[19], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[57], const real_T Xin[10], real_T *labels, real_T scores
  [3]);
static void predictOneWithCache_jpyzwefnbjt(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[19], const real_T weak_learner_Children[38],
  const real_T weak_learner_CutPoint[19], const boolean_T
  weak_learner_NanCutPoints[19], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[57], boolean_T *cached, real_T score[3]);
static void CompactClassificationT_gnexe4eq(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassification_gnexe4eq5(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[153]);
static void CompactClassificat_naplrqtlhieu(const real_T obj_CutPredictorIndex
  [51], const real_T obj_Children[102], const real_T obj_CutPoint[51], const
  boolean_T obj_NanCutPoints[51], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[153], const real_T Xin[10], real_T *labels, real_T
  scores[3]);
static void predictOneWithCach_jpyzwefnbjt0(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[51], const real_T weak_learner_Children[102],
  const real_T weak_learner_CutPoint[51], const boolean_T
  weak_learner_NanCutPoints[51], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[153], boolean_T *cached, real_T score[3]);
static void CompactClassificatio_gnexe4eq5x(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificati_gnexe4eq5xh(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69]);
static void CompactClassificat_gnexe4eq5xht(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[135]);
static void CompactClassifica_gnexe4eq5xhts(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57]);
static void CompactClassific_gnexe4eq5xhtsj(real_T obj_CutPredictorIndex[29],
  real_T obj_Children[58], real_T obj_CutPoint[29], boolean_T obj_NanCutPoints
  [29], boolean_T obj_InfCutPoints[29], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[87]);
static void CompactClassifi_gnexe4eq5xhtsjp(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree_Com_l(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree_Co_jt(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69]);
static void CompactClassificationTree_Com_p(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81]);
static void CompactClassificationTree_Com_d(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassificationTree_Co_g0(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassificationTree_Co_bl(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree_Co_cj(real_T obj_CutPredictorIndex[33],
  real_T obj_Children[66], real_T obj_CutPoint[33], boolean_T obj_NanCutPoints
  [33], boolean_T obj_InfCutPoints[33], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[99]);
static void CompactClassificationTree_Co_lj(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69]);
static void CompactClassificationTree_Co_lk(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree_Co_n0(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75]);
static void CompactClassificationTree_Co_ha(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69]);
static void CompactClassificationTree_Co_cw(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63]);
static void CompactClassificationTree_Co_pp(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81]);
static void CompactClassificationTree_Co_de(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63]);
static void CompactClassificationTree_Co_gj(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63]);
static void CompactClassificationTree_Co_gv(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81]);
static void CompactClassificationTree_Co_pa(real_T obj_CutPredictorIndex[35],
  real_T obj_Children[70], real_T obj_CutPoint[35], boolean_T obj_NanCutPoints
  [35], boolean_T obj_InfCutPoints[35], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[105]);
static void CompactClassificationTree_Com_f(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81]);
static void CompactClassificationTree_Co_o4(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93]);
static void CompactClassificationTree_Co_ba(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57]);
static void CompactEnsemble_ensemblePredi_j(const boolean_T obj_IsCached[50],
  const real_T X[10], real_T score[3]);

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void FFTImplementationCallback_doHal(const real_T x[2048], creal_T y[2048])
{
  real_T costab[512];
  real_T sintab[512];
  real_T temp2_im;
  real_T temp2_re;
  real_T temp_im;
  real_T temp_re;
  real_T temp_re_tmp_0;
  real_T tmp;
  real_T y_im_tmp;
  real_T y_im_tmp_0;
  int32_T b_i;
  int32_T iDelta;
  int32_T iheight;
  int32_T ix;
  int32_T j;
  int32_T k;
  int16_T d;
  static const real_T b[1025] = { 1.0, 0.9999952938095762, 0.9999811752826011,
    0.9999576445519639, 0.9999247018391445, 0.9998823474542126,
    0.9998305817958234, 0.9997694053512153, 0.9996988186962042,
    0.9996188224951786, 0.9995294175010931, 0.9994306045554617,
    0.9993223845883495, 0.9992047586183639, 0.9990777277526454,
    0.9989412931868569, 0.9987954562051724, 0.9986402181802653,
    0.9984755805732948, 0.9983015449338929, 0.9981181129001492,
    0.997925286198596, 0.9977230666441916, 0.9975114561403035,
    0.9972904566786902, 0.997060070339483, 0.9968202992911657,
    0.9965711457905548, 0.996312612182778, 0.996044700901252, 0.9957674144676598,
    0.9954807554919269, 0.9951847266721969, 0.9948793307948056,
    0.9945645707342554, 0.9942404494531879, 0.9939069700023561,
    0.9935641355205953, 0.9932119492347945, 0.9928504144598651, 0.99247953459871,
    0.9920993131421918, 0.9917097536690995, 0.9913108598461154, 0.99090263542778,
    0.9904850842564571, 0.9900582102622971, 0.9896220174632009,
    0.989176509964781, 0.9887216919603238, 0.9882575677307495,
    0.9877841416445722, 0.9873014181578584, 0.9868094018141855,
    0.9863080972445987, 0.9857975091675675, 0.9852776423889412,
    0.9847485018019042, 0.984210092386929, 0.9836624192117303,
    0.9831054874312163, 0.9825393022874412, 0.9819638691095552,
    0.9813791933137546, 0.9807852804032304, 0.9801821359681174,
    0.9795697656854405, 0.9789481753190622, 0.9783173707196277,
    0.9776773578245099, 0.9770281426577544, 0.9763697313300211,
    0.9757021300385286, 0.9750253450669941, 0.9743393827855759,
    0.973644249650812, 0.9729399522055602, 0.9722264970789363,
    0.9715038909862518, 0.9707721407289504, 0.970031253194544,
    0.9692812353565485, 0.9685220942744173, 0.9677538370934755,
    0.9669764710448521, 0.9661900034454125, 0.9653944416976894,
    0.9645897932898128, 0.9637760657954398, 0.9629532668736839,
    0.9621214042690416, 0.9612804858113206, 0.9604305194155658,
    0.9595715130819845, 0.9587034748958716, 0.9578264130275329,
    0.9569403357322088, 0.9560452513499964, 0.9551411683057708,
    0.9542280951091057, 0.9533060403541939, 0.9523750127197659,
    0.9514350209690083, 0.9504860739494817, 0.9495281805930367,
    0.9485613499157303, 0.9475855910177411, 0.9466009130832835,
    0.9456073253805213, 0.9446048372614803, 0.9435934581619604,
    0.9425731976014469, 0.9415440651830208, 0.9405060705932683,
    0.9394592236021899, 0.9384035340631081, 0.937339011912575,
    0.9362656671702783, 0.9351835099389476, 0.9340925504042589,
    0.932992798834739, 0.9318842655816681, 0.9307669610789837,
    0.9296408958431812, 0.9285060804732156, 0.9273625256504011,
    0.9262102421383114, 0.9250492407826776, 0.9238795325112867,
    0.9227011283338786, 0.9215140393420419, 0.9203182767091106,
    0.9191138516900578, 0.9179007756213905, 0.9166790599210427,
    0.9154487160882678, 0.9142097557035307, 0.9129621904283982,
    0.9117060320054299, 0.9104412922580672, 0.9091679830905224,
    0.9078861164876663, 0.9065957045149153, 0.9052967593181188,
    0.9039892931234433, 0.9026733182372588, 0.901348847046022,
    0.9000158920161602, 0.8986744656939538, 0.8973245807054183,
    0.8959662497561852, 0.8945994856313827, 0.8932243011955153,
    0.8918407093923427, 0.8904487232447579, 0.8890483558546646,
    0.8876396204028539, 0.8862225301488806, 0.8847970984309378,
    0.8833633386657316, 0.881921264348355, 0.8804708890521608,
    0.8790122264286335, 0.8775452902072614, 0.8760700941954066,
    0.8745866522781761, 0.8730949784182901, 0.8715950866559511,
    0.8700869911087115, 0.8685707059713409, 0.8670462455156926,
    0.8655136240905691, 0.8639728561215867, 0.8624239561110405,
    0.8608669386377673, 0.8593018183570085, 0.8577286100002721,
    0.8561473283751945, 0.8545579883654005, 0.8529606049303636,
    0.8513551931052652, 0.8497417680008525, 0.8481203448032972,
    0.8464909387740521, 0.8448535652497071, 0.8432082396418454,
    0.8415549774368984, 0.8398937941959995, 0.8382247055548381,
    0.836547727223512, 0.83486287498638, 0.8331701647019132, 0.8314696123025452,
    0.829761233794523, 0.8280450452577558, 0.8263210628456635,
    0.8245893027850253, 0.8228497813758264, 0.8211025149911046,
    0.819347520076797, 0.8175848131515837, 0.8158144108067338,
    0.8140363297059484, 0.8122505865852039, 0.8104571982525948,
    0.808656181588175, 0.8068475535437993, 0.8050313311429637,
    0.8032075314806449, 0.8013761717231402, 0.799537269107905,
    0.7976908409433912, 0.7958369046088836, 0.7939754775543372,
    0.7921065773002124, 0.79023022143731, 0.7883464276266063, 0.7864552135990858,
    0.7845565971555752, 0.7826505961665757, 0.7807372285720945,
    0.778816512381476, 0.7768884656732324, 0.7749531065948739, 0.773010453362737,
    0.7710605242618138, 0.7691033376455797, 0.7671389119358204,
    0.765167265622459, 0.7631884172633813, 0.7612023854842618, 0.759209188978388,
    0.7572088465064846, 0.7552013768965365, 0.7531867990436125,
    0.7511651319096864, 0.7491363945234594, 0.7471006059801801,
    0.745057785441466, 0.7430079521351217, 0.7409511253549592,
    0.7388873244606151, 0.7368165688773698, 0.7347388780959635,
    0.7326542716724128, 0.7305627692278276, 0.7284643904482252,
    0.726359155084346, 0.724247082951467, 0.7221281939292153, 0.7200025079613817,
    0.7178700450557317, 0.7157308252838186, 0.7135848687807935,
    0.7114321957452164, 0.7092728264388657, 0.7071067811865476,
    0.7049340803759049, 0.7027547444572253, 0.7005687939432483,
    0.6983762494089729, 0.696177131491463, 0.6939714608896539,
    0.6917592583641577, 0.6895405447370668, 0.687315340891759,
    0.6850836677727004, 0.6828455463852481, 0.680600997795453,
    0.6783500431298615, 0.6760927035753159, 0.673829000378756,
    0.6715589548470183, 0.669282588346636, 0.6669999223036375,
    0.6647109782033448, 0.6624157775901718, 0.6601143420674205,
    0.6578066932970786, 0.6554928529996153, 0.6531728429537768,
    0.650846684996381, 0.6485144010221124, 0.6461760129833163,
    0.6438315428897914, 0.641481012808583, 0.6391244448637757,
    0.6367618612362842, 0.6343932841636455, 0.6320187359398091,
    0.629638238914927, 0.6272518154951441, 0.6248594881423863, 0.62246127937415,
    0.6200572117632891, 0.6176473079378039, 0.6152315905806268,
    0.6128100824294097, 0.6103828062763095, 0.6079497849677736,
    0.6055110414043255, 0.6030665985403482, 0.600616479383869,
    0.5981607069963424, 0.5956993044924334, 0.5932322950397998,
    0.5907597018588742, 0.5882815482226452, 0.5857978574564389,
    0.5833086529376983, 0.5808139580957645, 0.5783137964116556,
    0.5758081914178453, 0.5732971666980422, 0.5707807458869673,
    0.5682589526701315, 0.5657318107836131, 0.5631993440138341,
    0.560661576197336, 0.5581185312205561, 0.5555702330196022,
    0.5530167055800275, 0.5504579729366048, 0.5478940591731002,
    0.5453249884220465, 0.5427507848645159, 0.5401714727298929,
    0.5375870762956454, 0.5349976198870972, 0.5324031278771979,
    0.5298036246862946, 0.5271991347819013, 0.524589682678469,
    0.5219752929371544, 0.5193559901655896, 0.5167317990176499,
    0.5141027441932217, 0.5114688504379703, 0.508830142543107,
    0.5061866453451552, 0.5035383837257176, 0.5008853826112407,
    0.4982276669727818, 0.49556526182577254, 0.49289819222978404,
    0.49022648328829116, 0.487550160148436, 0.48486924800079106,
    0.4821837720791227, 0.47949375766015295, 0.4767992300633221,
    0.47410021465054997, 0.47139673682599764, 0.46868882203582796,
    0.4659764957679662, 0.46325978355186015, 0.46053871095824,
    0.4578133035988772, 0.45508358712634384, 0.4523495872337709,
    0.44961132965460654, 0.44686884016237416, 0.4441221445704292,
    0.44137126873171667, 0.43861623853852766, 0.4358570799222555,
    0.43309381885315196, 0.4303264813400826, 0.4275550934302821,
    0.4247796812091088, 0.4220002707997997, 0.4192168883632239,
    0.41642956009763715, 0.4136383122384345, 0.4108431710579039,
    0.4080441628649787, 0.40524131400498986, 0.40243465085941843,
    0.3996241998456468, 0.3968099874167103, 0.3939920400610481,
    0.39117038430225387, 0.38834504669882625, 0.38551605384391885,
    0.3826834323650898, 0.37984720892405116, 0.37700741021641826,
    0.37416406297145793, 0.3713171939518375, 0.3684668299533723,
    0.36561299780477385, 0.3627557243673972, 0.3598950365349881,
    0.35703096123343, 0.35416352542049034, 0.3512927560855671,
    0.34841868024943456, 0.3455413249639891, 0.3426607173119944,
    0.33977688440682685, 0.33688985339222005, 0.3339996514420094,
    0.33110630575987643, 0.3282098435790925, 0.3253102921622629,
    0.32240767880106985, 0.3195020308160157, 0.31659337555616585,
    0.3136817403988915, 0.3107671527496115, 0.30784964004153487,
    0.3049292297354024, 0.3020059493192281, 0.2990798263080405,
    0.2961508882436238, 0.29321916269425863, 0.29028467725446233,
    0.2873474595447295, 0.2844075372112719, 0.28146493792575794,
    0.27851968938505306, 0.27557181931095814, 0.272621355449949,
    0.2696683255729151, 0.26671275747489837, 0.26375467897483135,
    0.2607941179152755, 0.257831102162159, 0.25486565960451457,
    0.25189781815421697, 0.24892760574572015, 0.2459550503357946,
    0.24298017990326387, 0.2400030224487415, 0.2370236059943672,
    0.23404195858354343, 0.2310581082806711, 0.22807208317088573,
    0.22508391135979283, 0.2220936209732035, 0.2191012401568698,
    0.21610679707621952, 0.21311031991609136, 0.2101118368804696,
    0.20711137619221856, 0.20410896609281687, 0.2011046348420919,
    0.19809841071795356, 0.19509032201612825, 0.19208039704989244,
    0.1890686641498062, 0.18605515166344663, 0.18303988795514095,
    0.18002290140569951, 0.17700422041214875, 0.17398387338746382,
    0.17096188876030122, 0.16793829497473117, 0.16491312048996992,
    0.16188639378011183, 0.15885814333386145, 0.15582839765426523,
    0.15279718525844344, 0.1497645346773215, 0.14673047445536175,
    0.14369503315029447, 0.1406582393328492, 0.13762012158648604,
    0.13458070850712617, 0.13154002870288312, 0.12849811079379317,
    0.12545498341154623, 0.1224106751992162, 0.11936521481099135,
    0.11631863091190475, 0.11327095217756435, 0.11022220729388306,
    0.10717242495680884, 0.10412163387205459, 0.10106986275482782,
    0.0980171403295606, 0.09496349532963899, 0.09190895649713272,
    0.0888535525825246, 0.0857973123444399, 0.08274026454937569,
    0.07968243797143013, 0.07662386139203149, 0.07356456359966743,
    0.07050457338961386, 0.06744391956366405, 0.06438263092985747,
    0.06132073630220858, 0.05825826450043575, 0.05519524434968994,
    0.052131704680283324, 0.049067674327418015, 0.04600318213091462,
    0.04293825693494082, 0.03987292758773981, 0.03680722294135883,
    0.03374117185137758, 0.030674803176636626, 0.02760814577896574,
    0.024541228522912288, 0.021474080275469508, 0.01840672990580482,
    0.0153392062849881, 0.012271538285719925, 0.00920375478205982,
    0.006135884649154475, 0.003067956762965976, 0.0, -0.003067956762965976,
    -0.006135884649154475, -0.00920375478205982, -0.012271538285719925,
    -0.0153392062849881, -0.01840672990580482, -0.021474080275469508,
    -0.024541228522912288, -0.02760814577896574, -0.030674803176636626,
    -0.03374117185137758, -0.03680722294135883, -0.03987292758773981,
    -0.04293825693494082, -0.04600318213091462, -0.049067674327418015,
    -0.052131704680283324, -0.05519524434968994, -0.05825826450043575,
    -0.06132073630220858, -0.06438263092985747, -0.06744391956366405,
    -0.07050457338961386, -0.07356456359966743, -0.07662386139203149,
    -0.07968243797143013, -0.08274026454937569, -0.0857973123444399,
    -0.0888535525825246, -0.09190895649713272, -0.09496349532963899,
    -0.0980171403295606, -0.10106986275482782, -0.10412163387205459,
    -0.10717242495680884, -0.11022220729388306, -0.11327095217756435,
    -0.11631863091190475, -0.11936521481099135, -0.1224106751992162,
    -0.12545498341154623, -0.12849811079379317, -0.13154002870288312,
    -0.13458070850712617, -0.13762012158648604, -0.1406582393328492,
    -0.14369503315029447, -0.14673047445536175, -0.1497645346773215,
    -0.15279718525844344, -0.15582839765426523, -0.15885814333386145,
    -0.16188639378011183, -0.16491312048996992, -0.16793829497473117,
    -0.17096188876030122, -0.17398387338746382, -0.17700422041214875,
    -0.18002290140569951, -0.18303988795514095, -0.18605515166344663,
    -0.1890686641498062, -0.19208039704989244, -0.19509032201612825,
    -0.19809841071795356, -0.2011046348420919, -0.20410896609281687,
    -0.20711137619221856, -0.2101118368804696, -0.21311031991609136,
    -0.21610679707621952, -0.2191012401568698, -0.2220936209732035,
    -0.22508391135979283, -0.22807208317088573, -0.2310581082806711,
    -0.23404195858354343, -0.2370236059943672, -0.2400030224487415,
    -0.24298017990326387, -0.2459550503357946, -0.24892760574572015,
    -0.25189781815421697, -0.25486565960451457, -0.257831102162159,
    -0.2607941179152755, -0.26375467897483135, -0.26671275747489837,
    -0.2696683255729151, -0.272621355449949, -0.27557181931095814,
    -0.27851968938505306, -0.28146493792575794, -0.2844075372112719,
    -0.2873474595447295, -0.29028467725446233, -0.29321916269425863,
    -0.2961508882436238, -0.2990798263080405, -0.3020059493192281,
    -0.3049292297354024, -0.30784964004153487, -0.3107671527496115,
    -0.3136817403988915, -0.31659337555616585, -0.3195020308160157,
    -0.32240767880106985, -0.3253102921622629, -0.3282098435790925,
    -0.33110630575987643, -0.3339996514420094, -0.33688985339222005,
    -0.33977688440682685, -0.3426607173119944, -0.3455413249639891,
    -0.34841868024943456, -0.3512927560855671, -0.35416352542049034,
    -0.35703096123343, -0.3598950365349881, -0.3627557243673972,
    -0.36561299780477385, -0.3684668299533723, -0.3713171939518375,
    -0.37416406297145793, -0.37700741021641826, -0.37984720892405116,
    -0.3826834323650898, -0.38551605384391885, -0.38834504669882625,
    -0.39117038430225387, -0.3939920400610481, -0.3968099874167103,
    -0.3996241998456468, -0.40243465085941843, -0.40524131400498986,
    -0.4080441628649787, -0.4108431710579039, -0.4136383122384345,
    -0.41642956009763715, -0.4192168883632239, -0.4220002707997997,
    -0.4247796812091088, -0.4275550934302821, -0.4303264813400826,
    -0.43309381885315196, -0.4358570799222555, -0.43861623853852766,
    -0.44137126873171667, -0.4441221445704292, -0.44686884016237416,
    -0.44961132965460654, -0.4523495872337709, -0.45508358712634384,
    -0.4578133035988772, -0.46053871095824, -0.46325978355186015,
    -0.4659764957679662, -0.46868882203582796, -0.47139673682599764,
    -0.47410021465054997, -0.4767992300633221, -0.47949375766015295,
    -0.4821837720791227, -0.48486924800079106, -0.487550160148436,
    -0.49022648328829116, -0.49289819222978404, -0.49556526182577254,
    -0.4982276669727818, -0.5008853826112407, -0.5035383837257176,
    -0.5061866453451552, -0.508830142543107, -0.5114688504379703,
    -0.5141027441932217, -0.5167317990176499, -0.5193559901655896,
    -0.5219752929371544, -0.524589682678469, -0.5271991347819013,
    -0.5298036246862946, -0.5324031278771979, -0.5349976198870972,
    -0.5375870762956454, -0.5401714727298929, -0.5427507848645159,
    -0.5453249884220465, -0.5478940591731002, -0.5504579729366048,
    -0.5530167055800275, -0.5555702330196022, -0.5581185312205561,
    -0.560661576197336, -0.5631993440138341, -0.5657318107836131,
    -0.5682589526701315, -0.5707807458869673, -0.5732971666980422,
    -0.5758081914178453, -0.5783137964116556, -0.5808139580957645,
    -0.5833086529376983, -0.5857978574564389, -0.5882815482226452,
    -0.5907597018588742, -0.5932322950397998, -0.5956993044924334,
    -0.5981607069963424, -0.600616479383869, -0.6030665985403482,
    -0.6055110414043255, -0.6079497849677736, -0.6103828062763095,
    -0.6128100824294097, -0.6152315905806268, -0.6176473079378039,
    -0.6200572117632891, -0.62246127937415, -0.6248594881423863,
    -0.6272518154951441, -0.629638238914927, -0.6320187359398091,
    -0.6343932841636455, -0.6367618612362842, -0.6391244448637757,
    -0.641481012808583, -0.6438315428897914, -0.6461760129833163,
    -0.6485144010221124, -0.650846684996381, -0.6531728429537768,
    -0.6554928529996153, -0.6578066932970786, -0.6601143420674205,
    -0.6624157775901718, -0.6647109782033448, -0.6669999223036375,
    -0.669282588346636, -0.6715589548470183, -0.673829000378756,
    -0.6760927035753159, -0.6783500431298615, -0.680600997795453,
    -0.6828455463852481, -0.6850836677727004, -0.687315340891759,
    -0.6895405447370668, -0.6917592583641577, -0.6939714608896539,
    -0.696177131491463, -0.6983762494089729, -0.7005687939432483,
    -0.7027547444572253, -0.7049340803759049, -0.7071067811865476,
    -0.7092728264388657, -0.7114321957452164, -0.7135848687807935,
    -0.7157308252838186, -0.7178700450557317, -0.7200025079613817,
    -0.7221281939292153, -0.724247082951467, -0.726359155084346,
    -0.7284643904482252, -0.7305627692278276, -0.7326542716724128,
    -0.7347388780959635, -0.7368165688773698, -0.7388873244606151,
    -0.7409511253549592, -0.7430079521351217, -0.745057785441466,
    -0.7471006059801801, -0.7491363945234594, -0.7511651319096864,
    -0.7531867990436125, -0.7552013768965365, -0.7572088465064846,
    -0.759209188978388, -0.7612023854842618, -0.7631884172633813,
    -0.765167265622459, -0.7671389119358204, -0.7691033376455797,
    -0.7710605242618138, -0.773010453362737, -0.7749531065948739,
    -0.7768884656732324, -0.778816512381476, -0.7807372285720945,
    -0.7826505961665757, -0.7845565971555752, -0.7864552135990858,
    -0.7883464276266063, -0.79023022143731, -0.7921065773002124,
    -0.7939754775543372, -0.7958369046088836, -0.7976908409433912,
    -0.799537269107905, -0.8013761717231402, -0.8032075314806449,
    -0.8050313311429637, -0.8068475535437993, -0.808656181588175,
    -0.8104571982525948, -0.8122505865852039, -0.8140363297059484,
    -0.8158144108067338, -0.8175848131515837, -0.819347520076797,
    -0.8211025149911046, -0.8228497813758264, -0.8245893027850253,
    -0.8263210628456635, -0.8280450452577558, -0.829761233794523,
    -0.8314696123025452, -0.8331701647019132, -0.83486287498638,
    -0.836547727223512, -0.8382247055548381, -0.8398937941959995,
    -0.8415549774368984, -0.8432082396418454, -0.8448535652497071,
    -0.8464909387740521, -0.8481203448032972, -0.8497417680008525,
    -0.8513551931052652, -0.8529606049303636, -0.8545579883654005,
    -0.8561473283751945, -0.8577286100002721, -0.8593018183570085,
    -0.8608669386377673, -0.8624239561110405, -0.8639728561215867,
    -0.8655136240905691, -0.8670462455156926, -0.8685707059713409,
    -0.8700869911087115, -0.8715950866559511, -0.8730949784182901,
    -0.8745866522781761, -0.8760700941954066, -0.8775452902072614,
    -0.8790122264286335, -0.8804708890521608, -0.881921264348355,
    -0.8833633386657316, -0.8847970984309378, -0.8862225301488806,
    -0.8876396204028539, -0.8890483558546646, -0.8904487232447579,
    -0.8918407093923427, -0.8932243011955153, -0.8945994856313827,
    -0.8959662497561852, -0.8973245807054183, -0.8986744656939538,
    -0.9000158920161602, -0.901348847046022, -0.9026733182372588,
    -0.9039892931234433, -0.9052967593181188, -0.9065957045149153,
    -0.9078861164876663, -0.9091679830905224, -0.9104412922580672,
    -0.9117060320054299, -0.9129621904283982, -0.9142097557035307,
    -0.9154487160882678, -0.9166790599210427, -0.9179007756213905,
    -0.9191138516900578, -0.9203182767091106, -0.9215140393420419,
    -0.9227011283338786, -0.9238795325112867, -0.9250492407826776,
    -0.9262102421383114, -0.9273625256504011, -0.9285060804732156,
    -0.9296408958431812, -0.9307669610789837, -0.9318842655816681,
    -0.932992798834739, -0.9340925504042589, -0.9351835099389476,
    -0.9362656671702783, -0.937339011912575, -0.9384035340631081,
    -0.9394592236021899, -0.9405060705932683, -0.9415440651830208,
    -0.9425731976014469, -0.9435934581619604, -0.9446048372614803,
    -0.9456073253805213, -0.9466009130832835, -0.9475855910177411,
    -0.9485613499157303, -0.9495281805930367, -0.9504860739494817,
    -0.9514350209690083, -0.9523750127197659, -0.9533060403541939,
    -0.9542280951091057, -0.9551411683057708, -0.9560452513499964,
    -0.9569403357322088, -0.9578264130275329, -0.9587034748958716,
    -0.9595715130819845, -0.9604305194155658, -0.9612804858113206,
    -0.9621214042690416, -0.9629532668736839, -0.9637760657954398,
    -0.9645897932898128, -0.9653944416976894, -0.9661900034454125,
    -0.9669764710448521, -0.9677538370934755, -0.9685220942744173,
    -0.9692812353565485, -0.970031253194544, -0.9707721407289504,
    -0.9715038909862518, -0.9722264970789363, -0.9729399522055602,
    -0.973644249650812, -0.9743393827855759, -0.9750253450669941,
    -0.9757021300385286, -0.9763697313300211, -0.9770281426577544,
    -0.9776773578245099, -0.9783173707196277, -0.9789481753190622,
    -0.9795697656854405, -0.9801821359681174, -0.9807852804032304,
    -0.9813791933137546, -0.9819638691095552, -0.9825393022874412,
    -0.9831054874312163, -0.9836624192117303, -0.984210092386929,
    -0.9847485018019042, -0.9852776423889412, -0.9857975091675675,
    -0.9863080972445987, -0.9868094018141855, -0.9873014181578584,
    -0.9877841416445722, -0.9882575677307495, -0.9887216919603238,
    -0.989176509964781, -0.9896220174632009, -0.9900582102622971,
    -0.9904850842564571, -0.99090263542778, -0.9913108598461154,
    -0.9917097536690995, -0.9920993131421918, -0.99247953459871,
    -0.9928504144598651, -0.9932119492347945, -0.9935641355205953,
    -0.9939069700023561, -0.9942404494531879, -0.9945645707342554,
    -0.9948793307948056, -0.9951847266721969, -0.9954807554919269,
    -0.9957674144676598, -0.996044700901252, -0.996312612182778,
    -0.9965711457905548, -0.9968202992911657, -0.997060070339483,
    -0.9972904566786902, -0.9975114561403035, -0.9977230666441916,
    -0.997925286198596, -0.9981181129001492, -0.9983015449338929,
    -0.9984755805732948, -0.9986402181802653, -0.9987954562051724,
    -0.9989412931868569, -0.9990777277526454, -0.9992047586183639,
    -0.9993223845883495, -0.9994306045554617, -0.9995294175010931,
    -0.9996188224951786, -0.9996988186962042, -0.9997694053512153,
    -0.9998305817958234, -0.9998823474542126, -0.9999247018391445,
    -0.9999576445519639, -0.9999811752826011, -0.9999952938095762, -1.0 };

  static const real_T c[1025] = { 0.0, -0.003067956762965976,
    -0.006135884649154475, -0.00920375478205982, -0.012271538285719925,
    -0.0153392062849881, -0.01840672990580482, -0.021474080275469508,
    -0.024541228522912288, -0.02760814577896574, -0.030674803176636626,
    -0.03374117185137758, -0.03680722294135883, -0.03987292758773981,
    -0.04293825693494082, -0.04600318213091462, -0.049067674327418015,
    -0.052131704680283324, -0.05519524434968994, -0.05825826450043575,
    -0.06132073630220858, -0.06438263092985747, -0.06744391956366405,
    -0.07050457338961386, -0.07356456359966743, -0.07662386139203149,
    -0.07968243797143013, -0.08274026454937569, -0.0857973123444399,
    -0.0888535525825246, -0.09190895649713272, -0.09496349532963899,
    -0.0980171403295606, -0.10106986275482782, -0.10412163387205459,
    -0.10717242495680884, -0.11022220729388306, -0.11327095217756435,
    -0.11631863091190475, -0.11936521481099135, -0.1224106751992162,
    -0.12545498341154623, -0.12849811079379317, -0.13154002870288312,
    -0.13458070850712617, -0.13762012158648604, -0.1406582393328492,
    -0.14369503315029447, -0.14673047445536175, -0.1497645346773215,
    -0.15279718525844344, -0.15582839765426523, -0.15885814333386145,
    -0.16188639378011183, -0.16491312048996992, -0.16793829497473117,
    -0.17096188876030122, -0.17398387338746382, -0.17700422041214875,
    -0.18002290140569951, -0.18303988795514095, -0.18605515166344663,
    -0.1890686641498062, -0.19208039704989244, -0.19509032201612825,
    -0.19809841071795356, -0.2011046348420919, -0.20410896609281687,
    -0.20711137619221856, -0.2101118368804696, -0.21311031991609136,
    -0.21610679707621952, -0.2191012401568698, -0.2220936209732035,
    -0.22508391135979283, -0.22807208317088573, -0.2310581082806711,
    -0.23404195858354343, -0.2370236059943672, -0.2400030224487415,
    -0.24298017990326387, -0.2459550503357946, -0.24892760574572015,
    -0.25189781815421697, -0.25486565960451457, -0.257831102162159,
    -0.2607941179152755, -0.26375467897483135, -0.26671275747489837,
    -0.2696683255729151, -0.272621355449949, -0.27557181931095814,
    -0.27851968938505306, -0.28146493792575794, -0.2844075372112719,
    -0.2873474595447295, -0.29028467725446233, -0.29321916269425863,
    -0.2961508882436238, -0.2990798263080405, -0.3020059493192281,
    -0.3049292297354024, -0.30784964004153487, -0.3107671527496115,
    -0.3136817403988915, -0.31659337555616585, -0.3195020308160157,
    -0.32240767880106985, -0.3253102921622629, -0.3282098435790925,
    -0.33110630575987643, -0.3339996514420094, -0.33688985339222005,
    -0.33977688440682685, -0.3426607173119944, -0.3455413249639891,
    -0.34841868024943456, -0.3512927560855671, -0.35416352542049034,
    -0.35703096123343, -0.3598950365349881, -0.3627557243673972,
    -0.36561299780477385, -0.3684668299533723, -0.3713171939518375,
    -0.37416406297145793, -0.37700741021641826, -0.37984720892405116,
    -0.3826834323650898, -0.38551605384391885, -0.38834504669882625,
    -0.39117038430225387, -0.3939920400610481, -0.3968099874167103,
    -0.3996241998456468, -0.40243465085941843, -0.40524131400498986,
    -0.4080441628649787, -0.4108431710579039, -0.4136383122384345,
    -0.41642956009763715, -0.4192168883632239, -0.4220002707997997,
    -0.4247796812091088, -0.4275550934302821, -0.4303264813400826,
    -0.43309381885315196, -0.4358570799222555, -0.43861623853852766,
    -0.44137126873171667, -0.4441221445704292, -0.44686884016237416,
    -0.44961132965460654, -0.4523495872337709, -0.45508358712634384,
    -0.4578133035988772, -0.46053871095824, -0.46325978355186015,
    -0.4659764957679662, -0.46868882203582796, -0.47139673682599764,
    -0.47410021465054997, -0.4767992300633221, -0.47949375766015295,
    -0.4821837720791227, -0.48486924800079106, -0.487550160148436,
    -0.49022648328829116, -0.49289819222978404, -0.49556526182577254,
    -0.4982276669727818, -0.5008853826112407, -0.5035383837257176,
    -0.5061866453451552, -0.508830142543107, -0.5114688504379703,
    -0.5141027441932217, -0.5167317990176499, -0.5193559901655896,
    -0.5219752929371544, -0.524589682678469, -0.5271991347819013,
    -0.5298036246862946, -0.5324031278771979, -0.5349976198870972,
    -0.5375870762956454, -0.5401714727298929, -0.5427507848645159,
    -0.5453249884220465, -0.5478940591731002, -0.5504579729366048,
    -0.5530167055800275, -0.5555702330196022, -0.5581185312205561,
    -0.560661576197336, -0.5631993440138341, -0.5657318107836131,
    -0.5682589526701315, -0.5707807458869673, -0.5732971666980422,
    -0.5758081914178453, -0.5783137964116556, -0.5808139580957645,
    -0.5833086529376983, -0.5857978574564389, -0.5882815482226452,
    -0.5907597018588742, -0.5932322950397998, -0.5956993044924334,
    -0.5981607069963424, -0.600616479383869, -0.6030665985403482,
    -0.6055110414043255, -0.6079497849677736, -0.6103828062763095,
    -0.6128100824294097, -0.6152315905806268, -0.6176473079378039,
    -0.6200572117632891, -0.62246127937415, -0.6248594881423863,
    -0.6272518154951441, -0.629638238914927, -0.6320187359398091,
    -0.6343932841636455, -0.6367618612362842, -0.6391244448637757,
    -0.641481012808583, -0.6438315428897914, -0.6461760129833163,
    -0.6485144010221124, -0.650846684996381, -0.6531728429537768,
    -0.6554928529996153, -0.6578066932970786, -0.6601143420674205,
    -0.6624157775901718, -0.6647109782033448, -0.6669999223036375,
    -0.669282588346636, -0.6715589548470183, -0.673829000378756,
    -0.6760927035753159, -0.6783500431298615, -0.680600997795453,
    -0.6828455463852481, -0.6850836677727004, -0.687315340891759,
    -0.6895405447370668, -0.6917592583641577, -0.6939714608896539,
    -0.696177131491463, -0.6983762494089729, -0.7005687939432483,
    -0.7027547444572253, -0.7049340803759049, -0.7071067811865476,
    -0.7092728264388657, -0.7114321957452164, -0.7135848687807935,
    -0.7157308252838186, -0.7178700450557317, -0.7200025079613817,
    -0.7221281939292153, -0.724247082951467, -0.726359155084346,
    -0.7284643904482252, -0.7305627692278276, -0.7326542716724128,
    -0.7347388780959635, -0.7368165688773698, -0.7388873244606151,
    -0.7409511253549592, -0.7430079521351217, -0.745057785441466,
    -0.7471006059801801, -0.7491363945234594, -0.7511651319096864,
    -0.7531867990436125, -0.7552013768965365, -0.7572088465064846,
    -0.759209188978388, -0.7612023854842618, -0.7631884172633813,
    -0.765167265622459, -0.7671389119358204, -0.7691033376455797,
    -0.7710605242618138, -0.773010453362737, -0.7749531065948739,
    -0.7768884656732324, -0.778816512381476, -0.7807372285720945,
    -0.7826505961665757, -0.7845565971555752, -0.7864552135990858,
    -0.7883464276266063, -0.79023022143731, -0.7921065773002124,
    -0.7939754775543372, -0.7958369046088836, -0.7976908409433912,
    -0.799537269107905, -0.8013761717231402, -0.8032075314806449,
    -0.8050313311429637, -0.8068475535437993, -0.808656181588175,
    -0.8104571982525948, -0.8122505865852039, -0.8140363297059484,
    -0.8158144108067338, -0.8175848131515837, -0.819347520076797,
    -0.8211025149911046, -0.8228497813758264, -0.8245893027850253,
    -0.8263210628456635, -0.8280450452577558, -0.829761233794523,
    -0.8314696123025452, -0.8331701647019132, -0.83486287498638,
    -0.836547727223512, -0.8382247055548381, -0.8398937941959995,
    -0.8415549774368984, -0.8432082396418454, -0.8448535652497071,
    -0.8464909387740521, -0.8481203448032972, -0.8497417680008525,
    -0.8513551931052652, -0.8529606049303636, -0.8545579883654005,
    -0.8561473283751945, -0.8577286100002721, -0.8593018183570085,
    -0.8608669386377673, -0.8624239561110405, -0.8639728561215867,
    -0.8655136240905691, -0.8670462455156926, -0.8685707059713409,
    -0.8700869911087115, -0.8715950866559511, -0.8730949784182901,
    -0.8745866522781761, -0.8760700941954066, -0.8775452902072614,
    -0.8790122264286335, -0.8804708890521608, -0.881921264348355,
    -0.8833633386657316, -0.8847970984309378, -0.8862225301488806,
    -0.8876396204028539, -0.8890483558546646, -0.8904487232447579,
    -0.8918407093923427, -0.8932243011955153, -0.8945994856313827,
    -0.8959662497561852, -0.8973245807054183, -0.8986744656939538,
    -0.9000158920161602, -0.901348847046022, -0.9026733182372588,
    -0.9039892931234433, -0.9052967593181188, -0.9065957045149153,
    -0.9078861164876663, -0.9091679830905224, -0.9104412922580672,
    -0.9117060320054299, -0.9129621904283982, -0.9142097557035307,
    -0.9154487160882678, -0.9166790599210427, -0.9179007756213905,
    -0.9191138516900578, -0.9203182767091106, -0.9215140393420419,
    -0.9227011283338786, -0.9238795325112867, -0.9250492407826776,
    -0.9262102421383114, -0.9273625256504011, -0.9285060804732156,
    -0.9296408958431812, -0.9307669610789837, -0.9318842655816681,
    -0.932992798834739, -0.9340925504042589, -0.9351835099389476,
    -0.9362656671702783, -0.937339011912575, -0.9384035340631081,
    -0.9394592236021899, -0.9405060705932683, -0.9415440651830208,
    -0.9425731976014469, -0.9435934581619604, -0.9446048372614803,
    -0.9456073253805213, -0.9466009130832835, -0.9475855910177411,
    -0.9485613499157303, -0.9495281805930367, -0.9504860739494817,
    -0.9514350209690083, -0.9523750127197659, -0.9533060403541939,
    -0.9542280951091057, -0.9551411683057708, -0.9560452513499964,
    -0.9569403357322088, -0.9578264130275329, -0.9587034748958716,
    -0.9595715130819845, -0.9604305194155658, -0.9612804858113206,
    -0.9621214042690416, -0.9629532668736839, -0.9637760657954398,
    -0.9645897932898128, -0.9653944416976894, -0.9661900034454125,
    -0.9669764710448521, -0.9677538370934755, -0.9685220942744173,
    -0.9692812353565485, -0.970031253194544, -0.9707721407289504,
    -0.9715038909862518, -0.9722264970789363, -0.9729399522055602,
    -0.973644249650812, -0.9743393827855759, -0.9750253450669941,
    -0.9757021300385286, -0.9763697313300211, -0.9770281426577544,
    -0.9776773578245099, -0.9783173707196277, -0.9789481753190622,
    -0.9795697656854405, -0.9801821359681174, -0.9807852804032304,
    -0.9813791933137546, -0.9819638691095552, -0.9825393022874412,
    -0.9831054874312163, -0.9836624192117303, -0.984210092386929,
    -0.9847485018019042, -0.9852776423889412, -0.9857975091675675,
    -0.9863080972445987, -0.9868094018141855, -0.9873014181578584,
    -0.9877841416445722, -0.9882575677307495, -0.9887216919603238,
    -0.989176509964781, -0.9896220174632009, -0.9900582102622971,
    -0.9904850842564571, -0.99090263542778, -0.9913108598461154,
    -0.9917097536690995, -0.9920993131421918, -0.99247953459871,
    -0.9928504144598651, -0.9932119492347945, -0.9935641355205953,
    -0.9939069700023561, -0.9942404494531879, -0.9945645707342554,
    -0.9948793307948056, -0.9951847266721969, -0.9954807554919269,
    -0.9957674144676598, -0.996044700901252, -0.996312612182778,
    -0.9965711457905548, -0.9968202992911657, -0.997060070339483,
    -0.9972904566786902, -0.9975114561403035, -0.9977230666441916,
    -0.997925286198596, -0.9981181129001492, -0.9983015449338929,
    -0.9984755805732948, -0.9986402181802653, -0.9987954562051724,
    -0.9989412931868569, -0.9990777277526454, -0.9992047586183639,
    -0.9993223845883495, -0.9994306045554617, -0.9995294175010931,
    -0.9996188224951786, -0.9996988186962042, -0.9997694053512153,
    -0.9998305817958234, -0.9998823474542126, -0.9999247018391445,
    -0.9999576445519639, -0.9999811752826011, -0.9999952938095762, -1.0,
    -0.9999952938095762, -0.9999811752826011, -0.9999576445519639,
    -0.9999247018391445, -0.9998823474542126, -0.9998305817958234,
    -0.9997694053512153, -0.9996988186962042, -0.9996188224951786,
    -0.9995294175010931, -0.9994306045554617, -0.9993223845883495,
    -0.9992047586183639, -0.9990777277526454, -0.9989412931868569,
    -0.9987954562051724, -0.9986402181802653, -0.9984755805732948,
    -0.9983015449338929, -0.9981181129001492, -0.997925286198596,
    -0.9977230666441916, -0.9975114561403035, -0.9972904566786902,
    -0.997060070339483, -0.9968202992911657, -0.9965711457905548,
    -0.996312612182778, -0.996044700901252, -0.9957674144676598,
    -0.9954807554919269, -0.9951847266721969, -0.9948793307948056,
    -0.9945645707342554, -0.9942404494531879, -0.9939069700023561,
    -0.9935641355205953, -0.9932119492347945, -0.9928504144598651,
    -0.99247953459871, -0.9920993131421918, -0.9917097536690995,
    -0.9913108598461154, -0.99090263542778, -0.9904850842564571,
    -0.9900582102622971, -0.9896220174632009, -0.989176509964781,
    -0.9887216919603238, -0.9882575677307495, -0.9877841416445722,
    -0.9873014181578584, -0.9868094018141855, -0.9863080972445987,
    -0.9857975091675675, -0.9852776423889412, -0.9847485018019042,
    -0.984210092386929, -0.9836624192117303, -0.9831054874312163,
    -0.9825393022874412, -0.9819638691095552, -0.9813791933137546,
    -0.9807852804032304, -0.9801821359681174, -0.9795697656854405,
    -0.9789481753190622, -0.9783173707196277, -0.9776773578245099,
    -0.9770281426577544, -0.9763697313300211, -0.9757021300385286,
    -0.9750253450669941, -0.9743393827855759, -0.973644249650812,
    -0.9729399522055602, -0.9722264970789363, -0.9715038909862518,
    -0.9707721407289504, -0.970031253194544, -0.9692812353565485,
    -0.9685220942744173, -0.9677538370934755, -0.9669764710448521,
    -0.9661900034454125, -0.9653944416976894, -0.9645897932898128,
    -0.9637760657954398, -0.9629532668736839, -0.9621214042690416,
    -0.9612804858113206, -0.9604305194155658, -0.9595715130819845,
    -0.9587034748958716, -0.9578264130275329, -0.9569403357322088,
    -0.9560452513499964, -0.9551411683057708, -0.9542280951091057,
    -0.9533060403541939, -0.9523750127197659, -0.9514350209690083,
    -0.9504860739494817, -0.9495281805930367, -0.9485613499157303,
    -0.9475855910177411, -0.9466009130832835, -0.9456073253805213,
    -0.9446048372614803, -0.9435934581619604, -0.9425731976014469,
    -0.9415440651830208, -0.9405060705932683, -0.9394592236021899,
    -0.9384035340631081, -0.937339011912575, -0.9362656671702783,
    -0.9351835099389476, -0.9340925504042589, -0.932992798834739,
    -0.9318842655816681, -0.9307669610789837, -0.9296408958431812,
    -0.9285060804732156, -0.9273625256504011, -0.9262102421383114,
    -0.9250492407826776, -0.9238795325112867, -0.9227011283338786,
    -0.9215140393420419, -0.9203182767091106, -0.9191138516900578,
    -0.9179007756213905, -0.9166790599210427, -0.9154487160882678,
    -0.9142097557035307, -0.9129621904283982, -0.9117060320054299,
    -0.9104412922580672, -0.9091679830905224, -0.9078861164876663,
    -0.9065957045149153, -0.9052967593181188, -0.9039892931234433,
    -0.9026733182372588, -0.901348847046022, -0.9000158920161602,
    -0.8986744656939538, -0.8973245807054183, -0.8959662497561852,
    -0.8945994856313827, -0.8932243011955153, -0.8918407093923427,
    -0.8904487232447579, -0.8890483558546646, -0.8876396204028539,
    -0.8862225301488806, -0.8847970984309378, -0.8833633386657316,
    -0.881921264348355, -0.8804708890521608, -0.8790122264286335,
    -0.8775452902072614, -0.8760700941954066, -0.8745866522781761,
    -0.8730949784182901, -0.8715950866559511, -0.8700869911087115,
    -0.8685707059713409, -0.8670462455156926, -0.8655136240905691,
    -0.8639728561215867, -0.8624239561110405, -0.8608669386377673,
    -0.8593018183570085, -0.8577286100002721, -0.8561473283751945,
    -0.8545579883654005, -0.8529606049303636, -0.8513551931052652,
    -0.8497417680008525, -0.8481203448032972, -0.8464909387740521,
    -0.8448535652497071, -0.8432082396418454, -0.8415549774368984,
    -0.8398937941959995, -0.8382247055548381, -0.836547727223512,
    -0.83486287498638, -0.8331701647019132, -0.8314696123025452,
    -0.829761233794523, -0.8280450452577558, -0.8263210628456635,
    -0.8245893027850253, -0.8228497813758264, -0.8211025149911046,
    -0.819347520076797, -0.8175848131515837, -0.8158144108067338,
    -0.8140363297059484, -0.8122505865852039, -0.8104571982525948,
    -0.808656181588175, -0.8068475535437993, -0.8050313311429637,
    -0.8032075314806449, -0.8013761717231402, -0.799537269107905,
    -0.7976908409433912, -0.7958369046088836, -0.7939754775543372,
    -0.7921065773002124, -0.79023022143731, -0.7883464276266063,
    -0.7864552135990858, -0.7845565971555752, -0.7826505961665757,
    -0.7807372285720945, -0.778816512381476, -0.7768884656732324,
    -0.7749531065948739, -0.773010453362737, -0.7710605242618138,
    -0.7691033376455797, -0.7671389119358204, -0.765167265622459,
    -0.7631884172633813, -0.7612023854842618, -0.759209188978388,
    -0.7572088465064846, -0.7552013768965365, -0.7531867990436125,
    -0.7511651319096864, -0.7491363945234594, -0.7471006059801801,
    -0.745057785441466, -0.7430079521351217, -0.7409511253549592,
    -0.7388873244606151, -0.7368165688773698, -0.7347388780959635,
    -0.7326542716724128, -0.7305627692278276, -0.7284643904482252,
    -0.726359155084346, -0.724247082951467, -0.7221281939292153,
    -0.7200025079613817, -0.7178700450557317, -0.7157308252838186,
    -0.7135848687807935, -0.7114321957452164, -0.7092728264388657,
    -0.7071067811865476, -0.7049340803759049, -0.7027547444572253,
    -0.7005687939432483, -0.6983762494089729, -0.696177131491463,
    -0.6939714608896539, -0.6917592583641577, -0.6895405447370668,
    -0.687315340891759, -0.6850836677727004, -0.6828455463852481,
    -0.680600997795453, -0.6783500431298615, -0.6760927035753159,
    -0.673829000378756, -0.6715589548470183, -0.669282588346636,
    -0.6669999223036375, -0.6647109782033448, -0.6624157775901718,
    -0.6601143420674205, -0.6578066932970786, -0.6554928529996153,
    -0.6531728429537768, -0.650846684996381, -0.6485144010221124,
    -0.6461760129833163, -0.6438315428897914, -0.641481012808583,
    -0.6391244448637757, -0.6367618612362842, -0.6343932841636455,
    -0.6320187359398091, -0.629638238914927, -0.6272518154951441,
    -0.6248594881423863, -0.62246127937415, -0.6200572117632891,
    -0.6176473079378039, -0.6152315905806268, -0.6128100824294097,
    -0.6103828062763095, -0.6079497849677736, -0.6055110414043255,
    -0.6030665985403482, -0.600616479383869, -0.5981607069963424,
    -0.5956993044924334, -0.5932322950397998, -0.5907597018588742,
    -0.5882815482226452, -0.5857978574564389, -0.5833086529376983,
    -0.5808139580957645, -0.5783137964116556, -0.5758081914178453,
    -0.5732971666980422, -0.5707807458869673, -0.5682589526701315,
    -0.5657318107836131, -0.5631993440138341, -0.560661576197336,
    -0.5581185312205561, -0.5555702330196022, -0.5530167055800275,
    -0.5504579729366048, -0.5478940591731002, -0.5453249884220465,
    -0.5427507848645159, -0.5401714727298929, -0.5375870762956454,
    -0.5349976198870972, -0.5324031278771979, -0.5298036246862946,
    -0.5271991347819013, -0.524589682678469, -0.5219752929371544,
    -0.5193559901655896, -0.5167317990176499, -0.5141027441932217,
    -0.5114688504379703, -0.508830142543107, -0.5061866453451552,
    -0.5035383837257176, -0.5008853826112407, -0.4982276669727818,
    -0.49556526182577254, -0.49289819222978404, -0.49022648328829116,
    -0.487550160148436, -0.48486924800079106, -0.4821837720791227,
    -0.47949375766015295, -0.4767992300633221, -0.47410021465054997,
    -0.47139673682599764, -0.46868882203582796, -0.4659764957679662,
    -0.46325978355186015, -0.46053871095824, -0.4578133035988772,
    -0.45508358712634384, -0.4523495872337709, -0.44961132965460654,
    -0.44686884016237416, -0.4441221445704292, -0.44137126873171667,
    -0.43861623853852766, -0.4358570799222555, -0.43309381885315196,
    -0.4303264813400826, -0.4275550934302821, -0.4247796812091088,
    -0.4220002707997997, -0.4192168883632239, -0.41642956009763715,
    -0.4136383122384345, -0.4108431710579039, -0.4080441628649787,
    -0.40524131400498986, -0.40243465085941843, -0.3996241998456468,
    -0.3968099874167103, -0.3939920400610481, -0.39117038430225387,
    -0.38834504669882625, -0.38551605384391885, -0.3826834323650898,
    -0.37984720892405116, -0.37700741021641826, -0.37416406297145793,
    -0.3713171939518375, -0.3684668299533723, -0.36561299780477385,
    -0.3627557243673972, -0.3598950365349881, -0.35703096123343,
    -0.35416352542049034, -0.3512927560855671, -0.34841868024943456,
    -0.3455413249639891, -0.3426607173119944, -0.33977688440682685,
    -0.33688985339222005, -0.3339996514420094, -0.33110630575987643,
    -0.3282098435790925, -0.3253102921622629, -0.32240767880106985,
    -0.3195020308160157, -0.31659337555616585, -0.3136817403988915,
    -0.3107671527496115, -0.30784964004153487, -0.3049292297354024,
    -0.3020059493192281, -0.2990798263080405, -0.2961508882436238,
    -0.29321916269425863, -0.29028467725446233, -0.2873474595447295,
    -0.2844075372112719, -0.28146493792575794, -0.27851968938505306,
    -0.27557181931095814, -0.272621355449949, -0.2696683255729151,
    -0.26671275747489837, -0.26375467897483135, -0.2607941179152755,
    -0.257831102162159, -0.25486565960451457, -0.25189781815421697,
    -0.24892760574572015, -0.2459550503357946, -0.24298017990326387,
    -0.2400030224487415, -0.2370236059943672, -0.23404195858354343,
    -0.2310581082806711, -0.22807208317088573, -0.22508391135979283,
    -0.2220936209732035, -0.2191012401568698, -0.21610679707621952,
    -0.21311031991609136, -0.2101118368804696, -0.20711137619221856,
    -0.20410896609281687, -0.2011046348420919, -0.19809841071795356,
    -0.19509032201612825, -0.19208039704989244, -0.1890686641498062,
    -0.18605515166344663, -0.18303988795514095, -0.18002290140569951,
    -0.17700422041214875, -0.17398387338746382, -0.17096188876030122,
    -0.16793829497473117, -0.16491312048996992, -0.16188639378011183,
    -0.15885814333386145, -0.15582839765426523, -0.15279718525844344,
    -0.1497645346773215, -0.14673047445536175, -0.14369503315029447,
    -0.1406582393328492, -0.13762012158648604, -0.13458070850712617,
    -0.13154002870288312, -0.12849811079379317, -0.12545498341154623,
    -0.1224106751992162, -0.11936521481099135, -0.11631863091190475,
    -0.11327095217756435, -0.11022220729388306, -0.10717242495680884,
    -0.10412163387205459, -0.10106986275482782, -0.0980171403295606,
    -0.09496349532963899, -0.09190895649713272, -0.0888535525825246,
    -0.0857973123444399, -0.08274026454937569, -0.07968243797143013,
    -0.07662386139203149, -0.07356456359966743, -0.07050457338961386,
    -0.06744391956366405, -0.06438263092985747, -0.06132073630220858,
    -0.05825826450043575, -0.05519524434968994, -0.052131704680283324,
    -0.049067674327418015, -0.04600318213091462, -0.04293825693494082,
    -0.03987292758773981, -0.03680722294135883, -0.03374117185137758,
    -0.030674803176636626, -0.02760814577896574, -0.024541228522912288,
    -0.021474080275469508, -0.01840672990580482, -0.0153392062849881,
    -0.012271538285719925, -0.00920375478205982, -0.006135884649154475,
    -0.003067956762965976, -0.0 };

  static const int16_T d_0[1024] = { 1, 513, 257, 769, 129, 641, 385, 897, 65,
    577, 321, 833, 193, 705, 449, 961, 33, 545, 289, 801, 161, 673, 417, 929, 97,
    609, 353, 865, 225, 737, 481, 993, 17, 529, 273, 785, 145, 657, 401, 913, 81,
    593, 337, 849, 209, 721, 465, 977, 49, 561, 305, 817, 177, 689, 433, 945,
    113, 625, 369, 881, 241, 753, 497, 1009, 9, 521, 265, 777, 137, 649, 393,
    905, 73, 585, 329, 841, 201, 713, 457, 969, 41, 553, 297, 809, 169, 681, 425,
    937, 105, 617, 361, 873, 233, 745, 489, 1001, 25, 537, 281, 793, 153, 665,
    409, 921, 89, 601, 345, 857, 217, 729, 473, 985, 57, 569, 313, 825, 185, 697,
    441, 953, 121, 633, 377, 889, 249, 761, 505, 1017, 5, 517, 261, 773, 133,
    645, 389, 901, 69, 581, 325, 837, 197, 709, 453, 965, 37, 549, 293, 805, 165,
    677, 421, 933, 101, 613, 357, 869, 229, 741, 485, 997, 21, 533, 277, 789,
    149, 661, 405, 917, 85, 597, 341, 853, 213, 725, 469, 981, 53, 565, 309, 821,
    181, 693, 437, 949, 117, 629, 373, 885, 245, 757, 501, 1013, 13, 525, 269,
    781, 141, 653, 397, 909, 77, 589, 333, 845, 205, 717, 461, 973, 45, 557, 301,
    813, 173, 685, 429, 941, 109, 621, 365, 877, 237, 749, 493, 1005, 29, 541,
    285, 797, 157, 669, 413, 925, 93, 605, 349, 861, 221, 733, 477, 989, 61, 573,
    317, 829, 189, 701, 445, 957, 125, 637, 381, 893, 253, 765, 509, 1021, 3,
    515, 259, 771, 131, 643, 387, 899, 67, 579, 323, 835, 195, 707, 451, 963, 35,
    547, 291, 803, 163, 675, 419, 931, 99, 611, 355, 867, 227, 739, 483, 995, 19,
    531, 275, 787, 147, 659, 403, 915, 83, 595, 339, 851, 211, 723, 467, 979, 51,
    563, 307, 819, 179, 691, 435, 947, 115, 627, 371, 883, 243, 755, 499, 1011,
    11, 523, 267, 779, 139, 651, 395, 907, 75, 587, 331, 843, 203, 715, 459, 971,
    43, 555, 299, 811, 171, 683, 427, 939, 107, 619, 363, 875, 235, 747, 491,
    1003, 27, 539, 283, 795, 155, 667, 411, 923, 91, 603, 347, 859, 219, 731,
    475, 987, 59, 571, 315, 827, 187, 699, 443, 955, 123, 635, 379, 891, 251,
    763, 507, 1019, 7, 519, 263, 775, 135, 647, 391, 903, 71, 583, 327, 839, 199,
    711, 455, 967, 39, 551, 295, 807, 167, 679, 423, 935, 103, 615, 359, 871,
    231, 743, 487, 999, 23, 535, 279, 791, 151, 663, 407, 919, 87, 599, 343, 855,
    215, 727, 471, 983, 55, 567, 311, 823, 183, 695, 439, 951, 119, 631, 375,
    887, 247, 759, 503, 1015, 15, 527, 271, 783, 143, 655, 399, 911, 79, 591,
    335, 847, 207, 719, 463, 975, 47, 559, 303, 815, 175, 687, 431, 943, 111,
    623, 367, 879, 239, 751, 495, 1007, 31, 543, 287, 799, 159, 671, 415, 927,
    95, 607, 351, 863, 223, 735, 479, 991, 63, 575, 319, 831, 191, 703, 447, 959,
    127, 639, 383, 895, 255, 767, 511, 1023, 2, 514, 258, 770, 130, 642, 386,
    898, 66, 578, 322, 834, 194, 706, 450, 962, 34, 546, 290, 802, 162, 674, 418,
    930, 98, 610, 354, 866, 226, 738, 482, 994, 18, 530, 274, 786, 146, 658, 402,
    914, 82, 594, 338, 850, 210, 722, 466, 978, 50, 562, 306, 818, 178, 690, 434,
    946, 114, 626, 370, 882, 242, 754, 498, 1010, 10, 522, 266, 778, 138, 650,
    394, 906, 74, 586, 330, 842, 202, 714, 458, 970, 42, 554, 298, 810, 170, 682,
    426, 938, 106, 618, 362, 874, 234, 746, 490, 1002, 26, 538, 282, 794, 154,
    666, 410, 922, 90, 602, 346, 858, 218, 730, 474, 986, 58, 570, 314, 826, 186,
    698, 442, 954, 122, 634, 378, 890, 250, 762, 506, 1018, 6, 518, 262, 774,
    134, 646, 390, 902, 70, 582, 326, 838, 198, 710, 454, 966, 38, 550, 294, 806,
    166, 678, 422, 934, 102, 614, 358, 870, 230, 742, 486, 998, 22, 534, 278,
    790, 150, 662, 406, 918, 86, 598, 342, 854, 214, 726, 470, 982, 54, 566, 310,
    822, 182, 694, 438, 950, 118, 630, 374, 886, 246, 758, 502, 1014, 14, 526,
    270, 782, 142, 654, 398, 910, 78, 590, 334, 846, 206, 718, 462, 974, 46, 558,
    302, 814, 174, 686, 430, 942, 110, 622, 366, 878, 238, 750, 494, 1006, 30,
    542, 286, 798, 158, 670, 414, 926, 94, 606, 350, 862, 222, 734, 478, 990, 62,
    574, 318, 830, 190, 702, 446, 958, 126, 638, 382, 894, 254, 766, 510, 1022,
    4, 516, 260, 772, 132, 644, 388, 900, 68, 580, 324, 836, 196, 708, 452, 964,
    36, 548, 292, 804, 164, 676, 420, 932, 100, 612, 356, 868, 228, 740, 484,
    996, 20, 532, 276, 788, 148, 660, 404, 916, 84, 596, 340, 852, 212, 724, 468,
    980, 52, 564, 308, 820, 180, 692, 436, 948, 116, 628, 372, 884, 244, 756,
    500, 1012, 12, 524, 268, 780, 140, 652, 396, 908, 76, 588, 332, 844, 204,
    716, 460, 972, 44, 556, 300, 812, 172, 684, 428, 940, 108, 620, 364, 876,
    236, 748, 492, 1004, 28, 540, 284, 796, 156, 668, 412, 924, 92, 604, 348,
    860, 220, 732, 476, 988, 60, 572, 316, 828, 188, 700, 444, 956, 124, 636,
    380, 892, 252, 764, 508, 1020, 8, 520, 264, 776, 136, 648, 392, 904, 72, 584,
    328, 840, 200, 712, 456, 968, 40, 552, 296, 808, 168, 680, 424, 936, 104,
    616, 360, 872, 232, 744, 488, 1000, 24, 536, 280, 792, 152, 664, 408, 920,
    88, 600, 344, 856, 216, 728, 472, 984, 56, 568, 312, 824, 184, 696, 440, 952,
    120, 632, 376, 888, 248, 760, 504, 1016, 16, 528, 272, 784, 144, 656, 400,
    912, 80, 592, 336, 848, 208, 720, 464, 976, 48, 560, 304, 816, 176, 688, 432,
    944, 112, 624, 368, 880, 240, 752, 496, 1008, 32, 544, 288, 800, 160, 672,
    416, 928, 96, 608, 352, 864, 224, 736, 480, 992, 64, 576, 320, 832, 192, 704,
    448, 960, 128, 640, 384, 896, 256, 768, 512, 1024 };

  static const int16_T g[1024] = { 1, 1024, 1023, 1022, 1021, 1020, 1019, 1018,
    1017, 1016, 1015, 1014, 1013, 1012, 1011, 1010, 1009, 1008, 1007, 1006, 1005,
    1004, 1003, 1002, 1001, 1000, 999, 998, 997, 996, 995, 994, 993, 992, 991,
    990, 989, 988, 987, 986, 985, 984, 983, 982, 981, 980, 979, 978, 977, 976,
    975, 974, 973, 972, 971, 970, 969, 968, 967, 966, 965, 964, 963, 962, 961,
    960, 959, 958, 957, 956, 955, 954, 953, 952, 951, 950, 949, 948, 947, 946,
    945, 944, 943, 942, 941, 940, 939, 938, 937, 936, 935, 934, 933, 932, 931,
    930, 929, 928, 927, 926, 925, 924, 923, 922, 921, 920, 919, 918, 917, 916,
    915, 914, 913, 912, 911, 910, 909, 908, 907, 906, 905, 904, 903, 902, 901,
    900, 899, 898, 897, 896, 895, 894, 893, 892, 891, 890, 889, 888, 887, 886,
    885, 884, 883, 882, 881, 880, 879, 878, 877, 876, 875, 874, 873, 872, 871,
    870, 869, 868, 867, 866, 865, 864, 863, 862, 861, 860, 859, 858, 857, 856,
    855, 854, 853, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841,
    840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826,
    825, 824, 823, 822, 821, 820, 819, 818, 817, 816, 815, 814, 813, 812, 811,
    810, 809, 808, 807, 806, 805, 804, 803, 802, 801, 800, 799, 798, 797, 796,
    795, 794, 793, 792, 791, 790, 789, 788, 787, 786, 785, 784, 783, 782, 781,
    780, 779, 778, 777, 776, 775, 774, 773, 772, 771, 770, 769, 768, 767, 766,
    765, 764, 763, 762, 761, 760, 759, 758, 757, 756, 755, 754, 753, 752, 751,
    750, 749, 748, 747, 746, 745, 744, 743, 742, 741, 740, 739, 738, 737, 736,
    735, 734, 733, 732, 731, 730, 729, 728, 727, 726, 725, 724, 723, 722, 721,
    720, 719, 718, 717, 716, 715, 714, 713, 712, 711, 710, 709, 708, 707, 706,
    705, 704, 703, 702, 701, 700, 699, 698, 697, 696, 695, 694, 693, 692, 691,
    690, 689, 688, 687, 686, 685, 684, 683, 682, 681, 680, 679, 678, 677, 676,
    675, 674, 673, 672, 671, 670, 669, 668, 667, 666, 665, 664, 663, 662, 661,
    660, 659, 658, 657, 656, 655, 654, 653, 652, 651, 650, 649, 648, 647, 646,
    645, 644, 643, 642, 641, 640, 639, 638, 637, 636, 635, 634, 633, 632, 631,
    630, 629, 628, 627, 626, 625, 624, 623, 622, 621, 620, 619, 618, 617, 616,
    615, 614, 613, 612, 611, 610, 609, 608, 607, 606, 605, 604, 603, 602, 601,
    600, 599, 598, 597, 596, 595, 594, 593, 592, 591, 590, 589, 588, 587, 586,
    585, 584, 583, 582, 581, 580, 579, 578, 577, 576, 575, 574, 573, 572, 571,
    570, 569, 568, 567, 566, 565, 564, 563, 562, 561, 560, 559, 558, 557, 556,
    555, 554, 553, 552, 551, 550, 549, 548, 547, 546, 545, 544, 543, 542, 541,
    540, 539, 538, 537, 536, 535, 534, 533, 532, 531, 530, 529, 528, 527, 526,
    525, 524, 523, 522, 521, 520, 519, 518, 517, 516, 515, 514, 513, 512, 511,
    510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496,
    495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481,
    480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466,
    465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, 452, 451,
    450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436,
    435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423, 422, 421,
    420, 419, 418, 417, 416, 415, 414, 413, 412, 411, 410, 409, 408, 407, 406,
    405, 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, 392, 391,
    390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, 377, 376,
    375, 374, 373, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, 362, 361,
    360, 359, 358, 357, 356, 355, 354, 353, 352, 351, 350, 349, 348, 347, 346,
    345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331,
    330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316,
    315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301,
    300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286,
    285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271,
    270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256,
    255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241,
    240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226,
    225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211,
    210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196,
    195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181,
    180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166,
    165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151,
    150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136,
    135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121,
    120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106,
    105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88,
    87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69,
    68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50,
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
    30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12,
    11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

  static const creal_T reconVar1[1024] = { { 1.0,/* re */
      -1.0                             /* im */
    }, { 0.996932043237034,            /* re */
      -0.9999952938095762              /* im */
    }, { 0.9938641153508455,           /* re */
      -0.9999811752826011              /* im */
    }, { 0.9907962452179402,           /* re */
      -0.9999576445519639              /* im */
    }, { 0.9877284617142801,           /* re */
      -0.9999247018391445              /* im */
    }, { 0.9846607937150119,           /* re */
      -0.9998823474542126              /* im */
    }, { 0.9815932700941952,           /* re */
      -0.9998305817958234              /* im */
    }, { 0.9785259197245305,           /* re */
      -0.9997694053512153              /* im */
    }, { 0.9754587714770877,           /* re */
      -0.9996988186962042              /* im */
    }, { 0.9723918542210342,           /* re */
      -0.9996188224951786              /* im */
    }, { 0.9693251968233634,           /* re */
      -0.9995294175010931              /* im */
    }, { 0.9662588281486224,           /* re */
      -0.9994306045554617              /* im */
    }, { 0.9631927770586411,           /* re */
      -0.9993223845883495              /* im */
    }, { 0.9601270724122601,           /* re */
      -0.9992047586183639              /* im */
    }, { 0.9570617430650592,           /* re */
      -0.9990777277526454              /* im */
    }, { 0.9539968178690854,           /* re */
      -0.9989412931868569              /* im */
    }, { 0.950932325672582,            /* re */
      -0.9987954562051724              /* im */
    }, { 0.9478682953197167,           /* re */
      -0.9986402181802653              /* im */
    }, { 0.9448047556503101,           /* re */
      -0.9984755805732948              /* im */
    }, { 0.9417417354995643,           /* re */
      -0.9983015449338929              /* im */
    }, { 0.9386792636977914,           /* re */
      -0.9981181129001492              /* im */
    }, { 0.9356173690701426,           /* re */
      -0.997925286198596               /* im */
    }, { 0.932556080436336,            /* re */
      -0.9977230666441916              /* im */
    }, { 0.9294954266103861,           /* re */
      -0.9975114561403035              /* im */
    }, { 0.9264354364003325,           /* re */
      -0.9972904566786902              /* im */
    }, { 0.9233761386079685,           /* re */
      -0.997060070339483               /* im */
    }, { 0.9203175620285698,           /* re */
      -0.9968202992911657              /* im */
    }, { 0.9172597354506243,           /* re */
      -0.9965711457905548              /* im */
    }, { 0.9142026876555601,           /* re */
      -0.996312612182778               /* im */
    }, { 0.9111464474174754,           /* re */
      -0.996044700901252               /* im */
    }, { 0.9080910435028673,           /* re */
      -0.9957674144676598              /* im */
    }, { 0.905036504670361,            /* re */
      -0.9954807554919269              /* im */
    }, { 0.9019828596704393,           /* re */
      -0.9951847266721969              /* im */
    }, { 0.8989301372451721,           /* re */
      -0.9948793307948056              /* im */
    }, { 0.8958783661279455,           /* re */
      -0.9945645707342554              /* im */
    }, { 0.8928275750431911,           /* re */
      -0.9942404494531879              /* im */
    }, { 0.8897777927061169,           /* re */
      -0.9939069700023561              /* im */
    }, { 0.8867290478224357,           /* re */
      -0.9935641355205953              /* im */
    }, { 0.8836813690880952,           /* re */
      -0.9932119492347945              /* im */
    }, { 0.8806347851890086,           /* re */
      -0.9928504144598651              /* im */
    }, { 0.8775893248007838,           /* re */
      -0.99247953459871                /* im */
    }, { 0.8745450165884537,           /* re */
      -0.9920993131421918              /* im */
    }, { 0.8715018892062069,           /* re */
      -0.9917097536690995              /* im */
    }, { 0.8684599712971168,           /* re */
      -0.9913108598461154              /* im */
    }, { 0.8654192914928738,           /* re */
      -0.99090263542778                /* im */
    }, { 0.8623798784135139,           /* re */
      -0.9904850842564571              /* im */
    }, { 0.8593417606671507,           /* re */
      -0.9900582102622971              /* im */
    }, { 0.8563049668497056,           /* re */
      -0.9896220174632009              /* im */
    }, { 0.8532695255446383,           /* re */
      -0.989176509964781               /* im */
    }, { 0.8502354653226785,           /* re */
      -0.9887216919603238              /* im */
    }, { 0.8472028147415566,           /* re */
      -0.9882575677307495              /* im */
    }, { 0.8441716023457347,           /* re */
      -0.9877841416445722              /* im */
    }, { 0.8411418566661386,           /* re */
      -0.9873014181578584              /* im */
    }, { 0.8381136062198882,           /* re */
      -0.9868094018141855              /* im */
    }, { 0.8350868795100301,           /* re */
      -0.9863080972445987              /* im */
    }, { 0.8320617050252688,           /* re */
      -0.9857975091675675              /* im */
    }, { 0.8290381112396987,           /* re */
      -0.9852776423889412              /* im */
    }, { 0.8260161266125362,           /* re */
      -0.9847485018019042              /* im */
    }, { 0.8229957795878513,           /* re */
      -0.984210092386929               /* im */
    }, { 0.8199770985943005,           /* re */
      -0.9836624192117303              /* im */
    }, { 0.8169601120448591,           /* re */
      -0.9831054874312163              /* im */
    }, { 0.8139448483365533,           /* re */
      -0.9825393022874412              /* im */
    }, { 0.8109313358501938,           /* re */
      -0.9819638691095552              /* im */
    }, { 0.8079196029501076,           /* re */
      -0.9813791933137546              /* im */
    }, { 0.8049096779838718,           /* re */
      -0.9807852804032304              /* im */
    }, { 0.8019015892820465,           /* re */
      -0.9801821359681174              /* im */
    }, { 0.798895365157908,            /* re */
      -0.9795697656854405              /* im */
    }, { 0.7958910339071832,           /* re */
      -0.9789481753190622              /* im */
    }, { 0.7928886238077815,           /* re */
      -0.9783173707196277              /* im */
    }, { 0.7898881631195304,           /* re */
      -0.9776773578245099              /* im */
    }, { 0.7868896800839087,           /* re */
      -0.9770281426577544              /* im */
    }, { 0.7838932029237805,           /* re */
      -0.9763697313300211              /* im */
    }, { 0.7808987598431302,           /* re */
      -0.9757021300385286              /* im */
    }, { 0.7779063790267965,           /* re */
      -0.9750253450669941              /* im */
    }, { 0.7749160886402071,           /* re */
      -0.9743393827855759              /* im */
    }, { 0.7719279168291142,           /* re */
      -0.973644249650812               /* im */
    }, { 0.7689418917193289,           /* re */
      -0.9729399522055602              /* im */
    }, { 0.7659580414164566,           /* re */
      -0.9722264970789363              /* im */
    }, { 0.7629763940056328,           /* re */
      -0.9715038909862518              /* im */
    }, { 0.7599969775512585,           /* re */
      -0.9707721407289504              /* im */
    }, { 0.7570198200967362,           /* re */
      -0.970031253194544               /* im */
    }, { 0.7540449496642054,           /* re */
      -0.9692812353565485              /* im */
    }, { 0.7510723942542799,           /* re */
      -0.9685220942744173              /* im */
    }, { 0.748102181845783,            /* re */
      -0.9677538370934755              /* im */
    }, { 0.7451343403954854,           /* re */
      -0.9669764710448521              /* im */
    }, { 0.742168897837841,            /* re */
      -0.9661900034454125              /* im */
    }, { 0.7392058820847245,           /* re */
      -0.9653944416976894              /* im */
    }, { 0.7362453210251687,           /* re */
      -0.9645897932898128              /* im */
    }, { 0.7332872425251016,           /* re */
      -0.9637760657954398              /* im */
    }, { 0.7303316744270849,           /* re */
      -0.9629532668736839              /* im */
    }, { 0.727378644550051,            /* re */
      -0.9621214042690416              /* im */
    }, { 0.7244281806890418,           /* re */
      -0.9612804858113206              /* im */
    }, { 0.721480310614947,            /* re */
      -0.9604305194155658              /* im */
    }, { 0.7185350620742421,           /* re */
      -0.9595715130819845              /* im */
    }, { 0.7155924627887281,           /* re */
      -0.9587034748958716              /* im */
    }, { 0.7126525404552705,           /* re */
      -0.9578264130275329              /* im */
    }, { 0.7097153227455377,           /* re */
      -0.9569403357322088              /* im */
    }, { 0.7067808373057414,           /* re */
      -0.9560452513499964              /* im */
    }, { 0.7038491117563762,           /* re */
      -0.9551411683057708              /* im */
    }, { 0.7009201736919595,           /* re */
      -0.9542280951091057              /* im */
    }, { 0.6979940506807719,           /* re */
      -0.9533060403541939              /* im */
    }, { 0.6950707702645976,           /* re */
      -0.9523750127197659              /* im */
    }, { 0.6921503599584651,           /* re */
      -0.9514350209690083              /* im */
    }, { 0.6892328472503886,           /* re */
      -0.9504860739494817              /* im */
    }, { 0.6863182596011085,           /* re */
      -0.9495281805930367              /* im */
    }, { 0.6834066244438342,           /* re */
      -0.9485613499157303              /* im */
    }, { 0.6804979691839843,           /* re */
      -0.9475855910177411              /* im */
    }, { 0.6775923211989301,           /* re */
      -0.9466009130832835              /* im */
    }, { 0.6746897078377371,           /* re */
      -0.9456073253805213              /* im */
    }, { 0.6717901564209074,           /* re */
      -0.9446048372614803              /* im */
    }, { 0.6688936942401236,           /* re */
      -0.9435934581619604              /* im */
    }, { 0.6660003485579906,           /* re */
      -0.9425731976014469              /* im */
    }, { 0.66311014660778,             /* re */
      -0.9415440651830208              /* im */
    }, { 0.6602231155931731,           /* re */
      -0.9405060705932683              /* im */
    }, { 0.6573392826880056,           /* re */
      -0.9394592236021899              /* im */
    }, { 0.6544586750360109,           /* re */
      -0.9384035340631081              /* im */
    }, { 0.6515813197505654,           /* re */
      -0.937339011912575               /* im */
    }, { 0.6487072439144329,           /* re */
      -0.9362656671702783              /* im */
    }, { 0.6458364745795097,           /* re */
      -0.9351835099389476              /* im */
    }, { 0.6429690387665701,           /* re */
      -0.9340925504042589              /* im */
    }, { 0.6401049634650119,           /* re */
      -0.932992798834739               /* im */
    }, { 0.6372442756326028,           /* re */
      -0.9318842655816681              /* im */
    }, { 0.6343870021952261,           /* re */
      -0.9307669610789837              /* im */
    }, { 0.6315331700466277,           /* re */
      -0.9296408958431812              /* im */
    }, { 0.6286828060481625,           /* re */
      -0.9285060804732156              /* im */
    }, { 0.625835937028542,            /* re */
      -0.9273625256504011              /* im */
    }, { 0.6229925897835817,           /* re */
      -0.9262102421383114              /* im */
    }, { 0.6201527910759488,           /* re */
      -0.9250492407826776              /* im */
    }, { 0.6173165676349102,           /* re */
      -0.9238795325112867              /* im */
    }, { 0.6144839461560812,           /* re */
      -0.9227011283338786              /* im */
    }, { 0.6116549533011737,           /* re */
      -0.9215140393420419              /* im */
    }, { 0.6088296156977462,           /* re */
      -0.9203182767091106              /* im */
    }, { 0.6060079599389518,           /* re */
      -0.9191138516900578              /* im */
    }, { 0.6031900125832896,           /* re */
      -0.9179007756213905              /* im */
    }, { 0.6003758001543532,           /* re */
      -0.9166790599210427              /* im */
    }, { 0.5975653491405816,           /* re */
      -0.9154487160882678              /* im */
    }, { 0.5947586859950101,           /* re */
      -0.9142097557035307              /* im */
    }, { 0.5919558371350213,           /* re */
      -0.9129621904283982              /* im */
    }, { 0.5891568289420961,           /* re */
      -0.9117060320054299              /* im */
    }, { 0.5863616877615655,           /* re */
      -0.9104412922580672              /* im */
    }, { 0.5835704399023629,           /* re */
      -0.9091679830905224              /* im */
    }, { 0.5807831116367761,           /* re */
      -0.9078861164876663              /* im */
    }, { 0.5779997292002004,           /* re */
      -0.9065957045149153              /* im */
    }, { 0.5752203187908912,           /* re */
      -0.9052967593181188              /* im */
    }, { 0.5724449065697179,           /* re */
      -0.9039892931234433              /* im */
    }, { 0.5696735186599173,           /* re */
      -0.9026733182372588              /* im */
    }, { 0.5669061811468481,           /* re */
      -0.901348847046022               /* im */
    }, { 0.5641429200777446,           /* re */
      -0.9000158920161602              /* im */
    }, { 0.5613837614614723,           /* re */
      -0.8986744656939538              /* im */
    }, { 0.5586287312682834,           /* re */
      -0.8973245807054183              /* im */
    }, { 0.5558778554295708,           /* re */
      -0.8959662497561852              /* im */
    }, { 0.5531311598376258,           /* re */
      -0.8945994856313827              /* im */
    }, { 0.5503886703453935,           /* re */
      -0.8932243011955153              /* im */
    }, { 0.5476504127662292,           /* re */
      -0.8918407093923427              /* im */
    }, { 0.5449164128736561,           /* re */
      -0.8904487232447579              /* im */
    }, { 0.5421866964011228,           /* re */
      -0.8890483558546646              /* im */
    }, { 0.53946128904176,             /* re */
      -0.8876396204028539              /* im */
    }, { 0.5367402164481399,           /* re */
      -0.8862225301488806              /* im */
    }, { 0.5340235042320338,           /* re */
      -0.8847970984309378              /* im */
    }, { 0.531311177964172,            /* re */
      -0.8833633386657316              /* im */
    }, { 0.5286032631740023,           /* re */
      -0.881921264348355               /* im */
    }, { 0.52589978534945,             /* re */
      -0.8804708890521608              /* im */
    }, { 0.5232007699366779,           /* re */
      -0.8790122264286335              /* im */
    }, { 0.520506242339847,            /* re */
      -0.8775452902072614              /* im */
    }, { 0.5178162279208773,           /* re */
      -0.8760700941954066              /* im */
    }, { 0.515130751999209,            /* re */
      -0.8745866522781761              /* im */
    }, { 0.512449839851564,            /* re */
      -0.8730949784182901              /* im */
    }, { 0.5097735167117088,           /* re */
      -0.8715950866559511              /* im */
    }, { 0.507101807770216,            /* re */
      -0.8700869911087115              /* im */
    }, { 0.5044347381742275,           /* re */
      -0.8685707059713409              /* im */
    }, { 0.5017723330272181,           /* re */
      -0.8670462455156926              /* im */
    }, { 0.4991146173887593,           /* re */
      -0.8655136240905691              /* im */
    }, { 0.4964616162742824,           /* re */
      -0.8639728561215867              /* im */
    }, { 0.49381335465484477,          /* re */
      -0.8624239561110405              /* im */
    }, { 0.491169857456893,            /* re */
      -0.8608669386377673              /* im */
    }, { 0.4885311495620297,           /* re */
      -0.8593018183570085              /* im */
    }, { 0.48589725580677834,          /* re */
      -0.8577286100002721              /* im */
    }, { 0.4832682009823501,           /* re */
      -0.8561473283751945              /* im */
    }, { 0.48064400983441036,          /* re */
      -0.8545579883654005              /* im */
    }, { 0.4780247070628456,           /* re */
      -0.8529606049303636              /* im */
    }, { 0.47541031732153105,          /* re */
      -0.8513551931052652              /* im */
    }, { 0.4728008652180987,           /* re */
      -0.8497417680008525              /* im */
    }, { 0.4701963753137054,           /* re */
      -0.8481203448032972              /* im */
    }, { 0.4675968721228021,           /* re */
      -0.8464909387740521              /* im */
    }, { 0.46500238011290285,          /* re */
      -0.8448535652497071              /* im */
    }, { 0.4624129237043546,           /* re */
      -0.8432082396418454              /* im */
    }, { 0.45982852727010715,          /* re */
      -0.8415549774368984              /* im */
    }, { 0.4572492151354841,           /* re */
      -0.8398937941959995              /* im */
    }, { 0.45467501157795354,          /* re */
      -0.8382247055548381              /* im */
    }, { 0.4521059408268998,           /* re */
      -0.836547727223512               /* im */
    }, { 0.4495420270633952,           /* re */
      -0.83486287498638                /* im */
    }, { 0.44698329441997253,          /* re */
      -0.8331701647019132              /* im */
    }, { 0.4444297669803978,           /* re */
      -0.8314696123025452              /* im */
    }, { 0.4418814687794439,           /* re */
      -0.829761233794523               /* im */
    }, { 0.43933842380266397,          /* re */
      -0.8280450452577558              /* im */
    }, { 0.4368006559861659,           /* re */
      -0.8263210628456635              /* im */
    }, { 0.4342681892163869,           /* re */
      -0.8245893027850253              /* im */
    }, { 0.4317410473298685,           /* re */
      -0.8228497813758264              /* im */
    }, { 0.42921925411303274,          /* re */
      -0.8211025149911046              /* im */
    }, { 0.4267028333019578,           /* re */
      -0.819347520076797               /* im */
    }, { 0.42419180858215466,          /* re */
      -0.8175848131515837              /* im */
    }, { 0.4216862035883444,           /* re */
      -0.8158144108067338              /* im */
    }, { 0.4191860419042355,           /* re */
      -0.8140363297059484              /* im */
    }, { 0.4166913470623017,           /* re */
      -0.8122505865852039              /* im */
    }, { 0.41420214254356114,          /* re */
      -0.8104571982525948              /* im */
    }, { 0.4117184517773548,           /* re */
      -0.808656181588175               /* im */
    }, { 0.40924029814112584,          /* re */
      -0.8068475535437993              /* im */
    }, { 0.4067677049602002,           /* re */
      -0.8050313311429637              /* im */
    }, { 0.40430069550756664,          /* re */
      -0.8032075314806449              /* im */
    }, { 0.4018392930036576,           /* re */
      -0.8013761717231402              /* im */
    }, { 0.399383520616131,            /* re */
      -0.799537269107905               /* im */
    }, { 0.39693340145965184,          /* re */
      -0.7976908409433912              /* im */
    }, { 0.39448895859567445,          /* re */
      -0.7958369046088836              /* im */
    }, { 0.39205021503222637,          /* re */
      -0.7939754775543372              /* im */
    }, { 0.3896171937236905,           /* re */
      -0.7921065773002124              /* im */
    }, { 0.3871899175705903,           /* re */
      -0.79023022143731                /* im */
    }, { 0.3847684094193732,           /* re */
      -0.7883464276266063              /* im */
    }, { 0.38235269206219613,          /* re */
      -0.7864552135990858              /* im */
    }, { 0.3799427882367109,           /* re */
      -0.7845565971555752              /* im */
    }, { 0.37753872062585003,          /* re */
      -0.7826505961665757              /* im */
    }, { 0.37514051185761366,          /* re */
      -0.7807372285720945              /* im */
    }, { 0.3727481845048559,           /* re */
      -0.778816512381476               /* im */
    }, { 0.370361761085073,            /* re */
      -0.7768884656732324              /* im */
    }, { 0.36798126406019094,          /* re */
      -0.7749531065948739              /* im */
    }, { 0.3656067158363545,           /* re */
      -0.773010453362737               /* im */
    }, { 0.3632381387637158,           /* re */
      -0.7710605242618138              /* im */
    }, { 0.36087555513622427,          /* re */
      -0.7691033376455797              /* im */
    }, { 0.35851898719141695,          /* re */
      -0.7671389119358204              /* im */
    }, { 0.3561684571102086,           /* re */
      -0.765167265622459               /* im */
    }, { 0.3538239870166837,           /* re */
      -0.7631884172633813              /* im */
    }, { 0.35148559897788756,          /* re */
      -0.7612023854842618              /* im */
    }, { 0.349153315003619,            /* re */
      -0.759209188978388               /* im */
    }, { 0.34682715704622324,          /* re */
      -0.7572088465064846              /* im */
    }, { 0.34450714700038465,          /* re */
      -0.7552013768965365              /* im */
    }, { 0.34219330670292136,          /* re */
      -0.7531867990436125              /* im */
    }, { 0.3398856579325795,           /* re */
      -0.7511651319096864              /* im */
    }, { 0.3375842224098282,           /* re */
      -0.7491363945234594              /* im */
    }, { 0.3352890217966552,           /* re */
      -0.7471006059801801              /* im */
    }, { 0.33300007769636253,          /* re */
      -0.745057785441466               /* im */
    }, { 0.330717411653364,            /* re */
      -0.7430079521351217              /* im */
    }, { 0.32844104515298167,          /* re */
      -0.7409511253549592              /* im */
    }, { 0.32617099962124396,          /* re */
      -0.7388873244606151              /* im */
    }, { 0.3239072964246841,           /* re */
      -0.7368165688773698              /* im */
    }, { 0.32164995687013853,          /* re */
      -0.7347388780959635              /* im */
    }, { 0.319399002204547,            /* re */
      -0.7326542716724128              /* im */
    }, { 0.3171544536147519,           /* re */
      -0.7305627692278276              /* im */
    }, { 0.31491633222729964,          /* re */
      -0.7284643904482252              /* im */
    }, { 0.31268465910824095,          /* re */
      -0.726359155084346               /* im */
    }, { 0.31045945526293317,          /* re */
      -0.724247082951467               /* im */
    }, { 0.30824074163584225,          /* re */
      -0.7221281939292153              /* im */
    }, { 0.3060285391103461,           /* re */
      -0.7200025079613817              /* im */
    }, { 0.303822868508537,            /* re */
      -0.7178700450557317              /* im */
    }, { 0.3016237505910271,           /* re */
      -0.7157308252838186              /* im */
    }, { 0.29943120605675166,          /* re */
      -0.7135848687807935              /* im */
    }, { 0.2972452555427747,           /* re */
      -0.7114321957452164              /* im */
    }, { 0.2950659196240951,           /* re */
      -0.7092728264388657              /* im */
    }, { 0.2928932188134524,           /* re */
      -0.7071067811865476              /* im */
    }, { 0.2907271735611343,           /* re */
      -0.7049340803759049              /* im */
    }, { 0.28856780425478357,          /* re */
      -0.7027547444572253              /* im */
    }, { 0.2864151312192065,           /* re */
      -0.7005687939432483              /* im */
    }, { 0.2842691747161814,           /* re */
      -0.6983762494089729              /* im */
    }, { 0.2821299549442683,           /* re */
      -0.696177131491463               /* im */
    }, { 0.27999749203861835,          /* re */
      -0.6939714608896539              /* im */
    }, { 0.27787180607078465,          /* re */
      -0.6917592583641577              /* im */
    }, { 0.275752917048533,            /* re */
      -0.6895405447370668              /* im */
    }, { 0.273640844915654,            /* re */
      -0.687315340891759               /* im */
    }, { 0.2715356095517748,           /* re */
      -0.6850836677727004              /* im */
    }, { 0.2694372307721724,           /* re */
      -0.6828455463852481              /* im */
    }, { 0.2673457283275872,           /* re */
      -0.680600997795453               /* im */
    }, { 0.2652611219040365,           /* re */
      -0.6783500431298615              /* im */
    }, { 0.2631834311226302,           /* re */
      -0.6760927035753159              /* im */
    }, { 0.2611126755393849,           /* re */
      -0.673829000378756               /* im */
    }, { 0.2590488746450408,           /* re */
      -0.6715589548470183              /* im */
    }, { 0.2569920478648783,           /* re */
      -0.669282588346636               /* im */
    }, { 0.25494221455853405,          /* re */
      -0.6669999223036375              /* im */
    }, { 0.25289939401981987,          /* re */
      -0.6647109782033448              /* im */
    }, { 0.25086360547654063,          /* re */
      -0.6624157775901718              /* im */
    }, { 0.24883486809031363,          /* re */
      -0.6601143420674205              /* im */
    }, { 0.24681320095638748,          /* re */
      -0.6578066932970786              /* im */
    }, { 0.24479862310346345,          /* re */
      -0.6554928529996153              /* im */
    }, { 0.24279115349351543,          /* re */
      -0.6531728429537768              /* im */
    }, { 0.24079081102161204,          /* re */
      -0.650846684996381               /* im */
    }, { 0.23879761451573822,          /* re */
      -0.6485144010221124              /* im */
    }, { 0.23681158273661873,          /* re */
      -0.6461760129833163              /* im */
    }, { 0.23483273437754104,          /* re */
      -0.6438315428897914              /* im */
    }, { 0.2328610880641796,           /* re */
      -0.641481012808583               /* im */
    }, { 0.2308966623544203,           /* re */
      -0.6391244448637757              /* im */
    }, { 0.22893947573818618,          /* re */
      -0.6367618612362842              /* im */
    }, { 0.226989546637263,            /* re */
      -0.6343932841636455              /* im */
    }, { 0.22504689340512607,          /* re */
      -0.6320187359398091              /* im */
    }, { 0.22311153432676756,          /* re */
      -0.629638238914927               /* im */
    }, { 0.22118348761852402,          /* re */
      -0.6272518154951441              /* im */
    }, { 0.2192627714279055,           /* re */
      -0.6248594881423863              /* im */
    }, { 0.21734940383342427,          /* re */
      -0.62246127937415                /* im */
    }, { 0.21544340284442476,          /* re */
      -0.6200572117632891              /* im */
    }, { 0.21354478640091423,          /* re */
      -0.6176473079378039              /* im */
    }, { 0.21165357237339366,          /* re */
      -0.6152315905806268              /* im */
    }, { 0.20976977856268997,          /* re */
      -0.6128100824294097              /* im */
    }, { 0.2078934226997876,           /* re */
      -0.6103828062763095              /* im */
    }, { 0.20602452244566283,          /* re */
      -0.6079497849677736              /* im */
    }, { 0.20416309539111643,          /* re */
      -0.6055110414043255              /* im */
    }, { 0.20230915905660884,          /* re */
      -0.6030665985403482              /* im */
    }, { 0.200462730892095,            /* re */
      -0.600616479383869               /* im */
    }, { 0.19862382827685976,          /* re */
      -0.5981607069963424              /* im */
    }, { 0.19679246851935506,          /* re */
      -0.5956993044924334              /* im */
    }, { 0.19496866885703634,          /* re */
      -0.5932322950397998              /* im */
    }, { 0.19315244645620067,          /* re */
      -0.5907597018588742              /* im */
    }, { 0.19134381841182502,          /* re */
      -0.5882815482226452              /* im */
    }, { 0.18954280174740523,          /* re */
      -0.5857978574564389              /* im */
    }, { 0.18774941341479612,          /* re */
      -0.5833086529376983              /* im */
    }, { 0.1859636702940516,           /* re */
      -0.5808139580957645              /* im */
    }, { 0.18418558919326622,          /* re */
      -0.5783137964116556              /* im */
    }, { 0.1824151868484163,           /* re */
      -0.5758081914178453              /* im */
    }, { 0.180652479923203,            /* re */
      -0.5732971666980422              /* im */
    }, { 0.17889748500889535,          /* re */
      -0.5707807458869673              /* im */
    }, { 0.17715021862417357,          /* re */
      -0.5682589526701315              /* im */
    }, { 0.1754106972149747,           /* re */
      -0.5657318107836131              /* im */
    }, { 0.17367893715433647,          /* re */
      -0.5631993440138341              /* im */
    }, { 0.1719549547422442,           /* re */
      -0.560661576197336               /* im */
    }, { 0.17023876620547695,          /* re */
      -0.5581185312205561              /* im */
    }, { 0.16853038769745476,          /* re */
      -0.5555702330196022              /* im */
    }, { 0.16682983529808681,          /* re */
      -0.5530167055800275              /* im */
    }, { 0.16513712501362,             /* re */
      -0.5504579729366048              /* im */
    }, { 0.163452272776488,            /* re */
      -0.5478940591731002              /* im */
    }, { 0.16177529444516192,          /* re */
      -0.5453249884220465              /* im */
    }, { 0.16010620580400048,          /* re */
      -0.5427507848645159              /* im */
    }, { 0.15844502256310156,          /* re */
      -0.5401714727298929              /* im */
    }, { 0.15679176035815456,          /* re */
      -0.5375870762956454              /* im */
    }, { 0.15514643475029288,          /* re */
      -0.5349976198870972              /* im */
    }, { 0.15350906122594787,          /* re */
      -0.5324031278771979              /* im */
    }, { 0.15187965519670277,          /* re */
      -0.5298036246862946              /* im */
    }, { 0.15025823199914745,          /* re */
      -0.5271991347819013              /* im */
    }, { 0.1486448068947348,           /* re */
      -0.524589682678469               /* im */
    }, { 0.14703939506963637,          /* re */
      -0.5219752929371544              /* im */
    }, { 0.14544201163459947,          /* re */
      -0.5193559901655896              /* im */
    }, { 0.14385267162480553,          /* re */
      -0.5167317990176499              /* im */
    }, { 0.14227138999972788,          /* re */
      -0.5141027441932217              /* im */
    }, { 0.14069818164299153,          /* re */
      -0.5114688504379703              /* im */
    }, { 0.1391330613622327,           /* re */
      -0.508830142543107               /* im */
    }, { 0.1375760438889595,           /* re */
      -0.5061866453451552              /* im */
    }, { 0.1360271438784133,           /* re */
      -0.5035383837257176              /* im */
    }, { 0.1344863759094309,           /* re */
      -0.5008853826112407              /* im */
    }, { 0.13295375448430735,          /* re */
      -0.4982276669727818              /* im */
    }, { 0.1314292940286591,           /* re */
      -0.49556526182577254             /* im */
    }, { 0.12991300889128854,          /* re */
      -0.49289819222978404             /* im */
    }, { 0.1284049133440489,           /* re */
      -0.49022648328829116             /* im */
    }, { 0.1269050215817099,           /* re */
      -0.487550160148436               /* im */
    }, { 0.1254133477218239,           /* re */
      -0.48486924800079106             /* im */
    }, { 0.1239299058045934,           /* re */
      -0.4821837720791227              /* im */
    }, { 0.12245470979273865,          /* re */
      -0.47949375766015295             /* im */
    }, { 0.12098777357136647,          /* re */
      -0.4767992300633221              /* im */
    }, { 0.11952911094783925,          /* re */
      -0.47410021465054997             /* im */
    }, { 0.11807873565164495,          /* re */
      -0.47139673682599764             /* im */
    }, { 0.11663666133426842,          /* re */
      -0.46868882203582796             /* im */
    }, { 0.11520290156906221,          /* re */
      -0.4659764957679662              /* im */
    }, { 0.11377746985111936,          /* re */
      -0.46325978355186015             /* im */
    }, { 0.11236037959714607,          /* re */
      -0.46053871095824                /* im */
    }, { 0.11095164414533543,          /* re */
      -0.4578133035988772              /* im */
    }, { 0.10955127675524212,          /* re */
      -0.45508358712634384             /* im */
    }, { 0.10815929060765728,          /* re */
      -0.4523495872337709              /* im */
    }, { 0.10677569880448468,          /* re */
      -0.44961132965460654             /* im */
    }, { 0.1054005143686173,           /* re */
      -0.44686884016237416             /* im */
    }, { 0.10403375024381478,          /* re */
      -0.4441221445704292              /* im */
    }, { 0.10267541929458168,          /* re */
      -0.44137126873171667             /* im */
    }, { 0.10132553430604618,          /* re */
      -0.43861623853852766             /* im */
    }, { 0.09998410798383983,          /* re */
      -0.4358570799222555              /* im */
    }, { 0.09865115295397797,          /* re */
      -0.43309381885315196             /* im */
    }, { 0.09732668176274117,          /* re */
      -0.4303264813400826              /* im */
    }, { 0.09601070687655666,          /* re */
      -0.4275550934302821              /* im */
    }, { 0.09470324068188118,          /* re */
      -0.4247796812091088              /* im */
    }, { 0.09340429548508467,          /* re */
      -0.4220002707997997              /* im */
    }, { 0.09211388351233374,          /* re */
      -0.4192168883632239              /* im */
    }, { 0.09083201690947762,          /* re */
      -0.41642956009763715             /* im */
    }, { 0.08955870774193275,          /* re */
      -0.4136383122384345              /* im */
    }, { 0.08829396799457012,          /* re */
      -0.4108431710579039              /* im */
    }, { 0.08703780957160179,          /* re */
      -0.4080441628649787              /* im */
    }, { 0.08579024429646931,          /* re */
      -0.40524131400498986             /* im */
    }, { 0.08455128391173217,          /* re */
      -0.40243465085941843             /* im */
    }, { 0.0833209400789573,           /* re */
      -0.3996241998456468              /* im */
    }, { 0.0820992243786095,           /* re */
      -0.3968099874167103              /* im */
    }, { 0.08088614830994223,          /* re */
      -0.3939920400610481              /* im */
    }, { 0.0796817232908894,           /* re */
      -0.39117038430225387             /* im */
    }, { 0.0784859606579581,           /* re */
      -0.38834504669882625             /* im */
    }, { 0.07729887166612137,          /* re */
      -0.38551605384391885             /* im */
    }, { 0.07612046748871326,          /* re */
      -0.3826834323650898              /* im */
    }, { 0.07495075921732242,          /* re */
      -0.37984720892405116             /* im */
    }, { 0.07378975786168862,          /* re */
      -0.37700741021641826             /* im */
    }, { 0.07263747434959889,          /* re */
      -0.37416406297145793             /* im */
    }, { 0.07149391952678441,          /* re */
      -0.3713171939518375              /* im */
    }, { 0.07035910415681879,          /* re */
      -0.3684668299533723              /* im */
    }, { 0.06923303892101629,          /* re */
      -0.36561299780477385             /* im */
    }, { 0.06811573441833185,          /* re */
      -0.3627557243673972              /* im */
    }, { 0.06700720116526104,          /* re */
      -0.3598950365349881              /* im */
    }, { 0.06590744959574113,          /* re */
      -0.35703096123343                /* im */
    }, { 0.06481649006105239,          /* re */
      -0.35416352542049034             /* im */
    }, { 0.06373433282972174,          /* re */
      -0.3512927560855671              /* im */
    }, { 0.06266098808742504,          /* re */
      -0.34841868024943456             /* im */
    }, { 0.06159646593689194,          /* re */
      -0.3455413249639891              /* im */
    }, { 0.06054077639781008,          /* re */
      -0.3426607173119944              /* im */
    }, { 0.059493929406731705,         /* re */
      -0.33977688440682685             /* im */
    }, { 0.058455934816979194,         /* re */
      -0.33688985339222005             /* im */
    }, { 0.057426802398553134,         /* re */
      -0.3339996514420094              /* im */
    }, { 0.056406541838039614,         /* re */
      -0.33110630575987643             /* im */
    }, { 0.05539516273851974,          /* re */
      -0.3282098435790925              /* im */
    }, { 0.05439267461947872,          /* re */
      -0.3253102921622629              /* im */
    }, { 0.053399086916716465,         /* re */
      -0.32240767880106985             /* im */
    }, { 0.05241440898225891,          /* re */
      -0.3195020308160157              /* im */
    }, { 0.05143865008426973,          /* re */
      -0.31659337555616585             /* im */
    }, { 0.050471819406963325,         /* re */
      -0.3136817403988915              /* im */
    }, { 0.0495139260505183,           /* re */
      -0.3107671527496115              /* im */
    }, { 0.04856497903099166,          /* re */
      -0.30784964004153487             /* im */
    }, { 0.04762498728023412,          /* re */
      -0.3049292297354024              /* im */
    }, { 0.04669395964580614,          /* re */
      -0.3020059493192281              /* im */
    }, { 0.04577190489089433,          /* re */
      -0.2990798263080405              /* im */
    }, { 0.04485883169422922,          /* re */
      -0.2961508882436238              /* im */
    }, { 0.043954748650003594,         /* re */
      -0.29321916269425863             /* im */
    }, { 0.043059664267791176,         /* re */
      -0.29028467725446233             /* im */
    }, { 0.04217358697246709,          /* re */
      -0.2873474595447295              /* im */
    }, { 0.0412965251041284,           /* re */
      -0.2844075372112719              /* im */
    }, { 0.04042848691801548,          /* re */
      -0.28146493792575794             /* im */
    }, { 0.03956948058443421,          /* re */
      -0.27851968938505306             /* im */
    }, { 0.03871951418867936,          /* re */
      -0.27557181931095814             /* im */
    }, { 0.03787859573095842,          /* re */
      -0.272621355449949               /* im */
    }, { 0.03704673312631612,          /* re */
      -0.2696683255729151              /* im */
    }, { 0.03622393420456016,          /* re */
      -0.26671275747489837             /* im */
    }, { 0.03541020671018724,          /* re */
      -0.26375467897483135             /* im */
    }, { 0.0346055583023106,           /* re */
      -0.2607941179152755              /* im */
    }, { 0.033809996554587496,         /* re */
      -0.257831102162159               /* im */
    }, { 0.03302352895514793,          /* re */
      -0.25486565960451457             /* im */
    }, { 0.03224616290652449,          /* re */
      -0.25189781815421697             /* im */
    }, { 0.03147790572558273,          /* re */
      -0.24892760574572015             /* im */
    }, { 0.03071876464345147,          /* re */
      -0.2459550503357946              /* im */
    }, { 0.029968746805456026,         /* re */
      -0.24298017990326387             /* im */
    }, { 0.02922785927104965,          /* re */
      -0.2400030224487415              /* im */
    }, { 0.028496109013748216,         /* re */
      -0.2370236059943672              /* im */
    }, { 0.02777350292106373,          /* re */
      -0.23404195858354343             /* im */
    }, { 0.027060047794439823,         /* re */
      -0.2310581082806711              /* im */
    }, { 0.026355750349188023,         /* re */
      -0.22807208317088573             /* im */
    }, { 0.025660617214424142,         /* re */
      -0.22508391135979283             /* im */
    }, { 0.02497465493300588,          /* re */
      -0.2220936209732035              /* im */
    }, { 0.02429786996147143,          /* re */
      -0.2191012401568698              /* im */
    }, { 0.02363026866997886,          /* re */
      -0.21610679707621952             /* im */
    }, { 0.022971857342245605,         /* re */
      -0.21311031991609136             /* im */
    }, { 0.02232264217549007,          /* re */
      -0.2101118368804696              /* im */
    }, { 0.021682629280372345,         /* re */
      -0.20711137619221856             /* im */
    }, { 0.021051824680937803,         /* re */
      -0.20410896609281687             /* im */
    }, { 0.02043023431455948,          /* re */
      -0.2011046348420919              /* im */
    }, { 0.01981786403188257,          /* re */
      -0.19809841071795356             /* im */
    }, { 0.01921471959676957,          /* re */
      -0.19509032201612825             /* im */
    }, { 0.01862080668624544,          /* re */
      -0.19208039704989244             /* im */
    }, { 0.018036130890444757,         /* re */
      -0.1890686641498062              /* im */
    }, { 0.01746069771255876,          /* re */
      -0.18605515166344663             /* im */
    }, { 0.016894512568783715,         /* re */
      -0.18303988795514095             /* im */
    }, { 0.016337580788269745,         /* re */
      -0.18002290140569951             /* im */
    }, { 0.015789907613070975,         /* re */
      -0.17700422041214875             /* im */
    }, { 0.015251498198095792,         /* re */
      -0.17398387338746382             /* im */
    }, { 0.014722357611058778,         /* re */
      -0.17096188876030122             /* im */
    }, { 0.014202490832432524,         /* re */
      -0.16793829497473117             /* im */
    }, { 0.01369190275540133,          /* re */
      -0.16491312048996992             /* im */
    }, { 0.013190598185814473,         /* re */
      -0.16188639378011183             /* im */
    }, { 0.012698581842141565,         /* re */
      -0.15885814333386145             /* im */
    }, { 0.012215858355427822,         /* re */
      -0.15582839765426523             /* im */
    }, { 0.011742432269250536,         /* re */
      -0.15279718525844344             /* im */
    }, { 0.011278308039676221,         /* re */
      -0.1497645346773215              /* im */
    }, { 0.010823490035218986,         /* re */
      -0.14673047445536175             /* im */
    }, { 0.010377982536799113,         /* re */
      -0.14369503315029447             /* im */
    }, { 0.009941789737702877,         /* re */
      -0.1406582393328492              /* im */
    }, { 0.009514915743542907,         /* re */
      -0.13762012158648604             /* im */
    }, { 0.00909736457221999,          /* re */
      -0.13458070850712617             /* im */
    }, { 0.008689140153884556,         /* re */
      -0.13154002870288312             /* im */
    }, { 0.008290246330900475,         /* re */
      -0.12849811079379317             /* im */
    }, { 0.007900686857808203,         /* re */
      -0.12545498341154623             /* im */
    }, { 0.007520465401290033,         /* re */
      -0.1224106751992162              /* im */
    }, { 0.007149585540134895,         /* re */
      -0.11936521481099135             /* im */
    }, { 0.0067880507652055,           /* re */
      -0.11631863091190475             /* im */
    }, { 0.006435864479404696,         /* re */
      -0.11327095217756435             /* im */
    }, { 0.0060930299976439395,        /* re */
      -0.11022220729388306             /* im */
    }, { 0.005759550546812098,         /* re */
      -0.10717242495680884             /* im */
    }, { 0.005435429265744585,         /* re */
      -0.10412163387205459             /* im */
    }, { 0.005120669205194384,         /* re */
      -0.10106986275482782             /* im */
    }, { 0.004815273327803071,         /* re */
      -0.0980171403295606              /* im */
    }, { 0.0045192445080730614,        /* re */
      -0.09496349532963899             /* im */
    }, { 0.004232585532340183,         /* re */
      -0.09190895649713272             /* im */
    }, { 0.003955299098748033,         /* re */
      -0.0888535525825246              /* im */
    }, { 0.0036873878172219987,        /* re */
      -0.0857973123444399              /* im */
    }, { 0.0034288542094451646,        /* re */
      -0.08274026454937569             /* im */
    }, { 0.003179700708834332,         /* re */
      -0.07968243797143013             /* im */
    }, { 0.0029399296605170377,        /* re */
      -0.07662386139203149             /* im */
    }, { 0.002709543321309793,         /* re */
      -0.07356456359966743             /* im */
    }, { 0.002488543859696546,         /* re */
      -0.07050457338961386             /* im */
    }, { 0.0022769333558083638,        /* re */
      -0.06744391956366405             /* im */
    }, { 0.0020747138014040045,        /* re */
      -0.06438263092985747             /* im */
    }, { 0.0018818870998508208,        /* re */
      -0.06132073630220858             /* im */
    }, { 0.0016984550661071074,        /* re */
      -0.05825826450043575             /* im */
    }, { 0.0015244194267052258,        /* re */
      -0.05519524434968994             /* im */
    }, { 0.0013597818197347289,        /* re */
      -0.052131704680283324            /* im */
    }, { 0.001204543794827595,         /* re */
      -0.049067674327418015            /* im */
    }, { 0.0010587068131431288,        /* re */
      -0.04600318213091462             /* im */
    }, { 0.0009222722473546385,        /* re */
      -0.04293825693494082             /* im */
    }, { 0.0007952413816361137,        /* re */
      -0.03987292758773981             /* im */
    }, { 0.0006776154116504562,        /* re */
      -0.03680722294135883             /* im */
    }, { 0.0005693954445382676,        /* re */
      -0.03374117185137758             /* im */
    }, { 0.00047058249890685744,       /* re */
      -0.030674803176636626            /* im */
    }, { 0.0003811775048213617,        /* re */
      -0.02760814577896574             /* im */
    }, { 0.00030118130379575003,       /* re */
      -0.024541228522912288            /* im */
    }, { 0.00023059464878472102,       /* re */
      -0.021474080275469508            /* im */
    }, { 0.0001694182041765968,        /* re */
      -0.01840672990580482             /* im */
    }, { 0.00011765254578743889,       /* re */
      -0.0153392062849881              /* im */
    }, { 7.529816085549701E-5,         /* re */
      -0.012271538285719925            /* im */
    }, { 4.235544803610214E-5,         /* re */
      -0.00920375478205982             /* im */
    }, { 1.882471739889091E-5,         /* re */
      -0.006135884649154475            /* im */
    }, { 4.70619042380882E-6,          /* re */
      -0.003067956762965976            /* im */
    }, { 0.0,                          /* re */
      -0.0                             /* im */
    }, { 4.70619042380882E-6,          /* re */
      0.003067956762965976             /* im */
    }, { 1.882471739889091E-5,         /* re */
      0.006135884649154475             /* im */
    }, { 4.235544803610214E-5,         /* re */
      0.00920375478205982              /* im */
    }, { 7.529816085549701E-5,         /* re */
      0.012271538285719925             /* im */
    }, { 0.00011765254578743889,       /* re */
      0.0153392062849881               /* im */
    }, { 0.0001694182041765968,        /* re */
      0.01840672990580482              /* im */
    }, { 0.00023059464878472102,       /* re */
      0.021474080275469508             /* im */
    }, { 0.00030118130379575003,       /* re */
      0.024541228522912288             /* im */
    }, { 0.0003811775048213617,        /* re */
      0.02760814577896574              /* im */
    }, { 0.00047058249890685744,       /* re */
      0.030674803176636626             /* im */
    }, { 0.0005693954445382676,        /* re */
      0.03374117185137758              /* im */
    }, { 0.0006776154116504562,        /* re */
      0.03680722294135883              /* im */
    }, { 0.0007952413816361137,        /* re */
      0.03987292758773981              /* im */
    }, { 0.0009222722473546385,        /* re */
      0.04293825693494082              /* im */
    }, { 0.0010587068131431288,        /* re */
      0.04600318213091462              /* im */
    }, { 0.001204543794827595,         /* re */
      0.049067674327418015             /* im */
    }, { 0.0013597818197347289,        /* re */
      0.052131704680283324             /* im */
    }, { 0.0015244194267052258,        /* re */
      0.05519524434968994              /* im */
    }, { 0.0016984550661071074,        /* re */
      0.05825826450043575              /* im */
    }, { 0.0018818870998508208,        /* re */
      0.06132073630220858              /* im */
    }, { 0.0020747138014040045,        /* re */
      0.06438263092985747              /* im */
    }, { 0.0022769333558083638,        /* re */
      0.06744391956366405              /* im */
    }, { 0.002488543859696546,         /* re */
      0.07050457338961386              /* im */
    }, { 0.002709543321309793,         /* re */
      0.07356456359966743              /* im */
    }, { 0.0029399296605170377,        /* re */
      0.07662386139203149              /* im */
    }, { 0.003179700708834332,         /* re */
      0.07968243797143013              /* im */
    }, { 0.0034288542094451646,        /* re */
      0.08274026454937569              /* im */
    }, { 0.0036873878172219987,        /* re */
      0.0857973123444399               /* im */
    }, { 0.003955299098748033,         /* re */
      0.0888535525825246               /* im */
    }, { 0.004232585532340183,         /* re */
      0.09190895649713272              /* im */
    }, { 0.0045192445080730614,        /* re */
      0.09496349532963899              /* im */
    }, { 0.004815273327803071,         /* re */
      0.0980171403295606               /* im */
    }, { 0.005120669205194384,         /* re */
      0.10106986275482782              /* im */
    }, { 0.005435429265744585,         /* re */
      0.10412163387205459              /* im */
    }, { 0.005759550546812098,         /* re */
      0.10717242495680884              /* im */
    }, { 0.0060930299976439395,        /* re */
      0.11022220729388306              /* im */
    }, { 0.006435864479404696,         /* re */
      0.11327095217756435              /* im */
    }, { 0.0067880507652055,           /* re */
      0.11631863091190475              /* im */
    }, { 0.007149585540134895,         /* re */
      0.11936521481099135              /* im */
    }, { 0.007520465401290033,         /* re */
      0.1224106751992162               /* im */
    }, { 0.007900686857808203,         /* re */
      0.12545498341154623              /* im */
    }, { 0.008290246330900475,         /* re */
      0.12849811079379317              /* im */
    }, { 0.008689140153884556,         /* re */
      0.13154002870288312              /* im */
    }, { 0.00909736457221999,          /* re */
      0.13458070850712617              /* im */
    }, { 0.009514915743542907,         /* re */
      0.13762012158648604              /* im */
    }, { 0.009941789737702877,         /* re */
      0.1406582393328492               /* im */
    }, { 0.010377982536799113,         /* re */
      0.14369503315029447              /* im */
    }, { 0.010823490035218986,         /* re */
      0.14673047445536175              /* im */
    }, { 0.011278308039676221,         /* re */
      0.1497645346773215               /* im */
    }, { 0.011742432269250536,         /* re */
      0.15279718525844344              /* im */
    }, { 0.012215858355427822,         /* re */
      0.15582839765426523              /* im */
    }, { 0.012698581842141565,         /* re */
      0.15885814333386145              /* im */
    }, { 0.013190598185814473,         /* re */
      0.16188639378011183              /* im */
    }, { 0.01369190275540133,          /* re */
      0.16491312048996992              /* im */
    }, { 0.014202490832432524,         /* re */
      0.16793829497473117              /* im */
    }, { 0.014722357611058778,         /* re */
      0.17096188876030122              /* im */
    }, { 0.015251498198095792,         /* re */
      0.17398387338746382              /* im */
    }, { 0.015789907613070975,         /* re */
      0.17700422041214875              /* im */
    }, { 0.016337580788269745,         /* re */
      0.18002290140569951              /* im */
    }, { 0.016894512568783715,         /* re */
      0.18303988795514095              /* im */
    }, { 0.01746069771255876,          /* re */
      0.18605515166344663              /* im */
    }, { 0.018036130890444757,         /* re */
      0.1890686641498062               /* im */
    }, { 0.01862080668624544,          /* re */
      0.19208039704989244              /* im */
    }, { 0.01921471959676957,          /* re */
      0.19509032201612825              /* im */
    }, { 0.01981786403188257,          /* re */
      0.19809841071795356              /* im */
    }, { 0.02043023431455948,          /* re */
      0.2011046348420919               /* im */
    }, { 0.021051824680937803,         /* re */
      0.20410896609281687              /* im */
    }, { 0.021682629280372345,         /* re */
      0.20711137619221856              /* im */
    }, { 0.02232264217549007,          /* re */
      0.2101118368804696               /* im */
    }, { 0.022971857342245605,         /* re */
      0.21311031991609136              /* im */
    }, { 0.02363026866997886,          /* re */
      0.21610679707621952              /* im */
    }, { 0.02429786996147143,          /* re */
      0.2191012401568698               /* im */
    }, { 0.02497465493300588,          /* re */
      0.2220936209732035               /* im */
    }, { 0.025660617214424142,         /* re */
      0.22508391135979283              /* im */
    }, { 0.026355750349188023,         /* re */
      0.22807208317088573              /* im */
    }, { 0.027060047794439823,         /* re */
      0.2310581082806711               /* im */
    }, { 0.02777350292106373,          /* re */
      0.23404195858354343              /* im */
    }, { 0.028496109013748216,         /* re */
      0.2370236059943672               /* im */
    }, { 0.02922785927104965,          /* re */
      0.2400030224487415               /* im */
    }, { 0.029968746805456026,         /* re */
      0.24298017990326387              /* im */
    }, { 0.03071876464345147,          /* re */
      0.2459550503357946               /* im */
    }, { 0.03147790572558273,          /* re */
      0.24892760574572015              /* im */
    }, { 0.03224616290652449,          /* re */
      0.25189781815421697              /* im */
    }, { 0.03302352895514793,          /* re */
      0.25486565960451457              /* im */
    }, { 0.033809996554587496,         /* re */
      0.257831102162159                /* im */
    }, { 0.0346055583023106,           /* re */
      0.2607941179152755               /* im */
    }, { 0.03541020671018724,          /* re */
      0.26375467897483135              /* im */
    }, { 0.03622393420456016,          /* re */
      0.26671275747489837              /* im */
    }, { 0.03704673312631612,          /* re */
      0.2696683255729151               /* im */
    }, { 0.03787859573095842,          /* re */
      0.272621355449949                /* im */
    }, { 0.03871951418867936,          /* re */
      0.27557181931095814              /* im */
    }, { 0.03956948058443421,          /* re */
      0.27851968938505306              /* im */
    }, { 0.04042848691801548,          /* re */
      0.28146493792575794              /* im */
    }, { 0.0412965251041284,           /* re */
      0.2844075372112719               /* im */
    }, { 0.04217358697246709,          /* re */
      0.2873474595447295               /* im */
    }, { 0.043059664267791176,         /* re */
      0.29028467725446233              /* im */
    }, { 0.043954748650003594,         /* re */
      0.29321916269425863              /* im */
    }, { 0.04485883169422922,          /* re */
      0.2961508882436238               /* im */
    }, { 0.04577190489089433,          /* re */
      0.2990798263080405               /* im */
    }, { 0.04669395964580614,          /* re */
      0.3020059493192281               /* im */
    }, { 0.04762498728023412,          /* re */
      0.3049292297354024               /* im */
    }, { 0.04856497903099166,          /* re */
      0.30784964004153487              /* im */
    }, { 0.0495139260505183,           /* re */
      0.3107671527496115               /* im */
    }, { 0.050471819406963325,         /* re */
      0.3136817403988915               /* im */
    }, { 0.05143865008426973,          /* re */
      0.31659337555616585              /* im */
    }, { 0.05241440898225891,          /* re */
      0.3195020308160157               /* im */
    }, { 0.053399086916716465,         /* re */
      0.32240767880106985              /* im */
    }, { 0.05439267461947872,          /* re */
      0.3253102921622629               /* im */
    }, { 0.05539516273851974,          /* re */
      0.3282098435790925               /* im */
    }, { 0.056406541838039614,         /* re */
      0.33110630575987643              /* im */
    }, { 0.057426802398553134,         /* re */
      0.3339996514420094               /* im */
    }, { 0.058455934816979194,         /* re */
      0.33688985339222005              /* im */
    }, { 0.059493929406731705,         /* re */
      0.33977688440682685              /* im */
    }, { 0.06054077639781008,          /* re */
      0.3426607173119944               /* im */
    }, { 0.06159646593689194,          /* re */
      0.3455413249639891               /* im */
    }, { 0.06266098808742504,          /* re */
      0.34841868024943456              /* im */
    }, { 0.06373433282972174,          /* re */
      0.3512927560855671               /* im */
    }, { 0.06481649006105239,          /* re */
      0.35416352542049034              /* im */
    }, { 0.06590744959574113,          /* re */
      0.35703096123343                 /* im */
    }, { 0.06700720116526104,          /* re */
      0.3598950365349881               /* im */
    }, { 0.06811573441833185,          /* re */
      0.3627557243673972               /* im */
    }, { 0.06923303892101629,          /* re */
      0.36561299780477385              /* im */
    }, { 0.07035910415681879,          /* re */
      0.3684668299533723               /* im */
    }, { 0.07149391952678441,          /* re */
      0.3713171939518375               /* im */
    }, { 0.07263747434959889,          /* re */
      0.37416406297145793              /* im */
    }, { 0.07378975786168862,          /* re */
      0.37700741021641826              /* im */
    }, { 0.07495075921732242,          /* re */
      0.37984720892405116              /* im */
    }, { 0.07612046748871326,          /* re */
      0.3826834323650898               /* im */
    }, { 0.07729887166612137,          /* re */
      0.38551605384391885              /* im */
    }, { 0.0784859606579581,           /* re */
      0.38834504669882625              /* im */
    }, { 0.0796817232908894,           /* re */
      0.39117038430225387              /* im */
    }, { 0.08088614830994223,          /* re */
      0.3939920400610481               /* im */
    }, { 0.0820992243786095,           /* re */
      0.3968099874167103               /* im */
    }, { 0.0833209400789573,           /* re */
      0.3996241998456468               /* im */
    }, { 0.08455128391173217,          /* re */
      0.40243465085941843              /* im */
    }, { 0.08579024429646931,          /* re */
      0.40524131400498986              /* im */
    }, { 0.08703780957160179,          /* re */
      0.4080441628649787               /* im */
    }, { 0.08829396799457012,          /* re */
      0.4108431710579039               /* im */
    }, { 0.08955870774193275,          /* re */
      0.4136383122384345               /* im */
    }, { 0.09083201690947762,          /* re */
      0.41642956009763715              /* im */
    }, { 0.09211388351233374,          /* re */
      0.4192168883632239               /* im */
    }, { 0.09340429548508467,          /* re */
      0.4220002707997997               /* im */
    }, { 0.09470324068188118,          /* re */
      0.4247796812091088               /* im */
    }, { 0.09601070687655666,          /* re */
      0.4275550934302821               /* im */
    }, { 0.09732668176274117,          /* re */
      0.4303264813400826               /* im */
    }, { 0.09865115295397797,          /* re */
      0.43309381885315196              /* im */
    }, { 0.09998410798383983,          /* re */
      0.4358570799222555               /* im */
    }, { 0.10132553430604618,          /* re */
      0.43861623853852766              /* im */
    }, { 0.10267541929458168,          /* re */
      0.44137126873171667              /* im */
    }, { 0.10403375024381478,          /* re */
      0.4441221445704292               /* im */
    }, { 0.1054005143686173,           /* re */
      0.44686884016237416              /* im */
    }, { 0.10677569880448468,          /* re */
      0.44961132965460654              /* im */
    }, { 0.10815929060765728,          /* re */
      0.4523495872337709               /* im */
    }, { 0.10955127675524212,          /* re */
      0.45508358712634384              /* im */
    }, { 0.11095164414533543,          /* re */
      0.4578133035988772               /* im */
    }, { 0.11236037959714607,          /* re */
      0.46053871095824                 /* im */
    }, { 0.11377746985111936,          /* re */
      0.46325978355186015              /* im */
    }, { 0.11520290156906221,          /* re */
      0.4659764957679662               /* im */
    }, { 0.11663666133426842,          /* re */
      0.46868882203582796              /* im */
    }, { 0.11807873565164495,          /* re */
      0.47139673682599764              /* im */
    }, { 0.11952911094783925,          /* re */
      0.47410021465054997              /* im */
    }, { 0.12098777357136647,          /* re */
      0.4767992300633221               /* im */
    }, { 0.12245470979273865,          /* re */
      0.47949375766015295              /* im */
    }, { 0.1239299058045934,           /* re */
      0.4821837720791227               /* im */
    }, { 0.1254133477218239,           /* re */
      0.48486924800079106              /* im */
    }, { 0.1269050215817099,           /* re */
      0.487550160148436                /* im */
    }, { 0.1284049133440489,           /* re */
      0.49022648328829116              /* im */
    }, { 0.12991300889128854,          /* re */
      0.49289819222978404              /* im */
    }, { 0.1314292940286591,           /* re */
      0.49556526182577254              /* im */
    }, { 0.13295375448430735,          /* re */
      0.4982276669727818               /* im */
    }, { 0.1344863759094309,           /* re */
      0.5008853826112407               /* im */
    }, { 0.1360271438784133,           /* re */
      0.5035383837257176               /* im */
    }, { 0.1375760438889595,           /* re */
      0.5061866453451552               /* im */
    }, { 0.1391330613622327,           /* re */
      0.508830142543107                /* im */
    }, { 0.14069818164299153,          /* re */
      0.5114688504379703               /* im */
    }, { 0.14227138999972788,          /* re */
      0.5141027441932217               /* im */
    }, { 0.14385267162480553,          /* re */
      0.5167317990176499               /* im */
    }, { 0.14544201163459947,          /* re */
      0.5193559901655896               /* im */
    }, { 0.14703939506963637,          /* re */
      0.5219752929371544               /* im */
    }, { 0.1486448068947348,           /* re */
      0.524589682678469                /* im */
    }, { 0.15025823199914745,          /* re */
      0.5271991347819013               /* im */
    }, { 0.15187965519670277,          /* re */
      0.5298036246862946               /* im */
    }, { 0.15350906122594787,          /* re */
      0.5324031278771979               /* im */
    }, { 0.15514643475029288,          /* re */
      0.5349976198870972               /* im */
    }, { 0.15679176035815456,          /* re */
      0.5375870762956454               /* im */
    }, { 0.15844502256310156,          /* re */
      0.5401714727298929               /* im */
    }, { 0.16010620580400048,          /* re */
      0.5427507848645159               /* im */
    }, { 0.16177529444516192,          /* re */
      0.5453249884220465               /* im */
    }, { 0.163452272776488,            /* re */
      0.5478940591731002               /* im */
    }, { 0.16513712501362,             /* re */
      0.5504579729366048               /* im */
    }, { 0.16682983529808681,          /* re */
      0.5530167055800275               /* im */
    }, { 0.16853038769745476,          /* re */
      0.5555702330196022               /* im */
    }, { 0.17023876620547695,          /* re */
      0.5581185312205561               /* im */
    }, { 0.1719549547422442,           /* re */
      0.560661576197336                /* im */
    }, { 0.17367893715433647,          /* re */
      0.5631993440138341               /* im */
    }, { 0.1754106972149747,           /* re */
      0.5657318107836131               /* im */
    }, { 0.17715021862417357,          /* re */
      0.5682589526701315               /* im */
    }, { 0.17889748500889535,          /* re */
      0.5707807458869673               /* im */
    }, { 0.180652479923203,            /* re */
      0.5732971666980422               /* im */
    }, { 0.1824151868484163,           /* re */
      0.5758081914178453               /* im */
    }, { 0.18418558919326622,          /* re */
      0.5783137964116556               /* im */
    }, { 0.1859636702940516,           /* re */
      0.5808139580957645               /* im */
    }, { 0.18774941341479612,          /* re */
      0.5833086529376983               /* im */
    }, { 0.18954280174740523,          /* re */
      0.5857978574564389               /* im */
    }, { 0.19134381841182502,          /* re */
      0.5882815482226452               /* im */
    }, { 0.19315244645620067,          /* re */
      0.5907597018588742               /* im */
    }, { 0.19496866885703634,          /* re */
      0.5932322950397998               /* im */
    }, { 0.19679246851935506,          /* re */
      0.5956993044924334               /* im */
    }, { 0.19862382827685976,          /* re */
      0.5981607069963424               /* im */
    }, { 0.200462730892095,            /* re */
      0.600616479383869                /* im */
    }, { 0.20230915905660884,          /* re */
      0.6030665985403482               /* im */
    }, { 0.20416309539111643,          /* re */
      0.6055110414043255               /* im */
    }, { 0.20602452244566283,          /* re */
      0.6079497849677736               /* im */
    }, { 0.2078934226997876,           /* re */
      0.6103828062763095               /* im */
    }, { 0.20976977856268997,          /* re */
      0.6128100824294097               /* im */
    }, { 0.21165357237339366,          /* re */
      0.6152315905806268               /* im */
    }, { 0.21354478640091423,          /* re */
      0.6176473079378039               /* im */
    }, { 0.21544340284442476,          /* re */
      0.6200572117632891               /* im */
    }, { 0.21734940383342427,          /* re */
      0.62246127937415                 /* im */
    }, { 0.2192627714279055,           /* re */
      0.6248594881423863               /* im */
    }, { 0.22118348761852402,          /* re */
      0.6272518154951441               /* im */
    }, { 0.22311153432676756,          /* re */
      0.629638238914927                /* im */
    }, { 0.22504689340512607,          /* re */
      0.6320187359398091               /* im */
    }, { 0.226989546637263,            /* re */
      0.6343932841636455               /* im */
    }, { 0.22893947573818618,          /* re */
      0.6367618612362842               /* im */
    }, { 0.2308966623544203,           /* re */
      0.6391244448637757               /* im */
    }, { 0.2328610880641796,           /* re */
      0.641481012808583                /* im */
    }, { 0.23483273437754104,          /* re */
      0.6438315428897914               /* im */
    }, { 0.23681158273661873,          /* re */
      0.6461760129833163               /* im */
    }, { 0.23879761451573822,          /* re */
      0.6485144010221124               /* im */
    }, { 0.24079081102161204,          /* re */
      0.650846684996381                /* im */
    }, { 0.24279115349351543,          /* re */
      0.6531728429537768               /* im */
    }, { 0.24479862310346345,          /* re */
      0.6554928529996153               /* im */
    }, { 0.24681320095638748,          /* re */
      0.6578066932970786               /* im */
    }, { 0.24883486809031363,          /* re */
      0.6601143420674205               /* im */
    }, { 0.25086360547654063,          /* re */
      0.6624157775901718               /* im */
    }, { 0.25289939401981987,          /* re */
      0.6647109782033448               /* im */
    }, { 0.25494221455853405,          /* re */
      0.6669999223036375               /* im */
    }, { 0.2569920478648783,           /* re */
      0.669282588346636                /* im */
    }, { 0.2590488746450408,           /* re */
      0.6715589548470183               /* im */
    }, { 0.2611126755393849,           /* re */
      0.673829000378756                /* im */
    }, { 0.2631834311226302,           /* re */
      0.6760927035753159               /* im */
    }, { 0.2652611219040365,           /* re */
      0.6783500431298615               /* im */
    }, { 0.2673457283275872,           /* re */
      0.680600997795453                /* im */
    }, { 0.2694372307721724,           /* re */
      0.6828455463852481               /* im */
    }, { 0.2715356095517748,           /* re */
      0.6850836677727004               /* im */
    }, { 0.273640844915654,            /* re */
      0.687315340891759                /* im */
    }, { 0.275752917048533,            /* re */
      0.6895405447370668               /* im */
    }, { 0.27787180607078465,          /* re */
      0.6917592583641577               /* im */
    }, { 0.27999749203861835,          /* re */
      0.6939714608896539               /* im */
    }, { 0.2821299549442683,           /* re */
      0.696177131491463                /* im */
    }, { 0.2842691747161814,           /* re */
      0.6983762494089729               /* im */
    }, { 0.2864151312192065,           /* re */
      0.7005687939432483               /* im */
    }, { 0.28856780425478357,          /* re */
      0.7027547444572253               /* im */
    }, { 0.2907271735611343,           /* re */
      0.7049340803759049               /* im */
    }, { 0.2928932188134524,           /* re */
      0.7071067811865476               /* im */
    }, { 0.2950659196240951,           /* re */
      0.7092728264388657               /* im */
    }, { 0.2972452555427747,           /* re */
      0.7114321957452164               /* im */
    }, { 0.29943120605675166,          /* re */
      0.7135848687807935               /* im */
    }, { 0.3016237505910271,           /* re */
      0.7157308252838186               /* im */
    }, { 0.303822868508537,            /* re */
      0.7178700450557317               /* im */
    }, { 0.3060285391103461,           /* re */
      0.7200025079613817               /* im */
    }, { 0.30824074163584225,          /* re */
      0.7221281939292153               /* im */
    }, { 0.31045945526293317,          /* re */
      0.724247082951467                /* im */
    }, { 0.31268465910824095,          /* re */
      0.726359155084346                /* im */
    }, { 0.31491633222729964,          /* re */
      0.7284643904482252               /* im */
    }, { 0.3171544536147519,           /* re */
      0.7305627692278276               /* im */
    }, { 0.319399002204547,            /* re */
      0.7326542716724128               /* im */
    }, { 0.32164995687013853,          /* re */
      0.7347388780959635               /* im */
    }, { 0.3239072964246841,           /* re */
      0.7368165688773698               /* im */
    }, { 0.32617099962124396,          /* re */
      0.7388873244606151               /* im */
    }, { 0.32844104515298167,          /* re */
      0.7409511253549592               /* im */
    }, { 0.330717411653364,            /* re */
      0.7430079521351217               /* im */
    }, { 0.33300007769636253,          /* re */
      0.745057785441466                /* im */
    }, { 0.3352890217966552,           /* re */
      0.7471006059801801               /* im */
    }, { 0.3375842224098282,           /* re */
      0.7491363945234594               /* im */
    }, { 0.3398856579325795,           /* re */
      0.7511651319096864               /* im */
    }, { 0.34219330670292136,          /* re */
      0.7531867990436125               /* im */
    }, { 0.34450714700038465,          /* re */
      0.7552013768965365               /* im */
    }, { 0.34682715704622324,          /* re */
      0.7572088465064846               /* im */
    }, { 0.349153315003619,            /* re */
      0.759209188978388                /* im */
    }, { 0.35148559897788756,          /* re */
      0.7612023854842618               /* im */
    }, { 0.3538239870166837,           /* re */
      0.7631884172633813               /* im */
    }, { 0.3561684571102086,           /* re */
      0.765167265622459                /* im */
    }, { 0.35851898719141695,          /* re */
      0.7671389119358204               /* im */
    }, { 0.36087555513622427,          /* re */
      0.7691033376455797               /* im */
    }, { 0.3632381387637158,           /* re */
      0.7710605242618138               /* im */
    }, { 0.3656067158363545,           /* re */
      0.773010453362737                /* im */
    }, { 0.36798126406019094,          /* re */
      0.7749531065948739               /* im */
    }, { 0.370361761085073,            /* re */
      0.7768884656732324               /* im */
    }, { 0.3727481845048559,           /* re */
      0.778816512381476                /* im */
    }, { 0.37514051185761366,          /* re */
      0.7807372285720945               /* im */
    }, { 0.37753872062585003,          /* re */
      0.7826505961665757               /* im */
    }, { 0.3799427882367109,           /* re */
      0.7845565971555752               /* im */
    }, { 0.38235269206219613,          /* re */
      0.7864552135990858               /* im */
    }, { 0.3847684094193732,           /* re */
      0.7883464276266063               /* im */
    }, { 0.3871899175705903,           /* re */
      0.79023022143731                 /* im */
    }, { 0.3896171937236905,           /* re */
      0.7921065773002124               /* im */
    }, { 0.39205021503222637,          /* re */
      0.7939754775543372               /* im */
    }, { 0.39448895859567445,          /* re */
      0.7958369046088836               /* im */
    }, { 0.39693340145965184,          /* re */
      0.7976908409433912               /* im */
    }, { 0.399383520616131,            /* re */
      0.799537269107905                /* im */
    }, { 0.4018392930036576,           /* re */
      0.8013761717231402               /* im */
    }, { 0.40430069550756664,          /* re */
      0.8032075314806449               /* im */
    }, { 0.4067677049602002,           /* re */
      0.8050313311429637               /* im */
    }, { 0.40924029814112584,          /* re */
      0.8068475535437993               /* im */
    }, { 0.4117184517773548,           /* re */
      0.808656181588175                /* im */
    }, { 0.41420214254356114,          /* re */
      0.8104571982525948               /* im */
    }, { 0.4166913470623017,           /* re */
      0.8122505865852039               /* im */
    }, { 0.4191860419042355,           /* re */
      0.8140363297059484               /* im */
    }, { 0.4216862035883444,           /* re */
      0.8158144108067338               /* im */
    }, { 0.42419180858215466,          /* re */
      0.8175848131515837               /* im */
    }, { 0.4267028333019578,           /* re */
      0.819347520076797                /* im */
    }, { 0.42921925411303274,          /* re */
      0.8211025149911046               /* im */
    }, { 0.4317410473298685,           /* re */
      0.8228497813758264               /* im */
    }, { 0.4342681892163869,           /* re */
      0.8245893027850253               /* im */
    }, { 0.4368006559861659,           /* re */
      0.8263210628456635               /* im */
    }, { 0.43933842380266397,          /* re */
      0.8280450452577558               /* im */
    }, { 0.4418814687794439,           /* re */
      0.829761233794523                /* im */
    }, { 0.4444297669803978,           /* re */
      0.8314696123025452               /* im */
    }, { 0.44698329441997253,          /* re */
      0.8331701647019132               /* im */
    }, { 0.4495420270633952,           /* re */
      0.83486287498638                 /* im */
    }, { 0.4521059408268998,           /* re */
      0.836547727223512                /* im */
    }, { 0.45467501157795354,          /* re */
      0.8382247055548381               /* im */
    }, { 0.4572492151354841,           /* re */
      0.8398937941959995               /* im */
    }, { 0.45982852727010715,          /* re */
      0.8415549774368984               /* im */
    }, { 0.4624129237043546,           /* re */
      0.8432082396418454               /* im */
    }, { 0.46500238011290285,          /* re */
      0.8448535652497071               /* im */
    }, { 0.4675968721228021,           /* re */
      0.8464909387740521               /* im */
    }, { 0.4701963753137054,           /* re */
      0.8481203448032972               /* im */
    }, { 0.4728008652180987,           /* re */
      0.8497417680008525               /* im */
    }, { 0.47541031732153105,          /* re */
      0.8513551931052652               /* im */
    }, { 0.4780247070628456,           /* re */
      0.8529606049303636               /* im */
    }, { 0.48064400983441036,          /* re */
      0.8545579883654005               /* im */
    }, { 0.4832682009823501,           /* re */
      0.8561473283751945               /* im */
    }, { 0.48589725580677834,          /* re */
      0.8577286100002721               /* im */
    }, { 0.4885311495620297,           /* re */
      0.8593018183570085               /* im */
    }, { 0.491169857456893,            /* re */
      0.8608669386377673               /* im */
    }, { 0.49381335465484477,          /* re */
      0.8624239561110405               /* im */
    }, { 0.4964616162742824,           /* re */
      0.8639728561215867               /* im */
    }, { 0.4991146173887593,           /* re */
      0.8655136240905691               /* im */
    }, { 0.5017723330272181,           /* re */
      0.8670462455156926               /* im */
    }, { 0.5044347381742275,           /* re */
      0.8685707059713409               /* im */
    }, { 0.507101807770216,            /* re */
      0.8700869911087115               /* im */
    }, { 0.5097735167117088,           /* re */
      0.8715950866559511               /* im */
    }, { 0.512449839851564,            /* re */
      0.8730949784182901               /* im */
    }, { 0.515130751999209,            /* re */
      0.8745866522781761               /* im */
    }, { 0.5178162279208773,           /* re */
      0.8760700941954066               /* im */
    }, { 0.520506242339847,            /* re */
      0.8775452902072614               /* im */
    }, { 0.5232007699366779,           /* re */
      0.8790122264286335               /* im */
    }, { 0.52589978534945,             /* re */
      0.8804708890521608               /* im */
    }, { 0.5286032631740023,           /* re */
      0.881921264348355                /* im */
    }, { 0.531311177964172,            /* re */
      0.8833633386657316               /* im */
    }, { 0.5340235042320338,           /* re */
      0.8847970984309378               /* im */
    }, { 0.5367402164481399,           /* re */
      0.8862225301488806               /* im */
    }, { 0.53946128904176,             /* re */
      0.8876396204028539               /* im */
    }, { 0.5421866964011228,           /* re */
      0.8890483558546646               /* im */
    }, { 0.5449164128736561,           /* re */
      0.8904487232447579               /* im */
    }, { 0.5476504127662292,           /* re */
      0.8918407093923427               /* im */
    }, { 0.5503886703453935,           /* re */
      0.8932243011955153               /* im */
    }, { 0.5531311598376258,           /* re */
      0.8945994856313827               /* im */
    }, { 0.5558778554295708,           /* re */
      0.8959662497561852               /* im */
    }, { 0.5586287312682834,           /* re */
      0.8973245807054183               /* im */
    }, { 0.5613837614614723,           /* re */
      0.8986744656939538               /* im */
    }, { 0.5641429200777446,           /* re */
      0.9000158920161602               /* im */
    }, { 0.5669061811468481,           /* re */
      0.901348847046022                /* im */
    }, { 0.5696735186599173,           /* re */
      0.9026733182372588               /* im */
    }, { 0.5724449065697179,           /* re */
      0.9039892931234433               /* im */
    }, { 0.5752203187908912,           /* re */
      0.9052967593181188               /* im */
    }, { 0.5779997292002004,           /* re */
      0.9065957045149153               /* im */
    }, { 0.5807831116367761,           /* re */
      0.9078861164876663               /* im */
    }, { 0.5835704399023629,           /* re */
      0.9091679830905224               /* im */
    }, { 0.5863616877615655,           /* re */
      0.9104412922580672               /* im */
    }, { 0.5891568289420961,           /* re */
      0.9117060320054299               /* im */
    }, { 0.5919558371350213,           /* re */
      0.9129621904283982               /* im */
    }, { 0.5947586859950101,           /* re */
      0.9142097557035307               /* im */
    }, { 0.5975653491405816,           /* re */
      0.9154487160882678               /* im */
    }, { 0.6003758001543532,           /* re */
      0.9166790599210427               /* im */
    }, { 0.6031900125832896,           /* re */
      0.9179007756213905               /* im */
    }, { 0.6060079599389518,           /* re */
      0.9191138516900578               /* im */
    }, { 0.6088296156977462,           /* re */
      0.9203182767091106               /* im */
    }, { 0.6116549533011737,           /* re */
      0.9215140393420419               /* im */
    }, { 0.6144839461560812,           /* re */
      0.9227011283338786               /* im */
    }, { 0.6173165676349102,           /* re */
      0.9238795325112867               /* im */
    }, { 0.6201527910759488,           /* re */
      0.9250492407826776               /* im */
    }, { 0.6229925897835817,           /* re */
      0.9262102421383114               /* im */
    }, { 0.625835937028542,            /* re */
      0.9273625256504011               /* im */
    }, { 0.6286828060481625,           /* re */
      0.9285060804732156               /* im */
    }, { 0.6315331700466277,           /* re */
      0.9296408958431812               /* im */
    }, { 0.6343870021952261,           /* re */
      0.9307669610789837               /* im */
    }, { 0.6372442756326028,           /* re */
      0.9318842655816681               /* im */
    }, { 0.6401049634650119,           /* re */
      0.932992798834739                /* im */
    }, { 0.6429690387665701,           /* re */
      0.9340925504042589               /* im */
    }, { 0.6458364745795097,           /* re */
      0.9351835099389476               /* im */
    }, { 0.6487072439144329,           /* re */
      0.9362656671702783               /* im */
    }, { 0.6515813197505654,           /* re */
      0.937339011912575                /* im */
    }, { 0.6544586750360109,           /* re */
      0.9384035340631081               /* im */
    }, { 0.6573392826880056,           /* re */
      0.9394592236021899               /* im */
    }, { 0.6602231155931731,           /* re */
      0.9405060705932683               /* im */
    }, { 0.66311014660778,             /* re */
      0.9415440651830208               /* im */
    }, { 0.6660003485579906,           /* re */
      0.9425731976014469               /* im */
    }, { 0.6688936942401236,           /* re */
      0.9435934581619604               /* im */
    }, { 0.6717901564209074,           /* re */
      0.9446048372614803               /* im */
    }, { 0.6746897078377371,           /* re */
      0.9456073253805213               /* im */
    }, { 0.6775923211989301,           /* re */
      0.9466009130832835               /* im */
    }, { 0.6804979691839843,           /* re */
      0.9475855910177411               /* im */
    }, { 0.6834066244438342,           /* re */
      0.9485613499157303               /* im */
    }, { 0.6863182596011085,           /* re */
      0.9495281805930367               /* im */
    }, { 0.6892328472503886,           /* re */
      0.9504860739494817               /* im */
    }, { 0.6921503599584651,           /* re */
      0.9514350209690083               /* im */
    }, { 0.6950707702645976,           /* re */
      0.9523750127197659               /* im */
    }, { 0.6979940506807719,           /* re */
      0.9533060403541939               /* im */
    }, { 0.7009201736919595,           /* re */
      0.9542280951091057               /* im */
    }, { 0.7038491117563762,           /* re */
      0.9551411683057708               /* im */
    }, { 0.7067808373057414,           /* re */
      0.9560452513499964               /* im */
    }, { 0.7097153227455377,           /* re */
      0.9569403357322088               /* im */
    }, { 0.7126525404552705,           /* re */
      0.9578264130275329               /* im */
    }, { 0.7155924627887281,           /* re */
      0.9587034748958716               /* im */
    }, { 0.7185350620742421,           /* re */
      0.9595715130819845               /* im */
    }, { 0.721480310614947,            /* re */
      0.9604305194155658               /* im */
    }, { 0.7244281806890418,           /* re */
      0.9612804858113206               /* im */
    }, { 0.727378644550051,            /* re */
      0.9621214042690416               /* im */
    }, { 0.7303316744270849,           /* re */
      0.9629532668736839               /* im */
    }, { 0.7332872425251016,           /* re */
      0.9637760657954398               /* im */
    }, { 0.7362453210251687,           /* re */
      0.9645897932898128               /* im */
    }, { 0.7392058820847245,           /* re */
      0.9653944416976894               /* im */
    }, { 0.742168897837841,            /* re */
      0.9661900034454125               /* im */
    }, { 0.7451343403954854,           /* re */
      0.9669764710448521               /* im */
    }, { 0.748102181845783,            /* re */
      0.9677538370934755               /* im */
    }, { 0.7510723942542799,           /* re */
      0.9685220942744173               /* im */
    }, { 0.7540449496642054,           /* re */
      0.9692812353565485               /* im */
    }, { 0.7570198200967362,           /* re */
      0.970031253194544                /* im */
    }, { 0.7599969775512585,           /* re */
      0.9707721407289504               /* im */
    }, { 0.7629763940056328,           /* re */
      0.9715038909862518               /* im */
    }, { 0.7659580414164566,           /* re */
      0.9722264970789363               /* im */
    }, { 0.7689418917193289,           /* re */
      0.9729399522055602               /* im */
    }, { 0.7719279168291142,           /* re */
      0.973644249650812                /* im */
    }, { 0.7749160886402071,           /* re */
      0.9743393827855759               /* im */
    }, { 0.7779063790267965,           /* re */
      0.9750253450669941               /* im */
    }, { 0.7808987598431302,           /* re */
      0.9757021300385286               /* im */
    }, { 0.7838932029237805,           /* re */
      0.9763697313300211               /* im */
    }, { 0.7868896800839087,           /* re */
      0.9770281426577544               /* im */
    }, { 0.7898881631195304,           /* re */
      0.9776773578245099               /* im */
    }, { 0.7928886238077815,           /* re */
      0.9783173707196277               /* im */
    }, { 0.7958910339071832,           /* re */
      0.9789481753190622               /* im */
    }, { 0.798895365157908,            /* re */
      0.9795697656854405               /* im */
    }, { 0.8019015892820465,           /* re */
      0.9801821359681174               /* im */
    }, { 0.8049096779838718,           /* re */
      0.9807852804032304               /* im */
    }, { 0.8079196029501076,           /* re */
      0.9813791933137546               /* im */
    }, { 0.8109313358501938,           /* re */
      0.9819638691095552               /* im */
    }, { 0.8139448483365533,           /* re */
      0.9825393022874412               /* im */
    }, { 0.8169601120448591,           /* re */
      0.9831054874312163               /* im */
    }, { 0.8199770985943005,           /* re */
      0.9836624192117303               /* im */
    }, { 0.8229957795878513,           /* re */
      0.984210092386929                /* im */
    }, { 0.8260161266125362,           /* re */
      0.9847485018019042               /* im */
    }, { 0.8290381112396987,           /* re */
      0.9852776423889412               /* im */
    }, { 0.8320617050252688,           /* re */
      0.9857975091675675               /* im */
    }, { 0.8350868795100301,           /* re */
      0.9863080972445987               /* im */
    }, { 0.8381136062198882,           /* re */
      0.9868094018141855               /* im */
    }, { 0.8411418566661386,           /* re */
      0.9873014181578584               /* im */
    }, { 0.8441716023457347,           /* re */
      0.9877841416445722               /* im */
    }, { 0.8472028147415566,           /* re */
      0.9882575677307495               /* im */
    }, { 0.8502354653226785,           /* re */
      0.9887216919603238               /* im */
    }, { 0.8532695255446383,           /* re */
      0.989176509964781                /* im */
    }, { 0.8563049668497056,           /* re */
      0.9896220174632009               /* im */
    }, { 0.8593417606671507,           /* re */
      0.9900582102622971               /* im */
    }, { 0.8623798784135139,           /* re */
      0.9904850842564571               /* im */
    }, { 0.8654192914928738,           /* re */
      0.99090263542778                 /* im */
    }, { 0.8684599712971168,           /* re */
      0.9913108598461154               /* im */
    }, { 0.8715018892062069,           /* re */
      0.9917097536690995               /* im */
    }, { 0.8745450165884537,           /* re */
      0.9920993131421918               /* im */
    }, { 0.8775893248007838,           /* re */
      0.99247953459871                 /* im */
    }, { 0.8806347851890086,           /* re */
      0.9928504144598651               /* im */
    }, { 0.8836813690880952,           /* re */
      0.9932119492347945               /* im */
    }, { 0.8867290478224357,           /* re */
      0.9935641355205953               /* im */
    }, { 0.8897777927061169,           /* re */
      0.9939069700023561               /* im */
    }, { 0.8928275750431911,           /* re */
      0.9942404494531879               /* im */
    }, { 0.8958783661279455,           /* re */
      0.9945645707342554               /* im */
    }, { 0.8989301372451721,           /* re */
      0.9948793307948056               /* im */
    }, { 0.9019828596704393,           /* re */
      0.9951847266721969               /* im */
    }, { 0.905036504670361,            /* re */
      0.9954807554919269               /* im */
    }, { 0.9080910435028673,           /* re */
      0.9957674144676598               /* im */
    }, { 0.9111464474174754,           /* re */
      0.996044700901252                /* im */
    }, { 0.9142026876555601,           /* re */
      0.996312612182778                /* im */
    }, { 0.9172597354506243,           /* re */
      0.9965711457905548               /* im */
    }, { 0.9203175620285698,           /* re */
      0.9968202992911657               /* im */
    }, { 0.9233761386079685,           /* re */
      0.997060070339483                /* im */
    }, { 0.9264354364003325,           /* re */
      0.9972904566786902               /* im */
    }, { 0.9294954266103861,           /* re */
      0.9975114561403035               /* im */
    }, { 0.932556080436336,            /* re */
      0.9977230666441916               /* im */
    }, { 0.9356173690701426,           /* re */
      0.997925286198596                /* im */
    }, { 0.9386792636977914,           /* re */
      0.9981181129001492               /* im */
    }, { 0.9417417354995643,           /* re */
      0.9983015449338929               /* im */
    }, { 0.9448047556503101,           /* re */
      0.9984755805732948               /* im */
    }, { 0.9478682953197167,           /* re */
      0.9986402181802653               /* im */
    }, { 0.950932325672582,            /* re */
      0.9987954562051724               /* im */
    }, { 0.9539968178690854,           /* re */
      0.9989412931868569               /* im */
    }, { 0.9570617430650592,           /* re */
      0.9990777277526454               /* im */
    }, { 0.9601270724122601,           /* re */
      0.9992047586183639               /* im */
    }, { 0.9631927770586411,           /* re */
      0.9993223845883495               /* im */
    }, { 0.9662588281486224,           /* re */
      0.9994306045554617               /* im */
    }, { 0.9693251968233634,           /* re */
      0.9995294175010931               /* im */
    }, { 0.9723918542210342,           /* re */
      0.9996188224951786               /* im */
    }, { 0.9754587714770877,           /* re */
      0.9996988186962042               /* im */
    }, { 0.9785259197245305,           /* re */
      0.9997694053512153               /* im */
    }, { 0.9815932700941952,           /* re */
      0.9998305817958234               /* im */
    }, { 0.9846607937150119,           /* re */
      0.9998823474542126               /* im */
    }, { 0.9877284617142801,           /* re */
      0.9999247018391445               /* im */
    }, { 0.9907962452179402,           /* re */
      0.9999576445519639               /* im */
    }, { 0.9938641153508455,           /* re */
      0.9999811752826011               /* im */
    }, { 0.996932043237034,            /* re */
      0.9999952938095762               /* im */
    } };

  static const creal_T reconVar2[1024] = { { 1.0,/* re */
      1.0                              /* im */
    }, { 1.003067956762966,            /* re */
      0.9999952938095762               /* im */
    }, { 1.0061358846491544,           /* re */
      0.9999811752826011               /* im */
    }, { 1.0092037547820598,           /* re */
      0.9999576445519639               /* im */
    }, { 1.01227153828572,             /* re */
      0.9999247018391445               /* im */
    }, { 1.0153392062849882,           /* re */
      0.9998823474542126               /* im */
    }, { 1.0184067299058048,           /* re */
      0.9998305817958234               /* im */
    }, { 1.0214740802754696,           /* re */
      0.9997694053512153               /* im */
    }, { 1.0245412285229123,           /* re */
      0.9996988186962042               /* im */
    }, { 1.0276081457789656,           /* re */
      0.9996188224951786               /* im */
    }, { 1.0306748031766366,           /* re */
      0.9995294175010931               /* im */
    }, { 1.0337411718513776,           /* re */
      0.9994306045554617               /* im */
    }, { 1.0368072229413587,           /* re */
      0.9993223845883495               /* im */
    }, { 1.0398729275877399,           /* re */
      0.9992047586183639               /* im */
    }, { 1.0429382569349408,           /* re */
      0.9990777277526454               /* im */
    }, { 1.0460031821309146,           /* re */
      0.9989412931868569               /* im */
    }, { 1.049067674327418,            /* re */
      0.9987954562051724               /* im */
    }, { 1.0521317046802834,           /* re */
      0.9986402181802653               /* im */
    }, { 1.05519524434969,             /* re */
      0.9984755805732948               /* im */
    }, { 1.0582582645004357,           /* re */
      0.9983015449338929               /* im */
    }, { 1.0613207363022086,           /* re */
      0.9981181129001492               /* im */
    }, { 1.0643826309298574,           /* re */
      0.997925286198596                /* im */
    }, { 1.067443919563664,            /* re */
      0.9977230666441916               /* im */
    }, { 1.070504573389614,            /* re */
      0.9975114561403035               /* im */
    }, { 1.0735645635996673,           /* re */
      0.9972904566786902               /* im */
    }, { 1.0766238613920316,           /* re */
      0.997060070339483                /* im */
    }, { 1.07968243797143,             /* re */
      0.9968202992911657               /* im */
    }, { 1.0827402645493758,           /* re */
      0.9965711457905548               /* im */
    }, { 1.08579731234444,             /* re */
      0.996312612182778                /* im */
    }, { 1.0888535525825247,           /* re */
      0.996044700901252                /* im */
    }, { 1.0919089564971327,           /* re */
      0.9957674144676598               /* im */
    }, { 1.094963495329639,            /* re */
      0.9954807554919269               /* im */
    }, { 1.0980171403295607,           /* re */
      0.9951847266721969               /* im */
    }, { 1.1010698627548279,           /* re */
      0.9948793307948056               /* im */
    }, { 1.1041216338720545,           /* re */
      0.9945645707342554               /* im */
    }, { 1.107172424956809,            /* re */
      0.9942404494531879               /* im */
    }, { 1.110222207293883,            /* re */
      0.9939069700023561               /* im */
    }, { 1.1132709521775643,           /* re */
      0.9935641355205953               /* im */
    }, { 1.1163186309119046,           /* re */
      0.9932119492347945               /* im */
    }, { 1.1193652148109914,           /* re */
      0.9928504144598651               /* im */
    }, { 1.1224106751992162,           /* re */
      0.99247953459871                 /* im */
    }, { 1.1254549834115462,           /* re */
      0.9920993131421918               /* im */
    }, { 1.1284981107937933,           /* re */
      0.9917097536690995               /* im */
    }, { 1.1315400287028832,           /* re */
      0.9913108598461154               /* im */
    }, { 1.1345807085071262,           /* re */
      0.99090263542778                 /* im */
    }, { 1.137620121586486,            /* re */
      0.9904850842564571               /* im */
    }, { 1.1406582393328493,           /* re */
      0.9900582102622971               /* im */
    }, { 1.1436950331502944,           /* re */
      0.9896220174632009               /* im */
    }, { 1.1467304744553617,           /* re */
      0.989176509964781                /* im */
    }, { 1.1497645346773215,           /* re */
      0.9887216919603238               /* im */
    }, { 1.1527971852584433,           /* re */
      0.9882575677307495               /* im */
    }, { 1.1558283976542651,           /* re */
      0.9877841416445722               /* im */
    }, { 1.1588581433338614,           /* re */
      0.9873014181578584               /* im */
    }, { 1.1618863937801118,           /* re */
      0.9868094018141855               /* im */
    }, { 1.1649131204899699,           /* re */
      0.9863080972445987               /* im */
    }, { 1.1679382949747312,           /* re */
      0.9857975091675675               /* im */
    }, { 1.1709618887603013,           /* re */
      0.9852776423889412               /* im */
    }, { 1.173983873387464,            /* re */
      0.9847485018019042               /* im */
    }, { 1.1770042204121487,           /* re */
      0.984210092386929                /* im */
    }, { 1.1800229014056995,           /* re */
      0.9836624192117303               /* im */
    }, { 1.183039887955141,            /* re */
      0.9831054874312163               /* im */
    }, { 1.1860551516634465,           /* re */
      0.9825393022874412               /* im */
    }, { 1.1890686641498063,           /* re */
      0.9819638691095552               /* im */
    }, { 1.1920803970498923,           /* re */
      0.9813791933137546               /* im */
    }, { 1.1950903220161282,           /* re */
      0.9807852804032304               /* im */
    }, { 1.1980984107179535,           /* re */
      0.9801821359681174               /* im */
    }, { 1.201104634842092,            /* re */
      0.9795697656854405               /* im */
    }, { 1.2041089660928168,           /* re */
      0.9789481753190622               /* im */
    }, { 1.2071113761922185,           /* re */
      0.9783173707196277               /* im */
    }, { 1.2101118368804695,           /* re */
      0.9776773578245099               /* im */
    }, { 1.2131103199160913,           /* re */
      0.9770281426577544               /* im */
    }, { 1.2161067970762196,           /* re */
      0.9763697313300211               /* im */
    }, { 1.2191012401568697,           /* re */
      0.9757021300385286               /* im */
    }, { 1.2220936209732036,           /* re */
      0.9750253450669941               /* im */
    }, { 1.2250839113597929,           /* re */
      0.9743393827855759               /* im */
    }, { 1.2280720831708858,           /* re */
      0.973644249650812                /* im */
    }, { 1.231058108280671,            /* re */
      0.9729399522055602               /* im */
    }, { 1.2340419585835434,           /* re */
      0.9722264970789363               /* im */
    }, { 1.2370236059943671,           /* re */
      0.9715038909862518               /* im */
    }, { 1.2400030224487415,           /* re */
      0.9707721407289504               /* im */
    }, { 1.2429801799032638,           /* re */
      0.970031253194544                /* im */
    }, { 1.2459550503357946,           /* re */
      0.9692812353565485               /* im */
    }, { 1.2489276057457201,           /* re */
      0.9685220942744173               /* im */
    }, { 1.2518978181542169,           /* re */
      0.9677538370934755               /* im */
    }, { 1.2548656596045147,           /* re */
      0.9669764710448521               /* im */
    }, { 1.257831102162159,            /* re */
      0.9661900034454125               /* im */
    }, { 1.2607941179152755,           /* re */
      0.9653944416976894               /* im */
    }, { 1.2637546789748313,           /* re */
      0.9645897932898128               /* im */
    }, { 1.2667127574748984,           /* re */
      0.9637760657954398               /* im */
    }, { 1.269668325572915,            /* re */
      0.9629532668736839               /* im */
    }, { 1.272621355449949,            /* re */
      0.9621214042690416               /* im */
    }, { 1.2755718193109582,           /* re */
      0.9612804858113206               /* im */
    }, { 1.278519689385053,            /* re */
      0.9604305194155658               /* im */
    }, { 1.2814649379257579,           /* re */
      0.9595715130819845               /* im */
    }, { 1.2844075372112718,           /* re */
      0.9587034748958716               /* im */
    }, { 1.2873474595447294,           /* re */
      0.9578264130275329               /* im */
    }, { 1.2902846772544623,           /* re */
      0.9569403357322088               /* im */
    }, { 1.2932191626942586,           /* re */
      0.9560452513499964               /* im */
    }, { 1.296150888243624,            /* re */
      0.9551411683057708               /* im */
    }, { 1.2990798263080405,           /* re */
      0.9542280951091057               /* im */
    }, { 1.302005949319228,            /* re */
      0.9533060403541939               /* im */
    }, { 1.3049292297354023,           /* re */
      0.9523750127197659               /* im */
    }, { 1.307849640041535,            /* re */
      0.9514350209690083               /* im */
    }, { 1.3107671527496114,           /* re */
      0.9504860739494817               /* im */
    }, { 1.3136817403988914,           /* re */
      0.9495281805930367               /* im */
    }, { 1.3165933755561658,           /* re */
      0.9485613499157303               /* im */
    }, { 1.3195020308160157,           /* re */
      0.9475855910177411               /* im */
    }, { 1.32240767880107,             /* re */
      0.9466009130832835               /* im */
    }, { 1.3253102921622628,           /* re */
      0.9456073253805213               /* im */
    }, { 1.3282098435790926,           /* re */
      0.9446048372614803               /* im */
    }, { 1.3311063057598764,           /* re */
      0.9435934581619604               /* im */
    }, { 1.3339996514420094,           /* re */
      0.9425731976014469               /* im */
    }, { 1.33688985339222,             /* re */
      0.9415440651830208               /* im */
    }, { 1.339776884406827,            /* re */
      0.9405060705932683               /* im */
    }, { 1.3426607173119944,           /* re */
      0.9394592236021899               /* im */
    }, { 1.3455413249639891,           /* re */
      0.9384035340631081               /* im */
    }, { 1.3484186802494347,           /* re */
      0.937339011912575                /* im */
    }, { 1.351292756085567,            /* re */
      0.9362656671702783               /* im */
    }, { 1.3541635254204905,           /* re */
      0.9351835099389476               /* im */
    }, { 1.35703096123343,             /* re */
      0.9340925504042589               /* im */
    }, { 1.3598950365349882,           /* re */
      0.932992798834739                /* im */
    }, { 1.3627557243673971,           /* re */
      0.9318842655816681               /* im */
    }, { 1.365612997804774,            /* re */
      0.9307669610789837               /* im */
    }, { 1.3684668299533724,           /* re */
      0.9296408958431812               /* im */
    }, { 1.3713171939518376,           /* re */
      0.9285060804732156               /* im */
    }, { 1.374164062971458,            /* re */
      0.9273625256504011               /* im */
    }, { 1.3770074102164183,           /* re */
      0.9262102421383114               /* im */
    }, { 1.3798472089240512,           /* re */
      0.9250492407826776               /* im */
    }, { 1.3826834323650898,           /* re */
      0.9238795325112867               /* im */
    }, { 1.3855160538439188,           /* re */
      0.9227011283338786               /* im */
    }, { 1.3883450466988263,           /* re */
      0.9215140393420419               /* im */
    }, { 1.3911703843022538,           /* re */
      0.9203182767091106               /* im */
    }, { 1.3939920400610482,           /* re */
      0.9191138516900578               /* im */
    }, { 1.3968099874167104,           /* re */
      0.9179007756213905               /* im */
    }, { 1.399624199845647,            /* re */
      0.9166790599210427               /* im */
    }, { 1.4024346508594183,           /* re */
      0.9154487160882678               /* im */
    }, { 1.4052413140049897,           /* re */
      0.9142097557035307               /* im */
    }, { 1.4080441628649787,           /* re */
      0.9129621904283982               /* im */
    }, { 1.410843171057904,            /* re */
      0.9117060320054299               /* im */
    }, { 1.4136383122384344,           /* re */
      0.9104412922580672               /* im */
    }, { 1.416429560097637,            /* re */
      0.9091679830905224               /* im */
    }, { 1.419216888363224,            /* re */
      0.9078861164876663               /* im */
    }, { 1.4220002707997996,           /* re */
      0.9065957045149153               /* im */
    }, { 1.4247796812091087,           /* re */
      0.9052967593181188               /* im */
    }, { 1.427555093430282,            /* re */
      0.9039892931234433               /* im */
    }, { 1.4303264813400827,           /* re */
      0.9026733182372588               /* im */
    }, { 1.433093818853152,            /* re */
      0.901348847046022                /* im */
    }, { 1.4358570799222554,           /* re */
      0.9000158920161602               /* im */
    }, { 1.4386162385385277,           /* re */
      0.8986744656939538               /* im */
    }, { 1.4413712687317166,           /* re */
      0.8973245807054183               /* im */
    }, { 1.444122144570429,            /* re */
      0.8959662497561852               /* im */
    }, { 1.4468688401623742,           /* re */
      0.8945994856313827               /* im */
    }, { 1.4496113296546065,           /* re */
      0.8932243011955153               /* im */
    }, { 1.4523495872337708,           /* re */
      0.8918407093923427               /* im */
    }, { 1.455083587126344,            /* re */
      0.8904487232447579               /* im */
    }, { 1.4578133035988772,           /* re */
      0.8890483558546646               /* im */
    }, { 1.46053871095824,             /* re */
      0.8876396204028539               /* im */
    }, { 1.4632597835518601,           /* re */
      0.8862225301488806               /* im */
    }, { 1.4659764957679662,           /* re */
      0.8847970984309378               /* im */
    }, { 1.468688822035828,            /* re */
      0.8833633386657316               /* im */
    }, { 1.4713967368259977,           /* re */
      0.881921264348355                /* im */
    }, { 1.47410021465055,             /* re */
      0.8804708890521608               /* im */
    }, { 1.4767992300633221,           /* re */
      0.8790122264286335               /* im */
    }, { 1.479493757660153,            /* re */
      0.8775452902072614               /* im */
    }, { 1.4821837720791227,           /* re */
      0.8760700941954066               /* im */
    }, { 1.484869248000791,            /* re */
      0.8745866522781761               /* im */
    }, { 1.487550160148436,            /* re */
      0.8730949784182901               /* im */
    }, { 1.4902264832882912,           /* re */
      0.8715950866559511               /* im */
    }, { 1.492898192229784,            /* re */
      0.8700869911087115               /* im */
    }, { 1.4955652618257727,           /* re */
      0.8685707059713409               /* im */
    }, { 1.4982276669727819,           /* re */
      0.8670462455156926               /* im */
    }, { 1.5008853826112407,           /* re */
      0.8655136240905691               /* im */
    }, { 1.5035383837257177,           /* re */
      0.8639728561215867               /* im */
    }, { 1.5061866453451551,           /* re */
      0.8624239561110405               /* im */
    }, { 1.508830142543107,            /* re */
      0.8608669386377673               /* im */
    }, { 1.5114688504379703,           /* re */
      0.8593018183570085               /* im */
    }, { 1.5141027441932216,           /* re */
      0.8577286100002721               /* im */
    }, { 1.5167317990176499,           /* re */
      0.8561473283751945               /* im */
    }, { 1.5193559901655895,           /* re */
      0.8545579883654005               /* im */
    }, { 1.5219752929371544,           /* re */
      0.8529606049303636               /* im */
    }, { 1.524589682678469,            /* re */
      0.8513551931052652               /* im */
    }, { 1.5271991347819012,           /* re */
      0.8497417680008525               /* im */
    }, { 1.5298036246862945,           /* re */
      0.8481203448032972               /* im */
    }, { 1.532403127877198,            /* re */
      0.8464909387740521               /* im */
    }, { 1.5349976198870972,           /* re */
      0.8448535652497071               /* im */
    }, { 1.5375870762956454,           /* re */
      0.8432082396418454               /* im */
    }, { 1.540171472729893,            /* re */
      0.8415549774368984               /* im */
    }, { 1.542750784864516,            /* re */
      0.8398937941959995               /* im */
    }, { 1.5453249884220464,           /* re */
      0.8382247055548381               /* im */
    }, { 1.5478940591731,              /* re */
      0.836547727223512                /* im */
    }, { 1.5504579729366048,           /* re */
      0.83486287498638                 /* im */
    }, { 1.5530167055800275,           /* re */
      0.8331701647019132               /* im */
    }, { 1.5555702330196022,           /* re */
      0.8314696123025452               /* im */
    }, { 1.558118531220556,            /* re */
      0.829761233794523                /* im */
    }, { 1.5606615761973361,           /* re */
      0.8280450452577558               /* im */
    }, { 1.563199344013834,            /* re */
      0.8263210628456635               /* im */
    }, { 1.5657318107836131,           /* re */
      0.8245893027850253               /* im */
    }, { 1.5682589526701314,           /* re */
      0.8228497813758264               /* im */
    }, { 1.5707807458869674,           /* re */
      0.8211025149911046               /* im */
    }, { 1.5732971666980422,           /* re */
      0.819347520076797                /* im */
    }, { 1.5758081914178454,           /* re */
      0.8175848131515837               /* im */
    }, { 1.5783137964116556,           /* re */
      0.8158144108067338               /* im */
    }, { 1.5808139580957645,           /* re */
      0.8140363297059484               /* im */
    }, { 1.5833086529376983,           /* re */
      0.8122505865852039               /* im */
    }, { 1.5857978574564389,           /* re */
      0.8104571982525948               /* im */
    }, { 1.5882815482226453,           /* re */
      0.808656181588175                /* im */
    }, { 1.5907597018588742,           /* re */
      0.8068475535437993               /* im */
    }, { 1.5932322950397997,           /* re */
      0.8050313311429637               /* im */
    }, { 1.5956993044924332,           /* re */
      0.8032075314806449               /* im */
    }, { 1.5981607069963424,           /* re */
      0.8013761717231402               /* im */
    }, { 1.600616479383869,            /* re */
      0.799537269107905                /* im */
    }, { 1.603066598540348,            /* re */
      0.7976908409433912               /* im */
    }, { 1.6055110414043257,           /* re */
      0.7958369046088836               /* im */
    }, { 1.6079497849677735,           /* re */
      0.7939754775543372               /* im */
    }, { 1.6103828062763095,           /* re */
      0.7921065773002124               /* im */
    }, { 1.6128100824294096,           /* re */
      0.79023022143731                 /* im */
    }, { 1.6152315905806267,           /* re */
      0.7883464276266063               /* im */
    }, { 1.617647307937804,            /* re */
      0.7864552135990858               /* im */
    }, { 1.6200572117632892,           /* re */
      0.7845565971555752               /* im */
    }, { 1.62246127937415,             /* re */
      0.7826505961665757               /* im */
    }, { 1.6248594881423863,           /* re */
      0.7807372285720945               /* im */
    }, { 1.627251815495144,            /* re */
      0.778816512381476                /* im */
    }, { 1.6296382389149269,           /* re */
      0.7768884656732324               /* im */
    }, { 1.632018735939809,            /* re */
      0.7749531065948739               /* im */
    }, { 1.6343932841636455,           /* re */
      0.773010453362737                /* im */
    }, { 1.6367618612362842,           /* re */
      0.7710605242618138               /* im */
    }, { 1.6391244448637758,           /* re */
      0.7691033376455797               /* im */
    }, { 1.641481012808583,            /* re */
      0.7671389119358204               /* im */
    }, { 1.6438315428897914,           /* re */
      0.765167265622459                /* im */
    }, { 1.6461760129833163,           /* re */
      0.7631884172633813               /* im */
    }, { 1.6485144010221124,           /* re */
      0.7612023854842618               /* im */
    }, { 1.650846684996381,            /* re */
      0.759209188978388                /* im */
    }, { 1.6531728429537766,           /* re */
      0.7572088465064846               /* im */
    }, { 1.6554928529996153,           /* re */
      0.7552013768965365               /* im */
    }, { 1.6578066932970787,           /* re */
      0.7531867990436125               /* im */
    }, { 1.6601143420674205,           /* re */
      0.7511651319096864               /* im */
    }, { 1.6624157775901718,           /* re */
      0.7491363945234594               /* im */
    }, { 1.664710978203345,            /* re */
      0.7471006059801801               /* im */
    }, { 1.6669999223036376,           /* re */
      0.745057785441466                /* im */
    }, { 1.669282588346636,            /* re */
      0.7430079521351217               /* im */
    }, { 1.6715589548470184,           /* re */
      0.7409511253549592               /* im */
    }, { 1.6738290003787561,           /* re */
      0.7388873244606151               /* im */
    }, { 1.676092703575316,            /* re */
      0.7368165688773698               /* im */
    }, { 1.6783500431298615,           /* re */
      0.7347388780959635               /* im */
    }, { 1.680600997795453,            /* re */
      0.7326542716724128               /* im */
    }, { 1.682845546385248,            /* re */
      0.7305627692278276               /* im */
    }, { 1.6850836677727004,           /* re */
      0.7284643904482252               /* im */
    }, { 1.6873153408917592,           /* re */
      0.726359155084346                /* im */
    }, { 1.6895405447370668,           /* re */
      0.724247082951467                /* im */
    }, { 1.6917592583641579,           /* re */
      0.7221281939292153               /* im */
    }, { 1.693971460889654,            /* re */
      0.7200025079613817               /* im */
    }, { 1.696177131491463,            /* re */
      0.7178700450557317               /* im */
    }, { 1.698376249408973,            /* re */
      0.7157308252838186               /* im */
    }, { 1.7005687939432483,           /* re */
      0.7135848687807935               /* im */
    }, { 1.7027547444572253,           /* re */
      0.7114321957452164               /* im */
    }, { 1.7049340803759048,           /* re */
      0.7092728264388657               /* im */
    }, { 1.7071067811865475,           /* re */
      0.7071067811865476               /* im */
    }, { 1.7092728264388657,           /* re */
      0.7049340803759049               /* im */
    }, { 1.7114321957452163,           /* re */
      0.7027547444572253               /* im */
    }, { 1.7135848687807935,           /* re */
      0.7005687939432483               /* im */
    }, { 1.7157308252838186,           /* re */
      0.6983762494089729               /* im */
    }, { 1.7178700450557316,           /* re */
      0.696177131491463                /* im */
    }, { 1.7200025079613817,           /* re */
      0.6939714608896539               /* im */
    }, { 1.7221281939292155,           /* re */
      0.6917592583641577               /* im */
    }, { 1.7242470829514671,           /* re */
      0.6895405447370668               /* im */
    }, { 1.726359155084346,            /* re */
      0.687315340891759                /* im */
    }, { 1.728464390448225,            /* re */
      0.6850836677727004               /* im */
    }, { 1.7305627692278276,           /* re */
      0.6828455463852481               /* im */
    }, { 1.7326542716724127,           /* re */
      0.680600997795453                /* im */
    }, { 1.7347388780959636,           /* re */
      0.6783500431298615               /* im */
    }, { 1.7368165688773698,           /* re */
      0.6760927035753159               /* im */
    }, { 1.7388873244606151,           /* re */
      0.673829000378756                /* im */
    }, { 1.7409511253549592,           /* re */
      0.6715589548470183               /* im */
    }, { 1.7430079521351218,           /* re */
      0.669282588346636                /* im */
    }, { 1.745057785441466,            /* re */
      0.6669999223036375               /* im */
    }, { 1.7471006059801801,           /* re */
      0.6647109782033448               /* im */
    }, { 1.7491363945234593,           /* re */
      0.6624157775901718               /* im */
    }, { 1.7511651319096864,           /* re */
      0.6601143420674205               /* im */
    }, { 1.7531867990436125,           /* re */
      0.6578066932970786               /* im */
    }, { 1.7552013768965367,           /* re */
      0.6554928529996153               /* im */
    }, { 1.7572088465064846,           /* re */
      0.6531728429537768               /* im */
    }, { 1.7592091889783878,           /* re */
      0.650846684996381                /* im */
    }, { 1.7612023854842618,           /* re */
      0.6485144010221124               /* im */
    }, { 1.7631884172633812,           /* re */
      0.6461760129833163               /* im */
    }, { 1.765167265622459,            /* re */
      0.6438315428897914               /* im */
    }, { 1.7671389119358203,           /* re */
      0.641481012808583                /* im */
    }, { 1.7691033376455798,           /* re */
      0.6391244448637757               /* im */
    }, { 1.7710605242618138,           /* re */
      0.6367618612362842               /* im */
    }, { 1.7730104533627369,           /* re */
      0.6343932841636455               /* im */
    }, { 1.7749531065948738,           /* re */
      0.6320187359398091               /* im */
    }, { 1.7768884656732324,           /* re */
      0.629638238914927                /* im */
    }, { 1.7788165123814759,           /* re */
      0.6272518154951441               /* im */
    }, { 1.7807372285720944,           /* re */
      0.6248594881423863               /* im */
    }, { 1.7826505961665757,           /* re */
      0.62246127937415                 /* im */
    }, { 1.7845565971555752,           /* re */
      0.6200572117632891               /* im */
    }, { 1.7864552135990857,           /* re */
      0.6176473079378039               /* im */
    }, { 1.7883464276266063,           /* re */
      0.6152315905806268               /* im */
    }, { 1.79023022143731,             /* re */
      0.6128100824294097               /* im */
    }, { 1.7921065773002125,           /* re */
      0.6103828062763095               /* im */
    }, { 1.793975477554337,            /* re */
      0.6079497849677736               /* im */
    }, { 1.7958369046088836,           /* re */
      0.6055110414043255               /* im */
    }, { 1.7976908409433912,           /* re */
      0.6030665985403482               /* im */
    }, { 1.799537269107905,            /* re */
      0.600616479383869                /* im */
    }, { 1.8013761717231402,           /* re */
      0.5981607069963424               /* im */
    }, { 1.8032075314806448,           /* re */
      0.5956993044924334               /* im */
    }, { 1.8050313311429638,           /* re */
      0.5932322950397998               /* im */
    }, { 1.8068475535437993,           /* re */
      0.5907597018588742               /* im */
    }, { 1.808656181588175,            /* re */
      0.5882815482226452               /* im */
    }, { 1.8104571982525948,           /* re */
      0.5857978574564389               /* im */
    }, { 1.8122505865852039,           /* re */
      0.5833086529376983               /* im */
    }, { 1.8140363297059485,           /* re */
      0.5808139580957645               /* im */
    }, { 1.8158144108067338,           /* re */
      0.5783137964116556               /* im */
    }, { 1.8175848131515837,           /* re */
      0.5758081914178453               /* im */
    }, { 1.819347520076797,            /* re */
      0.5732971666980422               /* im */
    }, { 1.8211025149911046,           /* re */
      0.5707807458869673               /* im */
    }, { 1.8228497813758264,           /* re */
      0.5682589526701315               /* im */
    }, { 1.8245893027850253,           /* re */
      0.5657318107836131               /* im */
    }, { 1.8263210628456634,           /* re */
      0.5631993440138341               /* im */
    }, { 1.8280450452577557,           /* re */
      0.560661576197336                /* im */
    }, { 1.829761233794523,            /* re */
      0.5581185312205561               /* im */
    }, { 1.8314696123025453,           /* re */
      0.5555702330196022               /* im */
    }, { 1.8331701647019132,           /* re */
      0.5530167055800275               /* im */
    }, { 1.83486287498638,             /* re */
      0.5504579729366048               /* im */
    }, { 1.836547727223512,            /* re */
      0.5478940591731002               /* im */
    }, { 1.838224705554838,            /* re */
      0.5453249884220465               /* im */
    }, { 1.8398937941959996,           /* re */
      0.5427507848645159               /* im */
    }, { 1.8415549774368984,           /* re */
      0.5401714727298929               /* im */
    }, { 1.8432082396418454,           /* re */
      0.5375870762956454               /* im */
    }, { 1.8448535652497071,           /* re */
      0.5349976198870972               /* im */
    }, { 1.846490938774052,            /* re */
      0.5324031278771979               /* im */
    }, { 1.8481203448032972,           /* re */
      0.5298036246862946               /* im */
    }, { 1.8497417680008525,           /* re */
      0.5271991347819013               /* im */
    }, { 1.8513551931052652,           /* re */
      0.524589682678469                /* im */
    }, { 1.8529606049303635,           /* re */
      0.5219752929371544               /* im */
    }, { 1.8545579883654004,           /* re */
      0.5193559901655896               /* im */
    }, { 1.8561473283751946,           /* re */
      0.5167317990176499               /* im */
    }, { 1.8577286100002721,           /* re */
      0.5141027441932217               /* im */
    }, { 1.8593018183570085,           /* re */
      0.5114688504379703               /* im */
    }, { 1.8608669386377672,           /* re */
      0.508830142543107                /* im */
    }, { 1.8624239561110405,           /* re */
      0.5061866453451552               /* im */
    }, { 1.8639728561215867,           /* re */
      0.5035383837257176               /* im */
    }, { 1.865513624090569,            /* re */
      0.5008853826112407               /* im */
    }, { 1.8670462455156926,           /* re */
      0.4982276669727818               /* im */
    }, { 1.868570705971341,            /* re */
      0.49556526182577254              /* im */
    }, { 1.8700869911087115,           /* re */
      0.49289819222978404              /* im */
    }, { 1.871595086655951,            /* re */
      0.49022648328829116              /* im */
    }, { 1.87309497841829,             /* re */
      0.487550160148436                /* im */
    }, { 1.8745866522781762,           /* re */
      0.48486924800079106              /* im */
    }, { 1.8760700941954065,           /* re */
      0.4821837720791227               /* im */
    }, { 1.8775452902072614,           /* re */
      0.47949375766015295              /* im */
    }, { 1.8790122264286335,           /* re */
      0.4767992300633221               /* im */
    }, { 1.8804708890521606,           /* re */
      0.47410021465054997              /* im */
    }, { 1.881921264348355,            /* re */
      0.47139673682599764              /* im */
    }, { 1.8833633386657316,           /* re */
      0.46868882203582796              /* im */
    }, { 1.884797098430938,            /* re */
      0.4659764957679662               /* im */
    }, { 1.8862225301488806,           /* re */
      0.46325978355186015              /* im */
    }, { 1.887639620402854,            /* re */
      0.46053871095824                 /* im */
    }, { 1.8890483558546647,           /* re */
      0.4578133035988772               /* im */
    }, { 1.890448723244758,            /* re */
      0.45508358712634384              /* im */
    }, { 1.8918407093923428,           /* re */
      0.4523495872337709               /* im */
    }, { 1.8932243011955152,           /* re */
      0.44961132965460654              /* im */
    }, { 1.8945994856313826,           /* re */
      0.44686884016237416              /* im */
    }, { 1.895966249756185,            /* re */
      0.4441221445704292               /* im */
    }, { 1.8973245807054182,           /* re */
      0.44137126873171667              /* im */
    }, { 1.8986744656939538,           /* re */
      0.43861623853852766              /* im */
    }, { 1.9000158920161603,           /* re */
      0.4358570799222555               /* im */
    }, { 1.901348847046022,            /* re */
      0.43309381885315196              /* im */
    }, { 1.9026733182372588,           /* re */
      0.4303264813400826               /* im */
    }, { 1.9039892931234434,           /* re */
      0.4275550934302821               /* im */
    }, { 1.905296759318119,            /* re */
      0.4247796812091088               /* im */
    }, { 1.9065957045149153,           /* re */
      0.4220002707997997               /* im */
    }, { 1.9078861164876662,           /* re */
      0.4192168883632239               /* im */
    }, { 1.9091679830905224,           /* re */
      0.41642956009763715              /* im */
    }, { 1.9104412922580671,           /* re */
      0.4136383122384345               /* im */
    }, { 1.91170603200543,             /* re */
      0.4108431710579039               /* im */
    }, { 1.9129621904283982,           /* re */
      0.4080441628649787               /* im */
    }, { 1.9142097557035307,           /* re */
      0.40524131400498986              /* im */
    }, { 1.9154487160882678,           /* re */
      0.40243465085941843              /* im */
    }, { 1.9166790599210426,           /* re */
      0.3996241998456468               /* im */
    }, { 1.9179007756213906,           /* re */
      0.3968099874167103               /* im */
    }, { 1.9191138516900579,           /* re */
      0.3939920400610481               /* im */
    }, { 1.9203182767091107,           /* re */
      0.39117038430225387              /* im */
    }, { 1.9215140393420418,           /* re */
      0.38834504669882625              /* im */
    }, { 1.9227011283338786,           /* re */
      0.38551605384391885              /* im */
    }, { 1.9238795325112867,           /* re */
      0.3826834323650898               /* im */
    }, { 1.9250492407826776,           /* re */
      0.37984720892405116              /* im */
    }, { 1.9262102421383114,           /* re */
      0.37700741021641826              /* im */
    }, { 1.927362525650401,            /* re */
      0.37416406297145793              /* im */
    }, { 1.9285060804732157,           /* re */
      0.3713171939518375               /* im */
    }, { 1.9296408958431812,           /* re */
      0.3684668299533723               /* im */
    }, { 1.9307669610789837,           /* re */
      0.36561299780477385              /* im */
    }, { 1.9318842655816681,           /* re */
      0.3627557243673972               /* im */
    }, { 1.9329927988347388,           /* re */
      0.3598950365349881               /* im */
    }, { 1.9340925504042588,           /* re */
      0.35703096123343                 /* im */
    }, { 1.9351835099389476,           /* re */
      0.35416352542049034              /* im */
    }, { 1.9362656671702783,           /* re */
      0.3512927560855671               /* im */
    }, { 1.937339011912575,            /* re */
      0.34841868024943456              /* im */
    }, { 1.938403534063108,            /* re */
      0.3455413249639891               /* im */
    }, { 1.93945922360219,             /* re */
      0.3426607173119944               /* im */
    }, { 1.9405060705932682,           /* re */
      0.33977688440682685              /* im */
    }, { 1.9415440651830207,           /* re */
      0.33688985339222005              /* im */
    }, { 1.9425731976014469,           /* re */
      0.3339996514420094               /* im */
    }, { 1.9435934581619603,           /* re */
      0.33110630575987643              /* im */
    }, { 1.9446048372614801,           /* re */
      0.3282098435790925               /* im */
    }, { 1.9456073253805213,           /* re */
      0.3253102921622629               /* im */
    }, { 1.9466009130832835,           /* re */
      0.32240767880106985              /* im */
    }, { 1.947585591017741,            /* re */
      0.3195020308160157               /* im */
    }, { 1.9485613499157304,           /* re */
      0.31659337555616585              /* im */
    }, { 1.9495281805930367,           /* re */
      0.3136817403988915               /* im */
    }, { 1.9504860739494818,           /* re */
      0.3107671527496115               /* im */
    }, { 1.9514350209690083,           /* re */
      0.30784964004153487              /* im */
    }, { 1.9523750127197659,           /* re */
      0.3049292297354024               /* im */
    }, { 1.9533060403541938,           /* re */
      0.3020059493192281               /* im */
    }, { 1.9542280951091056,           /* re */
      0.2990798263080405               /* im */
    }, { 1.955141168305771,            /* re */
      0.2961508882436238               /* im */
    }, { 1.9560452513499964,           /* re */
      0.29321916269425863              /* im */
    }, { 1.9569403357322088,           /* re */
      0.29028467725446233              /* im */
    }, { 1.957826413027533,            /* re */
      0.2873474595447295               /* im */
    }, { 1.9587034748958716,           /* re */
      0.2844075372112719               /* im */
    }, { 1.9595715130819844,           /* re */
      0.28146493792575794              /* im */
    }, { 1.9604305194155658,           /* re */
      0.27851968938505306              /* im */
    }, { 1.9612804858113206,           /* re */
      0.27557181931095814              /* im */
    }, { 1.9621214042690416,           /* re */
      0.272621355449949                /* im */
    }, { 1.9629532668736838,           /* re */
      0.2696683255729151               /* im */
    }, { 1.96377606579544,             /* re */
      0.26671275747489837              /* im */
    }, { 1.9645897932898126,           /* re */
      0.26375467897483135              /* im */
    }, { 1.9653944416976894,           /* re */
      0.2607941179152755               /* im */
    }, { 1.9661900034454125,           /* re */
      0.257831102162159                /* im */
    }, { 1.966976471044852,            /* re */
      0.25486565960451457              /* im */
    }, { 1.9677538370934755,           /* re */
      0.25189781815421697              /* im */
    }, { 1.9685220942744173,           /* re */
      0.24892760574572015              /* im */
    }, { 1.9692812353565485,           /* re */
      0.2459550503357946               /* im */
    }, { 1.970031253194544,            /* re */
      0.24298017990326387              /* im */
    }, { 1.9707721407289505,           /* re */
      0.2400030224487415               /* im */
    }, { 1.9715038909862517,           /* re */
      0.2370236059943672               /* im */
    }, { 1.9722264970789363,           /* re */
      0.23404195858354343              /* im */
    }, { 1.9729399522055602,           /* re */
      0.2310581082806711               /* im */
    }, { 1.973644249650812,            /* re */
      0.22807208317088573              /* im */
    }, { 1.9743393827855757,           /* re */
      0.22508391135979283              /* im */
    }, { 1.9750253450669941,           /* re */
      0.2220936209732035               /* im */
    }, { 1.9757021300385285,           /* re */
      0.2191012401568698               /* im */
    }, { 1.976369731330021,            /* re */
      0.21610679707621952              /* im */
    }, { 1.9770281426577543,           /* re */
      0.21311031991609136              /* im */
    }, { 1.97767735782451,             /* re */
      0.2101118368804696               /* im */
    }, { 1.9783173707196275,           /* re */
      0.20711137619221856              /* im */
    }, { 1.9789481753190623,           /* re */
      0.20410896609281687              /* im */
    }, { 1.9795697656854405,           /* re */
      0.2011046348420919               /* im */
    }, { 1.9801821359681173,           /* re */
      0.19809841071795356              /* im */
    }, { 1.9807852804032304,           /* re */
      0.19509032201612825              /* im */
    }, { 1.9813791933137546,           /* re */
      0.19208039704989244              /* im */
    }, { 1.9819638691095554,           /* re */
      0.1890686641498062               /* im */
    }, { 1.9825393022874414,           /* re */
      0.18605515166344663              /* im */
    }, { 1.9831054874312164,           /* re */
      0.18303988795514095              /* im */
    }, { 1.9836624192117303,           /* re */
      0.18002290140569951              /* im */
    }, { 1.984210092386929,            /* re */
      0.17700422041214875              /* im */
    }, { 1.9847485018019042,           /* re */
      0.17398387338746382              /* im */
    }, { 1.985277642388941,            /* re */
      0.17096188876030122              /* im */
    }, { 1.9857975091675675,           /* re */
      0.16793829497473117              /* im */
    }, { 1.9863080972445988,           /* re */
      0.16491312048996992              /* im */
    }, { 1.9868094018141855,           /* re */
      0.16188639378011183              /* im */
    }, { 1.9873014181578585,           /* re */
      0.15885814333386145              /* im */
    }, { 1.987784141644572,            /* re */
      0.15582839765426523              /* im */
    }, { 1.9882575677307495,           /* re */
      0.15279718525844344              /* im */
    }, { 1.9887216919603237,           /* re */
      0.1497645346773215               /* im */
    }, { 1.9891765099647811,           /* re */
      0.14673047445536175              /* im */
    }, { 1.9896220174632009,           /* re */
      0.14369503315029447              /* im */
    }, { 1.9900582102622972,           /* re */
      0.1406582393328492               /* im */
    }, { 1.990485084256457,            /* re */
      0.13762012158648604              /* im */
    }, { 1.99090263542778,             /* re */
      0.13458070850712617              /* im */
    }, { 1.9913108598461156,           /* re */
      0.13154002870288312              /* im */
    }, { 1.9917097536690995,           /* re */
      0.12849811079379317              /* im */
    }, { 1.9920993131421918,           /* re */
      0.12545498341154623              /* im */
    }, { 1.99247953459871,             /* re */
      0.1224106751992162               /* im */
    }, { 1.992850414459865,            /* re */
      0.11936521481099135              /* im */
    }, { 1.9932119492347944,           /* re */
      0.11631863091190475              /* im */
    }, { 1.9935641355205953,           /* re */
      0.11327095217756435              /* im */
    }, { 1.9939069700023562,           /* re */
      0.11022220729388306              /* im */
    }, { 1.994240449453188,            /* re */
      0.10717242495680884              /* im */
    }, { 1.9945645707342554,           /* re */
      0.10412163387205459              /* im */
    }, { 1.9948793307948056,           /* re */
      0.10106986275482782              /* im */
    }, { 1.995184726672197,            /* re */
      0.0980171403295606               /* im */
    }, { 1.995480755491927,            /* re */
      0.09496349532963899              /* im */
    }, { 1.9957674144676598,           /* re */
      0.09190895649713272              /* im */
    }, { 1.996044700901252,            /* re */
      0.0888535525825246               /* im */
    }, { 1.996312612182778,            /* re */
      0.0857973123444399               /* im */
    }, { 1.9965711457905548,           /* re */
      0.08274026454937569              /* im */
    }, { 1.9968202992911657,           /* re */
      0.07968243797143013              /* im */
    }, { 1.997060070339483,            /* re */
      0.07662386139203149              /* im */
    }, { 1.9972904566786902,           /* re */
      0.07356456359966743              /* im */
    }, { 1.9975114561403036,           /* re */
      0.07050457338961386              /* im */
    }, { 1.9977230666441916,           /* re */
      0.06744391956366405              /* im */
    }, { 1.9979252861985959,           /* re */
      0.06438263092985747              /* im */
    }, { 1.998118112900149,            /* re */
      0.06132073630220858              /* im */
    }, { 1.9983015449338928,           /* re */
      0.05825826450043575              /* im */
    }, { 1.9984755805732948,           /* re */
      0.05519524434968994              /* im */
    }, { 1.9986402181802654,           /* re */
      0.052131704680283324             /* im */
    }, { 1.9987954562051724,           /* re */
      0.049067674327418015             /* im */
    }, { 1.9989412931868569,           /* re */
      0.04600318213091462              /* im */
    }, { 1.9990777277526455,           /* re */
      0.04293825693494082              /* im */
    }, { 1.9992047586183639,           /* re */
      0.03987292758773981              /* im */
    }, { 1.9993223845883494,           /* re */
      0.03680722294135883              /* im */
    }, { 1.9994306045554617,           /* re */
      0.03374117185137758              /* im */
    }, { 1.9995294175010931,           /* re */
      0.030674803176636626             /* im */
    }, { 1.9996188224951785,           /* re */
      0.02760814577896574              /* im */
    }, { 1.9996988186962041,           /* re */
      0.024541228522912288             /* im */
    }, { 1.9997694053512154,           /* re */
      0.021474080275469508             /* im */
    }, { 1.9998305817958233,           /* re */
      0.01840672990580482              /* im */
    }, { 1.9998823474542125,           /* re */
      0.0153392062849881               /* im */
    }, { 1.9999247018391446,           /* re */
      0.012271538285719925             /* im */
    }, { 1.999957644551964,            /* re */
      0.00920375478205982              /* im */
    }, { 1.999981175282601,            /* re */
      0.006135884649154475             /* im */
    }, { 1.9999952938095762,           /* re */
      0.003067956762965976             /* im */
    }, { 2.0,                          /* re */
      0.0                              /* im */
    }, { 1.9999952938095762,           /* re */
      -0.003067956762965976            /* im */
    }, { 1.999981175282601,            /* re */
      -0.006135884649154475            /* im */
    }, { 1.999957644551964,            /* re */
      -0.00920375478205982             /* im */
    }, { 1.9999247018391446,           /* re */
      -0.012271538285719925            /* im */
    }, { 1.9998823474542125,           /* re */
      -0.0153392062849881              /* im */
    }, { 1.9998305817958233,           /* re */
      -0.01840672990580482             /* im */
    }, { 1.9997694053512154,           /* re */
      -0.021474080275469508            /* im */
    }, { 1.9996988186962041,           /* re */
      -0.024541228522912288            /* im */
    }, { 1.9996188224951785,           /* re */
      -0.02760814577896574             /* im */
    }, { 1.9995294175010931,           /* re */
      -0.030674803176636626            /* im */
    }, { 1.9994306045554617,           /* re */
      -0.03374117185137758             /* im */
    }, { 1.9993223845883494,           /* re */
      -0.03680722294135883             /* im */
    }, { 1.9992047586183639,           /* re */
      -0.03987292758773981             /* im */
    }, { 1.9990777277526455,           /* re */
      -0.04293825693494082             /* im */
    }, { 1.9989412931868569,           /* re */
      -0.04600318213091462             /* im */
    }, { 1.9987954562051724,           /* re */
      -0.049067674327418015            /* im */
    }, { 1.9986402181802654,           /* re */
      -0.052131704680283324            /* im */
    }, { 1.9984755805732948,           /* re */
      -0.05519524434968994             /* im */
    }, { 1.9983015449338928,           /* re */
      -0.05825826450043575             /* im */
    }, { 1.998118112900149,            /* re */
      -0.06132073630220858             /* im */
    }, { 1.9979252861985959,           /* re */
      -0.06438263092985747             /* im */
    }, { 1.9977230666441916,           /* re */
      -0.06744391956366405             /* im */
    }, { 1.9975114561403036,           /* re */
      -0.07050457338961386             /* im */
    }, { 1.9972904566786902,           /* re */
      -0.07356456359966743             /* im */
    }, { 1.997060070339483,            /* re */
      -0.07662386139203149             /* im */
    }, { 1.9968202992911657,           /* re */
      -0.07968243797143013             /* im */
    }, { 1.9965711457905548,           /* re */
      -0.08274026454937569             /* im */
    }, { 1.996312612182778,            /* re */
      -0.0857973123444399              /* im */
    }, { 1.996044700901252,            /* re */
      -0.0888535525825246              /* im */
    }, { 1.9957674144676598,           /* re */
      -0.09190895649713272             /* im */
    }, { 1.995480755491927,            /* re */
      -0.09496349532963899             /* im */
    }, { 1.995184726672197,            /* re */
      -0.0980171403295606              /* im */
    }, { 1.9948793307948056,           /* re */
      -0.10106986275482782             /* im */
    }, { 1.9945645707342554,           /* re */
      -0.10412163387205459             /* im */
    }, { 1.994240449453188,            /* re */
      -0.10717242495680884             /* im */
    }, { 1.9939069700023562,           /* re */
      -0.11022220729388306             /* im */
    }, { 1.9935641355205953,           /* re */
      -0.11327095217756435             /* im */
    }, { 1.9932119492347944,           /* re */
      -0.11631863091190475             /* im */
    }, { 1.992850414459865,            /* re */
      -0.11936521481099135             /* im */
    }, { 1.99247953459871,             /* re */
      -0.1224106751992162              /* im */
    }, { 1.9920993131421918,           /* re */
      -0.12545498341154623             /* im */
    }, { 1.9917097536690995,           /* re */
      -0.12849811079379317             /* im */
    }, { 1.9913108598461156,           /* re */
      -0.13154002870288312             /* im */
    }, { 1.99090263542778,             /* re */
      -0.13458070850712617             /* im */
    }, { 1.990485084256457,            /* re */
      -0.13762012158648604             /* im */
    }, { 1.9900582102622972,           /* re */
      -0.1406582393328492              /* im */
    }, { 1.9896220174632009,           /* re */
      -0.14369503315029447             /* im */
    }, { 1.9891765099647811,           /* re */
      -0.14673047445536175             /* im */
    }, { 1.9887216919603237,           /* re */
      -0.1497645346773215              /* im */
    }, { 1.9882575677307495,           /* re */
      -0.15279718525844344             /* im */
    }, { 1.987784141644572,            /* re */
      -0.15582839765426523             /* im */
    }, { 1.9873014181578585,           /* re */
      -0.15885814333386145             /* im */
    }, { 1.9868094018141855,           /* re */
      -0.16188639378011183             /* im */
    }, { 1.9863080972445988,           /* re */
      -0.16491312048996992             /* im */
    }, { 1.9857975091675675,           /* re */
      -0.16793829497473117             /* im */
    }, { 1.985277642388941,            /* re */
      -0.17096188876030122             /* im */
    }, { 1.9847485018019042,           /* re */
      -0.17398387338746382             /* im */
    }, { 1.984210092386929,            /* re */
      -0.17700422041214875             /* im */
    }, { 1.9836624192117303,           /* re */
      -0.18002290140569951             /* im */
    }, { 1.9831054874312164,           /* re */
      -0.18303988795514095             /* im */
    }, { 1.9825393022874414,           /* re */
      -0.18605515166344663             /* im */
    }, { 1.9819638691095554,           /* re */
      -0.1890686641498062              /* im */
    }, { 1.9813791933137546,           /* re */
      -0.19208039704989244             /* im */
    }, { 1.9807852804032304,           /* re */
      -0.19509032201612825             /* im */
    }, { 1.9801821359681173,           /* re */
      -0.19809841071795356             /* im */
    }, { 1.9795697656854405,           /* re */
      -0.2011046348420919              /* im */
    }, { 1.9789481753190623,           /* re */
      -0.20410896609281687             /* im */
    }, { 1.9783173707196275,           /* re */
      -0.20711137619221856             /* im */
    }, { 1.97767735782451,             /* re */
      -0.2101118368804696              /* im */
    }, { 1.9770281426577543,           /* re */
      -0.21311031991609136             /* im */
    }, { 1.976369731330021,            /* re */
      -0.21610679707621952             /* im */
    }, { 1.9757021300385285,           /* re */
      -0.2191012401568698              /* im */
    }, { 1.9750253450669941,           /* re */
      -0.2220936209732035              /* im */
    }, { 1.9743393827855757,           /* re */
      -0.22508391135979283             /* im */
    }, { 1.973644249650812,            /* re */
      -0.22807208317088573             /* im */
    }, { 1.9729399522055602,           /* re */
      -0.2310581082806711              /* im */
    }, { 1.9722264970789363,           /* re */
      -0.23404195858354343             /* im */
    }, { 1.9715038909862517,           /* re */
      -0.2370236059943672              /* im */
    }, { 1.9707721407289505,           /* re */
      -0.2400030224487415              /* im */
    }, { 1.970031253194544,            /* re */
      -0.24298017990326387             /* im */
    }, { 1.9692812353565485,           /* re */
      -0.2459550503357946              /* im */
    }, { 1.9685220942744173,           /* re */
      -0.24892760574572015             /* im */
    }, { 1.9677538370934755,           /* re */
      -0.25189781815421697             /* im */
    }, { 1.966976471044852,            /* re */
      -0.25486565960451457             /* im */
    }, { 1.9661900034454125,           /* re */
      -0.257831102162159               /* im */
    }, { 1.9653944416976894,           /* re */
      -0.2607941179152755              /* im */
    }, { 1.9645897932898126,           /* re */
      -0.26375467897483135             /* im */
    }, { 1.96377606579544,             /* re */
      -0.26671275747489837             /* im */
    }, { 1.9629532668736838,           /* re */
      -0.2696683255729151              /* im */
    }, { 1.9621214042690416,           /* re */
      -0.272621355449949               /* im */
    }, { 1.9612804858113206,           /* re */
      -0.27557181931095814             /* im */
    }, { 1.9604305194155658,           /* re */
      -0.27851968938505306             /* im */
    }, { 1.9595715130819844,           /* re */
      -0.28146493792575794             /* im */
    }, { 1.9587034748958716,           /* re */
      -0.2844075372112719              /* im */
    }, { 1.957826413027533,            /* re */
      -0.2873474595447295              /* im */
    }, { 1.9569403357322088,           /* re */
      -0.29028467725446233             /* im */
    }, { 1.9560452513499964,           /* re */
      -0.29321916269425863             /* im */
    }, { 1.955141168305771,            /* re */
      -0.2961508882436238              /* im */
    }, { 1.9542280951091056,           /* re */
      -0.2990798263080405              /* im */
    }, { 1.9533060403541938,           /* re */
      -0.3020059493192281              /* im */
    }, { 1.9523750127197659,           /* re */
      -0.3049292297354024              /* im */
    }, { 1.9514350209690083,           /* re */
      -0.30784964004153487             /* im */
    }, { 1.9504860739494818,           /* re */
      -0.3107671527496115              /* im */
    }, { 1.9495281805930367,           /* re */
      -0.3136817403988915              /* im */
    }, { 1.9485613499157304,           /* re */
      -0.31659337555616585             /* im */
    }, { 1.947585591017741,            /* re */
      -0.3195020308160157              /* im */
    }, { 1.9466009130832835,           /* re */
      -0.32240767880106985             /* im */
    }, { 1.9456073253805213,           /* re */
      -0.3253102921622629              /* im */
    }, { 1.9446048372614801,           /* re */
      -0.3282098435790925              /* im */
    }, { 1.9435934581619603,           /* re */
      -0.33110630575987643             /* im */
    }, { 1.9425731976014469,           /* re */
      -0.3339996514420094              /* im */
    }, { 1.9415440651830207,           /* re */
      -0.33688985339222005             /* im */
    }, { 1.9405060705932682,           /* re */
      -0.33977688440682685             /* im */
    }, { 1.93945922360219,             /* re */
      -0.3426607173119944              /* im */
    }, { 1.938403534063108,            /* re */
      -0.3455413249639891              /* im */
    }, { 1.937339011912575,            /* re */
      -0.34841868024943456             /* im */
    }, { 1.9362656671702783,           /* re */
      -0.3512927560855671              /* im */
    }, { 1.9351835099389476,           /* re */
      -0.35416352542049034             /* im */
    }, { 1.9340925504042588,           /* re */
      -0.35703096123343                /* im */
    }, { 1.9329927988347388,           /* re */
      -0.3598950365349881              /* im */
    }, { 1.9318842655816681,           /* re */
      -0.3627557243673972              /* im */
    }, { 1.9307669610789837,           /* re */
      -0.36561299780477385             /* im */
    }, { 1.9296408958431812,           /* re */
      -0.3684668299533723              /* im */
    }, { 1.9285060804732157,           /* re */
      -0.3713171939518375              /* im */
    }, { 1.927362525650401,            /* re */
      -0.37416406297145793             /* im */
    }, { 1.9262102421383114,           /* re */
      -0.37700741021641826             /* im */
    }, { 1.9250492407826776,           /* re */
      -0.37984720892405116             /* im */
    }, { 1.9238795325112867,           /* re */
      -0.3826834323650898              /* im */
    }, { 1.9227011283338786,           /* re */
      -0.38551605384391885             /* im */
    }, { 1.9215140393420418,           /* re */
      -0.38834504669882625             /* im */
    }, { 1.9203182767091107,           /* re */
      -0.39117038430225387             /* im */
    }, { 1.9191138516900579,           /* re */
      -0.3939920400610481              /* im */
    }, { 1.9179007756213906,           /* re */
      -0.3968099874167103              /* im */
    }, { 1.9166790599210426,           /* re */
      -0.3996241998456468              /* im */
    }, { 1.9154487160882678,           /* re */
      -0.40243465085941843             /* im */
    }, { 1.9142097557035307,           /* re */
      -0.40524131400498986             /* im */
    }, { 1.9129621904283982,           /* re */
      -0.4080441628649787              /* im */
    }, { 1.91170603200543,             /* re */
      -0.4108431710579039              /* im */
    }, { 1.9104412922580671,           /* re */
      -0.4136383122384345              /* im */
    }, { 1.9091679830905224,           /* re */
      -0.41642956009763715             /* im */
    }, { 1.9078861164876662,           /* re */
      -0.4192168883632239              /* im */
    }, { 1.9065957045149153,           /* re */
      -0.4220002707997997              /* im */
    }, { 1.905296759318119,            /* re */
      -0.4247796812091088              /* im */
    }, { 1.9039892931234434,           /* re */
      -0.4275550934302821              /* im */
    }, { 1.9026733182372588,           /* re */
      -0.4303264813400826              /* im */
    }, { 1.901348847046022,            /* re */
      -0.43309381885315196             /* im */
    }, { 1.9000158920161603,           /* re */
      -0.4358570799222555              /* im */
    }, { 1.8986744656939538,           /* re */
      -0.43861623853852766             /* im */
    }, { 1.8973245807054182,           /* re */
      -0.44137126873171667             /* im */
    }, { 1.895966249756185,            /* re */
      -0.4441221445704292              /* im */
    }, { 1.8945994856313826,           /* re */
      -0.44686884016237416             /* im */
    }, { 1.8932243011955152,           /* re */
      -0.44961132965460654             /* im */
    }, { 1.8918407093923428,           /* re */
      -0.4523495872337709              /* im */
    }, { 1.890448723244758,            /* re */
      -0.45508358712634384             /* im */
    }, { 1.8890483558546647,           /* re */
      -0.4578133035988772              /* im */
    }, { 1.887639620402854,            /* re */
      -0.46053871095824                /* im */
    }, { 1.8862225301488806,           /* re */
      -0.46325978355186015             /* im */
    }, { 1.884797098430938,            /* re */
      -0.4659764957679662              /* im */
    }, { 1.8833633386657316,           /* re */
      -0.46868882203582796             /* im */
    }, { 1.881921264348355,            /* re */
      -0.47139673682599764             /* im */
    }, { 1.8804708890521606,           /* re */
      -0.47410021465054997             /* im */
    }, { 1.8790122264286335,           /* re */
      -0.4767992300633221              /* im */
    }, { 1.8775452902072614,           /* re */
      -0.47949375766015295             /* im */
    }, { 1.8760700941954065,           /* re */
      -0.4821837720791227              /* im */
    }, { 1.8745866522781762,           /* re */
      -0.48486924800079106             /* im */
    }, { 1.87309497841829,             /* re */
      -0.487550160148436               /* im */
    }, { 1.871595086655951,            /* re */
      -0.49022648328829116             /* im */
    }, { 1.8700869911087115,           /* re */
      -0.49289819222978404             /* im */
    }, { 1.868570705971341,            /* re */
      -0.49556526182577254             /* im */
    }, { 1.8670462455156926,           /* re */
      -0.4982276669727818              /* im */
    }, { 1.865513624090569,            /* re */
      -0.5008853826112407              /* im */
    }, { 1.8639728561215867,           /* re */
      -0.5035383837257176              /* im */
    }, { 1.8624239561110405,           /* re */
      -0.5061866453451552              /* im */
    }, { 1.8608669386377672,           /* re */
      -0.508830142543107               /* im */
    }, { 1.8593018183570085,           /* re */
      -0.5114688504379703              /* im */
    }, { 1.8577286100002721,           /* re */
      -0.5141027441932217              /* im */
    }, { 1.8561473283751946,           /* re */
      -0.5167317990176499              /* im */
    }, { 1.8545579883654004,           /* re */
      -0.5193559901655896              /* im */
    }, { 1.8529606049303635,           /* re */
      -0.5219752929371544              /* im */
    }, { 1.8513551931052652,           /* re */
      -0.524589682678469               /* im */
    }, { 1.8497417680008525,           /* re */
      -0.5271991347819013              /* im */
    }, { 1.8481203448032972,           /* re */
      -0.5298036246862946              /* im */
    }, { 1.846490938774052,            /* re */
      -0.5324031278771979              /* im */
    }, { 1.8448535652497071,           /* re */
      -0.5349976198870972              /* im */
    }, { 1.8432082396418454,           /* re */
      -0.5375870762956454              /* im */
    }, { 1.8415549774368984,           /* re */
      -0.5401714727298929              /* im */
    }, { 1.8398937941959996,           /* re */
      -0.5427507848645159              /* im */
    }, { 1.838224705554838,            /* re */
      -0.5453249884220465              /* im */
    }, { 1.836547727223512,            /* re */
      -0.5478940591731002              /* im */
    }, { 1.83486287498638,             /* re */
      -0.5504579729366048              /* im */
    }, { 1.8331701647019132,           /* re */
      -0.5530167055800275              /* im */
    }, { 1.8314696123025453,           /* re */
      -0.5555702330196022              /* im */
    }, { 1.829761233794523,            /* re */
      -0.5581185312205561              /* im */
    }, { 1.8280450452577557,           /* re */
      -0.560661576197336               /* im */
    }, { 1.8263210628456634,           /* re */
      -0.5631993440138341              /* im */
    }, { 1.8245893027850253,           /* re */
      -0.5657318107836131              /* im */
    }, { 1.8228497813758264,           /* re */
      -0.5682589526701315              /* im */
    }, { 1.8211025149911046,           /* re */
      -0.5707807458869673              /* im */
    }, { 1.819347520076797,            /* re */
      -0.5732971666980422              /* im */
    }, { 1.8175848131515837,           /* re */
      -0.5758081914178453              /* im */
    }, { 1.8158144108067338,           /* re */
      -0.5783137964116556              /* im */
    }, { 1.8140363297059485,           /* re */
      -0.5808139580957645              /* im */
    }, { 1.8122505865852039,           /* re */
      -0.5833086529376983              /* im */
    }, { 1.8104571982525948,           /* re */
      -0.5857978574564389              /* im */
    }, { 1.808656181588175,            /* re */
      -0.5882815482226452              /* im */
    }, { 1.8068475535437993,           /* re */
      -0.5907597018588742              /* im */
    }, { 1.8050313311429638,           /* re */
      -0.5932322950397998              /* im */
    }, { 1.8032075314806448,           /* re */
      -0.5956993044924334              /* im */
    }, { 1.8013761717231402,           /* re */
      -0.5981607069963424              /* im */
    }, { 1.799537269107905,            /* re */
      -0.600616479383869               /* im */
    }, { 1.7976908409433912,           /* re */
      -0.6030665985403482              /* im */
    }, { 1.7958369046088836,           /* re */
      -0.6055110414043255              /* im */
    }, { 1.793975477554337,            /* re */
      -0.6079497849677736              /* im */
    }, { 1.7921065773002125,           /* re */
      -0.6103828062763095              /* im */
    }, { 1.79023022143731,             /* re */
      -0.6128100824294097              /* im */
    }, { 1.7883464276266063,           /* re */
      -0.6152315905806268              /* im */
    }, { 1.7864552135990857,           /* re */
      -0.6176473079378039              /* im */
    }, { 1.7845565971555752,           /* re */
      -0.6200572117632891              /* im */
    }, { 1.7826505961665757,           /* re */
      -0.62246127937415                /* im */
    }, { 1.7807372285720944,           /* re */
      -0.6248594881423863              /* im */
    }, { 1.7788165123814759,           /* re */
      -0.6272518154951441              /* im */
    }, { 1.7768884656732324,           /* re */
      -0.629638238914927               /* im */
    }, { 1.7749531065948738,           /* re */
      -0.6320187359398091              /* im */
    }, { 1.7730104533627369,           /* re */
      -0.6343932841636455              /* im */
    }, { 1.7710605242618138,           /* re */
      -0.6367618612362842              /* im */
    }, { 1.7691033376455798,           /* re */
      -0.6391244448637757              /* im */
    }, { 1.7671389119358203,           /* re */
      -0.641481012808583               /* im */
    }, { 1.765167265622459,            /* re */
      -0.6438315428897914              /* im */
    }, { 1.7631884172633812,           /* re */
      -0.6461760129833163              /* im */
    }, { 1.7612023854842618,           /* re */
      -0.6485144010221124              /* im */
    }, { 1.7592091889783878,           /* re */
      -0.650846684996381               /* im */
    }, { 1.7572088465064846,           /* re */
      -0.6531728429537768              /* im */
    }, { 1.7552013768965367,           /* re */
      -0.6554928529996153              /* im */
    }, { 1.7531867990436125,           /* re */
      -0.6578066932970786              /* im */
    }, { 1.7511651319096864,           /* re */
      -0.6601143420674205              /* im */
    }, { 1.7491363945234593,           /* re */
      -0.6624157775901718              /* im */
    }, { 1.7471006059801801,           /* re */
      -0.6647109782033448              /* im */
    }, { 1.745057785441466,            /* re */
      -0.6669999223036375              /* im */
    }, { 1.7430079521351218,           /* re */
      -0.669282588346636               /* im */
    }, { 1.7409511253549592,           /* re */
      -0.6715589548470183              /* im */
    }, { 1.7388873244606151,           /* re */
      -0.673829000378756               /* im */
    }, { 1.7368165688773698,           /* re */
      -0.6760927035753159              /* im */
    }, { 1.7347388780959636,           /* re */
      -0.6783500431298615              /* im */
    }, { 1.7326542716724127,           /* re */
      -0.680600997795453               /* im */
    }, { 1.7305627692278276,           /* re */
      -0.6828455463852481              /* im */
    }, { 1.728464390448225,            /* re */
      -0.6850836677727004              /* im */
    }, { 1.726359155084346,            /* re */
      -0.687315340891759               /* im */
    }, { 1.7242470829514671,           /* re */
      -0.6895405447370668              /* im */
    }, { 1.7221281939292155,           /* re */
      -0.6917592583641577              /* im */
    }, { 1.7200025079613817,           /* re */
      -0.6939714608896539              /* im */
    }, { 1.7178700450557316,           /* re */
      -0.696177131491463               /* im */
    }, { 1.7157308252838186,           /* re */
      -0.6983762494089729              /* im */
    }, { 1.7135848687807935,           /* re */
      -0.7005687939432483              /* im */
    }, { 1.7114321957452163,           /* re */
      -0.7027547444572253              /* im */
    }, { 1.7092728264388657,           /* re */
      -0.7049340803759049              /* im */
    }, { 1.7071067811865475,           /* re */
      -0.7071067811865476              /* im */
    }, { 1.7049340803759048,           /* re */
      -0.7092728264388657              /* im */
    }, { 1.7027547444572253,           /* re */
      -0.7114321957452164              /* im */
    }, { 1.7005687939432483,           /* re */
      -0.7135848687807935              /* im */
    }, { 1.698376249408973,            /* re */
      -0.7157308252838186              /* im */
    }, { 1.696177131491463,            /* re */
      -0.7178700450557317              /* im */
    }, { 1.693971460889654,            /* re */
      -0.7200025079613817              /* im */
    }, { 1.6917592583641579,           /* re */
      -0.7221281939292153              /* im */
    }, { 1.6895405447370668,           /* re */
      -0.724247082951467               /* im */
    }, { 1.6873153408917592,           /* re */
      -0.726359155084346               /* im */
    }, { 1.6850836677727004,           /* re */
      -0.7284643904482252              /* im */
    }, { 1.682845546385248,            /* re */
      -0.7305627692278276              /* im */
    }, { 1.680600997795453,            /* re */
      -0.7326542716724128              /* im */
    }, { 1.6783500431298615,           /* re */
      -0.7347388780959635              /* im */
    }, { 1.676092703575316,            /* re */
      -0.7368165688773698              /* im */
    }, { 1.6738290003787561,           /* re */
      -0.7388873244606151              /* im */
    }, { 1.6715589548470184,           /* re */
      -0.7409511253549592              /* im */
    }, { 1.669282588346636,            /* re */
      -0.7430079521351217              /* im */
    }, { 1.6669999223036376,           /* re */
      -0.745057785441466               /* im */
    }, { 1.664710978203345,            /* re */
      -0.7471006059801801              /* im */
    }, { 1.6624157775901718,           /* re */
      -0.7491363945234594              /* im */
    }, { 1.6601143420674205,           /* re */
      -0.7511651319096864              /* im */
    }, { 1.6578066932970787,           /* re */
      -0.7531867990436125              /* im */
    }, { 1.6554928529996153,           /* re */
      -0.7552013768965365              /* im */
    }, { 1.6531728429537766,           /* re */
      -0.7572088465064846              /* im */
    }, { 1.650846684996381,            /* re */
      -0.759209188978388               /* im */
    }, { 1.6485144010221124,           /* re */
      -0.7612023854842618              /* im */
    }, { 1.6461760129833163,           /* re */
      -0.7631884172633813              /* im */
    }, { 1.6438315428897914,           /* re */
      -0.765167265622459               /* im */
    }, { 1.641481012808583,            /* re */
      -0.7671389119358204              /* im */
    }, { 1.6391244448637758,           /* re */
      -0.7691033376455797              /* im */
    }, { 1.6367618612362842,           /* re */
      -0.7710605242618138              /* im */
    }, { 1.6343932841636455,           /* re */
      -0.773010453362737               /* im */
    }, { 1.632018735939809,            /* re */
      -0.7749531065948739              /* im */
    }, { 1.6296382389149269,           /* re */
      -0.7768884656732324              /* im */
    }, { 1.627251815495144,            /* re */
      -0.778816512381476               /* im */
    }, { 1.6248594881423863,           /* re */
      -0.7807372285720945              /* im */
    }, { 1.62246127937415,             /* re */
      -0.7826505961665757              /* im */
    }, { 1.6200572117632892,           /* re */
      -0.7845565971555752              /* im */
    }, { 1.617647307937804,            /* re */
      -0.7864552135990858              /* im */
    }, { 1.6152315905806267,           /* re */
      -0.7883464276266063              /* im */
    }, { 1.6128100824294096,           /* re */
      -0.79023022143731                /* im */
    }, { 1.6103828062763095,           /* re */
      -0.7921065773002124              /* im */
    }, { 1.6079497849677735,           /* re */
      -0.7939754775543372              /* im */
    }, { 1.6055110414043257,           /* re */
      -0.7958369046088836              /* im */
    }, { 1.603066598540348,            /* re */
      -0.7976908409433912              /* im */
    }, { 1.600616479383869,            /* re */
      -0.799537269107905               /* im */
    }, { 1.5981607069963424,           /* re */
      -0.8013761717231402              /* im */
    }, { 1.5956993044924332,           /* re */
      -0.8032075314806449              /* im */
    }, { 1.5932322950397997,           /* re */
      -0.8050313311429637              /* im */
    }, { 1.5907597018588742,           /* re */
      -0.8068475535437993              /* im */
    }, { 1.5882815482226453,           /* re */
      -0.808656181588175               /* im */
    }, { 1.5857978574564389,           /* re */
      -0.8104571982525948              /* im */
    }, { 1.5833086529376983,           /* re */
      -0.8122505865852039              /* im */
    }, { 1.5808139580957645,           /* re */
      -0.8140363297059484              /* im */
    }, { 1.5783137964116556,           /* re */
      -0.8158144108067338              /* im */
    }, { 1.5758081914178454,           /* re */
      -0.8175848131515837              /* im */
    }, { 1.5732971666980422,           /* re */
      -0.819347520076797               /* im */
    }, { 1.5707807458869674,           /* re */
      -0.8211025149911046              /* im */
    }, { 1.5682589526701314,           /* re */
      -0.8228497813758264              /* im */
    }, { 1.5657318107836131,           /* re */
      -0.8245893027850253              /* im */
    }, { 1.563199344013834,            /* re */
      -0.8263210628456635              /* im */
    }, { 1.5606615761973361,           /* re */
      -0.8280450452577558              /* im */
    }, { 1.558118531220556,            /* re */
      -0.829761233794523               /* im */
    }, { 1.5555702330196022,           /* re */
      -0.8314696123025452              /* im */
    }, { 1.5530167055800275,           /* re */
      -0.8331701647019132              /* im */
    }, { 1.5504579729366048,           /* re */
      -0.83486287498638                /* im */
    }, { 1.5478940591731,              /* re */
      -0.836547727223512               /* im */
    }, { 1.5453249884220464,           /* re */
      -0.8382247055548381              /* im */
    }, { 1.542750784864516,            /* re */
      -0.8398937941959995              /* im */
    }, { 1.540171472729893,            /* re */
      -0.8415549774368984              /* im */
    }, { 1.5375870762956454,           /* re */
      -0.8432082396418454              /* im */
    }, { 1.5349976198870972,           /* re */
      -0.8448535652497071              /* im */
    }, { 1.532403127877198,            /* re */
      -0.8464909387740521              /* im */
    }, { 1.5298036246862945,           /* re */
      -0.8481203448032972              /* im */
    }, { 1.5271991347819012,           /* re */
      -0.8497417680008525              /* im */
    }, { 1.524589682678469,            /* re */
      -0.8513551931052652              /* im */
    }, { 1.5219752929371544,           /* re */
      -0.8529606049303636              /* im */
    }, { 1.5193559901655895,           /* re */
      -0.8545579883654005              /* im */
    }, { 1.5167317990176499,           /* re */
      -0.8561473283751945              /* im */
    }, { 1.5141027441932216,           /* re */
      -0.8577286100002721              /* im */
    }, { 1.5114688504379703,           /* re */
      -0.8593018183570085              /* im */
    }, { 1.508830142543107,            /* re */
      -0.8608669386377673              /* im */
    }, { 1.5061866453451551,           /* re */
      -0.8624239561110405              /* im */
    }, { 1.5035383837257177,           /* re */
      -0.8639728561215867              /* im */
    }, { 1.5008853826112407,           /* re */
      -0.8655136240905691              /* im */
    }, { 1.4982276669727819,           /* re */
      -0.8670462455156926              /* im */
    }, { 1.4955652618257727,           /* re */
      -0.8685707059713409              /* im */
    }, { 1.492898192229784,            /* re */
      -0.8700869911087115              /* im */
    }, { 1.4902264832882912,           /* re */
      -0.8715950866559511              /* im */
    }, { 1.487550160148436,            /* re */
      -0.8730949784182901              /* im */
    }, { 1.484869248000791,            /* re */
      -0.8745866522781761              /* im */
    }, { 1.4821837720791227,           /* re */
      -0.8760700941954066              /* im */
    }, { 1.479493757660153,            /* re */
      -0.8775452902072614              /* im */
    }, { 1.4767992300633221,           /* re */
      -0.8790122264286335              /* im */
    }, { 1.47410021465055,             /* re */
      -0.8804708890521608              /* im */
    }, { 1.4713967368259977,           /* re */
      -0.881921264348355               /* im */
    }, { 1.468688822035828,            /* re */
      -0.8833633386657316              /* im */
    }, { 1.4659764957679662,           /* re */
      -0.8847970984309378              /* im */
    }, { 1.4632597835518601,           /* re */
      -0.8862225301488806              /* im */
    }, { 1.46053871095824,             /* re */
      -0.8876396204028539              /* im */
    }, { 1.4578133035988772,           /* re */
      -0.8890483558546646              /* im */
    }, { 1.455083587126344,            /* re */
      -0.8904487232447579              /* im */
    }, { 1.4523495872337708,           /* re */
      -0.8918407093923427              /* im */
    }, { 1.4496113296546065,           /* re */
      -0.8932243011955153              /* im */
    }, { 1.4468688401623742,           /* re */
      -0.8945994856313827              /* im */
    }, { 1.444122144570429,            /* re */
      -0.8959662497561852              /* im */
    }, { 1.4413712687317166,           /* re */
      -0.8973245807054183              /* im */
    }, { 1.4386162385385277,           /* re */
      -0.8986744656939538              /* im */
    }, { 1.4358570799222554,           /* re */
      -0.9000158920161602              /* im */
    }, { 1.433093818853152,            /* re */
      -0.901348847046022               /* im */
    }, { 1.4303264813400827,           /* re */
      -0.9026733182372588              /* im */
    }, { 1.427555093430282,            /* re */
      -0.9039892931234433              /* im */
    }, { 1.4247796812091087,           /* re */
      -0.9052967593181188              /* im */
    }, { 1.4220002707997996,           /* re */
      -0.9065957045149153              /* im */
    }, { 1.419216888363224,            /* re */
      -0.9078861164876663              /* im */
    }, { 1.416429560097637,            /* re */
      -0.9091679830905224              /* im */
    }, { 1.4136383122384344,           /* re */
      -0.9104412922580672              /* im */
    }, { 1.410843171057904,            /* re */
      -0.9117060320054299              /* im */
    }, { 1.4080441628649787,           /* re */
      -0.9129621904283982              /* im */
    }, { 1.4052413140049897,           /* re */
      -0.9142097557035307              /* im */
    }, { 1.4024346508594183,           /* re */
      -0.9154487160882678              /* im */
    }, { 1.399624199845647,            /* re */
      -0.9166790599210427              /* im */
    }, { 1.3968099874167104,           /* re */
      -0.9179007756213905              /* im */
    }, { 1.3939920400610482,           /* re */
      -0.9191138516900578              /* im */
    }, { 1.3911703843022538,           /* re */
      -0.9203182767091106              /* im */
    }, { 1.3883450466988263,           /* re */
      -0.9215140393420419              /* im */
    }, { 1.3855160538439188,           /* re */
      -0.9227011283338786              /* im */
    }, { 1.3826834323650898,           /* re */
      -0.9238795325112867              /* im */
    }, { 1.3798472089240512,           /* re */
      -0.9250492407826776              /* im */
    }, { 1.3770074102164183,           /* re */
      -0.9262102421383114              /* im */
    }, { 1.374164062971458,            /* re */
      -0.9273625256504011              /* im */
    }, { 1.3713171939518376,           /* re */
      -0.9285060804732156              /* im */
    }, { 1.3684668299533724,           /* re */
      -0.9296408958431812              /* im */
    }, { 1.365612997804774,            /* re */
      -0.9307669610789837              /* im */
    }, { 1.3627557243673971,           /* re */
      -0.9318842655816681              /* im */
    }, { 1.3598950365349882,           /* re */
      -0.932992798834739               /* im */
    }, { 1.35703096123343,             /* re */
      -0.9340925504042589              /* im */
    }, { 1.3541635254204905,           /* re */
      -0.9351835099389476              /* im */
    }, { 1.351292756085567,            /* re */
      -0.9362656671702783              /* im */
    }, { 1.3484186802494347,           /* re */
      -0.937339011912575               /* im */
    }, { 1.3455413249639891,           /* re */
      -0.9384035340631081              /* im */
    }, { 1.3426607173119944,           /* re */
      -0.9394592236021899              /* im */
    }, { 1.339776884406827,            /* re */
      -0.9405060705932683              /* im */
    }, { 1.33688985339222,             /* re */
      -0.9415440651830208              /* im */
    }, { 1.3339996514420094,           /* re */
      -0.9425731976014469              /* im */
    }, { 1.3311063057598764,           /* re */
      -0.9435934581619604              /* im */
    }, { 1.3282098435790926,           /* re */
      -0.9446048372614803              /* im */
    }, { 1.3253102921622628,           /* re */
      -0.9456073253805213              /* im */
    }, { 1.32240767880107,             /* re */
      -0.9466009130832835              /* im */
    }, { 1.3195020308160157,           /* re */
      -0.9475855910177411              /* im */
    }, { 1.3165933755561658,           /* re */
      -0.9485613499157303              /* im */
    }, { 1.3136817403988914,           /* re */
      -0.9495281805930367              /* im */
    }, { 1.3107671527496114,           /* re */
      -0.9504860739494817              /* im */
    }, { 1.307849640041535,            /* re */
      -0.9514350209690083              /* im */
    }, { 1.3049292297354023,           /* re */
      -0.9523750127197659              /* im */
    }, { 1.302005949319228,            /* re */
      -0.9533060403541939              /* im */
    }, { 1.2990798263080405,           /* re */
      -0.9542280951091057              /* im */
    }, { 1.296150888243624,            /* re */
      -0.9551411683057708              /* im */
    }, { 1.2932191626942586,           /* re */
      -0.9560452513499964              /* im */
    }, { 1.2902846772544623,           /* re */
      -0.9569403357322088              /* im */
    }, { 1.2873474595447294,           /* re */
      -0.9578264130275329              /* im */
    }, { 1.2844075372112718,           /* re */
      -0.9587034748958716              /* im */
    }, { 1.2814649379257579,           /* re */
      -0.9595715130819845              /* im */
    }, { 1.278519689385053,            /* re */
      -0.9604305194155658              /* im */
    }, { 1.2755718193109582,           /* re */
      -0.9612804858113206              /* im */
    }, { 1.272621355449949,            /* re */
      -0.9621214042690416              /* im */
    }, { 1.269668325572915,            /* re */
      -0.9629532668736839              /* im */
    }, { 1.2667127574748984,           /* re */
      -0.9637760657954398              /* im */
    }, { 1.2637546789748313,           /* re */
      -0.9645897932898128              /* im */
    }, { 1.2607941179152755,           /* re */
      -0.9653944416976894              /* im */
    }, { 1.257831102162159,            /* re */
      -0.9661900034454125              /* im */
    }, { 1.2548656596045147,           /* re */
      -0.9669764710448521              /* im */
    }, { 1.2518978181542169,           /* re */
      -0.9677538370934755              /* im */
    }, { 1.2489276057457201,           /* re */
      -0.9685220942744173              /* im */
    }, { 1.2459550503357946,           /* re */
      -0.9692812353565485              /* im */
    }, { 1.2429801799032638,           /* re */
      -0.970031253194544               /* im */
    }, { 1.2400030224487415,           /* re */
      -0.9707721407289504              /* im */
    }, { 1.2370236059943671,           /* re */
      -0.9715038909862518              /* im */
    }, { 1.2340419585835434,           /* re */
      -0.9722264970789363              /* im */
    }, { 1.231058108280671,            /* re */
      -0.9729399522055602              /* im */
    }, { 1.2280720831708858,           /* re */
      -0.973644249650812               /* im */
    }, { 1.2250839113597929,           /* re */
      -0.9743393827855759              /* im */
    }, { 1.2220936209732036,           /* re */
      -0.9750253450669941              /* im */
    }, { 1.2191012401568697,           /* re */
      -0.9757021300385286              /* im */
    }, { 1.2161067970762196,           /* re */
      -0.9763697313300211              /* im */
    }, { 1.2131103199160913,           /* re */
      -0.9770281426577544              /* im */
    }, { 1.2101118368804695,           /* re */
      -0.9776773578245099              /* im */
    }, { 1.2071113761922185,           /* re */
      -0.9783173707196277              /* im */
    }, { 1.2041089660928168,           /* re */
      -0.9789481753190622              /* im */
    }, { 1.201104634842092,            /* re */
      -0.9795697656854405              /* im */
    }, { 1.1980984107179535,           /* re */
      -0.9801821359681174              /* im */
    }, { 1.1950903220161282,           /* re */
      -0.9807852804032304              /* im */
    }, { 1.1920803970498923,           /* re */
      -0.9813791933137546              /* im */
    }, { 1.1890686641498063,           /* re */
      -0.9819638691095552              /* im */
    }, { 1.1860551516634465,           /* re */
      -0.9825393022874412              /* im */
    }, { 1.183039887955141,            /* re */
      -0.9831054874312163              /* im */
    }, { 1.1800229014056995,           /* re */
      -0.9836624192117303              /* im */
    }, { 1.1770042204121487,           /* re */
      -0.984210092386929               /* im */
    }, { 1.173983873387464,            /* re */
      -0.9847485018019042              /* im */
    }, { 1.1709618887603013,           /* re */
      -0.9852776423889412              /* im */
    }, { 1.1679382949747312,           /* re */
      -0.9857975091675675              /* im */
    }, { 1.1649131204899699,           /* re */
      -0.9863080972445987              /* im */
    }, { 1.1618863937801118,           /* re */
      -0.9868094018141855              /* im */
    }, { 1.1588581433338614,           /* re */
      -0.9873014181578584              /* im */
    }, { 1.1558283976542651,           /* re */
      -0.9877841416445722              /* im */
    }, { 1.1527971852584433,           /* re */
      -0.9882575677307495              /* im */
    }, { 1.1497645346773215,           /* re */
      -0.9887216919603238              /* im */
    }, { 1.1467304744553617,           /* re */
      -0.989176509964781               /* im */
    }, { 1.1436950331502944,           /* re */
      -0.9896220174632009              /* im */
    }, { 1.1406582393328493,           /* re */
      -0.9900582102622971              /* im */
    }, { 1.137620121586486,            /* re */
      -0.9904850842564571              /* im */
    }, { 1.1345807085071262,           /* re */
      -0.99090263542778                /* im */
    }, { 1.1315400287028832,           /* re */
      -0.9913108598461154              /* im */
    }, { 1.1284981107937933,           /* re */
      -0.9917097536690995              /* im */
    }, { 1.1254549834115462,           /* re */
      -0.9920993131421918              /* im */
    }, { 1.1224106751992162,           /* re */
      -0.99247953459871                /* im */
    }, { 1.1193652148109914,           /* re */
      -0.9928504144598651              /* im */
    }, { 1.1163186309119046,           /* re */
      -0.9932119492347945              /* im */
    }, { 1.1132709521775643,           /* re */
      -0.9935641355205953              /* im */
    }, { 1.110222207293883,            /* re */
      -0.9939069700023561              /* im */
    }, { 1.107172424956809,            /* re */
      -0.9942404494531879              /* im */
    }, { 1.1041216338720545,           /* re */
      -0.9945645707342554              /* im */
    }, { 1.1010698627548279,           /* re */
      -0.9948793307948056              /* im */
    }, { 1.0980171403295607,           /* re */
      -0.9951847266721969              /* im */
    }, { 1.094963495329639,            /* re */
      -0.9954807554919269              /* im */
    }, { 1.0919089564971327,           /* re */
      -0.9957674144676598              /* im */
    }, { 1.0888535525825247,           /* re */
      -0.996044700901252               /* im */
    }, { 1.08579731234444,             /* re */
      -0.996312612182778               /* im */
    }, { 1.0827402645493758,           /* re */
      -0.9965711457905548              /* im */
    }, { 1.07968243797143,             /* re */
      -0.9968202992911657              /* im */
    }, { 1.0766238613920316,           /* re */
      -0.997060070339483               /* im */
    }, { 1.0735645635996673,           /* re */
      -0.9972904566786902              /* im */
    }, { 1.070504573389614,            /* re */
      -0.9975114561403035              /* im */
    }, { 1.067443919563664,            /* re */
      -0.9977230666441916              /* im */
    }, { 1.0643826309298574,           /* re */
      -0.997925286198596               /* im */
    }, { 1.0613207363022086,           /* re */
      -0.9981181129001492              /* im */
    }, { 1.0582582645004357,           /* re */
      -0.9983015449338929              /* im */
    }, { 1.05519524434969,             /* re */
      -0.9984755805732948              /* im */
    }, { 1.0521317046802834,           /* re */
      -0.9986402181802653              /* im */
    }, { 1.049067674327418,            /* re */
      -0.9987954562051724              /* im */
    }, { 1.0460031821309146,           /* re */
      -0.9989412931868569              /* im */
    }, { 1.0429382569349408,           /* re */
      -0.9990777277526454              /* im */
    }, { 1.0398729275877399,           /* re */
      -0.9992047586183639              /* im */
    }, { 1.0368072229413587,           /* re */
      -0.9993223845883495              /* im */
    }, { 1.0337411718513776,           /* re */
      -0.9994306045554617              /* im */
    }, { 1.0306748031766366,           /* re */
      -0.9995294175010931              /* im */
    }, { 1.0276081457789656,           /* re */
      -0.9996188224951786              /* im */
    }, { 1.0245412285229123,           /* re */
      -0.9996988186962042              /* im */
    }, { 1.0214740802754696,           /* re */
      -0.9997694053512153              /* im */
    }, { 1.0184067299058048,           /* re */
      -0.9998305817958234              /* im */
    }, { 1.0153392062849882,           /* re */
      -0.9998823474542126              /* im */
    }, { 1.01227153828572,             /* re */
      -0.9999247018391445              /* im */
    }, { 1.0092037547820598,           /* re */
      -0.9999576445519639              /* im */
    }, { 1.0061358846491544,           /* re */
      -0.9999811752826011              /* im */
    }, { 1.003067956762966,            /* re */
      -0.9999952938095762              /* im */
    } };

  for (iDelta = 0; iDelta < 512; iDelta++) {
    ix = ((iDelta + 1) << 1) - 2;
    costab[iDelta] = b[ix];
    sintab[iDelta] = c[ix];
  }

  for (iDelta = 0; iDelta < 1024; iDelta++) {
    d = d_0[iDelta];
    ix = iDelta << 1;
    y[d - 1].re = x[ix];
    y[d - 1].im = x[ix + 1];
  }

  for (iDelta = 0; iDelta <= 1022; iDelta += 2) {
    temp_re = y[iDelta + 1].re;
    temp2_re = y[iDelta + 1].im;
    temp_im = y[iDelta].re;
    temp2_im = y[iDelta].im;
    y[iDelta + 1].re = temp_im - temp_re;
    y[iDelta + 1].im = temp2_im - temp2_re;
    y[iDelta].re = temp_im + temp_re;
    y[iDelta].im = temp2_im + temp2_re;
  }

  iDelta = 2;
  ix = 4;
  k = 256;
  iheight = 1021;
  while (k > 0) {
    int32_T istart;
    int32_T temp_re_tmp;
    for (b_i = 0; b_i < iheight; b_i += ix) {
      temp_re_tmp = b_i + iDelta;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[b_i].re - temp_re;
      y[temp_re_tmp].im = y[b_i].im - temp_im;
      y[b_i].re += temp_re;
      y[b_i].im += temp_im;
    }

    istart = 1;
    for (j = k; j < 512; j += k) {
      int32_T ihi;
      temp2_re = costab[j];
      temp2_im = sintab[j];
      b_i = istart;
      ihi = istart + iheight;
      while (b_i < ihi) {
        temp_re_tmp = b_i + iDelta;
        temp_im = y[temp_re_tmp].im;
        temp_re_tmp_0 = y[temp_re_tmp].re;
        temp_re = temp_re_tmp_0 * temp2_re - temp_im * temp2_im;
        temp_im = temp_im * temp2_re + temp_re_tmp_0 * temp2_im;
        y[temp_re_tmp].re = y[b_i].re - temp_re;
        y[temp_re_tmp].im = y[b_i].im - temp_im;
        y[b_i].re += temp_re;
        y[b_i].im += temp_im;
        b_i += ix;
      }

      istart++;
    }

    k >>= 1;
    iDelta = ix;
    ix += ix;
    iheight -= iDelta;
  }

  temp_re = y[0].re;
  temp_im = y[0].im;
  temp2_re = -y[0].re + y[0].im;
  temp2_im = y[0].re - y[0].im;
  temp_re_tmp_0 = y[0].re - (-y[0].im);
  y[0].re = (temp_re_tmp_0 + temp_re_tmp_0) * 0.5;
  y[0].im = (temp2_re + temp2_im) * 0.5;
  y[1024].re = (temp2_im + temp2_im) * 0.5;
  y[1024].im = ((temp_re + temp_im) + (-temp_re - temp_im)) * 0.5;
  for (iDelta = 0; iDelta < 511; iDelta++) {
    temp_re = y[iDelta + 1].re;
    temp_im = y[iDelta + 1].im;
    d = g[iDelta + 1];
    temp2_re = y[d - 1].re;
    temp2_im = y[d - 1].im;
    y_im_tmp = reconVar1[iDelta + 1].re;
    y_im_tmp_0 = reconVar1[iDelta + 1].im;
    temp_re_tmp_0 = reconVar2[iDelta + 1].im;
    tmp = reconVar2[iDelta + 1].re;
    y[iDelta + 1].re = ((temp_re * y_im_tmp - temp_im * y_im_tmp_0) + (tmp *
      temp2_re - temp_re_tmp_0 * -temp2_im)) * 0.5;
    y[iDelta + 1].im = ((temp_re_tmp_0 * temp2_re + tmp * -temp2_im) + (temp_re *
      y_im_tmp_0 + temp_im * y_im_tmp)) * 0.5;
    y[iDelta + 1025].re = ((tmp * temp_re - temp_re_tmp_0 * temp_im) + (y_im_tmp
      * temp2_re - y_im_tmp_0 * -temp2_im)) * 0.5;
    y[iDelta + 1025].im = ((temp_re_tmp_0 * temp_re + tmp * temp_im) +
      (y_im_tmp_0 * temp2_re + y_im_tmp * -temp2_im)) * 0.5;
    temp_re_tmp_0 = reconVar1[d - 1].im;
    tmp = reconVar1[d - 1].re;
    y_im_tmp = reconVar2[d - 1].im;
    y_im_tmp_0 = reconVar2[d - 1].re;
    y[d - 1].re = ((tmp * temp2_re - temp_re_tmp_0 * temp2_im) + (y_im_tmp_0 *
      temp_re - y_im_tmp * -temp_im)) * 0.5;
    y[d - 1].im = ((temp_re_tmp_0 * temp2_re + tmp * temp2_im) + (y_im_tmp *
      temp_re + y_im_tmp_0 * -temp_im)) * 0.5;
    y[d + 1023].re = ((y_im_tmp_0 * temp2_re - y_im_tmp * temp2_im) + (tmp *
      temp_re - temp_re_tmp_0 * -temp_im)) * 0.5;
    y[d + 1023].im = ((y_im_tmp * temp2_re + y_im_tmp_0 * temp2_im) +
                      (temp_re_tmp_0 * temp_re + tmp * -temp_im)) * 0.5;
  }

  temp_im = y[512].im;
  y_im_tmp = y[512].re * 0.0;
  y_im_tmp_0 = y[512].im * 0.0;
  temp_re_tmp_0 = y[512].re * 2.0;
  tmp = -y[512].im * 0.0;
  y[512].re = ((y_im_tmp - y_im_tmp_0) + (temp_re_tmp_0 - tmp)) * 0.5;
  y[512].im = ((-y[512].im * 2.0 + y_im_tmp) + (y_im_tmp + y_im_tmp_0)) * 0.5;
  y[1536].re = ((temp_re_tmp_0 - y_im_tmp_0) + (y_im_tmp - tmp)) * 0.5;
  y[1536].im = ((temp_im * 2.0 + y_im_tmp) + (y_im_tmp + tmp)) * 0.5;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static real_T MotorFaultDeploy_mean(const real_T x[2048])
{
  real_T b_y;
  real_T bsum;
  real_T x_0;
  int32_T counts;
  int32_T k;
  if (rtIsNaN(x[0])) {
    b_y = 0.0;
    counts = 0;
  } else {
    b_y = x[0];
    counts = 1;
  }

  for (k = 0; k < 1023; k++) {
    x_0 = x[k + 1];
    if (!rtIsNaN(x_0)) {
      b_y += x_0;
      counts++;
    }
  }

  if (rtIsNaN(x[1024])) {
    bsum = 0.0;
  } else {
    bsum = x[1024];
    counts++;
  }

  for (k = 0; k < 1023; k++) {
    x_0 = x[k + 1025];
    if (!rtIsNaN(x_0)) {
      bsum += x_0;
      counts++;
    }
  }

  return (b_y + bsum) / (real_T)counts;
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static real_T MotorFaultDeploy_maximum(const real_T x[2048])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while (!exitg1 && (k < 2049)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 2049; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaultDeploy_minimum(const real_T x[4], real_T *ex, int32_T *idx)
{
  int32_T b_idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    b_idx = 1;
  } else {
    boolean_T exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while (!exitg1 && (k < 5)) {
      if (!rtIsNaN(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[b_idx - 1];
    *idx = b_idx;
    for (k = b_idx + 1; k < 5; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (*ex > x_0) {
        *ex = x_0;
        *idx = k;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_predi(const real_T obj_CutPredictorIndex
  [49], const real_T obj_Children[98], const real_T obj_CutPoint[49], const
  boolean_T obj_NanCutPoints[49], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[196], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 49] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 98]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 147];
    scores[i] = obj_ClassProbability[49 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaultDeploy_updateCache(const real_T learnerscore[4], real_T
  cachedScore[4], real_T *cachedWeights, boolean_T *cached, const char_T
  combinerName[15], real_T score[4])
{
  static const char_T b[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T c[15] = { 'w', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'a', 'v',
    'e', 'r', 'a', 'g', 'e' };

  score[0] = cachedScore[0];
  score[1] = cachedScore[1];
  score[2] = cachedScore[2];
  score[3] = cachedScore[3];
  if (!*cached) {
    int32_T kstr;
    boolean_T b_bool;
    *cached = true;
    cachedScore[0] += learnerscore[0];
    cachedScore[1] += learnerscore[1];
    cachedScore[2] += learnerscore[2];
    cachedScore[3] += learnerscore[3];
    (*cachedWeights)++;
    b_bool = false;
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (b[(int32_T)combinerName[kstr]] != b[(int32_T)c[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (b_bool) {
      score[0] = cachedScore[0] / *cachedWeights;
      score[1] = cachedScore[1] / *cachedWeights;
      score[2] = cachedScore[2] / *cachedWeights;
      score[3] = cachedScore[3] / *cachedWeights;
    } else {
      score[0] = cachedScore[0];
      score[1] = cachedScore[1];
      score[2] = cachedScore[2];
      score[3] = cachedScore[3];
    }
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaultD_predictOneWithCache(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[49], const real_T weak_learner_Children[98],
  const real_T weak_learner_CutPoint[49], const boolean_T
  weak_learner_NanCutPoints[49], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[196], boolean_T *cached, boolean_T
  initCache, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_predi(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  if (initCache) {
    cachedScore[0] = 0.0;
    cachedScore[1] = 0.0;
    cachedScore[2] = 0.0;
    cachedScore[3] = 0.0;
  } else {
    y = false;
    k = 0;
    exitg1 = false;
    while (!exitg1 && (k < 4)) {
      if (rtIsNaN(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (y) {
      for (k = 0; k < 4; k++) {
        if (rtIsNaN(cachedScore[k])) {
          cachedScore[k] = 0.0;
        }
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_pre_g(const real_T obj_CutPredictorIndex
  [31], const real_T obj_Children[62], const real_T obj_CutPoint[31], const
  boolean_T obj_NanCutPoints[31], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[124], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 31] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 62]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 93];
    scores[i] = obj_ClassProbability[31 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaul_predictOneWithCache_o(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[31], const real_T weak_learner_Children[62],
  const real_T weak_learner_CutPoint[31], const boolean_T
  weak_learner_NanCutPoints[31], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[124], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pre_g(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_pr_gp(const real_T obj_CutPredictorIndex
  [29], const real_T obj_Children[58], const real_T obj_CutPoint[29], const
  boolean_T obj_NanCutPoints[29], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[116], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 29] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 58]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 87];
    scores[i] = obj_ClassProbability[29 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFau_predictOneWithCache_o2(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[29], const real_T weak_learner_Children[58],
  const real_T weak_learner_CutPoint[29], const boolean_T
  weak_learner_NanCutPoints[29], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[116], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pr_gp(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_p_gps(const real_T obj_CutPredictorIndex
  [63], const real_T obj_Children[126], const real_T obj_CutPoint[63], const
  boolean_T obj_NanCutPoints[63], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[252], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 63] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 126]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 189];
    scores[i] = obj_ClassProbability[63 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFa_predictOneWithCache_o22(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[63], const real_T weak_learner_Children[126],
  const real_T weak_learner_CutPoint[63], const boolean_T
  weak_learner_NanCutPoints[63], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[252], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_p_gps(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree__gpst(const real_T obj_CutPredictorIndex
  [33], const real_T obj_Children[66], const real_T obj_CutPoint[33], const
  boolean_T obj_NanCutPoints[33], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[132], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 33] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 66]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 99];
    scores[i] = obj_ClassProbability[33 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorF_predictOneWithCache_o22p(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[33], const real_T weak_learner_Children[66],
  const real_T weak_learner_CutPoint[33], const boolean_T
  weak_learner_NanCutPoints[33], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[132], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree__gpst(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_gpst0(const real_T obj_CutPredictorIndex
  [47], const real_T obj_Children[94], const real_T obj_CutPoint[47], const
  boolean_T obj_NanCutPoints[47], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[188], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 47] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 94]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 141];
    scores[i] = obj_ClassProbability[47 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void Motor_predictOneWithCache_o22p4(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[47], const real_T weak_learner_Children[94],
  const real_T weak_learner_CutPoint[47], const boolean_T
  weak_learner_NanCutPoints[47], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[188], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_gpst0(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTre_gpst0p(const real_T obj_CutPredictorIndex
  [41], const real_T obj_Children[82], const real_T obj_CutPoint[41], const
  boolean_T obj_NanCutPoints[41], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[164], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 41] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 82]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 123];
    scores[i] = obj_ClassProbability[41 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void Moto_predictOneWithCache_o22p4v(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[41], const real_T weak_learner_Children[82],
  const real_T weak_learner_CutPoint[41], const boolean_T
  weak_learner_NanCutPoints[41], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[164], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTre_gpst0p(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTr_gpst0p4(const real_T obj_CutPredictorIndex
  [37], const real_T obj_Children[74], const real_T obj_CutPoint[37], const
  boolean_T obj_NanCutPoints[37], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[148], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 37] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 74]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 111];
    scores[i] = obj_ClassProbability[37 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void Mot_predictOneWithCache_o22p4vs(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[37], const real_T weak_learner_Children[74],
  const real_T weak_learner_CutPoint[37], const boolean_T
  weak_learner_NanCutPoints[37], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[148], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTr_gpst0p4(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationT_gpst0p4p(const real_T obj_CutPredictorIndex
  [39], const real_T obj_Children[78], const real_T obj_CutPoint[39], const
  boolean_T obj_NanCutPoints[39], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[156], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 39] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 78]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 117];
    scores[i] = obj_ClassProbability[39 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void Mo_predictOneWithCache_o22p4vsu(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[39], const real_T weak_learner_Children[78],
  const real_T weak_learner_CutPoint[39], const boolean_T
  weak_learner_NanCutPoints[39], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[156], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationT_gpst0p4p(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassification_gpst0p4p3(const real_T obj_CutPredictorIndex
  [53], const real_T obj_Children[106], const real_T obj_CutPoint[53], const
  boolean_T obj_NanCutPoints[53], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[212], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 53] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 106]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 159];
    scores[i] = obj_ClassProbability[53 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void M_predictOneWithCache_o22p4vsub(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[53], const real_T weak_learner_Children[106],
  const real_T weak_learner_CutPoint[53], const boolean_T
  weak_learner_NanCutPoints[53], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[212], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassification_gpst0p4p3(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificatio_gpst0p4p3i(const real_T obj_CutPredictorIndex
  [59], const real_T obj_Children[118], const real_T obj_CutPoint[59], const
  boolean_T obj_NanCutPoints[59], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[236], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 59] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 118]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 177];
    scores[i] = obj_ClassProbability[59 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithCache_o22p4vsubw(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[59], const real_T weak_learner_Children[118],
  const real_T weak_learner_CutPoint[59], const boolean_T
  weak_learner_NanCutPoints[59], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[236], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificatio_gpst0p4p3i(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificati_gpst0p4p3is(const real_T obj_CutPredictorIndex
  [45], const real_T obj_Children[90], const real_T obj_CutPoint[45], const
  boolean_T obj_NanCutPoints[45], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[180], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 45] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 90]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 135];
    scores[i] = obj_ClassProbability[45 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithCache_o22p4vsubwb(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[45], const real_T weak_learner_Children[90],
  const real_T weak_learner_CutPoint[45], const boolean_T
  weak_learner_NanCutPoints[45], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[180], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificati_gpst0p4p3is(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Compa(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172])
{
  int32_T i;
  static const real_T tmp[43] = { 0.0005343054096836643, 0.0,
    0.15840568100343969, 0.10405640349033901, 0.06575833537783901,
    3.751543226048165, 13.763392189254521, 0.28244135030227946, 0.0,
    0.0043594703723780475, 0.0, 0.0012967483494699052, 0.010351370232154834,
    0.16693879138922185, 0.0, 0.0013251935795847126, 0.0, 0.0,
    0.002057417701559171, 0.0, 0.0, 0.003982793582756362, 0.007822807745310393,
    0.0, 0.0, 0.12670813383768065, 0.0, 0.0, 8.73870771985564, 15.04125735587763,
    0.269913313995951, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.025700905869801883, 0.0,
    1.2149335528942116, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[43] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, false, true, false, true,
    true, false, true, true, false, false, true, true, false, true, true, false,
    false, false, true, true, true, true, true, true, false, true, false, true,
    true, true };

  static const real_T tmp_1[172] = { 0.37639198218262476, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21158129175946666, 0.0,
    0.33928571428571436, 0.05891238670694861, 0.5907859078590803, 0.0,
    0.09285714285714276, 0.8515625000000007, 0.0, 0.0, 0.0, 0.0,
    0.8297872340425532, 0.8879837067209781, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.5833333333333331, 0.9403341288782817, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.1176470588235294, 0.16666666666666666, 0.9631449631449632, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.9162011173184357, 1.0, 0.9820359281437125, 0.0, 0.0, 1.0,
    0.21291759465478963, 0.0, 0.3414285714285715, 0.6072507552870103,
    0.10298102981029786, 0.1446280991735541, 0.8738095238095238,
    0.14843749999999936, 0.0, 0.03271028037383187, 1.0, 0.9624664879356568,
    0.17021276595744686, 0.11201629327902192, 1.0, 0.7777777777777778, 0.0, 1.0,
    0.9161676646706587, 1.0, 0.0, 0.4166666666666668, 0.05966587112171827, 0.0,
    1.0, 0.12499999999999999, 1.0, 0.0, 0.8823529411764706, 0.8333333333333333,
    0.03685503685503679, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0837988826815643, 0.0,
    0.017964071856287435, 1.0, 1.0, 0.0, 0.19910913140311898, 0.0,
    0.31928571428571406, 0.33383685800604107, 0.3062330623306219,
    0.8553719008264459, 0.03333333333333331, 0.0, 1.0, 0.967289719626168, 0.0,
    0.037533512064343154, 0.0, 0.0, 0.0, 0.2222222222222222, 1.0, 0.0,
    0.08383233532934131, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.875, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[43] = { 10, 0, 2, 2, 9, 5, 5, 6, 0, 10, 0, 8, 10, 3, 0,
    9, 0, 0, 9, 0, 0, 1, 9, 0, 0, 6, 0, 0, 7, 5, 2, 0, 0, 0, 0, 0, 0, 10, 0, 4,
    0, 0, 0 };

  static const int8_T d[86] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 0, 0, 0, 0, 26,
    27, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0, 32, 33, 0, 0, 0, 0, 34, 35, 36,
    37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 42, 43, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 43U * sizeof(real_T));
  for (i = 0; i < 43; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 172U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 43; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 86; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 43; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37639198218262804;
  obj_Prior[1] = 0.21158129175946547;
  obj_Prior[2] = 0.2129175946547884;
  obj_Prior[3] = 0.19910913140311803;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificat_gpst0p4p3isq(const real_T obj_CutPredictorIndex
  [43], const real_T obj_Children[86], const real_T obj_CutPoint[43], const
  boolean_T obj_NanCutPoints[43], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[172], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 43] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 86]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 129];
    scores[i] = obj_ClassProbability[43 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithCach_o22p4vsubwbf(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[43], const real_T weak_learner_Children[86],
  const real_T weak_learner_CutPoint[43], const boolean_T
  weak_learner_NanCutPoints[43], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[172], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificat_gpst0p4p3isq(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_g(real_T obj_CutPredictorIndex[39],
  real_T obj_Children[78], real_T obj_CutPoint[39], boolean_T obj_NanCutPoints
  [39], boolean_T obj_InfCutPoints[39], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[156])
{
  int32_T i;
  static const real_T tmp[39] = { 0.0005343054096836643, 0.0,
    0.006957788860168146, 0.4207772255489022, 0.06525662953219286,
    0.08586038860411174, 0.0028933970048184857, 1.1796039121756485, 0.0, 0.0,
    0.0019688563970003065, 0.0, 14.452560505369537, 0.0, 2.1614430538922154, 0.0,
    0.0, 0.10717202857851262, 0.0013032896758269432, 0.016141991487531312, 0.0,
    0.10701973972834679, 0.0, 0.0, 0.0, 13.592733445228966, 0.0, 0.0, 0.0,
    0.16367127651210645, 0.004035919694923745, 0.0, 0.0, 0.004890701263488656,
    0.0, 0.0, 20.042933326448924, 0.0, 0.0 };

  static const boolean_T tmp_0[39] = { false, true, false, false, false, false,
    false, false, true, true, false, true, false, true, false, true, true, false,
    false, false, true, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, false, true, true };

  static const real_T tmp_1[156] = { 0.35768374164810396, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.2129175946547894, 0.0, 0.33148404993065184,
    0.008438818565400845, 0.645690834473326, 0.0, 0.01398601398601395,
    0.8939393939393946, 0.0, 0.0, 0.0, 0.0, 0.014285714285714249, 0.0,
    0.9402390438247014, 0.0, 0.0, 0.0, 0.5454545454545454, 0.9477911646586348,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.87378640776699, 1.0, 0.0, 0.0,
    0.047619047619047616, 0.9675675675675676, 1.0, 0.0, 0.9781420765027323, 0.0,
    1.0, 0.7333333333333334, 0.0, 1.0, 0.2129175946547894, 0.0,
    0.33148404993065184, 0.5935302390998612, 0.07660738714090261,
    0.03546099290780159, 0.9603729603729604, 0.10606060606060547, 0.0, 1.0,
    0.007299270072992736, 0.0, 0.980952380952381, 1.0, 0.05976095617529853, 0.0,
    1.0, 0.9951100244498778, 0.45454545454545453, 0.05220883534136522, 1.0,
    0.9534883720930232, 1.0, 0.0, 1.0, 0.12621359223300987, 0.0, 1.0, 0.0,
    0.9523809523809523, 0.03243243243243248, 0.0, 1.0, 0.021857923497267794, 1.0,
    0.0, 0.26666666666666666, 1.0, 0.0, 0.21648106904231731, 0.0,
    0.33703190013869627, 0.39803094233473785, 0.27770177838577154,
    0.9645390070921985, 0.025641025641025574, 0.0, 1.0, 0.0, 0.9927007299270072,
    1.0, 0.00476190476190475, 0.0, 0.0, 1.0, 0.0, 0.004889975550122238, 0.0, 0.0,
    0.0, 0.04651162790697677, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[39] = { 10, 0, 9, 4, 9, 3, 1, 4, 0, 0, 9, 0, 5, 0, 4, 0,
    0, 2, 8, 9, 0, 2, 0, 0, 0, 5, 0, 0, 0, 3, 8, 0, 0, 1, 0, 0, 5, 0, 0 };

  static const int8_T d[78] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 24,
    25, 26, 27, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 32, 33,
    34, 35, 0, 0, 0, 0, 36, 37, 0, 0, 0, 0, 38, 39, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 39U * sizeof(real_T));
  for (i = 0; i < 39; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 156U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 39; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 78; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 39; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3576837416481069;
  obj_Prior[1] = 0.2129175946547884;
  obj_Prior[2] = 0.2129175946547884;
  obj_Prior[3] = 0.21648106904231626;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_gk(real_T obj_CutPredictorIndex[53],
  real_T obj_Children[106], real_T obj_CutPoint[53], boolean_T obj_NanCutPoints
  [53], boolean_T obj_InfCutPoints[53], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[212])
{
  int32_T i;
  static const real_T tmp[53] = { 0.006426228580249356, 1.1813906986027942,
    0.08675042442037463, 0.10221310508189356, 0.1344733869952961, 0.0,
    0.8979413972055887, 3.7094083839075287, 0.003181154741298652,
    0.30232602109322, 0.0, 0.0022213639071833285, 0.46761329083168385,
    0.08602593973885742, 0.00487156994339347, 0.13844567828714052,
    0.0034943488998565374, 0.004701997170662565, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.8994489618759145, 0.001955674787897246, 0.0, 0.0035225908242109546, 0.0,
    0.0, 0.0010841619921793076, 0.0, 0.0, 0.008480713578116387, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.01960711134017208, 0.27214695531527705, 0.0,
    0.17321401288680385, 7.19426157981164, 0.0, 0.0, 0.0, 0.0,
    0.027399350761358143, 0.0, 0.0 };

  static const boolean_T tmp_0[53] = { false, false, false, false, false, true,
    false, false, false, false, true, false, false, false, false, false, false,
    false, true, true, true, true, true, false, false, true, false, true, true,
    false, true, true, false, true, true, true, true, true, true, true, true,
    false, false, true, false, false, true, true, true, true, false, true, true
  };

  static const real_T tmp_1[212] = { 0.39109131403117686, 0.003738317757009346,
    0.7438297872340406, 0.007532956685499064, 0.0, 1.0, 0.0,
    0.019607843137254916, 0.0, 0.0, 0.0, 0.0, 0.0, 0.022346368715083813, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.36363636363636365, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21202672605790787,
    0.32149532710280354, 0.1123404255319159, 0.0, 0.6382189239332094, 0.0,
    0.4385382059800668, 0.0, 0.0, 0.8797953964194373, 0.0, 0.0,
    0.7252747252747257, 0.0, 0.0, 0.0, 0.0, 0.9476584022038567, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9555555555555555,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.8405797101449274,
    0.9828178694158076, 1.0, 0.15384615384615385, 0.9640287769784173, 1.0, 1.0,
    0.0, 0.0, 0.9852941176470589, 1.0, 0.0, 0.205790645879734,
    0.37102803738317836, 0.05531914893617056, 0.6591337099811678,
    0.0871985157699443, 0.0, 0.21594684385382024, 0.16176470588235306,
    0.9694189602446482, 0.12020460358056262, 0.0, 0.5462184873949579, 0.0,
    0.06703910614525144, 0.84, 0.18181818181818182, 0.9968354430379747,
    0.05234159779614328, 1.0, 0.0, 1.0, 0.0, 0.0, 0.6363636363636364,
    0.029761904761904778, 1.0, 0.6666666666666667, 0.0, 1.0, 0.9, 1.0, 1.0,
    0.044444444444444474, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.15942028985507267, 0.01718213058419252, 0.0, 0.8461538461538461,
    0.0359712230215827, 0.0, 0.0, 1.0, 1.0, 0.014705882352941164, 0.0, 1.0,
    0.19109131403118135, 0.3037383177570088, 0.08851063829787305,
    0.33333333333333304, 0.27458256029684625, 0.0, 0.345514950166113,
    0.818627450980392, 0.03058103975535175, 0.0, 1.0, 0.4537815126050421,
    0.27472527472527436, 0.9106145251396648, 0.16, 0.8181818181818181,
    0.003164556962025324, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.9702380952380952,
    0.0, 0.33333333333333337, 1.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const int8_T c[53] = { 1, 4, 3, 3, 10, 0, 4, 5, 1, 6, 0, 9, 2, 2, 10, 2,
    1, 9, 0, 0, 0, 0, 0, 5, 9, 0, 1, 0, 0, 8, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0,
    10, 2, 0, 2, 7, 0, 0, 0, 0, 10, 0, 0 };

  static const int8_T d[106] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 38, 39, 0, 0, 0,
    0, 40, 41, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 44, 45, 46, 47, 0, 0, 48, 49, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 52, 53, 0,
    0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 53U * sizeof(real_T));
  for (i = 0; i < 53; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 212U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 53; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 106; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 53; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3910913140311804;
  obj_Prior[1] = 0.21202672605790646;
  obj_Prior[2] = 0.20579064587973275;
  obj_Prior[3] = 0.1910913140311804;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_C_gkd(real_T obj_CutPredictorIndex[55],
  real_T obj_Children[110], real_T obj_CutPoint[55], boolean_T obj_NanCutPoints
  [55], boolean_T obj_InfCutPoints[55], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[220])
{
  int32_T i;
  static const real_T tmp[55] = { 0.07944453635367484, 0.0, 0.435542985657873,
    0.1567899144497448, 0.0, 0.4102404590818363, 0.007092095439852447,
    0.004314710136244343, 1.1162542115768463, 0.0, 0.010733883138640382,
    3.142400908166266, 0.0, 0.003196845147595434, 13.396392114921976,
    0.004231403404129242, 0.1602803564558569, 0.08725004727849969, 0.0,
    0.1401697365059066, 0.1107381706312475, 0.0, 0.002372369332315511, 0.0,
    20.867788430268902, 0.0, 0.01599384612690863, 0.0, 0.0, 0.0, 0.0,
    3.576070149069099, 0.0, 0.0, 0.0, -0.07184349177323515, 0.0,
    0.21302457305199882, 0.0, 0.0, 0.11059707194227922, 0.0, 0.0,
    1.2358064670658684, 0.0, 0.008289342594108656, 0.0, 0.0,
    0.004690548438463711, 0.0, 0.0, 0.02684018036423489, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[55] = { false, true, false, false, true, false,
    false, false, false, true, false, false, true, false, false, false, false,
    false, true, false, false, true, false, true, false, true, false, true, true,
    true, true, false, true, true, true, false, true, false, true, true, false,
    true, true, false, true, false, true, true, false, true, true, false, true,
    true, true };

  static const real_T tmp_1[220] = { 0.3670378619153643, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.21336302895323048, 0.0, 0.3370865587614357,
    0.4025210084033621, 0.0, 0.04461538461538464, 0.8333333333333339, 0.0,
    0.06807511737089196, 0.0, 0.8964143426294825, 0.0, 0.0, 0.0, 0.90625,
    0.636363636363636, 0.9602977667493797, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.9666666666666667, 1.0, 0.18181818181818182, 0.0, 0.9650872817955112, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.027027027027027032, 1.0, 0.875, 1.0,
    0.0, 0.0, 1.0, 0.0, 0.9607843137254902, 0.0, 0.0, 0.0, 0.0,
    0.9800000000000001, 0.0, 0.0, 0.9898989898989898, 0.0, 1.0, 0.0,
    0.2124721603563485, 0.0, 0.3356790992258973, 0.4008403361344545, 0.0,
    0.5953846153846166, 0.166666666666666, 0.058035714285714454,
    0.8779342723004695, 1.0, 0.10358565737051743, 0.8666666666666667, 0.0,
    0.9416243654822335, 0.09375, 0.36363636363636404, 0.039702233250620285, 0.5,
    1.0, 0.05, 0.9893048128342246, 1.0, 0.03333333333333333, 0.0,
    0.8181818181818181, 1.0, 0.03491271820448872, 0.0, 1.0, 0.0, 1.0,
    0.9374999999999999, 1.0, 0.0, 1.0, 0.972972972972973, 0.0,
    0.12500000000000003, 0.0, 0.0, 0.9677419354838709, 0.0, 1.0,
    0.03921568627450982, 1.0, 0.9836065573770492, 0.0, 1.0, 0.020000000000000007,
    1.0, 0.0, 0.010101010101010104, 1.0, 0.0, 1.0, 0.20712694877505664, 0.0,
    0.32723434201266705, 0.19663865546218348, 1.0, 0.35999999999999877, 0.0,
    0.9419642857142855, 0.05399061032863845, 0.0, 0.0, 0.13333333333333333, 1.0,
    0.05837563451776645, 0.0, 0.0, 0.0, 0.5, 0.0, 0.95, 0.010695187165775394,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0625000000000001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.03225806451612908, 0.0, 0.0, 0.0, 0.0,
    0.016393442622950845, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[55] = { 2, 0, 2, 2, 0, 4, 9, 10, 4, 0, 9, 5, 0, 1, 5, 1,
    3, 2, 0, 2, 2, 0, 8, 0, 5, 0, 9, 0, 0, 0, 0, 5, 0, 0, 0, 6, 0, 3, 0, 0, 2, 0,
    0, 4, 0, 1, 0, 0, 8, 0, 0, 10, 0, 0, 0 };

  static const int8_T d[110] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 0, 0, 30, 31, 32, 33, 0, 0, 34, 35, 0, 0, 36, 37, 0, 0, 38, 39, 0, 0, 0,
    0, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0, 44, 45, 0, 0, 0, 0,
    46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 50, 51, 0, 0, 0, 0, 52, 53, 0, 0, 0, 0, 54,
    55, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 55U * sizeof(real_T));
  for (i = 0; i < 55; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 220U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 55; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 110; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 55; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36703786191536747;
  obj_Prior[1] = 0.2133630289532294;
  obj_Prior[2] = 0.21247216035634744;
  obj_Prior[3] = 0.2071269487750557;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassifica_gpst0p4p3isq4(const real_T obj_CutPredictorIndex
  [55], const real_T obj_Children[110], const real_T obj_CutPoint[55], const
  boolean_T obj_NanCutPoints[55], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[220], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 55] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 110]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 165];
    scores[i] = obj_ClassProbability[55 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithCac_o22p4vsubwbfs(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[55], const real_T weak_learner_Children[110],
  const real_T weak_learner_CutPoint[55], const boolean_T
  weak_learner_NanCutPoints[55], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[220], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassifica_gpst0p4p3isq4(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree__gkd2(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196])
{
  int32_T i;
  static const real_T tmp[49] = { 0.0005511413578816758, 0.0,
    0.0072716187798791375, 0.1073882180280788, 0.06536073956848822,
    3.3119845701517576, 0.0031758923169286444, 0.31592690184863964, 0.0,
    0.004147574572845165, 0.005128778500727391, 0.0027844591870945633,
    0.001433414236580562, 0.010740908690905972, 0.0, 0.0, 0.0, 0.0,
    4.447411198159676, 0.0, 0.005796716010485469, 0.0, 16.92612836158439,
    7.500372119096591, -0.17825626866522581, 0.0, 0.0016353940728616424, 0.0,
    0.0, 0.0, 9.539089847708066, 0.0, 0.0, 7.029798720478523, 1.220375129740519,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0054762370766279905, 0.04609289061943246,
    0.0, 0.0, 0.0, 0.024625254903270423, 0.0, 0.0 };

  static const boolean_T tmp_0[49] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, true, true, true,
    true, false, true, false, true, false, false, false, true, false, true, true,
    true, false, true, true, false, false, true, true, true, true, true, true,
    false, false, true, true, true, false, true, true };

  static const real_T tmp_1[196] = { 0.36080178173719063, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.21024498886414342, 0.0, 0.3289198606271775, 0.01620029455080999,
    0.6097883597883614, 0.0, 0.02709359605911324, 0.9021526418786696, 0.0, 0.0,
    0.0, 0.3636363636363636, 0.01772151898734173, 0.9257028112449802, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.7999999999999999, 0.0, 0.017857142857142818,
    0.7499999999999998, 0.9743589743589743, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.5384615384615384, 0.0, 1.0, 0.7142857142857143, 0.9891598915989159, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.39999999999999997, 0.9972527472527472, 0.0, 1.0,
    1.0, 0.9814814814814814, 0.0, 1.0, 0.21336302895323048, 0.0,
    0.33379790940766557, 0.6318114874815922, 0.0661375661375661,
    0.15750915750915795, 0.9507389162561577, 0.09784735812133044, 0.0,
    0.022123893805309786, 0.8085106382978723, 0.09090909090909091,
    0.9746835443037976, 0.0742971887550198, 1.0, 1.0, 0.0, 1.0, 0.4, 0.0, 0.2,
    0.0, 0.9821428571428572, 0.2500000000000003, 0.025641025641025612, 0.0,
    0.8571428571428571, 1.0, 0.0, 1.0, 0.46153846153846156, 1.0, 0.0,
    0.28571428571428575, 0.010840108401084007, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.6,
    0.0027472527472527466, 1.0, 0.0, 0.0, 0.018518518518518542, 1.0, 0.0,
    0.21559020044543542, 0.0, 0.3372822299651569, 0.3519882179675978,
    0.32407407407407246, 0.842490842490842, 0.022167487684729016, 0.0, 1.0,
    0.9778761061946902, 0.1914893617021276, 0.5454545454545454,
    0.007594936708860744, 0.0, 0.0, 0.0, 1.0, 0.0, 0.6, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 1.0, 0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[49] = { 10, 0, 9, 2, 9, 5, 1, 6, 0, 10, 10, 1, 9, 9, 0,
    0, 0, 0, 5, 0, 9, 0, 5, 7, 6, 0, 9, 0, 0, 0, 7, 0, 0, 7, 4, 0, 0, 0, 0, 0, 0,
    1, 10, 0, 0, 0, 9, 0, 0 };

  static const int8_T d[98] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 0, 0, 26,
    27, 0, 0, 28, 29, 0, 0, 30, 31, 32, 33, 34, 35, 0, 0, 36, 37, 0, 0, 0, 0, 0,
    0, 38, 39, 0, 0, 0, 0, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    44, 45, 46, 47, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 49U * sizeof(real_T));
  for (i = 0; i < 49; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 196U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 49; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 98; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 49; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3608017817371938;
  obj_Prior[1] = 0.21024498886414256;
  obj_Prior[2] = 0.21336302895322942;
  obj_Prior[3] = 0.21559020044543434;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_gkd2u(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180])
{
  int32_T i;
  static const real_T tmp[45] = { 0.08012190595190324, 0.0, 0.16052573842886475,
    0.0018650900666421508, 2.4422121756487027, 0.004134761726265451,
    15.524099247880462, 1.2862425748502995, 0.0, 0.0, 0.6932725948103792,
    0.0029653744854041906, 0.009347261067670032, 0.26219563130716717,
    0.272120275234923, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0012275837395503604, 0.0,
    0.006303054464617781, 19.53203399787503, 5.324526637961523, 0.0, 0.0,
    1.9701756886227546, 0.0, 1.7782585828343314, 0.0, 0.0, 0.19515867527784697,
    0.15596114613816234, 0.0, 0.0, 0.0048801128407247995, 0.0, 0.0, 0.0, 0.0,
    0.021981642962288547, 0.0, 0.0 };

  static const boolean_T tmp_0[45] = { false, true, false, false, false, false,
    false, false, true, true, false, false, false, false, false, true, true,
    true, true, true, true, false, true, false, false, false, true, true, false,
    true, false, true, true, false, false, true, true, false, true, true, true,
    true, false, true, true };

  static const real_T tmp_1[180] = { 0.37861915367482957, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21158129175946666, 0.0,
    0.3405017921146954, 0.05985401459854018, 0.6112676056338044, 0.0,
    0.09715639810426524, 0.8875255623721887, 0.0, 0.0, 0.0, 0.0,
    0.8541666666666666, 0.3111111111111111, 0.9459459459459462, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.1388888888888889, 1.0, 0.9881516587677726,
    0.13636363636363635, 0.7142857142857142, 0.0, 0.0, 0.9928571428571429, 0.0,
    0.5999999999999999, 0.0, 1.0, 0.9951923076923077, 0.7499999999999999, 1.0,
    0.0, 0.9857142857142858, 1.0, 1.0, 0.0, 1.0, 0.9090909090909091, 1.0, 0.0,
    0.19510022271715008, 0.0, 0.31397849462365557, 0.5591240875912422,
    0.0774647887323942, 0.01140684410646393, 0.9004739336492892,
    0.11247443762781138, 0.0, 1.0, 0.003831417624521091, 0.9973262032085561,
    0.1458333333333334, 0.6888888888888889, 0.054054054054053904, 0.0, 1.0, 0.0,
    1.0, 1.0, 0.0, 0.8611111111111112, 0.0, 0.011848341232227454,
    0.8636363636363636, 0.2857142857142857, 1.0, 1.0, 0.007142857142857123, 1.0,
    0.4, 1.0, 0.0, 0.004807692307692295, 0.25000000000000006, 0.0, 1.0,
    0.014285714285714273, 0.0, 0.0, 1.0, 0.0, 0.09090909090909091, 0.0, 1.0,
    0.21469933184855358, 0.0, 0.3455197132616489, 0.38102189781021756,
    0.31126760563380146, 0.9885931558935361, 0.0023696682464454948, 0.0, 1.0,
    0.0, 0.996168582375479, 0.002673796791443848, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[45] = { 3, 0, 2, 9, 4, 10, 5, 4, 0, 0, 4, 1, 10, 3, 6, 0,
    0, 0, 0, 0, 0, 8, 0, 9, 5, 7, 0, 0, 4, 0, 4, 0, 0, 3, 6, 0, 0, 1, 0, 0, 0, 0,
    10, 0, 0 };

  static const int8_T d[90] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 26, 27, 0, 0, 28, 29, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 0,
    0, 36, 37, 0, 0, 0, 0, 38, 39, 40, 41, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0,
    0, 0, 44, 45, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 45U * sizeof(real_T));
  for (i = 0; i < 45; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 180U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 45; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 90; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 45; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37861915367483295;
  obj_Prior[1] = 0.21158129175946547;
  obj_Prior[2] = 0.19510022271714922;
  obj_Prior[3] = 0.21469933184855233;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTre_gkd2u4(real_T obj_CutPredictorIndex[47],
  real_T obj_Children[94], real_T obj_CutPoint[47], boolean_T obj_NanCutPoints
  [47], boolean_T obj_InfCutPoints[47], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[188])
{
  int32_T i;
  static const real_T tmp[47] = { 0.08012190595190324, 0.0, 0.007085046280946148,
    0.4207772255489022, 2.4336843313373255, 0.004314710136244343,
    0.002899244986589325, 0.1465089366059796, 0.0, 0.0, 0.12082311188983894,
    0.012922505803364522, 14.83457930750589, 0.0, 0.2751489368047294,
    3.559288267749268, 0.0, 0.0, 0.0, -0.052257847917980924,
    0.004023957563388844, 1.1822028742514972, 0.019011351886857958, 0.0, 0.0,
    0.0016987816007528554, 0.0, 0.0, 0.0, 0.005694826538329591,
    0.012673485756592773, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 13.413044152702682,
    0.19514353860991954, -0.01883989284552475, 0.0, 0.19432182801624964, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[47] = { false, true, false, false, false, false,
    false, false, true, true, false, false, false, true, false, false, true,
    true, true, false, false, false, false, true, true, false, true, true, true,
    false, false, true, true, true, true, true, true, false, false, false, true,
    false, true, true, true, true, true };

  static const real_T tmp_1[188] = { 0.37282850779509696, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.21380846325167155, 0.0, 0.340909090909091, 0.016845329249617142,
    0.6211920529801345, 0.0, 0.026634382566585908, 0.9071566731141204, 0.0, 0.0,
    0.0, 0.11111111111111112, 0.024752475247524705, 0.0, 0.9178082191780826, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.625, 0.9452332657200815, 0.16666666666666669, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.058823529411764705, 0.9768907563025211, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.9275362318840581, 0.9970414201183432, 0.09090909090909091,
    1.0, 0.984375, 1.0, 1.0, 0.0, 1.0, 0.0, 0.20534521158129276, 0.0,
    0.32741477272727265, 0.6324655436447182, 0.06357615894039718,
    0.08333333333333359, 0.9515738498789347, 0.0928433268858796, 0.0, 1.0,
    0.01785714285714292, 0.0, 0.9727722772277227, 1.0, 0.08219178082191742,
    0.00452488687782807, 1.0, 0.0, 0.0, 0.997422680412371, 0.37500000000000006,
    0.05476673427991863, 0.8333333333333334, 0.0, 1.0, 0.9565217391304348, 1.0,
    0.0, 1.0, 0.9411764705882353, 0.023109243697478885, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0, 0.07246376811594198, 0.0029585798816568077, 0.9090909090909091, 0.0,
    0.015625000000000028, 0.0, 0.0, 1.0, 0.0, 1.0, 0.2080178173719387, 0.0,
    0.33167613636363635, 0.3506891271056647, 0.31523178807946844,
    0.9166666666666664, 0.02179176755447938, 0.0, 1.0, 0.0, 0.9821428571428571,
    0.888888888888889, 0.0024752475247524705, 0.0, 0.0, 0.995475113122172, 0.0,
    1.0, 0.0, 0.002577319587628862, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.043478260869565216, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[47] = { 3, 0, 9, 4, 4, 10, 1, 3, 0, 0, 2, 10, 5, 0, 6, 5,
    0, 0, 0, 6, 1, 4, 10, 0, 0, 9, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 0, 5, 2, 6, 0,
    2, 0, 0, 0, 0, 0 };

  static const int8_T d[94] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 0, 0, 0, 0, 0,
    0, 26, 27, 28, 29, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 0, 0, 0, 0, 0, 0, 36,
    37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0,
    46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 47U * sizeof(real_T));
  for (i = 0; i < 47; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 188U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 47; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 94; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 47; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37282850779510024;
  obj_Prior[1] = 0.21380846325167038;
  obj_Prior[2] = 0.20534521158129176;
  obj_Prior[3] = 0.20801781737193764;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTr_gkd2u4z(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[124])
{
  int32_T i;
  static const real_T tmp[31] = { 0.0005511413578816758, 0.0, 1.1813906986027942,
    0.0017260388163948303, 2.4422121756487027, 0.002330103305554363,
    0.0028456896168600307, 0.0061836300929036785, 0.0, 0.08139616261398952, 0.0,
    0.0, 0.0, 0.0032765814757204363, 2.1614430538922154, 0.0, 0.0, 0.0, 0.0,
    0.2654647905243882, 0.0, 0.2751489368047294, 0.0, 13.413044152702682,
    0.003977043315712322, 0.0037942244807260463, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, true, false, false, false, false,
    false, false, true, false, true, true, true, false, false, true, true, true,
    true, false, true, false, true, false, false, false, true, true, true, true,
    true };

  static const real_T tmp_1[124] = { 0.36525612472160046, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21336302895323048,
    0.0, 0.336140350877193, 0.0, 0.6220779220779242, 0.0, 0.0,
    0.9247104247104251, 0.0, 0.0, 0.0, 0.0, 0.0, 0.09090909090909091,
    0.9428007889546354, 0.0, 0.0, 1.0, 0.0, 0.9465346534653468, 0.0,
    0.9003690036900365, 1.0, 0.9343629343629342, 0.16666666666666669, 0.15, 1.0,
    1.0, 0.0, 1.0, 0.0, 0.19910913140311884, 0.0, 0.3136842105263155,
    0.6229007633587802, 0.05064935064935055, 0.0242914979757086,
    0.9852941176470589, 0.0752895752895749, 0.0, 0.008230452674897153, 1.0, 0.0,
    1.0, 0.9090909090909091, 0.05719921104536462, 1.0, 0.0, 0.0, 1.0,
    0.053465346534653214, 1.0, 0.09963099630996348, 0.0, 0.0656370656370659,
    0.8333333333333333, 0.8500000000000001, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.22227171492205025, 0.0, 0.3501754385964915, 0.37709923664121975,
    0.3272727272727253, 0.9757085020242914, 0.014705882352941143, 0.0, 1.0,
    0.9917695473251028, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[31] = { 10, 0, 4, 9, 4, 8, 1, 9, 0, 2, 0, 0, 0, 1, 4, 0,
    0, 0, 0, 3, 0, 6, 0, 5, 1, 1, 0, 0, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0,
    22, 23, 0, 0, 24, 25, 0, 0, 26, 27, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 124U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36525612472160357;
  obj_Prior[1] = 0.2133630289532294;
  obj_Prior[2] = 0.19910913140311803;
  obj_Prior[3] = 0.222271714922049;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationT_gkd2u4zd(real_T obj_CutPredictorIndex[39],
  real_T obj_Children[78], real_T obj_CutPoint[39], boolean_T obj_NanCutPoints
  [39], boolean_T obj_InfCutPoints[39], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[156])
{
  int32_T i;
  static const real_T tmp[39] = { 0.07743902859725196, 0.0, 1.1813906986027942,
    0.10405640349033901, 0.44355059080120485, 0.0015682116281618172,
    0.002057417701559171, 0.01164547971220281, 0.0, 0.004090001490131747,
    0.0032001138543226067, 0.007023654697150117, 0.0, 0.0, 0.009767193079320599,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.004243776392527444, 0.28244135030227946,
    0.0020016550539724135, 0.16266857498728796, 1.2521311976047906, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.2470775981808624, 0.17056148417173478, 0.0, 0.0,
    0.024360555516978716, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[39] = { false, true, false, false, false, false,
    false, false, true, false, false, false, true, true, false, true, true, true,
    true, true, true, false, false, false, false, false, true, true, true, true,
    true, false, false, true, true, false, true, true, true };

  static const real_T tmp_1[156] = { 0.3768374164810657, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.2097995545657027, 0.0, 0.3366690493209436, 0.0,
    0.6238410596026509, 0.0, 0.0, 0.9092664092664098, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.9235294117647062, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.6836734693877548,
    0.9805825242718448, 0.9104477611940297, 0.1935483870967742,
    0.9926289926289926, 0.0, 1.0, 0.0, 1.0, 0.0, 0.8, 0.9950248756218906, 0.0,
    1.0, 0.9285714285714286, 1.0, 1.0, 0.0, 0.20935412026726172, 0.0,
    0.33595425303788423, 0.6568322981366475, 0.06225165562913891,
    0.1440000000000004, 0.9822335025380711, 0.09073359073359026, 0.0,
    0.018518518518518576, 0.9411764705882353, 0.5625, 1.0, 1.0,
    0.07647058823529375, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.3163265306122453,
    0.019417475728155296, 0.08955223880597027, 0.8064516129032258,
    0.007371007371007354, 1.0, 0.0, 1.0, 0.0, 1.0, 0.2, 0.004975124378109442,
    1.0, 0.0, 0.07142857142857142, 0.0, 0.0, 1.0, 0.20400890868596985, 0.0,
    0.32737669764117217, 0.34316770186335255, 0.3139072847682101,
    0.8559999999999997, 0.017766497461928907, 0.0, 1.0, 0.9814814814814815,
    0.058823529411764705, 0.43750000000000006, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[39] = { 2, 0, 4, 2, 2, 9, 9, 10, 0, 10, 1, 10, 0, 0, 9,
    0, 0, 0, 0, 0, 0, 1, 6, 8, 2, 4, 0, 0, 0, 0, 0, 2, 2, 0, 0, 10, 0, 0, 0 };

  static const int8_T d[78] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 38, 39, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 39U * sizeof(real_T));
  for (i = 0; i < 39; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 156U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 39; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 78; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 39; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37683741648106905;
  obj_Prior[1] = 0.20979955456570157;
  obj_Prior[2] = 0.20935412026726058;
  obj_Prior[3] = 0.20400890868596883;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassification_gkd2u4zdv(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.0005343054096836643, 0.0,
    0.007085046280946148, 3.2968274070040104, 0.1344733869952961,
    0.11749611824400613, 0.0037398943714134197, 0.272120275234923, 0.0,
    0.003968133535574361, 0.0, 0.12858340450450817, 17.13957078596502,
    0.011468843032199926, 0.017706418628682996, 0.0, 0.0, 0.0, 0.0,
    3.4190639762271324, 0.004024036877417038, 7.423222338853745,
    0.01672620891613691, 8.606547627183845, 0.0, 0.0012416273996630795,
    0.0013985200442381699, 0.0, 0.0, 0.0, 0.0018123158618226832,
    12.48217377825466, -0.18140848083035166, 0.0, 0.0, 0.0, 0.0,
    -0.028501711962470706, 0.0, 0.024552198108721352, 0.0, 0.0, 0.0,
    14.173085902029737, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, false, false, true, true,
    true, true, false, false, false, false, false, true, false, false, true,
    true, true, false, false, false, true, true, true, true, false, true, false,
    true, true, true, false, true, true, true, true, true, true, true };

  static const real_T tmp_1[204] = { 0.36525612472160046, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.2044543429844107, 0.0, 0.32210526315789456, 0.014727540500736365,
    0.601876675603219, 0.0, 0.04366812227074248, 0.8684719535783372, 0.0, 0.0,
    0.0, 0.6, 0.004672897196261697, 0.9122448979591841, 0.07407407407407407, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.09999999999999999, 0.7222222222222223,
    0.9913294797687862, 0.6666666666666666, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.9369369369369369, 0.9375, 0.9968152866242037, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.9811320754716982, 0.0, 0.0, 1.0, 0.7999999999999999, 1.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 0.22360801781737322, 0.0, 0.35228070175438625,
    0.6391752577319605, 0.09115281501340457, 0.4955555555555556,
    0.9213973799126635, 0.13152804642166277, 0.0, 0.03404255319148949, 1.0, 0.0,
    0.9859813084112149, 0.08775510204081595, 0.9259259259259259, 1.0, 0.0, 0.0,
    0.0, 0.9901960784313725, 0.9, 0.2777777777777777, 0.008670520231213879,
    0.33333333333333337, 1.0, 0.9, 0.9948453608247423, 0.0, 1.0, 1.0,
    0.06306306306306307, 0.0625, 0.0031847133757961867, 1.0, 0.0, 0.0, 1.0, 0.8,
    1.0, 0.01886792452830189, 1.0, 1.0, 0.0, 0.2, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0, 0.20668151447661565, 0.0, 0.3256140350877192, 0.3460972017673032,
    0.3069705093833765, 0.5044444444444444, 0.03493449781659399, 0.0, 1.0,
    0.9659574468085105, 0.0, 0.4, 0.009345794392523393, 0.0, 0.0, 0.0, 1.0, 1.0,
    0.0, 0.009803921568627477, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1,
    0.005154639175257744, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 10, 0, 9, 5, 10, 2, 1, 6, 0, 10, 0, 2, 5, 9, 10,
    0, 0, 0, 0, 5, 1, 7, 10, 7, 0, 9, 8, 0, 0, 0, 8, 5, 6, 0, 0, 0, 0, 6, 0, 10,
    0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0,
    0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 36, 37, 38, 39, 0, 0, 0,
    0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 46, 47, 0, 0, 48,
    49, 0, 0, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36525612472160357;
  obj_Prior[1] = 0.2044543429844098;
  obj_Prior[2] = 0.22360801781737194;
  obj_Prior[3] = 0.2066815144766147;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassific_gpst0p4p3isq4m(const real_T obj_CutPredictorIndex
  [51], const real_T obj_Children[102], const real_T obj_CutPoint[51], const
  boolean_T obj_NanCutPoints[51], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[204], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 51] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 102]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 153];
    scores[i] = obj_ClassProbability[51 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithCa_o22p4vsubwbfsd(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[51], const real_T weak_learner_Children[102],
  const real_T weak_learner_CutPoint[51], const boolean_T
  weak_learner_NanCutPoints[51], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[204], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassific_gpst0p4p3isq4m(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificatio_gkd2u4zdvp(real_T obj_CutPredictorIndex[53],
  real_T obj_Children[106], real_T obj_CutPoint[53], boolean_T obj_NanCutPoints
  [53], boolean_T obj_InfCutPoints[53], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[212])
{
  int32_T i;
  static const real_T tmp[53] = { 0.08040307333828223, 0.3371483344081069,
    1.1768425149700596, 0.0, 0.0, 0.0018782192116963388, 0.06536073956848822,
    0.004226481526399742, 0.002627480965802771, 0.006799255947665533, 0.0,
    3.2306610945854093, 0.002386095871151641, 0.0, 14.537555566161597,
    0.15458642564778705, 2.19401129740519, 0.0, 0.0, 0.0, 0.0, 0.0,
    17.12164801945942, 0.0018072224940294942, 0.0, 0.2751489368047294, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.2860801397205588, 9.230756805304434, 0.04072061227213892,
    1.965302634730539, 0.0, 0.0, 6.976534747279798, 0.27464381638543894,
    0.008361006562636905, 0.010048092276139214, 5.295848433209889, 0.0, 0.0, 0.0,
    0.0015917435990136825, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[53] = { false, false, false, true, true, false,
    false, false, false, false, true, false, false, true, false, false, false,
    true, true, true, true, true, false, false, true, false, true, true, true,
    true, true, false, false, false, false, true, true, false, false, false,
    false, false, true, true, true, false, true, true, true, true, true, true,
    true };

  static const real_T tmp_1[212] = { 0.3665924276169234, 0.9987864077669903, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.21469933184855347, 0.0, 0.33919774806474323, 0.0,
    0.0, 0.0015360983102918593, 0.6246753246753267, 0.0, 0.002531645569620249,
    0.9075471698113212, 0.0, 0.0, 0.0, 0.0, 0.0025575447570332435,
    0.2105263157894737, 0.9334637964774954, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.33333333333333337, 0.8, 0.0, 0.9408284023668642, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.9731958762886599, 0.22727272727272727, 0.7586206896551724,
    0.986842105263158, 0.0, 1.0, 0.9090909090909091, 0.2857142857142857,
    0.9933035714285715, 0.625, 0.75, 1.0, 0.0, 1.0, 0.8888888888888888, 1.0, 0.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.19955456570155986, 0.0012135922330097193,
    0.3145672061928217, 0.0, 1.0, 0.6113671274961613, 0.06363636363636345,
    0.03125000000000013, 0.9873417721518987, 0.09245283018867873, 0.0,
    0.7142857142857142, 0.012048192771084388, 0.0, 0.9974424552429667,
    0.7894736842105263, 0.06653620352250458, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.6666666666666667, 0.2, 1.0, 0.059171597633135814, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.02680412371134008, 0.7727272727272728, 0.2413793103448276,
    0.013157894736842052, 1.0, 0.0, 0.09090909090909091, 0.7142857142857142,
    0.006696428571428545, 0.37500000000000006, 0.25, 0.0, 1.0, 0.0,
    0.1111111111111111, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.21915367483296336,
    0.0, 0.3462350457424351, 0.0, 0.0, 0.3870967741935468, 0.31168831168830985,
    0.9687499999999999, 0.010126582278480995, 0.0, 1.0, 0.2857142857142857,
    0.9879518072289156, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[53] = { 3, 4, 4, 0, 0, 9, 9, 10, 1, 9, 0, 5, 8, 0, 5, 2,
    4, 0, 0, 0, 0, 0, 5, 8, 0, 6, 0, 0, 0, 0, 0, 4, 7, 10, 4, 0, 0, 7, 3, 9, 9,
    7, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[106] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 26, 27, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 34, 35, 36, 37, 38, 39, 40, 41, 0, 0, 0, 0, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 51, 0, 0, 0, 0, 0, 0, 52, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 53U * sizeof(real_T));
  for (i = 0; i < 53; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 212U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 53; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 106; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 53; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3665924276169265;
  obj_Prior[1] = 0.21469933184855233;
  obj_Prior[2] = 0.19955456570155902;
  obj_Prior[3] = 0.21915367483296214;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificati_gkd2u4zdvpw(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.0008654461460154454, 0.0,
    0.007072374718226294, 0.10890347953714333, 0.435542985657873,
    4.641107980358363, 1.1796039121756485, 1.1813906986027942, 0.0,
    0.0017979479234467924, 0.0018701871129421718, 0.0028456896168600307,
    0.004019159064683133, 0.0, 0.005691999674187374, 0.002330103305554363, 0.0,
    0.004720311123494808, 0.0, 0.0, 0.0, 0.0, 0.0, 1.9605920159680639, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.2906283233532934, 0.0, 0.26201415911732834,
    1.6971222355289421, 7.394864874075996, 0.0, 0.28547001187208587,
    15.192486180249674, -0.04831413457696379, 0.0, 0.00834590680338994, 0.0,
    0.262486238030072, 0.0, 0.0, 0.0, 0.02091085773023302, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, true, false, false, true,
    false, true, true, true, true, true, false, true, true, true, true, true,
    false, true, false, false, false, true, false, false, false, true, false,
    true, false, true, true, true, false, true, true, true, true, true };

  static const real_T tmp_1[204] = { 0.3630289532293956, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.2178173719376403, 0.0, 0.34195804195804214, 0.015015015015015006,
    0.6269633507853423, 0.0, 0.02538071065989845, 0.8740875912408766, 0.0, 0.0,
    0.0, 0.0, 0.39999999999999997, 0.0, 0.933723196881092, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.9392156862745101, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.9503968253968257, 0.0, 0.6666666666666667, 0.9722222222222223, 0.5, 1.0,
    0.984732824427481, 0.9066666666666665, 0.07692307692307693, 1.0,
    0.997422680412371, 0.0, 0.36363636363636365, 1.0, 1.0, 0.0,
    0.9629629629629629, 1.0, 0.0, 1.0, 1.0, 0.0, 0.21870824053452229, 0.0,
    0.3433566433566435, 0.6336336336336352, 0.0903141361256541,
    0.16544117647058865, 0.9568527918781726, 0.12591240875912332, 0.0,
    0.0570175438596493, 0.7272727272727273, 0.981029810298103, 0.6, 1.0,
    0.06627680311890807, 0.009216589861751182, 1.0, 0.19999999999999998, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.06078431372548991, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.049603174603174364, 1.0, 0.33333333333333337, 0.027777777777777662, 0.5,
    0.0, 0.01526717557251906, 0.09333333333333348, 0.923076923076923, 0.0,
    0.0025773195876288616, 1.0, 0.6363636363636364, 0.0, 0.0, 1.0,
    0.037037037037037035, 0.0, 1.0, 0.0, 0.0, 1.0, 0.20044543429844175, 0.0,
    0.31468531468531447, 0.35135135135134976, 0.28272251308900376,
    0.8345588235294115, 0.017766497461928914, 0.0, 1.0, 0.9429824561403507,
    0.2727272727272727, 0.01897018970189701, 0.0, 0.0, 0.0, 0.9907834101382488,
    0.0, 0.8, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 10, 0, 9, 3, 2, 7, 4, 4, 0, 9, 9, 1, 1, 0, 8, 8,
    0, 10, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 2, 4, 7, 0, 6, 5, 6, 0, 9, 0,
    3, 0, 0, 0, 10, 0, 0, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 0, 0, 28,
    29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32,
    33, 0, 0, 34, 35, 36, 37, 38, 39, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 46, 47,
    0, 0, 48, 49, 0, 0, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36302895322939865;
  obj_Prior[1] = 0.2178173719376392;
  obj_Prior[2] = 0.21870824053452115;
  obj_Prior[3] = 0.20044543429844097;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificat_gkd2u4zdvpwa(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180])
{
  int32_T i;
  static const real_T tmp[45] = { 0.07988847617151121, 0.0, 1.1796039121756485,
    0.4102404590818363, 0.13542646950941317, 0.0038684782162721684,
    0.0032840925765656188, 0.2252609441748376, 0.0, 0.0, 0.0019537893565226574,
    0.0, 0.001148659482976413, 0.28547001187208587, 0.0, 0.0,
    0.001977685476977842, 0.0, 0.0, 11.536025305766277, 0.017500960890579547,
    0.0, 0.0, 0.0, 13.587885304629305, 0.4093537638642756, 0.0,
    13.00001612314326, 0.004904875903087602, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.954338263473054, 1.4810022954091817, 0.03663308082612726,
    0.011292029925253154, 0.0, 0.0, 0.0, 0.0, 1.4777535928143712, 0.0, 0.0 };

  static const boolean_T tmp_0[45] = { false, true, false, false, false, false,
    false, false, true, true, false, true, false, false, true, true, false, true,
    true, false, false, true, true, true, false, false, true, false, false, true,
    true, true, true, true, false, false, false, false, true, true, true, true,
    false, true, true };

  static const real_T tmp_1[180] = { 0.36659242761692334, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20534521158129268, 0.0,
    0.3241912798874823, 0.0, 0.613031914893619, 0.0, 0.0, 0.9183266932270919,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.8446969696969693, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.9208333333333331, 0.08333333333333334, 0.0, 0.0, 0.0, 0.9735682819383259,
    0.22222222222222224, 0.0, 0.5714285714285714, 0.9863636363636363, 1.0, 0.0,
    1.0, 0.0, 0.0, 0.9908675799086757, 0.9953488372093023, 0.75,
    0.9888888888888888, 1.0, 1.0, 0.0, 1.0, 0.875, 1.0, 0.0, 0.2080178173719386,
    0.0, 0.3284106891701828, 0.6358208955223899, 0.054521276595744586,
    0.030303030303030408, 0.9544419134396356, 0.08167330677290799, 0.0, 1.0,
    0.004444444444444461, 0.0, 0.9882075471698114, 0.1553030303030307, 0.0, 0.0,
    0.33333333333333337, 0.0, 1.0, 0.07916666666666691, 0.9166666666666666, 1.0,
    0.0, 1.0, 0.0264317180616741, 0.7777777777777778, 1.0, 0.42857142857142855,
    0.01363636363636368, 0.0, 1.0, 0.0, 1.0, 1.0, 0.009132420091324232,
    0.00465116279069769, 0.25, 0.011111111111111118, 0.0, 0.0, 1.0, 0.0, 0.125,
    0.0, 1.0, 0.2200445434298453, 0.0, 0.34739803094233496, 0.3641791044776102,
    0.3324468085106364, 0.9696969696969695, 0.04555808656036433, 0.0, 1.0, 0.0,
    0.9955555555555556, 1.0, 0.011792452830188645, 0.0, 0.0, 1.0,
    0.6666666666666666, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const int8_T c[45] = { 2, 0, 4, 4, 10, 10, 1, 3, 0, 0, 8, 0, 9, 6, 0, 0,
    8, 0, 0, 5, 10, 0, 0, 0, 5, 6, 0, 5, 9, 0, 0, 0, 0, 0, 4, 4, 10, 9, 0, 0, 0,
    0, 4, 0, 0 };

  static const int8_T d[90] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 0, 0,
    24, 25, 26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 32, 33, 34, 35, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 36, 37, 38, 39, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0, 0,
    0, 44, 45, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 45U * sizeof(real_T));
  for (i = 0; i < 45; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 180U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 45; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 90; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 45; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3665924276169265;
  obj_Prior[1] = 0.20534521158129176;
  obj_Prior[2] = 0.20801781737193764;
  obj_Prior[3] = 0.22004454342984409;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassifica_gkd2u4zdvpwal(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.0005340809045944201, 0.0, 1.1813906986027942,
    0.10447134297475781, 0.4370204932144296, 3.3224236178070923,
    0.12533236242484652, 2.113037385229541, 0.0, 0.002035680477942979,
    0.10329257813938288, 0.001747804845224242, 0.0, 0.0061836300929036785, 0.0,
    0.0021057293376541223, 0.0, 0.008392730503488396, 0.0, 12.698895258666086,
    3.814912409719377, 0.0, 0.30232602109322, 0.0, 0.0, 0.003344492986682884,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.282425349301397, 0.0, 0.0, 0.0,
    13.773563367519277, 8.01958100103831, 0.027370602174429083, 0.0,
    0.011310498657385336, 0.0, 0.0, 0.0, 0.18155435437027193,
    0.014204232262706215, 0.0, 0.0, 1.6264629540918163, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, false, false,
    false, false, true, false, false, false, true, false, true, false, true,
    false, true, false, false, true, false, true, true, false, true, true, true,
    true, true, false, true, true, true, false, false, false, true, false, true,
    true, true, false, false, true, true, false, true, true, true };

  static const real_T tmp_1[204] = { 0.3616926503340727, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.22093541202672723, 0.0, 0.3461270062805305, 0.0, 0.6416558861578289, 0.0,
    0.0, 0.9411764705882356, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9465648854961836, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.964980544747082, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9802371541501977, 0.0, 0.0, 0.0, 0.8611111111111112,
    0.9893617021276597, 0.6428571428571429, 1.0, 0.9795081967213114, 1.0, 0.0,
    1.0, 0.2, 0.99581589958159, 1.0, 0.0, 0.875, 1.0, 1.0, 0.0,
    0.20757238307349757, 0.0, 0.3251919050942078, 0.6590909090909107,
    0.04010349288486408, 0.15476190476190513, 0.9705882352941178,
    0.0588235294117644, 0.0, 0.03669724770642213, 0.9117647058823529,
    0.8285714285714283, 1.0, 0.053435114503816515, 1.0, 0.00943396226415097, 1.0,
    0.9393939393939393, 0.0, 0.0909090909090909, 0.9661016949152542, 1.0,
    0.0350194552529181, 0.0, 1.0, 0.96875, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.019762845849802264, 1.0, 0.0, 1.0, 0.1388888888888889,
    0.010638297872340377, 0.35714285714285715, 0.0, 0.020491803278688606, 0.0,
    1.0, 0.0, 0.7999999999999999, 0.004184100418410059, 0.0, 1.0,
    0.12499999999999999, 0.0, 0.0, 1.0, 0.2097995545657025, 0.0,
    0.32868108862526163, 0.3409090909090893, 0.31824062095730715,
    0.8452380952380949, 0.029411764705882297, 0.0, 1.0, 0.9633027522935779,
    0.08823529411764705, 0.17142857142857162, 0.0, 0.0, 0.0, 0.990566037735849,
    0.0, 0.06060606060606061, 1.0, 0.9090909090909091, 0.03389830508474581, 0.0,
    0.0, 1.0, 0.0, 0.03125, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 10, 0, 4, 3, 3, 5, 3, 4, 0, 8, 3, 8, 0, 9, 0, 9,
    0, 10, 0, 5, 7, 0, 6, 0, 0, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 5, 7, 9, 0, 9, 0,
    0, 0, 2, 9, 0, 0, 4, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 0, 0, 24, 25, 0, 0, 26,
    27, 0, 0, 28, 29, 30, 31, 0, 0, 32, 33, 0, 0, 0, 0, 34, 35, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 36, 37, 0, 0, 0, 0, 0, 0, 38, 39, 40, 41, 42, 43, 0, 0, 44, 45,
    0, 0, 0, 0, 0, 0, 46, 47, 48, 49, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3616926503340757;
  obj_Prior[1] = 0.22093541202672606;
  obj_Prior[2] = 0.20757238307349665;
  obj_Prior[3] = 0.20979955456570157;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassific_gkd2u4zdvpwala(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172])
{
  int32_T i;
  static const real_T tmp[43] = { 0.07931390259990749, 0.0, 0.15822484036203865,
    0.10394259910985063, 0.06536073956848822, 0.0015682116281618172,
    1.1655532734530938, 0.2751489368047294, 0.0, 0.0, 0.0, 0.1164974562301071,
    0.001915335805846115, 1.1796039121756485, 0.0, 0.0017277859351472252, 0.0,
    0.0, 0.0, 0.0, 1.2818568263473056, 0.0, 4.303239439139347,
    0.003951829861634894, 0.00834590680338994, 0.007906083192087191, 0.0,
    0.0018579490652423443, 0.0, 0.18126917602502302, 0.0012065497322042704, 0.0,
    0.0, 0.0, 0.0, 0.006735839284163449, 0.0, 0.0012046580124661782, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[43] = { false, true, false, false, false, false,
    false, false, true, true, true, false, false, false, true, false, true, true,
    true, true, false, true, false, false, false, false, true, false, true,
    false, false, true, true, true, true, false, true, false, true, true, true,
    true, true };

  static const real_T tmp_1[172] = { 0.37772828507794753, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2093541202672618, 0.0,
    0.3364352183249822, 0.04287901990811635, 0.5940860215053778, 0.0,
    0.07142857142857138, 0.8683693516699413, 0.0, 0.0, 0.0, 0.0,
    0.8235294117647058, 0.9002036659877802, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.9546436285097195, 0.0, 0.0, 0.68, 0.9703196347031965, 0.0, 0.0,
    0.3333333333333333, 1.0, 0.56, 0.9951573849878935, 0.0, 0.0, 1.0, 0.0, 0.875,
    0.0, 0.9801980198019802, 1.0, 0.0, 1.0, 1.0, 0.0, 0.20801781737193883, 0.0,
    0.3342877594846099, 0.6125574272588067, 0.0900537634408602,
    0.16858237547892763, 0.9081632653061225, 0.13163064833005864, 0.0, 0.0, 1.0,
    0.9776536312849163, 0.17647058823529413, 0.09979633401221966, 1.0,
    0.8297872340425533, 1.0, 0.0, 1.0, 1.0, 0.04535637149028059, 0.0,
    0.951219512195122, 0.32, 0.029680365296803544, 0.5, 1.0, 0.6666666666666666,
    0.0, 0.44, 0.004842615012106522, 1.0, 0.0, 0.0, 1.0, 0.125, 1.0,
    0.019801980198019754, 0.0, 1.0, 0.0, 0.0, 1.0, 0.2048997772828519, 0.0,
    0.329277022190408, 0.34456355283307694, 0.31586021505376194,
    0.8314176245210725, 0.020408163265306107, 0.0, 1.0, 1.0, 0.0,
    0.022346368715083793, 0.0, 0.0, 0.0, 0.17021276595744678, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.04878048780487804, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[43] = { 2, 0, 2, 2, 9, 9, 4, 6, 0, 0, 0, 2, 8, 4, 0, 8,
    0, 0, 0, 0, 4, 0, 7, 8, 9, 10, 0, 8, 0, 2, 8, 0, 0, 0, 0, 9, 0, 8, 0, 0, 0,
    0, 0 };

  static const int8_T d[86] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0,
    0, 0, 24, 25, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 0, 0, 34, 35, 0, 0, 36,
    37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 43U * sizeof(real_T));
  for (i = 0; i < 43; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 172U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 43; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 86; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 43; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37772828507795103;
  obj_Prior[1] = 0.2093541202672606;
  obj_Prior[2] = 0.20801781737193767;
  obj_Prior[3] = 0.2048997772828508;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassifi_gkd2u4zdvpwalat(real_T obj_CutPredictorIndex[57],
  real_T obj_Children[114], real_T obj_CutPoint[57], boolean_T obj_NanCutPoints
  [57], boolean_T obj_InfCutPoints[57], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[228])
{
  int32_T i;
  static const real_T tmp[57] = { 0.0005511413578816758, 0.0,
    0.006957788860168146, 0.10447134297475781, 2.443633483033932,
    0.004736559380115803, 14.556172470233864, 1.1813906986027942, 0.0,
    0.003466867047155689, 0.0018266808889749893, 0.4084752295409182,
    0.004023957563388844, 13.40056784195275, 0.31592690184863964, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0028456896168600307, 0.0, 0.0, 0.0, 0.0, 1.2860801397205588,
    0.003804416333348928, 0.0, 0.10711747649432155, 0.02750292461464604,
    0.00834590680338994, 0.0, 0.0, 0.007661484687974283, 0.0,
    0.004244053991626123, 0.0, 0.02010725853210691, 0.28547001187208587, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.17919317708564675, 0.0, 0.0032783088203331753,
    0.0, 0.0011706033221337802, 0.0, 0.0, 0.00458732510564808, 0.0,
    8.668477606625833, 0.0, 0.0 };

  static const boolean_T tmp_0[57] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, false, true, true,
    true, true, true, false, true, true, true, true, false, false, true, false,
    false, false, true, true, false, true, false, true, false, false, true, true,
    true, true, true, true, false, true, false, true, false, true, true, false,
    true, false, true, true };

  static const real_T tmp_1[228] = { 0.36570155902004137, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2106904231625846, 0.0,
    0.3321629213483146, 0.01860465116279068, 0.5917843388960223, 0.0,
    0.030690537084398936, 0.8747628083491464, 0.0, 0.0, 0.0, 0.0,
    0.6666666666666666, 0.03333333333333333, 0.9255533199195175, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.9622641509433965, 0.05, 0.0, 0.0,
    0.7741935483870968, 0.9753363228699552, 1.0, 0.0, 0.0, 0.0,
    0.5882352941176471, 1.0, 0.825, 0.9901477832512315, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.9925925925925926, 0.0, 0.9666666666666668, 1.0, 0.9886363636363636,
    0.0, 1.0, 0.9444444444444444, 1.0, 0.5, 0.0, 1.0, 0.2111358574610256, 0.0,
    0.3328651685393258, 0.632558139534885, 0.08472400513478817,
    0.15354330708661448, 0.9437340153452687, 0.12523719165085354, 0.0,
    0.8333333333333334, 0.04128440366972485, 0.9731903485254692,
    0.3333333333333333, 0.9666666666666667, 0.07444668008048257, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.981081081081081, 0.0, 1.0, 1.0, 0.0, 0.0377358490566036, 0.95,
    0.0, 0.9945205479452055, 0.22580645161290322, 0.02466367713004474, 0.0, 1.0,
    0.7142857142857143, 1.0, 0.4117647058823529, 0.0, 0.175,
    0.009852216748768444, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.007407407407407386,
    1.0, 0.033333333333333263, 0.0, 0.011363636363636338, 1.0, 0.0,
    0.05555555555555555, 0.0, 0.5, 1.0, 0.0, 0.21247216035634856, 0.0,
    0.33497191011235955, 0.3488372093023243, 0.3234916559691895,
    0.8464566929133855, 0.02557544757033245, 0.0, 1.0, 0.16666666666666666,
    0.9587155963302753, 0.0268096514745308, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0189189189189189, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0054794520547945145, 0.0, 0.0, 0.0, 0.0, 0.2857142857142857, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[57] = { 10, 0, 9, 3, 4, 10, 5, 4, 0, 1, 9, 4, 1, 5, 6, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 1, 0, 2, 9, 9, 0, 0, 10, 0, 1, 0, 10, 6, 0, 0,
    0, 0, 0, 0, 3, 0, 8, 0, 8, 0, 0, 1, 0, 7, 0, 0 };

  static const int8_T d[114] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 34, 35,
    36, 37, 38, 39, 0, 0, 0, 0, 40, 41, 0, 0, 42, 43, 0, 0, 44, 45, 46, 47, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 50, 51, 0, 0, 52, 53, 0, 0, 0, 0,
    54, 55, 0, 0, 56, 57, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 57U * sizeof(real_T));
  for (i = 0; i < 57; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 228U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 57; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 114; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 57; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3657015590200446;
  obj_Prior[1] = 0.21069042316258355;
  obj_Prior[2] = 0.21113585746102453;
  obj_Prior[3] = 0.21247216035634747;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassifi_gpst0p4p3isq4md(const real_T obj_CutPredictorIndex
  [57], const real_T obj_Children[114], const real_T obj_CutPoint[57], const
  boolean_T obj_NanCutPoints[57], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[228], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 57] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 114]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 171];
    scores[i] = obj_ClassProbability[57 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void predictOneWithC_o22p4vsubwbfsdz(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[57], const real_T weak_learner_Children[114],
  const real_T weak_learner_CutPoint[57], const boolean_T
  weak_learner_NanCutPoints[57], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[228], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassifi_gpst0p4p3isq4md(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_k(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196])
{
  int32_T i;
  static const real_T tmp[49] = { 0.2839087867342239, 0.08024481144127106,
    1.1813906986027942, 0.0, 0.0, 0.42028992015968064, 0.1344733869952961,
    0.0017979479234467924, 0.0018418245169142988, 0.2751489368047294, 0.0,
    0.08506039715532734, 0.07873144405371577, 0.0020468580836787496,
    0.0028456896168600307, 0.006712646530540386, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.21030925078571877, 14.589722467270716, 0.24114389919394402, 0.0,
    12.91296009154854, 0.0, 18.855319764609266, 1.8312124351297405,
    0.18737221082906008, 0.0, 0.0, 0.0, 0.0, 0.2252609441748376,
    0.22986956958672042, 0.0, 0.0, 7.10554375697767, 0.0, 0.0, 0.0, 0.0,
    11.536025305766277, 0.0, 0.0 };

  static const boolean_T tmp_0[49] = { false, false, false, true, true, false,
    false, false, false, false, true, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, false, true, false,
    true, false, false, false, true, true, true, true, false, false, true, true,
    false, true, true, true, true, false, true, true };

  static const real_T tmp_1[196] = { 0.3772828507795067, 0.9976133651551312,
    0.00781805259417196, 1.0, 0.0, 0.015647226173541945, 0.0,
    0.04263565891472882, 0.0, 0.0, 0.0, 0.0, 0.4230769230769231, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.19198218262806316, 0.0, 0.30632551528073876, 0.0, 0.0,
    0.0014224751066856313, 0.6107954545454561, 0.0, 0.0022471910112359474,
    0.9090909090909094, 0.0, 0.0, 0.0, 0.0, 0.0023148148148148064,
    0.9555555555555557, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0023201856148491796, 0.43750000000000006, 0.9746543778801844, 0.0,
    0.12499999999999999, 0.0, 0.875, 0.9790209790209791, 0.5999999999999999, 0.0,
    1.0, 1.0, 0.0, 0.9852216748768473, 0.8695652173913043, 1.0, 0.0,
    0.9708737864077669, 1.0, 1.0, 0.0, 0.0, 0.99009900990099, 0.0, 1.0,
    0.22048997772828646, 0.002386634844868757, 0.35039090262970884, 0.0, 1.0,
    0.6401137980085367, 0.06107954545454536, 0.06976744186046534,
    0.9707865168539327, 0.09090909090909058, 0.0, 0.012931034482758669,
    0.576923076923077, 0.15384615384615385, 0.9953703703703703,
    0.044444444444444293, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.9976798143851507, 0.5625, 0.02534562211981559, 1.0, 0.875, 1.0, 0.125,
    0.020979020979020917, 0.4, 1.0, 0.0, 0.0, 1.0, 0.014778325123152677,
    0.13043478260869565, 0.0, 1.0, 0.029126213592233087, 0.0, 0.0, 1.0, 1.0,
    0.009900990099009927, 1.0, 0.0, 0.21024498886414372, 0.0, 0.3354655294953803,
    0.0, 0.0, 0.34281650071123576, 0.32812499999999845, 0.8875968992248058,
    0.026966292134831368, 0.0, 1.0, 0.9870689655172413, 0.0, 0.8461538461538461,
    0.0023148148148148064, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[49] = { 4, 3, 4, 0, 0, 4, 10, 9, 9, 6, 0, 3, 3, 8, 1, 9,
    0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 6, 0, 5, 0, 5, 4, 3, 0, 0, 0, 0, 3, 2, 0, 0, 7,
    0, 0, 0, 0, 5, 0, 0 };

  static const int8_T d[98] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 0, 0, 34, 35, 0,
    0, 36, 37, 38, 39, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 0, 0, 0,
    0, 46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 49U * sizeof(real_T));
  for (i = 0; i < 49; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 196U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 49; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 98; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 49; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37728285077951;
  obj_Prior[1] = 0.19198218262806235;
  obj_Prior[2] = 0.22048997772828507;
  obj_Prior[3] = 0.21024498886414253;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_o(real_T obj_CutPredictorIndex[47],
  real_T obj_Children[94], real_T obj_CutPoint[47], boolean_T obj_NanCutPoints
  [47], boolean_T obj_InfCutPoints[47], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[188])
{
  int32_T i;
  static const real_T tmp[47] = { 0.0005509168527924317, 0.0,
    0.007092095439852447, 0.10405640349033901, 0.1344733869952961,
    0.0017260388163948303, 0.0033005739692490007, 0.2751489368047294, 0.0,
    0.08501454635706668, 0.0, 4.23742726172109, 1.2275222754491018,
    1.1813906986027942, 0.0, 0.0015815598464578367, 0.08801056043658229, 0.0,
    0.13588407884417292, 0.11067363480798148, 0.004019159064683133,
    13.375065226533689, 0.04581937529386296, 0.0, 0.08861733661016313, 0.0, 0.0,
    0.0, 0.0, 0.0011639294617193485, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.005253766119131129, 6.18201350986305, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.030599957803211054, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[47] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, false, true, false, false,
    true, false, false, false, false, false, true, false, true, true, true, true,
    false, true, true, true, true, true, false, false, true, true, true, true,
    true, false, true, true, true, true };

  static const real_T tmp_1[188] = { 0.37371937639197883, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.2026726057906469, 0.0, 0.3236130867709814, 0.015037593984962391,
    0.6005398110661285, 0.0, 0.0261096605744125, 0.8917835671342689, 0.0, 0.0,
    0.0, 0.4, 0.010869565217391294, 0.9408033826638481, 0.0, 0.0, 0.0, 0.0,
    0.6666666666666666, 0.0, 0.36363636363636365, 0.09090909090909091,
    0.9822616407982262, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    1.0, 0.9949874686716793, 0.8846153846153847, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.7777777777777778, 1.0, 0.0, 0.0, 1.0, 0.20846325167037974, 0.0,
    0.3328591749644381, 0.6225563909774451, 0.07287449392712547,
    0.16666666666666718, 0.95822454308094, 0.10821643286573115, 0.0,
    0.016736401673640218, 1.0, 0.4, 0.9809782608695652, 0.059196617336151974,
    1.0, 0.004347826086956534, 0.3333333333333333, 1.0, 0.0, 0.9915966386554622,
    0.6363636363636364, 0.9090909090909091, 0.017738359201773756, 0.0,
    0.3333333333333333, 1.0, 0.0, 0.0, 0.0, 0.8695652173913043, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.005012531328320789, 0.1153846153846153, 1.0, 0.0, 0.0, 1.0, 0.0,
    0.2222222222222222, 0.0, 1.0, 1.0, 0.0, 0.21514476614699457, 0.0,
    0.34352773826458055, 0.36240601503759245, 0.32658569500674606,
    0.8333333333333327, 0.0156657963446475, 0.0, 1.0, 0.9832635983263599, 0.0,
    0.2, 0.00815217391304347, 0.0, 0.0, 0.9956521739130435, 0.6666666666666666,
    0.0, 0.3333333333333333, 0.00840336134453781, 0.0, 0.0, 0.0, 1.0,
    0.6666666666666666, 0.0, 1.0, 1.0, 0.0, 0.13043478260869565, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[47] = { 10, 0, 9, 2, 10, 9, 1, 6, 0, 6, 0, 7, 4, 4, 0, 9,
    6, 0, 2, 2, 1, 5, 10, 0, 2, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 8, 5, 0, 0, 0, 0,
    0, 10, 0, 0, 0, 0 };

  static const int8_T d[94] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 0, 0,
    28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0, 0, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0,
    40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 46, 47, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 47U * sizeof(real_T));
  for (i = 0; i < 47; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 188U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 47; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 94; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 47; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3737193763919822;
  obj_Prior[1] = 0.20267260579064592;
  obj_Prior[2] = 0.20846325167037866;
  obj_Prior[3] = 0.21514476614699335;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_e(real_T obj_CutPredictorIndex[37],
  real_T obj_Children[74], real_T obj_CutPoint[37], boolean_T obj_NanCutPoints
  [37], boolean_T obj_InfCutPoints[37], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[148])
{
  int32_T i;
  static const real_T tmp[37] = { 0.000534042222881256, 0.0, 1.1813906986027942,
    0.0035579681554859053, 2.443633483033932, 0.12951312554138106,
    0.0013562057009519949, 0.011820951850340286, 0.0, 0.0, 0.0, 0.0,
    7.550609438294948, 0.0, 1.9605920159680639, 0.0, 0.0014943915863822135,
    0.012006370225432918, 0.19763884846669677, 0.0, 0.0, 0.021431415919321496,
    0.00577353754555797, 0.0, 0.0, 12.150858173714619, 0.0, 0.012672539178592705,
    0.0, 0.0, 0.0055289058158902865, 6.554392674375415, 0.0, 0.0, 0.0, 0.0, 0.0
  };

  static const boolean_T tmp_0[37] = { false, true, false, false, false, false,
    false, false, true, true, true, true, false, true, false, true, false, false,
    false, true, true, false, false, true, true, false, true, false, true, true,
    false, false, true, true, true, true, true };

  static const real_T tmp_1[148] = { 0.372383073496656, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.1995545657015599, 0.0, 0.31795599716110695, 0.0030349013657056164,
    0.5946666666666686, 0.0, 0.004484304932735422, 0.8937875751503012, 0.0, 0.0,
    0.0, 0.0, 0.005181347150259061, 0.0, 0.9065040650406508, 0.0,
    0.15384615384615385, 0.9248434237995827, 0.23076923076923075, 1.0, 0.0,
    0.7961783439490446, 0.9875776397515528, 1.0, 0.0, 0.9689922480620156, 0.0,
    0.9968652037617555, 0.0, 0.0, 0.9920634920634921, 0.9444444444444445, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.20089086859688288, 0.0, 0.32008516678495363,
    0.6039453717754188, 0.07066666666666652, 0.06572769953051659,
    0.8609865470852022, 0.10621242484969891, 0.0, 0.0, 1.0, 0.0,
    0.994818652849741, 1.0, 0.09349593495934919, 1.0, 0.8461538461538461,
    0.07515657620041725, 0.7692307692307692, 0.0, 1.0, 0.2038216560509553,
    0.012422360248447234, 0.0, 1.0, 0.031007751937984475, 1.0,
    0.0031347962382445214, 1.0, 1.0, 0.00793650793650793, 0.05555555555555556,
    0.0, 1.0, 0.0, 1.0, 0.0, 0.22717149220490124, 0.0, 0.36195883605393936,
    0.39301972685887543, 0.3346666666666649, 0.9342723004694834,
    0.13452914798206245, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[37] = { 10, 0, 4, 1, 4, 2, 9, 10, 0, 0, 0, 0, 7, 0, 4, 0,
    8, 9, 3, 0, 0, 10, 8, 0, 0, 5, 0, 9, 0, 0, 9, 7, 0, 0, 0, 0, 0 };

  static const int8_T d[74] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 0, 0, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24,
    25, 0, 0, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 30, 31, 0, 0, 32, 33, 0, 0, 0, 0,
    34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 37U * sizeof(real_T));
  for (i = 0; i < 37; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 148U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 37; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 74; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 37; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3723830734966592;
  obj_Prior[1] = 0.19955456570155902;
  obj_Prior[2] = 0.20089086859688196;
  obj_Prior[3] = 0.22717149220489977;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_ej(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[180])
{
  int32_T i;
  static const real_T tmp[45] = { 0.07944453635367484, 0.3371483344081069,
    1.1819592215568862, 0.0, 0.0, 0.4207772255489022, 2.443633483033932,
    0.004314710136244343, 0.11236467633595357, 0.21296849747346336, 0.0, 0.0,
    0.0, 0.0018753334578075656, 0.2007717735617281, 1.2862425748502995,
    0.001944172630552694, 0.0036639274575848307, 0.0, 0.0020368352409443256,
    0.005765574651478292, 0.004477871746740894, 6.089478218932559, 0.0, 0.0, 0.0,
    0.007981961077844305, 0.0, 0.0, 0.0, 0.0, 0.0, 0.26219563130716717, 0.0,
    11.552152081265225, 0.0, 0.0, 0.0017292543903449748, 0.0, 0.0,
    0.0049335243671550216, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[45] = { false, false, false, true, true, false,
    false, false, false, false, true, true, true, false, false, false, false,
    false, true, false, false, false, false, true, true, true, false, true, true,
    true, true, true, false, true, false, true, true, false, true, true, false,
    true, true, true, true };

  static const real_T tmp_1[180] = { 0.3665924276169234, 0.9987864077669903, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.2258351893095782, 0.0, 0.35679099225897287, 0.0, 0.0, 0.0031201248049922,
    0.6474358974358996, 0.0, 0.004901960784313718, 0.921532846715329, 0.0, 0.0,
    0.0, 0.0, 0.005714285714285717, 0.9744094488188978, 0.25, 0.0, 0.0, 0.0,
    0.3333333333333333, 0.8250000000000001, 0.9871794871794872, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.6666666666666667, 1.0, 0.974025974025974,
    0.0, 0.0, 0.29999999999999993, 1.0, 0.0, 0.9911894273127753, 1.0, 0.0, 0.0,
    1.0, 0.19955456570155986, 0.0012135922330097193, 0.3145672061928217, 0.0,
    1.0, 0.6302652106084259, 0.05512820512820495, 0.07296137339055817,
    0.9485294117647061, 0.07846715328467106, 0.0, 1.0, 0.0, 0.6896551724137929,
    0.9914285714285714, 0.025590551181102223, 0.75, 0.18181818181818182, 1.0,
    0.997093023255814, 0.6666666666666667, 0.17500000000000002,
    0.012820512820512763, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 1.0, 0.0, 0.0,
    0.33333333333333337, 0.0, 0.025974025974026066, 1.0, 0.0, 0.7000000000000001,
    0.0, 1.0, 0.008810572687224702, 0.0, 1.0, 1.0, 0.0, 0.20801781737193864, 0.0,
    0.3286418015482054, 0.0, 0.0, 0.36661466458658204, 0.29743589743589555,
    0.9270386266094419, 0.046568627450980324, 0.0, 1.0, 0.0, 1.0,
    0.31034482758620696, 0.0028571428571428584, 0.0, 0.0, 0.8181818181818181,
    0.0, 0.0029069767441860486, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.5, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[45] = { 2, 4, 4, 0, 0, 4, 4, 10, 3, 6, 0, 0, 0, 9, 6, 4,
    8, 1, 0, 9, 1, 1, 7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 5, 0, 0, 8, 0, 0, 9, 0,
    0, 0, 0 };

  static const int8_T d[90] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
    0, 0, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 36, 37, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 38, 39, 0, 0, 40, 41, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 44,
    45, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 45U * sizeof(real_T));
  for (i = 0; i < 45; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 180U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 45; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 90; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 45; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3665924276169265;
  obj_Prior[1] = 0.22583518930957683;
  obj_Prior[2] = 0.19955456570155902;
  obj_Prior[3] = 0.20801781737193764;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_j(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.0005340809045944201, 0.0, 1.184152095808383,
    0.4199855489021956, 0.06578536197768634, 0.004314710136244343,
    0.0029514901642028434, 0.2671735379729756, 0.0, 0.054427214810474536,
    3.4702456315948695, 0.0, 0.11067363480798148, 0.2270031447445927, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.008103549483065116, 0.0, 0.006799255947665533,
    0.0037057893392901716, 0.0, 0.0, 0.0040791204699975065, 1.2860801397205588,
    0.0, 0.0, 0.0, 0.0, 0.04316897009944336, 0.009780724777724657,
    1.276009161676647, 0.27184749952751397, 0.1761721378343629,
    -0.045903319551187136, 0.0, 0.0017337515632767262, 0.0, 0.0, 0.0, 0.0,
    0.23664564530278542, 0.0, 0.0, 0.0, 0.0, -0.04691600538238663, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, false, false,
    false, false, true, false, false, true, false, false, true, true, true, true,
    true, false, true, false, false, true, true, false, false, true, true, true,
    true, false, false, false, false, false, false, true, false, true, true,
    true, true, false, true, true, true, true, false, true, true };

  static const real_T tmp_1[204] = { 0.3804008908685935, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.200445434298442, 0.0, 0.3235082674335009, 0.0, 0.629370629370631, 0.0, 0.0,
    0.9036144578313258, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9635974304068523, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.9694323144104804, 0.6666666666666667, 0.0, 0.0,
    0.6153846153846154, 0.9797752808988764, 1.0, 0.0, 1.0, 0.0,
    0.8928571428571428, 0.985611510791367, 0.9523809523809523,
    0.7142857142857142, 0.9152542372881356, 0.9972067039106145, 1.0, 0.5, 0.0,
    1.0, 1.0, 0.0, 0.9866666666666666, 1.0, 1.0, 0.0, 1.0, 0.9, 1.0, 0.0,
    0.21469933184855367, 0.0, 0.34651329978432804, 0.6420118343195284,
    0.06713286713286697, 0.084677419354839, 0.9649532710280375,
    0.09638554216867426, 0.0, 0.9090909090909091, 0.004424778761061963, 0.0,
    0.9880382775119618, 0.03640256959314761, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.9019607843137255, 1.0, 0.030567685589519535, 0.33333333333333337, 1.0, 0.0,
    0.3846153846153846, 0.02022471910112352, 0.0, 1.0, 0.0, 1.0,
    0.10714285714285714, 0.014388489208633056, 0.04761904761904762,
    0.2857142857142857, 0.08474576271186451, 0.0027932960893854745, 0.0,
    0.5000000000000001, 1.0, 0.0, 0.0, 1.0, 0.013333333333333355, 0.0, 0.0, 1.0,
    0.0, 0.1, 0.0, 1.0, 0.2044543429844109, 0.0, 0.32997843278217104,
    0.3579881656804716, 0.30349650349650203, 0.9153225806451609,
    0.035046728971962524, 0.0, 1.0, 0.0909090909090909, 0.995575221238938, 1.0,
    0.011961722488038246, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.09803921568627459, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 10, 0, 4, 4, 9, 10, 1, 6, 0, 6, 5, 0, 2, 6, 0, 0,
    0, 0, 0, 1, 0, 9, 1, 0, 0, 1, 4, 0, 0, 0, 0, 10, 9, 4, 3, 2, 6, 0, 8, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 6, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 24, 25, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0,
    0, 0, 0, 0, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 0, 0, 46, 47, 0,
    0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3804008908685969;
  obj_Prior[1] = 0.20044543429844097;
  obj_Prior[2] = 0.21469933184855233;
  obj_Prior[3] = 0.2044543429844098;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_ea(real_T obj_CutPredictorIndex[41],
  real_T obj_Children[82], real_T obj_CutPoint[41], boolean_T obj_NanCutPoints
  [41], boolean_T obj_InfCutPoints[41], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[164])
{
  int32_T i;
  static const real_T tmp[41] = { 0.07944453635367484, 0.0, 0.00674422734936207,
    0.0017897211693342521, 2.4422121756487027, 5.911485242641046,
    7.909978021831424, 1.184152095808383, 0.0, 0.08636850400931739, 0.0,
    0.0020201501308521105, 0.004019079750654939, 0.0, 0.2707683160069425, 0.0,
    0.0, 0.0015529481245520303, 0.07283856558917187, 0.0, 0.0, 14.07614985791917,
    0.0, 0.0, 0.0, 0.0, 0.5055181237524949, 0.0, 0.028036269727789945,
    0.4943100998003992, 0.0, 0.2197034217546889, 0.0, 0.0, 0.0,
    0.31971074156187557, 0.0, 0.0, 1.7282285628742515, 0.0, 0.0 };

  static const boolean_T tmp_0[41] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, true, false, true, true,
    false, false, true, true, false, true, true, true, true, false, true, false,
    false, true, false, true, true, true, false, true, true, false, true, true };

  static const real_T tmp_1[164] = { 0.3616926503340727, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.19510022271714988, 0.0, 0.30565247732030665,
    0.010159651669085626, 0.579301075268819, 0.0, 0.016241299303944266,
    0.8654618473895589, 0.0, 0.0, 0.0, 0.0, 0.3888888888888889, 0.0,
    0.9248927038626612, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.8541666666666663, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.9624413145539905, 0.0, 0.0, 0.985576923076923,
    0.0, 0.0, 0.0, 0.9903381642512077, 0.0, 1.0, 0.33333333333333337, 0.0, 1.0,
    0.22093541202672723, 0.0, 0.3461270062805305, 0.622641509433964,
    0.09005376344086002, 0.0348837209302327, 0.974477958236659,
    0.13453815261044116, 0.0, 0.011904761904761956, 1.0, 0.9903147699757869,
    0.6111111111111112, 1.0, 0.07510729613733882, 1.0, 0.0, 0.625,
    0.9975308641975308, 0.0, 1.0, 0.1458333333333337, 0.0, 0.0, 1.0, 1.0,
    0.9750000000000001, 1.0, 0.037558685446009495, 0.8, 1.0,
    0.014423076923076964, 1.0, 1.0, 0.0, 0.009661835748792298, 1.0, 0.0,
    0.6666666666666667, 1.0, 0.0, 0.2222717149220502, 0.0, 0.3482205163991628,
    0.36719883889695026, 0.330645161290321, 0.9651162790697674,
    0.009280742459396724, 0.0, 1.0, 0.988095238095238, 0.0, 0.009685230024213051,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.37500000000000006, 0.00246913580246913, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.025000000000000012, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[41] = { 2, 0, 9, 9, 4, 7, 7, 4, 0, 3, 0, 9, 1, 0, 2, 0,
    0, 8, 6, 0, 0, 5, 0, 0, 0, 0, 4, 0, 10, 4, 0, 2, 0, 0, 0, 6, 0, 0, 4, 0, 0 };

  static const int8_T d[82] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 22, 23, 0, 0, 0, 0, 24, 25, 26,
    27, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 32, 33, 34, 35,
    0, 0, 36, 37, 0, 0, 0, 0, 0, 0, 38, 39, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 41U * sizeof(real_T));
  for (i = 0; i < 41; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 164U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 41; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 82; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 41; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3616926503340757;
  obj_Prior[1] = 0.19510022271714922;
  obj_Prior[2] = 0.22093541202672606;
  obj_Prior[3] = 0.222271714922049;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_a(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.27984004974666055, 0.0, 0.13542646950941317,
    1.1813906986027942, 0.0, 0.0017897211693342521, 1.2860801397205588,
    0.004717683298627148, 0.07937996061714182, 0.004019159064683133,
    0.006348168705434622, 3.2306610945854093, 0.0, 0.0, 0.06594375972437447, 0.0,
    0.030088275815336046, 0.0, 0.005253766119131129, 0.0, 0.0, 0.0,
    0.0016539982123349919, 0.001853579979559078, 0.0, 6.654445503725885,
    6.547981890451615, 0.001417121056218825, 0.0, 0.0, 0.0, 0.0,
    0.0035232719582527013, 0.0, 0.0, 0.0, 0.0, 0.02684018036423489,
    0.014779949976376007, 0.21013160865670186, 0.0, 0.0, 0.0, 0.3495163871132262,
    0.21858149118547882, 7.080201762704775, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, true, false,
    false, false, false, false, false, false, true, true, false, true, false,
    true, false, true, true, true, false, false, true, false, false, false, true,
    true, true, true, false, true, true, true, true, false, false, false, true,
    true, true, false, false, false, true, true, true, true, true };

  static const real_T tmp_1[204] = { 0.38396436525612127, 1.0,
    0.0043196544276457695, 0.005244755244755233, 0.0, 0.00964630225080387, 0.0,
    0.0, 0.01599999999999999, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.2097995545657028, 0.0, 0.3390928725701945, 0.4117132867132878,
    0.0, 0.0, 0.9022988505747132, 0.0, 0.0, 0.5952380952380952,
    0.9291666666666669, 0.0, 0.0, 0.0, 0.0, 1.0, 0.32, 0.0, 0.9429175475687106,
    0.0, 0.0, 0.0, 0.0, 0.05555555555555556, 1.0, 0.9643652561247217,
    0.5416666666666666, 0.0, 0.0, 1.0, 0.0, 1.0, 0.9307359307359305, 1.0, 0.0,
    0.0, 0.0, 0.9675925925925924, 0.4, 0.9858490566037735, 0.0, 0.0, 1.0,
    0.9904761904761904, 0.5, 0.9952153110047848, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.18841870824053533, 0.0, 0.3045356371490277, 0.3697552447552451, 0.0,
    0.5980707395498405, 0.09770114942528683, 0.02024291497975717,
    0.9786666666666668, 0.40476190476190477, 0.07083333333333308,
    0.7142857142857142, 0.0, 0.0, 0.9945799457994581, 0.0, 0.68, 1.0,
    0.057082452431289434, 0.0, 1.0, 1.0, 0.9574468085106382, 0.9444444444444445,
    0.0, 0.03563474387527828, 0.4583333333333333, 0.7777777777777778, 1.0, 0.0,
    1.0, 0.0, 0.06926406926406947, 0.0, 1.0, 1.0, 0.0, 0.0324074074074075, 0.6,
    0.014150943396226457, 1.0, 1.0, 0.0, 0.009523809523809552, 0.5,
    0.0047846889952153256, 1.0, 1.0, 0.0, 1.0, 0.0, 0.2178173719376406, 0.0,
    0.3520518358531321, 0.21328671328671192, 1.0, 0.3922829581993557, 0.0,
    0.9797570850202428, 0.0053333333333333306, 0.0, 0.0, 0.2857142857142857, 1.0,
    0.0, 0.005420054200542003, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.042553191489361736, 0.0, 0.0, 0.0, 0.0, 0.22222222222222224, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 4, 0, 10, 4, 0, 9, 4, 10, 3, 1, 9, 5, 0, 0, 6, 0,
    9, 0, 8, 0, 0, 0, 8, 8, 0, 5, 7, 8, 0, 0, 0, 0, 8, 0, 0, 0, 0, 10, 9, 2, 0,
    0, 0, 6, 3, 7, 0, 0, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 24, 25, 0, 0,
    26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 32, 33, 34, 35, 36, 37, 0, 0,
    0, 0, 0, 0, 0, 0, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0,
    0, 0, 0, 0, 0, 46, 47, 48, 49, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3839643652561247;
  obj_Prior[1] = 0.20979955456570157;
  obj_Prior[2] = 0.18841870824053453;
  obj_Prior[3] = 0.2178173719376392;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_c(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.006946252308783872, 0.007207531825943473,
    0.08744458404387309, 0.0017897211693342521, 0.4419176254675409, 0.0,
    0.9054134131736526, 0.003910560452860944, 0.0061836300929036785,
    0.30232602109322, 0.0, 0.009824866569086939, 0.0745300771781949, 0.0,
    7.0926859331782754, 0.002675188353761226, 1.128030758483034,
    0.010358974149859777, 0.019649341960249804, 0.0, 0.0, 0.0, 0.0,
    0.0021408553342484047, 0.0, 0.0, 0.0, 0.0, 0.16269539492839452,
    0.0013995949610691497, 0.15549265600748963, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.1813906986027942, 0.0, 0.012672539178592705,
    0.21794077783277027, 0.0, 0.17056148417173478, 0.0, 0.17024824774870104, 0.0,
    0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, false, false, false, false, true,
    false, false, false, false, true, false, false, true, false, false, false,
    false, false, true, true, true, true, false, true, true, true, true, false,
    false, false, true, true, true, true, true, true, true, true, true, false,
    true, false, false, true, false, true, false, true, true, true };

  static const real_T tmp_1[204] = { 0.3795100222717115, 0.0, 0.7383015597920258,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.20489977728285186, 0.3098075160403295, 0.1057192374350095,
    0.021978021978021997, 0.5981651376146787, 0.0, 0.40397350993377507, 0.0,
    0.03380281690140848, 0.8624338624338623, 0.0, 0.0, 0.6815642458100563, 0.0,
    0.0, 0.0, 0.3, 0.8879781420765026, 0.08333333333333334, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.7058823529411765, 0.614583333333333,
    0.9851851851851852, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.9888475836431226, 0.0, 0.9925373134328358, 0.9565217391304347, 1.0,
    0.9777777777777779, 0.0, 0.9166666666666666, 1.0, 1.0, 0.0,
    0.2071269487750568, 0.3684692942254819, 0.05459272097053757,
    0.6410256410256414, 0.09541284403669727, 0.0, 0.20860927152317846,
    0.04712041884816762, 0.9605633802816902, 0.13756613756613761, 0.0,
    0.5121951219512195, 0.0, 1.0, 0.016216216216216245, 0.9936507936507937,
    0.7000000000000001, 0.11202185792349739, 0.9166666666666666, 0.0, 1.0, 0.0,
    0.0, 0.00546448087431695, 1.0, 0.0, 1.0, 1.0, 0.29411764705882354,
    0.38541666666666696, 0.014814814814814887, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 1.0, 0.011152416356877377, 1.0, 0.007462686567164215,
    0.04347826086956525, 0.0, 0.02222222222222224, 1.0, 0.08333333333333334, 0.0,
    0.0, 1.0, 0.20846325167037977, 0.3217231897341886, 0.10138648180242713,
    0.3369963369963367, 0.30642201834862404, 0.0, 0.3874172185430465,
    0.9528795811518325, 0.005633802816901414, 0.0, 1.0, 0.48780487804878053,
    0.3184357541899437, 0.0, 0.9837837837837837, 0.0063492063492063665, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.9945355191256832, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 1, 9, 3, 9, 3, 0, 4, 10, 9, 6, 0, 10, 9, 0, 5, 1,
    4, 9, 10, 0, 0, 0, 0, 8, 0, 0, 0, 0, 3, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
    0, 9, 2, 0, 2, 0, 2, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 36,
    37, 38, 39, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42,
    43, 0, 0, 44, 45, 46, 47, 0, 0, 48, 49, 0, 0, 50, 51, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37951002227171493;
  obj_Prior[1] = 0.20489977728285078;
  obj_Prior[2] = 0.2071269487750557;
  obj_Prior[3] = 0.20846325167037863;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_gt(real_T obj_CutPredictorIndex[35],
  real_T obj_Children[70], real_T obj_CutPoint[35], boolean_T obj_NanCutPoints
  [35], boolean_T obj_InfCutPoints[35], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[140])
{
  int32_T i;
  static const real_T tmp[35] = { 0.0005343054096836643, 0.0,
    0.006955827871244737, 0.42028992015968064, 0.1344733869952961,
    0.0019066569319939196, 0.0017897211693342521, 1.1813906986027942, 0.0,
    0.08349536401579707, 0.0, 0.0020346972973399346, 14.556172470233864, 0.0,
    0.2751489368047294, 0.0, 0.0, 0.0, 0.0, 0.0, 0.004701997170662565,
    6.437213643676216, 0.0023755823019810697, 0.0, 0.0, 0.0, 0.02684018036423489,
    0.0, 0.0, 7.065140010787314, 0.0, 0.0, 11.536025305766277, 0.0, 0.0 };

  static const boolean_T tmp_0[35] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, true, false, true, true, true,
    true, true, false, false, false, true, true, true, false, true, true, false,
    true, true, false, true, true };

  static const real_T tmp_1[140] = { 0.3478841870824026, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.21024498886414333, 0.0, 0.3224043715846993, 0.019886363636363598,
    0.6026315789473704, 0.0, 0.029411764705882238, 0.8962818003913899, 0.0, 0.0,
    0.0, 0.0, 0.03036876355748361, 0.0, 0.9482401656314702, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.7777777777777778, 0.9784482758620691, 0.21052631578947367, 0.0, 1.0,
    1.0, 0.9574468085106381, 1.0, 0.0, 0.9782608695652173, 0.0, 0.0,
    0.9911894273127753, 0.0, 1.0, 0.2298440979955468, 0.0, 0.3524590163934429,
    0.6576704545454563, 0.069736842105263, 0.061403508771930015,
    0.94327731092437, 0.10371819960861005, 0.0, 0.00465116279069769, 1.0,
    0.13333333333333333, 0.9696312364425164, 1.0, 0.05175983436852981, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.22222222222222224, 0.021551724137930942, 0.7894736842105263,
    1.0, 0.0, 0.0, 0.04255319148936185, 0.0, 1.0, 0.021739130434782684, 1.0, 1.0,
    0.008810572687224702, 1.0, 0.0, 0.2120267260579073, 0.0, 0.3251366120218578,
    0.32244318181818, 0.3276315789473666, 0.93859649122807, 0.02731092436974779,
    0.0, 1.0, 0.9953488372093023, 0.0, 0.8666666666666667, 0.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[35] = { 10, 0, 9, 4, 10, 9, 9, 4, 0, 3, 0, 8, 5, 0, 6, 0,
    0, 0, 0, 0, 9, 5, 8, 0, 0, 0, 10, 0, 0, 7, 0, 0, 5, 0, 0 };

  static const int8_T d[70] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 24, 25, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 32, 33,
    0, 0, 0, 0, 34, 35, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 35U * sizeof(real_T));
  for (i = 0; i < 35; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 140U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 35; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 70; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 35; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.34788418708240537;
  obj_Prior[1] = 0.21024498886414253;
  obj_Prior[2] = 0.22984409799554567;
  obj_Prior[3] = 0.21202672605790646;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_pre_a(const real_T obj_CutPredictorIndex
  [35], const real_T obj_Children[70], const real_T obj_CutPoint[35], const
  boolean_T obj_NanCutPoints[35], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[140], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 35] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 70]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 105];
    scores[i] = obj_ClassProbability[35 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaul_predictOneWithCache_e(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[35], const real_T weak_learner_Children[70],
  const real_T weak_learner_CutPoint[35], const boolean_T
  weak_learner_NanCutPoints[35], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[140], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pre_a(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_i(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172])
{
  int32_T i;
  static const real_T tmp[43] = { 0.07931390259990749, 0.0, 0.13542646950941317,
    0.1602739764816959, 0.0, 0.1021621565246987, 0.269913313995951,
    0.0018899846220002039, 15.557649244917314, 13.669951402654949, 0.0,
    0.0015815598464578367, 0.0012527265184175533, 0.0018753334578075656,
    0.14159948882661805, 0.0035717882886570624, 0.28973273207510536, 0.0, 0.0,
    0.0, 0.0, 0.6932725948103792, 0.12630084695592375, 0.0,
    0.0042562167950195426, 0.0, 0.0, 0.23959966368652602, 0.0, 0.0, 0.0,
    0.0032804494624033157, 0.0, 0.0, 0.0, 1.4810022954091817, 0.0, 0.0, 0.0,
    1.4771850698602795, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[43] = { false, true, false, false, true, false,
    false, false, false, false, true, false, false, false, false, false, false,
    true, true, true, true, false, false, true, false, true, true, false, true,
    true, true, false, true, true, true, false, true, true, true, false, true,
    true, true };

  static const real_T tmp_1[172] = { 0.3630289532293956, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21514476614699438, 0.0,
    0.33776223776223785, 0.40932203389830585, 0.0, 0.058558558558558536,
    0.8638132295719851, 0.0, 0.09397590361445778, 0.7482014388489207, 1.0, 0.0,
    0.0, 0.0, 0.8297872340425532, 0.016666666666666694, 0.9495412844036696, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9750000000000001, 1.0, 0.0,
    0.9904306220095693, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.9951923076923077,
    0.0, 0.0, 0.0, 0.9811320754716981, 1.0, 1.0, 0.0, 0.20890868596882053, 0.0,
    0.3279720279720279, 0.39745762711864463, 0.0, 0.5990990990991004,
    0.13618677042801489, 0.14741035856573742, 0.8722891566265061,
    0.25179856115107935, 0.0, 0.05777777777777795, 0.923076923076923,
    0.9619565217391304, 0.17021276595744686, 0.9833333333333334,
    0.05045871559633042, 0.0, 1.0, 0.0, 1.0, 0.07142857142857142,
    0.9971751412429378, 1.0, 0.02500000000000001, 0.0, 1.0, 0.00956937799043065,
    1.0, 0.0, 1.0, 0.9807692307692308, 1.0, 1.0, 0.0, 0.004807692307692322, 1.0,
    0.0, 1.0, 0.018867924528301907, 0.0, 0.0, 1.0, 0.21291759465478943, 0.0,
    0.3342657342657343, 0.19322033898304947, 1.0, 0.34234234234234107, 0.0,
    0.8525896414342625, 0.03373493975903614, 0.0, 0.0, 0.9422222222222221,
    0.07692307692307691, 0.03804347826086957, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.9285714285714286, 0.002824858757062147, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.019230769230769253, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const int8_T c[43] = { 2, 0, 10, 2, 0, 2, 2, 8, 5, 5, 0, 9, 9, 9, 3, 1,
    6, 0, 0, 0, 0, 4, 2, 0, 9, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0,
    0 };

  static const int8_T d[86] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0,
    0, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 34, 35, 0, 0, 0, 0, 36, 37, 0, 0,
    0, 0, 0, 0, 38, 39, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 43U * sizeof(real_T));
  for (i = 0; i < 43; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 172U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 43; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 86; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 43; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36302895322939865;
  obj_Prior[1] = 0.21514476614699332;
  obj_Prior[2] = 0.2089086859688196;
  obj_Prior[3] = 0.2129175946547884;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_h(real_T obj_CutPredictorIndex[41],
  real_T obj_Children[82], real_T obj_CutPoint[41], boolean_T obj_NanCutPoints
  [41], boolean_T obj_InfCutPoints[41], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[164])
{
  int32_T i;
  static const real_T tmp[41] = { 3.7092076727078185, 0.0005343054096836643,
    0.4416781642468419, 0.0, 0.0017503001345564768, 1.1813906986027942, 0.0,
    0.003290071493705783, 0.0, 0.0032804494624033157, 0.28547001187208587, 0.0,
    0.08423293344813151, 0.0, 0.001148659482976413, 0.26201415911732834,
    0.0019295091830043504, 0.0, 0.0, 0.0, 0.0011554690665331793,
    11.6487216573428, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.004062872986994214,
    0.00418064242608533, 0.0, 0.0, 1.3101205389221557, 0.0, 0.004182545962761975,
    0.0, 0.005121227486433384, 0.02684018036423489, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[41] = { false, false, false, true, false, false,
    true, false, true, false, false, true, false, true, false, false, false,
    true, true, true, false, false, true, true, true, true, true, true, false,
    false, true, true, false, true, false, true, false, false, true, true, true
  };

  static const real_T tmp_1[164] = { 0.3648106904231595, 0.6383476227591572, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.22316258351893223, 0.0,
    0.5207900207900231, 0.0, 0.0, 0.6853625170998651, 0.0, 0.0, 0.0,
    0.01604278074866312, 0.9154411764705888, 0.0, 0.0, 0.0, 0.016949152542372902,
    0.964980544747082, 0.06666666666666667, 0.0, 0.0, 0.0, 0.01704545454545457,
    0.9347826086956519, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.9847328244274809,
    0.9885057471264368, 0.0, 1.0, 0.9605263157894737, 0.0, 0.9733333333333334,
    0.0, 0.9864864864864864, 0.9, 1.0, 1.0, 0.0, 0.2044543429844107,
    0.18706157443491866, 0.22765072765072658, 0.0, 0.5172413793103448,
    0.2995896032831718, 0.0, 0.01754385964912287, 1.0, 0.9251336898395721,
    0.08455882352941126, 1.0, 0.00444444444444446, 0.0, 0.9774011299435029,
    0.0350194552529181, 0.9333333333333333, 1.0, 0.0, 0.0, 0.9829545454545454,
    0.0652173913043481, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.015267175572519153,
    0.011494252873563269, 1.0, 0.0, 0.039473684210526376, 1.0,
    0.02666666666666671, 1.0, 0.013513513513513535, 0.09999999999999999, 0.0,
    0.0, 1.0, 0.20757238307349762, 0.17459080280592418, 0.2515592515592502, 0.0,
    0.4827586206896553, 0.015047879616963019, 1.0, 0.9824561403508772, 0.0,
    0.058823529411764774, 0.0, 0.0, 0.9955555555555556, 1.0,
    0.005649717514124301, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[41] = { 5, 10, 2, 0, 9, 4, 0, 10, 0, 1, 6, 0, 2, 0, 9, 2,
    8, 0, 0, 0, 8, 5, 0, 0, 0, 0, 0, 0, 8, 1, 0, 0, 4, 0, 1, 0, 1, 10, 0, 0, 0 };

  static const int8_T d[82] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 0, 0, 12,
    13, 0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0,
    0, 0, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 32,
    33, 0, 0, 0, 0, 34, 35, 0, 0, 36, 37, 0, 0, 38, 39, 40, 41, 0, 0, 0, 0, 0, 0
  };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 41U * sizeof(real_T));
  for (i = 0; i < 41; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 164U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 41; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 82; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 41; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3648106904231626;
  obj_Prior[1] = 0.22316258351893095;
  obj_Prior[2] = 0.2044543429844098;
  obj_Prior[3] = 0.20757238307349665;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_n(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[204])
{
  int32_T i;
  static const real_T tmp[51] = { 0.0005340809045944201, 0.0, 1.1823653093812374,
    0.10681061304868125, 2.4422121756487027, 3.2395541730037234,
    0.1167053469529549, 0.006799255947665533, 0.0, 0.0037017669559044784,
    0.001667705912675373, 3.9868332201310688, 7.550609438294948,
    0.004033197647673403, 0.006064730192809396, 0.0, 0.0, 0.08919931255766693,
    0.0, 0.0, 0.0016569543672531068, 0.0028456896168600307, 0.14435328726971303,
    0.0, 0.0, 0.015221666568552243, 0.0, 0.0, -0.09893749560218573, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 13.598722215592653, 0.0, 0.0, 0.0027647051706200312,
    0.0016143278445195346, 0.027944891675803427, 0.0, 0.0, 0.0, 0.0,
    0.1932762613825879, 0.0, 0.0, 0.19373485777959815, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, false, true, true,
    false, true, true, false, false, false, true, true, false, true, true, false,
    true, true, true, true, true, true, false, true, true, false, false, false,
    true, true, true, true, false, true, true, false, true, true };

  static const real_T tmp_1[204] = { 0.36525612472160046, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.2120267260579075, 0.0, 0.33403508771929824, 0.0029112081513828236,
    0.6422764227642296, 0.0, 0.005154639175257727, 0.9312377210216113, 0.0, 0.0,
    0.0, 0.0, 0.005882352941176478, 0.368421052631579, 0.9530612244897961, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 1.0, 0.0, 0.9569672131147543, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.8928571428571427, 1.0, 0.0, 0.0,
    0.05555555555555556, 0.9775280898876405, 0.0, 0.0, 1.0, 0.0,
    0.9942857142857143, 0.0, 1.0, 0.8333333333333333, 0.0, 1.0,
    0.2044543429844107, 0.0, 0.32210526315789456, 0.6171761280931606,
    0.04742547425474246, 0.1571906354515055, 0.9716494845360826,
    0.06876227897838869, 0.0, 0.02857142857142868, 0.7407407407407406,
    0.8541666666666666, 0.9882352941176472, 0.6315789473684211,
    0.04693877551020387, 1.0, 0.0, 0.3, 1.0, 0.0, 0.9318181818181819,
    0.993939393939394, 0.8, 0.0, 1.0, 0.04303278688524571, 1.0, 1.0,
    0.12499999999999999, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.10714285714285726, 0.0,
    1.0, 0.06666666666666667, 0.9444444444444445, 0.02247191011235958, 0.0, 1.0,
    0.0, 1.0, 0.005714285714285722, 1.0, 0.0, 0.16666666666666666, 1.0, 0.0,
    0.21826280623608135, 0.0, 0.34385964912280714, 0.3799126637554567,
    0.31029810298102806, 0.8428093645484945, 0.02319587628865977, 0.0, 1.0,
    0.9714285714285713, 0.25925925925925936, 0.1458333333333334,
    0.005882352941176478, 0.0, 0.0, 0.0, 1.0, 0.7000000000000001, 0.0, 1.0,
    0.06818181818181822, 0.006060606060606071, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.875, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9333333333333333, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[51] = { 10, 0, 4, 2, 4, 5, 2, 9, 0, 10, 8, 5, 7, 1, 8, 0,
    0, 3, 0, 0, 8, 1, 3, 0, 0, 9, 0, 0, 6, 0, 0, 0, 0, 0, 0, 5, 0, 0, 9, 8, 10,
    0, 0, 0, 0, 2, 0, 0, 3, 0, 0 };

  static const int8_T d[102] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 28,
    29, 0, 0, 0, 0, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 36, 37, 0, 0, 0, 0, 38,
    39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0, 42, 43, 44, 45,
    46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 204U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36525612472160357;
  obj_Prior[1] = 0.21202672605790646;
  obj_Prior[2] = 0.2044543429844098;
  obj_Prior[3] = 0.2182628062360802;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_kq(real_T obj_CutPredictorIndex[57],
  real_T obj_Children[114], real_T obj_CutPoint[57], boolean_T obj_NanCutPoints
  [57], boolean_T obj_InfCutPoints[57], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[228])
{
  int32_T i;
  static const real_T tmp[57] = { 0.006934712117681702, 0.1590934906422222,
    0.08643144713245803, 0.0035784110100112254, 0.13542646950941317, 0.0,
    5.426666283735684, 0.1310929761070689, 0.3620844311377246,
    1.2509129341317364, 0.0, 0.16335696244533293, 0.0, 0.0, 9.993031748504585,
    0.00515710791851382, 13.90566414594564, 0.24706947433317844,
    0.22019431322735605, 0.00998503477651971, 0.0, 0.0, 0.0, 0.2352526927683095,
    0.0, 0.0, 0.0013598752763501498, 0.0, 0.0, 0.008366089464976209,
    0.0035878890363803644, 0.0, 4.096399523464692, 0.0, 0.0, 0.0, 0.0,
    0.1748204330866201, 0.005239800228780586, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.17083171564728533, 9.40652948752292, 0.02388690434113296,
    1.2860801397205588, 0.0, 0.0, 0.0, 0.0, 1.283562395209581, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[57] = { false, false, false, false, false, true,
    false, false, false, false, true, false, true, true, false, false, false,
    false, false, false, true, true, true, false, true, true, false, true, true,
    false, false, true, false, true, true, true, true, false, false, true, true,
    true, true, true, true, false, false, false, false, true, true, true, true,
    false, true, true, true };

  static const real_T tmp_1[228] = { 0.37282850779509696, 0.003521126760563376,
    0.7511271415689794, 0.007220216606498198, 0.0, 1.0, 0.0, 0.0,
    0.010526315789473691, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.15384615384615385, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20890868596882067,
    0.32306338028168996, 0.09197475202885545, 0.055956678700361036,
    0.5773195876288657, 0.0, 0.36956521739130443, 0.09770114942528735,
    0.03684210526315791, 0.7905882352941176, 0.0, 0.1944444444444444, 1.0, 0.0,
    0.7727272727272728, 0.0, 0.03954802259887009, 0.06521739130434787,
    0.8786279683377308, 0.27450980392156876, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.6363636363636364, 0.0, 1.0, 0.956140350877193, 0.16216216216216214, 0.0,
    0.41176470588235314, 0.0, 0.0, 1.0, 0.0, 0.6785714285714286,
    0.9808917197452229, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.9866666666666666,
    0.8571428571428571, 0.9166666666666667, 0.9962121212121212, 1.0, 0.0, 1.0,
    0.0, 0.875, 1.0, 1.0, 0.0, 0.22271714922049135, 0.3873239436619728,
    0.05410279531109136, 0.6335740072202167, 0.15292096219931273, 0.0,
    0.2173913043478258, 0.028735632183908042, 0.9105263157894736,
    0.20941176470588244, 0.0, 0.2777777777777774, 0.0, 0.0, 0.22727272727272727,
    0.23076923076923075, 0.9604519774011299, 0.9347826086956522,
    0.12137203166226918, 0.39215686274509787, 0.0, 1.0, 0.0, 0.6, 0.0, 1.0,
    0.36363636363636365, 1.0, 0.0, 0.04385964912280709, 0.8378378378378378, 0.0,
    0.5882352941176469, 0.0, 1.0, 0.0, 1.0, 0.32142857142857145,
    0.01910828025477713, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.013333333333333384,
    0.14285714285714285, 0.08333333333333334, 0.003787878787878806, 0.0, 1.0,
    0.0, 1.0, 0.125, 0.0, 0.0, 1.0, 0.195545657015591, 0.2860915492957738,
    0.10279531109107377, 0.303249097472924, 0.26975945017182146, 0.0,
    0.4130434782608698, 0.8735632183908046, 0.042105263157894764, 0.0, 1.0,
    0.5277777777777781, 0.0, 1.0, 0.0, 0.6153846153846154, 0.0, 0.0, 0.0,
    0.3333333333333333, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[57] = { 1, 2, 2, 1, 10, 0, 7, 3, 4, 4, 0, 10, 0, 0, 5,
    10, 5, 3, 6, 10, 0, 0, 0, 4, 0, 0, 8, 0, 0, 9, 1, 0, 5, 0, 0, 0, 0, 3, 8, 0,
    0, 0, 0, 0, 0, 3, 5, 10, 4, 0, 0, 0, 0, 4, 0, 0, 0 };

  static const int8_T d[114] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 34, 35, 0, 0, 0, 0, 36, 37, 0, 0, 0, 0,
    38, 39, 40, 41, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 44, 45, 46, 47, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 50, 51, 52, 53, 54, 55, 0, 0, 0, 0, 0,
    0, 0, 0, 56, 57, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 57U * sizeof(real_T));
  for (i = 0; i < 57; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 228U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 57; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 114; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 57; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.37282850779510024;
  obj_Prior[1] = 0.2089086859688196;
  obj_Prior[2] = 0.22271714922049;
  obj_Prior[3] = 0.1955456570155902;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_o2(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196])
{
  int32_T i;
  static const real_T tmp[49] = { 0.291311397512667, 0.0008656706511046895,
    1.1796039121756485, 0.0, 0.0037959345520248693, 0.0018650900666421508,
    0.43546770836122617, 0.0, 0.0, 0.002330103305554363, 0.07778006779664128,
    0.009129541844983751, 0.0, 3.320897601062088, 0.0, 0.0, 0.002627480965802771,
    15.557649244917314, 0.39607092976644986, 0.0, 4.299668696972951, 0.0, 0.0,
    0.0, 0.0045882768739864, 0.27749461304033207, 0.0, 0.0, 0.0,
    0.010096738926162146, 0.0, 1.2345882035928144, 0.011255490065406128, 0.0,
    0.0, 5.253610350637672, 0.03980215895237977, 0.0, 0.0, 0.0, 0.0,
    0.03866860010706223, 0.0, 0.23664564530278542, 0.0, 0.0, 0.27973789236767577,
    0.0, 0.0 };

  static const boolean_T tmp_0[49] = { false, false, false, true, false, false,
    false, true, true, false, false, false, true, false, true, true, false,
    false, false, true, false, true, true, true, false, false, true, true, true,
    false, true, false, false, true, true, false, false, true, true, true, true,
    false, true, false, true, true, false, true, true };

  static const real_T tmp_1[196] = { 0.39198218262805873, 0.995418098510882,
    0.008017492711370226, 1.0, 0.0, 0.01694915254237286, 0.0, 0.0, 0.0, 0.0,
    0.025700934579439182, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.20311804008908804, 0.0, 0.33236151603498537, 0.0, 0.0, 0.0,
    0.6307053941908729, 0.0, 0.0, 0.0, 0.0, 0.928716904276986, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7473684210526312, 0.9722222222222222, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.922077922077922, 0.9846547314578006, 0.0, 0.0, 0.0, 0.986111111111111, 0.0,
    0.9896373056994818, 0.6, 0.0, 1.0, 0.75, 0.9947089947089948, 0.0, 1.0, 1.0,
    0.0, 0.9867549668874172, 1.0, 0.9933333333333334, 0.0, 1.0,
    0.9814814814814815, 0.0, 1.0, 0.20311804008908804, 0.001145475372279508,
    0.3316326530612244, 0.0, 0.24999999999999997, 0.6471494607087839,
    0.04840940525587819, 1.0, 0.0, 0.022624434389140316, 0.9696261682242991,
    0.07128309572301397, 0.0, 0.004608294930875586, 1.0, 0.0, 0.9952038369304557,
    0.25263157894736876, 0.027777777777777735, 0.0, 0.08333333333333333, 0.0,
    1.0, 1.0, 0.07792207792207806, 0.015345268542199466, 1.0, 1.0, 0.0,
    0.013888888888888914, 1.0, 0.010362694300518121, 0.4, 1.0, 0.0, 0.25,
    0.0052910052910052855, 1.0, 0.0, 0.0, 1.0, 0.013245033112582776, 0.0,
    0.0066666666666666645, 1.0, 0.0, 0.018518518518518542, 1.0, 0.0,
    0.20178173719376521, 0.0034364261168385243, 0.3279883381924199, 0.0, 0.75,
    0.33590138674884323, 0.3208852005532489, 0.0, 1.0, 0.9773755656108597,
    0.00467289719626167, 0.0, 1.0, 0.9953917050691244, 0.0, 0.0,
    0.004796163069544352, 0.0, 0.0, 1.0, 0.9166666666666666, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[49] = { 4, 10, 4, 0, 10, 9, 3, 0, 0, 8, 2, 9, 0, 5, 0, 0,
    1, 5, 6, 0, 7, 0, 0, 0, 1, 6, 0, 0, 0, 10, 0, 4, 9, 0, 0, 7, 6, 0, 0, 0, 0,
    6, 0, 2, 0, 0, 3, 0, 0 };

  static const int8_T d[98] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12, 13, 0,
    0, 0, 0, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 24, 25,
    26, 27, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 34,
    35, 0, 0, 36, 37, 38, 39, 0, 0, 0, 0, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0,
    44, 45, 0, 0, 46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 49U * sizeof(real_T));
  for (i = 0; i < 49; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 196U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 49; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 98; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 49; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3919821826280624;
  obj_Prior[1] = 0.20311804008908688;
  obj_Prior[2] = 0.20311804008908688;
  obj_Prior[3] = 0.20178173719376394;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Com_b(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172])
{
  int32_T i;
  static const real_T tmp[43] = { 0.0005343054096836643, 0.0,
    0.007225626596020394, 0.4191734530938124, 0.1374764141791631,
    0.0017343022432522908, 0.003485970510151572, 1.2509129341317364, 0.0,
    0.08501251453601325, 0.0, 0.12951312554138106, 8.15673078726008,
    0.24706947433317844, 0.272120275234923, 0.0, 0.0, 0.0, 5.917310195066335,
    0.0, 0.0014607619311881048, -0.18421662108886702, 0.0, 0.00829734570451,
    0.019011351886857958, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1748138823225865,
    0.1708252626587306, 0.0, 0.0, 0.0, 0.0, 0.011121350020129914, 0.0, 0.0,
    0.17024824774870104, 0.0, 0.0 };

  static const boolean_T tmp_0[43] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, false, false, true, true,
    true, false, true, false, false, true, false, false, true, true, true, true,
    true, true, false, false, true, true, true, true, false, true, true, false,
    true, true };

  static const real_T tmp_1[172] = { 0.3496659242761665, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2200445434298451, 0.0,
    0.3383561643835617, 0.01749271137026237, 0.6227390180878574, 0.0,
    0.026548672566371608, 0.9146110056926001, 0.0, 0.0, 0.0, 0.2972972972972973,
    0.0024096385542168603, 0.17241379310344826, 0.9578313253012051, 0.0, 0.0,
    0.0, 0.6111111111111112, 0.0, 0.14285714285714285, 0.039999999999999994, 1.0,
    0.9874739039665972, 0.21052631578947367, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0,
    0.8484848484848485, 0.9977578475336323, 1.0, 0.0, 1.0, 0.0,
    0.9787234042553192, 1.0, 1.0, 0.888888888888889, 1.0, 0.0,
    0.2164810690423172, 0.0, 0.33287671232876714, 0.6428571428571446,
    0.058139534883720784, 0.08547008547008572, 0.93141592920354,
    0.08538899430739992, 0.0, 0.013824884792626772, 1.0, 0.18918918918918923,
    0.9975903614457831, 0.8275862068965517, 0.042168674698794976, 1.0, 0.0, 0.0,
    0.3888888888888889, 1.0, 0.8571428571428571, 0.96, 0.0, 0.012526096033402863,
    0.7894736842105263, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.1515151515151515,
    0.0022421524663677043, 0.0, 1.0, 0.0, 1.0, 0.02127659574468087, 0.0, 0.0,
    0.11111111111111112, 0.0, 1.0, 0.21380846325167127, 0.0, 0.32876712328767116,
    0.33965014577259306, 0.3191214470284218, 0.9145299145299143,
    0.042035398230088374, 0.0, 1.0, 0.9861751152073732, 0.0, 0.5135135135135136,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const int8_T c[43] = { 10, 0, 9, 4, 10, 9, 1, 4, 0, 2, 0, 2, 7, 3, 6, 0,
    0, 0, 7, 0, 8, 6, 0, 9, 10, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 9, 0, 0, 2,
    0, 0 };

  static const int8_T d[86] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26,
    27, 0, 0, 28, 29, 30, 31, 0, 0, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0, 42, 43, 0,
    0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 43U * sizeof(real_T));
  for (i = 0; i < 43; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 172U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 43; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 86; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 43; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.34966592427616927;
  obj_Prior[1] = 0.22004454342984409;
  obj_Prior[2] = 0.21648106904231626;
  obj_Prior[3] = 0.21380846325167038;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_cr(real_T obj_CutPredictorIndex[67],
  real_T obj_Children[134], real_T obj_CutPoint[67], boolean_T obj_NanCutPoints
  [67], boolean_T obj_InfCutPoints[67], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[268])
{
  int32_T i;
  static const real_T tmp[67] = { 0.07763883647050532, 0.0, 0.006957788860168146,
    0.10447134297475781, 0.06536073956848822, 0.0018899846220002039,
    0.002057417701559171, 1.1813906986027942, 0.0, 0.003968133535574361,
    0.008323536208832333, 6.588957101793498, 7.721199389709195, 0.0,
    0.2671735379729756, 0.007763698463049862, 0.08607290731424058, 0.0,
    0.0906675746847655, 0.0, 0.0, 0.002627480965802771, 0.011390848406210123,
    1.2499383233532935, 0.16401902831002912, 0.0, 0.0, 0.0, 5.06384390384442,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0017767550884115325, 0.004244053991626123,
    0.24114389919394402, 0.0, 0.0, 0.0, 0.003262260946856288, 0.0, 0.0, 0.0,
    0.0054762370766279905, 1.2860801397205588, 0.0028749042700564765, 0.0, 0.0,
    0.0, 0.0, 0.015018094259946504, 0.029308438251397714, 0.0, 0.0, 0.0,
    0.002275006472741, 0.03601001233518063, 0.0, 0.0, 0.0, 0.0,
    0.0041347147902713235, 0.037513111258623534, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[67] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, true, false, false, false,
    true, false, true, true, false, false, false, false, true, true, true, false,
    true, true, true, true, true, false, false, false, true, true, true, false,
    true, true, true, false, false, false, true, true, true, true, false, false,
    true, true, true, false, false, true, true, true, true, false, false, true,
    true, true };

  static const real_T tmp_1[268] = { 0.38307349665923934, 1.0,
    0.0014419610670511832, 0.0029895366218236153, 0.0, 0.007518796992481226, 0.0,
    0.0, 0.0, 0.004273504273504287, 0.03125, 0.0, 0.0, 0.0, 0.0,
    0.14285714285714285, 0.0, 0.0, 0.33333333333333337, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.19554565701559115, 0.0, 0.3165104542177359, 0.013452914798206268,
    0.5988857938718679, 0.0, 0.022332506203473917, 0.8775510204081638, 0.0, 0.0,
    0.0, 0.0, 0.023195876288659767, 0.0, 0.9327548806941434, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.36, 0.9727272727272729, 0.09523809523809525, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.75, 0.5833333333333334, 0.9836448598130841,
    1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.16666666666666669, 0.9881516587677726,
    0.6666666666666667, 0.0, 0.0, 0.0, 1.0, 0.8571428571428571,
    0.9926470588235294, 1.0, 0.0, 1.0, 0.33333333333333337, 0.9830508474576272,
    1.0, 1.0, 0.0, 1.0, 0.9508196721311475, 0.9666666666666666, 0.0, 0.0, 1.0,
    0.21514476614699468, 0.0, 0.34823359769286255, 0.6322869955156966,
    0.08356545961002766, 0.16165413533834624, 0.9429280397022333,
    0.1224489795918362, 0.0, 0.05982905982906002, 0.90625, 0.13333333333333333,
    0.9742268041237113, 1.0, 0.06724511930585662, 0.8571428571428571,
    0.03524229074889879, 1.0, 0.0, 0.0, 1.0, 0.9972451790633609, 0.64,
    0.027272727272727185, 0.9047619047619048, 1.0, 0.0, 1.0,
    0.026666666666666755, 0.0, 0.0, 0.0, 1.0, 1.0, 0.25, 0.41666666666666663,
    0.016355140186915838, 0.0, 1.0, 0.0, 0.5454545454545454, 0.0, 1.0, 0.0,
    0.8333333333333333, 0.011848341232227454, 0.33333333333333337, 0.0, 1.0, 1.0,
    0.0, 0.14285714285714285, 0.007352941176470571, 0.0, 1.0, 0.0,
    0.6666666666666667, 0.016949152542372902, 0.0, 0.0, 1.0, 0.0,
    0.04918032786885253, 0.03333333333333338, 1.0, 1.0, 0.0, 0.20623608017817488,
    0.0, 0.33381398702235043, 0.3512705530642734, 0.31754874651810444,
    0.8308270676691725, 0.034739454094292764, 0.0, 1.0, 0.9358974358974357,
    0.0625, 0.8666666666666667, 0.002577319587628863, 0.0, 0.0, 0.0,
    0.9647577092511012, 0.0, 0.6666666666666667, 1.0, 0.0, 0.0027548209366391172,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9733333333333333, 0.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.45454545454545453, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[67] = { 3, 0, 9, 3, 9, 8, 9, 4, 0, 10, 1, 7, 7, 0, 6, 1,
    3, 0, 3, 0, 0, 1, 10, 4, 3, 0, 0, 0, 7, 0, 0, 0, 0, 0, 8, 1, 6, 0, 0, 0, 1,
    0, 0, 0, 1, 4, 8, 0, 0, 0, 0, 6, 10, 0, 0, 0, 8, 6, 0, 0, 0, 0, 8, 6, 0, 0,
    0 };

  static const int8_T d[134] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 28, 29,
    0, 0, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0,
    40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 46, 47, 0, 0, 0, 0, 0,
    0, 48, 49, 0, 0, 0, 0, 0, 0, 50, 51, 52, 53, 54, 55, 0, 0, 0, 0, 0, 0, 0, 0,
    56, 57, 58, 59, 0, 0, 0, 0, 0, 0, 60, 61, 62, 63, 0, 0, 0, 0, 0, 0, 0, 0, 64,
    65, 66, 67, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 67U * sizeof(real_T));
  memcpy(&obj_NanCutPoints[0], &tmp_0[0], 67U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &tmp_1[0], 268U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 67; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 134; i++) {
    obj_Children[i] = d[i];
  }

  memset(&obj_InfCutPoints[0], 0, 67U * sizeof(boolean_T));
  obj_Prior[0] = 0.3830734966592428;
  obj_Prior[1] = 0.1955456570155902;
  obj_Prior[2] = 0.21514476614699332;
  obj_Prior[3] = 0.20623608017817371;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_pre_b(const real_T obj_CutPredictorIndex
  [67], const real_T obj_Children[134], const real_T obj_CutPoint[67], const
  boolean_T obj_NanCutPoints[67], const real_T obj_Cost[16], const real_T
  obj_ClassProbability[268], const real_T Xin[10], real_T *labels, real_T
  scores[4])
{
  real_T obj_ClassProbability_0[4];
  real_T a__4;
  int32_T i;
  int32_T m;
  int32_T obj_ClassProbability_tmp;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 4; i++) {
    obj_ClassProbability_tmp = i << 2;
    obj_ClassProbability_0[i] = ((obj_Cost[obj_ClassProbability_tmp + 1] *
      obj_ClassProbability[m + 67] + obj_Cost[obj_ClassProbability_tmp] *
      obj_ClassProbability[m]) + obj_Cost[obj_ClassProbability_tmp + 2] *
      obj_ClassProbability[m + 134]) + obj_Cost[obj_ClassProbability_tmp + 3] *
      obj_ClassProbability[m + 201];
    scores[i] = obj_ClassProbability[67 * i + m];
  }

  MotorFaultDeploy_minimum(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void MotorFaul_predictOneWithCache_i(const real_T X[10], real_T
  cachedScore[4], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[67], const real_T weak_learner_Children[134],
  const real_T weak_learner_CutPoint[67], const boolean_T
  weak_learner_NanCutPoints[67], const real_T weak_learner_Cost[16], const
  real_T weak_learner_ClassProbability[268], boolean_T *cached, real_T score[4])
{
  real_T b[4];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pre_b(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 4)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 4; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_he(real_T obj_CutPredictorIndex[43],
  real_T obj_Children[86], real_T obj_CutPoint[43], boolean_T obj_NanCutPoints
  [43], boolean_T obj_InfCutPoints[43], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[172])
{
  int32_T i;
  static const real_T tmp[43] = { 0.07944453635367484, 0.35446341133118375,
    0.1589961175587839, 0.0, 0.0, 0.4166964870259481, 0.14000143563976908,
    0.0017503001345564768, 1.1162542115768463, 0.2751489368047294, 0.0, 0.0, 0.0,
    0.0018701871129421718, 0.0019096760533111367, 3.712554727474525, 0.0,
    0.004949870109726345, 0.07283856558917187, 0.0, 0.0, 0.0, 1.2509129341317364,
    0.0, 0.0, 0.0, 0.5055181237524949, 0.004053612981711509, 0.2708660553318115,
    0.4943100998003992, 0.0, 0.0, 0.0, 7.234665326001996, 0.0, 0.0, 0.0, 0.0,
    0.02640619878230964, 0.006754155833662094, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[43] = { false, false, false, true, true, false,
    false, false, false, false, true, true, true, false, false, false, true,
    false, false, true, true, true, false, true, true, true, false, false, false,
    false, true, true, true, false, true, true, true, true, false, false, true,
    true, true };

  static const real_T tmp_1[172] = { 0.3621380846325137, 0.9963235294117647, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2106904231625845, 0.0,
    0.3310006997900629, 0.0, 0.0, 0.04604316546762589, 0.6008174386920998, 0.0,
    0.07017543859649109, 0.8855421686746993, 0.0, 0.0, 0.0, 0.0,
    0.888888888888889, 0.9303797468354432, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.9382978723404257, 0.0, 0.0, 0.0, 0.0, 0.15, 0.9733333333333335, 0.0, 0.0,
    0.0, 1.0, 0.9414634146341463, 1.0, 0.0, 0.0, 0.0, 0.9747474747474747,
    0.9948453608247423, 0.0, 0.0, 1.0, 0.21113585746102548, 0.003676470588235324,
    0.3296011196641007, 0.0, 1.0, 0.5956834532374116, 0.07765667574931862,
    0.054393305439330734, 0.8793859649122809, 0.11445783132530067, 0.0, 0.0, 1.0,
    0.9452380952380953, 0.11111111111111112, 0.06962025316455671, 1.0,
    0.043478260869565216, 0.9974811083123425, 0.0, 1.0, 1.0,
    0.061702127659574245, 1.0, 0.0, 1.0, 0.9811320754716981, 0.8500000000000001,
    0.02666666666666657, 0.9, 1.0, 1.0, 0.0, 0.05853658536585379, 0.0, 1.0, 0.0,
    1.0, 0.025252525252525308, 0.005154639175257744, 1.0, 1.0, 0.0,
    0.21603563474387635, 0.0, 0.3393981805458363, 0.0, 0.0, 0.3582733812949624,
    0.3215258855585815, 0.9456066945606693, 0.05043859649122797, 0.0, 1.0, 1.0,
    0.0, 0.05476190476190465, 0.0, 0.0, 0.0, 0.9565217391304348,
    0.0025188916876574255, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.018867924528301907, 0.0, 0.0, 0.09999999999999999, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[43] = { 2, 4, 3, 0, 0, 4, 10, 9, 4, 6, 0, 0, 0, 9, 8, 7,
    0, 10, 6, 0, 0, 0, 4, 0, 0, 0, 4, 8, 3, 4, 0, 0, 0, 7, 0, 0, 0, 0, 10, 9, 0,
    0, 0 };

  static const int8_T d[86] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25,
    26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 34, 35,
    36, 37, 0, 0, 0, 0, 0, 0, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 0,
    0, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 43U * sizeof(real_T));
  for (i = 0; i < 43; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 172U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 43; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 86; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 43; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3621380846325167;
  obj_Prior[1] = 0.21069042316258352;
  obj_Prior[2] = 0.2111358574610245;
  obj_Prior[3] = 0.21603563474387527;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactClassificationTree_Co_ci(real_T obj_CutPredictorIndex[49],
  real_T obj_Children[98], real_T obj_CutPoint[49], boolean_T obj_NanCutPoints
  [49], boolean_T obj_InfCutPoints[49], int32_T obj_ClassNamesLength[4],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[4],
  boolean_T obj_ClassLogicalIndices[4], real_T obj_Cost[16], real_T
  obj_ClassProbability[196])
{
  int32_T i;
  static const real_T tmp[49] = { 0.08012190595190324, 0.35446341133118375,
    1.1813906986027942, 0.0, 0.0, 0.0018650900666421508, 0.06536073956848822,
    5.387763369800359, 0.21030925078571877, 0.007357046408646196, 0.0,
    0.08453163486010447, 0.003602503927691492, 0.07344282166892332,
    0.005765574651478292, 0.15341943239461547, 1.823821636726547, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.5055181237524949, 0.0, 0.0, 0.0023289700967457326,
    0.0016126188064167703, 0.2671735379729756, 0.026863983589130613,
    0.49260453093812373, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2559356796041202,
    9.511354299001766, 0.0, 0.0, 0.0, 0.0, 0.023801726599014125, 0.0, 0.0, 0.0,
    0.0, 1.529895269461078, 0.0, 0.0 };

  static const boolean_T tmp_0[49] = { false, false, false, true, true, false,
    false, false, false, false, true, false, false, false, false, false, false,
    true, true, true, true, true, false, true, true, false, false, false, false,
    false, true, true, true, true, true, false, false, true, true, true, true,
    false, true, true, true, true, false, true, true };

  static const real_T tmp_1[196] = { 0.3781737193763886, 0.9988235294117648, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.20222717149220593, 0.0, 0.32544802867383504, 0.0, 0.0,
    0.0015337423312883427, 0.6096904441453584, 0.0, 0.0024038461538461475,
    0.8934911242603555, 0.0, 0.0, 0.0, 0.0, 0.25, 0.25806451612903225,
    0.9348739495798322, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.7777777777777778, 0.045454545454545456, 0.9596412556053814,
    0.5666666666666667, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.9793577981651377, 0.1,
    1.0, 0.0, 0.0, 0.0, 0.9545454545454545, 1.0, 0.0, 1.0, 1.0,
    0.35714285714285715, 0.0, 1.0, 0.2106904231625847, 0.0011764705882353055,
    0.33835125448028686, 0.0, 1.0, 0.6411042944785291, 0.07267833109017478,
    0.025423728813559417, 0.9903846153846154, 0.10650887573964445, 0.0,
    0.008810572687224702, 0.4444444444444445, 0.9927184466019418, 0.75,
    0.7419354838709677, 0.06512605042016784, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.9361702127659575, 1.0, 0.0, 0.22222222222222224, 0.9545454545454546,
    0.04035874439461871, 0.43333333333333335, 0.5000000000000001, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.020642201834862317, 0.9, 0.0, 1.0, 1.0, 0.0,
    0.045454545454545546, 0.0, 1.0, 0.0, 0.0, 0.6428571428571429, 1.0, 0.0,
    0.20890868596882076, 0.0, 0.3362007168458782, 0.0, 0.0, 0.3573619631901825,
    0.3176312247644667, 0.9745762711864406, 0.007211538461538441, 0.0, 1.0,
    0.9911894273127753, 0.5555555555555556, 0.007281553398058233, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 0.06382978723404259, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[49] = { 3, 4, 4, 0, 0, 9, 9, 7, 6, 9, 0, 2, 1, 6, 1, 3,
    4, 0, 0, 0, 0, 0, 4, 0, 0, 8, 8, 6, 10, 4, 0, 0, 0, 0, 0, 3, 7, 0, 0, 0, 0,
    10, 0, 0, 0, 0, 4, 0, 0 };

  static const int8_T d[98] = { 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38,
    39, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0,
    0, 0, 46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0 };

  static const int8_T h[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 49U * sizeof(real_T));
  for (i = 0; i < 49; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 196U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  obj_ClassNamesLength[3] = 1;
  obj_ClassLogicalIndices[3] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 49; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 98; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 49; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.378173719376392;
  obj_Prior[1] = 0.2022271714922049;
  obj_Prior[2] = 0.21069042316258352;
  obj_Prior[3] = 0.2089086859688196;
  for (i = 0; i < 16; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/BearingDetector' */
static void CompactEnsemble_ensemblePredict(const boolean_T obj_IsCached[50],
  const real_T X[10], real_T score[4])
{
  real_T assign_temp_ClassProbability_c[268];
  real_T assign_temp_ClassProbability_8[228];
  real_T assign_temp_ClassProbability_2[220];
  real_T assign_temp_ClassProbability_1[212];
  real_T assign_temp_ClassProbability_7[204];
  real_T assign_temp_ClassProbability_3[196];
  real_T assign_temp_ClassProbability_5[188];
  real_T assign_temp_ClassProbability_4[180];
  real_T assign_temp_ClassProbability[172];
  real_T assign_temp_ClassProbability_a[164];
  real_T assign_temp_ClassProbability_0[156];
  real_T assign_temp_ClassProbability_9[148];
  real_T assign_temp_ClassProbability_b[140];
  real_T assign_temp_Children_4[134];
  real_T x[126];
  real_T assign_temp_ClassProbability_6[124];
  real_T od[118];
  real_T assign_temp_Children_2[114];
  real_T assign_temp_Children_0[110];
  real_T pc[106];
  real_T assign_temp_Children_1[102];
  real_T e[98];
  real_T kb[94];
  real_T ud[90];
  real_T assign_temp_Children[86];
  real_T qb[82];
  real_T jc[78];
  real_T wb[74];
  real_T assign_temp_Children_3[70];
  real_T assign_temp_CutPoint_c[67];
  real_T assign_temp_CutPredictorIndex_4[67];
  real_T eb[66];
  real_T w[63];
  real_T l[62];
  real_T nd[59];
  real_T r[58];
  real_T assign_temp_CutPoint_8[57];
  real_T assign_temp_CutPredictorIndex_2[57];
  real_T assign_temp_CutPoint_2[55];
  real_T assign_temp_CutPredictorIndex_0[55];
  real_T assign_temp_CutPoint_1[53];
  real_T oc[53];
  real_T assign_temp_CutPoint_7[51];
  real_T assign_temp_CutPredictorIndex_1[51];
  real_T assign_temp_CutPoint_3[49];
  real_T d[49];
  real_T assign_temp_CutPoint_5[47];
  real_T jb[47];
  real_T assign_temp_CutPoint_4[45];
  real_T td[45];
  real_T assign_temp_CutPoint[43];
  real_T assign_temp_CutPredictorIndex[43];
  real_T assign_temp_CutPoint_a[41];
  real_T pb[41];
  real_T assign_temp_CutPoint_0[39];
  real_T ic[39];
  real_T assign_temp_CutPoint_9[37];
  real_T vb[37];
  real_T assign_temp_CutPoint_b[35];
  real_T assign_temp_CutPredictorIndex_3[35];
  real_T db[33];
  real_T assign_temp_CutPoint_6[31];
  real_T k[31];
  real_T q[29];
  real_T assign_temp_Cost[16];
  real_T cachedScore[4];
  real_T cachedWeights;
  c_classreg_learning_coderutil_T expl_temp_1;
  int32_T expl_temp_0[4];
  int32_T i;
  boolean_T assign_temp_NanCutPoints_c[67];
  boolean_T expl_temp_f[67];
  boolean_T assign_temp_NanCutPoints_8[57];
  boolean_T expl_temp_b[57];
  boolean_T assign_temp_NanCutPoints_2[55];
  boolean_T expl_temp_5[55];
  boolean_T assign_temp_NanCutPoints_1[53];
  boolean_T expl_temp_4[53];
  boolean_T assign_temp_NanCutPoints_7[51];
  boolean_T expl_temp_a[51];
  boolean_T assign_temp_NanCutPoints_3[49];
  boolean_T expl_temp_6[49];
  boolean_T assign_temp_NanCutPoints_5[47];
  boolean_T expl_temp_8[47];
  boolean_T assign_temp_NanCutPoints_4[45];
  boolean_T expl_temp_7[45];
  boolean_T assign_temp_NanCutPoints[43];
  boolean_T expl_temp[43];
  boolean_T assign_temp_NanCutPoints_a[41];
  boolean_T expl_temp_d[41];
  boolean_T assign_temp_NanCutPoints_0[39];
  boolean_T expl_temp_3[39];
  boolean_T assign_temp_NanCutPoints_9[37];
  boolean_T expl_temp_c[37];
  boolean_T assign_temp_NanCutPoints_b[35];
  boolean_T expl_temp_e[35];
  boolean_T assign_temp_NanCutPoints_6[31];
  boolean_T expl_temp_9[31];
  boolean_T expl_temp_2[4];
  boolean_T b;
  static const int8_T i_0[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0
  };

  static const int8_T d_0[49] = { 10, 0, 4, 3, 9, 7, 4, 3, 0, 10, 1, 0, 3, 0, 10,
    8, 0, 0, 0, 8, 1, 0, 4, 8, 0, 0, 1, 0, 4, 6, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0,
    7, 0, 0, 8, 5, 0, 0, 0 };

  static const int8_T e_0[98] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 22, 23, 24, 25, 0, 0, 0, 0,
    0, 0, 26, 27, 28, 29, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 0, 0, 36, 37,
    38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0,
    44, 45, 0, 0, 0, 0, 46, 47, 48, 49, 0, 0, 0, 0, 0, 0 };

  static const char_T combiner[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
    'A', 'v', 'e', 'r', 'a', 'g', 'e' };

  static const real_T c[49] = { 0.0005511413578816758, 0.0, 1.1837460079840318,
    0.10447134297475781, 0.06536073956848822, 4.701838716596798,
    0.4084752295409182, 0.14066616273133764, 0.0, 0.004271697273558396,
    0.0034583464613741274, 0.0, 0.11672819771502302, 0.0, 0.012563887735941243,
    0.0014284583326677927, 0.0, 0.0, 0.0, 0.0015084095513561522,
    0.0028456896168600307, 0.0, 2.1614430538922154, 0.0012973895479110916, 0.0,
    0.0, 0.00850955799338822, 0.0, 1.119665349301397, 0.31592690184863964, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.005765574651478292, 0.2710162971120107, 0.0, 0.0,
    0.0, 7.209323331729101, 0.0, 0.0, 0.004323725332436709, 11.536025305766277,
    0.0, 0.0, 0.0 };

  static const boolean_T f[49] = { false, true, false, false, false, false,
    false, false, true, false, false, true, false, true, false, false, true,
    true, true, false, false, true, false, false, true, true, false, true, false,
    false, true, true, true, true, true, true, false, false, true, true, true,
    false, true, true, false, false, true, true, true };

  static const real_T g[196] = { 0.3510022271714894, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.21870824053452215, 0.0, 0.3369938229238161, 0.0015015015015015008,
    0.6194690265486749, 0.0, 0.002557544757033245, 0.9280303030303034, 0.0, 0.0,
    0.0, 0.0, 0.0025839793281653717, 0.0, 0.9351145038167943, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.002941176470588238, 0.0, 0.9459459459459463, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002949852507374634, 0.9514563106796119, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.1111111111111111, 0.9800000000000001, 0.0, 0.0, 1.0, 0.9615384615384613,
    1.0, 0.0, 0.9881422924901185, 0.9960159362549801, 0.0, 0.0, 1.0,
    0.20356347438752853, 0.0, 0.3136582017844884, 0.6291291291291308,
    0.04804045512010104, 0.1563636363636368, 0.9616368286445012,
    0.07196969696969659, 0.0, 0.05907172995780611, 0.7631578947368421, 0.0,
    0.9715762273901808, 1.0, 0.06488549618320578, 0.9333333333333333, 0.0, 0.0,
    1.0, 0.8085106382978724, 0.9941176470588234, 1.0, 0.05405405405405378,
    0.6666666666666667, 1.0, 0.0, 0.9047619047619048, 0.0, 0.9970501474926253,
    0.0485436893203881, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.888888888888889,
    0.019999999999999893, 1.0, 1.0, 0.0, 0.03846153846153862, 0.0, 1.0,
    0.011857707509881474, 0.0039840637450199385, 1.0, 1.0, 0.0,
    0.22672605790645994, 0.0, 0.3493479752916955, 0.36936936936936765,
    0.3324905183312241, 0.8436363636363632, 0.03580562659846543, 0.0, 1.0,
    0.9409282700421939, 0.23684210526315788, 1.0, 0.025839793281653717, 0.0, 0.0,
    0.06666666666666667, 1.0, 1.0, 0.0, 0.1914893617021277, 0.002941176470588238,
    0.0, 0.0, 0.33333333333333337, 0.0, 1.0, 0.09523809523809526, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const int8_T k_0[31] = { 10, 0, 4, 9, 3, 10, 1, 2, 0, 0, 7, 0, 0, 5, 0,
    0, 8, 1, 8, 0, 0, 0, 0, 6, 0, 5, 0, 2, 0, 0, 0 };

  static const int8_T l_0[62] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 22, 23,
    24, 25, 0, 0, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 28, 29, 0, 0, 30, 31, 0, 0, 0,
    0, 0, 0 };

  static const real_T j[31] = { 0.0008656706511046895, 0.0, 1.119665349301397,
    0.0018367274706142778, 0.4370204932144296, 0.004226481526399742,
    0.0028456896168600307, 0.26201415911732834, 0.0, 0.0, 5.54248348704785, 0.0,
    0.0, 14.217187221152662, 0.0, 0.0, 0.0018823370343703186,
    0.0034979072713947103, 0.004386624044404427, 0.0, 0.0, 0.0, 0.0,
    0.6115479717406337, 0.0, 15.387114863551428, 0.0, 0.17001610645788495, 0.0,
    0.0, 0.0 };

  static const boolean_T m[31] = { false, true, false, false, false, false,
    false, false, true, true, false, true, true, false, true, true, false, false,
    false, true, true, true, true, false, true, false, true, false, true, true,
    true };

  static const real_T n[124] = { 0.37861915367482957, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20668151447661579, 0.0,
    0.33261648745519706, 0.0, 0.6462395543175504, 0.0, 0.0, 0.9169960474308305,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.8494623655913974, 1.0, 0.0, 0.0,
    0.02857142857142857, 0.9672131147540982, 0.0, 0.0, 1.0, 0.0,
    0.9915966386554621, 0.0, 0.9957805907172996, 0.0, 0.8, 1.0, 0.0, 1.0,
    0.21603563474387655, 0.0, 0.3476702508960575, 0.6543574593796178,
    0.05849582172701935, 0.0373443983402491, 0.9954128440366973,
    0.08300395256916956, 0.0, 1.0, 0.012765957446808557, 0.0, 1.0,
    0.1505376344086026, 0.0, 0.0, 0.5999999999999999, 0.9714285714285714,
    0.032786885245901766, 0.0, 1.0, 0.0, 1.0, 0.008403361344537848, 1.0,
    0.004219409282700439, 1.0, 0.19999999999999998, 0.0, 1.0, 0.0,
    0.198663697104678, 0.0, 0.31971326164874525, 0.3456425406203823,
    0.29526462395543024, 0.962655601659751, 0.004587155963302736, 0.0, 1.0, 0.0,
    0.9872340425531915, 1.0, 0.0, 0.0, 0.0, 1.0, 0.4, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T q_0[29] = { 3, 0, 3, 4, 0, 9, 6, 8, 0, 6, 8, 2, 0, 9, 10,
    0, 0, 0, 0, 5, 9, 0, 0, 0, 0, 7, 0, 0, 0 };

  static const int8_T r_0[58] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 0, 0, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 0,
    0, 24, 25, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0 };

  static const real_T p[29] = { 0.08012190595190324, 0.0, 0.4370204932144296,
    1.1813906986027942, 0.0, 0.0020201501308521105, 0.28244135030227946,
    0.0020779973100607547, 0.0, 0.2182322804930567, 0.001790824101972401,
    0.08343769206013966, 0.0, 0.0072670164197668405, 0.02633793106939755, 0.0,
    0.0, 0.0, 0.0, 14.556172470233864, 0.013490944003855646, 0.0, 0.0, 0.0, 0.0,
    7.19426157981164, 0.0, 0.0, 0.0 };

  static const boolean_T s[29] = { false, true, false, false, true, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    false, false, true, true, true, true, false, true, true, true };

  static const real_T t[116] = { 0.3781737193763886, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20534521158129285, 0.0,
    0.33022922636103147, 0.3953687821612355, 0.0, 0.0, 0.9146825396825401, 0.0,
    0.0, 0.9684210526315791, 0.034482758620689655, 0.0, 0.0, 0.9760348583877996,
    0.75, 1.0, 0.0, 0.0, 0.0, 0.7857142857142857, 0.9883990719257542, 1.0, 0.0,
    0.0, 1.0, 0.9606299212598425, 1.0, 0.0, 1.0, 0.21692650334075855, 0.0,
    0.34885386819484265, 0.41766723842195624, 0.0, 0.67069486404834,
    0.08531746031745992, 0.03964757709251114, 1.0, 0.031578947368420915,
    0.9655172413793104, 0.009090909090909122, 1.0, 0.023965141612200338, 0.25,
    0.0, 1.0, 1.0, 0.0, 0.21428571428571427, 0.011600928074245903, 0.0, 1.0, 1.0,
    0.0, 0.03937007874015745, 0.0, 1.0, 0.0, 0.19955456570156, 0.0,
    0.3209169054441259, 0.18696397941680837, 1.0, 0.32930513595166, 0.0,
    0.9603524229074889, 0.0, 0.0, 0.0, 0.9909090909090909, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T w_0[63] = { 10, 0, 9, 2, 9, 8, 5, 6, 0, 10, 1, 6, 1, 4, 2,
    9, 0, 0, 0, 4, 1, 0, 0, 0, 4, 2, 0, 0, 0, 5, 0, 0, 9, 9, 4, 0, 0, 0, 0, 0, 0,
    8, 0, 4, 4, 0, 0, 2, 6, 0, 0, 2, 0, 6, 0, 0, 0, 4, 0, 0, 6, 0, 0 };

  static const int8_T x_0[126] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0,
    0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 0,
    0, 38, 39, 0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 46, 47, 0, 0, 48, 49, 50, 51, 0, 0, 0, 0, 52, 53, 54, 55, 0, 0, 0, 0,
    56, 57, 0, 0, 58, 59, 0, 0, 0, 0, 0, 0, 60, 61, 0, 0, 0, 0, 62, 63, 0, 0, 0,
    0 };

  static const real_T v[63] = { 0.0008656706511046895, 0.0, 0.006957788860168146,
    0.10403043823014252, 0.06533371296864089, 0.0018899846220002039,
    15.413027356360503, 0.272120275234923, 0.0, 0.0047155365866961745,
    0.008323536208832333, -0.052257847917980924, 0.003860887921422776,
    1.1466295808383233, 0.17820763442387802, 0.00144689612226154, 0.0, 0.0, 0.0,
    0.6453382035928144, 0.0027471658343469307, 0.0, 0.0, 0.0, 1.2860801397205588,
    0.17702745358432292, 0.0, 0.0, 0.0, 4.06106805829498, 0.0, 0.0,
    0.0011324154972401157, 0.027370602174429083, 1.9701756886227546, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001793968837830427, 0.0, 1.3426075648702596,
    2.0033936726546906, 0.0, 0.0, 0.24306501069273578, 0.03923576541019389, 0.0,
    0.0, 0.18126917602502302, 0.0, 0.03496386748852046, 0.0, 0.0, 0.0,
    1.8145628343313374, 0.0, 0.0, -0.051299031155173716, 0.0, 0.0 };

  static const boolean_T y[63] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, true,
    true, true, false, false, true, true, true, false, false, true, true, true,
    false, true, true, false, false, false, true, true, true, true, true, true,
    false, true, false, false, true, true, false, false, true, true, false, true,
    false, true, true, true, false, true, true, false, true, true };

  static const real_T ab[252] = { 0.37371937639197883, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.20801781737193875, 0.0, 0.33214793741109533, 0.014992503748125927,
    0.6184032476319367, 0.0, 0.026246719160104962, 0.8891050583657591, 0.0, 0.0,
    0.0, 0.0, 0.5555555555555556, 0.9193548387096777, 0.05555555555555555, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.9764453961456103,
    0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7142857142857143,
    0.9887892376681615, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.5384615384615384, 1.0,
    0.9909706546275395, 0.6666666666666666, 1.0, 0.0, 0.9534883720930233,
    0.9950000000000001, 0.0, 1.0, 0.8461538461538461, 1.0, 0.9873417721518987,
    1.0, 1.0, 0.0, 0.9936305732484078, 0.0, 1.0, 0.9, 1.0, 0.0,
    0.20846325167037974, 0.0, 0.3328591749644381, 0.6161919040479776,
    0.07713125845737476, 0.1678321678321684, 0.9527559055118111,
    0.1108949416342409, 0.0, 0.05220883534136561, 0.9459459459459458,
    0.9779614325068869, 0.4444444444444444, 0.08064516129032225,
    0.9444444444444444, 0.7222222222222222, 0.0, 1.0, 0.0, 0.7058823529411765,
    0.9913294797687862, 0.0, 1.0, 1.0, 0.023554603854389608, 0.8571428571428571,
    1.0, 0.0, 1.0, 0.16666666666666666, 1.0, 0.0, 0.997093023255814,
    0.2857142857142857, 0.011210762331838518, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.46153846153846156, 0.0, 0.009029345372460458, 0.3333333333333333, 0.0, 1.0,
    0.04651162790697672, 0.004999999999999987, 1.0, 0.0, 0.15384615384615385,
    0.0, 0.012658227848101247, 0.0, 0.0, 1.0, 0.0063694267515923475, 1.0, 0.0,
    0.1, 0.0, 1.0, 0.2097995545657027, 0.0, 0.3349928876244666,
    0.3688155922038966, 0.3044654939106886, 0.8321678321678315,
    0.02099737532808397, 0.0, 1.0, 0.9477911646586343, 0.05405405405405405,
    0.02203856749311293, 0.0, 0.0, 0.0, 0.2777777777777778, 1.0, 0.0, 1.0,
    0.29411764705882354, 0.008670520231213872, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.8333333333333334, 0.0, 1.0, 0.002906976744186046, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T db_0[33] = { 3, 0, 4, 9, 5, 8, 1, 0, 3, 3, 0, 0, 10, 5, 0,
    0, 0, 0, 7, 0, 10, 0, 2, 10, 0, 0, 0, 0, 8, 0, 6, 0, 0 };

  static const int8_T eb_0[66] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    0, 0, 14, 15, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 22,
    23, 0, 0, 24, 25, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0,
    32, 33, 0, 0, 0, 0 };

  static const real_T cb[33] = { 0.07767432700643459, 0.0, 1.1813906986027942,
    0.0018650900666421508, 6.554050300738116, 0.002191727285983306,
    0.002627480965802771, 0.0, 0.391801922730153, 0.08349536401579707, 0.0, 0.0,
    0.0005332782999811433, 13.587885304629305, 0.0, 0.0, 0.0, 0.0,
    7.507287988574154, 0.0, 0.03076778500796529, 0.0, 0.14427785802156748,
    0.010351370232154834, 0.0, 0.0, 0.0, 0.0, 0.0028007657976247815, 0.0,
    0.22465801102608512, 0.0, 0.0 };

  static const boolean_T fb[33] = { false, true, false, false, false, false,
    false, true, false, false, true, true, false, false, true, true, true, true,
    false, true, false, true, false, false, true, true, true, true, false, true,
    false, true, true };

  static const real_T gb[132] = { 0.37461024498886086, 1.0,
    0.0007117437722419895, 0.0014814814814814784, 0.0, 0.0,
    0.0021834061135371087, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0021881838074398158, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.20311804008908785, 0.0, 0.3245551601423486,
    0.0014814814814814782, 0.6232876712328785, 0.0, 0.0021834061135371082, 1.0,
    0.44999999999999996, 0.0, 0.0, 0.0, 0.0021881838074398153, 0.865384615384615,
    0.0, 0.0, 0.0, 0.0, 0.002192982456140341, 0.0, 0.9336099585062239, 0.0,
    0.06249999999999999, 0.9574468085106381, 0.0, 0.0, 1.0, 0.0,
    0.9698275862068964, 1.0, 0.72, 1.0, 0.0, 0.22271714922049135, 0.0,
    0.35587188612099674, 0.6888888888888905, 0.04794520547945199,
    0.04608294930875589, 0.9934497816593887, 0.0, 0.07000000000000026,
    0.014285714285714327, 1.0, 0.0, 0.9956236323851204, 0.13461538461538505, 0.0,
    1.0, 0.0, 0.0, 0.9978070175438596, 1.0, 0.06639004149377616, 1.0, 0.9375,
    0.04255319148936185, 1.0, 1.0, 0.0, 1.0, 0.030172413793103554, 0.0, 0.28,
    0.0, 1.0, 0.19955456570155994, 0.0, 0.3188612099644126, 0.30814814814814656,
    0.32876712328766944, 0.9539170506912441, 0.0021834061135371087, 0.0,
    0.4799999999999997, 0.9857142857142857, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const int8_T jb_0[47] = { 10, 0, 9, 9, 4, 10, 1, 6, 0, 9, 4, 2, 9, 10,
    1, 0, 0, 0, 0, 0, 0, 7, 2, 9, 9, 0, 0, 0, 7, 0, 0, 0, 0, 1, 4, 0, 0, 7, 8,
    10, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T kb_0[94] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 36,
    37, 0, 0, 0, 0, 0, 0, 0, 0, 38, 39, 40, 41, 0, 0, 0, 0, 42, 43, 44, 45, 46,
    47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T ib[47] = { 0.0008656706511046895, 0.0,
    0.007207531825943473, 0.0018650900666421508, 2.443633483033932,
    0.004271241762533446, 0.002899244986589325, 0.272120275234923, 0.0,
    0.001320140678547319, 0.6932725948103792, 0.13588407884417292,
    0.006957788860168146, 0.013316699703486225, 0.0040655181141623, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 8.130031114606858, 0.14766804922635457,
    0.01165945940212475, 0.0134493070969684, 0.0, 0.0, 0.0, 8.36331979359906,
    0.0, 0.0, 0.0, 0.0, 0.004245362673091316, 1.220375129740519, 0.0, 0.0,
    6.319662360310239, 0.0012051107135237428, 0.027065816958305722, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T lb[47] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, false, true, true,
    true, true, true, true, false, false, false, false, true, true, true, false,
    true, true, true, true, false, false, true, true, false, false, false, true,
    true, true, true, true, true, true };

  static const real_T mb[188] = { 0.3657015590200414, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.19910913140311884,
    0.0, 0.31390449438202217, 0.0117130307467057, 0.5924426450742257, 0.0,
    0.01801801801801796, 0.8658777120315588, 0.0, 0.0, 0.0, 0.19999999999999998,
    0.01594533029612751, 0.9161425576519919, 0.06666666666666667, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.002358490566037728, 0.4, 0.16666666666666666,
    0.9256900212314227, 1.0, 0.0, 0.0, 0.3333333333333333, 0.0, 1.0, 0.0, 1.0,
    0.7962962962962965, 0.993527508090615, 1.0, 0.0, 0.9838709677419355,
    0.1842105263157895, 0.3333333333333333, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.22538975501113717, 0.0, 0.35533707865168573, 0.6412884333821394,
    0.09176788124156521, 0.025104602510460348, 0.9729729729729731,
    0.13412228796844117, 0.0, 0.8333333333333333, 0.004291845493562249, 0.0,
    0.9840546697038725, 0.08385744234800807, 0.9333333333333333, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.0, 0.9976415094339622, 0.6, 0.8333333333333333,
    0.07430997876857724, 0.0, 1.0, 1.0, 0.6666666666666667, 1.0, 0.0, 1.0, 0.0,
    0.20370370370370358, 0.0064724919093851335, 0.0, 1.0, 0.01612903225806451,
    0.8157894736842106, 0.6666666666666667, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.20979955456570257, 0.0, 0.3307584269662921, 0.3469985358711549,
    0.315789473684209, 0.9748953974895397, 0.00900900900900898, 0.0, 1.0,
    0.16666666666666669, 0.9957081545064378, 0.8, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T pb_0[41] = { 2, 0, 4, 9, 10, 10, 9, 2, 0, 0, 7, 2, 3, 6, 0,
    0, 4, 0, 0, 10, 0, 7, 7, 0, 0, 0, 0, 0, 8, 0, 1, 5, 0, 0, 0, 0, 10, 10, 0, 0,
    0 };

  static const int8_T qb_0[82] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25, 0, 0,
    0, 0, 26, 27, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 33, 0,
    0, 34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 38, 39, 40, 41, 0, 0, 0, 0, 0, 0
  };

  static const real_T ob[41] = { 0.07975784241774386, 0.0, 1.1813906986027942,
    0.001703293833276451, 0.13542646950941317, 0.003910560452860944,
    0.0020201501308521105, 0.269913313995951, 0.0, 0.0, 5.387763369800359,
    0.1186235165560943, 0.11433801096350935, 0.2751489368047294, 0.0, 0.0,
    0.5092285628742514, 0.0, 0.0, 0.009946211242337731, 0.0, 7.209323331729101,
    9.715690042891222, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0044661356690631725, 0.0,
    0.0038833337914015737, 11.6487216573428, 0.0, 0.0, 0.0, 0.0,
    0.02640619878230964, 0.010096738926162146, 0.0, 0.0, 0.0 };

  static const boolean_T rb[41] = { false, true, false, false, false, false,
    false, false, true, true, false, false, false, false, true, true, false,
    true, true, false, true, false, false, true, true, true, true, true, false,
    true, false, false, true, true, true, true, false, false, true, true, true };

  static const real_T sb[164] = { 0.3732739420935379, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.20178173719376485, 0.0, 0.321961620469083, 0.0,
    0.6015936254980099, 0.0, 0.0, 0.8970297029702975, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.8188153310104525, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.917647058823529,
    0.031249999999999997, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9629629629629629, 0.0,
    0.16666666666666666, 0.975, 0.0, 1.0, 0.0, 0.0, 0.9790794979079497,
    0.9915254237288135, 0.0, 0.0, 1.0, 0.20846325167037968, 0.0,
    0.3326226012793177, 0.6360856269113165, 0.06905710491367846,
    0.025000000000000095, 0.9903381642512077, 0.10297029702970247, 0.0, 1.0,
    0.004255319148936188, 0.8181818181818181, 0.9950372208436725,
    0.18118466898954744, 0.0, 0.0, 0.25, 1.0, 0.0, 0.9682539682539683, 1.0,
    0.08235294117647088, 0.96875, 1.0, 0.0, 1.0, 0.0, 1.0, 0.037037037037037174,
    1.0, 0.8333333333333333, 0.025000000000000095, 1.0, 0.0, 1.0, 1.0,
    0.020920502092050288, 0.008474576271186474, 1.0, 1.0, 0.0,
    0.21648106904231748, 0.0, 0.34541577825159936, 0.3639143730886834,
    0.3293492695883116, 0.975, 0.009661835748792246, 0.0, 1.0, 0.0,
    0.9957446808510638, 0.18181818181818182, 0.004962779156327533, 0.0, 0.0, 1.0,
    0.75, 0.0, 1.0, 0.03174603174603179, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T vb_0[37] = { 10, 0, 3, 4, 9, 9, 4, 2, 0, 3, 0, 3, 10, 5, 0,
    0, 0, 1, 1, 0, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 6, 3, 0, 8, 0, 0, 0 };

  static const int8_T wb_0[74] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0, 24, 25,
    26, 27, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    32, 33, 34, 35, 0, 0, 36, 37, 0, 0, 0, 0, 0, 0 };

  static const real_T ub[37] = { 0.000534042222881256, 0.0, 0.1591338520746478,
    0.42028992015968064, 0.06536073956848822, 0.0018110770685009806,
    1.1162542115768463, 0.27196792590360874, 0.0, 0.08506039715532734, 0.0,
    0.11652405274826572, 0.01164547971220281, 13.592733445228966, 0.0, 0.0, 0.0,
    0.0035537602724239024, 0.0028456896168600307, 0.0, 0.0, 0.003635080883155565,
    0.005731784548315324, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.28973273207510536,
    0.24114981451481704, 0.0, 0.004004619752330133, 0.0, 0.0, 0.0 };

  static const boolean_T xb[37] = { false, true, false, false, false, false,
    false, false, true, false, true, false, false, false, true, true, true,
    false, false, true, true, false, false, true, true, true, true, true, true,
    true, false, false, true, false, true, true, true };

  static const real_T yb[148] = { 0.3750556792873018, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.20178173719376488, 0.0, 0.3228795438346399, 0.04782608695652176,
    0.5890603085554013, 0.0, 0.0760368663594469, 0.8659793814432994, 0.0, 0.0,
    0.0, 0.0, 0.868421052631579, 0.7234042553191491, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.037735849056603814, 0.923076923076923, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.943820224719101, 0.9767441860465117, 0.0, 0.988235294117647, 0.0,
    1.0, 0.0, 0.20757238307349773, 0.0, 0.3321454027084818, 0.5811594202898566,
    0.09116409537166881, 0.05468750000000022, 0.891705069124424,
    0.13402061855670047, 0.0, 0.016260162601626084, 1.0, 0.9646464646464646,
    0.13157894736842105, 0.27659574468085096, 0.0, 1.0, 0.0, 0.8354430379746833,
    0.9968454258675078, 1.0, 0.0, 0.9622641509433961, 0.076923076923077, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.05617977528089892, 0.023255813953488393, 1.0,
    0.011764705882352951, 1.0, 0.0, 1.0, 0.21559020044543553, 0.0,
    0.3449750534568783, 0.37101449275362164, 0.31977559607292994,
    0.9453124999999998, 0.03225806451612898, 0.0, 1.0, 0.983739837398374, 0.0,
    0.035353535353535304, 0.0, 0.0, 0.0, 0.0, 1.0, 0.1645569620253167,
    0.0031545741324921213, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T cc[49] = { 9, 3, 2, 9, 1, 4, 0, 0, 0, 10, 1, 5, 4, 0, 0, 9,
    10, 0, 0, 6, 0, 0, 0, 0, 0, 4, 0, 10, 4, 0, 3, 1, 8, 0, 0, 0, 8, 0, 0, 7, 7,
    0, 3, 0, 0, 5, 0, 0, 0 };

  static const int8_T dc[98] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 0, 0,
    0, 0, 0, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 24, 25, 0, 0, 0,
    0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 30, 31, 32, 33, 0, 0,
    34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 0, 0, 42, 43, 44, 45,
    0, 0, 46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0, 0, 0 };

  static const real_T bc[49] = { 0.004042842409235481, 0.07989403455609564,
    0.4370937316035346, 0.001520332098803309, 0.0036979697635978045,
    1.1813906986027942, 0.0, 0.0, 0.0, 0.01216518113565251, 0.01131338820406062,
    14.287324203559105, 2.1614430538922154, 0.0, 0.0, 0.001182699040077461,
    0.010112501710743474, 0.0, 0.0, 0.2751489368047294, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.2860801397205588, 0.0, 0.019146037233003364, 1.9701756886227546, 0.0,
    0.26219563130716717, 0.004726997109297029, 0.003865422385264476, 0.0, 0.0,
    0.0, 0.005253766119131129, 0.0, 0.0, 6.1809410077959495, 6.326476520528919,
    0.0, 0.21112154041551304, 0.0, 0.0, 13.307129804024942, 0.0, 0.0, 0.0 };

  static const boolean_T ec[49] = { false, false, false, false, false, false,
    true, true, true, false, false, false, false, true, true, false, false, true,
    true, false, true, true, true, true, true, false, true, false, false, true,
    false, false, false, true, true, true, false, true, true, false, false, true,
    false, true, true, false, true, true, true };

  static const real_T fc[196] = { 0.37861915367482957, 0.677290836653385, 0.0,
    0.9976525821596244, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.21380846325167163, 0.0, 0.48484848484848725, 0.0, 0.0,
    0.6374501992031896, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01271186440677971,
    0.9226305609284337, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.9298245614035091, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9695121951219514, 0.0, 0.8095238095238095,
    0.9844444444444445, 1.0, 0.6, 0.9887640449438203, 0.6, 0.0, 1.0, 1.0,
    0.9759615384615383, 1.0, 0.0, 0.9805825242718447, 0.5, 1.0,
    0.9310344827586206, 1.0, 0.0, 0.9818181818181818, 0.0, 0.0, 1.0,
    0.2066815144766158, 0.15219123505976176, 0.2757575757575743,
    0.0023474178403756095, 0.46898263027295317, 0.3625498007968104, 0.0, 1.0,
    0.0, 0.013513513513513506, 0.7333333333333333, 0.9872881355932203,
    0.07736943907156635, 0.0, 1.0, 0.9664804469273743, 0.1842105263157897, 1.0,
    0.0, 0.07017543859649089, 1.0, 0.0, 1.0, 0.0, 1.0, 0.030487804878048634, 1.0,
    0.1904761904761905, 0.015555555555555496, 0.0, 0.4, 0.011235955056179733,
    0.4, 1.0, 0.0, 0.0, 0.024038461538461602, 0.0, 1.0, 0.019417475728155394,
    0.5, 0.0, 0.06896551724137939, 0.0, 1.0, 0.018181818181818205, 1.0, 1.0, 0.0,
    0.20089086859688296, 0.1705179282868533, 0.2393939393939384, 0.0,
    0.5310173697270469, 0.0, 1.0, 0.0, 0.0, 0.9864864864864864,
    0.2666666666666667, 0.0, 0.0, 1.0, 0.0, 0.03351955307262574,
    0.8157894736842103, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T ic_0[39] = { 10, 0, 9, 4, 2, 3, 5, 6, 0, 0, 10, 1, 1, 9, 7,
    0, 5, 2, 1, 0, 0, 8, 4, 0, 10, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T jc_0[78] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 26, 27, 28,
    29, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 0, 0, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T hc[39] = { 0.0005340809045944201, 0.0,
    0.007092095439852447, 0.4102404590818363, 0.4415238677481643,
    0.08506039715532734, 17.270805531110884, 0.2813295336039644, 0.0, 0.0,
    0.003968133535574361, 0.003186259327049026, 0.004226327306324849,
    0.010358974149859777, 9.715690042891222, 0.0, 3.5037387391112533,
    0.13844567828714052, 0.014296018314932641, 0.0, 0.0, 0.0014045045623220314,
    1.1851267065868263, 0.0, 0.017706418628682996, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.181226950285357, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T kc[39] = { false, true, false, false, false, false,
    false, false, true, true, false, false, false, false, false, true, false,
    false, false, true, true, false, false, true, false, true, true, true, true,
    true, false, true, true, true, true, true, true, true, true };

  static const real_T lc[156] = { 0.36748329621380527, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.20534521158129268, 0.0, 0.3246478873239435,
    0.014792899408284006, 0.6061827956989266, 0.0, 0.02164502164502157,
    0.8948412698412703, 0.0, 0.0, 0.0, 0.0, 0.8333333333333333,
    0.9238683127572019, 0.11111111111111112, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.6458333333333329, 0.9923076923076923, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.21959910913140432, 0.0,
    0.3471830985915495, 0.6508875739644987, 0.07123655913978479,
    0.037383177570093566, 0.9350649350649353, 0.10515873015872966, 0.0, 1.0,
    0.019047619047619105, 0.9555555555555557, 0.16666666666666669,
    0.07613168724279806, 0.888888888888889, 1.0, 0.009615384615384644, 0.15,
    0.9930232558139536, 0.0, 1.0, 0.354166666666667, 0.00769230769230768, 1.0,
    0.5, 0.0, 1.0, 0.0, 1.0, 1.0, 0.7857142857142858, 0.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 0.0, 0.20757238307349762, 0.0, 0.328169014084507,
    0.3343195266272173, 0.32258064516128865, 0.9626168224299064,
    0.04329004329004314, 0.0, 1.0, 0.0, 0.980952380952381, 0.044444444444444293,
    0.0, 0.0, 0.0, 0.0, 0.9903846153846153, 0.8500000000000001,
    0.006976744186046488, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.21428571428571427, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T oc_0[53] = { 3, 0, 2, 10, 4, 9, 4, 6, 0, 8, 1, 4, 8, 9, 1,
    3, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 8, 4, 0, 0, 4, 9, 0, 0,
    3, 4, 0, 0, 7, 7, 0, 10, 0, 0, 0, 0 };

  static const int8_T pc_0[106] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0,
    0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 40, 41, 42, 43, 0, 0,
    0, 0, 44, 45, 46, 47, 0, 0, 0, 0, 48, 49, 50, 51, 0, 0, 52, 53, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const real_T nc[53] = { 0.08017520194247463, 0.0, 0.15921860091774723,
    0.009512832542903766, 2.4011160878243514, 0.0016783910275045145,
    1.1118684630738522, 0.2751489368047294, 0.0, 0.00235936617402768,
    0.003482700088105038, 0.3939002594810379, 0.001915335805846115,
    0.006959668334457173, 0.0037150294235747273, 0.08349536401579707, 0.0, 0.0,
    0.0, 0.0, 0.0028456896168600307, 0.0, 0.0, 0.0, 1.1813906986027942, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2614712175648704, 0.0036438802647299697,
    1.2860801397205588, 0.0, 0.0, 1.283562395209581, 0.007822807745310393, 0.0,
    0.0, 0.19647263527782755, 1.8239840718562874, 0.0, 0.0, 8.645059929613632,
    8.146784382239858, 0.0, 0.026172363190813595, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T qc[53] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, false, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, true, true,
    false, false, true, true, false, false, true, false, true, true, true, true
  };

  static const real_T rc[212] = { 0.36837416481068724, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.21380846325167152, 0.0, 0.33850493653032443, 0.04796511627906977,
    0.6123287671232894, 0.0, 0.09455587392550166, 0.8886679920477143, 0.0, 0.0,
    0.0, 0.0, 0.8918918918918919, 0.919421487603306, 0.10526315789473685, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.9528907922912208, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9845132743362832, 0.7272727272727273,
    0.9909297052154195, 0.0, 1.0, 0.9090909090909091, 0.9930232558139536, 1.0,
    0.0, 0.9166666666666666, 0.9952153110047848, 1.0, 0.0, 0.9974489795918366,
    0.9615384615384616, 1.0, 0.988235294117647, 0.0, 1.0, 1.0, 0.0,
    0.20846325167037966, 0.0, 0.3300423131170662, 0.5988372093023272,
    0.0767123287671231, 0.29498525073746396, 0.8939828080229223,
    0.11133200795228575, 0.0, 0.03252032520325216, 0.9892473118279569,
    0.9871794871794871, 0.1081081081081081, 0.08057851239669389,
    0.8947368421052633, 0.008333333333333366, 1.0, 0.0, 1.0, 0.0,
    0.9935483870967743, 0.0, 1.0, 1.0, 0.047109207708779265, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.015486725663716753, 0.2727272727272727,
    0.009070294784580466, 1.0, 0.0, 0.09090909090909091, 0.006976744186046489,
    0.0, 1.0, 0.08333333333333334, 0.004784688995215298, 0.0, 1.0,
    0.0025510204081632608, 0.038461538461538464, 0.0, 0.011764705882352951, 1.0,
    0.0, 0.0, 1.0, 0.20935412026726163, 0.0, 0.33145275035260924,
    0.3531976744186031, 0.31095890410958754, 0.705014749262536,
    0.011461318051575959, 0.0, 1.0, 0.9674796747967478, 0.010752688172043017,
    0.012820512820512858, 0.0, 0.0, 0.0, 0.9916666666666666, 0.0, 1.0, 0.0, 1.0,
    0.006451612903225826, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T uc[49] = { 10, 0, 10, 3, 0, 3, 3, 10, 4, 5, 0, 9, 4, 1, 1,
    1, 10, 0, 0, 4, 1, 0, 9, 7, 8, 0, 0, 6, 0, 0, 8, 0, 0, 3, 0, 0, 0, 0, 0, 8,
    0, 0, 0, 0, 0, 0, 3, 0, 0 };

  static const int8_T vc[98] = { 2, 3, 0, 0, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0,
    0, 0, 0, 30, 31, 32, 33, 0, 0, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 40, 41, 0,
    0, 0, 0, 42, 43, 0, 0, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 47, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0 };

  static const real_T tc[49] = { 0.0005339367479995261, 0.0, 0.139048353125652,
    0.1590974729565343, 0.0, 0.10416087957178816, 0.27008602414732896,
    0.004552249819849776, 1.1814719161676646, 14.002610371028432, 0.0,
    0.0014476804064122153, 0.45793197604790414, 0.0028456896168600307,
    0.004044341268634604, 0.003684017638551023, 0.02684018036423489, 0.0, 0.0,
    0.377777744510978, 0.00339422288236028, 0.0, 0.0018753334578075656,
    7.862003021166657, 0.001915335805846115, 0.0, 0.0, 0.38653411465909554, 0.0,
    0.0, 0.0018779256612374198, 0.0, 0.0, 0.10487832714524978, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0036754416854231035, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.1831641870157905, 0.0, 0.0 };

  static const boolean_T wc[49] = { false, true, false, false, true, false,
    false, false, false, false, true, false, false, false, false, false, false,
    true, true, false, false, true, false, false, false, true, true, false, true,
    true, false, true, true, false, true, true, true, true, true, false, true,
    true, true, true, true, true, false, true, true };

  static const real_T xc[196] = { 0.35367483296213514, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.21380846325167127, 0.0, 0.3308063404548586, 0.39441248972884213, 0.0,
    0.045714285714285714, 0.8665377176015481, 0.0, 0.07655502392344492,
    0.7561837455830386, 1.0, 0.0, 0.0, 0.0, 0.7441860465116279,
    0.05084745762711871, 0.9419642857142855, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.96,
    0.4444444444444445, 1.0, 0.0, 0.9768518518518517, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.9952830188679246, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.7500000000000001, 0.0, 1.0, 0.21603563474387621, 0.0,
    0.3342522398345968, 0.3985209531635176, 0.0, 0.594285714285716,
    0.13346228239845193, 0.1560283687943267, 0.8899521531100478,
    0.24381625441696136, 0.0, 0.9393939393939393, 0.05220883534136566,
    0.9626666666666666, 0.25581395348837205, 0.9491525423728814,
    0.058035714285714454, 0.0, 1.0, 0.004291845493562248, 0.75, 0.0,
    0.9809782608695652, 0.039999999999999994, 0.5555555555555556, 0.0, 1.0,
    0.023148148148148216, 1.0, 0.0, 0.022222222222222237, 0.0, 1.0,
    0.12499999999999999, 1.0, 1.0, 0.0, 0.0, 1.0, 0.004716981132075486, 1.0, 0.0,
    1.0, 1.0, 0.0, 0.0, 0.25, 1.0, 0.0, 0.2164810690423172, 0.0,
    0.3349414197105444, 0.20706655710764013, 1.0, 0.3599999999999984, 0.0,
    0.8439716312056733, 0.03349282296650715, 0.0, 0.0, 0.06060606060606061,
    0.9477911646586343, 0.03733333333333332, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.9957081545064378, 0.25, 1.0, 0.019021739130434777, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.9777777777777779, 1.0, 0.0, 0.875, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T bd[53] = { 3, 0, 4, 4, 3, 9, 9, 4, 0, 8, 0, 1, 0, 2, 2, 2,
    0, 0, 1, 6, 5, 0, 10, 0, 0, 0, 0, 0, 0, 0, 5, 0, 6, 0, 0, 9, 10, 7, 9, 10, 0,
    0, 0, 3, 9, 0, 0, 0, 0, 9, 0, 0, 0 };

  static const int8_T cd[106] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0,
    26, 27, 28, 29, 30, 31, 0, 0, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 34, 35, 0, 0, 36, 37, 0, 0, 0, 0, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    0, 0, 0, 0, 0, 0, 48, 49, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 52, 53, 0, 0, 0, 0,
    0, 0 };

  static const real_T ad[53] = { 0.08012190595190324, 0.0, 1.1813906986027942,
    0.42028992015968064, 0.4370204932144296, 0.0017503001345564768,
    0.0018753334578075656, 1.2862425748502995, 0.0, 0.002330103305554363, 0.0,
    0.0036639274575848307, 0.0, 0.15458642564778705, 0.13974919346338743,
    0.08453163486010447, 0.0, 0.0, 0.007981961077844305, 0.36331672355297767,
    6.112233754950803, 0.0, 0.011820951850340286, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 13.773563367519277, 0.0, 0.28547001187208587, 0.0, 0.0,
    0.0072670164197668405, 0.019011351886857958, 8.154198727016286,
    0.008222611991904412, 0.015468751229193202, 0.0, 0.0, 0.0,
    0.1841782554262109, 0.01143659449104904, 0.0, 0.0, 0.0, 0.0,
    0.011333859103988788, 0.0, 0.0, 0.0 };

  static const boolean_T dd[53] = { false, true, false, false, false, false,
    false, false, true, false, true, false, true, false, false, false, true,
    true, false, false, false, true, false, true, true, true, true, true, true,
    true, false, true, false, true, true, false, false, false, false, false,
    true, true, true, false, false, true, true, true, true, false, true, true,
    true };

  static const real_T ed[212] = { 0.3594654788418678, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.22138084632516816, 0.0, 0.3456189151599446, 0.0,
    0.6143386897404226, 0.0, 0.0, 0.908592321755028, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.5434782608695652, 0.9421157684630741, 0.0, 0.0, 0.0, 0.0, 0.9375,
    0.33333333333333337, 0.0, 0.9458917835671345, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 0.0909090909090909, 0.0, 0.9554655870445347, 0.0, 1.0,
    0.9812500000000001, 0.07142857142857142, 0.6428571428571429,
    0.9914163090128756, 0.3333333333333333, 0.0, 0.0, 1.0, 0.9047619047619048,
    0.9955056179775281, 0.0, 1.0, 1.0, 0.0, 0.9672131147540983, 1.0, 1.0, 0.0,
    0.20623608017817457, 0.0, 0.32197496522948527, 0.6565977742448343,
    0.06180469715698375, 0.05660377358490581, 0.9616306954436452,
    0.09140767824497202, 0.0, 0.014778325123152749, 1.0, 0.23809523809523808,
    1.0, 0.45652173913043476, 0.05788423153692589, 0.0049751243781094665, 1.0,
    0.0, 0.8333333333333333, 0.0625, 0.6666666666666667, 1.0,
    0.05410821643286549, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.9090909090909091,
    1.0, 0.04453441295546538, 1.0, 0.0, 0.01874999999999991, 0.9285714285714286,
    0.35714285714285715, 0.008583690987124425, 0.6666666666666667, 1.0, 1.0, 0.0,
    0.09523809523809525, 0.004494382022471893, 1.0, 0.0, 0.0, 1.0,
    0.03278688524590169, 0.0, 0.0, 1.0, 0.2129175946547894, 0.0,
    0.33240611961057026, 0.34340222575516555, 0.32385661310259367,
    0.9433962264150942, 0.03836930455635484, 0.0, 1.0, 0.9852216748768473, 0.0,
    0.761904761904762, 0.0, 0.0, 0.0, 0.9950248756218906, 0.0, 1.0,
    0.16666666666666666, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T hd[47] = { 9, 10, 9, 0, 3, 4, 0, 10, 1, 0, 6, 1, 3, 5, 1,
    10, 0, 0, 0, 0, 9, 0, 0, 9, 0, 4, 9, 0, 0, 0, 5, 1, 8, 0, 0, 0, 1, 0, 7, 7,
    0, 0, 0, 0, 0, 0, 0 };

  static const int8_T id[94] = { 2, 3, 4, 5, 6, 7, 0, 0, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0,
    0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 30, 31, 0, 0, 32, 33, 34, 35, 0, 0, 0, 0, 0,
    0, 36, 37, 38, 39, 40, 41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0, 44, 45, 46, 47, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T gd[47] = { 0.006479335900058198, 0.0008656706511046895,
    0.06536073956848822, 0.0, 0.10482587470186608, 1.1814719161676646, 0.0,
    0.004425948601649123, 0.0031426200821014225, 0.0, 0.30232602109322,
    0.003298257128321481, 0.08699241727564032, 11.674505000930873,
    0.016029523511570613, 0.045955506970112664, 0.0, 0.0, 0.0, 0.0,
    0.001753934765490502, 0.0, 0.0, 0.001433414236580562, 0.0,
    1.3041104391217564, 0.024625254903270423, 0.0, 0.0, 0.0, 14.730967342641563,
    0.004524706680389222, 0.002049070407517022, 0.0, 0.0, 0.0,
    0.004023957563388844, 0.0, 5.295848433209889, 7.065140010787314, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T jd[47] = { false, false, false, true, false, false,
    true, false, false, true, false, false, false, false, false, false, true,
    true, true, true, false, true, true, false, true, false, false, true, true,
    true, false, false, false, true, true, true, false, true, false, false, true,
    true, true, true, true, true, true };

  static const real_T kd[188] = { 0.35233853006681226, 0.5451412818745675, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.224053452115814, 0.0027567195037905, 0.6284634760705311, 0.0,
    0.00606060606060606, 0.8894830659536549, 0.0, 0.0, 0.01023017902813298, 0.0,
    0.9468690702087289, 0.0, 0.0, 0.25000000000000006, 0.007751937984496114,
    0.9727095516569202, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.007772020725388591,
    0.0, 0.9825327510917032, 0.8909090909090908, 0.0, 0.0, 0.0,
    0.00783289817232375, 0.7777777777777778, 0.9953596287703017, 0.0, 1.0, 0.0,
    0.21428571428571427, 1.0, 0.4, 0.9885057471264367, 1.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.21202672605790732, 0.2853204686423176, 0.07808564231738005, 0.0,
    0.6272727272727289, 0.11051693404634509, 0.0, 0.1263940520446101,
    0.9718670076726342, 1.0, 0.05313092979127106, 0.9642857142857143,
    0.02904564315352708, 0.0, 0.9819121447028424, 0.02729044834307977, 1.0, 0.0,
    1.0, 1.0, 0.020920502092050288, 0.0, 0.0, 0.9844559585492229, 0.0,
    0.017467248908296873, 0.10909090909090918, 0.0, 1.0, 0.0, 0.9921671018276763,
    0.2222222222222222, 0.004640371229698361, 1.0, 0.0, 1.0, 0.7857142857142857,
    0.0, 0.6, 0.011494252873563232, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.21158129175946633, 0.16678152997932455, 0.2934508816120889, 0.0,
    0.3666666666666651, 0.0, 1.0, 0.8736059479553898, 0.017902813299232715, 0.0,
    0.0, 0.03571428571428571, 0.9709543568464729, 0.7499999999999999,
    0.010335917312661485, 0.0, 0.0, 1.0, 0.0, 0.0, 0.9790794979079497, 1.0, 0.0,
    0.0077720207253885905, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T nd_0[59] = { 2, 0, 9, 4, 5, 8, 1, 2, 9, 9, 1, 10, 5, 0, 0,
    5, 0, 10, 0, 0, 0, 0, 7, 2, 6, 0, 6, 0, 0, 0, 0, 3, 0, 8, 0, 7, 6, 0, 0, 0,
    0, 0, 5, 4, 0, 8, 7, 0, 0, 1, 0, 1, 0, 0, 10, 0, 0, 0, 0 };

  static const int8_T od_0[118] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 26, 27, 0, 0, 28,
    29, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 34, 35, 0, 0, 36, 37, 0, 0, 0, 0,
    0, 0, 0, 0, 38, 39, 0, 0, 40, 41, 0, 0, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 46, 47, 48, 49, 0, 0, 50, 51, 52, 53, 0, 0, 0, 0, 54, 55, 0, 0, 56,
    57, 0, 0, 0, 0, 58, 59, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T md[59] = { 0.07974410951441725, 0.0, 0.007085046280946148,
    0.42028992015968064, 6.23281855964949, 0.0019613331952087936,
    0.003186259327049026, 0.23245838158023477, 0.05131167115093193,
    0.0019066569319939196, 0.008323536208832333, 0.01135574160908176,
    14.83457930750589, 0.0, 0.0, 12.00904301326792, 0.0, 0.004226481526399742,
    0.0, 0.0, 0.0, 0.0, 5.917310195066335, 0.10711747649432155,
    0.12924872705914622, 0.0, 0.30232602109322, 0.0, 0.0, 0.0, 0.0,
    0.10713822615451046, 0.0, 0.002106507897150903, 0.0, 7.19426157981164,
    0.35522608593510846, 0.0, 0.0, 0.0, 0.0, 0.0, 26.491178304614543,
    1.6650412974051896, 0.0, 0.004705373012251836, 10.098959427280327, 0.0, 0.0,
    0.0047839842385541415, 0.0, 0.015009267724316998, 0.0, 0.0,
    0.025743161919558534, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T pd[59] = { false, true, false, false, false, false,
    false, false, false, false, false, false, false, true, true, false, true,
    false, true, true, true, true, false, false, false, true, false, true, true,
    true, true, false, true, false, true, false, false, true, true, true, true,
    true, false, false, true, false, false, true, true, false, true, false, true,
    true, false, true, true, true, true };

  static const real_T qd[236] = { 0.38619153674832607, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.19643652561247316, 0.0,
    0.32002902757619717, 0.017316017316017306, 0.6262773722627751, 0.0,
    0.027334851936218603, 0.9734513274336283, 0.4553376906318082, 0.0, 0.0,
    0.4666666666666667, 0.011792452830188647, 0.0, 1.0, 0.8228346456692911, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.875, 0.0, 0.45454545454545453, 0.0,
    0.9288888888888887, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.8333333333333333, 0.0,
    0.9719626168224299, 0.09090909090909091, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.976525821596244, 0.5000000000000001, 0.0, 0.985, 0.8461538461538461, 0.0,
    1.0, 0.9899497487437185, 0.0, 0.33333333333333337, 1.0, 1.0,
    0.9672131147540983, 0.0, 1.0, 1.0, 0.0, 0.2160356347438767, 0.0,
    0.3519593613933239, 0.6262626262626281, 0.07445255474452538,
    0.07086614173228373, 0.947608200455581, 0.02654867256637177,
    0.0980392156862747, 0.02118644067796618, 0.7222222222222223,
    0.06666666666666667, 0.9787735849056605, 1.0, 0.0, 0.17716535433070899, 0.0,
    0.004310344827586223, 1.0, 1.0, 0.0, 0.0, 0.12499999999999999,
    0.9903147699757869, 0.5454545454545454, 1.0, 0.07111111111111132, 1.0, 0.0,
    1.0, 0.0, 0.875, 1.0, 0.16666666666666666, 1.0, 0.028037383177570176,
    0.9090909090909091, 1.0, 0.0, 0.0, 1.0, 1.0, 0.023474178403755937, 0.5, 1.0,
    0.015000000000000034, 0.15384615384615383, 1.0, 0.0, 0.010050251256281431,
    1.0, 0.6666666666666666, 0.0, 0.0, 0.03278688524590168, 1.0, 0.0, 0.0, 1.0,
    0.20133630289532403, 0.0, 0.3280116110304788, 0.35642135642135464,
    0.29927007299269953, 0.9291338582677162, 0.025056947608200385, 0.0,
    0.44662309368191716, 0.9788135593220338, 0.2777777777777778,
    0.4666666666666667, 0.009433962264150919, 0.0, 0.0, 0.0, 1.0,
    0.9956896551724138, 0.0, 0.0, 1.0, 1.0, 0.0, 0.009685230024213051, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.125, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const int8_T td_0[45] = { 2, 0, 4, 9, 9, 2, 1, 4, 0, 1, 10, 0, 5, 2, 5,
    0, 0, 0, 0, 0, 2, 10, 0, 0, 6, 0, 0, 5, 0, 0, 2, 9, 2, 0, 0, 0, 0, 0, 1, 0,
    5, 0, 1, 0, 0 };

  static const int8_T ud_0[90] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 32, 33, 0, 0, 0,
    0, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 0, 0, 42,
    43, 0, 0, 44, 45, 0, 0, 0, 0 };

  static const real_T sd[45] = { 0.07944453635367484, 0.0, 1.1823653093812374,
    0.0017260388163948303, 0.06526905318331727, 0.08661261356747518,
    0.0031711545853605307, 1.8312124351297405, 0.0, 0.00332732571965444,
    0.004717683298627148, 0.0, 14.537555566161597, 0.2628691611283199,
    19.504894587052483, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1429052902447571,
    0.0267719126513228, 0.0, 0.0, 0.22201301950129432, 0.0, 0.0,
    13.587885304629305, 0.0, 0.0, 0.1941179766662685, 0.011315727788647888,
    0.13974919346338743, 0.0, 0.0, 0.0, 0.0, 0.0, 0.004181316595324979, 0.0,
    16.649365058576084, 0.0, 0.004182545962761975, 0.0, 0.0 };

  static const boolean_T vd[45] = { false, true, false, false, false, false,
    false, false, true, false, false, true, false, false, false, true, true,
    true, true, true, false, false, true, true, false, true, true, false, true,
    true, false, false, false, true, true, true, true, true, false, true, false,
    true, false, true, true };

  static const real_T wd[180] = { 0.36703786191536436, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.21737193763919932, 0.0,
    0.3434201266713583, 0.0030075187969924788, 0.6428571428571449, 0.0,
    0.004739336492890979, 0.9328214971209217, 0.0, 0.0, 0.0, 0.0,
    0.004796163069544348, 0.94908350305499, 0.6666666666666666, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.24999999999999997, 0.8987854251012143, 1.0, 0.0,
    0.9090909090909091, 0.0, 1.0, 0.9367088607594934, 0.0, 1.0,
    0.3333333333333333, 0.08333333333333333, 0.9822222222222221, 1.0, 0.0, 0.0,
    1.0, 0.0, 0.9866071428571428, 1.0, 0.9620253164556962, 0.0,
    0.9870129870129869, 0.0, 1.0, 0.20267260579064683, 0.0, 0.3201970443349753,
    0.6315789473684229, 0.046296296296296204, 0.02057613168724288,
    0.9834123222748817, 0.06717850287907838, 0.0, 0.8, 0.004201680672268926, 0.0,
    0.9952038369304557, 0.050916496945009965, 0.33333333333333337, 0.0, 1.0, 1.0,
    0.0, 1.0, 0.75, 0.10121457489878577, 0.0, 1.0, 0.09090909090909093, 1.0, 0.0,
    0.06329113924050654, 1.0, 0.0, 0.6666666666666666, 0.9166666666666666,
    0.01777777777777784, 0.0, 1.0, 1.0, 0.0, 1.0, 0.01339285714285719, 0.0,
    0.03797468354430386, 1.0, 0.012987012987013007, 1.0, 0.0,
    0.21291759465478943, 0.0, 0.3363828289936664, 0.36541353383458464,
    0.31084656084655893, 0.9794238683127571, 0.011848341232227447, 0.0, 1.0,
    0.19999999999999998, 0.9957983193277311, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T unusedExpr[4];
  cachedScore[0] = 0.0;
  cachedScore[1] = 0.0;
  cachedScore[2] = 0.0;
  cachedScore[3] = 0.0;
  cachedWeights = 0.0;
  b = false;
  for (i = 0; i < 16; i++) {
    assign_temp_Cost[i] = i_0[i];
  }

  for (i = 0; i < 49; i++) {
    d[i] = d_0[i];
  }

  for (i = 0; i < 98; i++) {
    e[i] = e_0[i];
  }

  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    c, f, assign_temp_Cost, g, &b, true, unusedExpr);
  b = obj_IsCached[1];
  for (i = 0; i < 31; i++) {
    k[i] = k_0[i];
  }

  for (i = 0; i < 62; i++) {
    l[i] = l_0[i];
  }

  MotorFaul_predictOneWithCache_o(X, cachedScore, &cachedWeights, combiner, k, l,
    j, m, assign_temp_Cost, n, &b, unusedExpr);
  b = obj_IsCached[2];
  for (i = 0; i < 29; i++) {
    q[i] = q_0[i];
  }

  for (i = 0; i < 58; i++) {
    r[i] = r_0[i];
  }

  MotorFau_predictOneWithCache_o2(X, cachedScore, &cachedWeights, combiner, q, r,
    p, s, assign_temp_Cost, t, &b, unusedExpr);
  b = obj_IsCached[3];
  for (i = 0; i < 63; i++) {
    w[i] = w_0[i];
  }

  for (i = 0; i < 126; i++) {
    x[i] = x_0[i];
  }

  MotorFa_predictOneWithCache_o22(X, cachedScore, &cachedWeights, combiner, w, x,
    v, y, assign_temp_Cost, ab, &b, unusedExpr);
  b = obj_IsCached[4];
  for (i = 0; i < 33; i++) {
    db[i] = db_0[i];
  }

  for (i = 0; i < 66; i++) {
    eb[i] = eb_0[i];
  }

  MotorF_predictOneWithCache_o22p(X, cachedScore, &cachedWeights, combiner, db,
    eb, cb, fb, assign_temp_Cost, gb, &b, unusedExpr);
  b = obj_IsCached[5];
  for (i = 0; i < 47; i++) {
    jb[i] = jb_0[i];
  }

  for (i = 0; i < 94; i++) {
    kb[i] = kb_0[i];
  }

  Motor_predictOneWithCache_o22p4(X, cachedScore, &cachedWeights, combiner, jb,
    kb, ib, lb, assign_temp_Cost, mb, &b, unusedExpr);
  b = obj_IsCached[6];
  for (i = 0; i < 41; i++) {
    pb[i] = pb_0[i];
  }

  for (i = 0; i < 82; i++) {
    qb[i] = qb_0[i];
  }

  Moto_predictOneWithCache_o22p4v(X, cachedScore, &cachedWeights, combiner, pb,
    qb, ob, rb, assign_temp_Cost, sb, &b, unusedExpr);
  b = obj_IsCached[7];
  for (i = 0; i < 37; i++) {
    vb[i] = vb_0[i];
  }

  for (i = 0; i < 74; i++) {
    wb[i] = wb_0[i];
  }

  Mot_predictOneWithCache_o22p4vs(X, cachedScore, &cachedWeights, combiner, vb,
    wb, ub, xb, assign_temp_Cost, yb, &b, unusedExpr);
  b = obj_IsCached[8];
  for (i = 0; i < 49; i++) {
    d[i] = cc[i];
  }

  for (i = 0; i < 98; i++) {
    e[i] = dc[i];
  }

  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    bc, ec, assign_temp_Cost, fc, &b, false, unusedExpr);
  b = obj_IsCached[9];
  for (i = 0; i < 39; i++) {
    ic[i] = ic_0[i];
  }

  for (i = 0; i < 78; i++) {
    jc[i] = jc_0[i];
  }

  Mo_predictOneWithCache_o22p4vsu(X, cachedScore, &cachedWeights, combiner, ic,
    jc, hc, kc, assign_temp_Cost, lc, &b, unusedExpr);
  b = obj_IsCached[10];
  for (i = 0; i < 53; i++) {
    oc[i] = oc_0[i];
  }

  for (i = 0; i < 106; i++) {
    pc[i] = pc_0[i];
  }

  M_predictOneWithCache_o22p4vsub(X, cachedScore, &cachedWeights, combiner, oc,
    pc, nc, qc, assign_temp_Cost, rc, &b, unusedExpr);
  b = obj_IsCached[11];
  for (i = 0; i < 49; i++) {
    d[i] = uc[i];
  }

  for (i = 0; i < 98; i++) {
    e[i] = vc[i];
  }

  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    tc, wc, assign_temp_Cost, xc, &b, false, unusedExpr);
  b = obj_IsCached[12];
  for (i = 0; i < 53; i++) {
    oc[i] = bd[i];
  }

  for (i = 0; i < 106; i++) {
    pc[i] = cd[i];
  }

  M_predictOneWithCache_o22p4vsub(X, cachedScore, &cachedWeights, combiner, oc,
    pc, ad, dd, assign_temp_Cost, ed, &b, unusedExpr);
  b = obj_IsCached[13];
  for (i = 0; i < 47; i++) {
    jb[i] = hd[i];
  }

  for (i = 0; i < 94; i++) {
    kb[i] = id[i];
  }

  Motor_predictOneWithCache_o22p4(X, cachedScore, &cachedWeights, combiner, jb,
    kb, gd, jd, assign_temp_Cost, kd, &b, unusedExpr);
  b = obj_IsCached[14];
  for (i = 0; i < 59; i++) {
    nd[i] = nd_0[i];
  }

  for (i = 0; i < 118; i++) {
    od[i] = od_0[i];
  }

  predictOneWithCache_o22p4vsubw(X, cachedScore, &cachedWeights, combiner, nd,
    od, md, pd, assign_temp_Cost, qd, &b, unusedExpr);
  b = obj_IsCached[15];
  for (i = 0; i < 45; i++) {
    td[i] = td_0[i];
  }

  for (i = 0; i < 90; i++) {
    ud[i] = ud_0[i];
  }

  predictOneWithCache_o22p4vsubwb(X, cachedScore, &cachedWeights, combiner, td,
    ud, sd, vd, assign_temp_Cost, wd, &b, unusedExpr);
  b = obj_IsCached[16];
  CompactClassificationTree_Compa(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint, assign_temp_NanCutPoints,
    expl_temp, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability);
  predictOneWithCach_o22p4vsubwbf(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint,
    assign_temp_NanCutPoints, assign_temp_Cost, assign_temp_ClassProbability, &b,
    unusedExpr);
  b = obj_IsCached[17];
  CompactClassificationTree_Com_g(ic, jc, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  Mo_predictOneWithCache_o22p4vsu(X, cachedScore, &cachedWeights, combiner, ic,
    jc, assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[18];
  CompactClassificationTree_Co_gk(oc, pc, assign_temp_CutPoint_1,
    assign_temp_NanCutPoints_1, expl_temp_4, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_1);
  M_predictOneWithCache_o22p4vsub(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_1, assign_temp_NanCutPoints_1, assign_temp_Cost,
    assign_temp_ClassProbability_1, &b, unusedExpr);
  b = obj_IsCached[19];
  CompactClassificationTree_C_gkd(assign_temp_CutPredictorIndex_0,
    assign_temp_Children_0, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2,
    expl_temp_5, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_2);
  predictOneWithCac_o22p4vsubwbfs(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_0, assign_temp_Children_0,
    assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[20];
  CompactClassificationTree__gkd2(d, e, assign_temp_CutPoint_3,
    assign_temp_NanCutPoints_3, expl_temp_6, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_3);
  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, false, unusedExpr);
  b = obj_IsCached[21];
  CompactClassificationTree_gkd2u(td, ud, assign_temp_CutPoint_4,
    assign_temp_NanCutPoints_4, expl_temp_7, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_4);
  predictOneWithCache_o22p4vsubwb(X, cachedScore, &cachedWeights, combiner, td,
    ud, assign_temp_CutPoint_4, assign_temp_NanCutPoints_4, assign_temp_Cost,
    assign_temp_ClassProbability_4, &b, unusedExpr);
  b = obj_IsCached[22];
  CompactClassificationTre_gkd2u4(jb, kb, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  Motor_predictOneWithCache_o22p4(X, cachedScore, &cachedWeights, combiner, jb,
    kb, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[23];
  CompactClassificationTr_gkd2u4z(k, l, assign_temp_CutPoint_6,
    assign_temp_NanCutPoints_6, expl_temp_9, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_6);
  MotorFaul_predictOneWithCache_o(X, cachedScore, &cachedWeights, combiner, k, l,
    assign_temp_CutPoint_6, assign_temp_NanCutPoints_6, assign_temp_Cost,
    assign_temp_ClassProbability_6, &b, unusedExpr);
  b = obj_IsCached[24];
  CompactClassificationT_gkd2u4zd(ic, jc, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  Mo_predictOneWithCache_o22p4vsu(X, cachedScore, &cachedWeights, combiner, ic,
    jc, assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[25];
  CompactClassification_gkd2u4zdv(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[26];
  CompactClassificatio_gkd2u4zdvp(oc, pc, assign_temp_CutPoint_1,
    assign_temp_NanCutPoints_1, expl_temp_4, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_1);
  M_predictOneWithCache_o22p4vsub(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_1, assign_temp_NanCutPoints_1, assign_temp_Cost,
    assign_temp_ClassProbability_1, &b, unusedExpr);
  b = obj_IsCached[27];
  CompactClassificati_gkd2u4zdvpw(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[28];
  CompactClassificat_gkd2u4zdvpwa(td, ud, assign_temp_CutPoint_4,
    assign_temp_NanCutPoints_4, expl_temp_7, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_4);
  predictOneWithCache_o22p4vsubwb(X, cachedScore, &cachedWeights, combiner, td,
    ud, assign_temp_CutPoint_4, assign_temp_NanCutPoints_4, assign_temp_Cost,
    assign_temp_ClassProbability_4, &b, unusedExpr);
  b = obj_IsCached[29];
  CompactClassifica_gkd2u4zdvpwal(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[30];
  CompactClassific_gkd2u4zdvpwala(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint, assign_temp_NanCutPoints,
    expl_temp, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability);
  predictOneWithCach_o22p4vsubwbf(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint,
    assign_temp_NanCutPoints, assign_temp_Cost, assign_temp_ClassProbability, &b,
    unusedExpr);
  b = obj_IsCached[31];
  CompactClassifi_gkd2u4zdvpwalat(assign_temp_CutPredictorIndex_2,
    assign_temp_Children_2, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8,
    expl_temp_b, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_8);
  predictOneWithC_o22p4vsubwbfsdz(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_2, assign_temp_Children_2,
    assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[32];
  CompactClassificationTree_Com_k(d, e, assign_temp_CutPoint_3,
    assign_temp_NanCutPoints_3, expl_temp_6, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_3);
  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, false, unusedExpr);
  b = obj_IsCached[33];
  CompactClassificationTree_Com_o(jb, kb, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  Motor_predictOneWithCache_o22p4(X, cachedScore, &cachedWeights, combiner, jb,
    kb, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[34];
  CompactClassificationTree_Com_e(vb, wb, assign_temp_CutPoint_9,
    assign_temp_NanCutPoints_9, expl_temp_c, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_9);
  Mot_predictOneWithCache_o22p4vs(X, cachedScore, &cachedWeights, combiner, vb,
    wb, assign_temp_CutPoint_9, assign_temp_NanCutPoints_9, assign_temp_Cost,
    assign_temp_ClassProbability_9, &b, unusedExpr);
  b = obj_IsCached[35];
  CompactClassificationTree_Co_ej(td, ud, assign_temp_CutPoint_4,
    assign_temp_NanCutPoints_4, expl_temp_7, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_4);
  predictOneWithCache_o22p4vsubwb(X, cachedScore, &cachedWeights, combiner, td,
    ud, assign_temp_CutPoint_4, assign_temp_NanCutPoints_4, assign_temp_Cost,
    assign_temp_ClassProbability_4, &b, unusedExpr);
  b = obj_IsCached[36];
  CompactClassificationTree_Com_j(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[37];
  CompactClassificationTree_Co_ea(pb, qb, assign_temp_CutPoint_a,
    assign_temp_NanCutPoints_a, expl_temp_d, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_a);
  Moto_predictOneWithCache_o22p4v(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_a, assign_temp_NanCutPoints_a, assign_temp_Cost,
    assign_temp_ClassProbability_a, &b, unusedExpr);
  b = obj_IsCached[38];
  CompactClassificationTree_Com_a(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[39];
  CompactClassificationTree_Com_c(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[40];
  CompactClassificationTree_Co_gt(assign_temp_CutPredictorIndex_3,
    assign_temp_Children_3, assign_temp_CutPoint_b, assign_temp_NanCutPoints_b,
    expl_temp_e, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_b);
  MotorFaul_predictOneWithCache_e(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_3, assign_temp_Children_3,
    assign_temp_CutPoint_b, assign_temp_NanCutPoints_b, assign_temp_Cost,
    assign_temp_ClassProbability_b, &b, unusedExpr);
  b = obj_IsCached[41];
  CompactClassificationTree_Com_i(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint, assign_temp_NanCutPoints,
    expl_temp, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability);
  predictOneWithCach_o22p4vsubwbf(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint,
    assign_temp_NanCutPoints, assign_temp_Cost, assign_temp_ClassProbability, &b,
    unusedExpr);
  b = obj_IsCached[42];
  CompactClassificationTree_Com_h(pb, qb, assign_temp_CutPoint_a,
    assign_temp_NanCutPoints_a, expl_temp_d, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_a);
  Moto_predictOneWithCache_o22p4v(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_a, assign_temp_NanCutPoints_a, assign_temp_Cost,
    assign_temp_ClassProbability_a, &b, unusedExpr);
  b = obj_IsCached[43];
  CompactClassificationTree_Com_n(assign_temp_CutPredictorIndex_1,
    assign_temp_Children_1, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7,
    expl_temp_a, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_7);
  predictOneWithCa_o22p4vsubwbfsd(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_1, assign_temp_Children_1,
    assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[44];
  CompactClassificationTree_Co_kq(assign_temp_CutPredictorIndex_2,
    assign_temp_Children_2, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8,
    expl_temp_b, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_8);
  predictOneWithC_o22p4vsubwbfsdz(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_2, assign_temp_Children_2,
    assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[45];
  CompactClassificationTree_Co_o2(d, e, assign_temp_CutPoint_3,
    assign_temp_NanCutPoints_3, expl_temp_6, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_3);
  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, false, unusedExpr);
  b = obj_IsCached[46];
  CompactClassificationTree_Com_b(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint, assign_temp_NanCutPoints,
    expl_temp, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability);
  predictOneWithCach_o22p4vsubwbf(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint,
    assign_temp_NanCutPoints, assign_temp_Cost, assign_temp_ClassProbability, &b,
    unusedExpr);
  b = obj_IsCached[47];
  CompactClassificationTree_Co_cr(assign_temp_CutPredictorIndex_4,
    assign_temp_Children_4, assign_temp_CutPoint_c, assign_temp_NanCutPoints_c,
    expl_temp_f, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_c);
  MotorFaul_predictOneWithCache_i(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_4, assign_temp_Children_4,
    assign_temp_CutPoint_c, assign_temp_NanCutPoints_c, assign_temp_Cost,
    assign_temp_ClassProbability_c, &b, unusedExpr);
  b = obj_IsCached[48];
  CompactClassificationTree_Co_he(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint, assign_temp_NanCutPoints,
    expl_temp, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability);
  predictOneWithCach_o22p4vsubwbf(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint,
    assign_temp_NanCutPoints, assign_temp_Cost, assign_temp_ClassProbability, &b,
    unusedExpr);
  b = obj_IsCached[49];
  CompactClassificationTree_Co_ci(d, e, assign_temp_CutPoint_3,
    assign_temp_NanCutPoints_3, expl_temp_6, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_3);
  MotorFaultD_predictOneWithCache(X, cachedScore, &cachedWeights, combiner, d, e,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, false, score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static real_T MotorFaultDeploy_mean_o(const real_T x[2400])
{
  real_T b_y;
  real_T bsum;
  int32_T b_k;
  int32_T counts;
  int32_T k;
  if (rtIsNaN(x[0])) {
    b_y = 0.0;
    counts = 0;
  } else {
    b_y = x[0];
    counts = 1;
  }

  for (k = 0; k < 1023; k++) {
    bsum = x[k + 1];
    if (!rtIsNaN(bsum)) {
      b_y += bsum;
      counts++;
    }
  }

  for (k = 0; k < 2; k++) {
    int32_T hi;
    int32_T xblockoffset;
    xblockoffset = (k + 1) << 10;
    bsum = x[xblockoffset];
    if (rtIsNaN(bsum)) {
      bsum = 0.0;
    } else {
      counts++;
    }

    if (k + 2 == 3) {
      hi = 352;
    } else {
      hi = 1024;
    }

    for (b_k = 2; b_k <= hi; b_k++) {
      int32_T xoffset;
      xoffset = (xblockoffset + b_k) - 1;
      if (!rtIsNaN(x[xoffset])) {
        bsum += x[xoffset];
        counts++;
      }
    }

    b_y += bsum;
  }

  return b_y / (real_T)counts;
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static real_T MotorFaul_combineVectorElements(const real_T x[2400])
{
  real_T y;
  int32_T b_k;
  int32_T k;
  y = x[0];
  for (k = 0; k < 1023; k++) {
    y += x[k + 1];
  }

  for (k = 0; k < 2; k++) {
    real_T bsum;
    int32_T hi;
    int32_T xblockoffset;
    xblockoffset = (k + 1) << 10;
    bsum = x[xblockoffset];
    if (k + 2 == 3) {
      hi = 352;
    } else {
      hi = 1024;
    }

    for (b_k = 2; b_k <= hi; b_k++) {
      bsum += x[(xblockoffset + b_k) - 1];
    }

    y += bsum;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static real_T MotorFaultDeploy_std(const real_T x[2400])
{
  real_T b_x;
  real_T t;
  real_T xbar;
  real_T y;
  int32_T exitg1;
  int32_T k;
  xbar = MotorFaul_combineVectorElements(x) / 2400.0;
  for (k = 0; k < 2400; k++) {
    MotorFaultDeploy_B.b_x_k[k] = fabs(x[k] - xbar);
  }

  y = 0.0;
  xbar = 3.312168642111238E-170;
  for (k = 0; k < 2400; k++) {
    b_x = MotorFaultDeploy_B.b_x_k[k];
    if (b_x > xbar) {
      t = xbar / b_x;
      y = y * t * t + 1.0;
      xbar = b_x;
    } else {
      t = b_x / xbar;
      y += t * t;
    }
  }

  y = xbar * sqrt(y);
  if (rtIsNaN(y)) {
    k = 0;
    do {
      exitg1 = 0;
      if (k < 2400) {
        if (rtIsNaN(MotorFaultDeploy_B.b_x_k[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        y = (rtInf);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  y /= 48.979587585033826;
  return y;
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static real_T MotorFaultDeploy_maximum_p(const real_T x[2400])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while (!exitg1 && (k < 2401)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 2401; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorFaultDeploy_minimum_j(const real_T x[3], real_T *ex, int32_T
  *idx)
{
  int32_T b_idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    b_idx = 1;
  } else {
    boolean_T exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while (!exitg1 && (k < 4)) {
      if (!rtIsNaN(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[b_idx - 1];
    *idx = b_idx;
    for (k = b_idx + 1; k < 4; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (*ex > x_0) {
        *ex = x_0;
        *idx = k;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_pre_n(const real_T obj_CutPredictorIndex
  [35], const real_T obj_Children[70], const real_T obj_CutPoint[35], const
  boolean_T obj_NanCutPoints[35], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[105], const real_T Xin[10], real_T *labels, real_T
  scores[3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      35] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 70];
    scores[i] = obj_ClassProbability[35 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorFaultDeploy_updateCache_k(const real_T learnerscore[3], real_T
  cachedScore[3], real_T *cachedWeights, boolean_T *cached, const char_T
  combinerName[15], real_T score[3])
{
  static const char_T b[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T c[15] = { 'w', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'a', 'v',
    'e', 'r', 'a', 'g', 'e' };

  score[0] = cachedScore[0];
  score[1] = cachedScore[1];
  score[2] = cachedScore[2];
  if (!*cached) {
    int32_T kstr;
    boolean_T b_bool;
    *cached = true;
    cachedScore[0] += learnerscore[0];
    cachedScore[1] += learnerscore[1];
    cachedScore[2] += learnerscore[2];
    (*cachedWeights)++;
    b_bool = false;
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (b[(int32_T)combinerName[kstr]] != b[(int32_T)c[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (b_bool) {
      score[0] = cachedScore[0] / *cachedWeights;
      score[1] = cachedScore[1] / *cachedWeights;
      score[2] = cachedScore[2] / *cachedWeights;
    } else {
      score[0] = cachedScore[0];
      score[1] = cachedScore[1];
      score[2] = cachedScore[2];
    }
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorFaul_predictOneWithCache_j(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[35], const real_T weak_learner_Children[70],
  const real_T weak_learner_CutPoint[35], const boolean_T
  weak_learner_NanCutPoints[35], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[105], boolean_T *cached, boolean_T initCache,
  real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pre_n(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  if (initCache) {
    cachedScore[0] = 0.0;
    cachedScore[1] = 0.0;
    cachedScore[2] = 0.0;
  } else {
    y = false;
    k = 0;
    exitg1 = false;
    while (!exitg1 && (k < 3)) {
      if (rtIsNaN(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (y) {
      for (k = 0; k < 3; k++) {
        if (rtIsNaN(cachedScore[k])) {
          cachedScore[k] = 0.0;
        }
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_pr_na(const real_T obj_CutPredictorIndex
  [33], const real_T obj_Children[66], const real_T obj_CutPoint[33], const
  boolean_T obj_NanCutPoints[33], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[99], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      33] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 66];
    scores[i] = obj_ClassProbability[33 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorFau_predictOneWithCache_jp(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[33], const real_T weak_learner_Children[66],
  const real_T weak_learner_CutPoint[33], const boolean_T
  weak_learner_NanCutPoints[33], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[99], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_pr_na(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_p_nap(const real_T obj_CutPredictorIndex
  [25], const real_T obj_Children[50], const real_T obj_CutPoint[25], const
  boolean_T obj_NanCutPoints[25], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[75], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      25] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 50];
    scores[i] = obj_ClassProbability[25 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorFa_predictOneWithCache_jpy(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[25], const real_T weak_learner_Children[50],
  const real_T weak_learner_CutPoint[25], const boolean_T
  weak_learner_NanCutPoints[25], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[75], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_p_nap(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree__napl(const real_T obj_CutPredictorIndex
  [45], const real_T obj_Children[90], const real_T obj_CutPoint[45], const
  boolean_T obj_NanCutPoints[45], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[135], const real_T Xin[10], real_T *labels, real_T
  scores[3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      45] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 90];
    scores[i] = obj_ClassProbability[45 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void MotorF_predictOneWithCache_jpyz(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[45], const real_T weak_learner_Children[90],
  const real_T weak_learner_CutPoint[45], const boolean_T
  weak_learner_NanCutPoints[45], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[135], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree__napl(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_naplr(const real_T obj_CutPredictorIndex
  [27], const real_T obj_Children[54], const real_T obj_CutPoint[27], const
  boolean_T obj_NanCutPoints[27], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[81], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      27] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 54];
    scores[i] = obj_ClassProbability[27 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void Motor_predictOneWithCache_jpyzw(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[27], const real_T weak_learner_Children[54],
  const real_T weak_learner_CutPoint[27], const boolean_T
  weak_learner_NanCutPoints[27], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[81], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTree_naplr(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTre_naplrq(const real_T obj_CutPredictorIndex
  [29], const real_T obj_Children[58], const real_T obj_CutPoint[29], const
  boolean_T obj_NanCutPoints[29], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[87], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      29] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 58];
    scores[i] = obj_ClassProbability[29 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void Moto_predictOneWithCache_jpyzwe(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[29], const real_T weak_learner_Children[58],
  const real_T weak_learner_CutPoint[29], const boolean_T
  weak_learner_NanCutPoints[29], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[87], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTre_naplrq(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTr_naplrqt(const real_T obj_CutPredictorIndex
  [21], const real_T obj_Children[42], const real_T obj_CutPoint[21], const
  boolean_T obj_NanCutPoints[21], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[63], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      21] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 42];
    scores[i] = obj_ClassProbability[21 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void Mot_predictOneWithCache_jpyzwef(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[21], const real_T weak_learner_Children[42],
  const real_T weak_learner_CutPoint[21], const boolean_T
  weak_learner_NanCutPoints[21], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[63], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationTr_naplrqt(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationT_naplrqtl(const real_T obj_CutPredictorIndex
  [31], const real_T obj_Children[62], const real_T obj_CutPoint[31], const
  boolean_T obj_NanCutPoints[31], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[93], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      31] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 62];
    scores[i] = obj_ClassProbability[31 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void Mo_predictOneWithCache_jpyzwefn(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[31], const real_T weak_learner_Children[62],
  const real_T weak_learner_CutPoint[31], const boolean_T
  weak_learner_NanCutPoints[31], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[93], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificationT_naplrqtl(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassification_naplrqtlh(const real_T obj_CutPredictorIndex
  [23], const real_T obj_Children[46], const real_T obj_CutPoint[23], const
  boolean_T obj_NanCutPoints[23], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[69], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      23] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 46];
    scores[i] = obj_ClassProbability[23 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void M_predictOneWithCache_jpyzwefnb(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[23], const real_T weak_learner_Children[46],
  const real_T weak_learner_CutPoint[23], const boolean_T
  weak_learner_NanCutPoints[23], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[69], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassification_naplrqtlh(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_gn(real_T obj_CutPredictorIndex[33],
  real_T obj_Children[66], real_T obj_CutPoint[33], boolean_T obj_NanCutPoints
  [33], boolean_T obj_InfCutPoints[33], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[99])
{
  int32_T i;
  static const real_T tmp[33] = { -0.35201830476404355, 0.0, 9.292933408740097,
    2.86829968722897, 1.1382911358384367, 2.1491831849892327, 8.82816403362844,
    207.99185181015292, 1.0827367186520593, 0.0, 0.021820086788640086, 0.0, 0.0,
    0.0, 1.0081766790435729, 0.0, 1.4781213957378556, 0.5028885554266924, 0.0,
    0.0, 0.0, 239.4399108365312, 0.0, 0.0, 2.3875598934974565, 0.0,
    10.579553785911568, 1.0291985424435564, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[33] = { false, true, false, false, false, false,
    false, false, false, true, false, true, true, true, false, true, false,
    false, true, true, true, false, true, true, false, true, false, false, true,
    true, true, true, true };

  static const real_T tmp_1[99] = { 0.32083333333333314, 0.0, 0.4873417721518985,
    0.9251336898395722, 0.0937499999999998, 0.9853801169590644,
    0.28125000000000006, 0.6315789473684209, 0.03968253968253966, 1.0,
    0.9358974358974358, 1.0, 0.0, 1.0, 0.2631578947368421, 1.0,
    0.03199999999999998, 0.948051948051948, 0.0, 1.0, 0.0, 0.12121212121212124,
    0.0, 1.0, 0.8857142857142857, 0.0, 0.22222222222222238, 0.6923076923076923,
    1.0, 1.0, 0.0, 0.0, 1.0, 0.3416666666666669, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33750000000000013,
    0.0, 0.5126582278481016, 0.0748663101604278, 0.9062500000000002,
    0.014619883040935687, 0.71875, 0.36842105263157904, 0.9603174603174603, 0.0,
    0.06410256410256418, 0.0, 1.0, 0.0, 0.7368421052631579, 0.0, 0.968,
    0.05194805194805202, 1.0, 0.0, 1.0, 0.8787878787878788, 1.0, 0.0,
    0.11428571428571437, 1.0, 0.7777777777777776, 0.3076923076923077, 0.0, 0.0,
    1.0, 1.0, 0.0 };

  static const int8_T c[33] = { 6, 0, 10, 4, 4, 1, 10, 8, 1, 0, 2, 0, 0, 0, 4, 0,
    1, 9, 0, 0, 0, 8, 0, 0, 1, 0, 10, 7, 0, 0, 0, 0, 0 };

  static const int8_T d[66] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 22, 23, 24, 25, 0,
    0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 28, 29, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 33U * sizeof(real_T));
  for (i = 0; i < 33; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 99U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 33; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 66; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 33; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.32083333333333336;
  obj_Prior[1] = 0.3416666666666667;
  obj_Prior[2] = 0.3375;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_C_gne(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { 0.13360890391781266, 2.2811241228479133, 0.0,
    0.9723355636507722, 8.806236481669528, 0.0, 9.679256178546266,
    2.4608702530077067, 0.0, 2.19758821746564, 0.0, 2.3128817688667564, 0.0,
    212.652007855342, 0.01964973597082879, 0.0, 0.0, 0.0, 226.2352481970895, 0.0,
    8.708288401363706, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, false, true, false, false, true,
    false, false, true, false, true, false, true, false, false, true, true, true,
    false, true, false, true, true, true, true };

  static const real_T tmp_1[75] = { 0.35583333333333383, 0.5175757575757579, 0.0,
    0.6648250460405157, 0.2340425531914894, 1.0, 0.5999999999999991,
    0.8461538461538459, 0.0, 0.9578947368421051, 0.0, 0.45454545454545453, 1.0,
    0.9850746268656716, 0.5294117647058824, 1.0, 0.0, 1.0, 0.9611650485436894,
    0.0, 0.6923076923076923, 0.0, 1.0, 1.0, 0.0, 0.3124999999999996, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33166666666666667, 0.4824242424242421,
    0.0, 0.33517495395948427, 0.7659574468085106, 0.0, 0.4000000000000008,
    0.15384615384615402, 1.0, 0.04210526315789487, 1.0, 0.5454545454545454, 0.0,
    0.014925373134328401, 0.47058823529411764, 0.0, 1.0, 0.0,
    0.03883495145631066, 1.0, 0.30769230769230765, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[25] = { 2, 4, 0, 3, 10, 0, 10, 4, 0, 4, 0, 1, 0, 8, 2, 0,
    0, 0, 8, 0, 10, 0, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 22,
    23, 0, 0, 24, 25, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.35583333333333333;
  obj_Prior[1] = 0.3125;
  obj_Prior[2] = 0.33166666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree__gnex(real_T obj_CutPredictorIndex[17],
  real_T obj_Children[34], real_T obj_CutPoint[17], boolean_T obj_NanCutPoints
  [17], boolean_T obj_InfCutPoints[17], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[51])
{
  int32_T i;
  static const real_T tmp[17] = { 1.1141973340137805, 9.305830444589635, 0.0,
    2.2013542677380045, 9.925292565316994, 0.0, 8.539661957729152,
    1.510866846801123, 0.0, 0.0, 2.921520719183943, 0.0, 0.0, 0.0,
    3.0101349903732446, 0.0, 0.0 };

  static const boolean_T tmp_0[17] = { false, false, true, false, false, true,
    false, false, true, true, false, true, true, true, false, true, true };

  static const real_T tmp_1[51] = { 0.3433333333333336, 0.5162907268170429, 0.0,
    0.9166666666666669, 0.09743589743589737, 1.0, 0.6822429906542056,
    0.40425531914893625, 0.0, 1.0, 0.20930232558139547, 1.0, 0.0, 0.0,
    0.8181818181818182, 1.0, 0.0, 0.3350000000000001, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3216666666666665,
    0.4837092731829571, 0.0, 0.08333333333333316, 0.9025641025641027, 0.0,
    0.31775700934579454, 0.5957446808510637, 1.0, 0.0, 0.7906976744186045, 0.0,
    1.0, 1.0, 0.1818181818181818, 0.0, 1.0 };

  static const int8_T c[17] = { 7, 10, 0, 4, 10, 0, 10, 1, 0, 0, 3, 0, 0, 0, 4,
    0, 0 };

  static const int8_T d[34] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 0, 0, 14, 15, 0, 0, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 17U * sizeof(real_T));
  for (i = 0; i < 17; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 51U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 17; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 34; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 17; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3433333333333333;
  obj_Prior[1] = 0.335;
  obj_Prior[2] = 0.32166666666666666;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificatio_naplrqtlhi(const real_T obj_CutPredictorIndex
  [17], const real_T obj_Children[34], const real_T obj_CutPoint[17], const
  boolean_T obj_NanCutPoints[17], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[51], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      17] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 34];
    scores[i] = obj_ClassProbability[17 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void predictOneWithCache_jpyzwefnbj(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[17], const real_T weak_learner_Children[34],
  const real_T weak_learner_CutPoint[17], const boolean_T
  weak_learner_NanCutPoints[17], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[51], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificatio_naplrqtlhi(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_gnexe(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { 1.1088530839786763, 1.0254244617498665, 0.0,
    3.059031181192455, 0.9723198582869388, 2.924520697282814, 0.0, 0.0,
    9.292933408740097, 2.825643065557346, 0.0, 2.9314734858423517,
    9.679256178546266, 0.0, 8.658561827869024, 8.650996908363707, 0.0,
    1.5863940763399778, 0.0, 0.0, 0.0, 0.0, 1.0319688635348245, 0.0, 0.0,
    237.52513099363603, 2.2462342814282037, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, false, true, false, false, false,
    true, true, false, false, true, false, false, true, false, false, true,
    false, true, true, true, true, false, true, true, false, false, true, true,
    true, true };

  static const real_T tmp_1[93] = { 0.32999999999999996, 0.5038167938931298, 0.0,
    0.16304347826086973, 0.54899135446686, 0.31250000000000017, 0.0, 1.0,
    0.49678456591639863, 0.10810810810810818, 1.0, 0.9463087248322146,
    0.08333333333333359, 1.0, 0.0833333333333334, 0.9591836734693876, 0.0,
    0.3750000000000001, 0.0, 1.0, 0.0, 1.0, 0.8823529411764707, 1.0, 0.0,
    0.45000000000000007, 0.9878048780487804, 0.0, 1.0, 1.0, 0.0,
    0.34500000000000025, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.32499999999999984, 0.49618320610687017, 0.0,
    0.8369565217391303, 0.4510086455331401, 0.6874999999999998, 1.0, 0.0,
    0.5032154340836014, 0.8918918918918918, 0.0, 0.053691275167785414,
    0.9166666666666665, 0.0, 0.9166666666666666, 0.04081632653061238, 1.0,
    0.6249999999999999, 1.0, 0.0, 1.0, 0.0, 0.11764705882352942, 0.0, 1.0, 0.55,
    0.012195121951219521, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[31] = { 7, 7, 0, 4, 1, 3, 0, 0, 10, 5, 0, 3, 10, 0, 10,
    10, 0, 4, 0, 0, 0, 0, 7, 0, 0, 8, 3, 0, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0,
    12, 13, 14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25, 0,
    0, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33;
  obj_Prior[1] = 0.345;
  obj_Prior[2] = 0.325;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTre_gnexe4(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { 1.1109774680412126, 9.292148139465922, 0.0,
    1.0304504030903527, 1.1425139568732892, 8.595088148553007,
    2.3223706692091124, 10.372393968278153, 1.517274815090492, 0.0,
    2.924390028631521, 9.224123981410937, 0.020084883447680363, 0.0, 0.0,
    9.807727609911861, 0.0, 2.2444754355321317, 0.5298525596290711, 0.0,
    -0.01370440326295206, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, false, true, false, false, false,
    false, false, false, true, false, false, false, true, true, false, true,
    false, false, true, false, true, true, true, true, true, true, true, true,
    true, true };

  static const real_T tmp_1[93] = { 0.3341666666666667, 0.4860606060606058, 0.0,
    0.9129353233830848, 0.08037825059101633, 0.6736842105263157,
    0.9869706840390878, 0.619047619047619, 0.020997375328083965, 1.0,
    0.26190476190476203, 0.9966666666666667, 0.5714285714285715, 1.0, 0.0,
    0.1454545454545456, 0.0, 0.06250000000000004, 0.9000000000000001, 1.0,
    0.6666666666666667, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.3124999999999996, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.3533333333333338, 0.5139393939393943, 0.0,
    0.08706467661691529, 0.9196217494089837, 0.32631578947368434,
    0.013029315960912098, 0.3809523809523811, 0.9790026246719161, 0.0,
    0.7380952380952379, 0.003333333333333346, 0.42857142857142855, 0.0, 1.0,
    0.8545454545454544, 1.0, 0.9375, 0.09999999999999999, 0.0,
    0.3333333333333333, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[31] = { 7, 10, 0, 7, 4, 10, 3, 10, 4, 0, 1, 10, 2, 0, 0,
    10, 0, 3, 9, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25, 0, 0, 26, 27,
    28, 29, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33416666666666667;
  obj_Prior[1] = 0.3125;
  obj_Prior[2] = 0.35333333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTr_gnexe4e(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57])
{
  int32_T i;
  static const real_T tmp[19] = { 0.13360890391781266, 9.224376248453815, 0.0,
    2.8004574053908877, 0.9696220368222984, 2.3847131675888287,
    234.80961451226352, 0.0, 9.685858536031336, 0.0, 2.3937352329345547, 0.0,
    0.0, 1.562931945501905, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[19] = { false, false, true, false, false, false,
    false, true, false, true, false, true, true, false, true, true, true, true,
    true };

  static const real_T tmp_1[57] = { 0.33333333333333337, 0.49627791563275425,
    0.0, 0.9251870324189528, 0.0716049382716048, 0.9681697612732095, 0.25, 1.0,
    0.050505050505050435, 1.0, 0.7818181818181816, 0.0, 1.0, 0.25974025974026,
    0.0, 0.0, 1.0, 1.0, 0.0, 0.32833333333333325, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3383333333333335, 0.5037220843672457, 0.0, 0.07481296758104726,
    0.9283950617283951, 0.03183023872679042, 0.75, 0.0, 0.9494949494949496, 0.0,
    0.21818181818181834, 1.0, 0.0, 0.7402597402597401, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[19] = { 2, 10, 0, 1, 3, 4, 8, 0, 10, 0, 1, 0, 0, 4, 0, 0,
    0, 0, 0 };

  static const int8_T d[38] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 0,
    0, 14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 19U * sizeof(real_T));
  for (i = 0; i < 19; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 57U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 19; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 38; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 19; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3333333333333333;
  obj_Prior[1] = 0.3283333333333333;
  obj_Prior[2] = 0.3383333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificati_naplrqtlhie(const real_T obj_CutPredictorIndex
  [19], const real_T obj_Children[38], const real_T obj_CutPoint[19], const
  boolean_T obj_NanCutPoints[19], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[57], const real_T Xin[10], real_T *labels, real_T scores
  [3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      19] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 38];
    scores[i] = obj_ClassProbability[19 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void predictOneWithCache_jpyzwefnbjt(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[19], const real_T weak_learner_Children[38],
  const real_T weak_learner_CutPoint[19], const boolean_T
  weak_learner_NanCutPoints[19], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[57], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificati_naplrqtlhie(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationT_gnexe4eq(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { 0.13360890391781266, 9.224376248453815, 0.0,
    2.8009850762882564, 1.0827367186520593, 2.3128817688667564,
    2.9951529038711575, 1.0182923166740911, 0.0193716897939957, 0.0,
    2.3875128909191314, 0.0, 0.026727526903909987, 0.9421706981696536,
    0.15207586986102484, 0.0, 1.0436137454424554, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.5584809574538185, 9.80987680002982, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, false, true, false, false, false,
    false, false, false, true, false, true, false, false, false, true, false,
    true, true, true, true, true, true, true, true, true, false, false, true,
    true, true };

  static const real_T tmp_1[93] = { 0.3274999999999999, 0.4974683544303797, 0.0,
    0.9493333333333334, 0.08915662650602389, 0.9859550561797753,
    0.2631578947368421, 0.5576923076923076, 0.022038567493112945, 1.0,
    0.9180327868852458, 0.0, 0.8333333333333333, 0.2592592592592593, 0.88, 1.0,
    0.01933701657458563, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.06542056074766352, 0.12068965517241391, 0.0, 1.0, 0.0, 0.3416666666666669,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3308333333333333, 0.5025316455696203, 0.0, 0.050666666666666665,
    0.910843373493976, 0.01404494382022472, 0.7368421052631579,
    0.4423076923076924, 0.977961432506887, 0.0, 0.08196721311475419, 1.0,
    0.16666666666666666, 0.7407407407407408, 0.12000000000000001, 0.0,
    0.9806629834254142, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.9345794392523366, 0.8793103448275861, 1.0, 0.0, 1.0 };

  static const int8_T c[31] = { 2, 10, 0, 1, 1, 1, 4, 3, 2, 0, 3, 0, 2, 3, 6, 0,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 10, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0, 26, 27, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0,
    0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3275;
  obj_Prior[1] = 0.3416666666666667;
  obj_Prior[2] = 0.3308333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassification_gnexe4eq5(real_T obj_CutPredictorIndex[51],
  real_T obj_Children[102], real_T obj_CutPoint[51], boolean_T obj_NanCutPoints
  [51], boolean_T obj_InfCutPoints[51], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[153])
{
  int32_T i;
  static const real_T tmp[51] = { 0.7524074195722035, 2.3299812780996643,
    9.925664794495269, 255.69683971347496, 2.946133914800475, 0.0, 0.0,
    9.56879145189843, 9.27742333230583, 2.924390028631521, 0.0,
    0.1150055682708143, 1.0717421221451147, 0.0, 10.130438704202668,
    2.3937352329345547, 3.0101349903732446, 0.019231552082560242, 0.0,
    207.57154836223512, 0.0, 9.861814671778323, 0.0, 2.2556773510207995,
    2.4220607670818644, 0.0, 0.0, 9.205937870406753, 9.29323721541239, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 265.8555376143694, 2.7353724182522337, 0.0, 0.0, 0.0,
    3.0267561608543962, 0.0, 0.0, 8.959564591486824, 0.0, 0.0,
    0.5001851238485603, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[51] = { false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, false, false, false,
    false, true, false, true, false, true, false, false, true, true, false,
    false, true, true, true, true, true, true, false, false, true, true, true,
    false, true, true, false, true, true, false, true, true, true, true };

  static const real_T tmp_1[153] = { 0.3325, 0.4938118811881187, 0.0,
    0.6145454545454545, 0.23643410852713165, 0.0, 0.0, 0.7403189066059219,
    0.11711711711711707, 0.3128205128205121, 0.0, 0.9724770642201834,
    0.06249999999999995, 1.0, 0.05769230769230766, 0.2569832402234631, 0.9375,
    0.9845201238390093, 0.0, 0.2916666666666667, 0.0, 0.3529411764705882, 0.0,
    0.019607843137254923, 0.3515624999999999, 1.0, 0.0, 0.33333333333333337,
    0.990625, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.875, 0.23076923076923087, 1.0, 0.0,
    1.0, 0.8500000000000001, 1.0, 0.0, 0.36363636363636376, 0.0, 1.0,
    0.5714285714285715, 1.0, 0.0, 1.0, 0.0, 0.3216666666666665,
    0.004950495049504936, 0.9744897959183673, 0.007272727272727279, 0.0, 1.0,
    0.0, 0.009111617312072901, 0.0, 0.0, 0.0, 0.0122324159021407, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3458333333333336, 0.5012376237623762,
    0.025510204081632605, 0.3781818181818181, 0.7635658914728682, 0.0, 1.0,
    0.2505694760820051, 0.882882882882883, 0.6871794871794878, 1.0,
    0.015290519877675877, 0.9375000000000001, 0.0, 0.9423076923076923,
    0.7430167597765368, 0.06249999999999999, 0.01547987616099075, 0.0,
    0.7083333333333334, 1.0, 0.6470588235294117, 1.0, 0.9803921568627452,
    0.6484375000000001, 0.0, 1.0, 0.6666666666666666, 0.009375000000000022, 0.0,
    1.0, 1.0, 0.0, 0.0, 1.0, 0.125, 0.7692307692307692, 0.0, 1.0, 0.0,
    0.14999999999999997, 0.0, 1.0, 0.6363636363636362, 1.0, 0.0,
    0.42857142857142855, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[51] = { 9, 4, 10, 8, 3, 0, 0, 10, 10, 1, 0, 2, 3, 0, 10,
    1, 4, 2, 0, 8, 0, 10, 0, 3, 1, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 8, 3, 0, 0, 0,
    5, 0, 0, 10, 0, 0, 9, 0, 0, 0, 0 };

  static const int8_T d[102] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 26, 27, 28,
    29, 0, 0, 30, 31, 0, 0, 32, 33, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 38, 39, 40,
    41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 46,
    47, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 51U * sizeof(real_T));
  for (i = 0; i < 51; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 153U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 51; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 102; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 51; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3325;
  obj_Prior[1] = 0.32166666666666666;
  obj_Prior[2] = 0.3458333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificat_naplrqtlhieu(const real_T obj_CutPredictorIndex
  [51], const real_T obj_Children[102], const real_T obj_CutPoint[51], const
  boolean_T obj_NanCutPoints[51], const real_T obj_Cost[9], const real_T
  obj_ClassProbability[153], const real_T Xin[10], real_T *labels, real_T
  scores[3])
{
  real_T obj_ClassProbability_0[3];
  real_T a__4;
  int32_T i;
  int32_T m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
    a__4 = Xin[(int32_T)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(a__4) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (a__4 < obj_CutPoint[m]) {
      m = (int32_T)obj_Children[m << 1] - 1;
    } else {
      m = (int32_T)obj_Children[(m << 1) + 1] - 1;
    }
  }

  for (i = 0; i < 3; i++) {
    obj_ClassProbability_0[i] = (obj_Cost[3 * i + 1] * obj_ClassProbability[m +
      51] + obj_Cost[3 * i] * obj_ClassProbability[m]) + obj_Cost[3 * i + 2] *
      obj_ClassProbability[m + 102];
    scores[i] = obj_ClassProbability[51 * i + m];
  }

  MotorFaultDeploy_minimum_j(obj_ClassProbability_0, &a__4, &m);
  if (m < 0) {
    m = 0;
  }

  *labels = (int8_T)((int8_T)(m - 1) + 1);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void predictOneWithCach_jpyzwefnbjt0(const real_T X[10], real_T
  cachedScore[3], real_T *cachedWeights, const char_T combiner[15], const real_T
  weak_learner_CutPredictorIndex[51], const real_T weak_learner_Children[102],
  const real_T weak_learner_CutPoint[51], const boolean_T
  weak_learner_NanCutPoints[51], const real_T weak_learner_Cost[9], const real_T
  weak_learner_ClassProbability[153], boolean_T *cached, real_T score[3])
{
  real_T b[3];
  real_T a__2;
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  CompactClassificat_naplrqtlhieu(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_Cost, weak_learner_ClassProbability, X, &a__2, b);
  y = false;
  k = 0;
  exitg1 = false;
  while (!exitg1 && (k < 3)) {
    if (rtIsNaN(cachedScore[k])) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    for (k = 0; k < 3; k++) {
      if (rtIsNaN(cachedScore[k])) {
        cachedScore[k] = 0.0;
      }
    }
  }

  MotorFaultDeploy_updateCache_k(b, cachedScore, cachedWeights, cached, combiner,
    score);
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificatio_gnexe4eq5x(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { -0.3537642023158249, 0.0, 2.2811241228479133,
    259.9899214982819, 8.544553492799327, 9.569052257509373, 1.1518800028098202,
    0.0, 8.806236481669528, 2.1322110418554283, 9.679150340738417, 0.0, 0.0,
    2.6499725290493563, 0.0, 0.0, 2.176156332872819, 210.4668835469273, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, true, false, false, false, false,
    false, true, false, false, false, true, true, false, true, true, false,
    false, true, true, true, true, true, true, true };

  static const real_T tmp_1[75] = { 0.3016666666666661, 0.0, 0.458227848101265,
    0.58235294117647, 0.23214285714285718, 0.7118226600985211,
    0.0769230769230769, 1.0, 0.03153153153153158, 0.9691780821917807,
    0.05263157894736837, 1.0, 0.0, 0.4375, 0.0, 1.0, 0.5, 0.4615384615384615,
    0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.3416666666666669, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.3566666666666672, 0.0, 0.5417721518987351,
    0.41764705882353004, 0.7678571428571429, 0.28817733990147887,
    0.9230769230769231, 0.0, 0.9684684684684685, 0.030821917808219284,
    0.9473684210526316, 0.0, 1.0, 0.5625, 1.0, 0.0, 0.5, 0.5384615384615384, 1.0,
    1.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[25] = { 6, 0, 4, 8, 10, 10, 3, 0, 10, 3, 10, 0, 0, 1, 0,
    0, 3, 8, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0,
    0, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 24, 25, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3016666666666667;
  obj_Prior[1] = 0.3416666666666667;
  obj_Prior[2] = 0.3566666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificati_gnexe4eq5xh(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69])
{
  int32_T i;
  static const real_T tmp[23] = { 0.13460875486096524, 201.19722832608886, 0.0,
    9.789637758203497, 9.223526329417794, 2.8771765153760755, 0.0,
    221.80492291446487, 1.0081766790435729, 0.0, 0.0, 8.257427306941421, 0.0,
    0.0, 1.4779408084940728, 0.0, 1.6178984215644148, 9.807727609911861, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[23] = { false, false, true, false, false, false,
    true, false, false, true, true, false, true, true, false, true, false, false,
    true, true, true, true, true };

  static const real_T tmp_1[69] = { 0.34833333333333366, 0.516687268232386, 0.0,
    0.8339350180505414, 0.3515037593984963, 0.9956896551724138, 0.0,
    0.8586387434554976, 0.0674486803519063, 1.0, 0.0, 0.5344827586206896, 1.0,
    1.0, 0.03927492447129919, 1.0, 0.15625000000000008, 0.15662650602409656, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.3258333333333332, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3258333333333332, 0.483312731767614, 0.0, 0.16606498194945862,
    0.6484962406015037, 0.0043103448275862155, 1.0, 0.14136125654450238,
    0.9325513196480937, 0.0, 1.0, 0.46551724137931033, 0.0, 0.0,
    0.9607250755287007, 0.0, 0.8437499999999999, 0.8433734939759033, 1.0, 0.0,
    1.0, 0.0, 1.0 };

  static const int8_T c[23] = { 2, 8, 0, 10, 10, 4, 0, 8, 4, 0, 0, 10, 0, 0, 3,
    0, 1, 10, 0, 0, 0, 0, 0 };

  static const int8_T d[46] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 23U * sizeof(real_T));
  for (i = 0; i < 23; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 69U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 23; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 46; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 23; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3483333333333334;
  obj_Prior[1] = 0.32583333333333336;
  obj_Prior[2] = 0.32583333333333336;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificat_gnexe4eq5xht(real_T obj_CutPredictorIndex[45],
  real_T obj_Children[90], real_T obj_CutPoint[45], boolean_T obj_NanCutPoints
  [45], boolean_T obj_InfCutPoints[45], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[135])
{
  int32_T i;
  static const real_T tmp[45] = { 0.13460875486096524, 200.79403359949305, 0.0,
    182.07041799459768, 0.9692581873147478, 0.0, 187.59975733371667, 0.0,
    2.1393951435261256, 1.9759465171347381, 10.080877554760658,
    255.69683971347496, 2.4101800250727656, 0.0, 0.0, 0.17403077166124772, 0.0,
    1.4294399052398654, 2.1151393747311507, 0.0, 266.3443078657572, 0.0, 0.0,
    251.78013173166488, 1.8194948311104893, 0.0, 2.187651728430436,
    254.97262930120522, 0.0, 0.0, 0.0, 9.569052257509373, 0.0, 282.5056948988867,
    0.0, 2.8004252187547856, 0.0, 0.0, 0.0, 0.0, 0.0, 8.959564591486824, 0.0,
    0.0, 0.0 };

  static const boolean_T tmp_0[45] = { false, false, true, false, false, true,
    false, true, false, false, false, false, false, true, true, false, true,
    false, false, true, false, true, true, false, false, true, false, false,
    true, true, true, false, true, false, true, false, true, true, true, true,
    true, false, true, true, true };

  static const real_T tmp_1[135] = { 0.3016666666666661, 0.45137157107231823,
    0.0, 0.8087649402390439, 0.2885662431941923, 1.0, 0.6097560975609756, 1.0,
    0.24324324324324315, 0.12820512820512828, 0.8333333333333331,
    0.3295880149812733, 0.15139442231075703, 1.0, 0.0, 0.9722222222222222, 0.0,
    0.5724137931034484, 0.04098360655737699, 0.0, 0.24836601307189501, 1.0, 0.0,
    0.20833333333333348, 0.7525773195876287, 0.0, 0.625, 0.383838383838384, 0.0,
    0.0, 1.0, 0.6129032258064515, 1.0, 0.25000000000000006, 1.0,
    0.2906976744186048, 1.0, 1.0, 0.0, 1.0, 0.0, 0.7575757575757575, 0.0, 1.0,
    0.0, 0.33166666666666667, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.36666666666666736, 0.5486284289276818, 0.0,
    0.19123505976095614, 0.7114337568058078, 0.0, 0.3902439024390245, 0.0,
    0.7567567567567568, 0.8717948717948716, 0.16666666666666685,
    0.6704119850187268, 0.8486055776892429, 0.0, 1.0, 0.02777777777777781, 1.0,
    0.4275862068965515, 0.959016393442623, 1.0, 0.7516339869281049, 0.0, 1.0,
    0.7916666666666665, 0.24742268041237134, 1.0, 0.37499999999999994,
    0.6161616161616161, 1.0, 1.0, 0.0, 0.3870967741935485, 0.0,
    0.7499999999999999, 0.0, 0.7093023255813952, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.2424242424242425, 1.0, 0.0, 1.0 };

  static const int8_T c[45] = { 2, 8, 0, 8, 1, 0, 8, 0, 3, 4, 10, 8, 3, 0, 0, 6,
    0, 3, 3, 0, 8, 0, 0, 8, 4, 0, 4, 8, 0, 0, 0, 10, 0, 8, 0, 3, 0, 0, 0, 0, 0,
    10, 0, 0, 0 };

  static const int8_T d[90] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 0, 0,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 24, 25, 26,
    27, 0, 0, 28, 29, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 34, 35, 36, 37, 0, 0, 0,
    0, 0, 0, 38, 39, 0, 0, 40, 41, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    44, 45, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 45U * sizeof(real_T));
  for (i = 0; i < 45; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 135U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 45; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 90; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 45; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3016666666666667;
  obj_Prior[1] = 0.33166666666666667;
  obj_Prior[2] = 0.36666666666666664;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassifica_gnexe4eq5xhts(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57])
{
  int32_T i;
  static const real_T tmp[19] = { 0.1250014433673732, 2.2074228051888194, 0.0,
    9.678861178168638, 8.8333853730066, 9.231492726563282, 0.9476505149479906,
    2.3939735915231473, 0.0, 0.0, 1.4946250147893543, 0.0, 0.0,
    8.316582600458773, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[19] = { false, false, true, false, false, false,
    false, false, true, true, false, true, true, false, true, true, true, true,
    true };

  static const real_T tmp_1[57] = { 0.31916666666666643, 0.48727735368956715,
    0.0, 0.6180422264875236, 0.23018867924528297, 0.9593749999999998,
    0.0746268656716418, 0.9242424242424242, 0.0, 1.0, 0.6749999999999999, 1.0,
    0.0, 0.5454545454545455, 1.0, 1.0, 0.0, 1.0, 0.0, 0.34500000000000025, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.33583333333333343, 0.5127226463104329, 0.0, 0.38195777351247634,
    0.769811320754717, 0.040625000000000126, 0.9253731343283581,
    0.07575757575757584, 1.0, 0.0, 0.32500000000000007, 0.0, 1.0,
    0.45454545454545453, 0.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[19] = { 2, 1, 0, 10, 10, 10, 3, 3, 0, 0, 1, 0, 0, 10, 0,
    0, 0, 0, 0 };

  static const int8_T d[38] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 19U * sizeof(real_T));
  for (i = 0; i < 19; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 57U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 19; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 38; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 19; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3191666666666667;
  obj_Prior[1] = 0.34500000000000003;
  obj_Prior[2] = 0.3358333333333334;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassific_gnexe4eq5xhtsj(real_T obj_CutPredictorIndex[29],
  real_T obj_Children[58], real_T obj_CutPoint[29], boolean_T obj_NanCutPoints
  [29], boolean_T obj_InfCutPoints[29], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[87])
{
  int32_T i;
  static const real_T tmp[29] = { -0.3543213767326082, 0.0, 9.230193450059172,
    2.8033693179180306, 1.1390379669469601, 2.3128817688667564, 234.793061066681,
    207.9895509178176, 1.517274815090492, 0.0, 214.1570812173905, 0.0, 0.0, 0.0,
    263.5415376186148, 1.426642385309111, 0.0, 0.0, 8.539625130193475, 0.0, 0.0,
    0.0, 0.5109815347848399, 0.0, 0.0, 10.665403498019236, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[29] = { false, true, false, false, false, false,
    false, false, false, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, true, true, false, true, true, true };

  static const real_T tmp_1[87] = { 0.3475000000000003, 0.0, 0.5232120451693857,
    0.9170731707317075, 0.10594315245478032, 0.9731903485254692,
    0.3513513513513514, 0.6382978723404253, 0.03235294117647064, 1.0,
    0.8484848484848484, 0.0, 1.0, 1.0, 0.4516129032258065, 0.18965517241379323,
    0.0, 1.0, 0.5454545454545454, 0.0, 1.0, 0.0, 0.7333333333333333, 1.0, 0.0,
    0.7857142857142858, 0.0, 1.0, 0.0, 0.33583333333333343, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3166666666666664, 0.0,
    0.4767879548306143, 0.0829268292682925, 0.8940568475452197,
    0.02680965147453081, 0.6486486486486486, 0.3617021276595746,
    0.9676470588235294, 0.0, 0.15151515151515166, 1.0, 0.0, 0.0,
    0.5483870967741936, 0.8103448275862066, 1.0, 0.0, 0.45454545454545453, 1.0,
    0.0, 1.0, 0.2666666666666666, 0.0, 1.0, 0.21428571428571427, 1.0, 0.0, 1.0 };

  static const int8_T c[29] = { 6, 0, 10, 3, 4, 1, 8, 8, 4, 0, 8, 0, 0, 0, 8, 1,
    0, 0, 10, 0, 0, 0, 9, 0, 0, 10, 0, 0, 0 };

  static const int8_T d[58] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 24,
    25, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 29U * sizeof(real_T));
  for (i = 0; i < 29; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 87U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 29; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 58; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 29; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3475;
  obj_Prior[1] = 0.3358333333333333;
  obj_Prior[2] = 0.31666666666666665;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassifi_gnexe4eq5xhtsjp(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { 9.561974759101414, 1.1109774680412126,
    0.9477392422334829, 2.1987436552503645, 0.0, 0.0, 9.679256178546266, 0.0,
    181.62160532116087, 9.610253338416634, 0.0, 0.0, 2.3978824434938044, 0.0,
    0.0, 2.1394730316895973, 210.1658658957057, 0.0, 0.0, 2.8675503914487894,
    0.0, 2.6346193664550737, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, false, false, false, true, true,
    false, true, false, false, true, true, false, true, true, false, false, true,
    true, false, true, false, true, true, true };

  static const real_T tmp_1[75] = { 0.3241666666666665, 0.4529914529914527,
    0.04724409448818895, 0.8833333333333336, 0.0, 1.0, 0.021563342318059286, 1.0,
    0.6620689655172417, 0.2962962962962963, 0.0, 1.0, 0.4787234042553192, 0.0,
    1.0, 0.04545454545454546, 0.6111111111111109, 1.0, 0.0, 0.3488372093023257,
    1.0, 0.6818181818181819, 0.0, 0.0, 1.0, 0.3325, 0.4871794871794876, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3433333333333336, 0.05982905982905966,
    0.952755905511811, 0.11666666666666645, 0.0, 0.0, 0.9784366576819408, 0.0,
    0.3379310344827583, 0.7037037037037037, 1.0, 0.0, 0.5212765957446809, 1.0,
    0.0, 0.9545454545454546, 0.38888888888888895, 0.0, 1.0, 0.6511627906976742,
    0.0, 0.3181818181818182, 1.0, 1.0, 0.0 };

  static const int8_T c[25] = { 10, 7, 3, 4, 0, 0, 10, 0, 8, 10, 0, 0, 1, 0, 0,
    3, 8, 0, 0, 4, 0, 3, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 10, 11, 0, 0,
    12, 13, 14, 15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0,
    22, 23, 0, 0, 24, 25, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.32416666666666666;
  obj_Prior[1] = 0.3325;
  obj_Prior[2] = 0.3433333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Com_l(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { 1.1109774680412126, 9.292148139465922, 0.0,
    2.86829968722897, 1.0581642432777074, 2.384598905301833, 234.8070064161846,
    1.4435507921039692, 9.981675832834311, 0.0, 0.020476382514107206, 0.0, 0.0,
    9.80987680002982, 0.0, 0.0, 0.0, 2.4533056528454846, 2.4611971861350823, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, false, true, false, false, false,
    false, false, false, true, false, true, true, false, true, true, true, false,
    false, true, true, true, true, true, true };

  static const real_T tmp_1[75] = { 0.3108333333333329, 0.4831606217616577, 0.0,
    0.9175824175824175, 0.09558823529411749, 0.9670658682634731,
    0.36666666666666664, 0.02153846153846159, 0.3855421686746989, 1.0,
    0.8405797101449274, 0.0, 1.0, 0.1250000000000001, 0.0, 1.0, 0.0,
    0.9298245614035087, 0.41666666666666663, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.3566666666666672, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3325,
    0.5168393782383424, 0.0, 0.08241758241758247, 0.9044117647058825,
    0.03293413173652701, 0.6333333333333333, 0.9784615384615383,
    0.6144578313253012, 0.0, 0.15942028985507264, 1.0, 0.0, 0.8749999999999998,
    1.0, 0.0, 1.0, 0.07017543859649131, 0.5833333333333334, 0.0, 1.0, 1.0, 0.0,
    1.0, 0.0 };

  static const int8_T c[25] = { 7, 10, 0, 4, 7, 4, 8, 1, 10, 0, 2, 0, 0, 10, 0,
    0, 0, 4, 4, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 22, 23, 24,
    25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.31083333333333335;
  obj_Prior[1] = 0.3566666666666667;
  obj_Prior[2] = 0.3325;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_jt(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69])
{
  int32_T i;
  static const real_T tmp[23] = { 1.111289542205076, 9.305830444589635, 0.0,
    2.2006392377359623, 0.9699361351153313, 0.0, 8.806300086149156, 0.0,
    1.5181785970813864, 8.544951035983177, 0.0, 1.4938055026517634, 0.0, 0.0,
    1.0272614711572876, 9.840271491374336, 10.579553785911568, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[23] = { false, false, true, false, false, true,
    false, true, false, false, true, false, true, true, false, false, false,
    true, true, true, true, true, true };

  static const real_T tmp_1[69] = { 0.3341666666666667, 0.5031367628607278, 0.0,
    0.9077669902912624, 0.07012987012987008, 1.0, 0.6666666666666666, 1.0,
    0.05039787798408487, 0.9156626506024096, 0.0, 0.20430107526881744, 0.0, 1.0,
    0.588235294117647, 0.13157894736842118, 0.5294117647058824, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.33583333333333343, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.32999999999999996, 0.4968632371392722, 0.0, 0.09223300970873768,
    0.92987012987013, 0.0, 0.3333333333333335, 0.0, 0.9496021220159152,
    0.08433734939759047, 1.0, 0.7956989247311826, 1.0, 0.0, 0.4117647058823529,
    0.8684210526315788, 0.47058823529411764, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[23] = { 7, 10, 0, 4, 3, 0, 10, 0, 4, 10, 0, 4, 0, 0, 7,
    10, 10, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[46] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 0, 0,
    12, 13, 14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 23U * sizeof(real_T));
  for (i = 0; i < 23; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 69U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 23; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 46; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 23; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33416666666666667;
  obj_Prior[1] = 0.3358333333333333;
  obj_Prior[2] = 0.33;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Com_p(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81])
{
  int32_T i;
  static const real_T tmp[27] = { -0.3508035782514354, 0.0, 9.224373226263262,
    2.801061141998142, 1.1407746272472488, 2.32225407810418, 2.9215806797020667,
    1.0764984446545345, 9.561930455222182, 0.0, 8.544553492799327, 0.0,
    0.022231800468885822, 0.9692581873147478, 1.0211851828270633,
    9.524801652320537, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[27] = { false, true, false, false, false, false,
    false, false, false, true, false, true, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true };

  static const real_T tmp_1[81] = { 0.32333333333333314, 0.0, 0.4886649874055413,
    0.9436997319034852, 0.0855106888361043, 0.9768115942028985,
    0.5357142857142857, 0.537037037037037, 0.01907356948228882, 1.0,
    0.8490566037735847, 0.0, 0.9375, 0.16, 0.8620689655172413,
    0.18421052631578957, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.3383333333333335, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3383333333333335, 0.0, 0.5113350125944587, 0.056300268096514734,
    0.9144893111638958, 0.023188405797101474, 0.4642857142857143,
    0.462962962962963, 0.9809264305177111, 0.0, 0.15094339622641523, 1.0,
    0.06249999999999999, 0.84, 0.13793103448275865, 0.8157894736842104, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0 };

  static const int8_T c[27] = { 6, 0, 10, 3, 4, 1, 3, 4, 10, 0, 10, 0, 2, 1, 1,
    10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[54] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 27U * sizeof(real_T));
  for (i = 0; i < 27; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 81U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 27; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 54; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 27; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3233333333333333;
  obj_Prior[1] = 0.3383333333333333;
  obj_Prior[2] = 0.3383333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Com_d(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { -0.35511532575619853, 0.0, 201.31283413441153,
    2.620582903318795, 283.85287115158025, 9.835323947967229, 201.28516934623497,
    9.23049111839774, 0.0, 0.0, 0.0, 2.9148174389892323, 0.0, 221.80492291446487,
    1.0081766790435729, 0.15463976485557085, 0.0, 214.63895872808206, 0.0, 0.0,
    1.4818928048867872, 0.0, 0.0, 2.803638278909362, 0.0, 9.973237553085355, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, true, false, false, false, false,
    false, false, true, true, true, false, true, false, false, false, true,
    false, true, true, false, true, true, false, true, false, true, true, true,
    true, true };

  static const real_T tmp_1[93] = { 0.33916666666666684, 0.0, 0.5132408575031528,
    0.8197278911564624, 0.3326653306613232, 0.8619402985074626,
    0.3846153846153846, 0.4462365591397855, 0.0, 1.0, 0.0, 0.15789473684210525,
    1.0, 0.9050632911392407, 0.10747663551401869, 0.6, 0.0, 0.6511627906976742,
    1.0, 1.0, 0.054455445544554476, 1.0, 0.0, 0.8235294117647057, 0.0,
    0.2340425531914895, 0.0, 1.0, 0.0, 1.0, 0.0, 0.33916666666666684, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3216666666666665, 0.0, 0.48675914249684715, 0.1802721088435376,
    0.6673346693386768, 0.13805970149253746, 0.6153846153846154,
    0.5537634408602145, 1.0, 0.0, 1.0, 0.8421052631578947, 0.0,
    0.09493670886075929, 0.8925233644859812, 0.39999999999999997, 1.0,
    0.3488372093023257, 0.0, 0.0, 0.9455445544554456, 0.0, 1.0,
    0.17647058823529418, 1.0, 0.7659574468085105, 1.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[31] = { 6, 0, 8, 4, 8, 10, 8, 10, 0, 0, 0, 5, 0, 8, 4, 6,
    0, 8, 0, 0, 1, 0, 0, 3, 0, 10, 0, 0, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 0,
    0, 0, 0, 26, 27, 0, 0, 0, 0, 28, 29, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33916666666666667;
  obj_Prior[1] = 0.33916666666666667;
  obj_Prior[2] = 0.32166666666666666;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_g0(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { 0.1284108347039896, 9.224376248453815, 0.0,
    2.3223512103635766, 1.0636814971474053, 0.0, 8.544699041695408,
    1.5589562014285512, 0.026432587156705826, 0.0, 238.93149571664026,
    1.4938055026517634, 0.0, 10.222243012320488, 0.9697295191116275, 0.0, 0.0,
    1.0596424877467823, 10.65898612519184, 0.0, 0.0, 0.0, 10.231047390439176,
    1.0104090400620411, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, false, true, false, false, true,
    false, false, false, true, false, false, true, false, false, true, true,
    false, false, true, true, true, false, false, true, true, true, true, true,
    true, true };

  static const real_T tmp_1[93] = { 0.3366666666666668, 0.5050000000000001, 0.0,
    0.92, 0.08999999999999987, 1.0, 0.6321839080459769, 0.03672316384180793, 0.5,
    1.0, 0.2727272727272729, 0.19117647058823548, 0.0, 0.7, 0.125, 0.0, 1.0,
    0.06818181818181823, 0.41666666666666663, 1.0, 0.0, 1.0, 0.06666666666666667,
    0.6, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.33333333333333337, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.32999999999999996, 0.4949999999999999, 0.0, 0.07999999999999986,
    0.9100000000000001, 0.0, 0.3678160919540231, 0.9632768361581919, 0.5, 0.0,
    0.7272727272727272, 0.8088235294117645, 1.0, 0.30000000000000004, 0.875, 1.0,
    0.0, 0.9318181818181817, 0.5833333333333334, 0.0, 1.0, 0.0,
    0.9333333333333333, 0.4, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0 };

  static const int8_T c[31] = { 2, 10, 0, 3, 7, 0, 10, 4, 6, 0, 8, 4, 0, 10, 3,
    0, 0, 3, 10, 0, 0, 0, 10, 3, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25,
    26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33666666666666667;
  obj_Prior[1] = 0.3333333333333333;
  obj_Prior[2] = 0.33;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_bl(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { -0.3543213767326082, 0.0, 2.130520995248585,
    9.573401943619684, 2.946012206210087, 0.0, 0.9422330392230123,
    2.9935472286382576, 0.0, 0.0, 1.0828800520827715, 3.054375950266576, 0.0,
    1.113305436543487, 0.0, 8.539540388384932, 8.66557797337329, 0.0,
    10.473564964508501, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, true, false, false, false, true,
    false, false, true, true, false, false, true, false, true, false, false,
    true, false, true, true, true, true, true, true };

  static const real_T tmp_1[75] = { 0.31333333333333296, 0.0,
    0.48267008985879295, 0.6189473684210517, 0.2697368421052634, 1.0,
    0.07653061224489793, 0.32283464566929104, 0.0, 1.0, 0.042328042328042326,
    0.28033472803347237, 1.0, 0.2962962962962963, 0.0, 0.20765027322404317,
    0.5178571428571428, 0.0, 0.8, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.3508333333333337, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.33583333333333343, 0.0, 0.517329910141207, 0.3810526315789483,
    0.7302631578947367, 0.0, 0.923469387755102, 0.677165354330709, 1.0, 0.0,
    0.9576719576719578, 0.7196652719665276, 0.0, 0.7037037037037037, 1.0,
    0.7923497267759568, 0.48214285714285715, 1.0, 0.19999999999999998, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[25] = { 6, 0, 1, 10, 1, 0, 1, 4, 0, 0, 1, 5, 0, 4, 0, 10,
    10, 0, 10, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24,
    25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.31333333333333335;
  obj_Prior[1] = 0.35083333333333333;
  obj_Prior[2] = 0.3358333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_cj(real_T obj_CutPredictorIndex[33],
  real_T obj_Children[66], real_T obj_CutPoint[33], boolean_T obj_NanCutPoints
  [33], boolean_T obj_InfCutPoints[33], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[99])
{
  int32_T i;
  static const real_T tmp[33] = { -0.35199925403856913, 0.0, 9.292148139465922,
    2.865021794750181, 1.0830956620610308, 2.3223713350504, 234.79468357524445,
    208.12786306661872, 1.4404474018237896, 0.0, 2.3938251299743545, 0.0, 0.0,
    0.0, 0.9475430326586615, 1.0510616712467262, 0.6468197880585094, 0.0, 0.0,
    0.0, 0.0, 10.59318215616291, 1.4276018817656586, 0.0, 0.20845016598733845,
    0.0, 0.0, 0.0, 1.517274815090492, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[33] = { false, true, false, false, false, false,
    false, false, false, true, false, true, true, true, false, false, false,
    true, true, true, true, false, false, true, false, true, true, true, false,
    true, true, true, true };

  static const real_T tmp_1[99] = { 0.363333333333334, 0.0, 0.5291262135922336,
    0.9503722084367247, 0.1258907363420425, 0.9843342036553525, 0.3,
    0.6379310344827585, 0.04407713498622592, 1.0, 0.9142857142857143, 0.0, 1.0,
    1.0, 0.3823529411764706, 0.22058823529411786, 0.003389830508474589, 0.0, 1.0,
    1.0, 0.0, 0.4375, 0.027777777777777804, 0.0, 0.07692307692307693, 1.0, 0.0,
    0.0, 0.5000000000000001, 1.0, 0.0, 1.0, 0.0, 0.31333333333333296, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.32333333333333314, 0.0, 0.4708737864077664, 0.04962779156327535,
    0.8741092636579575, 0.015665796344647497, 0.7000000000000001,
    0.36206896551724155, 0.9559228650137742, 0.0, 0.08571428571428581, 1.0, 0.0,
    0.0, 0.6176470588235293, 0.7794117647058822, 0.9966101694915255, 1.0, 0.0,
    0.0, 1.0, 0.5625, 0.9722222222222222, 1.0, 0.923076923076923, 0.0, 1.0, 1.0,
    0.5, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[33] = { 6, 0, 10, 4, 3, 1, 8, 8, 1, 0, 3, 0, 0, 0, 3, 7,
    9, 0, 0, 0, 0, 10, 3, 0, 6, 0, 0, 0, 4, 0, 0, 0, 0 };

  static const int8_T d[66] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0, 0,
    0, 0, 0, 0, 0, 26, 27, 28, 29, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 32, 33, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 33U * sizeof(real_T));
  for (i = 0; i < 33; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 99U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 33; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 66; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 33; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.36333333333333334;
  obj_Prior[1] = 0.31333333333333335;
  obj_Prior[2] = 0.3233333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_lj(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69])
{
  int32_T i;
  static const real_T tmp[23] = { 0.13360890391781266, 9.306706460588597, 0.0,
    2.86829968722897, 283.8475795830599, 9.224376248453815, 2.924390028631521,
    9.925065654659175, 0.0, 2.3116383557990403, 1.6583994740529104, 0.0, 0.0,
    1.5110043878017405, 0.0, 0.0, 2.4537602123251503, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T tmp_0[23] = { false, false, true, false, false, false,
    false, false, true, false, false, true, true, false, true, true, false, true,
    true, true, true, true, true };

  static const real_T tmp_1[69] = { 0.33166666666666667, 0.49440993788819865,
    0.0, 0.9271356783919599, 0.0712530712530711, 0.9627659574468086,
    0.3181818181818182, 0.10545454545454563, 0.0, 0.9805555555555555, 0.5625,
    0.0, 1.0, 0.30851063829787245, 0.0, 1.0, 0.8833333333333332, 1.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 0.3291666666666666, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.33916666666666684, 0.5055900621118014, 0.0, 0.07286432160804009,
    0.9287469287469289, 0.03723404255319147, 0.6818181818181819,
    0.8945454545454544, 1.0, 0.01944444444444444, 0.4375, 1.0, 0.0,
    0.6914893617021275, 1.0, 0.0, 0.11666666666666678, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0 };

  static const int8_T c[23] = { 2, 10, 0, 4, 8, 10, 1, 10, 0, 3, 4, 0, 0, 1, 0,
    0, 4, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[46] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 23U * sizeof(real_T));
  for (i = 0; i < 23; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 69U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 23; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 46; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 23; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.33166666666666667;
  obj_Prior[1] = 0.32916666666666666;
  obj_Prior[2] = 0.33916666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_lk(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { 0.1284108347039896, 2.132133153691956, 0.0,
    0.9692581873147478, 2.802471984153243, 0.0, 1.97320438859555,
    2.6375744495104456, 8.806300086149156, 9.679256178546266, 9.531788068198509,
    8.387667500373826, 0.0, 0.0, 0.0, 9.569007953630141, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.3135682282983931, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, false, true, false, false, true,
    false, false, false, false, false, false, true, true, true, false, true,
    true, true, true, true, true, false, true, true };

  static const real_T tmp_1[75] = { 0.33333333333333337, 0.5018820577164367, 0.0,
    0.6267190569744592, 0.28125000000000006, 1.0, 0.5711060948081258,
    0.37563451776649676, 0.07692307692307697, 0.5080645161290321,
    0.9014084507042252, 0.3011363636363631, 1.0, 1.0, 0.0, 0.9742268041237112,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.6666666666666666, 1.0, 0.0,
    0.33583333333333343, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3308333333333333, 0.4981179422835633, 0.0, 0.37328094302554077,
    0.7187499999999999, 0.0, 0.42889390519187415, 0.6243654822335032,
    0.9230769230769231, 0.4919354838709678, 0.09859154929577475,
    0.698863636363637, 0.0, 0.0, 1.0, 0.025773195876288662, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.3333333333333333, 0.0, 1.0 };

  static const int8_T c[25] = { 2, 3, 0, 1, 4, 0, 3, 1, 10, 10, 10, 10, 0, 0, 0,
    10, 0, 0, 0, 0, 0, 0, 3, 0, 0 };

  static const int8_T d[50] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 22, 23, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 24, 25, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3333333333333333;
  obj_Prior[1] = 0.3358333333333333;
  obj_Prior[2] = 0.3308333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_n0(real_T obj_CutPredictorIndex[25],
  real_T obj_Children[50], real_T obj_CutPoint[25], boolean_T obj_NanCutPoints
  [25], boolean_T obj_InfCutPoints[25], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[75])
{
  int32_T i;
  static const real_T tmp[25] = { 1.1181669879141625, 200.88601287161094, 0.0,
    2.549746847719531, 9.223458606838737, 9.835323947967229, 0.0,
    221.740273755605, 0.9428316347887862, 0.0, 0.0, 2.8003819731471014, 0.0, 0.0,
    1.0428531405014967, 8.257427306941421, 0.0, 0.0, 9.569052257509373, 0.0,
    1.6181699921124317, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[25] = { false, false, true, false, false, false,
    true, false, false, true, true, false, true, true, false, false, true, true,
    false, true, false, true, true, true, true };

  static const real_T tmp_1[75] = { 0.3216666666666665, 0.4837092731829571, 0.0,
    0.8358778625954197, 0.3115671641791045, 0.8795180722891565, 0.0,
    0.7978142076502738, 0.05949008498583576, 1.0, 0.0, 0.4126984126984128, 1.0,
    1.0, 0.037681159420289906, 0.7027027027027026, 0.0, 0.0, 0.09219858156028353,
    1.0, 0.3529411764705882, 1.0, 0.0, 1.0, 0.0, 0.3350000000000001, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3433333333333336, 0.5162907268170429,
    0.0, 0.16412213740458023, 0.6884328358208955, 0.12048192771084347, 1.0,
    0.20218579234972622, 0.9405099150141641, 0.0, 1.0, 0.5873015873015872, 0.0,
    0.0, 0.96231884057971, 0.29729729729729737, 1.0, 1.0, 0.9078014184397165,
    0.0, 0.6470588235294117, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T c[25] = { 7, 8, 0, 3, 10, 10, 0, 8, 1, 0, 0, 1, 0, 0, 7,
    10, 0, 0, 10, 0, 1, 0, 0, 0, 0 };

  static const int8_T d[50] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0, 12,
    13, 14, 15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 22,
    23, 0, 0, 24, 25, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 25U * sizeof(real_T));
  for (i = 0; i < 25; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 75U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 25; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 50; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 25; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.32166666666666666;
  obj_Prior[1] = 0.335;
  obj_Prior[2] = 0.3433333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_ha(real_T obj_CutPredictorIndex[23],
  real_T obj_Children[46], real_T obj_CutPoint[23], boolean_T obj_NanCutPoints
  [23], boolean_T obj_InfCutPoints[23], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[69])
{
  int32_T i;
  static const real_T tmp[23] = { 1.1109774680412126, 9.231227964185674,
    0.606264371304185, 2.8031986402244513, 1.1390379669469601, 0.0, 0.0,
    2.3223512103635766, 2.924450409469493, 10.36995633359006, 1.4777445484249094,
    0.0, 2.4584855153828222, 0.0, 0.0, 0.0, 0.0, 9.82715838397763, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T tmp_0[23] = { false, false, false, false, false, true,
    true, false, false, false, false, true, false, true, true, true, true, false,
    true, true, true, true, true };

  static const real_T tmp_1[69] = { 0.33583333333333343, 0.49629629629629624,
    0.002564102564102558, 0.9362244897959184, 0.08373205741626774, 1.0, 0.0,
    0.9754768392370572, 0.36, 0.6944444444444443, 0.026178010471204154, 1.0,
    0.8499999999999999, 0.0, 1.0, 1.0, 0.0, 0.12987012987013002, 0.0, 0.0, 1.0,
    1.0, 0.0, 0.3241666666666665, 0.0, 0.9974358974358973, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.3400000000000002, 0.5037037037037038, 0.0, 0.06377551020408155,
    0.9162679425837323, 0.0, 0.0, 0.02452316076294277, 0.64, 0.30555555555555564,
    0.9738219895287957, 0.0, 0.15000000000000016, 1.0, 0.0, 0.0, 1.0,
    0.87012987012987, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[23] = { 7, 10, 9, 3, 4, 0, 0, 3, 1, 10, 1, 0, 4, 0, 0, 0,
    0, 10, 0, 0, 0, 0, 0 };

  static const int8_T d[46] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0, 12,
    13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 22, 23, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 23U * sizeof(real_T));
  for (i = 0; i < 23; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 69U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 23; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 46; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 23; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3358333333333333;
  obj_Prior[1] = 0.32416666666666666;
  obj_Prior[2] = 0.34;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_cw(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63])
{
  int32_T i;
  static const real_T tmp[21] = { -0.3537642023158249, 0.0, 201.19722832608886,
    3.2051787258304563, 1.0384039843550519, 9.803465110921172, 0.0, 0.0,
    2.1392860696184623, 0.0, 0.0, 9.569052257509373, 8.833448977486228, 0.0,
    0.9693718614450284, 2.4645693805410946, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[21] = { false, true, false, false, false, false,
    true, true, false, true, true, false, false, true, false, false, true, true,
    true, true, true };

  static const real_T tmp_1[63] = { 0.3350000000000001, 0.0, 0.5006226650062267,
    0.8489208633093523, 0.31619047619047636, 0.8613138686131385, 0.0, 1.0,
    0.2673469387755105, 1.0, 0.0, 0.4024390243902434, 0.13114754098360662, 1.0,
    0.006756756756756741, 0.8421052631578946, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.3308333333333333, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3341666666666667, 0.0,
    0.49937733499377335, 0.15107913669064765, 0.6838095238095236,
    0.13868613138686148, 1.0, 0.0, 0.7326530612244896, 0.0, 1.0,
    0.5975609756097565, 0.8688524590163934, 0.0, 0.9932432432432432,
    0.15789473684210537, 1.0, 0.0, 1.0, 1.0, 0.0 };

  static const int8_T c[21] = { 6, 0, 8, 5, 4, 10, 0, 0, 1, 0, 0, 10, 10, 0, 1,
    4, 0, 0, 0, 0, 0 };

  static const int8_T d[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0,
    12, 13, 0, 0, 0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 21U * sizeof(real_T));
  for (i = 0; i < 21; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 63U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.335;
  obj_Prior[1] = 0.3308333333333333;
  obj_Prior[2] = 0.33416666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_pp(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81])
{
  int32_T i;
  static const real_T tmp[27] = { 1.11178076655644, 2.207513081788888, 0.0,
    9.6849546869785, 8.806300086149156, 2.2006392377359623, 1.013481916733125,
    2.4608702530077067, 0.0, 1.5480363111548758, 2.176156332872819, 0.0,
    0.21266239911474297, 2.311594132697694, 0.0, 0.0, 1.6059639299329025, 0.0,
    0.0, 0.0, 0.28061180254524054, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[27] = { false, false, true, false, false, false,
    false, false, true, false, false, true, false, false, true, true, false,
    true, true, true, false, true, true, true, true, true, true };

  static const real_T tmp_1[81] = { 0.3458333333333336, 0.5067155067155068, 0.0,
    0.6486988847583643, 0.23487544483985767, 0.9441340782122905,
    0.06111111111111106, 0.8918918918918918, 0.0, 0.9646017699115044,
    0.5789473684210525, 1.0, 0.0058823529411764644, 0.5555555555555556, 1.0, 1.0,
    0.9130434782608697, 0.0, 1.0, 0.0, 0.14285714285714285, 1.0, 0.0, 0.0, 1.0,
    1.0, 0.0, 0.3174999999999997, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.3366666666666668, 0.49328449328449314, 0.0, 0.3513011152416357,
    0.7651245551601423, 0.05586592178770955, 0.938888888888889,
    0.10810810810810824, 1.0, 0.03539823008849564, 0.42105263157894735, 0.0,
    0.9941176470588236, 0.4444444444444445, 0.0, 0.0, 0.0869565217391303, 1.0,
    0.0, 1.0, 0.8571428571428571, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[27] = { 7, 3, 0, 10, 10, 4, 4, 4, 0, 3, 3, 0, 6, 3, 0, 0,
    1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[54] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25, 0, 0, 0,
    0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 27U * sizeof(real_T));
  for (i = 0; i < 27; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 81U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 27; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 54; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 27; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3458333333333333;
  obj_Prior[1] = 0.3175;
  obj_Prior[2] = 0.33666666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_de(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63])
{
  int32_T i;
  static const real_T tmp[21] = { 0.12514571981995834, 2.132133153691956, 0.0,
    9.569052257509373, 3.027130540898809, 0.0, 1.0829462389307811,
    174.48773486901908, 0.0, 10.36995633359006, 0.0, 0.0, 1.0270187216596396,
    0.0, 0.0, 8.828100429148812, 8.54451666526365, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[21] = { false, false, true, false, false, true,
    false, false, true, false, true, true, false, true, true, false, false, true,
    true, true, true };

  static const real_T tmp_1[63] = { 0.3241666666666665, 0.4899244332493701, 0.0,
    0.6262425447316098, 0.25429553264604815, 1.0, 0.10900473933649288,
    0.31489361702127594, 0.0, 0.6388888888888888, 0.0, 1.0, 0.17435897435897402,
    1.0, 0.0, 0.33783783783783794, 0.07438016528925612, 1.0, 0.0, 1.0, 0.0,
    0.3383333333333335, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33750000000000013,
    0.5100755667506299, 0.0, 0.37375745526839027, 0.7457044673539518, 0.0,
    0.8909952606635071, 0.6851063829787241, 1.0, 0.36111111111111116, 1.0, 0.0,
    0.8256410256410259, 0.0, 1.0, 0.662162162162162, 0.9256198347107438, 0.0,
    1.0, 0.0, 1.0 };

  static const int8_T c[21] = { 2, 3, 0, 10, 4, 0, 3, 8, 0, 10, 0, 0, 7, 0, 0,
    10, 10, 0, 0, 0, 0 };

  static const int8_T d[42] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 14, 15, 0, 0, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 21U * sizeof(real_T));
  for (i = 0; i < 21; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 63U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.32416666666666666;
  obj_Prior[1] = 0.3383333333333333;
  obj_Prior[2] = 0.3375;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_gj(real_T obj_CutPredictorIndex[21],
  real_T obj_Children[42], real_T obj_CutPoint[21], boolean_T obj_NanCutPoints
  [21], boolean_T obj_InfCutPoints[21], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[63])
{
  int32_T i;
  static const real_T tmp[21] = { 1.11178076655644, 9.224373226263262, 0.0,
    2.8675503914487894, 9.92544192570017, 2.32225407810418, 1.024232638559675,
    1.511062601186398, 0.0, 0.0, 0.021581429812874003, 2.989776953819427, 0.0,
    0.0, 0.0, 2.3875598934974565, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[21] = { false, false, true, false, false, false,
    false, false, true, true, false, false, true, true, true, false, true, true,
    true, true, true };

  static const real_T tmp_1[63] = { 0.35166666666666707, 0.5171568627450984, 0.0,
    0.9365853658536587, 0.09359605911330035, 0.981675392670157,
    0.32142857142857145, 0.3423423423423425, 0.0, 1.0, 0.8870967741935483,
    0.45000000000000007, 0.0, 1.0, 0.0, 0.9482758620689654, 0.0, 0.0, 1.0, 0.0,
    1.0, 0.3199999999999998, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.32833333333333325,
    0.48284313725490163, 0.0, 0.06341463414634133, 0.9064039408866997,
    0.018324607329842906, 0.6785714285714286, 0.6576576576576576, 1.0, 0.0,
    0.11290322580645172, 0.55, 1.0, 0.0, 1.0, 0.05172413793103453, 1.0, 1.0, 0.0,
    1.0, 0.0 };

  static const int8_T c[21] = { 7, 10, 0, 4, 10, 1, 7, 3, 0, 0, 2, 4, 0, 0, 0, 1,
    0, 0, 0, 0, 0 };

  static const int8_T d[42] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 21U * sizeof(real_T));
  for (i = 0; i < 21; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 63U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 21; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 42; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 21; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3516666666666667;
  obj_Prior[1] = 0.32;
  obj_Prior[2] = 0.3283333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_gv(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81])
{
  int32_T i;
  static const real_T tmp[27] = { 0.1451661382505707, 9.306706460588597, 0.0,
    2.86829968722897, 1.1407746272472488, 2.1394730316895973, 234.6723801583451,
    1.0150210174042322, 9.561974759101414, 0.0, 8.539625130193475, 0.0, 0.0, 0.0,
    1.113305436543487, 1.0379227501203776, 1.0827367186520593, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 206.57273168395844, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[27] = { false, false, true, false, false, false,
    false, false, false, true, false, true, true, true, false, false, false,
    true, true, true, true, true, true, false, true, true, true };

  static const real_T tmp_1[81] = { 0.3458333333333336, 0.5048661800486619, 0.0,
    0.9178743961352659, 0.08578431372549003, 0.9589743589743591, 0.25, 0.6,
    0.029891304347826077, 1.0, 0.8222222222222221, 0.0, 1.0, 1.0,
    0.42857142857142855, 0.2500000000000001, 0.006024096385542178, 1.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.5, 0.0, 1.0, 0.0, 0.31499999999999967, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33916666666666684, 0.4951338199513381,
    0.0, 0.08212560386473411, 0.91421568627451, 0.04102564102564098, 0.75,
    0.40000000000000013, 0.970108695652174, 0.0, 0.177777777777778, 1.0, 0.0,
    0.0, 0.5714285714285714, 0.7499999999999999, 0.9939759036144579, 0.0, 1.0,
    1.0, 0.0, 1.0, 0.0, 0.5000000000000001, 1.0, 0.0, 1.0 };

  static const int8_T c[27] = { 2, 10, 0, 4, 4, 3, 8, 4, 10, 0, 10, 0, 0, 0, 4,
    7, 1, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0 };

  static const int8_T d[54] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 24, 25, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 27U * sizeof(real_T));
  for (i = 0; i < 27; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 81U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 27; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 54; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 27; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3458333333333333;
  obj_Prior[1] = 0.315;
  obj_Prior[2] = 0.33916666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_pa(real_T obj_CutPredictorIndex[35],
  real_T obj_Children[70], real_T obj_CutPoint[35], boolean_T obj_NanCutPoints
  [35], boolean_T obj_InfCutPoints[35], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[105])
{
  int32_T i;
  static const real_T tmp[35] = { -0.3797104313870286, 0.0, 2.2794954773697804,
    0.972119438107639, 3.033031748537292, 0.0, 1.021437954245018,
    171.60254358148222, 8.545119256928768, 0.0, 259.9899214982819, 0.0,
    8.806040055254027, 0.0, 2.995958314764893, 9.679256178546266, 0.0,
    2.3917923643069003, 0.0, 0.0, 2.9885977598810647, 2.132133153691956, 0.0,
    0.0, 0.0, 0.0, 0.0, 9.572909984358514, 2.176299785888614, 0.0,
    1.0569149926037338, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[35] = { false, true, false, false, false, true,
    false, false, false, true, false, true, false, true, false, false, true,
    false, true, true, false, false, true, true, true, true, true, false, false,
    true, false, true, true, true, true };

  static const real_T tmp_1[105] = { 0.34666666666666696, 0.0,
    0.5154894671623299, 0.6431226765799257, 0.26022304832713744, 1.0,
    0.5733333333333327, 0.17415730337078605, 0.42857142857142866, 0.0,
    0.5986078886310896, 1.0, 0.08695652173913025, 1.0, 0.037037037037037084,
    0.7456647398843925, 0.0, 0.7777777777777778, 0.0, 0.0, 0.16666666666666669,
    0.934782608695652, 0.0, 0.0, 1.0, 1.0, 0.0, 0.9683794466403162,
    0.5652173913043479, 1.0, 0.7241379310344827, 0.0, 1.0, 0.0, 1.0,
    0.3274999999999999, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3258333333333332, 0.0,
    0.4845105328376701, 0.3568773234200744, 0.7397769516728625, 0.0,
    0.4266666666666673, 0.825842696629214, 0.5714285714285714, 1.0,
    0.40139211136891034, 0.0, 0.9130434782608698, 0.0, 0.962962962962963,
    0.2543352601156074, 1.0, 0.2222222222222222, 1.0, 1.0, 0.8333333333333333,
    0.065217391304348, 1.0, 1.0, 0.0, 0.0, 1.0, 0.031620553359683876,
    0.4347826086956522, 0.0, 0.27586206896551724, 1.0, 0.0, 1.0, 0.0 };

  static const int8_T c[35] = { 6, 0, 4, 1, 5, 0, 3, 8, 10, 0, 8, 0, 10, 0, 4,
    10, 0, 3, 0, 0, 1, 3, 0, 0, 0, 0, 0, 10, 3, 0, 7, 0, 0, 0, 0 };

  static const int8_T d[70] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25,
    0, 0, 0, 0, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 0,
    0, 34, 35, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 35U * sizeof(real_T));
  for (i = 0; i < 35; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 105U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 35; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 70; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 35; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.3466666666666667;
  obj_Prior[1] = 0.3275;
  obj_Prior[2] = 0.3258333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Com_f(real_T obj_CutPredictorIndex[27],
  real_T obj_Children[54], real_T obj_CutPoint[27], boolean_T obj_NanCutPoints
  [27], boolean_T obj_InfCutPoints[27], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[81])
{
  int32_T i;
  static const real_T tmp[27] = { 0.13360890391781266, 200.79403359949305, 0.0,
    9.789531920395646, 1.0397693952070517, 0.0272082358332921, 0.0, 0.0,
    266.3462106818078, 0.0, 0.0, 9.223526329417794, 0.0, 2.86829968722897,
    1.4439472823462287, 221.80492291446487, 2.924450409469493,
    1.4270154231135999, 0.0, 214.27885028860368, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const boolean_T tmp_0[27] = { false, false, true, false, false, false,
    true, true, false, true, true, false, true, false, false, false, false,
    false, true, false, true, true, true, true, true, true, true };

  static const real_T tmp_1[81] = { 0.3400000000000002, 0.4921592279855246, 0.0,
    0.8273381294964027, 0.32304900181488183, 0.9956709956709957, 0.0, 1.0,
    0.26719056974459743, 1.0, 0.0, 0.38309859154929665, 0.0, 0.83448275862069,
    0.07142857142857147, 0.9322033898305085, 0.40740740740740744,
    0.28846153846153866, 0.0, 0.7575757575757575, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0, 0.3091666666666662, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.3508333333333337, 0.5078407720144754, 0.0, 0.17266187050359727,
    0.6769509981851181, 0.004329004329004338, 1.0, 0.0, 0.7328094302554026, 0.0,
    1.0, 0.6169014084507034, 1.0, 0.1655172413793101, 0.9285714285714285,
    0.06779661016949146, 0.5925925925925927, 0.7115384615384613, 1.0,
    0.2424242424242425, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T c[27] = { 2, 8, 0, 10, 4, 2, 0, 0, 8, 0, 0, 10, 0, 4, 3, 8,
    1, 3, 0, 8, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[54] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0,
    12, 13, 0, 0, 0, 0, 14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,
    0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 27U * sizeof(real_T));
  for (i = 0; i < 27; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 81U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 27; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 54; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 27; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.34;
  obj_Prior[1] = 0.30916666666666665;
  obj_Prior[2] = 0.35083333333333333;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_o4(real_T obj_CutPredictorIndex[31],
  real_T obj_Children[62], real_T obj_CutPoint[31], boolean_T obj_NanCutPoints
  [31], boolean_T obj_InfCutPoints[31], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[93])
{
  int32_T i;
  static const real_T tmp[31] = { 1.1088530839786763, 9.292148139465922,
    0.11016240646859886, 2.800822820729299, 1.0828800520827715, 0.0, 0.0,
    2.3222731129883636, 2.9944189705488813, 207.99185181015292,
    0.01936918836256723, 0.0, 8.544553492799327, 0.0, 2.994250575511324, 0.0,
    10.357864972870786, 9.425688419217071, 9.561930455222182, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 9.524797718363523, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[31] = { false, false, false, false, false, true,
    true, false, false, false, false, true, false, true, false, true, false,
    false, false, true, true, true, true, true, true, true, true, false, true,
    true, true };

  static const real_T tmp_1[93] = { 0.3141666666666663, 0.4839124839124836,
    0.0023640661938534187, 0.9342465753424657, 0.08495145631067944, 1.0, 0.0,
    0.976401179941003, 0.3846153846153846, 0.5952380952380952,
    0.02702702702702701, 1.0, 0.8688524590163933, 0.0, 0.8333333333333333, 1.0,
    0.3703703703703704, 0.6666666666666666, 0.021798365122615796, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.18181818181818196, 0.0, 0.0, 1.0,
    0.35166666666666707, 0.0, 0.9976359338061466, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3341666666666667, 0.5160875160875165,
    0.0, 0.06575342465753427, 0.9150485436893206, 0.0, 0.0, 0.023598820058997088,
    0.6153846153846154, 0.40476190476190493, 0.9729729729729729, 0.0,
    0.13114754098360668, 1.0, 0.16666666666666669, 0.0, 0.6296296296296297,
    0.33333333333333337, 0.9782016348773842, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0, 0.8181818181818181, 1.0, 1.0, 0.0 };

  static const int8_T c[31] = { 7, 10, 2, 1, 1, 0, 0, 1, 4, 8, 2, 0, 10, 0, 5, 0,
    10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0 };

  static const int8_T d[62] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0, 12,
    13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 0, 0, 22, 23, 0, 0, 24, 25, 26, 27,
    28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0,
    0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 31U * sizeof(real_T));
  for (i = 0; i < 31; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 93U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 31; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 62; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 31; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.31416666666666665;
  obj_Prior[1] = 0.3516666666666667;
  obj_Prior[2] = 0.33416666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactClassificationTree_Co_ba(real_T obj_CutPredictorIndex[19],
  real_T obj_Children[38], real_T obj_CutPoint[19], boolean_T obj_NanCutPoints
  [19], boolean_T obj_InfCutPoints[19], int32_T obj_ClassNamesLength[3],
  c_classreg_learning_coderutil_T *obj_ScoreTransform, real_T obj_Prior[3],
  boolean_T obj_ClassLogicalIndices[3], real_T obj_Cost[9], real_T
  obj_ClassProbability[57])
{
  int32_T i;
  static const real_T tmp[19] = { 0.12430467894213318, 2.132133153691956, 0.0,
    9.569007953630141, 8.806236481669528, 0.0, 0.9693718614450284,
    2.387642110181759, 0.0, 0.0, 9.679150340738417, 2.32225407810418, 0.0,
    1.3132378479357352, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T tmp_0[19] = { false, false, true, false, false, true,
    false, false, true, true, false, false, true, false, true, true, true, true,
    true };

  static const real_T tmp_1[57] = { 0.32666666666666655, 0.4943253467843631, 0.0,
    0.6200787401574798, 0.27017543859649124, 1.0, 0.09389671361502351,
    0.8953488372093021, 0.0, 1.0, 0.03500000000000002, 0.7, 1.0,
    0.3043478260869565, 0.0, 1.0, 0.0, 1.0, 0.0, 0.33916666666666684, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.3341666666666667, 0.505674653215637, 0.0, 0.37992125984252023,
    0.7298245614035088, 0.0, 0.9061032863849765, 0.10465116279069778, 1.0, 0.0,
    0.965, 0.30000000000000004, 0.0, 0.6956521739130435, 1.0, 0.0, 1.0, 0.0, 1.0
  };

  static const int8_T c[19] = { 2, 3, 0, 10, 10, 0, 1, 3, 0, 0, 10, 1, 0, 1, 0,
    0, 0, 0, 0 };

  static const int8_T d[38] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 0, 0, 14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T h[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  memcpy(&obj_CutPoint[0], &tmp[0], 19U * sizeof(real_T));
  for (i = 0; i < 19; i++) {
    obj_NanCutPoints[i] = tmp_0[i];
  }

  memcpy(&obj_ClassProbability[0], &tmp_1[0], 57U * sizeof(real_T));
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ClassNamesLength[2] = 1;
  obj_ClassLogicalIndices[2] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 19; i++) {
    obj_CutPredictorIndex[i] = c[i];
  }

  for (i = 0; i < 38; i++) {
    obj_Children[i] = d[i];
  }

  for (i = 0; i < 19; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.32666666666666666;
  obj_Prior[1] = 0.33916666666666667;
  obj_Prior[2] = 0.33416666666666667;
  for (i = 0; i < 9; i++) {
    obj_Cost[i] = h[i];
  }
}

/* Function for MATLAB Function: '<Root>/ElectricalDetector' */
static void CompactEnsemble_ensemblePredi_j(const boolean_T obj_IsCached[50],
  const real_T X[10], real_T score[3])
{
  real_T assign_temp_ClassProbability_4[153];
  real_T assign_temp_ClassProbability_6[135];
  real_T assign_temp_ClassProbability_a[105];
  real_T assign_temp_Children_1[102];
  real_T assign_temp_ClassProbability[99];
  real_T assign_temp_ClassProbability_2[93];
  real_T kb[90];
  real_T assign_temp_ClassProbability_7[87];
  real_T assign_temp_ClassProbability_8[81];
  real_T assign_temp_ClassProbability_0[75];
  real_T e[70];
  real_T assign_temp_ClassProbability_5[69];
  real_T r[66];
  real_T assign_temp_ClassProbability_9[63];
  real_T pc[62];
  real_T dc[58];
  real_T assign_temp_ClassProbability_3[57];
  real_T qb[54];
  real_T assign_temp_ClassProbability_1[51];
  real_T assign_temp_CutPoint_4[51];
  real_T x[50];
  real_T cd[46];
  real_T assign_temp_CutPoint_6[45];
  real_T jb[45];
  real_T jc[42];
  real_T assign_temp_Children_0[38];
  real_T assign_temp_CutPoint_a[35];
  real_T d[35];
  real_T assign_temp_Children[34];
  real_T assign_temp_CutPoint[33];
  real_T q[33];
  real_T assign_temp_CutPoint_2[31];
  real_T oc[31];
  real_T assign_temp_CutPoint_7[29];
  real_T cc[29];
  real_T assign_temp_CutPoint_8[27];
  real_T pb[27];
  real_T assign_temp_CutPoint_0[25];
  real_T w[25];
  real_T assign_temp_CutPoint_5[23];
  real_T bd[23];
  real_T assign_temp_CutPoint_9[21];
  real_T ic[21];
  real_T assign_temp_CutPoint_3[19];
  real_T assign_temp_CutPredictorIndex_0[19];
  real_T assign_temp_CutPoint_1[17];
  real_T assign_temp_CutPredictorIndex[17];
  real_T assign_temp_Cost[9];
  real_T cachedScore[3];
  real_T cachedWeights;
  c_classreg_learning_coderutil_T expl_temp_1;
  int32_T expl_temp_0[3];
  int32_T i;
  boolean_T assign_temp_NanCutPoints_4[51];
  boolean_T expl_temp_7[51];
  boolean_T assign_temp_NanCutPoints_6[45];
  boolean_T expl_temp_9[45];
  boolean_T assign_temp_NanCutPoints_a[35];
  boolean_T expl_temp_d[35];
  boolean_T assign_temp_NanCutPoints[33];
  boolean_T expl_temp[33];
  boolean_T assign_temp_NanCutPoints_2[31];
  boolean_T expl_temp_5[31];
  boolean_T assign_temp_NanCutPoints_7[29];
  boolean_T expl_temp_a[29];
  boolean_T assign_temp_NanCutPoints_8[27];
  boolean_T expl_temp_b[27];
  boolean_T assign_temp_NanCutPoints_0[25];
  boolean_T expl_temp_3[25];
  boolean_T assign_temp_NanCutPoints_5[23];
  boolean_T expl_temp_8[23];
  boolean_T assign_temp_NanCutPoints_9[21];
  boolean_T expl_temp_c[21];
  boolean_T assign_temp_NanCutPoints_3[19];
  boolean_T expl_temp_6[19];
  boolean_T assign_temp_NanCutPoints_1[17];
  boolean_T expl_temp_4[17];
  boolean_T expl_temp_2[3];
  boolean_T b;
  static const int8_T i_0[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  static const int8_T d_0[35] = { 2, 10, 0, 3, 7, 1, 8, 1, 1, 0, 10, 0, 0, 1, 0,
    0, 3, 0, 0, 7, 3, 0, 6, 0, 7, 0, 10, 0, 0, 0, 9, 0, 0, 0, 0 };

  static const int8_T e_0[70] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0,
    0, 0, 24, 25, 26, 27, 0, 0, 28, 29, 0, 0, 30, 31, 0, 0, 32, 33, 0, 0, 0, 0,
    0, 0, 34, 35, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const char_T combiner[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
    'A', 'v', 'e', 'r', 'a', 'g', 'e' };

  static const real_T c[35] = { 0.13460875486096524, 9.305830444589635, 0.0,
    2.8031986402244513, 1.0674560471090628, 2.1392860696184623, 234.793061066681,
    1.4777445484249094, 0.947428726950736, 0.0, 8.54451666526365, 0.0, 0.0,
    1.4271753999176573, 0.0, 0.0, 1.034001678580573, 0.0, 0.0,
    1.0625525760462686, 1.4322056790758741, 0.0, 0.07859170157669286, 0.0,
    1.0628971567273682, 0.0, 10.665012288691019, 0.0, 0.0, 0.0,
    0.4932383849085732, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T f[35] = { false, false, true, false, false, false,
    false, false, false, true, false, true, true, false, true, true, false, true,
    true, false, false, true, false, true, false, true, false, true, true, true,
    false, true, true, true, true };

  static const real_T g[105] = { 0.3166666666666664, 0.48655569782330316, 0.0,
    0.8994845360824743, 0.07888040712468183, 0.952112676056338,
    0.33333333333333337, 0.03966005665722383, 0.4250000000000001, 1.0,
    0.7848101265822782, 0.0, 1.0, 0.1891891891891894, 0.0, 1.0,
    0.2333333333333334, 1.0, 0.0, 0.03703703703703708, 0.6, 0.0, 0.4375, 0.0,
    0.16666666666666666, 1.0, 0.3846153846153846, 1.0, 0.0, 1.0,
    0.0909090909090909, 1.0, 0.0, 1.0, 0.0, 0.349166666666667, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.3341666666666667, 0.5134443021766968, 0.0, 0.10051546391752572,
    0.9211195928753182, 0.04788732394366202, 0.6666666666666666,
    0.9603399433427762, 0.575, 0.0, 0.21518987341772175, 1.0, 0.0,
    0.8108108108108106, 1.0, 0.0, 0.7666666666666666, 0.0, 1.0,
    0.962962962962963, 0.4, 1.0, 0.5625, 1.0, 0.8333333333333333, 0.0,
    0.6153846153846154, 0.0, 1.0, 0.0, 0.9090909090909091, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T k[35] = { 6, 0, 3, 9, 10, 10, 10, 1, 0, 1, 4, 10, 4, 1, 0,
    0, 3, 0, 10, 0, 7, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T l[70] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 26, 27, 0, 0,
    28, 29, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T j[35] = { -0.3537642023158249, 0.0, 2.2127771460637486,
    0.5120723873657096, 8.806300086149156, 9.569052257509373, 9.62406379039075,
    2.3938427344947635, 0.0, 2.1321167858530043, 1.0114245931330221,
    9.293374095780383, 1.0686192821794953, 2.32225407810418, 0.0, 0.0,
    2.1683299345705698, 0.0, 9.685447440551428, 0.0, 1.042795685970371,
    0.970128744279337, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0603259285419093, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T m[35] = { false, true, false, false, false, false,
    false, false, true, false, false, false, false, false, true, true, false,
    true, false, true, false, false, true, true, true, true, true, false, true,
    true, true, true, true, true, true };

  static const real_T n[105] = { 0.3166666666666664, 0.0, 0.4797979797979794,
    0.5962616822429905, 0.23735408560311275, 0.64142538975501,
    0.36046511627906985, 0.8591549295774646, 0.0, 0.9787985865724381,
    0.06626506024096374, 0.9666666666666667, 0.035714285714285754,
    0.47368421052631576, 1.0, 1.0, 0.5, 1.0, 0.012738853503184686, 1.0,
    0.6666666666666667, 0.4000000000000001, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.16666666666666666, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.3400000000000002,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.3433333333333336, 0.0, 0.5202020202020207,
    0.4037383177570096, 0.7626459143968873, 0.3585746102449901,
    0.6395348837209301, 0.14084507042253536, 1.0, 0.02120141342756191,
    0.9337349397590363, 0.033333333333333354, 0.9642857142857143,
    0.5263157894736842, 0.0, 0.0, 0.5, 0.0, 0.9872611464968152, 0.0,
    0.33333333333333337, 0.6000000000000001, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.8333333333333333, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 };

  static const int8_T q_0[33] = { 2, 10, 0, 1, 1, 4, 8, 8, 7, 0, 1, 0, 0, 0, 8,
    0, 7, 0, 0, 0, 0, 0, 5, 2, 3, 0, 0, 0, 3, 10, 0, 0, 0 };

  static const int8_T r_0[66] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 22, 23, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 24, 25, 26, 27, 28, 29, 0, 0, 0, 0, 0, 0, 30, 31, 32,
    33, 0, 0, 0, 0, 0, 0 };

  static const real_T p[33] = { 0.13360890391781266, 9.224376248453815, 0.0,
    2.803129322699013, 1.0736897167811716, 2.3859022274339647, 234.6723801583451,
    207.99185181015292, 1.0428531405014967, 0.0, 2.3938830848478623, 0.0, 0.0,
    0.0, 263.5407418631336, 0.0, 1.0436445771355267, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.764592560869315, 0.03119834122695859, 1.4275661258452126, 0.0, 0.0, 0.0,
    1.434270917126272, 10.665404398100916, 0.0, 0.0, 0.0 };

  static const boolean_T s[33] = { false, false, true, false, false, false,
    false, false, false, true, false, true, true, true, false, true, false, true,
    true, true, true, true, false, false, false, true, true, true, false, false,
    true, true, true };

  static const real_T t[99] = { 0.3433333333333336, 0.5182389937106922, 0.0,
    0.9348370927318297, 0.09848484848484838, 0.9731182795698924,
    0.40740740740740744, 0.509090909090909, 0.03225806451612908, 1.0,
    0.8245614035087718, 0.0, 1.0, 1.0, 0.28947368421052644, 0.0,
    0.09999999999999995, 0.0, 1.0, 0.0, 1.0, 1.0, 0.05714285714285711,
    0.21428571428571427, 0.03296703296703297, 1.0, 0.0, 0.0, 0.06976744186046516,
    0.7499999999999999, 0.0, 1.0, 0.0, 0.33750000000000013, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31916666666666643, 0.4817610062893078, 0.0, 0.06516290726817031,
    0.9015151515151516, 0.026881720430107506, 0.5925925925925927,
    0.4909090909090909, 0.967741935483871, 0.0, 0.17543859649122823, 1.0, 0.0,
    0.0, 0.7105263157894736, 1.0, 0.9, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.9428571428571428, 0.7857142857142858, 0.967032967032967, 0.0, 1.0, 1.0,
    0.9302325581395348, 0.25, 1.0, 0.0, 1.0 };

  static const int8_T w_0[25] = { 6, 0, 10, 3, 1, 0, 8, 8, 4, 0, 10, 0, 3, 10, 0,
    0, 4, 0, 0, 0, 0, 0, 10, 0, 0 };

  static const int8_T x_0[50] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 24, 25, 0, 0, 0, 0 };

  static const real_T v[25] = { -0.3537642023158249, 0.0, 9.305830444589635,
    2.131019736349559, 1.0827367186520593, 0.0, 201.19722832608886,
    206.83773192070367, 1.5181785970813864, 0.0, 8.544553492799327, 0.0,
    0.9696220368222984, 9.79683242205153, 0.0, 0.0, 2.9932392733905533, 0.0, 0.0,
    0.0, 0.0, 0.0, 8.887160857441081, 0.0, 0.0 };

  static const boolean_T y[25] = { false, true, false, false, false, true, false,
    false, false, true, false, true, false, false, true, true, false, true, true,
    true, true, true, false, true, true };

  static const real_T ab[75] = { 0.3325, 0.0, 0.5121951219512197,
    0.9039408866995076, 0.08579088471849866, 1.0, 0.6976744186046513,
    0.6341463414634145, 0.01807228915662654, 1.0, 0.5517241379310345, 1.0,
    0.4230769230769231, 0.09090909090909101, 0.0, 1.0, 0.2641509433962266, 1.0,
    0.0, 1.0, 0.0, 0.0, 0.9333333333333333, 1.0, 0.0, 0.3508333333333337, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3166666666666664, 0.0,
    0.48780487804878025, 0.09605911330049245, 0.9142091152815013, 0.0,
    0.30232558139534865, 0.36585365853658547, 0.9819277108433735, 0.0,
    0.44827586206896564, 0.0, 0.576923076923077, 0.9090909090909091, 1.0, 0.0,
    0.7358490566037734, 0.0, 1.0, 0.0, 1.0, 1.0, 0.06666666666666665, 0.0, 1.0 };

  static const int8_T db[35] = { 6, 0, 4, 10, 8, 4, 1, 0, 3, 3, 10, 0, 0, 3, 0,
    0, 1, 0, 0, 3, 1, 0, 0, 0, 3, 0, 9, 0, 4, 0, 0, 3, 0, 0, 0 };

  static const int8_T eb[70] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0,
    0, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 0,
    0, 24, 25, 26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 30, 31, 0, 0, 32, 33, 0,
    0, 0, 0, 34, 35, 0, 0, 0, 0, 0, 0 };

  static const real_T cb[35] = { -0.3522089548379009, 0.0, 2.2794954773697804,
    9.6849546869785, 171.9093328681921, 2.2006392377359623, 0.9692581873147478,
    0.0, 2.946133914800475, 1.5480363111548758, 8.701096097954242, 0.0, 0.0,
    2.924460736764691, 0.0, 0.0, 1.6004976244329148, 0.0, 0.0,
    2.4109250648987306, 2.931932468007499, 0.0, 0.0, 0.0, 2.4205501683662085,
    0.0, 0.5390214714826573, 0.0, 2.8065293023525255, 0.0, 0.0,
    2.6545518079800807, 0.0, 0.0, 0.0 };

  static const boolean_T fb[35] = { false, true, false, false, false, false,
    false, true, false, false, false, true, true, false, true, true, false, true,
    true, false, false, true, true, true, false, true, false, true, false, true,
    true, false, true, true, true };

  static const real_T gb[105] = { 0.3416666666666669, 0.0, 0.5137844611528825,
    0.657142857142857, 0.23809523809523805, 0.9622093023255812,
    0.07734806629834247, 1.0, 0.14049586776859507, 0.9846625766871165,
    0.5555555555555556, 1.0, 0.0, 0.19653179190751396, 0.0, 1.0,
    0.9657534246575343, 1.0, 0.0, 0.14285714285714257, 0.9166666666666666, 0.0,
    1.0, 0.0, 0.212962962962963, 1.0, 0.5000000000000001, 1.0,
    0.12371134020618563, 1.0, 0.0, 0.23529411764705896, 0.0, 0.0, 1.0,
    0.3350000000000001, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.32333333333333314, 0.0,
    0.4862155388471175, 0.3428571428571431, 0.7619047619047619,
    0.03779069767441866, 0.9226519337016575, 0.0, 0.8595041322314049,
    0.01533742331288347, 0.4444444444444445, 0.0, 1.0, 0.803468208092486, 1.0,
    0.0, 0.034246575342465675, 0.0, 1.0, 0.8571428571428575, 0.08333333333333333,
    1.0, 0.0, 1.0, 0.787037037037037, 0.0, 0.5, 0.0, 0.8762886597938144, 0.0,
    1.0, 0.764705882352941, 1.0, 1.0, 0.0 };

  static const int8_T jb_0[45] = { 7, 3, 0, 8, 10, 5, 0, 7, 4, 0, 8, 10, 4, 0, 1,
    8, 8, 3, 0, 0, 7, 1, 0, 0, 2, 3, 10, 0, 0, 3, 1, 0, 0, 0, 8, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0 };

  static const int8_T kb_0[90] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0,
    12, 13, 14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 26, 27,
    28, 29, 0, 0, 0, 0, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 36, 37, 38, 39, 0, 0,
    0, 0, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T ib[45] = { 1.1109774680412126, 1.4324858647214467, 0.0,
    287.7400404287654, 9.223636380475329, 2.7668618293093523, 0.0,
    1.0271134217451727, 1.4971094226074189, 0.0, 199.5576732063355,
    8.833448977486228, 2.392910118493772, 0.0, 1.4777445484249094,
    194.5157319490243, 235.41105505920115, 2.388907770912672, 0.0, 0.0,
    1.0302093925264717, 1.463747383156739, 0.0, 0.0, 0.020125247657139494,
    0.9326589794180721, 10.372654545092256, 0.0, 0.0, 2.3939330653665127,
    2.3875855224028966, 0.0, 0.0, 0.0, 195.71896528765558, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T lb[45] = { false, false, true, false, false, false,
    true, false, false, true, false, false, false, true, false, false, false,
    false, true, true, false, false, true, true, false, false, false, true, true,
    false, false, true, true, true, false, true, true, true, true, true, true,
    true, true, true, true };

  static const real_T mb[135] = { 0.3475000000000003, 0.5271807838179525, 0.0,
    0.7991266375545854, 0.4163701067615657, 0.8433179723502305, 0.0,
    0.9023437499999999, 0.009803921568627487, 0.0, 0.8551401869158879,
    0.7017543859649121, 0.9597989949748744, 1.0, 0.006557377049180353,
    0.9496402877697843, 0.6799999999999998, 0.9302325581395348, 0.0, 1.0,
    0.7777777777777777, 0.15384615384615385, 0.0, 1.0, 0.8727272727272726,
    0.3103448275862069, 0.9130434782608695, 0.0, 1.0, 0.9259259259259259,
    0.33333333333333337, 0.0, 1.0, 1.0, 0.631578947368421, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.34083333333333354, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.31166666666666626,
    0.4728192161820475, 0.0, 0.20087336244541465, 0.5836298932384343,
    0.15668202764976946, 1.0, 0.09765625000000015, 0.9901960784313725, 1.0,
    0.14485981308411205, 0.2982456140350879, 0.04020100502512564, 0.0,
    0.9934426229508198, 0.050359712230215736, 0.3200000000000002,
    0.06976744186046517, 1.0, 0.0, 0.22222222222222232, 0.8461538461538461, 1.0,
    0.0, 0.12727272727272737, 0.6896551724137931, 0.08695652173913052, 1.0, 0.0,
    0.0740740740740741, 0.6666666666666667, 1.0, 0.0, 0.0, 0.3684210526315789,
    0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 };

  static const int8_T pb_0[27] = { 6, 0, 4, 8, 10, 10, 0, 0, 10, 1, 4, 8, 0, 1,
    8, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 };

  static const int8_T qb_0[54] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0,
    0, 12, 13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25, 0, 0,
    0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T ob[27] = { -0.3529702532922346, 0.0, 2.2776527873912955,
    287.7182385958211, 8.539661957729152, 9.685858536031336, 0.0, 0.0,
    8.834555229671569, 2.1392860696184623, 1.012963693804129, 238.79434062512888,
    0.0, 1.5480445757810397, 191.31093692487156, 0.0, 0.9696220368222984, 0.0,
    0.0, 0.0, 1.606100249862549, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T rb[27] = { false, true, false, false, false, false,
    true, true, false, false, false, false, true, false, false, true, false,
    true, true, true, false, true, true, true, true, true, true };

  static const real_T sb[81] = { 0.33583333333333343, 0.0, 0.4920634920634919,
    0.6259689922480616, 0.2640264026402642, 0.709890109890109, 0.0, 1.0,
    0.038793103448275926, 0.9456193353474318, 0.08064516129032248,
    0.3333333333333333, 0.0, 0.9703947368421051, 0.6666666666666666, 1.0,
    0.008695652173913031, 0.0, 1.0, 1.0, 0.9262295081967213, 1.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.3174999999999997, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.34666666666666696, 0.0, 0.5079365079365081, 0.37403100775193837,
    0.7359735973597359, 0.29010989010989097, 1.0, 0.0, 0.9612068965517241,
    0.05438066465256813, 0.9193548387096775, 0.6666666666666666, 1.0,
    0.029605263157894846, 0.3333333333333333, 0.0, 0.9913043478260869, 1.0, 0.0,
    0.0, 0.0737704918032786, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0 };

  static const int8_T vb[25] = { 2, 3, 0, 10, 3, 8, 3, 10, 8, 0, 10, 0, 0, 0, 0,
    0, 6, 0, 0, 8, 8, 0, 0, 0, 0 };

  static const int8_T wb[50] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0, 0, 0,
    0, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T ub[25] = { 0.16256738338558754, 2.1393951435261256, 0.0,
    9.679256178546266, 2.7106635288176593, 219.25985870570074,
    0.9696220368222984, 8.539661957729152, 254.97299513241, 0.0,
    9.573223952732857, 0.0, 0.0, 0.0, 0.0, 0.0, 0.014759130209773694, 0.0, 0.0,
    267.08297746857363, 266.3443078657572, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T xb[25] = { false, false, true, false, false, false,
    false, false, false, true, false, true, true, true, true, true, false, true,
    true, false, false, true, true, true, true };

  static const real_T yb[75] = { 0.35000000000000037, 0.49469964664310945, 0.0,
    0.6324626865671641, 0.258785942492013, 0.9760479041916168,
    0.06435643564356437, 0.341121495327102, 0.08080808080808081, 1.0,
    0.9365079365079366, 1.0, 0.0, 1.0, 0.0, 0.0, 0.19047619047619063, 1.0, 0.0,
    0.4666666666666667, 0.037037037037037056, 1.0, 0.0, 1.0, 0.0,
    0.2924999999999992, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.35750000000000054, 0.5053003533568906, 0.0, 0.3675373134328359,
    0.7412140575079869, 0.02395209580838328, 0.9356435643564356,
    0.6588785046728981, 0.9191919191919192, 0.0, 0.0634920634920634, 0.0, 1.0,
    0.0, 1.0, 1.0, 0.8095238095238094, 0.0, 1.0, 0.5333333333333333,
    0.962962962962963, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T cc_0[29] = { 7, 4, 9, 8, 4, 0, 0, 8, 0, 10, 0, 0, 10, 10,
    0, 3, 8, 0, 1, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0 };

  static const int8_T dc_0[58] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0,
    12, 13, 0, 0, 14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0,
    24, 25, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0 };

  static const real_T bc[29] = { 1.1088530839786763, 2.2776527873912955,
    0.606264371304185, 287.5890301582434, 3.0101349903732446, 0.0, 0.0,
    182.41883533561202, 0.0, 8.895140526584003, 0.0, 0.0, 9.569002260223858,
    8.539661957729152, 0.0, 2.132133153691956, 270.10916122854735, 0.0,
    2.6561478684864546, 0.0, 0.0, 1.0738474071807285, 0.0, 0.0, 0.0,
    1.0340860397732272, 0.0, 0.0, 0.0 };

  static const boolean_T ec[29] = { false, false, false, false, false, true,
    true, false, true, false, true, true, false, false, true, false, false, true,
    false, true, true, false, true, true, true, false, true, true, true };

  static const real_T fc[87] = { 0.33166666666666667, 0.49255583126550856,
    0.0025380710659898414, 0.6302681992337162, 0.2394366197183099, 1.0, 0.0,
    0.7262693156732886, 0.0, 0.29437229437229384, 0.0, 1.0, 0.6487252124645885,
    0.8395061728395061, 0.0, 0.9585253456221198, 0.15441176470588217, 1.0, 0.48,
    1.0, 0.0, 0.06504065040650399, 1.0, 0.0, 1.0, 0.3076923076923077, 0.0, 0.0,
    1.0, 0.3274999999999999, 0.0, 0.9974619289340101, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.34083333333333354, 0.5074441687344915, 0.0,
    0.3697318007662838, 0.7605633802816901, 0.0, 0.0, 0.2737306843267115, 1.0,
    0.7056277056277063, 1.0, 0.0, 0.35127478753541164, 0.160493827160494, 1.0,
    0.04147465437788023, 0.8455882352941179, 0.0, 0.5199999999999999, 0.0, 1.0,
    0.934959349593496, 0.0, 1.0, 0.0, 0.6923076923076923, 1.0, 1.0, 0.0 };

  static const int8_T ic_0[21] = { 6, 0, 10, 3, 3, 0, 10, 0, 3, 0, 8, 10, 10, 0,
    0, 0, 0, 10, 0, 0, 0 };

  static const int8_T jc_0[42] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 0,
    0, 12, 13, 0, 0, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 0,
    0, 0, 0, 0, 0 };

  static const real_T hc[21] = { -0.3537642023158249, 0.0, 9.305830444589635,
    2.1394730316895973, 0.9696220368222984, 0.0, 8.539625130193475, 0.0,
    1.0609872703021979, 0.0, 240.78233091964017, 10.228446154322237,
    9.561974759101414, 0.0, 0.0, 0.0, 0.0, 9.51144447686669, 0.0, 0.0, 0.0 };

  static const boolean_T kc[21] = { false, true, false, false, false, true,
    false, true, false, true, false, false, false, true, true, true, true, false,
    true, true, true };

  static const real_T lc[63] = { 0.33333333333333337, 0.0, 0.4987531172069825,
    0.9012048192771087, 0.06718346253229968, 1.0, 0.6339285714285713, 1.0,
    0.037333333333333316, 1.0, 0.1276595744680852, 0.36363636363636365,
    0.016997167138810203, 0.0, 1.0, 1.0, 0.0, 0.18750000000000006, 0.0, 0.0, 1.0,
    0.33166666666666667, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3350000000000001, 0.0,
    0.5012468827930174, 0.09879518072289137, 0.9328165374677003, 0.0,
    0.36607142857142866, 0.0, 0.9626666666666667, 0.0, 0.8723404255319148,
    0.6363636363636364, 0.9830028328611898, 1.0, 0.0, 0.0, 1.0,
    0.8124999999999999, 1.0, 1.0, 0.0 };

  static const int8_T oc_0[31] = { 7, 10, 0, 7, 10, 10, 0, 8, 0, 5, 0, 0, 3, 8,
    3, 0, 0, 0, 2, 0, 0, 7, 7, 4, 0, 0, 9, 0, 0, 0, 0 };

  static const int8_T pc_0[62] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 0, 0,
    12, 13, 0, 0, 14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0,
    22, 23, 0, 0, 0, 0, 24, 25, 26, 27, 28, 29, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const real_T nc[31] = { 1.1141973340137805, 9.305722116009317, 0.0,
    1.0328776503266477, 9.925292565316994, 8.806300086149156, 0.0,
    199.54672631373174, 0.0, 3.172891006388043, 0.0, 0.0, 1.511062601186398,
    214.15499851615715, 2.39188050479327, 0.0, 0.0, 0.0, 0.020476638716766277,
    0.0, 0.0, 1.029243723298621, 1.0271637173110397, 2.5936119558988753, 0.0,
    0.0, 0.4935531149088872, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T qc[31] = { false, false, true, false, false, false,
    true, false, true, false, true, true, false, false, false, true, true, true,
    false, true, true, false, false, false, true, true, false, true, true, true,
    true };

  static const real_T rc[93] = { 0.34500000000000025, 0.5142857142857146, 0.0,
    0.9022004889975551, 0.11363636363636354, 0.7368421052631583, 1.0,
    0.44554455445544555, 0.0, 0.910569105691057, 0.0, 1.0, 0.3488372093023257,
    0.9391304347826088, 0.5, 1.0, 0.0, 1.0, 0.8541666666666665, 0.0, 1.0,
    0.9459459459459459, 0.5454545454545454, 0.875, 1.0, 1.0, 0.16666666666666669,
    0.0, 1.0, 1.0, 0.0, 0.3291666666666666, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3258333333333332,
    0.48571428571428543, 0.0, 0.09779951100244481, 0.8863636363636365,
    0.2631578947368417, 0.0, 0.5544554455445544, 1.0, 0.089430894308943, 1.0,
    0.0, 0.6511627906976742, 0.06086956521739125, 0.5, 0.0, 1.0, 0.0,
    0.14583333333333343, 1.0, 0.0, 0.0540540540540541, 0.45454545454545453,
    0.125, 0.0, 0.0, 0.8333333333333333, 1.0, 0.0, 0.0, 1.0 };

  static const int8_T uc[33] = { 6, 0, 8, 10, 4, 9, 0, 0, 4, 0, 0, 1, 0, 10, 0,
    3, 7, 8, 0, 1, 0, 8, 0, 3, 0, 0, 0, 0, 7, 10, 0, 0, 0 };

  static const int8_T vc[66] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0,
    0, 12, 13, 0, 0, 0, 0, 14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0,
    0, 24, 25, 0, 0, 26, 27, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 30, 31, 32,
    33, 0, 0, 0, 0, 0, 0 };

  static const real_T tc[33] = { -0.3537642023158249, 0.0, 200.79403359949305,
    9.803465110921172, 1.0347467483936703, 0.6905787841149189, 0.0, 0.0,
    3.0101349903732446, 0.0, 0.0, 2.924390028631521, 0.0, 9.229618429154542, 0.0,
    2.801061141998142, 1.0984603712402783, 221.733063043895, 0.0,
    1.478136058679524, 0.0, 214.1570812173905, 0.0, 1.4294399052398654, 0.0, 0.0,
    0.0, 0.0, 1.0593333159363763, 10.65891290554924, 0.0, 0.0, 0.0 };

  static const boolean_T wc[33] = { false, true, false, false, false, false,
    true, true, false, true, true, false, true, false, true, false, false, false,
    true, false, true, false, true, false, true, true, true, true, false, false,
    true, true, true };

  static const real_T xc[99] = { 0.33916666666666684, 0.0, 0.4969474969474969,
    0.8532818532818531, 0.3321428571428568, 0.9954954954954955, 0.0, 1.0,
    0.2793834296724472, 1.0, 0.0, 0.30655391120507486, 0.0, 0.2807017543859656,
    1.0, 0.8125000000000002, 0.03525641025641039, 0.9069767441860467, 0.0,
    0.03215434083601298, 1.0, 0.5862068965517241, 1.0, 0.12048192771084351, 0.0,
    1.0, 0.0, 0.0, 0.5555555555555556, 0.6666666666666666, 0.0, 1.0, 0.0,
    0.3174999999999997, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3433333333333336, 0.0, 0.5030525030525032,
    0.1467181467181468, 0.6678571428571431, 0.004504504504504511, 1.0, 0.0,
    0.7206165703275528, 0.0, 1.0, 0.6934460887949251, 1.0, 0.7192982456140344,
    0.0, 0.1874999999999997, 0.9647435897435896, 0.09302325581395338, 1.0,
    0.9678456591639869, 0.0, 0.4137931034482758, 0.0, 0.8795180722891565, 1.0,
    0.0, 1.0, 1.0, 0.4444444444444445, 0.3333333333333333, 1.0, 0.0, 1.0 };

  static const int8_T bd_0[23] = { 6, 0, 4, 8, 1, 10, 0, 10, 0, 10, 8, 3, 0, 0,
    1, 0, 0, 10, 0, 0, 0, 0, 0 };

  static const int8_T cd_0[46] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0,
    12, 13, 0, 0, 14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 0, 0, 22, 23,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T ad[23] = { -0.3529702532922346, 0.0, 2.2794954773697804,
    287.000065038074, 2.946012206210087, 9.679256178546266, 0.0,
    8.828100429148812, 0.0, 9.231492726563282, 270.10610732235654,
    2.3939330653665127, 0.0, 0.0, 1.511014839488664, 0.0, 0.0, 8.316582600458773,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T dd[23] = { false, true, false, false, false, false,
    true, false, true, false, false, false, true, true, false, true, true, false,
    true, true, true, true, true };

  static const real_T ed[69] = { 0.3533333333333338, 0.0, 0.5183374083129588,
    0.6275229357798165, 0.30036630036630024, 0.7154811715481166, 0.0,
    0.36283185840707893, 0.0, 0.9431818181818181, 0.07936507936507926,
    0.8913043478260869, 0.0, 1.0, 0.6491228070175437, 0.0, 1.0,
    0.5833333333333334, 1.0, 1.0, 0.0, 1.0, 0.0, 0.3183333333333331, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.32833333333333325, 0.0, 0.4816625916870412,
    0.37247706422018345, 0.6996336996336997, 0.2845188284518834, 1.0,
    0.637168141592921, 1.0, 0.05681818181818189, 0.9206349206349208,
    0.10869565217391311, 1.0, 0.0, 0.35087719298245634, 1.0, 0.0,
    0.41666666666666663, 0.0, 0.0, 1.0, 0.0, 1.0 };

  static const int8_T hd[23] = { 2, 10, 0, 3, 1, 1, 1, 0, 3, 0, 3, 0, 9, 10, 0,
    10, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T id[46] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13, 0,
    0, 14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 22, 23, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T gd[23] = { 0.13360890391781266, 9.305722116009317, 0.0,
    2.8031986402244513, 0.9473150528204553, 2.139365535526792, 2.924390028631521,
    0.0, 1.443698287240648, 0.0, 2.3939330653665127, 0.0, 0.5298525596290711,
    9.8401089000259, 0.0, 8.387302706881052, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const boolean_T jd[23] = { false, false, true, false, false, false,
    false, true, false, true, false, true, false, false, true, false, true, true,
    true, true, true, true, true };

  static const real_T kd[69] = { 0.3291666666666666, 0.4993678887484197, 0.0,
    0.8926829268292685, 0.07611548556430442, 0.9517426273458445,
    0.29729729729729737, 1.0, 0.04347826086956522, 1.0, 0.7977528089887639, 0.0,
    0.7857142857142857, 0.16000000000000006, 0.0, 0.41935483870967744, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 0.34083333333333354, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.32999999999999996, 0.5006321112515802, 0.0, 0.10731707317073154,
    0.9238845144356955, 0.048257372654155486, 0.7027027027027026, 0.0,
    0.9565217391304348, 0.0, 0.20224719101123617, 1.0, 0.21428571428571427,
    0.8399999999999999, 1.0, 0.5806451612903226, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0 };

  static const int8_T nd[35] = { 6, 0, 1, 3, 3, 0, 3, 4, 0, 3, 0, 0, 4, 8, 8, 0,
    0, 10, 1, 0, 8, 0, 0, 2, 10, 4, 0, 0, 10, 0, 0, 0, 0, 0, 0 };

  static const int8_T od[70] = { 2, 3, 0, 0, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 0, 0, 14, 15, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 24,
    25, 0, 0, 26, 27, 0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T md[35] = { -0.3537642023158249, 0.0, 2.710214045799864,
    0.9727425606064579, 2.9484438519049525, 0.0, 2.6485259020719063,
    2.9931799884152763, 0.0, 2.281093139863569, 0.0, 0.0, 3.0059727219517485,
    201.01931117784127, 171.8712737617349, 0.0, 0.0, 9.83521811015938,
    1.9414323727498723, 0.0, 214.1549923556148, 0.0, 0.0, 0.01938125954172264,
    9.010273555620145, 2.5639643949303927, 0.0, 0.0, 9.573170789969456, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 };

  static const boolean_T pd[35] = { false, true, false, false, false, true,
    false, false, true, false, true, true, false, false, false, true, true,
    false, false, true, false, true, true, false, false, false, true, true,
    false, true, true, true, true, true, true };

  static const real_T qd[105] = { 0.31499999999999967, 0.0, 0.48337595907928355,
    0.5580693815987946, 0.06722689075630245, 1.0, 0.5157024793388432,
    0.13793103448275876, 0.0, 0.4939550949913644, 1.0, 0.0, 0.8888888888888888,
    0.5560344827586202, 0.24347826086956517, 1.0, 0.0, 0.877450980392157,
    0.3038461538461536, 1.0, 0.10309278350515466, 1.0, 0.0, 0.2191011235955051,
    0.4878048780487805, 0.3448275862068965, 0.0, 1.0, 0.20114942528735583, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 0.34833333333333366, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.3366666666666668, 0.0, 0.5166240409207165, 0.44193061840120546,
    0.9327731092436975, 0.0, 0.48429752066115683, 0.8620689655172412, 1.0,
    0.5060449050086355, 0.0, 1.0, 0.1111111111111111, 0.4439655172413798,
    0.7565217391304349, 0.0, 1.0, 0.12254901960784306, 0.6961538461538465, 0.0,
    0.8969072164948454, 0.0, 1.0, 0.780898876404495, 0.5121951219512195,
    0.6551724137931034, 1.0, 0.0, 0.7988505747126442, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0 };

  static const int8_T td[27] = { 2, 10, 0, 3, 1, 3, 3, 3, 1, 0, 8, 0, 2, 3, 0,
    10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T ud[54] = { 2, 3, 4, 5, 0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25, 0, 0, 0, 0,
    26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T sd[27] = { 0.1295549620997273, 9.224376248453815, 0.0,
    2.8031986402244513, 1.0827367186520593, 2.3129678337495125,
    2.9217540143454768, 1.021437954245018, 1.478136058679524, 0.0,
    214.1549923556148, 0.0, 0.026727526903909987, 0.9696220368222984, 0.0,
    9.796882419337043, 0.0, 0.0, 2.532437908506698, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const boolean_T vd[27] = { false, false, true, false, false, false,
    false, false, false, true, false, true, false, false, true, false, true,
    true, false, true, true, true, true, true, true, true, true };

  static const real_T wd[81] = { 0.3441666666666669, 0.49879227053140096, 0.0,
    0.9238329238329239, 0.08788598574821829, 0.9634464751958225,
    0.2916666666666667, 0.5999999999999999, 0.02659574468085104, 1.0,
    0.7812499999999999, 0.0, 0.7777777777777778, 0.39999999999999997, 1.0,
    0.12987012987013002, 0.0, 1.0, 0.3333333333333333, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 0.30999999999999955, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.3458333333333336, 0.501207729468599, 0.0,
    0.07616707616707602, 0.9121140142517816, 0.03655352480417751,
    0.7083333333333334, 0.40000000000000013, 0.9734042553191489, 0.0,
    0.2187500000000002, 1.0, 0.2222222222222222, 0.6, 0.0, 0.87012987012987, 1.0,
    0.0, 0.6666666666666666, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0 };

  real_T unusedExpr[3];
  cachedScore[0] = 0.0;
  cachedScore[1] = 0.0;
  cachedScore[2] = 0.0;
  cachedWeights = 0.0;
  b = false;
  for (i = 0; i < 9; i++) {
    assign_temp_Cost[i] = i_0[i];
  }

  for (i = 0; i < 35; i++) {
    d[i] = d_0[i];
  }

  for (i = 0; i < 70; i++) {
    e[i] = e_0[i];
  }

  MotorFaul_predictOneWithCache_j(X, cachedScore, &cachedWeights, combiner, d, e,
    c, f, assign_temp_Cost, g, &b, true, unusedExpr);
  b = obj_IsCached[1];
  for (i = 0; i < 35; i++) {
    d[i] = k[i];
  }

  for (i = 0; i < 70; i++) {
    e[i] = l[i];
  }

  MotorFaul_predictOneWithCache_j(X, cachedScore, &cachedWeights, combiner, d, e,
    j, m, assign_temp_Cost, n, &b, false, unusedExpr);
  b = obj_IsCached[2];
  for (i = 0; i < 33; i++) {
    q[i] = q_0[i];
  }

  for (i = 0; i < 66; i++) {
    r[i] = r_0[i];
  }

  MotorFau_predictOneWithCache_jp(X, cachedScore, &cachedWeights, combiner, q, r,
    p, s, assign_temp_Cost, t, &b, unusedExpr);
  b = obj_IsCached[3];
  for (i = 0; i < 25; i++) {
    w[i] = w_0[i];
  }

  for (i = 0; i < 50; i++) {
    x[i] = x_0[i];
  }

  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    v, y, assign_temp_Cost, ab, &b, unusedExpr);
  b = obj_IsCached[4];
  for (i = 0; i < 35; i++) {
    d[i] = db[i];
  }

  for (i = 0; i < 70; i++) {
    e[i] = eb[i];
  }

  MotorFaul_predictOneWithCache_j(X, cachedScore, &cachedWeights, combiner, d, e,
    cb, fb, assign_temp_Cost, gb, &b, false, unusedExpr);
  b = obj_IsCached[5];
  for (i = 0; i < 45; i++) {
    jb[i] = jb_0[i];
  }

  for (i = 0; i < 90; i++) {
    kb[i] = kb_0[i];
  }

  MotorF_predictOneWithCache_jpyz(X, cachedScore, &cachedWeights, combiner, jb,
    kb, ib, lb, assign_temp_Cost, mb, &b, unusedExpr);
  b = obj_IsCached[6];
  for (i = 0; i < 27; i++) {
    pb[i] = pb_0[i];
  }

  for (i = 0; i < 54; i++) {
    qb[i] = qb_0[i];
  }

  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, ob, rb, assign_temp_Cost, sb, &b, unusedExpr);
  b = obj_IsCached[7];
  for (i = 0; i < 25; i++) {
    w[i] = vb[i];
  }

  for (i = 0; i < 50; i++) {
    x[i] = wb[i];
  }

  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    ub, xb, assign_temp_Cost, yb, &b, unusedExpr);
  b = obj_IsCached[8];
  for (i = 0; i < 29; i++) {
    cc[i] = cc_0[i];
  }

  for (i = 0; i < 58; i++) {
    dc[i] = dc_0[i];
  }

  Moto_predictOneWithCache_jpyzwe(X, cachedScore, &cachedWeights, combiner, cc,
    dc, bc, ec, assign_temp_Cost, fc, &b, unusedExpr);
  b = obj_IsCached[9];
  for (i = 0; i < 21; i++) {
    ic[i] = ic_0[i];
  }

  for (i = 0; i < 42; i++) {
    jc[i] = jc_0[i];
  }

  Mot_predictOneWithCache_jpyzwef(X, cachedScore, &cachedWeights, combiner, ic,
    jc, hc, kc, assign_temp_Cost, lc, &b, unusedExpr);
  b = obj_IsCached[10];
  for (i = 0; i < 31; i++) {
    oc[i] = oc_0[i];
  }

  for (i = 0; i < 62; i++) {
    pc[i] = pc_0[i];
  }

  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, nc, qc, assign_temp_Cost, rc, &b, unusedExpr);
  b = obj_IsCached[11];
  for (i = 0; i < 33; i++) {
    q[i] = uc[i];
  }

  for (i = 0; i < 66; i++) {
    r[i] = vc[i];
  }

  MotorFau_predictOneWithCache_jp(X, cachedScore, &cachedWeights, combiner, q, r,
    tc, wc, assign_temp_Cost, xc, &b, unusedExpr);
  b = obj_IsCached[12];
  for (i = 0; i < 23; i++) {
    bd[i] = bd_0[i];
  }

  for (i = 0; i < 46; i++) {
    cd[i] = cd_0[i];
  }

  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, ad, dd, assign_temp_Cost, ed, &b, unusedExpr);
  b = obj_IsCached[13];
  for (i = 0; i < 23; i++) {
    bd[i] = hd[i];
  }

  for (i = 0; i < 46; i++) {
    cd[i] = id[i];
  }

  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, gd, jd, assign_temp_Cost, kd, &b, unusedExpr);
  b = obj_IsCached[14];
  for (i = 0; i < 35; i++) {
    d[i] = nd[i];
  }

  for (i = 0; i < 70; i++) {
    e[i] = od[i];
  }

  MotorFaul_predictOneWithCache_j(X, cachedScore, &cachedWeights, combiner, d, e,
    md, pd, assign_temp_Cost, qd, &b, false, unusedExpr);
  b = obj_IsCached[15];
  for (i = 0; i < 27; i++) {
    pb[i] = td[i];
  }

  for (i = 0; i < 54; i++) {
    qb[i] = ud[i];
  }

  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, sd, vd, assign_temp_Cost, wd, &b, unusedExpr);
  b = obj_IsCached[16];
  CompactClassificationTree_Co_gn(q, r, assign_temp_CutPoint,
    assign_temp_NanCutPoints, expl_temp, expl_temp_0, &expl_temp_1, unusedExpr,
    expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability);
  MotorFau_predictOneWithCache_jp(X, cachedScore, &cachedWeights, combiner, q, r,
    assign_temp_CutPoint, assign_temp_NanCutPoints, assign_temp_Cost,
    assign_temp_ClassProbability, &b, unusedExpr);
  b = obj_IsCached[17];
  CompactClassificationTree_C_gne(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[18];
  CompactClassificationTree__gnex(assign_temp_CutPredictorIndex,
    assign_temp_Children, assign_temp_CutPoint_1, assign_temp_NanCutPoints_1,
    expl_temp_4, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_1);
  predictOneWithCache_jpyzwefnbj(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex, assign_temp_Children, assign_temp_CutPoint_1,
    assign_temp_NanCutPoints_1, assign_temp_Cost, assign_temp_ClassProbability_1,
    &b, unusedExpr);
  b = obj_IsCached[19];
  CompactClassificationTree_gnexe(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[20];
  CompactClassificationTre_gnexe4(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[21];
  CompactClassificationTr_gnexe4e(assign_temp_CutPredictorIndex_0,
    assign_temp_Children_0, assign_temp_CutPoint_3, assign_temp_NanCutPoints_3,
    expl_temp_6, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_3);
  predictOneWithCache_jpyzwefnbjt(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_0, assign_temp_Children_0,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, unusedExpr);
  b = obj_IsCached[22];
  CompactClassificationT_gnexe4eq(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[23];
  CompactClassification_gnexe4eq5(assign_temp_ClassProbability_1,
    assign_temp_Children_1, assign_temp_CutPoint_4, assign_temp_NanCutPoints_4,
    expl_temp_7, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_4);
  predictOneWithCach_jpyzwefnbjt0(X, cachedScore, &cachedWeights, combiner,
    assign_temp_ClassProbability_1, assign_temp_Children_1,
    assign_temp_CutPoint_4, assign_temp_NanCutPoints_4, assign_temp_Cost,
    assign_temp_ClassProbability_4, &b, unusedExpr);
  b = obj_IsCached[24];
  CompactClassificatio_gnexe4eq5x(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[25];
  CompactClassificati_gnexe4eq5xh(bd, cd, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[26];
  CompactClassificat_gnexe4eq5xht(jb, kb, assign_temp_CutPoint_6,
    assign_temp_NanCutPoints_6, expl_temp_9, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_6);
  MotorF_predictOneWithCache_jpyz(X, cachedScore, &cachedWeights, combiner, jb,
    kb, assign_temp_CutPoint_6, assign_temp_NanCutPoints_6, assign_temp_Cost,
    assign_temp_ClassProbability_6, &b, unusedExpr);
  b = obj_IsCached[27];
  CompactClassifica_gnexe4eq5xhts(assign_temp_CutPredictorIndex_0,
    assign_temp_Children_0, assign_temp_CutPoint_3, assign_temp_NanCutPoints_3,
    expl_temp_6, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_3);
  predictOneWithCache_jpyzwefnbjt(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_0, assign_temp_Children_0,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, unusedExpr);
  b = obj_IsCached[28];
  CompactClassific_gnexe4eq5xhtsj(cc, dc, assign_temp_CutPoint_7,
    assign_temp_NanCutPoints_7, expl_temp_a, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_7);
  Moto_predictOneWithCache_jpyzwe(X, cachedScore, &cachedWeights, combiner, cc,
    dc, assign_temp_CutPoint_7, assign_temp_NanCutPoints_7, assign_temp_Cost,
    assign_temp_ClassProbability_7, &b, unusedExpr);
  b = obj_IsCached[29];
  CompactClassifi_gnexe4eq5xhtsjp(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[30];
  CompactClassificationTree_Com_l(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[31];
  CompactClassificationTree_Co_jt(bd, cd, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[32];
  CompactClassificationTree_Com_p(pb, qb, assign_temp_CutPoint_8,
    assign_temp_NanCutPoints_8, expl_temp_b, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_8);
  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[33];
  CompactClassificationTree_Com_d(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[34];
  CompactClassificationTree_Co_g0(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[35];
  CompactClassificationTree_Co_bl(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[36];
  CompactClassificationTree_Co_cj(q, r, assign_temp_CutPoint,
    assign_temp_NanCutPoints, expl_temp, expl_temp_0, &expl_temp_1, unusedExpr,
    expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability);
  MotorFau_predictOneWithCache_jp(X, cachedScore, &cachedWeights, combiner, q, r,
    assign_temp_CutPoint, assign_temp_NanCutPoints, assign_temp_Cost,
    assign_temp_ClassProbability, &b, unusedExpr);
  b = obj_IsCached[37];
  CompactClassificationTree_Co_lj(bd, cd, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[38];
  CompactClassificationTree_Co_lk(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[39];
  CompactClassificationTree_Co_n0(w, x, assign_temp_CutPoint_0,
    assign_temp_NanCutPoints_0, expl_temp_3, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_0);
  MotorFa_predictOneWithCache_jpy(X, cachedScore, &cachedWeights, combiner, w, x,
    assign_temp_CutPoint_0, assign_temp_NanCutPoints_0, assign_temp_Cost,
    assign_temp_ClassProbability_0, &b, unusedExpr);
  b = obj_IsCached[40];
  CompactClassificationTree_Co_ha(bd, cd, assign_temp_CutPoint_5,
    assign_temp_NanCutPoints_5, expl_temp_8, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_5);
  M_predictOneWithCache_jpyzwefnb(X, cachedScore, &cachedWeights, combiner, bd,
    cd, assign_temp_CutPoint_5, assign_temp_NanCutPoints_5, assign_temp_Cost,
    assign_temp_ClassProbability_5, &b, unusedExpr);
  b = obj_IsCached[41];
  CompactClassificationTree_Co_cw(ic, jc, assign_temp_CutPoint_9,
    assign_temp_NanCutPoints_9, expl_temp_c, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_9);
  Mot_predictOneWithCache_jpyzwef(X, cachedScore, &cachedWeights, combiner, ic,
    jc, assign_temp_CutPoint_9, assign_temp_NanCutPoints_9, assign_temp_Cost,
    assign_temp_ClassProbability_9, &b, unusedExpr);
  b = obj_IsCached[42];
  CompactClassificationTree_Co_pp(pb, qb, assign_temp_CutPoint_8,
    assign_temp_NanCutPoints_8, expl_temp_b, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_8);
  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[43];
  CompactClassificationTree_Co_de(ic, jc, assign_temp_CutPoint_9,
    assign_temp_NanCutPoints_9, expl_temp_c, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_9);
  Mot_predictOneWithCache_jpyzwef(X, cachedScore, &cachedWeights, combiner, ic,
    jc, assign_temp_CutPoint_9, assign_temp_NanCutPoints_9, assign_temp_Cost,
    assign_temp_ClassProbability_9, &b, unusedExpr);
  b = obj_IsCached[44];
  CompactClassificationTree_Co_gj(ic, jc, assign_temp_CutPoint_9,
    assign_temp_NanCutPoints_9, expl_temp_c, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_9);
  Mot_predictOneWithCache_jpyzwef(X, cachedScore, &cachedWeights, combiner, ic,
    jc, assign_temp_CutPoint_9, assign_temp_NanCutPoints_9, assign_temp_Cost,
    assign_temp_ClassProbability_9, &b, unusedExpr);
  b = obj_IsCached[45];
  CompactClassificationTree_Co_gv(pb, qb, assign_temp_CutPoint_8,
    assign_temp_NanCutPoints_8, expl_temp_b, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_8);
  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[46];
  CompactClassificationTree_Co_pa(d, e, assign_temp_CutPoint_a,
    assign_temp_NanCutPoints_a, expl_temp_d, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_a);
  MotorFaul_predictOneWithCache_j(X, cachedScore, &cachedWeights, combiner, d, e,
    assign_temp_CutPoint_a, assign_temp_NanCutPoints_a, assign_temp_Cost,
    assign_temp_ClassProbability_a, &b, false, unusedExpr);
  b = obj_IsCached[47];
  CompactClassificationTree_Com_f(pb, qb, assign_temp_CutPoint_8,
    assign_temp_NanCutPoints_8, expl_temp_b, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_8);
  Motor_predictOneWithCache_jpyzw(X, cachedScore, &cachedWeights, combiner, pb,
    qb, assign_temp_CutPoint_8, assign_temp_NanCutPoints_8, assign_temp_Cost,
    assign_temp_ClassProbability_8, &b, unusedExpr);
  b = obj_IsCached[48];
  CompactClassificationTree_Co_o4(oc, pc, assign_temp_CutPoint_2,
    assign_temp_NanCutPoints_2, expl_temp_5, expl_temp_0, &expl_temp_1,
    unusedExpr, expl_temp_2, assign_temp_Cost, assign_temp_ClassProbability_2);
  Mo_predictOneWithCache_jpyzwefn(X, cachedScore, &cachedWeights, combiner, oc,
    pc, assign_temp_CutPoint_2, assign_temp_NanCutPoints_2, assign_temp_Cost,
    assign_temp_ClassProbability_2, &b, unusedExpr);
  b = obj_IsCached[49];
  CompactClassificationTree_Co_ba(assign_temp_CutPredictorIndex_0,
    assign_temp_Children_0, assign_temp_CutPoint_3, assign_temp_NanCutPoints_3,
    expl_temp_6, expl_temp_0, &expl_temp_1, unusedExpr, expl_temp_2,
    assign_temp_Cost, assign_temp_ClassProbability_3);
  predictOneWithCache_jpyzwefnbjt(X, cachedScore, &cachedWeights, combiner,
    assign_temp_CutPredictorIndex_0, assign_temp_Children_0,
    assign_temp_CutPoint_3, assign_temp_NanCutPoints_3, assign_temp_Cost,
    assign_temp_ClassProbability_3, &b, score);
}

/* Model step function */
void MotorFaultDeploy_step(void)
{
  real_T accumulatedData_0[10];
  real_T scores[4];
  real_T scores_0[3];
  real_T accumulatedData;
  real_T b_accumulatedData;
  real_T b_bsum;
  real_T b_y;
  real_T bsum;
  real_T c_accumulatedData;
  real_T c_y;
  real_T classnum;
  real_T t;
  real_T x0;
  real_T xbar;
  int32_T f_k;
  int32_T i;
  int32_T ii;
  uint32_T tmp;
  boolean_T c_x[4];
  boolean_T c_x_0[3];
  boolean_T c_x_tmp;
  boolean_T notNaN;
  static const int8_T d[16] = { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 };

  static const int8_T b[9] = { 0, 1, 1, 1, 0, 1, 1, 1, 0 };

  int32_T exitg1;
  boolean_T exitg2;

  /* MATLAB Function: '<Root>/BearingDetector' incorporates:
   *  Inport: '<Root>/accel'
   */
  if (!MotorFaultDeploy_DW.buf_not_empty) {
    MotorFaultDeploy_DW.buf_not_empty = true;
    MotorFaultDeploy_DW.mdl.ClassNamesLength[0] = 1;
    MotorFaultDeploy_DW.mdl.ClassLogicalIndices[0] = true;
    MotorFaultDeploy_DW.mdl.ClassNamesLength[1] = 1;
    MotorFaultDeploy_DW.mdl.ClassLogicalIndices[1] = true;
    MotorFaultDeploy_DW.mdl.ClassNamesLength[2] = 1;
    MotorFaultDeploy_DW.mdl.ClassLogicalIndices[2] = true;
    MotorFaultDeploy_DW.mdl.ClassNamesLength[3] = 1;
    MotorFaultDeploy_DW.mdl.ClassLogicalIndices[3] = true;
    MotorFaultDeploy_DW.mdl.ScoreTransform = Identity;
    for (i = 0; i < 50; i++) {
      MotorFaultDeploy_DW.mdl.LearnerWeights[i] = 1.0;
      MotorFaultDeploy_DW.mdl.IsCached[i] = false;
    }

    MotorFaultDeploy_DW.mdl.Prior[0] = 0.3688195991091314;
    MotorFaultDeploy_DW.mdl.Prior[1] = 0.21069042316258352;
    MotorFaultDeploy_DW.mdl.Prior[2] = 0.21024498886414253;
    MotorFaultDeploy_DW.mdl.Prior[3] = 0.21024498886414253;
    for (i = 0; i < 16; i++) {
      MotorFaultDeploy_DW.mdl.Cost[i] = d[i];
    }
  }

  MotorFaultDeploy_DW.idx_k++;
  MotorFaultDeploy_DW.buf[(int32_T)MotorFaultDeploy_DW.idx_k - 1] =
    MotorFaultDeploy_U.accel;
  if (MotorFaultDeploy_DW.idx_k == 2048.0) {
    MotorFaultDeploy_DW.idx_k = 0.0;
    for (i = 0; i < 2048; i++) {
      classnum = fabs(MotorFaultDeploy_DW.buf[i]);
      MotorFaultDeploy_B.x_c[i] = classnum;
      MotorFaultDeploy_B.b_x_b[i] = classnum;
    }

    FFTImplementationCallback_doHal(MotorFaultDeploy_DW.buf,
      MotorFaultDeploy_B.X);
    for (ii = 0; ii < 1025; ii++) {
      xbar = rt_hypotd_snf(MotorFaultDeploy_B.X[ii].re, MotorFaultDeploy_B.X[ii]
                           .im);
      MotorFaultDeploy_B.P[ii] = xbar * xbar / 2.4576E+7;
    }

    for (i = 0; i < 1023; i++) {
      MotorFaultDeploy_B.P[i + 1] *= 2.0;
    }

    classnum = MotorFaultDeploy_B.P[1];
    for (i = 0; i < 169; i++) {
      classnum += MotorFaultDeploy_B.P[i + 2];
    }

    FFTImplementationCallback_doHal(MotorFaultDeploy_DW.buf,
      MotorFaultDeploy_B.X);
    for (f_k = 0; f_k < 1025; f_k++) {
      xbar = rt_hypotd_snf(MotorFaultDeploy_B.X[f_k].re,
                           MotorFaultDeploy_B.X[f_k].im);
      MotorFaultDeploy_B.P[f_k] = xbar * xbar / 2.4576E+7;
    }

    for (i = 0; i < 1023; i++) {
      MotorFaultDeploy_B.P[i + 1] *= 2.0;
    }

    b_y = MotorFaultDeploy_B.P[171];
    for (i = 0; i < 341; i++) {
      b_y += MotorFaultDeploy_B.P[i + 172];
    }

    FFTImplementationCallback_doHal(MotorFaultDeploy_DW.buf,
      MotorFaultDeploy_B.X);
    for (i = 0; i < 1025; i++) {
      xbar = rt_hypotd_snf(MotorFaultDeploy_B.X[i].re, MotorFaultDeploy_B.X[i].
                           im);
      MotorFaultDeploy_B.P[i] = xbar * xbar / 2.4576E+7;
    }

    for (i = 0; i < 1023; i++) {
      MotorFaultDeploy_B.P[i + 1] *= 2.0;
    }

    c_y = MotorFaultDeploy_B.P[512];
    for (i = 0; i < 426; i++) {
      c_y += MotorFaultDeploy_B.P[i + 513];
    }

    accumulatedData = MotorFaultDeploy_DW.buf[0];
    bsum = MotorFaultDeploy_DW.buf[1024];
    xbar = MotorFaultDeploy_DW.buf[0];
    b_bsum = MotorFaultDeploy_DW.buf[1024];
    for (i = 0; i < 1023; i++) {
      accumulatedData += MotorFaultDeploy_DW.buf[i + 1];
      bsum += MotorFaultDeploy_DW.buf[i + 1025];
      xbar = accumulatedData;
      b_bsum = bsum;
    }

    bsum = (xbar + b_bsum) / 2048.0;
    b_bsum = 0.0;
    xbar = 3.312168642111238E-170;
    for (i = 0; i < 2048; i++) {
      MotorFaultDeploy_B.b_x0[i] = fabs(MotorFaultDeploy_DW.buf[i] - bsum);
      c_accumulatedData = MotorFaultDeploy_B.b_x0[i];
      if (c_accumulatedData > xbar) {
        t = xbar / c_accumulatedData;
        b_bsum = b_bsum * t * t + 1.0;
        xbar = c_accumulatedData;
      } else {
        t = c_accumulatedData / xbar;
        b_bsum += t * t;
      }
    }

    b_bsum = xbar * sqrt(b_bsum);
    if (rtIsNaN(b_bsum)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i < 2048) {
          if (rtIsNaN(MotorFaultDeploy_B.b_x0[i])) {
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          b_bsum = (rtInf);
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    for (i = 0; i < 2048; i++) {
      xbar = MotorFaultDeploy_DW.buf[i];
      MotorFaultDeploy_B.b_x0_tmp[i] = xbar * xbar;
    }

    b_accumulatedData = MotorFaultDeploy_B.b_x0_tmp[0];
    t = MotorFaultDeploy_B.b_x0_tmp[1024];
    for (i = 0; i < 1023; i++) {
      b_accumulatedData += MotorFaultDeploy_B.b_x0_tmp[i + 1];
      t += MotorFaultDeploy_B.b_x0_tmp[i + 1025];
    }

    xbar = 0.0;
    i = 0;
    for (ii = 0; ii < 2048; ii++) {
      if (!rtIsNaN(MotorFaultDeploy_DW.buf[ii])) {
        xbar += MotorFaultDeploy_DW.buf[ii];
        i++;
      }
    }

    if (i == 0) {
      xbar = (rtNaN);
    } else {
      xbar /= (real_T)i;
    }

    accumulatedData = 0.0;
    i = 0;
    for (ii = 0; ii < 2048; ii++) {
      x0 = MotorFaultDeploy_DW.buf[ii] - xbar;
      MotorFaultDeploy_B.x0_p[ii] = x0 * x0;
      if (!rtIsNaN(MotorFaultDeploy_DW.buf[ii])) {
        accumulatedData += MotorFaultDeploy_DW.buf[ii];
        i++;
      }
    }

    xbar = MotorFaultDeploy_mean(MotorFaultDeploy_B.x0_p);
    if (i == 0) {
      accumulatedData = (rtNaN);
    } else {
      accumulatedData /= (real_T)i;
    }

    for (i = 0; i < 2048; i++) {
      c_accumulatedData = MotorFaultDeploy_DW.buf[i] - accumulatedData;
      MotorFaultDeploy_B.b_x0[i] = c_accumulatedData;
      MotorFaultDeploy_B.xp_cv[i] = c_accumulatedData * c_accumulatedData;
    }

    c_accumulatedData = MotorFaultDeploy_B.b_x0_tmp[0];
    accumulatedData = MotorFaultDeploy_B.b_x0_tmp[1024];
    for (i = 0; i < 1023; i++) {
      c_accumulatedData += MotorFaultDeploy_B.b_x0_tmp[i + 1];
      accumulatedData += MotorFaultDeploy_B.b_x0_tmp[i + 1025];
    }

    for (i = 0; i < 2048; i++) {
      x0 = MotorFaultDeploy_B.x0_p[i];
      MotorFaultDeploy_B.b_x0_tmp[i] = x0 * x0;
      MotorFaultDeploy_B.xp_f[i] = MotorFaultDeploy_B.xp_cv[i] *
        MotorFaultDeploy_B.b_x0[i];
    }

    accumulatedData_0[0] = bsum;
    accumulatedData_0[1] = b_bsum / 45.24378410345447;
    accumulatedData_0[2] = sqrt((b_accumulatedData + t) / 2048.0);
    accumulatedData_0[3] = MotorFaultDeploy_maximum(MotorFaultDeploy_B.x_c);
    accumulatedData_0[4] = MotorFaultDeploy_mean(MotorFaultDeploy_B.b_x0_tmp) /
      (xbar * xbar);
    accumulatedData_0[5] = MotorFaultDeploy_mean(MotorFaultDeploy_B.xp_f) /
      rt_powd_snf(MotorFaultDeploy_mean(MotorFaultDeploy_B.xp_cv), 1.5);
    accumulatedData_0[6] = MotorFaultDeploy_maximum(MotorFaultDeploy_B.b_x_b) /
      sqrt((c_accumulatedData + accumulatedData) / 2048.0);
    accumulatedData_0[7] = classnum * 12000.0 / 2048.0;
    accumulatedData_0[8] = b_y * 12000.0 / 2048.0;
    accumulatedData_0[9] = c_y * 12000.0 / 2048.0;
    CompactEnsemble_ensemblePredict(MotorFaultDeploy_DW.mdl.IsCached,
      accumulatedData_0, scores);
    c_x_tmp = rtIsNaN(scores[0]);
    c_x[0] = c_x_tmp;
    c_x[1] = rtIsNaN(scores[1]);
    c_x[2] = rtIsNaN(scores[2]);
    c_x[3] = rtIsNaN(scores[3]);
    notNaN = true;
    i = 0;
    exitg2 = false;
    while (!exitg2 && (i < 4)) {
      if (!c_x[i]) {
        notNaN = false;
        exitg2 = true;
      } else {
        i++;
      }
    }

    if (!rtIsNaN(MotorFaultDeploy_DW.mdl.Prior[0])) {
      ii = 1;
    } else {
      ii = 0;
      i = 2;
      exitg2 = false;
      while (!exitg2 && (i < 5)) {
        if (!rtIsNaN(MotorFaultDeploy_DW.mdl.Prior[i - 1])) {
          ii = i;
          exitg2 = true;
        } else {
          i++;
        }
      }
    }

    if (ii == 0) {
      i = 1;
    } else {
      classnum = MotorFaultDeploy_DW.mdl.Prior[ii - 1];
      i = ii;
      for (f_k = ii + 1; f_k < 5; f_k++) {
        b_y = MotorFaultDeploy_DW.mdl.Prior[f_k - 1];
        if (classnum < b_y) {
          classnum = b_y;
          i = f_k;
        }
      }
    }

    MotorFaultDeploy_DW.lastLabel_a = ((real_T)i - 1.0) + 1.0;
    if (!notNaN) {
      if (!c_x_tmp) {
        ii = 1;
      } else {
        ii = 0;
        f_k = 2;
        exitg2 = false;
        while (!exitg2 && (f_k < 5)) {
          if (!rtIsNaN(scores[f_k - 1])) {
            ii = f_k;
            exitg2 = true;
          } else {
            f_k++;
          }
        }
      }

      if (ii == 0) {
        f_k = 1;
      } else {
        classnum = scores[ii - 1];
        f_k = ii;
        for (i = ii + 1; i < 5; i++) {
          b_y = scores[i - 1];
          if (classnum < b_y) {
            classnum = b_y;
            f_k = i;
          }
        }
      }

      if (f_k < 4.294967296E+9) {
        tmp = (uint32_T)f_k;
      } else {
        tmp = MAX_uint32_T;
      }

      MotorFaultDeploy_DW.lastLabel_a = (int8_T)((int8_T)((int32_T)tmp - 1) + 1);
    }

    if (MotorFaultDeploy_DW.lastLabel_a != 1.0) {
      MotorFaultDeploy_DW.cnt_p++;
    } else {
      MotorFaultDeploy_DW.cnt_p = 0.0;
    }
  }

  /* Outport: '<Root>/bearingClass' incorporates:
   *  MATLAB Function: '<Root>/BearingDetector'
   */
  MotorFaultDeploy_Y.bearingClass = MotorFaultDeploy_DW.lastLabel_a;

  /* MATLAB Function: '<Root>/ElectricalDetector' incorporates:
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/speed'
   *  Inport: '<Root>/voltage'
   */
  if (!MotorFaultDeploy_DW.bc_not_empty) {
    MotorFaultDeploy_DW.bc_not_empty = true;
    MotorFaultDeploy_DW.mdl_h.ClassNamesLength[0] = 1;
    MotorFaultDeploy_DW.mdl_h.ClassLogicalIndices[0] = true;
    MotorFaultDeploy_DW.mdl_h.ClassNamesLength[1] = 1;
    MotorFaultDeploy_DW.mdl_h.ClassLogicalIndices[1] = true;
    MotorFaultDeploy_DW.mdl_h.ClassNamesLength[2] = 1;
    MotorFaultDeploy_DW.mdl_h.ClassLogicalIndices[2] = true;
    MotorFaultDeploy_DW.mdl_h.ScoreTransform = Identity;
    for (i = 0; i < 50; i++) {
      MotorFaultDeploy_DW.mdl_h.LearnerWeights[i] = 1.0;
      MotorFaultDeploy_DW.mdl_h.IsCached[i] = false;
    }

    MotorFaultDeploy_DW.mdl_h.Prior[0] = 0.3333333333333333;
    MotorFaultDeploy_DW.mdl_h.Prior[1] = 0.3333333333333333;
    MotorFaultDeploy_DW.mdl_h.Prior[2] = 0.3333333333333333;
    for (i = 0; i < 9; i++) {
      MotorFaultDeploy_DW.mdl_h.Cost[i] = b[i];
    }
  }

  MotorFaultDeploy_DW.idx++;
  MotorFaultDeploy_DW.bc[(int32_T)MotorFaultDeploy_DW.idx - 1] =
    MotorFaultDeploy_U.current;
  MotorFaultDeploy_DW.bs[(int32_T)MotorFaultDeploy_DW.idx - 1] =
    MotorFaultDeploy_U.speed;
  if (MotorFaultDeploy_DW.idx == 2400.0) {
    MotorFaultDeploy_DW.idx = 0.0;
    for (i = 0; i < 2400; i++) {
      classnum = fabs(MotorFaultDeploy_DW.bc[i]);
      MotorFaultDeploy_B.x[i] = classnum;
      MotorFaultDeploy_B.b_x[i] = classnum;
    }

    xbar = 0.0;
    i = 0;
    for (ii = 0; ii < 2400; ii++) {
      if (!rtIsNaN(MotorFaultDeploy_DW.bc[ii])) {
        xbar += MotorFaultDeploy_DW.bc[ii];
        i++;
      }
    }

    if (i == 0) {
      xbar = (rtNaN);
    } else {
      xbar /= (real_T)i;
    }

    accumulatedData = 0.0;
    i = 0;
    for (ii = 0; ii < 2400; ii++) {
      x0 = MotorFaultDeploy_DW.bc[ii] - xbar;
      MotorFaultDeploy_B.x0[ii] = x0 * x0;
      if (!rtIsNaN(MotorFaultDeploy_DW.bc[ii])) {
        accumulatedData += MotorFaultDeploy_DW.bc[ii];
        i++;
      }
    }

    xbar = MotorFaultDeploy_mean_o(MotorFaultDeploy_B.x0);
    if (i == 0) {
      accumulatedData = (rtNaN);
    } else {
      accumulatedData /= (real_T)i;
    }

    for (i = 0; i < 2400; i++) {
      b_y = MotorFaultDeploy_DW.bc[i];
      c_accumulatedData = b_y - accumulatedData;
      classnum = c_accumulatedData * c_accumulatedData;
      MotorFaultDeploy_B.xp[i] = classnum;
      MotorFaultDeploy_B.dv[i] = b_y * b_y;
      x0 = MotorFaultDeploy_B.x0[i];
      MotorFaultDeploy_B.x0_m[i] = x0 * x0;
      MotorFaultDeploy_B.xp_c[i] = classnum * c_accumulatedData;
    }

    classnum = sqrt(MotorFaul_combineVectorElements(MotorFaultDeploy_B.dv) /
                    2400.0);
    accumulatedData_0[0] = MotorFaul_combineVectorElements
      (MotorFaultDeploy_DW.bc) / 2400.0;
    accumulatedData_0[1] = MotorFaultDeploy_std(MotorFaultDeploy_DW.bc);
    accumulatedData_0[2] = classnum;
    accumulatedData_0[3] = MotorFaultDeploy_maximum_p(MotorFaultDeploy_B.x);
    accumulatedData_0[4] = MotorFaultDeploy_mean_o(MotorFaultDeploy_B.x0_m) /
      (xbar * xbar);
    accumulatedData_0[5] = MotorFaultDeploy_mean_o(MotorFaultDeploy_B.xp_c) /
      rt_powd_snf(MotorFaultDeploy_mean_o(MotorFaultDeploy_B.xp), 1.5);
    accumulatedData_0[6] = MotorFaultDeploy_maximum_p(MotorFaultDeploy_B.b_x) /
      classnum;
    classnum = MotorFaul_combineVectorElements(MotorFaultDeploy_DW.bs) / 2400.0;
    accumulatedData_0[7] = classnum;
    accumulatedData_0[8] = MotorFaultDeploy_std(MotorFaultDeploy_DW.bs);
    accumulatedData_0[9] = classnum / MotorFaultDeploy_U.voltage;
    CompactEnsemble_ensemblePredi_j(MotorFaultDeploy_DW.mdl_h.IsCached,
      accumulatedData_0, scores_0);
    c_x_tmp = rtIsNaN(scores_0[0]);
    c_x_0[0] = c_x_tmp;
    c_x_0[1] = rtIsNaN(scores_0[1]);
    c_x_0[2] = rtIsNaN(scores_0[2]);
    notNaN = true;
    i = 0;
    exitg2 = false;
    while (!exitg2 && (i < 3)) {
      if (!c_x_0[i]) {
        notNaN = false;
        exitg2 = true;
      } else {
        i++;
      }
    }

    if (!rtIsNaN(MotorFaultDeploy_DW.mdl_h.Prior[0])) {
      ii = 1;
    } else {
      ii = 0;
      i = 2;
      exitg2 = false;
      while (!exitg2 && (i < 4)) {
        if (!rtIsNaN(MotorFaultDeploy_DW.mdl_h.Prior[i - 1])) {
          ii = i;
          exitg2 = true;
        } else {
          i++;
        }
      }
    }

    if (ii == 0) {
      i = 1;
    } else {
      classnum = MotorFaultDeploy_DW.mdl_h.Prior[ii - 1];
      i = ii;
      for (f_k = ii + 1; f_k < 4; f_k++) {
        b_y = MotorFaultDeploy_DW.mdl_h.Prior[f_k - 1];
        if (classnum < b_y) {
          classnum = b_y;
          i = f_k;
        }
      }
    }

    MotorFaultDeploy_DW.lastLabel = ((real_T)i - 1.0) + 1.0;
    if (!notNaN) {
      if (!c_x_tmp) {
        ii = 1;
      } else {
        ii = 0;
        f_k = 2;
        exitg2 = false;
        while (!exitg2 && (f_k < 4)) {
          if (!rtIsNaN(scores_0[f_k - 1])) {
            ii = f_k;
            exitg2 = true;
          } else {
            f_k++;
          }
        }
      }

      if (ii == 0) {
        f_k = 1;
      } else {
        classnum = scores_0[ii - 1];
        f_k = ii;
        for (i = ii + 1; i < 4; i++) {
          b_y = scores_0[i - 1];
          if (classnum < b_y) {
            classnum = b_y;
            f_k = i;
          }
        }
      }

      if (f_k < 4.294967296E+9) {
        tmp = (uint32_T)f_k;
      } else {
        tmp = MAX_uint32_T;
      }

      MotorFaultDeploy_DW.lastLabel = (int8_T)((int8_T)((int32_T)tmp - 1) + 1);
    }

    if (MotorFaultDeploy_DW.lastLabel != 1.0) {
      MotorFaultDeploy_DW.cnt++;
    } else {
      MotorFaultDeploy_DW.cnt = 0.0;
    }
  }

  /* Outport: '<Root>/electricalClass' incorporates:
   *  MATLAB Function: '<Root>/ElectricalDetector'
   */
  MotorFaultDeploy_Y.electricalClass = MotorFaultDeploy_DW.lastLabel;

  /* Outport: '<Root>/alarm' incorporates:
   *  Logic: '<Root>/SystemAlarm'
   *  MATLAB Function: '<Root>/BearingDetector'
   *  MATLAB Function: '<Root>/ElectricalDetector'
   */
  MotorFaultDeploy_Y.alarm = ((MotorFaultDeploy_DW.cnt_p >= 3.0) ||
    (MotorFaultDeploy_DW.cnt >= 3.0));

  /* Matfile logging */
  rt_UpdateTXYLogVars(MotorFaultDeploy_M->rtwLogInfo,
                      (&MotorFaultDeploy_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [8.33333e-05s, 0.0s] */
    if ((rtmGetTFinal(MotorFaultDeploy_M)!=-1) &&
        !((rtmGetTFinal(MotorFaultDeploy_M)-MotorFaultDeploy_M->Timing.taskTime0)
          > MotorFaultDeploy_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MotorFaultDeploy_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MotorFaultDeploy_M->Timing.clockTick0)) {
    ++MotorFaultDeploy_M->Timing.clockTickH0;
  }

  MotorFaultDeploy_M->Timing.taskTime0 = MotorFaultDeploy_M->Timing.clockTick0 *
    MotorFaultDeploy_M->Timing.stepSize0 +
    MotorFaultDeploy_M->Timing.clockTickH0 *
    MotorFaultDeploy_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void MotorFaultDeploy_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MotorFaultDeploy_M, 0,
                sizeof(RT_MODEL_MotorFaultDeploy_T));
  rtmSetTFinal(MotorFaultDeploy_M, 10.0);
  MotorFaultDeploy_M->Timing.stepSize0 = 8.3333333333333331E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    MotorFaultDeploy_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MotorFaultDeploy_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MotorFaultDeploy_M->rtwLogInfo, (NULL));
    rtliSetLogT(MotorFaultDeploy_M->rtwLogInfo, "tout");
    rtliSetLogX(MotorFaultDeploy_M->rtwLogInfo, "");
    rtliSetLogXFinal(MotorFaultDeploy_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MotorFaultDeploy_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MotorFaultDeploy_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(MotorFaultDeploy_M->rtwLogInfo, 0);
    rtliSetLogDecimation(MotorFaultDeploy_M->rtwLogInfo, 1);
    rtliSetLogY(MotorFaultDeploy_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(MotorFaultDeploy_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(MotorFaultDeploy_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&MotorFaultDeploy_DW, 0,
                sizeof(DW_MotorFaultDeploy_T));

  /* external inputs */
  (void)memset(&MotorFaultDeploy_U, 0, sizeof(ExtU_MotorFaultDeploy_T));

  /* external outputs */
  (void)memset(&MotorFaultDeploy_Y, 0, sizeof(ExtY_MotorFaultDeploy_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MotorFaultDeploy_M->rtwLogInfo, 0.0,
    rtmGetTFinal(MotorFaultDeploy_M), MotorFaultDeploy_M->Timing.stepSize0,
    (&rtmGetErrorStatus(MotorFaultDeploy_M)));

  /* SystemInitialize for MATLAB Function: '<Root>/BearingDetector' */
  MotorFaultDeploy_DW.buf_not_empty = false;
  memset(&MotorFaultDeploy_DW.buf[0], 0, sizeof(real_T) << 11U);
  MotorFaultDeploy_DW.idx_k = 0.0;
  MotorFaultDeploy_DW.lastLabel_a = 1.0;
  MotorFaultDeploy_DW.cnt_p = 0.0;

  /* SystemInitialize for MATLAB Function: '<Root>/ElectricalDetector' */
  MotorFaultDeploy_DW.bc_not_empty = false;
  memset(&MotorFaultDeploy_DW.bc[0], 0, 2400U * sizeof(real_T));
  memset(&MotorFaultDeploy_DW.bs[0], 0, 2400U * sizeof(real_T));
  MotorFaultDeploy_DW.idx = 0.0;
  MotorFaultDeploy_DW.lastLabel = 1.0;
  MotorFaultDeploy_DW.cnt = 0.0;
}

/* Model terminate function */
void MotorFaultDeploy_terminate(void)
{
  /* (no terminate code required) */
}
