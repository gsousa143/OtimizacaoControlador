/*
 * Fuzzy_manobra_aplicado_2015b_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_B.Integrator3), 0, 0, 41 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3.dc), 0, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1.ba), 0, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem3_m.dc), 0, 0, 1
  },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_B.IfActionSubsystem1_i.ba), 0, 0, 1
  }
  ,

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.UnitDelay_DSTATE), 0, 0, 9 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.Thetarobo_PWORK.LoggedData), 11,
    0, 16 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.HILRead1_EncoderBuffer[0]), 6, 0,
    2 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.Integrator1_IWORK), 10, 0, 2 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.If_ActiveSubsystem), 2, 0, 15 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.EnabledMovingAverage_MODE), 8, 0,
    1 },

  { (char_T *)
    (&Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3.IfActionSubsystem3_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem3_m.IfActionSubsystem3_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Fuzzy_manobra_aplicado_2015b_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.Actionu1_l.Actionu1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_DW.Actionu1.Actionu1_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  18U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.L), 0, 0, 95 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.HILRead1_analog_channels), 7, 0,
    9 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.HILInitialize_active), 8, 0, 8 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.Out1_Y0), 0, 0, 1084 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.sw5_CurrentSetting), 3, 0, 1 },

  { (char_T *)(&Fuzzy_manobra_aplicado_2015b_P.HILRead1_Active), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Fuzzy_manobra_aplicado_2015b_dt.h */
