/*
 * Fuzzy_manobra_aplicado_2015b.h
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

#ifndef RTW_HEADER_Fuzzy_manobra_aplicado_2015b_h_
#define RTW_HEADER_Fuzzy_manobra_aplicado_2015b_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef Fuzzy_manobra_aplicado_2015b_COMMON_INCLUDES_
# define Fuzzy_manobra_aplicado_2015b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* Fuzzy_manobra_aplicado_2015b_COMMON_INCLUDES_ */

#include "Fuzzy_manobra_aplicado_2015b_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<S19>/Action: u1' */
typedef struct {
  int8_T Actionu1_SubsysRanBC;         /* '<S19>/Action: u1' */
} DW_Actionu1_Fuzzy_manobra_apl_T;

/* Block signals for system '<S41>/If Action Subsystem1' */
typedef struct {
  real_T ba;                           /* '<S44>/Sum1' */
} B_IfActionSubsystem1_Fuzzy_ma_T;

/* Block states (auto storage) for system '<S41>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S41>/If Action Subsystem1' */
} DW_IfActionSubsystem1_Fuzzy_m_T;

/* Block signals for system '<S41>/If Action Subsystem3' */
typedef struct {
  real_T dc;                           /* '<S46>/Sum2' */
} B_IfActionSubsystem3_Fuzzy_ma_T;

/* Block states (auto storage) for system '<S41>/If Action Subsystem3' */
typedef struct {
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S41>/If Action Subsystem3' */
} DW_IfActionSubsystem3_Fuzzy_m_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Integrator3;                  /* '<Root>/Integrator3' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T UnitDelay;                    /* '<S9>/Unit Delay' */
  real_T Merge;                        /* '<S42>/Merge' */
  real_T TrigonometricFunction1;       /* '<S8>/Trigonometric Function1' */
  real_T Product;                      /* '<S5>/Product' */
  real_T Merge_k;                      /* '<S41>/Merge' */
  real_T Merge_j;                      /* '<S19>/Merge' */
  real_T Merge_jt;                     /* '<S20>/Merge' */
  real_T DataTypeConversion;           /* '<S9>/Data Type Conversion' */
  real_T Product_c;                    /* '<Root>/Product' */
  real_T Product1;                     /* '<S11>/Product1' */
  real_T wheelradiousm;                /* '<Root>/wheel radious (m)' */
  real_T Integrator4;                  /* '<Root>/Integrator4' */
  real_T Integrator5;                  /* '<Root>/Integrator5' */
  real_T ErrovR;                       /* '<Root>/Erro vR' */
  real_T sat2;                         /* '<Root>/sat2' */
  real_T Product1_f;                   /* '<Root>/Product1' */
  real_T Product1_k;                   /* '<S13>/Product1' */
  real_T wheelradiousmm1;              /* '<Root>/wheel radious (mm)1' */
  real_T ErrovL;                       /* '<Root>/Erro vL' */
  real_T sat1;                         /* '<Root>/sat1' */
  real_T encoderrotationtowheelrotationg;/* '<S10>/ encoder rotation to wheel rotation (gear ratio)' */
  real_T x0;                           /* '<S11>/x0' */
  real_T Product_a;                    /* '<S11>/Product' */
  real_T encoderrotationtowheelrotatio_f;/* '<S12>/ encoder rotation to wheel rotation (gear ratio)' */
  real_T x0_b;                         /* '<S13>/x0' */
  real_T Product_k;                    /* '<S13>/Product' */
  real_T FixPtSum1;                    /* '<S71>/FixPt Sum1' */
  real_T Switch;                       /* '<S9>/Switch' */
  real_T x_sp;                         /* '<S9>/MATLAB Function' */
  real_T y_sp;                         /* '<S9>/MATLAB Function' */
  real_T VVavg;                        /* '<S67>/V-Vavg' */
  real_T Vin;                          /* '<S66>/Vin' */
  real_T Constant;                     /* '<S65>/Constant' */
  real_T div;                          /* '<S64>/div' */
  real_T x_dot;                        /* '<S15>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T y_dot;                        /* '<S15>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T psi_dot;                      /* '<S15>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T Omega;                        /* '<S14>/Qbot2_Diff_Drive_Kinematics' */
  B_IfActionSubsystem3_Fuzzy_ma_T IfActionSubsystem3;/* '<S42>/If Action Subsystem3' */
  B_IfActionSubsystem1_Fuzzy_ma_T IfActionSubsystem1;/* '<S42>/If Action Subsystem1' */
  B_IfActionSubsystem3_Fuzzy_ma_T IfActionSubsystem3_m;/* '<S41>/If Action Subsystem3' */
  B_IfActionSubsystem1_Fuzzy_ma_T IfActionSubsystem1_i;/* '<S41>/If Action Subsystem1' */
} B_Fuzzy_manobra_aplicado_2015_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S9>/Unit Delay' */
  real_T UnitDelay_DSTATE_p;           /* '<S68>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S64>/Sum( k=1,n-1, x(k) )' */
  real_T HILInitialize_POValues[4];    /* '<Root>/HIL Initialize' */
  real_T HILWrite_OtherBuffer[2];      /* '<S63>/HIL Write' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  struct {
    void *LoggedData;
  } Thetarobo_PWORK;                   /* '<Root>/Thetarobo' */

  struct {
    void *LoggedData;
  } Xrobo_PWORK;                       /* '<Root>/Xrobo' */

  struct {
    void *LoggedData;
  } Yrobo_PWORK;                       /* '<Root>/Yrobo' */

  void *HILRead1_PWORK;                /* '<S63>/HIL Read1' */
  struct {
    void *LoggedData;
  } ud_PWORK;                          /* '<Root>/ud' */

  struct {
    void *LoggedData;
  } ud1_PWORK;                         /* '<Root>/ud1' */

  struct {
    void *LoggedData;
  } ud2_PWORK;                         /* '<Root>/ud2' */

  struct {
    void *LoggedData;
  } ud3_PWORK;                         /* '<Root>/ud3' */

  struct {
    void *LoggedData;
  } ud4_PWORK;                         /* '<Root>/ud4' */

  struct {
    void *LoggedData;
  } ud5_PWORK;                         /* '<Root>/ud5' */

  struct {
    void *LoggedData;
  } ue_PWORK;                          /* '<Root>/ue' */

  struct {
    void *LoggedData;
  } ue1_PWORK;                         /* '<Root>/ue1' */

  struct {
    void *LoggedData;
  } x_sp_PWORK;                        /* '<Root>/x_sp' */

  struct {
    void *LoggedData;
  } y_sp_PWORK;                        /* '<Root>/y_sp' */

  void *HILWrite_PWORK;                /* '<S63>/HIL Write' */
  struct {
    void *LoggedData;
  } d_PWORK;                           /* '<S8>/d' */

  int32_T HILRead1_EncoderBuffer[2];   /* '<S63>/HIL Read1' */
  int_T Integrator1_IWORK;             /* '<S11>/Integrator1' */
  int_T Integrator1_IWORK_j;           /* '<S13>/Integrator1' */
  int8_T If_ActiveSubsystem;           /* '<S42>/If' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S42>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S42>/If Action Subsystem2' */
  int8_T If_ActiveSubsystem_l;         /* '<S41>/If' */
  int8_T IfActionSubsystem_SubsysRanBC_m;/* '<S41>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanB_o;/* '<S41>/If Action Subsystem2' */
  int8_T If_ActiveSubsystem_a;         /* '<S19>/If' */
  int8_T ActionOne_SubsysRanBC;        /* '<S19>/Action: One' */
  int8_T If_ActiveSubsystem_f;         /* '<S20>/If' */
  int8_T ActionOne_SubsysRanBC_h;      /* '<S20>/Action: One' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S62>/Enabled Moving Average' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S62>/Switch Case' */
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S62>/Switch Case Action Subsystem' */
  int8_T SwitchCaseActionSubsystem1_Subs;/* '<S62>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem2_Subs;/* '<S62>/Switch Case Action Subsystem2' */
  boolean_T EnabledMovingAverage_MODE; /* '<S62>/Enabled Moving Average' */
  DW_IfActionSubsystem3_Fuzzy_m_T IfActionSubsystem3;/* '<S42>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Fuzzy_m_T IfActionSubsystem1;/* '<S42>/If Action Subsystem1' */
  DW_IfActionSubsystem3_Fuzzy_m_T IfActionSubsystem3_m;/* '<S41>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Fuzzy_m_T IfActionSubsystem1_i;/* '<S41>/If Action Subsystem1' */
  DW_Actionu1_Fuzzy_manobra_apl_T Actionu1_l;/* '<S20>/Action: u1' */
  DW_Actionu1_Fuzzy_manobra_apl_T Actionu1;/* '<S19>/Action: u1' */
} DW_Fuzzy_manobra_aplicado_201_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T theta;                        /* '<Root>/Integrator3' */
  real_T x_a;                          /* '<Root>/Integrator1' */
  real_T y_a;                          /* '<Root>/Integrator2' */
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T ePI_d;                        /* '<Root>/Integrator4' */
  real_T ePI_e;                        /* '<Root>/Integrator5' */
  real_T Integrator2_CSTATE_h;         /* '<S13>/Integrator2' */
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S13>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
} X_Fuzzy_manobra_aplicado_2015_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T theta;                        /* '<Root>/Integrator3' */
  real_T x_a;                          /* '<Root>/Integrator1' */
  real_T y_a;                          /* '<Root>/Integrator2' */
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T ePI_d;                        /* '<Root>/Integrator4' */
  real_T ePI_e;                        /* '<Root>/Integrator5' */
  real_T Integrator2_CSTATE_h;         /* '<S13>/Integrator2' */
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S13>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
} XDot_Fuzzy_manobra_aplicado_2_T;

/* State disabled  */
typedef struct {
  boolean_T theta;                     /* '<Root>/Integrator3' */
  boolean_T x_a;                       /* '<Root>/Integrator1' */
  boolean_T y_a;                       /* '<Root>/Integrator2' */
  boolean_T Integrator2_CSTATE;        /* '<S11>/Integrator2' */
  boolean_T ePI_d;                     /* '<Root>/Integrator4' */
  boolean_T ePI_e;                     /* '<Root>/Integrator5' */
  boolean_T Integrator2_CSTATE_h;      /* '<S13>/Integrator2' */
  boolean_T Integrator1_CSTATE;        /* '<S11>/Integrator1' */
  boolean_T Integrator1_CSTATE_n;      /* '<S13>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S15>/Integrator' */
} XDis_Fuzzy_manobra_aplicado_2_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_Fuzzy_manobra_aplicado_2015_T_ {
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T N_sp;                         /* Variable: N_sp
                                        * Referenced by:
                                        *   '<S9>/Constant1'
                                        *   '<S70>/Constant'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by:
                                        *   '<Root>/wheel radious (m)'
                                        *   '<Root>/wheel radious (mm)1'
                                        */
  real_T k_i;                          /* Variable: k_i
                                        * Referenced by:
                                        *   '<Root>/Ki'
                                        *   '<Root>/Ki '
                                        */
  real_T k_p;                          /* Variable: k_p
                                        * Referenced by:
                                        *   '<Root>/Kp'
                                        *   '<Root>/Kp1'
                                        */
  real_T setpoints[46];                /* Variable: setpoints
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T MP_a;                         /* Mask Parameter: MP_a
                                        * Referenced by: '<S42>/If Action Subsystem1'
                                        */
  real_T G_a;                          /* Mask Parameter: G_a
                                        * Referenced by: '<S41>/If Action Subsystem1'
                                        */
  real_T MP_b;                         /* Mask Parameter: MP_b
                                        * Referenced by: '<S42>/If Action Subsystem1'
                                        */
  real_T G_b;                          /* Mask Parameter: G_b
                                        * Referenced by: '<S41>/If Action Subsystem1'
                                        */
  real_T MP_c;                         /* Mask Parameter: MP_c
                                        * Referenced by: '<S42>/If Action Subsystem3'
                                        */
  real_T G_c;                          /* Mask Parameter: G_c
                                        * Referenced by: '<S41>/If Action Subsystem3'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T MP_d;                         /* Mask Parameter: MP_d
                                        * Referenced by: '<S42>/If Action Subsystem3'
                                        */
  real_T G_d;                          /* Mask Parameter: G_d
                                        * Referenced by: '<S41>/If Action Subsystem3'
                                        */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S62>/Step: end_time'
                                        */
  real_T HILInitialize_final_other_outpu[3];/* Mask Parameter: HILInitialize_final_other_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T SecondOrderLowPassFilter2_input;/* Mask Parameter: SecondOrderLowPassFilter2_input
                                          * Referenced by: '<S11>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_b;/* Mask Parameter: SecondOrderLowPassFilter2_inp_b
                                          * Referenced by: '<S13>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_p;/* Mask Parameter: SecondOrderLowPassFilter2_inp_p
                                          * Referenced by: '<S11>/zt'
                                          */
  real_T SecondOrderLowPassFilter2_inp_f;/* Mask Parameter: SecondOrderLowPassFilter2_inp_f
                                          * Referenced by: '<S13>/zt'
                                          */
  real_T EN_mu;                        /* Mask Parameter: EN_mu
                                        * Referenced by: '<S51>/mu'
                                        */
  real_T GN_mu;                        /* Mask Parameter: GN_mu
                                        * Referenced by: '<S53>/mu'
                                        */
  real_T MN_mu;                        /* Mask Parameter: MN_mu
                                        * Referenced by: '<S55>/mu'
                                        */
  real_T Z_mu;                         /* Mask Parameter: Z_mu
                                        * Referenced by: '<S61>/mu'
                                        */
  real_T MP_mu;                        /* Mask Parameter: MP_mu
                                        * Referenced by: '<S56>/mu'
                                        */
  real_T GP_mu;                        /* Mask Parameter: GP_mu
                                        * Referenced by: '<S54>/mu'
                                        */
  real_T EP_mu;                        /* Mask Parameter: EP_mu
                                        * Referenced by: '<S52>/mu'
                                        */
  real_T PNF_mu;                       /* Mask Parameter: PNF_mu
                                        * Referenced by: '<S57>/mu'
                                        */
  real_T PPF_mu;                       /* Mask Parameter: PPF_mu
                                        * Referenced by: '<S59>/mu'
                                        */
  real_T PNR_mu;                       /* Mask Parameter: PNR_mu
                                        * Referenced by: '<S58>/mu'
                                        */
  real_T PPR_mu;                       /* Mask Parameter: PPR_mu
                                        * Referenced by: '<S60>/mu'
                                        */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_m;/* Mask Parameter: HILInitialize_set_other_outpu_m
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T EN_sigma;                     /* Mask Parameter: EN_sigma
                                        * Referenced by: '<S51>/sigma'
                                        */
  real_T GN_sigma;                     /* Mask Parameter: GN_sigma
                                        * Referenced by: '<S53>/sigma'
                                        */
  real_T MN_sigma;                     /* Mask Parameter: MN_sigma
                                        * Referenced by: '<S55>/sigma'
                                        */
  real_T Z_sigma;                      /* Mask Parameter: Z_sigma
                                        * Referenced by: '<S61>/sigma'
                                        */
  real_T MP_sigma;                     /* Mask Parameter: MP_sigma
                                        * Referenced by: '<S56>/sigma'
                                        */
  real_T GP_sigma;                     /* Mask Parameter: GP_sigma
                                        * Referenced by: '<S54>/sigma'
                                        */
  real_T EP_sigma;                     /* Mask Parameter: EP_sigma
                                        * Referenced by: '<S52>/sigma'
                                        */
  real_T PNF_sigma;                    /* Mask Parameter: PNF_sigma
                                        * Referenced by: '<S57>/sigma'
                                        */
  real_T PPF_sigma;                    /* Mask Parameter: PPF_sigma
                                        * Referenced by: '<S59>/sigma'
                                        */
  real_T PNR_sigma;                    /* Mask Parameter: PNR_sigma
                                        * Referenced by: '<S58>/sigma'
                                        */
  real_T PPR_sigma;                    /* Mask Parameter: PPR_sigma
                                        * Referenced by: '<S60>/sigma'
                                        */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S62>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S62>/Constant'
                                        */
  uint32_T HILRead1_analog_channels;   /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<S63>/HIL Read1'
                                        */
  uint32_T HILRead1_digital_channels[3];/* Mask Parameter: HILRead1_digital_channels
                                         * Referenced by: '<S63>/HIL Read1'
                                         */
  uint32_T HILRead1_encoder_channels[2];/* Mask Parameter: HILRead1_encoder_channels
                                         * Referenced by: '<S63>/HIL Read1'
                                         */
  uint32_T HILRead1_other_channels;    /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<S63>/HIL Read1'
                                        */
  uint32_T HILWrite_other_channels[2]; /* Mask Parameter: HILWrite_other_channels
                                        * Referenced by: '<S63>/HIL Write'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out;/* Mask Parameter: HILInitialize_final_digital_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_f;/* Mask Parameter: HILInitialize_set_analog_outp_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_f;/* Mask Parameter: HILInitialize_set_digital_out_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_output_ah;/* Mask Parameter: HILInitialize_set_pwm_output_ah
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S37>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S37>/One'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S39>/Out1'
                                        */
  real_T One_Value_m;                  /* Expression: 1
                                        * Referenced by: '<S39>/One'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S43>/Out1'
                                        */
  real_T u_Value;                      /* Expression: 0
                                        * Referenced by: '<S43>/0'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 0
                                        * Referenced by: '<S45>/Out1'
                                        */
  real_T u_Value_g;                    /* Expression: 1
                                        * Referenced by: '<S45>/0'
                                        */
  real_T Out1_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S47>/Out1'
                                        */
  real_T u_Value_p;                    /* Expression: 0
                                        * Referenced by: '<S47>/0'
                                        */
  real_T Out1_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S49>/Out1'
                                        */
  real_T u_Value_h;                    /* Expression: 1
                                        * Referenced by: '<S49>/0'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S68>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S64>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S65>/zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S66>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S67>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S62>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S62>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S62>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S62>/Step: end_time'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T xdata_Value[101];             /* Expression: Xdata
                                        * Referenced by: '<S19>/x data'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T UnitDelay_InitialCondition_d; /* Expression: 1
                                        * Referenced by: '<S9>/Unit Delay'
                                        */
  real_T P_Value[101];                 /* Expression: pimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
                                        * Referenced by: '<S35>/P'
                                        */
  real_T N_Value[101];                 /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(2).params)
                                        * Referenced by: '<S36>/N'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S25>/Weight'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -0.5
                                        * Referenced by: '<S51>/Gain'
                                        */
  real_T R_Value[101];                 /* Expression: sigmf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S35>/R'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S26>/Weight'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -0.5
                                        * Referenced by: '<S53>/Gain'
                                        */
  real_T AH_Value[101];                /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(3).params)
                                        * Referenced by: '<S36>/AH'
                                        */
  real_T Weight_Value_n;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S27>/Weight'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -0.5
                                        * Referenced by: '<S55>/Gain'
                                        */
  real_T H_Value[101];                 /* Expression: trimf(linspace(fis.output(2).range(1),fis.output(2).range(2),101),fis.output(2).mf(1).params)
                                        * Referenced by: '<S36>/H'
                                        */
  real_T Weight_Value_p;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S28>/Weight'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -0.5
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T F_Value[101];                 /* Expression: sigmf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S35>/F'
                                        */
  real_T Weight_Value_nc;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S29>/Weight'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -0.5
                                        * Referenced by: '<S56>/Gain'
                                        */
  real_T Weight_Value_e;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S30>/Weight'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -0.5
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T Weight_Value_k;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S31>/Weight'
                                        */
  real_T Gain_Gain_eg;                 /* Expression: -0.5
                                        * Referenced by: '<S52>/Gain'
                                        */
  real_T Weight_Value_a;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S32>/Weight'
                                        */
  real_T Gain_Gain_b;                  /* Expression: -0.5
                                        * Referenced by: '<S57>/Gain'
                                        */
  real_T MF_Value[101];                /* Expression: pimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(4).params)
                                        * Referenced by: '<S35>/MF'
                                        */
  real_T Weight_Value_ec;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -0.5
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Weight_Value_l;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S23>/Weight'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -0.5
                                        * Referenced by: '<S58>/Gain'
                                        */
  real_T MR_Value[101];                /* Expression: pimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(5).params)
                                        * Referenced by: '<S35>/MR'
                                        */
  real_T Weight_Value_ez;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S24>/Weight'
                                        */
  real_T Gain_Gain_kj;                 /* Expression: -0.5
                                        * Referenced by: '<S60>/Gain'
                                        */
  real_T xdata_Value_k[101];           /* Expression: Xdata
                                        * Referenced by: '<S20>/x data'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S18>/Zero'
                                        */
  real_T MidRange_Value[2];            /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S18>/MidRange'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T Integrator2_IC_l;             /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  real_T sat2_UpperSat;                /* Expression: 0.65
                                        * Referenced by: '<Root>/sat2'
                                        */
  real_T sat2_LowerSat;                /* Expression: -0.65
                                        * Referenced by: '<Root>/sat2'
                                        */
  real_T Integrator2_IC_b;             /* Expression: 0
                                        * Referenced by: '<S13>/Integrator2'
                                        */
  real_T sat1_UpperSat;                /* Expression: 0.65
                                        * Referenced by: '<Root>/sat1'
                                        */
  real_T sat1_LowerSat;                /* Expression: -0.65
                                        * Referenced by: '<Root>/sat1'
                                        */
  real_T tickstoencoderrotation_Gain;  /* Expression: 2*pi/52
                                        * Referenced by: '<S10>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotationg;/* Expression: 1/49.5833
                                          * Referenced by: '<S10>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S11>/x0'
                                        */
  real_T tickstoencoderrotation_Gain_a;/* Expression: 2*pi/52
                                        * Referenced by: '<S12>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotatio_i;/* Expression: 1/49.5833
                                          * Referenced by: '<S12>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T x0_Value_p;                   /* Expression: input_init
                                        * Referenced by: '<S13>/x0'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T FixPtConstant_Value;          /* Expression: 1
                                        * Referenced by: '<S71>/FixPt Constant'
                                        */
  uint8_T sw5_CurrentSetting;          /* Computed Parameter: sw5_CurrentSetting
                                        * Referenced by: '<Root>/sw5'
                                        */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S63>/HIL Read1'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S63>/HIL Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Fuzzy_manobra_aplicad_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Fuzzy_manobra_aplicado_2015_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][10];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_P;

/* Block signals (auto storage) */
extern B_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_B;

/* Continuous states (auto storage) */
extern X_Fuzzy_manobra_aplicado_2015_T Fuzzy_manobra_aplicado_2015b_X;

/* Block states (auto storage) */
extern DW_Fuzzy_manobra_aplicado_201_T Fuzzy_manobra_aplicado_2015b_DW;

/* Model entry point functions */
extern void Fuzzy_manobra_aplicado_2015b_initialize(void);
extern void Fuzzy_manobra_aplicado_2015b_step(void);
extern void Fuzzy_manobra_aplicado_2015b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Fuzzy_manobra_aplica_T *const Fuzzy_manobra_aplicado_2015b_M;

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
 * '<Root>' : 'Fuzzy_manobra_aplicado_2015b'
 * '<S1>'   : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity'
 * '<S2>'   : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity1'
 * '<S3>'   : 'Fuzzy_manobra_aplicado_2015b/Forward Kinematics (No Gyro)'
 * '<S4>'   : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller'
 * '<S5>'   : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic'
 * '<S6>'   : 'Fuzzy_manobra_aplicado_2015b/S1'
 * '<S7>'   : 'Fuzzy_manobra_aplicado_2015b/S1 novo1'
 * '<S8>'   : 'Fuzzy_manobra_aplicado_2015b/S2'
 * '<S9>'   : 'Fuzzy_manobra_aplicado_2015b/Subsystem'
 * '<S10>'  : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity/Encoder to Distance'
 * '<S11>'  : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity/Second-Order Low-Pass Filter2'
 * '<S12>'  : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity1/Encoder to Distance'
 * '<S13>'  : 'Fuzzy_manobra_aplicado_2015b/Encoder_to_Velocity1/Second-Order Low-Pass Filter2'
 * '<S14>'  : 'Fuzzy_manobra_aplicado_2015b/Forward Kinematics (No Gyro)/Qbot2_Diff_Drive_Kinematics'
 * '<S15>'  : 'Fuzzy_manobra_aplicado_2015b/Forward Kinematics (No Gyro)/Qbot2_Kinematics (No Gyro)'
 * '<S16>'  : 'Fuzzy_manobra_aplicado_2015b/Forward Kinematics (No Gyro)/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics'
 * '<S17>'  : 'Fuzzy_manobra_aplicado_2015b/Forward Kinematics (No Gyro)/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)'
 * '<S18>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard'
 * '<S19>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1'
 * '<S20>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification2'
 * '<S21>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule1'
 * '<S22>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule10'
 * '<S23>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule11'
 * '<S24>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule12'
 * '<S25>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule2'
 * '<S26>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule3'
 * '<S27>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule4'
 * '<S28>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule5'
 * '<S29>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule6'
 * '<S30>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule7'
 * '<S31>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule8'
 * '<S32>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Rule9'
 * '<S33>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d'
 * '<S34>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi'
 * '<S35>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/v'
 * '<S36>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/w'
 * '<S37>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S38>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S39>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification2/Action: One'
 * '<S40>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/Defuzzification2/Action: u1'
 * '<S41>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/G'
 * '<S42>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/MP'
 * '<S43>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/G/If Action Subsystem'
 * '<S44>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/G/If Action Subsystem1'
 * '<S45>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/G/If Action Subsystem2'
 * '<S46>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/G/If Action Subsystem3'
 * '<S47>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/MP/If Action Subsystem'
 * '<S48>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/MP/If Action Subsystem1'
 * '<S49>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/MP/If Action Subsystem2'
 * '<S50>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/d/MP/If Action Subsystem3'
 * '<S51>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/EN'
 * '<S52>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/EP'
 * '<S53>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/GN'
 * '<S54>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/GP'
 * '<S55>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/MN'
 * '<S56>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/MP'
 * '<S57>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/PNF'
 * '<S58>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/PNR'
 * '<S59>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/PPF'
 * '<S60>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/PPR'
 * '<S61>'  : 'Fuzzy_manobra_aplicado_2015b/Fuzzy Logic  Controller/FIS Wizard/phi/Z'
 * '<S62>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal'
 * '<S63>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/QBot2_IO_Basic'
 * '<S64>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal/Enabled Moving Average'
 * '<S65>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal/Switch Case Action Subsystem'
 * '<S66>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal/Switch Case Action Subsystem1'
 * '<S67>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal/Switch Case Action Subsystem2'
 * '<S68>'  : 'Fuzzy_manobra_aplicado_2015b/QBot_Basic/Bias Removal/Enabled Moving Average/Increment'
 * '<S69>'  : 'Fuzzy_manobra_aplicado_2015b/Subsystem/Compare To Constant'
 * '<S70>'  : 'Fuzzy_manobra_aplicado_2015b/Subsystem/Compare To Constant1'
 * '<S71>'  : 'Fuzzy_manobra_aplicado_2015b/Subsystem/Increment Stored Integer'
 * '<S72>'  : 'Fuzzy_manobra_aplicado_2015b/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Fuzzy_manobra_aplicado_2015b_h_ */
