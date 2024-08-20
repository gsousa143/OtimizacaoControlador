/*
 * setpoints_model.c
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

#include "setpoints_model.h"
#include "setpoints_model_private.h"
#include "setpoints_model_dt.h"

/* Block signals (auto storage) */
B_setpoints_model_T setpoints_model_B;

/* Block states (auto storage) */
DW_setpoints_model_T setpoints_model_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_setpoints_model_T setpoints_model_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_setpoints_model_T setpoints_model_Y;

/* Real-time model */
RT_MODEL_setpoints_model_T setpoints_model_M_;
RT_MODEL_setpoints_model_T *const setpoints_model_M = &setpoints_model_M_;
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

/* Model output function */
void setpoints_model_output(void)
{
  real_T i_sp;
  int64m_T b_i_sp;
  boolean_T blarge;
  boolean_T alarge;
  boolean_T bsmall;
  boolean_T asmall;
  boolean_T rtb_Compare;
  int64m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  static int64m_T tmp_2 = { { 0U, 1048576U } };

  static int64m_T tmp_3 = { { 0U, 4293918720U } };

  static int64m_T tmp_4 = { { 0U, 2147483648U } };

  static int64m_T tmp_5 = { { MAX_uint32_T, 2147483647U } };

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  i_sp = setpoints_model_DW.UnitDelay_DSTATE;

  /* MATLAB Function 'MATLAB Function': '<S4>:1' */
  if (setpoints_model_DW.UnitDelay_DSTATE < 1.0) {
    /* '<S4>:1:3' */
    /* '<S4>:1:4' */
    i_sp = 1.0;
  }

  /* '<S4>:1:6' */
  i_sp = rt_roundd_snf(i_sp);
  if (i_sp < 9.2233720368547758E+18) {
    if (i_sp >= -9.2233720368547758E+18) {
      Double2MultiWord(i_sp, &tmp.chunks[0U], 2);
    } else {
      tmp = tmp_4;
    }
  } else {
    tmp = tmp_5;
  }

  b_i_sp = tmp;
  rtb_Compare = false;
  if (!((-9.2233720368547758E+18 <= setpoints_model_P.N_sp) &&
        (setpoints_model_P.N_sp < 9.2233720368547758E+18))) {
    if (setpoints_model_P.N_sp >= 0.0) {
      rtb_Compare = true;
    }
  } else {
    blarge = (setpoints_model_P.N_sp >= 4.503599627370496E+15);
    tmp_0 = tmp_2;
    alarge = sMultiWordGe(&b_i_sp.chunks[0U], &tmp_0.chunks[0U], 2);
    bsmall = (setpoints_model_P.N_sp <= -4.503599627370496E+15);
    tmp_0 = tmp_3;
    asmall = sMultiWordLe(&b_i_sp.chunks[0U], &tmp_0.chunks[0U], 2);
    if (((!alarge) && blarge) || (asmall && (!bsmall))) {
      rtb_Compare = true;
    } else if (blarge || asmall) {
      Double2MultiWord(rt_roundd_snf(setpoints_model_P.N_sp), &tmp_1.chunks[0U],
                       2);
      rtb_Compare = sMultiWordLe(&b_i_sp.chunks[0U], &tmp_1.chunks[0U], 2);
    } else {
      if ((!alarge) && (!bsmall)) {
        rtb_Compare = (sMultiWord2Double(&b_i_sp.chunks[0U], 2, 0) <=
                       setpoints_model_P.N_sp);
      }
    }
  }

  if (rtb_Compare) {
    /* Outport: '<Root>/x_sp' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* '<S4>:1:8' */
    setpoints_model_Y.x_sp = setpoints_model_P.setpoints[MultiWord2sLong
      (&b_i_sp.chunks[0U]) - 1];

    /* Outport: '<Root>/y_sp' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* '<S4>:1:9' */
    setpoints_model_Y.y_sp = setpoints_model_P.setpoints[MultiWord2sLong
      (&b_i_sp.chunks[0U]) + 14];
  } else {
    /* Outport: '<Root>/x_sp' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* '<S4>:1:11' */
    setpoints_model_Y.x_sp = setpoints_model_P.setpoints[14];

    /* Outport: '<Root>/y_sp' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* '<S4>:1:12' */
    setpoints_model_Y.y_sp = setpoints_model_P.setpoints[29];
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Stop: '<Root>/Stop Simulation' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (setpoints_model_DW.UnitDelay_DSTATE > setpoints_model_P.N_sp) {
    rtmSetStopRequested(setpoints_model_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S3>/FixPt Constant'
   *  Inport: '<Root>/distancia '
   *  RelationalOperator: '<S1>/Compare'
   *  Sum: '<S3>/FixPt Sum1'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (setpoints_model_U.distancia <= setpoints_model_P.CompareToConstant_const)
  {
    setpoints_model_B.Switch = setpoints_model_DW.UnitDelay_DSTATE +
      setpoints_model_P.FixPtConstant_Value;
  } else {
    setpoints_model_B.Switch = setpoints_model_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model update function */
void setpoints_model_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  setpoints_model_DW.UnitDelay_DSTATE = setpoints_model_B.Switch;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++setpoints_model_M->Timing.clockTick0)) {
    ++setpoints_model_M->Timing.clockTickH0;
  }

  setpoints_model_M->Timing.t[0] = setpoints_model_M->Timing.clockTick0 *
    setpoints_model_M->Timing.stepSize0 + setpoints_model_M->Timing.clockTickH0 *
    setpoints_model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void setpoints_model_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  setpoints_model_DW.UnitDelay_DSTATE =
    setpoints_model_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void setpoints_model_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  setpoints_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  setpoints_model_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  setpoints_model_initialize();
}

void MdlTerminate(void)
{
  setpoints_model_terminate();
}

/* Registration function */
RT_MODEL_setpoints_model_T *setpoints_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)setpoints_model_M, 0,
                sizeof(RT_MODEL_setpoints_model_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = setpoints_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    setpoints_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    setpoints_model_M->Timing.sampleTimes =
      (&setpoints_model_M->Timing.sampleTimesArray[0]);
    setpoints_model_M->Timing.offsetTimes =
      (&setpoints_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    setpoints_model_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    setpoints_model_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(setpoints_model_M, &setpoints_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = setpoints_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    setpoints_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(setpoints_model_M, -1);
  setpoints_model_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  setpoints_model_M->Sizes.checksums[0] = (4170397608U);
  setpoints_model_M->Sizes.checksums[1] = (159024942U);
  setpoints_model_M->Sizes.checksums[2] = (531929411U);
  setpoints_model_M->Sizes.checksums[3] = (3236631925U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    setpoints_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(setpoints_model_M->extModeInfo,
      &setpoints_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(setpoints_model_M->extModeInfo,
                        setpoints_model_M->Sizes.checksums);
    rteiSetTPtr(setpoints_model_M->extModeInfo, rtmGetTPtr(setpoints_model_M));
  }

  setpoints_model_M->solverInfoPtr = (&setpoints_model_M->solverInfo);
  setpoints_model_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&setpoints_model_M->solverInfo, 0.001);
  rtsiSetSolverMode(&setpoints_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  setpoints_model_M->ModelData.blockIO = ((void *) &setpoints_model_B);
  (void) memset(((void *) &setpoints_model_B), 0,
                sizeof(B_setpoints_model_T));

  /* parameters */
  setpoints_model_M->ModelData.defaultParam = ((real_T *)&setpoints_model_P);

  /* states (dwork) */
  setpoints_model_M->ModelData.dwork = ((void *) &setpoints_model_DW);
  (void) memset((void *)&setpoints_model_DW, 0,
                sizeof(DW_setpoints_model_T));

  /* external inputs */
  setpoints_model_M->ModelData.inputs = (((void*)&setpoints_model_U));
  setpoints_model_U.distancia = 0.0;

  /* external outputs */
  setpoints_model_M->ModelData.outputs = (&setpoints_model_Y);
  (void) memset((void *)&setpoints_model_Y, 0,
                sizeof(ExtY_setpoints_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    setpoints_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  setpoints_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  setpoints_model_M->Sizes.numY = (2); /* Number of model outputs */
  setpoints_model_M->Sizes.numU = (1); /* Number of model inputs */
  setpoints_model_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  setpoints_model_M->Sizes.numSampTimes = (1);/* Number of sample times */
  setpoints_model_M->Sizes.numBlocks = (16);/* Number of blocks */
  setpoints_model_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  setpoints_model_M->Sizes.numBlockPrms = (34);/* Sum of parameter "widths" */
  return setpoints_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
