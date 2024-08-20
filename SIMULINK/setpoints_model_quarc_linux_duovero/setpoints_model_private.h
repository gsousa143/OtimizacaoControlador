/*
 * setpoints_model_private.h
 *
 * Code generation for model "setpoints_model".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Jun 25 14:39:51 2024
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_setpoints_model_private_h_
#define RTW_HEADER_setpoints_model_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_roundd_snf(real_T u);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern int32_T div_s32(int32_T numerator, int32_T denominator);

#endif                                 /* RTW_HEADER_setpoints_model_private_h_ */
