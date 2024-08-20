/*
 * setpoints_model_data.c
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

/* Block parameters (auto storage) */
P_setpoints_model_T setpoints_model_P = {
  15.0,                                /* Variable: N_sp
                                        * Referenced by:
                                        *   '<Root>/Constant1'
                                        *   '<S2>/Constant'
                                        */

  /*  Variable: setpoints
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.732408192445406, 0.610340160371172, 0.488272128296938,
    0.366204096222703, 0.244136064148469, 0.122068032074234, 0.0,
    0.732408192445406, 0.610340160371172, 0.488272128296938, 0.366204096222703,
    0.244136064148469, 0.122068032074234, 0.0, 0.0, -4.44089209850063E-16,
    -0.501950467033187, -0.919916176948096, -1.26794919243112, -1.55775042969259,
    -1.799063044824, -2.0, -2.0, -1.799063044824, -1.55775042969259,
    -1.26794919243112, -0.919916176948096, -0.501950467033188,
    -4.44089209850063E-16 },
  0.035,                               /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
};
