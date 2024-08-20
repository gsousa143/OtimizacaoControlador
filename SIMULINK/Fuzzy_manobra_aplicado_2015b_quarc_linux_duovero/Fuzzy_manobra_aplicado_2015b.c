/*
 * Fuzzy_manobra_aplicado_2015b.c
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

#include "Fuzzy_manobra_aplicado_2015b.h"
#include "Fuzzy_manobra_aplicado_2015b_private.h"
#include "Fuzzy_manobra_aplicado_2015b_dt.h"

/* Block signals (auto storage) */
B_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_B;

/* Continuous states */
X_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_X;

/* Block states (auto storage) */
DW_Fuzzy_manobra_aplicado_201_T Fuzzy_manobra_aplicado_2015b_DW;

/* Real-time model */
RT_MODEL_Fuzzy_manobra_aplica_T Fuzzy_manobra_aplicado_2015b_M_;
RT_MODEL_Fuzzy_manobra_aplica_T *const Fuzzy_manobra_aplicado_2015b_M =
  &Fuzzy_manobra_aplicado_2015b_M_;
void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T currExp;
  int32_T prevExp;
  int32_T msl;
  real_T yn;
  real_T yd;
  boolean_T isNegative;
  uint32_T u1i;
  uint32_T cb;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : div_s32(currExp - 1, 32);
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0 ? (int32_T)1 : (int32_T)0;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T su1;
  uint32_T su2;
  int32_T i;
  su1 = u1[n - 1] & 2147483648U;
  su2 = u2[n - 1] & 2147483648U;
  if ((su1 ^ su2) != 0U) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = su1 > su2 ? 1 : -1;
      }
    }
  }

  return y;
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0 ? (int32_T)1 : (int32_T)0;
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (uint32_T)(numerator >= 0 ? numerator : -numerator) /
      (denominator >= 0 ? denominator : -denominator);
    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Fuzzy_manobra_aplicado_2015b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S19>/Action: u1'
 *    '<S20>/Action: u1'
 */
void Fuzzy_manobra_aplicado_Actionu1(real_T rtu_u1, real_T *rty_u2)
{
  /* Inport: '<S38>/u1' */
  *rty_u2 = rtu_u1;
}

/*
 * Output and update for action system:
 *    '<S41>/If Action Subsystem1'
 *    '<S42>/If Action Subsystem1'
 */
void Fuzzy_manobr_IfActionSubsystem1(RT_MODEL_Fuzzy_manobra_aplica_T * const
  Fuzzy_manobra_aplicado_2015b_M, real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem1_Fuzzy_ma_T *localB, real_T rtp_a, real_T rtp_b)
{
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* Sum: '<S44>/Sum1' incorporates:
     *  Constant: '<S44>/a'
     *  Constant: '<S44>/b'
     */
    localB->ba = rtp_b - rtp_a;
  }

  /* Product: '<S44>/Product ab (trimf)' incorporates:
   *  Constant: '<S44>/a'
   *  Sum: '<S44>/Sum'
   */
  *rty_Out1 = (rtu_x - rtp_a) / localB->ba;
}

/*
 * Output and update for action system:
 *    '<S41>/If Action Subsystem3'
 *    '<S42>/If Action Subsystem3'
 */
void Fuzzy_manobr_IfActionSubsystem3(RT_MODEL_Fuzzy_manobra_aplica_T * const
  Fuzzy_manobra_aplicado_2015b_M, real_T rtu_x, real_T *rty_Out1,
  B_IfActionSubsystem3_Fuzzy_ma_T *localB, real_T rtp_c, real_T rtp_d)
{
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* Sum: '<S46>/Sum2' incorporates:
     *  Constant: '<S46>/c'
     *  Constant: '<S46>/d'
     */
    localB->dc = rtp_d - rtp_c;
  }

  /* Product: '<S46>/Product cd (trimf)' incorporates:
   *  Constant: '<S46>/d'
   *  Sum: '<S46>/Sum3'
   */
  *rty_Out1 = 1.0 / localB->dc * (rtp_d - rtu_x);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Fuzzy_manobra_aplicado_2015b_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sqrt;
  real_T rtb_Sum1;
  real_T rtb_Sum1_k;
  real_T rtb_HILRead1_o1;
  real_T rtb_HILRead1_o4;
  real_T rtb_HILRead1_o2[2];
  boolean_T rtb_HILRead1_o3[3];
  int64m_T b_i_sp;
  boolean_T p;
  boolean_T blarge;
  boolean_T alarge;
  boolean_T bsmall;
  boolean_T asmall;
  real_T rtb_Weighting;
  int8_T rtAction;
  real_T rtb_Weighting_ga;
  real_T rtb_Weighting_n;
  real_T rtb_Weighting_mf;
  real_T rtb_Weighting_g;
  real_T rtb_Weighting_d;
  real_T rtb_Weighting_f;
  real_T rtb_Weighting_j;
  real_T rtb_Integrator1_o;
  real_T rtb_Integrator1;
  real_T rtb_Integrator2;
  real_T rtb_AggMethod1[101];
  real_T rtb_AggMethod2[101];
  real_T rtb_impMethod[202];
  int8_T rtPrevAction;
  real_T rtb_impMethod_o[202];
  real_T rtb_impMethod_hq[202];
  real_T rtb_impMethod_a[202];
  real_T rtb_impMethod_g[202];
  real_T rtb_impMethod_m[202];
  real_T rtb_impMethod_n[202];
  real_T rtb_impMethod_ks[202];
  real_T rtb_impMethod_i[202];
  real_T rtb_impMethod_hp[202];
  real_T rtb_impMethod_e5[202];
  real_T rtb_impMethod_h[202];
  real_T rtb_Sum_g;
  int32_T i;
  real_T rtb_Switch_n_idx_0;
  int64m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  real_T u0;
  static int64m_T tmp_2 = { { 0U, 1048576U } };

  static int64m_T tmp_3 = { { 0U, 4293918720U } };

  static int64m_T tmp_4 = { { 0U, 2147483648U } };

  static int64m_T tmp_5 = { { MAX_uint32_T, 2147483647U } };

  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* set solver stop time */
    if (!(Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                            ((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH0
        + 1) * Fuzzy_manobra_aplicado_2015b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                            ((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick0
        + 1) * Fuzzy_manobra_aplicado_2015b_M->Timing.stepSize0 +
        Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH0 *
        Fuzzy_manobra_aplicado_2015b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    Fuzzy_manobra_aplicado_2015b_M->Timing.t[0] = rtsiGetT
      (&Fuzzy_manobra_aplicado_2015b_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.Actionu1.Actionu1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanB_o);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3_m.IfActionSubsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Integrator: '<Root>/Integrator3' */
  Fuzzy_manobra_aplicado_2015b_B.Integrator3 =
    Fuzzy_manobra_aplicado_2015b_X.theta;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Integrator: '<Root>/Integrator1' */
  Fuzzy_manobra_aplicado_2015b_B.Integrator1 =
    Fuzzy_manobra_aplicado_2015b_X.x_a;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Integrator: '<Root>/Integrator2' */
  Fuzzy_manobra_aplicado_2015b_B.Integrator2 =
    Fuzzy_manobra_aplicado_2015b_X.y_a;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* UnitDelay: '<S9>/Unit Delay' */
    Fuzzy_manobra_aplicado_2015b_B.UnitDelay =
      Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE;

    /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     */
    rtb_Weighting = Fuzzy_manobra_aplicado_2015b_B.UnitDelay;

    /* MATLAB Function 'Subsystem/MATLAB Function': '<S72>:1' */
    if (Fuzzy_manobra_aplicado_2015b_B.UnitDelay < 1.0) {
      /* '<S72>:1:3' */
      /* '<S72>:1:4' */
      rtb_Weighting = 1.0;
    }

    /* '<S72>:1:6' */
    rtb_Switch_n_idx_0 = rt_roundd_snf(rtb_Weighting);
    if (rtb_Switch_n_idx_0 < 9.2233720368547758E+18) {
      if (rtb_Switch_n_idx_0 >= -9.2233720368547758E+18) {
        Double2MultiWord(rtb_Switch_n_idx_0, &tmp.chunks[0U], 2);
      } else {
        tmp = tmp_4;
      }
    } else {
      tmp = tmp_5;
    }

    b_i_sp = tmp;
    p = false;
    if (!((-9.2233720368547758E+18 <= Fuzzy_manobra_aplicado_2015b_P.N_sp) &&
          (Fuzzy_manobra_aplicado_2015b_P.N_sp < 9.2233720368547758E+18))) {
      if (Fuzzy_manobra_aplicado_2015b_P.N_sp >= 0.0) {
        p = true;
      }
    } else {
      blarge = (Fuzzy_manobra_aplicado_2015b_P.N_sp >= 4.503599627370496E+15);
      tmp_0 = tmp_2;
      alarge = sMultiWordGe(&b_i_sp.chunks[0U], &tmp_0.chunks[0U], 2);
      bsmall = (Fuzzy_manobra_aplicado_2015b_P.N_sp <= -4.503599627370496E+15);
      tmp_0 = tmp_3;
      asmall = sMultiWordLe(&b_i_sp.chunks[0U], &tmp_0.chunks[0U], 2);
      if (((!alarge) && blarge) || (asmall && (!bsmall))) {
        p = true;
      } else if (blarge || asmall) {
        Double2MultiWord(rt_roundd_snf(Fuzzy_manobra_aplicado_2015b_P.N_sp),
                         &tmp_1.chunks[0U], 2);
        p = sMultiWordLe(&b_i_sp.chunks[0U], &tmp_1.chunks[0U], 2);
      } else {
        if ((!alarge) && (!bsmall)) {
          p = (sMultiWord2Double(&b_i_sp.chunks[0U], 2, 0) <=
               Fuzzy_manobra_aplicado_2015b_P.N_sp);
        }
      }
    }

    if (p) {
      /* '<S72>:1:8' */
      Fuzzy_manobra_aplicado_2015b_B.x_sp =
        Fuzzy_manobra_aplicado_2015b_P.setpoints[MultiWord2sLong(&b_i_sp.chunks
        [0U]) - 1];

      /* '<S72>:1:9' */
      Fuzzy_manobra_aplicado_2015b_B.y_sp =
        Fuzzy_manobra_aplicado_2015b_P.setpoints[MultiWord2sLong(&b_i_sp.chunks
        [0U]) + 22];
    } else {
      /* '<S72>:1:11' */
      Fuzzy_manobra_aplicado_2015b_B.x_sp =
        Fuzzy_manobra_aplicado_2015b_P.setpoints[22];

      /* '<S72>:1:12' */
      Fuzzy_manobra_aplicado_2015b_B.y_sp =
        Fuzzy_manobra_aplicado_2015b_P.setpoints[45];
    }

    /* End of MATLAB Function: '<S9>/MATLAB Function' */
  }

  /* Sum: '<Root>/Erro X' */
  rtb_Weighting_n = Fuzzy_manobra_aplicado_2015b_B.x_sp -
    Fuzzy_manobra_aplicado_2015b_B.Integrator1;

  /* Sum: '<Root>/Erro Y' */
  rtb_Weighting_ga = Fuzzy_manobra_aplicado_2015b_B.y_sp -
    Fuzzy_manobra_aplicado_2015b_B.Integrator2;

  /* Sqrt: '<S6>/Sqrt' incorporates:
   *  Math: '<S6>/Math Function'
   *  Math: '<S6>/Math Function1'
   *  Sum: '<S6>/Add'
   *
   * About '<S6>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S6>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Sqrt = sqrt(rtb_Weighting_n * rtb_Weighting_n + rtb_Weighting_ga *
                  rtb_Weighting_ga);

  /* If: '<S42>/If' incorporates:
   *  Constant: '<S47>/0'
   *  Constant: '<S49>/0'
   */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    if ((rtb_Sqrt < -1.8) || (rtb_Sqrt > 0.02)) {
      rtAction = 0;
    } else if ((rtb_Sqrt >= -0.2) && (rtb_Sqrt <= 0.01)) {
      rtAction = 1;
    } else if (rtb_Sqrt < -0.2) {
      rtAction = 2;
    } else {
      rtAction = 3;
    }

    Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge =
        Fuzzy_manobra_aplicado_2015b_P.u_Value_p;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S42>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge =
        Fuzzy_manobra_aplicado_2015b_P.u_Value_h;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S42>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    Fuzzy_manobr_IfActionSubsystem1(Fuzzy_manobra_aplicado_2015b_M, rtb_Sqrt,
      &Fuzzy_manobra_aplicado_2015b_B.Merge,
      &Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1,
      Fuzzy_manobra_aplicado_2015b_P.MP_a, Fuzzy_manobra_aplicado_2015b_P.MP_b);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC
        (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S42>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    Fuzzy_manobr_IfActionSubsystem3(Fuzzy_manobra_aplicado_2015b_M, rtb_Sqrt,
      &Fuzzy_manobra_aplicado_2015b_B.Merge,
      &Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3,
      Fuzzy_manobra_aplicado_2015b_P.MP_c, Fuzzy_manobra_aplicado_2015b_P.MP_d);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC
        (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3.IfActionSubsystem3_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S42>/If Action Subsystem3' */
    break;
  }

  /* End of If: '<S42>/If' */

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   */
  rtb_Weighting = Fuzzy_manobra_aplicado_2015b_P.Weight_Value *
    Fuzzy_manobra_aplicado_2015b_B.Merge;

  /* MinMax: '<S21>/impMethod' incorporates:
   *  Constant: '<S35>/P'
   *  Constant: '<S36>/N'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_Weighting <= Fuzzy_manobra_aplicado_2015b_P.P_Value[i]) || rtIsNaN
        (Fuzzy_manobra_aplicado_2015b_P.P_Value[i])) {
      rtb_impMethod[i] = rtb_Weighting;
    } else {
      rtb_impMethod[i] = Fuzzy_manobra_aplicado_2015b_P.P_Value[i];
    }

    if ((rtb_Weighting <= Fuzzy_manobra_aplicado_2015b_P.N_Value[i]) || rtIsNaN
        (Fuzzy_manobra_aplicado_2015b_P.N_Value[i])) {
      rtb_impMethod[i + 101] = rtb_Weighting;
    } else {
      rtb_impMethod[i + 101] = Fuzzy_manobra_aplicado_2015b_P.N_Value[i];
    }
  }

  /* End of MinMax: '<S21>/impMethod' */

  /* Trigonometry: '<S8>/Trigonometric Function1' */
  Fuzzy_manobra_aplicado_2015b_B.TrigonometricFunction1 = rt_atan2d_snf
    (rtb_Weighting_ga, rtb_Weighting_n);
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* S-Function (hil_read_block): '<S63>/HIL Read1' */

    /* S-Function Block: Fuzzy_manobra_aplicado_2015b/QBot_Basic/QBot2_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
         &Fuzzy_manobra_aplicado_2015b_P.HILRead1_analog_channels, 1U,
         Fuzzy_manobra_aplicado_2015b_P.HILRead1_encoder_channels, 2U,
         Fuzzy_manobra_aplicado_2015b_P.HILRead1_digital_channels, 3U,
         &Fuzzy_manobra_aplicado_2015b_P.HILRead1_other_channels, 1U,
         &rtb_HILRead1_o1,
         &Fuzzy_manobra_aplicado_2015b_DW.HILRead1_EncoderBuffer[0],
         (t_boolean *)&rtb_HILRead1_o3[0],
         &rtb_HILRead1_o4
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] =
          Fuzzy_manobra_aplicado_2015b_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] =
          Fuzzy_manobra_aplicado_2015b_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S5>/Bias Removal' */
    /* Step: '<S62>/Step: end_time' */
    if ((((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1+
           Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1* 4294967296.0)) *
         0.01) < Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_end_time) {
      rtb_Weighting_ga = Fuzzy_manobra_aplicado_2015b_P.Stepend_time_Y0;
    } else {
      rtb_Weighting_ga = Fuzzy_manobra_aplicado_2015b_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S62>/Step: end_time' */

    /* Step: '<S62>/Step: start_time' */
    if ((((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1+
           Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1* 4294967296.0)) *
         0.01) < Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_start_time) {
      rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_P.Stepstart_time_Y0;
    } else {
      rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S62>/Step: start_time' */

    /* Outputs for Enabled SubSystem: '<S62>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S64>/Enable'
     */
    /* Logic: '<S62>/Logical Operator' incorporates:
     *  Logic: '<S62>/Logical Operator1'
     */
    if ((rtb_Switch_n_idx_0 != 0.0) && (!(rtb_Weighting_ga != 0.0))) {
      if (!Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
        Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p =
          Fuzzy_manobra_aplicado_2015b_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
        Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE =
          Fuzzy_manobra_aplicado_2015b_P.Sumk1n1xk_InitialCondition;
        Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE = true;
      }

      /* Sum: '<S68>/Count' incorporates:
       *  Constant: '<S68>/unity'
       *  UnitDelay: '<S68>/Unit Delay'
       */
      rtb_Weighting_n = Fuzzy_manobra_aplicado_2015b_P.unity_Value +
        Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p;

      /* Sum: '<S64>/Sum' incorporates:
       *  UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )'
       */
      rtb_Sum_g = rtb_HILRead1_o4 +
        Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE;

      /* Product: '<S64>/div' */
      Fuzzy_manobra_aplicado_2015b_B.div = rtb_Sum_g / rtb_Weighting_n;

      /* Update for UnitDelay: '<S68>/Unit Delay' */
      Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p = rtb_Weighting_n;

      /* Update for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
      Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE = rtb_Sum_g;
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE) {
        Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S62>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S62>/Enabled Moving Average' */

    /* Sum: '<S62>/Sum' */
    rtb_Weighting_n = rtb_HILRead1_o4 - Fuzzy_manobra_aplicado_2015b_B.div;

    /* SwitchCase: '<S62>/Switch Case' incorporates:
     *  Constant: '<S65>/Constant'
     *  Inport: '<S66>/Vin'
     *  Inport: '<S67>/V-Vavg'
     */
    rtPrevAction = Fuzzy_manobra_aplicado_2015b_DW.SwitchCase_ActiveSubsystem;
    rtAction = -1;
    if (Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_switch_id < 0.0) {
      rtb_Switch_n_idx_0 = ceil
        (Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_switch_id);
    } else {
      rtb_Switch_n_idx_0 = floor
        (Fuzzy_manobra_aplicado_2015b_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(rtb_Switch_n_idx_0) || rtIsInf(rtb_Switch_n_idx_0)) {
      rtb_Switch_n_idx_0 = 0.0;
    } else {
      rtb_Switch_n_idx_0 = fmod(rtb_Switch_n_idx_0, 4.294967296E+9);
    }

    switch (rtb_Switch_n_idx_0 < 0.0 ? -(int32_T)(uint32_T)-rtb_Switch_n_idx_0 :
            (int32_T)(uint32_T)rtb_Switch_n_idx_0) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    Fuzzy_manobra_aplicado_2015b_DW.SwitchCase_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S65>/zero' incorporates:
         *  Outport: '<S65>/zero'
         */
        Fuzzy_manobra_aplicado_2015b_B.Constant =
          Fuzzy_manobra_aplicado_2015b_P.zero_Y0;
        break;

       case 1:
        /* Disable for Outport: '<S66>/Vbiased' incorporates:
         *  Outport: '<S66>/Vbiased'
         */
        Fuzzy_manobra_aplicado_2015b_B.Vin =
          Fuzzy_manobra_aplicado_2015b_P.Vbiased_Y0;
        break;

       case 2:
        /* Disable for Outport: '<S67>/Vunbiased' incorporates:
         *  Outport: '<S67>/Vunbiased'
         */
        Fuzzy_manobra_aplicado_2015b_B.VVavg =
          Fuzzy_manobra_aplicado_2015b_P.Vunbiased_Y0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S62>/Switch Case Action Subsystem' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      Fuzzy_manobra_aplicado_2015b_B.Constant =
        Fuzzy_manobra_aplicado_2015b_P.Constant_Value;
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem_Subsy);

      /* End of Outputs for SubSystem: '<S62>/Switch Case Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S62>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      Fuzzy_manobra_aplicado_2015b_B.Vin = rtb_HILRead1_o4;
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S62>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S62>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      Fuzzy_manobra_aplicado_2015b_B.VVavg = rtb_Weighting_n;
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S62>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S62>/Switch Case' */

    /* Switch: '<S62>/Switch' incorporates:
     *  Logic: '<S62>/Logical Operator2'
     *  Sum: '<S62>/Sum1'
     */
    if (!(rtb_Weighting_ga != 0.0)) {
      rtb_Weighting_n = (Fuzzy_manobra_aplicado_2015b_B.Constant +
                         Fuzzy_manobra_aplicado_2015b_B.Vin) +
        Fuzzy_manobra_aplicado_2015b_B.VVavg;
    }

    /* End of Switch: '<S62>/Switch' */
    /* End of Outputs for SubSystem: '<S5>/Bias Removal' */

    /* Product: '<S5>/Product' */
    Fuzzy_manobra_aplicado_2015b_B.Product = rtb_Weighting_n * rtb_Weighting_ga;
  }

  /* ManualSwitch: '<Root>/sw5' */
  if (Fuzzy_manobra_aplicado_2015b_P.sw5_CurrentSetting == 1) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Product;
  } else {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Integrator3;
  }

  /* End of ManualSwitch: '<Root>/sw5' */

  /* Gain: '<S8>/Gain1' incorporates:
   *  Gain: '<S8>/Gain'
   *  Sum: '<S8>/Add'
   *  Trigonometry: '<S8>/Trigonometric Function'
   *  Trigonometry: '<S8>/Trigonometric Function2'
   */
  rtb_Weighting_ga = atan(tan
    ((Fuzzy_manobra_aplicado_2015b_B.TrigonometricFunction1 - rtb_Switch_n_idx_0)
     * Fuzzy_manobra_aplicado_2015b_P.Gain_Gain)) *
    Fuzzy_manobra_aplicado_2015b_P.Gain1_Gain;

  /* Product: '<S51>/Product (gaussmf)' incorporates:
   *  Constant: '<S51>/mu'
   *  Constant: '<S51>/sigma'
   *  Sum: '<S51>/Sum'
   */
  rtb_Weighting_n = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.EN_mu) /
    Fuzzy_manobra_aplicado_2015b_P.EN_sigma;

  /* Gain: '<S51>/Gain' incorporates:
   *  Math: '<S51>/Squaring (gaussmf)'
   */
  rtb_Weighting_n = rtb_Weighting_n * rtb_Weighting_n *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_l;

  /* If: '<S41>/If' incorporates:
   *  Constant: '<S43>/0'
   *  Constant: '<S45>/0'
   */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    if ((rtb_Sqrt < 0.01) || (rtb_Sqrt > 7.5)) {
      rtAction = 0;
    } else if ((rtb_Sqrt >= 0.02) && (rtb_Sqrt <= 7.0)) {
      rtAction = 1;
    } else if (rtb_Sqrt < 0.02) {
      rtAction = 2;
    } else {
      rtAction = 3;
    }

    Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_l = rtAction;
  } else {
    rtAction = Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_l;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge_k =
        Fuzzy_manobra_aplicado_2015b_P.u_Value;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC_m);
    }

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge_k =
        Fuzzy_manobra_aplicado_2015b_P.u_Value_g;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanB_o);
    }

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    Fuzzy_manobr_IfActionSubsystem1(Fuzzy_manobra_aplicado_2015b_M, rtb_Sqrt,
      &Fuzzy_manobra_aplicado_2015b_B.Merge_k,
      &Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1_i,
      Fuzzy_manobra_aplicado_2015b_P.G_a, Fuzzy_manobra_aplicado_2015b_P.G_b);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC
        (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    Fuzzy_manobr_IfActionSubsystem3(Fuzzy_manobra_aplicado_2015b_M, rtb_Sqrt,
      &Fuzzy_manobra_aplicado_2015b_B.Merge_k,
      &Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3_m,
      Fuzzy_manobra_aplicado_2015b_P.G_c, Fuzzy_manobra_aplicado_2015b_P.G_d);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC
        (Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3_m.IfActionSubsystem3_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem3' */
    break;
  }

  /* End of If: '<S41>/If' */

  /* MinMax: '<S25>/andorMethod' incorporates:
   *  Math: '<S51>/Exponential (gaussmf)'
   *
   * About '<S51>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_n);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S25>/andorMethod' */

  /* Product: '<S25>/Weighting' incorporates:
   *  Constant: '<S25>/Weight'
   */
  rtb_Weighting_n = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_h *
    rtb_Switch_n_idx_0;

  /* Product: '<S53>/Product (gaussmf)' incorporates:
   *  Constant: '<S53>/mu'
   *  Constant: '<S53>/sigma'
   *  Sum: '<S53>/Sum'
   */
  rtb_Sum_g = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.GN_mu) /
    Fuzzy_manobra_aplicado_2015b_P.GN_sigma;

  /* MinMax: '<S26>/andorMethod' incorporates:
   *  Gain: '<S53>/Gain'
   *  Math: '<S53>/Exponential (gaussmf)'
   *  Math: '<S53>/Squaring (gaussmf)'
   *
   * About '<S53>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Sum_g * rtb_Sum_g *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_c);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S26>/andorMethod' */

  /* Product: '<S26>/Weighting' incorporates:
   *  Constant: '<S26>/Weight'
   */
  rtb_Sum_g = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_g * rtb_Switch_n_idx_0;

  /* Product: '<S55>/Product (gaussmf)' incorporates:
   *  Constant: '<S55>/mu'
   *  Constant: '<S55>/sigma'
   *  Sum: '<S55>/Sum'
   */
  rtb_Weighting_mf = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.MN_mu) /
    Fuzzy_manobra_aplicado_2015b_P.MN_sigma;

  /* MinMax: '<S27>/andorMethod' incorporates:
   *  Gain: '<S55>/Gain'
   *  Math: '<S55>/Exponential (gaussmf)'
   *  Math: '<S55>/Squaring (gaussmf)'
   *
   * About '<S55>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_mf * rtb_Weighting_mf *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_k);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S27>/andorMethod' */

  /* Product: '<S27>/Weighting' incorporates:
   *  Constant: '<S27>/Weight'
   */
  rtb_Weighting_mf = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_n *
    rtb_Switch_n_idx_0;

  /* Product: '<S61>/Product (gaussmf)' incorporates:
   *  Constant: '<S61>/mu'
   *  Constant: '<S61>/sigma'
   *  Sum: '<S61>/Sum'
   */
  rtb_Weighting_g = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.Z_mu) /
    Fuzzy_manobra_aplicado_2015b_P.Z_sigma;

  /* MinMax: '<S28>/andorMethod' incorporates:
   *  Gain: '<S61>/Gain'
   *  Math: '<S61>/Exponential (gaussmf)'
   *  Math: '<S61>/Squaring (gaussmf)'
   *
   * About '<S61>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_g * rtb_Weighting_g *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_a);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S28>/andorMethod' */

  /* Product: '<S28>/Weighting' incorporates:
   *  Constant: '<S28>/Weight'
   */
  rtb_Weighting_g = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_p *
    rtb_Switch_n_idx_0;

  /* Product: '<S56>/Product (gaussmf)' incorporates:
   *  Constant: '<S56>/mu'
   *  Constant: '<S56>/sigma'
   *  Sum: '<S56>/Sum'
   */
  rtb_Weighting_d = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.MP_mu) /
    Fuzzy_manobra_aplicado_2015b_P.MP_sigma;

  /* MinMax: '<S29>/andorMethod' incorporates:
   *  Gain: '<S56>/Gain'
   *  Math: '<S56>/Exponential (gaussmf)'
   *  Math: '<S56>/Squaring (gaussmf)'
   *
   * About '<S56>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_d * rtb_Weighting_d *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_e);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S29>/andorMethod' */

  /* Product: '<S29>/Weighting' incorporates:
   *  Constant: '<S29>/Weight'
   */
  rtb_Weighting_d = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_nc *
    rtb_Switch_n_idx_0;

  /* Product: '<S54>/Product (gaussmf)' incorporates:
   *  Constant: '<S54>/mu'
   *  Constant: '<S54>/sigma'
   *  Sum: '<S54>/Sum'
   */
  rtb_Weighting_f = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.GP_mu) /
    Fuzzy_manobra_aplicado_2015b_P.GP_sigma;

  /* MinMax: '<S30>/andorMethod' incorporates:
   *  Gain: '<S54>/Gain'
   *  Math: '<S54>/Exponential (gaussmf)'
   *  Math: '<S54>/Squaring (gaussmf)'
   *
   * About '<S54>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_f * rtb_Weighting_f *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_o);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S30>/andorMethod' */

  /* Product: '<S30>/Weighting' incorporates:
   *  Constant: '<S30>/Weight'
   */
  rtb_Weighting_f = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_e *
    rtb_Switch_n_idx_0;

  /* Product: '<S52>/Product (gaussmf)' incorporates:
   *  Constant: '<S52>/mu'
   *  Constant: '<S52>/sigma'
   *  Sum: '<S52>/Sum'
   */
  rtb_Weighting_j = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.EP_mu) /
    Fuzzy_manobra_aplicado_2015b_P.EP_sigma;

  /* MinMax: '<S31>/andorMethod' incorporates:
   *  Gain: '<S52>/Gain'
   *  Math: '<S52>/Exponential (gaussmf)'
   *  Math: '<S52>/Squaring (gaussmf)'
   *
   * About '<S52>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_j * rtb_Weighting_j *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_eg);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S31>/andorMethod' */

  /* Product: '<S31>/Weighting' incorporates:
   *  Constant: '<S31>/Weight'
   */
  rtb_Weighting_j = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_k *
    rtb_Switch_n_idx_0;

  /* Product: '<S57>/Product (gaussmf)' incorporates:
   *  Constant: '<S57>/mu'
   *  Constant: '<S57>/sigma'
   *  Sum: '<S57>/Sum'
   */
  rtb_Integrator1_o = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.PNF_mu)
    / Fuzzy_manobra_aplicado_2015b_P.PNF_sigma;

  /* MinMax: '<S32>/andorMethod' incorporates:
   *  Gain: '<S57>/Gain'
   *  Math: '<S57>/Exponential (gaussmf)'
   *  Math: '<S57>/Squaring (gaussmf)'
   *
   * About '<S57>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Integrator1_o * rtb_Integrator1_o *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_b);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S32>/andorMethod' */

  /* Product: '<S32>/Weighting' incorporates:
   *  Constant: '<S32>/Weight'
   */
  rtb_Integrator1_o = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_a *
    rtb_Switch_n_idx_0;

  /* Product: '<S59>/Product (gaussmf)' incorporates:
   *  Constant: '<S59>/mu'
   *  Constant: '<S59>/sigma'
   *  Sum: '<S59>/Sum'
   */
  rtb_Integrator1 = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.PPF_mu) /
    Fuzzy_manobra_aplicado_2015b_P.PPF_sigma;

  /* MinMax: '<S22>/andorMethod' incorporates:
   *  Gain: '<S59>/Gain'
   *  Math: '<S59>/Exponential (gaussmf)'
   *  Math: '<S59>/Squaring (gaussmf)'
   *
   * About '<S59>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Integrator1 * rtb_Integrator1 *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_d);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S22>/andorMethod' */

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   */
  rtb_Integrator1 = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_ec *
    rtb_Switch_n_idx_0;

  /* Product: '<S58>/Product (gaussmf)' incorporates:
   *  Constant: '<S58>/mu'
   *  Constant: '<S58>/sigma'
   *  Sum: '<S58>/Sum'
   */
  rtb_Integrator2 = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.PNR_mu) /
    Fuzzy_manobra_aplicado_2015b_P.PNR_sigma;

  /* MinMax: '<S23>/andorMethod' incorporates:
   *  Gain: '<S58>/Gain'
   *  Math: '<S58>/Exponential (gaussmf)'
   *  Math: '<S58>/Squaring (gaussmf)'
   *
   * About '<S58>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Integrator2 * rtb_Integrator2 *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_p);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S23>/andorMethod' */

  /* Product: '<S23>/Weighting' incorporates:
   *  Constant: '<S23>/Weight'
   */
  rtb_Integrator2 = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_l *
    rtb_Switch_n_idx_0;

  /* Product: '<S60>/Product (gaussmf)' incorporates:
   *  Constant: '<S60>/mu'
   *  Constant: '<S60>/sigma'
   *  Sum: '<S60>/Sum'
   */
  rtb_Weighting_ga = (rtb_Weighting_ga - Fuzzy_manobra_aplicado_2015b_P.PPR_mu) /
    Fuzzy_manobra_aplicado_2015b_P.PPR_sigma;

  /* MinMax: '<S24>/andorMethod' incorporates:
   *  Gain: '<S60>/Gain'
   *  Math: '<S60>/Exponential (gaussmf)'
   *  Math: '<S60>/Squaring (gaussmf)'
   *
   * About '<S60>/Exponential (gaussmf)':
   *  Operator: exp
   */
  rtb_Switch_n_idx_0 = exp(rtb_Weighting_ga * rtb_Weighting_ga *
    Fuzzy_manobra_aplicado_2015b_P.Gain_Gain_kj);
  if (!((rtb_Switch_n_idx_0 <= Fuzzy_manobra_aplicado_2015b_B.Merge_k) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_B.Merge_k))) {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_B.Merge_k;
  }

  /* End of MinMax: '<S24>/andorMethod' */

  /* Product: '<S24>/Weighting' incorporates:
   *  Constant: '<S24>/Weight'
   */
  rtb_Weighting_ga = Fuzzy_manobra_aplicado_2015b_P.Weight_Value_ez *
    rtb_Switch_n_idx_0;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S25>/impMethod' incorporates:
     *  Constant: '<S35>/R'
     *  Constant: '<S36>/N'
     */
    if ((rtb_Weighting_n <= Fuzzy_manobra_aplicado_2015b_P.R_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.R_Value[i])) {
      rtb_impMethod_o[i] = rtb_Weighting_n;
    } else {
      rtb_impMethod_o[i] = Fuzzy_manobra_aplicado_2015b_P.R_Value[i];
    }

    if ((rtb_Weighting_n <= Fuzzy_manobra_aplicado_2015b_P.N_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.N_Value[i])) {
      rtb_impMethod_o[i + 101] = rtb_Weighting_n;
    } else {
      rtb_impMethod_o[i + 101] = Fuzzy_manobra_aplicado_2015b_P.N_Value[i];
    }

    /* End of MinMax: '<S25>/impMethod' */

    /* MinMax: '<S26>/impMethod' incorporates:
     *  Constant: '<S35>/P'
     *  Constant: '<S36>/AH'
     */
    if ((rtb_Sum_g <= Fuzzy_manobra_aplicado_2015b_P.P_Value[i]) || rtIsNaN
        (Fuzzy_manobra_aplicado_2015b_P.P_Value[i])) {
      rtb_impMethod_hq[i] = rtb_Sum_g;
    } else {
      rtb_impMethod_hq[i] = Fuzzy_manobra_aplicado_2015b_P.P_Value[i];
    }

    if ((rtb_Sum_g <= Fuzzy_manobra_aplicado_2015b_P.AH_Value[i]) || rtIsNaN
        (Fuzzy_manobra_aplicado_2015b_P.AH_Value[i])) {
      rtb_impMethod_hq[i + 101] = rtb_Sum_g;
    } else {
      rtb_impMethod_hq[i + 101] = Fuzzy_manobra_aplicado_2015b_P.AH_Value[i];
    }

    /* End of MinMax: '<S26>/impMethod' */

    /* MinMax: '<S27>/impMethod' incorporates:
     *  Constant: '<S35>/P'
     *  Constant: '<S36>/H'
     */
    if ((rtb_Weighting_mf <= Fuzzy_manobra_aplicado_2015b_P.P_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.P_Value[i])) {
      rtb_impMethod_a[i] = rtb_Weighting_mf;
    } else {
      rtb_impMethod_a[i] = Fuzzy_manobra_aplicado_2015b_P.P_Value[i];
    }

    if ((rtb_Weighting_mf <= Fuzzy_manobra_aplicado_2015b_P.H_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.H_Value[i])) {
      rtb_impMethod_a[i + 101] = rtb_Weighting_mf;
    } else {
      rtb_impMethod_a[i + 101] = Fuzzy_manobra_aplicado_2015b_P.H_Value[i];
    }

    /* End of MinMax: '<S27>/impMethod' */

    /* MinMax: '<S28>/impMethod' incorporates:
     *  Constant: '<S35>/F'
     *  Constant: '<S36>/N'
     */
    if ((rtb_Weighting_g <= Fuzzy_manobra_aplicado_2015b_P.F_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.F_Value[i])) {
      rtb_impMethod_g[i] = rtb_Weighting_g;
    } else {
      rtb_impMethod_g[i] = Fuzzy_manobra_aplicado_2015b_P.F_Value[i];
    }

    if ((rtb_Weighting_g <= Fuzzy_manobra_aplicado_2015b_P.N_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.N_Value[i])) {
      rtb_impMethod_g[i + 101] = rtb_Weighting_g;
    } else {
      rtb_impMethod_g[i + 101] = Fuzzy_manobra_aplicado_2015b_P.N_Value[i];
    }

    /* End of MinMax: '<S28>/impMethod' */

    /* MinMax: '<S29>/impMethod' incorporates:
     *  Constant: '<S35>/P'
     *  Constant: '<S36>/AH'
     */
    if ((rtb_Weighting_d <= Fuzzy_manobra_aplicado_2015b_P.P_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.P_Value[i])) {
      rtb_impMethod_m[i] = rtb_Weighting_d;
    } else {
      rtb_impMethod_m[i] = Fuzzy_manobra_aplicado_2015b_P.P_Value[i];
    }

    if ((rtb_Weighting_d <= Fuzzy_manobra_aplicado_2015b_P.AH_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.AH_Value[i])) {
      rtb_impMethod_m[i + 101] = rtb_Weighting_d;
    } else {
      rtb_impMethod_m[i + 101] = Fuzzy_manobra_aplicado_2015b_P.AH_Value[i];
    }

    /* End of MinMax: '<S29>/impMethod' */

    /* MinMax: '<S30>/impMethod' incorporates:
     *  Constant: '<S35>/P'
     *  Constant: '<S36>/H'
     */
    if ((rtb_Weighting_f <= Fuzzy_manobra_aplicado_2015b_P.P_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.P_Value[i])) {
      rtb_impMethod_n[i] = rtb_Weighting_f;
    } else {
      rtb_impMethod_n[i] = Fuzzy_manobra_aplicado_2015b_P.P_Value[i];
    }

    if ((rtb_Weighting_f <= Fuzzy_manobra_aplicado_2015b_P.H_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.H_Value[i])) {
      rtb_impMethod_n[i + 101] = rtb_Weighting_f;
    } else {
      rtb_impMethod_n[i + 101] = Fuzzy_manobra_aplicado_2015b_P.H_Value[i];
    }

    /* End of MinMax: '<S30>/impMethod' */

    /* MinMax: '<S31>/impMethod' incorporates:
     *  Constant: '<S35>/R'
     *  Constant: '<S36>/N'
     */
    if ((rtb_Weighting_j <= Fuzzy_manobra_aplicado_2015b_P.R_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.R_Value[i])) {
      rtb_impMethod_ks[i] = rtb_Weighting_j;
    } else {
      rtb_impMethod_ks[i] = Fuzzy_manobra_aplicado_2015b_P.R_Value[i];
    }

    if ((rtb_Weighting_j <= Fuzzy_manobra_aplicado_2015b_P.N_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.N_Value[i])) {
      rtb_impMethod_ks[i + 101] = rtb_Weighting_j;
    } else {
      rtb_impMethod_ks[i + 101] = Fuzzy_manobra_aplicado_2015b_P.N_Value[i];
    }

    /* End of MinMax: '<S31>/impMethod' */

    /* MinMax: '<S32>/impMethod' incorporates:
     *  Constant: '<S35>/MF'
     *  Constant: '<S36>/H'
     */
    if ((rtb_Integrator1_o <= Fuzzy_manobra_aplicado_2015b_P.MF_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.MF_Value[i])) {
      rtb_impMethod_i[i] = rtb_Integrator1_o;
    } else {
      rtb_impMethod_i[i] = Fuzzy_manobra_aplicado_2015b_P.MF_Value[i];
    }

    if ((rtb_Integrator1_o <= Fuzzy_manobra_aplicado_2015b_P.H_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.H_Value[i])) {
      rtb_impMethod_i[i + 101] = rtb_Integrator1_o;
    } else {
      rtb_impMethod_i[i + 101] = Fuzzy_manobra_aplicado_2015b_P.H_Value[i];
    }

    /* End of MinMax: '<S32>/impMethod' */

    /* MinMax: '<S22>/impMethod' incorporates:
     *  Constant: '<S35>/MF'
     *  Constant: '<S36>/AH'
     */
    if ((rtb_Integrator1 <= Fuzzy_manobra_aplicado_2015b_P.MF_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.MF_Value[i])) {
      rtb_impMethod_hp[i] = rtb_Integrator1;
    } else {
      rtb_impMethod_hp[i] = Fuzzy_manobra_aplicado_2015b_P.MF_Value[i];
    }

    if ((rtb_Integrator1 <= Fuzzy_manobra_aplicado_2015b_P.AH_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.AH_Value[i])) {
      rtb_impMethod_hp[i + 101] = rtb_Integrator1;
    } else {
      rtb_impMethod_hp[i + 101] = Fuzzy_manobra_aplicado_2015b_P.AH_Value[i];
    }

    /* End of MinMax: '<S22>/impMethod' */

    /* MinMax: '<S23>/impMethod' incorporates:
     *  Constant: '<S35>/MR'
     *  Constant: '<S36>/AH'
     */
    if ((rtb_Integrator2 <= Fuzzy_manobra_aplicado_2015b_P.MR_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.MR_Value[i])) {
      rtb_impMethod_e5[i] = rtb_Integrator2;
    } else {
      rtb_impMethod_e5[i] = Fuzzy_manobra_aplicado_2015b_P.MR_Value[i];
    }

    if ((rtb_Integrator2 <= Fuzzy_manobra_aplicado_2015b_P.AH_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.AH_Value[i])) {
      rtb_impMethod_e5[i + 101] = rtb_Integrator2;
    } else {
      rtb_impMethod_e5[i + 101] = Fuzzy_manobra_aplicado_2015b_P.AH_Value[i];
    }

    /* End of MinMax: '<S23>/impMethod' */

    /* MinMax: '<S24>/impMethod' incorporates:
     *  Constant: '<S35>/MR'
     *  Constant: '<S36>/H'
     */
    if ((rtb_Weighting_ga <= Fuzzy_manobra_aplicado_2015b_P.MR_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.MR_Value[i])) {
      rtb_impMethod_h[i] = rtb_Weighting_ga;
    } else {
      rtb_impMethod_h[i] = Fuzzy_manobra_aplicado_2015b_P.MR_Value[i];
    }

    if ((rtb_Weighting_ga <= Fuzzy_manobra_aplicado_2015b_P.H_Value[i]) ||
        rtIsNaN(Fuzzy_manobra_aplicado_2015b_P.H_Value[i])) {
      rtb_impMethod_h[i + 101] = rtb_Weighting_ga;
    } else {
      rtb_impMethod_h[i + 101] = Fuzzy_manobra_aplicado_2015b_P.H_Value[i];
    }

    /* End of MinMax: '<S24>/impMethod' */

    /* MinMax: '<S18>/AggMethod1' */
    if ((rtb_impMethod[i] >= rtb_impMethod_o[i]) || rtIsNaN(rtb_impMethod_o[i]))
    {
      u0 = rtb_impMethod[i];
    } else {
      u0 = rtb_impMethod_o[i];
    }

    if (!((u0 >= rtb_impMethod_hq[i]) || rtIsNaN(rtb_impMethod_hq[i]))) {
      u0 = rtb_impMethod_hq[i];
    }

    if (!((u0 >= rtb_impMethod_a[i]) || rtIsNaN(rtb_impMethod_a[i]))) {
      u0 = rtb_impMethod_a[i];
    }

    if (!((u0 >= rtb_impMethod_g[i]) || rtIsNaN(rtb_impMethod_g[i]))) {
      u0 = rtb_impMethod_g[i];
    }

    if (!((u0 >= rtb_impMethod_m[i]) || rtIsNaN(rtb_impMethod_m[i]))) {
      u0 = rtb_impMethod_m[i];
    }

    if (!((u0 >= rtb_impMethod_n[i]) || rtIsNaN(rtb_impMethod_n[i]))) {
      u0 = rtb_impMethod_n[i];
    }

    if (!((u0 >= rtb_impMethod_ks[i]) || rtIsNaN(rtb_impMethod_ks[i]))) {
      u0 = rtb_impMethod_ks[i];
    }

    if (!((u0 >= rtb_impMethod_i[i]) || rtIsNaN(rtb_impMethod_i[i]))) {
      u0 = rtb_impMethod_i[i];
    }

    if (!((u0 >= rtb_impMethod_hp[i]) || rtIsNaN(rtb_impMethod_hp[i]))) {
      u0 = rtb_impMethod_hp[i];
    }

    if (!((u0 >= rtb_impMethod_e5[i]) || rtIsNaN(rtb_impMethod_e5[i]))) {
      u0 = rtb_impMethod_e5[i];
    }

    if ((u0 >= rtb_impMethod_h[i]) || rtIsNaN(rtb_impMethod_h[i])) {
      rtb_AggMethod1[i] = u0;
    } else {
      rtb_AggMethod1[i] = rtb_impMethod_h[i];
    }

    /* End of MinMax: '<S18>/AggMethod1' */
  }

  /* Sum: '<S19>/Sum1' */
  rtb_Switch_n_idx_0 = rtb_AggMethod1[0];
  for (i = 0; i < 100; i++) {
    rtb_Switch_n_idx_0 += rtb_AggMethod1[i + 1];
  }

  rtb_Sum1 = rtb_Switch_n_idx_0;

  /* End of Sum: '<S19>/Sum1' */

  /* If: '<S19>/If' incorporates:
   *  Constant: '<S37>/One'
   */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    rtAction = (int8_T)!(rtb_Sum1 <= 0.0);
    Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_a = rtAction;
  } else {
    rtAction = Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_a;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S19>/Action: One' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge_j =
        Fuzzy_manobra_aplicado_2015b_P.One_Value;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S19>/Action: One' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S19>/Action: u1' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    Fuzzy_manobra_aplicado_Actionu1(rtb_Sum1,
      &Fuzzy_manobra_aplicado_2015b_B.Merge_j);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.Actionu1.Actionu1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S19>/Action: u1' */
    break;
  }

  /* End of If: '<S19>/If' */

  /* MinMax: '<S18>/AggMethod2' */
  for (i = 0; i < 101; i++) {
    if ((rtb_impMethod[i + 101] >= rtb_impMethod_o[i + 101]) || rtIsNaN
        (rtb_impMethod_o[i + 101])) {
      u0 = rtb_impMethod[i + 101];
    } else {
      u0 = rtb_impMethod_o[i + 101];
    }

    if (!((u0 >= rtb_impMethod_hq[i + 101]) || rtIsNaN(rtb_impMethod_hq[i + 101])))
    {
      u0 = rtb_impMethod_hq[i + 101];
    }

    if (!((u0 >= rtb_impMethod_a[i + 101]) || rtIsNaN(rtb_impMethod_a[i + 101])))
    {
      u0 = rtb_impMethod_a[i + 101];
    }

    if (!((u0 >= rtb_impMethod_g[i + 101]) || rtIsNaN(rtb_impMethod_g[i + 101])))
    {
      u0 = rtb_impMethod_g[i + 101];
    }

    if (!((u0 >= rtb_impMethod_m[i + 101]) || rtIsNaN(rtb_impMethod_m[i + 101])))
    {
      u0 = rtb_impMethod_m[i + 101];
    }

    if (!((u0 >= rtb_impMethod_n[i + 101]) || rtIsNaN(rtb_impMethod_n[i + 101])))
    {
      u0 = rtb_impMethod_n[i + 101];
    }

    if (!((u0 >= rtb_impMethod_ks[i + 101]) || rtIsNaN(rtb_impMethod_ks[i + 101])))
    {
      u0 = rtb_impMethod_ks[i + 101];
    }

    if (!((u0 >= rtb_impMethod_i[i + 101]) || rtIsNaN(rtb_impMethod_i[i + 101])))
    {
      u0 = rtb_impMethod_i[i + 101];
    }

    if (!((u0 >= rtb_impMethod_hp[i + 101]) || rtIsNaN(rtb_impMethod_hp[i + 101])))
    {
      u0 = rtb_impMethod_hp[i + 101];
    }

    if (!((u0 >= rtb_impMethod_e5[i + 101]) || rtIsNaN(rtb_impMethod_e5[i + 101])))
    {
      u0 = rtb_impMethod_e5[i + 101];
    }

    if ((u0 >= rtb_impMethod_h[i + 101]) || rtIsNaN(rtb_impMethod_h[i + 101])) {
      rtb_AggMethod2[i] = u0;
    } else {
      rtb_AggMethod2[i] = rtb_impMethod_h[i + 101];
    }
  }

  /* End of MinMax: '<S18>/AggMethod2' */

  /* Sum: '<S20>/Sum1' */
  rtb_Switch_n_idx_0 = rtb_AggMethod2[0];
  for (i = 0; i < 100; i++) {
    rtb_Switch_n_idx_0 += rtb_AggMethod2[i + 1];
  }

  rtb_Sum1_k = rtb_Switch_n_idx_0;

  /* End of Sum: '<S20>/Sum1' */

  /* If: '<S20>/If' incorporates:
   *  Constant: '<S39>/One'
   */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    rtAction = (int8_T)!(rtb_Sum1_k <= 0.0);
    Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_f = rtAction;
  } else {
    rtAction = Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_f;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S20>/Action: One' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      Fuzzy_manobra_aplicado_2015b_B.Merge_jt =
        Fuzzy_manobra_aplicado_2015b_P.One_Value_m;
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC_h);
    }

    /* End of Outputs for SubSystem: '<S20>/Action: One' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S20>/Action: u1' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    Fuzzy_manobra_aplicado_Actionu1(rtb_Sum1_k,
      &Fuzzy_manobra_aplicado_2015b_B.Merge_jt);
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      srUpdateBC(Fuzzy_manobra_aplicado_2015b_DW.Actionu1_l.Actionu1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S20>/Action: u1' */
    break;
  }

  /* End of If: '<S20>/If' */

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/MidRange'
   *  Constant: '<S18>/Zero'
   *  Product: '<S20>/Averaging (COA)'
   *  RelationalOperator: '<S18>/Zero Firing Strength?'
   *  Sum: '<S18>/Total Firing Strength'
   */
  if ((((((((((((rtb_Weighting + rtb_Weighting_n) + rtb_Sum_g) +
               rtb_Weighting_mf) + rtb_Weighting_g) + rtb_Weighting_d) +
            rtb_Weighting_f) + rtb_Weighting_j) + rtb_Integrator1_o) +
         rtb_Integrator1) + rtb_Integrator2) + rtb_Weighting_ga >
       Fuzzy_manobra_aplicado_2015b_P.Zero_Value) >=
      Fuzzy_manobra_aplicado_2015b_P.Switch_Threshold) {
    /* Product: '<S19>/Product (COA)' incorporates:
     *  Constant: '<S19>/x data'
     */
    for (i = 0; i < 101; i++) {
      rtb_AggMethod1[i] *= Fuzzy_manobra_aplicado_2015b_P.xdata_Value[i];
    }

    /* End of Product: '<S19>/Product (COA)' */

    /* Sum: '<S19>/Sum' */
    rtb_Weighting_n = rtb_AggMethod1[0];
    for (i = 0; i < 100; i++) {
      rtb_Weighting_n += rtb_AggMethod1[i + 1];
    }

    /* End of Sum: '<S19>/Sum' */

    /* Product: '<S19>/Averaging (COA)' */
    rtb_Weighting = rtb_Weighting_n / Fuzzy_manobra_aplicado_2015b_B.Merge_j;

    /* Product: '<S20>/Product (COA)' incorporates:
     *  Constant: '<S20>/x data'
     */
    for (i = 0; i < 101; i++) {
      rtb_AggMethod2[i] *= Fuzzy_manobra_aplicado_2015b_P.xdata_Value_k[i];
    }

    /* End of Product: '<S20>/Product (COA)' */

    /* Sum: '<S20>/Sum' */
    rtb_Weighting_n = rtb_AggMethod2[0];
    for (i = 0; i < 100; i++) {
      rtb_Weighting_n += rtb_AggMethod2[i + 1];
    }

    /* End of Sum: '<S20>/Sum' */
    rtb_Switch_n_idx_0 = rtb_Weighting;
    rtb_Weighting = rtb_Weighting_n / Fuzzy_manobra_aplicado_2015b_B.Merge_jt;
  } else {
    rtb_Switch_n_idx_0 = Fuzzy_manobra_aplicado_2015b_P.MidRange_Value[0];
    rtb_Weighting = Fuzzy_manobra_aplicado_2015b_P.MidRange_Value[1];
  }

  /* End of Switch: '<S18>/Switch' */

  /* Gain: '<S7>/Gain2' */
  rtb_Integrator2 = Fuzzy_manobra_aplicado_2015b_P.L * rtb_Weighting;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Constant: '<S70>/Constant'
     *  RelationalOperator: '<S70>/Compare'
     */
    Fuzzy_manobra_aplicado_2015b_B.DataTypeConversion =
      (Fuzzy_manobra_aplicado_2015b_B.UnitDelay <=
       Fuzzy_manobra_aplicado_2015b_P.N_sp);
  }

  /* Product: '<Root>/Product' incorporates:
   *  Sum: '<S7>/Add1'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product_c = (rtb_Switch_n_idx_0 +
    rtb_Integrator2) * Fuzzy_manobra_aplicado_2015b_B.DataTypeConversion;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S11>/wn'
   *  Integrator: '<S11>/Integrator2'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product1 =
    Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_input *
    Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE;

  /* Gain: '<Root>/wheel radious (m)' */
  Fuzzy_manobra_aplicado_2015b_B.wheelradiousm =
    Fuzzy_manobra_aplicado_2015b_P.R * Fuzzy_manobra_aplicado_2015b_B.Product1;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Integrator: '<Root>/Integrator4' */
  Fuzzy_manobra_aplicado_2015b_B.Integrator4 =
    Fuzzy_manobra_aplicado_2015b_X.ePI_d;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Integrator: '<Root>/Integrator5' */
  Fuzzy_manobra_aplicado_2015b_B.Integrator5 =
    Fuzzy_manobra_aplicado_2015b_X.ePI_e;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Sum: '<Root>/Erro vR' */
  Fuzzy_manobra_aplicado_2015b_B.ErrovR =
    Fuzzy_manobra_aplicado_2015b_B.Product_c -
    Fuzzy_manobra_aplicado_2015b_B.wheelradiousm;

  /* Sum: '<Root>/pi' incorporates:
   *  Gain: '<Root>/Ki '
   *  Gain: '<Root>/Kp'
   */
  u0 = Fuzzy_manobra_aplicado_2015b_P.k_p *
    Fuzzy_manobra_aplicado_2015b_B.ErrovR + Fuzzy_manobra_aplicado_2015b_P.k_i *
    Fuzzy_manobra_aplicado_2015b_B.Integrator4;

  /* Saturate: '<Root>/sat2' */
  if (u0 > Fuzzy_manobra_aplicado_2015b_P.sat2_UpperSat) {
    Fuzzy_manobra_aplicado_2015b_B.sat2 =
      Fuzzy_manobra_aplicado_2015b_P.sat2_UpperSat;
  } else if (u0 < Fuzzy_manobra_aplicado_2015b_P.sat2_LowerSat) {
    Fuzzy_manobra_aplicado_2015b_B.sat2 =
      Fuzzy_manobra_aplicado_2015b_P.sat2_LowerSat;
  } else {
    Fuzzy_manobra_aplicado_2015b_B.sat2 = u0;
  }

  /* End of Saturate: '<Root>/sat2' */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
  }

  /* Product: '<Root>/Product1' incorporates:
   *  Sum: '<S7>/Add2'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product1_f = (rtb_Switch_n_idx_0 -
    rtb_Integrator2) * Fuzzy_manobra_aplicado_2015b_B.DataTypeConversion;

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S13>/wn'
   *  Integrator: '<S13>/Integrator2'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product1_k =
    Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_b *
    Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE_h;

  /* Gain: '<Root>/wheel radious (mm)1' */
  Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1 =
    Fuzzy_manobra_aplicado_2015b_P.R * Fuzzy_manobra_aplicado_2015b_B.Product1_k;

  /* Sum: '<Root>/Erro vL' */
  Fuzzy_manobra_aplicado_2015b_B.ErrovL =
    Fuzzy_manobra_aplicado_2015b_B.Product1_f -
    Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1;

  /* Sum: '<Root>/pi1' incorporates:
   *  Gain: '<Root>/Ki'
   *  Gain: '<Root>/Kp1'
   */
  u0 = Fuzzy_manobra_aplicado_2015b_P.k_p *
    Fuzzy_manobra_aplicado_2015b_B.ErrovL + Fuzzy_manobra_aplicado_2015b_P.k_i *
    Fuzzy_manobra_aplicado_2015b_B.Integrator5;

  /* Saturate: '<Root>/sat1' */
  if (u0 > Fuzzy_manobra_aplicado_2015b_P.sat1_UpperSat) {
    Fuzzy_manobra_aplicado_2015b_B.sat1 =
      Fuzzy_manobra_aplicado_2015b_P.sat1_UpperSat;
  } else if (u0 < Fuzzy_manobra_aplicado_2015b_P.sat1_LowerSat) {
    Fuzzy_manobra_aplicado_2015b_B.sat1 =
      Fuzzy_manobra_aplicado_2015b_P.sat1_LowerSat;
  } else {
    Fuzzy_manobra_aplicado_2015b_B.sat1 = u0;
  }

  /* End of Saturate: '<Root>/sat1' */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* Gain: '<S10>/ encoder rotation to wheel rotation (gear ratio)' incorporates:
     *  Gain: '<S10>/ticks to encoder rotation'
     */
    Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotationg =
      Fuzzy_manobra_aplicado_2015b_P.tickstoencoderrotation_Gain *
      rtb_HILRead1_o2[0] *
      Fuzzy_manobra_aplicado_2015b_P.encoderrotationtowheelrotationg;

    /* Constant: '<S11>/x0' */
    Fuzzy_manobra_aplicado_2015b_B.x0 = Fuzzy_manobra_aplicado_2015b_P.x0_Value;
  }

  /* Integrator: '<S11>/Integrator1' */
  if (Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK != 0) {
    Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE =
      Fuzzy_manobra_aplicado_2015b_B.x0;
  }

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/wn'
   *  Constant: '<S11>/zt'
   *  Integrator: '<S11>/Integrator1'
   *  Integrator: '<S11>/Integrator2'
   *  Product: '<S11>/Product2'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product_a =
    ((Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotationg -
      Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE) -
     Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE *
     Fuzzy_manobra_aplicado_2015b_P.Constant_Value_n *
     Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_p) *
    Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_input;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* Gain: '<S12>/ encoder rotation to wheel rotation (gear ratio)' incorporates:
     *  Gain: '<S12>/ticks to encoder rotation'
     */
    Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotatio_f =
      Fuzzy_manobra_aplicado_2015b_P.tickstoencoderrotation_Gain_a *
      rtb_HILRead1_o2[1] *
      Fuzzy_manobra_aplicado_2015b_P.encoderrotationtowheelrotatio_i;

    /* Constant: '<S13>/x0' */
    Fuzzy_manobra_aplicado_2015b_B.x0_b =
      Fuzzy_manobra_aplicado_2015b_P.x0_Value_p;
  }

  /* Integrator: '<S13>/Integrator1' */
  if (Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK_j != 0) {
    Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE_n =
      Fuzzy_manobra_aplicado_2015b_B.x0_b;
  }

  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/wn'
   *  Constant: '<S13>/zt'
   *  Integrator: '<S13>/Integrator1'
   *  Integrator: '<S13>/Integrator2'
   *  Product: '<S13>/Product2'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum1'
   */
  Fuzzy_manobra_aplicado_2015b_B.Product_k =
    ((Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotatio_f -
      Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE_n) -
     Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE_h *
     Fuzzy_manobra_aplicado_2015b_P.Constant_Value_p *
     Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_f) *
    Fuzzy_manobra_aplicado_2015b_P.SecondOrderLowPassFilter2_inp_b;

  /* MATLAB Function: '<S14>/Qbot2_Diff_Drive_Kinematics' */
  /* MATLAB Function 'Forward Kinematics (No Gyro)/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics': '<S16>:1' */
  /* '<S16>:1:6' */
  rtb_Weighting_n = (Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1 +
                     Fuzzy_manobra_aplicado_2015b_B.wheelradiousm) * 0.5;

  /* '<S16>:1:7' */
  Fuzzy_manobra_aplicado_2015b_B.Omega =
    (Fuzzy_manobra_aplicado_2015b_B.wheelradiousm -
     Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1) * 4.25531914893617;

  /* MATLAB Function: '<S15>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' incorporates:
   *  Integrator: '<S15>/Integrator'
   */
  /* MATLAB Function 'Forward Kinematics (No Gyro)/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)': '<S17>:1' */
  /* '<S17>:1:5' */
  Fuzzy_manobra_aplicado_2015b_B.x_dot = cos
    (Fuzzy_manobra_aplicado_2015b_X.Integrator_CSTATE) * rtb_Weighting_n;

  /* '<S17>:1:6' */
  Fuzzy_manobra_aplicado_2015b_B.y_dot = sin
    (Fuzzy_manobra_aplicado_2015b_X.Integrator_CSTATE) * rtb_Weighting_n;

  /* '<S17>:1:7' */
  Fuzzy_manobra_aplicado_2015b_B.psi_dot = Fuzzy_manobra_aplicado_2015b_B.Omega;
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* S-Function (hil_write_block): '<S63>/HIL Write' */

    /* S-Function Block: Fuzzy_manobra_aplicado_2015b/QBot_Basic/QBot2_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer[0] =
        Fuzzy_manobra_aplicado_2015b_B.sat2;
      Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer[1] =
        Fuzzy_manobra_aplicado_2015b_B.sat1;
      result = hil_write(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         Fuzzy_manobra_aplicado_2015b_P.HILWrite_other_channels,
                         2U,
                         NULL,
                         NULL,
                         NULL,
                         &Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
      }
    }

    /* Sum: '<S71>/FixPt Sum1' incorporates:
     *  Constant: '<S71>/FixPt Constant'
     */
    Fuzzy_manobra_aplicado_2015b_B.FixPtSum1 =
      Fuzzy_manobra_aplicado_2015b_B.UnitDelay +
      Fuzzy_manobra_aplicado_2015b_P.FixPtConstant_Value;
  }

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S69>/Compare'
   */
  if (rtb_Sqrt <= Fuzzy_manobra_aplicado_2015b_P.CompareToConstant_const) {
    Fuzzy_manobra_aplicado_2015b_B.Switch =
      Fuzzy_manobra_aplicado_2015b_B.FixPtSum1;
  } else {
    Fuzzy_manobra_aplicado_2015b_B.Switch =
      Fuzzy_manobra_aplicado_2015b_B.UnitDelay;
  }

  /* End of Switch: '<S9>/Switch' */
  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
      /* Update for UnitDelay: '<S9>/Unit Delay' */
      Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE =
        Fuzzy_manobra_aplicado_2015b_B.Switch;
    }

    /* Update for Integrator: '<S11>/Integrator1' */
    Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK = 0;

    /* Update for Integrator: '<S13>/Integrator1' */
    Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK_j = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, Fuzzy_manobra_aplicado_2015b_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, (((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1+
                            Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1*
                            4294967296.0)) * 0.01));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Fuzzy_manobra_aplicado_2015b_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Fuzzy_manobra_aplicado_2015b_M)!=-1) &&
          !((rtmGetTFinal(Fuzzy_manobra_aplicado_2015b_M)-
             (((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1+
                Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1* 4294967296.0))
              * 0.01)) > (((Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1+
                            Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1*
                            4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Fuzzy_manobra_aplicado_2015b_M)) {
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Fuzzy_manobra_aplicado_2015b_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick0)) {
      ++Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH0;
    }

    Fuzzy_manobra_aplicado_2015b_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Fuzzy_manobra_aplicado_2015b_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1++;
      if (!Fuzzy_manobra_aplicado_2015b_M->Timing.clockTick1) {
        Fuzzy_manobra_aplicado_2015b_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Fuzzy_manobra_aplicado_2015b_derivatives(void)
{
  XDot_Fuzzy_manobra_aplicado_2_T *_rtXdot;
  _rtXdot = ((XDot_Fuzzy_manobra_aplicado_2_T *)
             Fuzzy_manobra_aplicado_2015b_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->theta = Fuzzy_manobra_aplicado_2015b_B.psi_dot;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->x_a = Fuzzy_manobra_aplicado_2015b_B.x_dot;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->y_a = Fuzzy_manobra_aplicado_2015b_B.y_dot;

  /* Derivatives for Integrator: '<S11>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Fuzzy_manobra_aplicado_2015b_B.Product_a;

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->ePI_d = Fuzzy_manobra_aplicado_2015b_B.ErrovR;

  /* Derivatives for Integrator: '<Root>/Integrator5' */
  _rtXdot->ePI_e = Fuzzy_manobra_aplicado_2015b_B.ErrovL;

  /* Derivatives for Integrator: '<S13>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_h = Fuzzy_manobra_aplicado_2015b_B.Product_k;

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Fuzzy_manobra_aplicado_2015b_B.Product1;

  /* Derivatives for Integrator: '<S13>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_n = Fuzzy_manobra_aplicado_2015b_B.Product1_k;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE = Fuzzy_manobra_aplicado_2015b_B.Omega;
}

/* Model initialize function */
void Fuzzy_manobra_aplicado_2015b_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Fuzzy_manobra_aplicado_2015b_M, 0,
                sizeof(RT_MODEL_Fuzzy_manobra_aplica_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                          &Fuzzy_manobra_aplicado_2015b_M->Timing.simTimeStep);
    rtsiSetTPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo, &rtmGetTPtr
                (Fuzzy_manobra_aplicado_2015b_M));
    rtsiSetStepSizePtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                       &Fuzzy_manobra_aplicado_2015b_M->Timing.stepSize0);
    rtsiSetdXPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                 &Fuzzy_manobra_aplicado_2015b_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo, (real_T **)
                         &Fuzzy_manobra_aplicado_2015b_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
      &Fuzzy_manobra_aplicado_2015b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
      &Fuzzy_manobra_aplicado_2015b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
       &Fuzzy_manobra_aplicado_2015b_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
       &Fuzzy_manobra_aplicado_2015b_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                          (&rtmGetErrorStatus(Fuzzy_manobra_aplicado_2015b_M)));
    rtsiSetRTModelPtr(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                      Fuzzy_manobra_aplicado_2015b_M);
  }

  rtsiSetSimTimeStep(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,
                     MAJOR_TIME_STEP);
  Fuzzy_manobra_aplicado_2015b_M->ModelData.intgData.f[0] =
    Fuzzy_manobra_aplicado_2015b_M->ModelData.odeF[0];
  Fuzzy_manobra_aplicado_2015b_M->ModelData.contStates =
    ((X_Fuzzy_manobra_aplicado_2015_T *) &Fuzzy_manobra_aplicado_2015b_X);
  rtsiSetSolverData(&Fuzzy_manobra_aplicado_2015b_M->solverInfo, (void *)
                    &Fuzzy_manobra_aplicado_2015b_M->ModelData.intgData);
  rtsiSetSolverName(&Fuzzy_manobra_aplicado_2015b_M->solverInfo,"ode1");
  rtmSetTPtr(Fuzzy_manobra_aplicado_2015b_M,
             &Fuzzy_manobra_aplicado_2015b_M->Timing.tArray[0]);
  rtmSetTFinal(Fuzzy_manobra_aplicado_2015b_M, 150.0);
  Fuzzy_manobra_aplicado_2015b_M->Timing.stepSize0 = 0.01;
  rtmSetFirstInitCond(Fuzzy_manobra_aplicado_2015b_M, 1);

  /* External mode info */
  Fuzzy_manobra_aplicado_2015b_M->Sizes.checksums[0] = (1222950069U);
  Fuzzy_manobra_aplicado_2015b_M->Sizes.checksums[1] = (3518685006U);
  Fuzzy_manobra_aplicado_2015b_M->Sizes.checksums[2] = (795471527U);
  Fuzzy_manobra_aplicado_2015b_M->Sizes.checksums[3] = (1186167036U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    Fuzzy_manobra_aplicado_2015b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.Actionu1.Actionu1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.ActionOne_SubsysRanBC_h;
    systemRan[7] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.Actionu1_l.Actionu1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[9] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanB_o;
    systemRan[11] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3_m.IfActionSubsystem3_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3.IfActionSubsystem3_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[17] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[18] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[19] = (sysRanDType *)
      &Fuzzy_manobra_aplicado_2015b_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Fuzzy_manobra_aplicado_2015b_M->extModeInfo,
      &Fuzzy_manobra_aplicado_2015b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Fuzzy_manobra_aplicado_2015b_M->extModeInfo,
                        Fuzzy_manobra_aplicado_2015b_M->Sizes.checksums);
    rteiSetTPtr(Fuzzy_manobra_aplicado_2015b_M->extModeInfo, rtmGetTPtr
                (Fuzzy_manobra_aplicado_2015b_M));
  }

  /* block I/O */
  {
    Fuzzy_manobra_aplicado_2015b_B.Integrator3 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Integrator1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Integrator2 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.UnitDelay = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Merge = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.TrigonometricFunction1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Merge_k = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Merge_j = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Merge_jt = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.DataTypeConversion = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product_c = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.wheelradiousm = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Integrator4 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Integrator5 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.ErrovR = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.sat2 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product1_f = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product1_k = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.wheelradiousmm1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.ErrovL = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.sat1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotationg = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.x0 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product_a = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.encoderrotationtowheelrotatio_f = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.x0_b = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Product_k = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.FixPtSum1 = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Switch = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.x_sp = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.y_sp = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.VVavg = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Vin = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Constant = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.div = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.x_dot = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.y_dot = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.psi_dot = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.Omega = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3.dc = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1.ba = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3_m.dc = 0.0;
    Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1_i.ba = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&Fuzzy_manobra_aplicado_2015b_X, 0,
                  sizeof(X_Fuzzy_manobra_aplicado_2015_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Fuzzy_manobra_aplicado_2015b_DW, 0,
                sizeof(DW_Fuzzy_manobra_aplicado_201_T));
  Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[0] = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[1] = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[2] = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[3] = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer[0] = 0.0;
  Fuzzy_manobra_aplicado_2015b_DW.HILWrite_OtherBuffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Fuzzy_manobra_aplicado_2015b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Fuzzy_manobra_aplicado_2015b/HIL Initialize (hil_initialize_block) */
  {
    static const t_uint encoder_input_channels[4U] = {
      0
      , 1
      , 2
      , 3
    };

    static const t_encoder_quadrature_mode encoder_quadrature[4U] = {
      ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
    };

    static const t_int32 initial_encoder_counts[4U] = {
      0
      , 0
      , 0
      , 0
    };

    static const t_uint pwm_output_channels[4U] = {
      0
      , 1
      , 2
      , 3
    };

    static const t_pwm_mode pwm_output_modes[4U] = {
      PWM_DUTY_CYCLE_MODE
      , PWM_DUTY_CYCLE_MODE
      , PWM_DUTY_CYCLE_MODE
      , PWM_DUTY_CYCLE_MODE
    };

    static const t_double pwm_output_frequencies[4] = {
      19531.25
      , 19531.25
      , 19531.25
      , 19531.25
    };

    static const t_pwm_configuration pwm_output_configurations[4U] = {
      PWM_UNIPOLAR_CONFIGURATION
      , PWM_UNIPOLAR_CONFIGURATION
      , PWM_UNIPOLAR_CONFIGURATION
      , PWM_UNIPOLAR_CONFIGURATION
    };

    static const t_pwm_alignment pwm_output_alignments[4U] = {
      PWM_LEADING_EDGE_ALIGNED
      , PWM_LEADING_EDGE_ALIGNED
      , PWM_LEADING_EDGE_ALIGNED
      , PWM_LEADING_EDGE_ALIGNED
    };

    static const t_pwm_polarity pwm_output_polarities[4U] = {
      PWM_ACTIVE_HIGH_POLARITY
      , PWM_ACTIVE_HIGH_POLARITY
      , PWM_ACTIVE_HIGH_POLARITY
      , PWM_ACTIVE_HIGH_POLARITY
    };

    static const t_double pwm_output_leading_deadbands[4U] = {
      0.0
      , 0.0
      , 0.0
      , 0.0
    };

    static const t_double pwm_output_trailing_deadbands[4U] = {
      0.0
      , 0.0
      , 0.0
      , 0.0
    };

    static const t_double initial_pwm_outputs[4U] = {
      0.0
      , 0.0
      , 0.0
      , 0.0
    };

    static const t_double watchdog_pwm_outputs[4U] = {
      0.0
      , 0.0
      , 0.0
      , 0.0
    };

    static const t_uint other_output_channels[2U] = {
      2000
      , 2001
    };

    static const t_double initial_other_outputs[2U] = {
      0.0
      , 0.0
    };

    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2", "0",
                      &Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
       "enc0_dir=0;enc0_filter=1;enc0_a=0;enc0_b=0;enc0_z=1;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=0;enc1_b=0;enc1_z=1;enc1_reload=0;pwm0_immediate=0;pwm1_immediate=0;pwm2_immediate=0;pwm3_immediate=0;",
       201);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
         encoder_input_channels, 4U, (t_encoder_quadrature_mode *)
         encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
         encoder_input_channels, 4U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_pwm_mode
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card, pwm_output_channels,
         4U, (t_pwm_mode *) pwm_output_modes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }

      result = hil_set_pwm_frequency
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card, pwm_output_channels,
         4, pwm_output_frequencies);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }

      result = hil_set_pwm_configuration
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card, pwm_output_channels,
         4U,
         (t_pwm_configuration *) pwm_output_configurations,
         (t_pwm_alignment *) pwm_output_alignments,
         (t_pwm_polarity *) pwm_output_polarities);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }

      result = hil_set_pwm_deadband
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card, pwm_output_channels,
         4U,
         pwm_output_leading_deadbands, pwm_output_trailing_deadbands);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_pwm(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
        pwm_output_channels, 4U, initial_pwm_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }

    {
      result = hil_watchdog_set_pwm_expiration_state
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card, pwm_output_channels,
         4U, watchdog_pwm_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_other
        (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
         other_output_channels, 2U, initial_other_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for If: '<S42>/If' */
  Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S42>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S49>/Out1' */
  Fuzzy_manobra_aplicado_2015b_B.Merge =
    Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_i;

  /* End of Start for SubSystem: '<S42>/If Action Subsystem2' */

  /* Start for Atomic SubSystem: '<S5>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S62>/Enabled Moving Average' */
  Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S62>/Enabled Moving Average' */

  /* InitializeConditions for Enabled SubSystem: '<S62>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
  Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE_p =
    Fuzzy_manobra_aplicado_2015b_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S64>/Sum( k=1,n-1, x(k) )' */
  Fuzzy_manobra_aplicado_2015b_DW.Sumk1n1xk_DSTATE =
    Fuzzy_manobra_aplicado_2015b_P.Sumk1n1xk_InitialCondition;

  /* End of InitializeConditions for SubSystem: '<S62>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S62>/Switch Case' */
  Fuzzy_manobra_aplicado_2015b_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S62>/Switch Case Action Subsystem' */
  /* VirtualOutportStart for Outport: '<S65>/zero' */
  Fuzzy_manobra_aplicado_2015b_B.Constant =
    Fuzzy_manobra_aplicado_2015b_P.zero_Y0;

  /* End of Start for SubSystem: '<S62>/Switch Case Action Subsystem' */

  /* Start for IfAction SubSystem: '<S62>/Switch Case Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S66>/Vbiased' */
  Fuzzy_manobra_aplicado_2015b_B.Vin = Fuzzy_manobra_aplicado_2015b_P.Vbiased_Y0;

  /* End of Start for SubSystem: '<S62>/Switch Case Action Subsystem1' */

  /* Start for IfAction SubSystem: '<S62>/Switch Case Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S67>/Vunbiased' */
  Fuzzy_manobra_aplicado_2015b_B.VVavg =
    Fuzzy_manobra_aplicado_2015b_P.Vunbiased_Y0;

  /* End of Start for SubSystem: '<S62>/Switch Case Action Subsystem2' */
  /* End of Start for SubSystem: '<S5>/Bias Removal' */

  /* Start for If: '<S41>/If' */
  Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_l = -1;

  /* Start for IfAction SubSystem: '<S41>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S45>/Out1' */
  Fuzzy_manobra_aplicado_2015b_B.Merge_k =
    Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_l;

  /* End of Start for SubSystem: '<S41>/If Action Subsystem2' */

  /* Start for If: '<S19>/If' */
  Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S19>/Action: One' */
  /* VirtualOutportStart for Outport: '<S37>/Out1' */
  Fuzzy_manobra_aplicado_2015b_B.Merge_j =
    Fuzzy_manobra_aplicado_2015b_P.Out1_Y0;

  /* End of Start for SubSystem: '<S19>/Action: One' */

  /* Start for If: '<S20>/If' */
  Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S20>/Action: One' */
  /* VirtualOutportStart for Outport: '<S39>/Out1' */
  Fuzzy_manobra_aplicado_2015b_B.Merge_jt =
    Fuzzy_manobra_aplicado_2015b_P.Out1_Y0_j;

  /* End of Start for SubSystem: '<S20>/Action: One' */
  /* Start for Constant: '<S11>/x0' */
  Fuzzy_manobra_aplicado_2015b_B.x0 = Fuzzy_manobra_aplicado_2015b_P.x0_Value;

  /* Start for Constant: '<S13>/x0' */
  Fuzzy_manobra_aplicado_2015b_B.x0_b =
    Fuzzy_manobra_aplicado_2015b_P.x0_Value_p;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  Fuzzy_manobra_aplicado_2015b_X.theta =
    Fuzzy_manobra_aplicado_2015b_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Fuzzy_manobra_aplicado_2015b_X.x_a =
    Fuzzy_manobra_aplicado_2015b_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  Fuzzy_manobra_aplicado_2015b_X.y_a =
    Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE =
    Fuzzy_manobra_aplicado_2015b_P.UnitDelay_InitialCondition_d;

  /* InitializeConditions for Integrator: '<S11>/Integrator2' */
  Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE =
    Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC_l;

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  Fuzzy_manobra_aplicado_2015b_X.ePI_d =
    Fuzzy_manobra_aplicado_2015b_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator5' */
  Fuzzy_manobra_aplicado_2015b_X.ePI_e =
    Fuzzy_manobra_aplicado_2015b_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S13>/Integrator2' */
  Fuzzy_manobra_aplicado_2015b_X.Integrator2_CSTATE_h =
    Fuzzy_manobra_aplicado_2015b_P.Integrator2_IC_b;

  /* InitializeConditions for Integrator: '<S11>/Integrator1' incorporates:
   *  InitializeConditions for Integrator: '<S13>/Integrator1'
   */
  if (rtmIsFirstInitCond(Fuzzy_manobra_aplicado_2015b_M)) {
    Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE = 0.0;
    Fuzzy_manobra_aplicado_2015b_X.Integrator1_CSTATE_n = 0.0;
  }

  Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S11>/Integrator1' */

  /* InitializeConditions for Integrator: '<S13>/Integrator1' */
  Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK_j = 1;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  Fuzzy_manobra_aplicado_2015b_X.Integrator_CSTATE =
    Fuzzy_manobra_aplicado_2015b_P.Integrator_IC;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Fuzzy_manobra_aplicado_2015b_M)) {
    rtmSetFirstInitCond(Fuzzy_manobra_aplicado_2015b_M, 0);
  }
}

/* Model terminate function */
void Fuzzy_manobra_aplicado_2015b_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Fuzzy_manobra_aplicado_2015b/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_pwm_outputs = 0;
    static const t_uint pwm_output_channels[4U] = {
      0
      , 1
      , 2
      , 3
    };

    t_uint32 num_final_other_outputs = 0;
    static const t_uint other_output_channels[2U] = {
      2000
      , 2001
    };

    hil_task_stop_all(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    hil_monitor_stop_all(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    is_switching = false;
    if ((Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_pwm_output_ah &&
         !is_switching) ||
        (Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_pwm_outputs_a &&
         is_switching)) {
      Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[0] =
        Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_pwm_outputs;
      Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[1] =
        Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_pwm_outputs;
      Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[2] =
        Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_pwm_outputs;
      Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[3] =
        Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_pwm_outputs;
      num_final_pwm_outputs = 4U;
    }

    if ((Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_other_outpu_m &&
         !is_switching) ||
        (Fuzzy_manobra_aplicado_2015b_P.HILInitialize_set_other_outputs &&
         is_switching)) {
      num_final_other_outputs = 2U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card
                         , NULL, 0
                         , pwm_output_channels, num_final_pwm_outputs
                         , NULL, 0
                         , other_output_channels, num_final_other_outputs
                         , NULL
                         ,
                         &Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[
                         0]
                         , (t_boolean *) NULL
                         ,
                         Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
             pwm_output_channels, num_final_pwm_outputs,
             &Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card,
             other_output_channels, num_final_other_outputs,
             Fuzzy_manobra_aplicado_2015b_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Fuzzy_manobra_aplicado_2015b_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    hil_monitor_delete_all(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    hil_close(Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card);
    Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card = NULL;
  }
}
