/*
 * Fuzzy_manobra_aplicado_2015b_private.h
 *
 * Code generation for model "Fuzzy_manobra_aplicado_2015b".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Jul 16 13:21:01 2024
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Fuzzy_manobra_aplicado_2015b_private_h_
#define RTW_HEADER_Fuzzy_manobra_aplicado_2015b_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void Fuzzy_manobra_aplicado_Actionu1(real_T rtu_u1, real_T *rty_u2);
extern void Fuzzy_manobr_IfActionSubsystem1(RT_MODEL_Fuzzy_manobra_aplica_T *
  const Fuzzy_manobra_aplicado_2015b_M, real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem1_Fuzzy_ma_T *localB, real_T rtp_a, real_T rtp_b);
extern void Fuzzy_manobr_IfActionSubsystem3(RT_MODEL_Fuzzy_manobra_aplica_T *
  const Fuzzy_manobra_aplicado_2015b_M, real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem3_Fuzzy_ma_T *localB, real_T rtp_c, real_T rtp_d);

/* private model entry point functions */
extern void Fuzzy_manobra_aplicado_2015b_derivatives(void);

#endif                                 /* RTW_HEADER_Fuzzy_manobra_aplicado_2015b_private_h_ */
