#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME ddmr_model_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwstringutil.h"
#define rt_logging_h
#include "ddmr_model_types.h"
#include "ddmr_model.h"
#include "ddmr_model_private.h"
real_T rtP_K_ce ; real_T rtP_K_t ; real_T rtP_L ; real_T rtP_Md ; real_T
rtP_Mn1 ; real_T rtP_Mn2 ; real_T rtP_N ; real_T rtP_R ; real_T rtP_R_a ;
real_T rtP_alpha_k ; real_T rtP_alpha_s ; real_T rtP_b ; real_T rtP_d ;
real_T rtP_f_k ; real_T rtP_f_s ; real_T rtP_g ; real_T rtP_k_i ; real_T
rtP_k_p ; real_T rtP_m ; real_T rtP_m_c ; const char *
rt_GetMatSignalLoggingFileName ( void ) { return NULL ; } const char *
rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; } void *
rt_GetOSigstreamManager ( void ) { return NULL ; } void * rt_slioCatalogue (
void ) { return NULL ; } void * rtwGetPointerFromUniquePtr ( void * uniquePtr
) { return NULL ; } void * CreateDiagnosticAsVoidPtr ( const char * id , int
nargs , ... ) { void * voidPtrDiagnostic = NULL ; va_list args ; va_start (
args , nargs ) ; slmrCreateDiagnostic ( id , nargs , args , &
voidPtrDiagnostic ) ; va_end ( args ) ; return voidPtrDiagnostic ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * simStrcut = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( simStrcut ) ) {
_ssSet_slLocalErrMsg ( simStrcut , diag ) ; } else { _ssDiscardDiagnostic (
simStrcut , diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S ,
void * diag ) { _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; }
void rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } const char *
rt_CreateFullPathToTop ( const char * toppath , const char * subpath ) { char
* fullpath = NULL ; slmrCreateFullPathToTop ( toppath , subpath , & fullpath
) ; return fullpath ; } boolean_T slIsRapidAcceleratorSimulating ( void ) {
return false ; } void rt_RAccelReplaceFromFilename ( const char * blockpath ,
char * fileName ) { ( void ) blockpath ; ( void ) fileName ; } void
rt_RAccelReplaceToFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; } void * slsa_malloc ( size_t s ) {
return malloc ( s ) ; } void slsa_free ( void * ptr ) { free ( ptr ) ; } void
slsaCacheDWorkPointerForSimTargetOP ( void * ss , void * * ptr ) { ( void )
ss ; ( void ) ptr ; } void slsaCacheDWorkDataForSimTargetOP ( void * ss ,
void * ptr , unsigned int sizeInBytes ) { ( void ) ss ; ( void ) ptr ; ( void
) sizeInBytes ; } void slsaSaveRawMemoryForSimTargetOP ( void * ss , const
char * key , void * * ptr , unsigned int sizeInBytes , void * ( *
customOPSaveFcn ) ( void * dworkPtr , unsigned int * sizeInBytes ) , void ( *
customOPRestoreFcn ) ( void * dworkPtr , const void * data , unsigned int
sizeInBytes ) ) { ( void ) ss ; ( void ) key ; ( void ) ptr ; ( void )
sizeInBytes ; ( void ) customOPSaveFcn ; ( void ) customOPRestoreFcn ; }
#define MDL_PROCESS_PARAMETERS
#if defined(MATLAB_MEX_FILE)
static void mdlProcessParameters ( SimStruct * S ) { real_T * GlobalPrm_0 = (
real_T * ) NULL ; real_T * GlobalPrm_1 = ( real_T * ) NULL ; real_T *
GlobalPrm_2 = ( real_T * ) NULL ; real_T * GlobalPrm_3 = ( real_T * ) NULL ;
real_T * GlobalPrm_4 = ( real_T * ) NULL ; real_T * GlobalPrm_5 = ( real_T *
) NULL ; real_T * GlobalPrm_6 = ( real_T * ) NULL ; real_T * GlobalPrm_7 = (
real_T * ) NULL ; real_T * GlobalPrm_8 = ( real_T * ) NULL ; real_T *
GlobalPrm_9 = ( real_T * ) NULL ; real_T * GlobalPrm_10 = ( real_T * ) NULL ;
real_T * GlobalPrm_11 = ( real_T * ) NULL ; real_T * GlobalPrm_12 = ( real_T
* ) NULL ; real_T * GlobalPrm_13 = ( real_T * ) NULL ; real_T * GlobalPrm_14
= ( real_T * ) NULL ; real_T * GlobalPrm_15 = ( real_T * ) NULL ; real_T *
GlobalPrm_16 = ( real_T * ) NULL ; real_T * GlobalPrm_17 = ( real_T * ) NULL
; real_T * GlobalPrm_18 = ( real_T * ) NULL ; real_T * GlobalPrm_19 = (
real_T * ) NULL ; if ( ! ssGetModelRefGlobalParamData ( S , 0 , ( void * * )
( & GlobalPrm_0 ) ) ) return ; if ( GlobalPrm_0 != NULL ) { ( void ) memcpy (
& ( rtP_K_ce ) , GlobalPrm_0 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 1 , ( void * * ) ( & GlobalPrm_1 ) ) )
return ; if ( GlobalPrm_1 != NULL ) { ( void ) memcpy ( & ( rtP_K_t ) ,
GlobalPrm_1 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 2 , ( void * * ) ( & GlobalPrm_2 ) ) ) return ; if ( GlobalPrm_2 != NULL )
{ ( void ) memcpy ( & ( rtP_L ) , GlobalPrm_2 , sizeof ( real_T ) ) ; } if (
! ssGetModelRefGlobalParamData ( S , 3 , ( void * * ) ( & GlobalPrm_3 ) ) )
return ; if ( GlobalPrm_3 != NULL ) { ( void ) memcpy ( & ( rtP_Md ) ,
GlobalPrm_3 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 4 , ( void * * ) ( & GlobalPrm_4 ) ) ) return ; if ( GlobalPrm_4 != NULL )
{ ( void ) memcpy ( & ( rtP_Mn1 ) , GlobalPrm_4 , sizeof ( real_T ) ) ; } if
( ! ssGetModelRefGlobalParamData ( S , 5 , ( void * * ) ( & GlobalPrm_5 ) ) )
return ; if ( GlobalPrm_5 != NULL ) { ( void ) memcpy ( & ( rtP_Mn2 ) ,
GlobalPrm_5 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 6 , ( void * * ) ( & GlobalPrm_6 ) ) ) return ; if ( GlobalPrm_6 != NULL )
{ ( void ) memcpy ( & ( rtP_N ) , GlobalPrm_6 , sizeof ( real_T ) ) ; } if (
! ssGetModelRefGlobalParamData ( S , 7 , ( void * * ) ( & GlobalPrm_7 ) ) )
return ; if ( GlobalPrm_7 != NULL ) { ( void ) memcpy ( & ( rtP_R ) ,
GlobalPrm_7 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 8 , ( void * * ) ( & GlobalPrm_8 ) ) ) return ; if ( GlobalPrm_8 != NULL )
{ ( void ) memcpy ( & ( rtP_R_a ) , GlobalPrm_8 , sizeof ( real_T ) ) ; } if
( ! ssGetModelRefGlobalParamData ( S , 9 , ( void * * ) ( & GlobalPrm_9 ) ) )
return ; if ( GlobalPrm_9 != NULL ) { ( void ) memcpy ( & ( rtP_alpha_k ) ,
GlobalPrm_9 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData ( S
, 10 , ( void * * ) ( & GlobalPrm_10 ) ) ) return ; if ( GlobalPrm_10 != NULL
) { ( void ) memcpy ( & ( rtP_alpha_s ) , GlobalPrm_10 , sizeof ( real_T ) )
; } if ( ! ssGetModelRefGlobalParamData ( S , 11 , ( void * * ) ( &
GlobalPrm_11 ) ) ) return ; if ( GlobalPrm_11 != NULL ) { ( void ) memcpy ( &
( rtP_b ) , GlobalPrm_11 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 12 , ( void * * ) ( & GlobalPrm_12 ) ) )
return ; if ( GlobalPrm_12 != NULL ) { ( void ) memcpy ( & ( rtP_d ) ,
GlobalPrm_12 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 13 , ( void * * ) ( & GlobalPrm_13 ) ) ) return ; if ( GlobalPrm_13 !=
NULL ) { ( void ) memcpy ( & ( rtP_f_k ) , GlobalPrm_13 , sizeof ( real_T ) )
; } if ( ! ssGetModelRefGlobalParamData ( S , 14 , ( void * * ) ( &
GlobalPrm_14 ) ) ) return ; if ( GlobalPrm_14 != NULL ) { ( void ) memcpy ( &
( rtP_f_s ) , GlobalPrm_14 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 15 , ( void * * ) ( & GlobalPrm_15 ) ) )
return ; if ( GlobalPrm_15 != NULL ) { ( void ) memcpy ( & ( rtP_g ) ,
GlobalPrm_15 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 16 , ( void * * ) ( & GlobalPrm_16 ) ) ) return ; if ( GlobalPrm_16 !=
NULL ) { ( void ) memcpy ( & ( rtP_k_i ) , GlobalPrm_16 , sizeof ( real_T ) )
; } if ( ! ssGetModelRefGlobalParamData ( S , 17 , ( void * * ) ( &
GlobalPrm_17 ) ) ) return ; if ( GlobalPrm_17 != NULL ) { ( void ) memcpy ( &
( rtP_k_p ) , GlobalPrm_17 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 18 , ( void * * ) ( & GlobalPrm_18 ) ) )
return ; if ( GlobalPrm_18 != NULL ) { ( void ) memcpy ( & ( rtP_m ) ,
GlobalPrm_18 , sizeof ( real_T ) ) ; } if ( ! ssGetModelRefGlobalParamData (
S , 19 , ( void * * ) ( & GlobalPrm_19 ) ) ) return ; if ( GlobalPrm_19 !=
NULL ) { ( void ) memcpy ( & ( rtP_m_c ) , GlobalPrm_19 , sizeof ( real_T ) )
; } }
#endif
static void mdlInitializeConditions ( SimStruct * S ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; gecj2ndo0o * localX = ( gecj2ndo0o * )
ssGetContStates ( S ) ; ccsiudf4i2 ( localX ) ; } static void mdlReset (
SimStruct * S ) { fy3lu2f2ujv * dw = ( fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ;
gecj2ndo0o * localX = ( gecj2ndo0o * ) ssGetContStates ( S ) ; etglvvkmke (
localX ) ; } static void mdlPeriodicOutputUpdate ( SimStruct * S , int_T tid
) { fy3lu2f2ujv * dw = ( fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; real_T const
* i_a2zzxv4i1q = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; real_T const *
i_lqjalg3n0u = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; real_T * o_B_1_1
= ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_1_2 = ( real_T
* ) ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_1_3 = ( real_T * )
ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_1_4 = ( real_T * )
ssGetOutputPortSignal ( S , 3 ) ; real_T * o_B_1_5 = ( real_T * )
ssGetOutputPortSignal ( S , 4 ) ; gecj2ndo0o * localX = ( gecj2ndo0o * )
ssGetContStates ( S ) ; if ( tid == 0 ) { ddmr_model ( & ( dw -> rtm ) ,
i_a2zzxv4i1q , i_lqjalg3n0u , o_B_1_1 , o_B_1_2 , o_B_1_3 , o_B_1_4 , o_B_1_5
, & ( dw -> rtb ) , & ( dw -> rtdw ) , localX ) ; fbm5qosqr1 ( & ( dw -> rtm
) ) ; } } static void mdlInitializeSizes ( SimStruct * S ) { if ( ( S ->
mdlInfo -> genericFcn != ( NULL ) ) && ( ! ( S -> mdlInfo -> genericFcn ) ( S
, GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK , - 1 , ( NULL ) ) ) ) { return ;
} ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 7 ) ;
ssSetNumDiscStates ( S , 0 ) ; ssSetNumPeriodicContStates ( S , 0 ) ;
ssSetSymbolicDimsSupport ( S , true ) ; slmrInitializeIOPortDataVectors ( S ,
2 , 5 ) ; if ( ! ssSetNumInputPorts ( S , 2 ) ) return ; if ( !
ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 0 ,
false ) ; ssSetInputPortSampleTime ( S , 0 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 0 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_LOCAL ) ; ssSetInputPortOverWritable ( S , 1 ,
false ) ; ssSetInputPortSampleTime ( S , 1 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 1 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S , 5 ) ) return ; if ( !
ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 0 , 0.01 ) ; ssSetOutputPortOffsetTime ( S
, 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 0 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 1 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 1 , 0.01 ) ; ssSetOutputPortOffsetTime ( S
, 1 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 1 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 1 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 1 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 1 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 2 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 2 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 2 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 2 , 0.01 ) ; ssSetOutputPortOffsetTime ( S
, 2 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 2 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 2 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 2 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 2 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 3 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 3 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 3 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 3 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 3 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 3 , 0.0 ) ; ssSetOutputPortOffsetTime ( S ,
3 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 3 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 3 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 3 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 3 , SS_NOT_REUSABLE_AND_GLOBAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 4 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 4 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 4 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 4 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 4 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 4 , 0.0 ) ; ssSetOutputPortOffsetTime ( S ,
4 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 4 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 4 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 4 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 4 , SS_NOT_REUSABLE_AND_GLOBAL ) ;
ssSetSimStateCompliance ( S , USE_CUSTOM_SIM_STATE ) ;
mr_ddmr_model_RegisterSimStateChecksum ( S ) ; ssSetNumSampleTimes ( S ,
PORT_BASED_SAMPLE_TIMES ) ; ssSetParameterTuningCompliance ( S , true ) ;
ssSetNumRWork ( S , 0 ) ; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ;
ssSetNumModes ( S , 0 ) ; { int_T zcsIdx = 0 ; zcsIdx =
ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S , zcsIdx , 1 ) ;
ssSetZcSignalName ( S , zcsIdx , "UprLim" ) ; ssSetZcSignalType ( S , zcsIdx
, SL_ZCS_TYPE_CONT ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0 ) ;
zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S , zcsIdx ,
1 ) ; ssSetZcSignalName ( S , zcsIdx , "LwrLim" ) ; ssSetZcSignalType ( S ,
zcsIdx , SL_ZCS_TYPE_CONT ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0 ) ;
zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S , zcsIdx ,
1 ) ; ssSetZcSignalName ( S , zcsIdx , "UprLim" ) ; ssSetZcSignalType ( S ,
zcsIdx , SL_ZCS_TYPE_CONT ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0 ) ;
zcsIdx = ssCreateAndAddZcSignalInfo ( S ) ; ssSetZcSignalWidth ( S , zcsIdx ,
1 ) ; ssSetZcSignalName ( S , zcsIdx , "LwrLim" ) ; ssSetZcSignalType ( S ,
zcsIdx , SL_ZCS_TYPE_CONT ) ; ssSetZcSignalZcEventType ( S , zcsIdx ,
SL_ZCS_EVENT_ALL ) ; ssSetZcSignalNeedsEventNotification ( S , zcsIdx , 0 ) ;
} ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 1 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 1 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 2 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 2 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 3 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 3 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 4 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 4 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 0 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 0 ) ; ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetAcceptsFcnCallInputs ( S ) ;
ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
true ) ; ssHasStateInsideForEachSS ( S , false ) ; ssSetOptions ( S ,
SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES | SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
| SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE ) ;
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ; mr_ddmr_model_MdlInfoRegFcn
( S , "ddmr_model" , & retVal ) ; if ( ! retVal ) return ; }
#endif
#if SS_SFCN_FOR_SIM
if ( ssSetNumDWork ( S , 1 ) ) { int mdlrefDWTypeId ; ssRegMdlRefDWorkType (
S , & mdlrefDWTypeId ) ; if ( mdlrefDWTypeId == INVALID_DTYPE_ID ) return ;
if ( ! ssSetDataTypeSize ( S , mdlrefDWTypeId , sizeof ( fy3lu2f2ujv ) ) )
return ; ssSetDWorkDataType ( S , 0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S
, 0 , 1 ) ; }
#else
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#endif
slmrRegisterSystemInitializeMethod ( S , mdlInitializeConditions ) ;
slmrRegisterSystemResetMethod ( S , mdlReset ) ;
slmrRegisterPeriodicOutputUpdateMethod ( S , mdlPeriodicOutputUpdate ) ;
ssSetSimulinkVersionGeneratedIn ( S , "23.2" ) ; ssSetNeedAbsoluteTime ( S ,
1 ) ; } static void mdlInitializeSampleTimes ( SimStruct * S ) { return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_SETUP_RUNTIME_RESOURCES
static void mdlSetupRuntimeResources ( SimStruct * S ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; gecj2ndo0o * localX = ( gecj2ndo0o * )
ssGetContStates ( S ) ; void * sysRanPtr = ( NULL ) ; int sysTid = 0 ;
ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid ( S , &
sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } mp5i2ytrlb ( S ,
slmrGetTopTidFromMdlRefChildTid ( S , 0 , false ) ,
slmrGetTopTidFromMdlRefChildTid ( S , 1 , false ) , & ( dw -> rtm ) , & ( dw
-> rtb ) , & ( dw -> rtdw ) , localX , sysRanPtr , sysTid , ( ( NULL ) ) , (
( NULL ) ) , 0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( dw -> rtm .
DataMapInfo . mmi ) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) {
_GenericFcn fcn = S -> mdlInfo -> genericFcn ; } }
#define MDL_START
static void mdlStart ( SimStruct * S ) { mdlProcessParameters ( S ) ; }
static void mdlOutputs ( SimStruct * S , int_T tid ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; real_T const * i_a2zzxv4i1q = ( real_T
* ) ssGetInputPortSignal ( S , 0 ) ; real_T const * i_lqjalg3n0u = ( real_T *
) ssGetInputPortSignal ( S , 1 ) ; real_T * o_B_1_1 = ( real_T * )
ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_1_2 = ( real_T * )
ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_1_3 = ( real_T * )
ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_1_4 = ( real_T * )
ssGetOutputPortSignal ( S , 3 ) ; real_T * o_B_1_5 = ( real_T * )
ssGetOutputPortSignal ( S , 4 ) ; gecj2ndo0o * localX = ( gecj2ndo0o * )
ssGetContStates ( S ) ; if ( tid != CONSTANT_TID && tid !=
PARAMETER_TUNING_TID ) { ddmr_model ( & ( dw -> rtm ) , i_a2zzxv4i1q ,
i_lqjalg3n0u , o_B_1_1 , o_B_1_2 , o_B_1_3 , o_B_1_4 , o_B_1_5 , & ( dw ->
rtb ) , & ( dw -> rtdw ) , localX ) ; } }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; fbm5qosqr1 ( & ( dw -> rtm ) ) ;
return ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; ontpm2umoe * localZCSV = ( ontpm2umoe
* ) ssGetNonsampledZCs ( S ) ; ogkmeckrq1 ( & ( dw -> rtb ) , localZCSV ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fy3lu2f2ujv * dw = (
fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; dzlksfmbtn * localXdot = ( dzlksfmbtn
* ) ssGetdX ( S ) ; ejme0r5xti ( & ( dw -> rtb ) , localXdot ) ; } static
void mdlTerminate ( SimStruct * S ) { fy3lu2f2ujv * dw = ( fy3lu2f2ujv * )
ssGetDWork ( S , 0 ) ; g5clpc2dtg ( & ( dw -> rtm ) ) ; return ; }
#define MDL_CLEANUP_RUNTIME_RESOURCES
static void mdlCleanupRuntimeResources ( SimStruct * S ) { }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static mxArray * mdlGetSimState ( SimStruct * S ) { static const char *
simStateFieldNames [ 6 ] = { "localX" , "mdlrefDW" , "disallowedStateData" ,
"tNext" , "tNextTid" , "nonContDerivSigInfoPrevVal" , } ; mxArray * ss =
mxCreateStructMatrix ( 1 , 1 , 6 , simStateFieldNames ) ; { const gecj2ndo0o
* localX = ( const gecj2ndo0o * ) ssGetContStates ( S ) ; const size_t
numBytes = sizeof ( gecj2ndo0o ) ; mxArray * storedX = mxCreateNumericMatrix
( 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; UINT8_T * rawData = ( UINT8_T * )
mxGetData ( storedX ) ; memcpy ( & rawData [ 0 ] , localX , numBytes ) ;
mxSetFieldByNumber ( ss , 0 , 0 , storedX ) ; } { mxArray * mdlrefDW =
mr_ddmr_model_GetDWork ( ssGetDWork ( S , 0 ) ) ; mxSetFieldByNumber ( ss , 0
, 1 , mdlrefDW ) ; } { mxArray * data =
mr_ddmr_model_GetSimStateDisallowedBlocks ( ) ; mxSetFieldByNumber ( ss , 0 ,
2 , data ) ; } ; mxSetFieldByNumber ( ss , 0 , 3 , mxCreateDoubleScalar ( (
double ) ssGetTNext ( S ) ) ) ; mxSetFieldByNumber ( ss , 0 , 4 ,
mxCreateDoubleScalar ( ( double ) ssGetTNextTid ( S ) ) ) ; { fy3lu2f2ujv *
dw = ( fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ; nbfwhaflif * rtm = & ( dw ->
rtm ) ; mxArray * nonContDerivSigInfo = mxCreateCellMatrix ( 2 , 1 ) ; for (
int i = 0 ; i < 2 ; ++ i ) { mxArray * prevValmxArray = mxCreateNumericMatrix
( 1 , rtm -> nonContDerivSignal [ i ] . sizeInBytes , mxUINT8_CLASS , mxREAL
) ; memcpy ( ( uint8_T * ) mxGetData ( prevValmxArray ) , ( const uint8_T * )
rtm -> nonContDerivSignal [ i ] . pPrevVal , rtm -> nonContDerivSignal [ i ]
. sizeInBytes ) ; mxSetCell ( nonContDerivSigInfo , i , prevValmxArray ) ; }
mxSetFieldByNumber ( ss , 0 , 5 , nonContDerivSigInfo ) ; } return ss ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static void mdlSetSimState ( SimStruct * S , const mxArray * ss ) { {
gecj2ndo0o * localX = ( gecj2ndo0o * ) ssGetContStates ( S ) ; const size_t
numBytes = sizeof ( gecj2ndo0o ) ; const mxArray * storedX =
mxGetFieldByNumber ( ss , 0 , 0 ) ; const UINT8_T * rawData = ( const UINT8_T
* ) mxGetData ( storedX ) ; memcpy ( localX , & rawData [ 0 ] , numBytes ) ;
} mr_ddmr_model_SetDWork ( ssGetDWork ( S , 0 ) , mxGetFieldByNumber ( ss , 0
, 1 ) ) ; ssSetTNext ( S , ( time_T ) mxGetScalar ( mxGetFieldByNumber ( ss ,
0 , 3 ) ) ) ; ssSetTNextTid ( S , ( int_T ) mxGetScalar ( mxGetFieldByNumber
( ss , 0 , 4 ) ) ) ; { mxArray * nonContDerivSigInfo = mxGetFieldByNumber (
ss , 0 , 5 ) ; fy3lu2f2ujv * dw = ( fy3lu2f2ujv * ) ssGetDWork ( S , 0 ) ;
nbfwhaflif * rtm = & ( dw -> rtm ) ; for ( int i = 0 ; i < 2 ; ++ i ) {
mxArray * prevValmxArray = mxGetCell ( nonContDerivSigInfo , i ) ; ( void )
memcpy ( rtm -> nonContDerivSignal [ i ] . pPrevVal , ( char * ) mxGetData (
prevValmxArray ) , rtm -> nonContDerivSignal [ i ] . sizeInBytes ) ; } } }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
