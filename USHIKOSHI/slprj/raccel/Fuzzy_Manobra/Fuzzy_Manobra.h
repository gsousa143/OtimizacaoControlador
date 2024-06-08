#ifndef RTW_HEADER_Fuzzy_Manobra_h_
#define RTW_HEADER_Fuzzy_Manobra_h_
#ifndef Fuzzy_Manobra_COMMON_INCLUDES_
#define Fuzzy_Manobra_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Fuzzy_Manobra_types.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME Fuzzy_Manobra
#define NSAMPLE_TIMES (6) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (29) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (9)   
#elif NCSTATES != 9
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T outputMFCache [ 606 ] ; real_T ha2gv25mhx ; real_T
cdu4i3mgs3 ; real_T npg2rgfpun ; real_T afgd0lhtf4 ; real_T nm5omszfx3 ;
real_T itsvmyrkai ; real_T pg5kicv5em ; real_T oe2lmsiz2a ; real_T kogoh4ns5v
; real_T kbrqy5f52m ; real_T dsmoak2jsv ; real_T ksxfj0gsfv ; real_T
h5uzudgb5w ; real_T fapvpqm3of ; real_T ii0yohmyk1 ; real_T gavabcvo5r ;
real_T hv31qc3uzw ; real_T oevdxkeqby ; real_T pnt2f1gct3 ; real_T pq2bv34fsb
; real_T etvmuhuczs ; real_T pavpjlcqba ; real_T p51nm1vilc ; real_T
olhqar1g4d ; real_T e5b5c1xnq0 ; } B ; typedef struct { real_T f5e2gopavh ;
real_T lpx2pph21r ; real_T adtef5njec ; real_T khlsdoxige ; struct { void *
LoggedData ; } c3dr1neq03 ; struct { void * LoggedData ; } oty2qpav4u ;
struct { void * LoggedData ; } kvmiotlkfk ; struct { void * LoggedData ; }
d5hpzicwc5 ; struct { void * LoggedData ; } jaq2k3c0ms ; struct { void *
LoggedData ; } ithk2wjz3d ; struct { void * LoggedData ; } me34h4u1wh ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } c3wmjp50zt
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
p0h3tkrxan ; struct { void * LoggedData ; } n0epb32tf2 ; int32_T lju2musbk0 ;
int32_T dpg2qc3x1y ; int32_T hfmnviw2hz ; struct { int_T PrevIndex ; }
hs5jgacqs1 ; struct { int_T PrevIndex ; } denj1jmxfa ; int_T hobxq1jfh4 ;
int_T hxoxcp0gyq ; int_T hfipyfd2hy ; int_T huwtgpmegi ; int_T ml4tiyctab ;
int8_T djpwfvqboz ; uint8_T de1hz3dcad ; uint8_T bgdd3ewqlm ; uint8_T
maa5oi5ny5 ; boolean_T garatixfd3 ; boolean_T knd1gqgkyt ; boolean_T
olcxu21tfo ; } DW ; typedef struct { real_T bkcuyngzrw ; real_T cjefnieqjk ;
real_T nteby5pkz0 ; real_T cstdmiz3hi ; real_T hrbxi1qk1v ; real_T mlbbkxddra
; real_T j1ktoc2z4w ; real_T b1haufhayo ; real_T huljek0oib ; } X ; typedef
struct { real_T bkcuyngzrw ; real_T cjefnieqjk ; real_T nteby5pkz0 ; real_T
cstdmiz3hi ; real_T hrbxi1qk1v ; real_T mlbbkxddra ; real_T j1ktoc2z4w ;
real_T b1haufhayo ; real_T huljek0oib ; } XDot ; typedef struct { boolean_T
bkcuyngzrw ; boolean_T cjefnieqjk ; boolean_T nteby5pkz0 ; boolean_T
cstdmiz3hi ; boolean_T hrbxi1qk1v ; boolean_T mlbbkxddra ; boolean_T
j1ktoc2z4w ; boolean_T b1haufhayo ; boolean_T huljek0oib ; } XDis ; typedef
struct { real_T bkcuyngzrw ; real_T cjefnieqjk ; real_T nteby5pkz0 ; real_T
cstdmiz3hi ; real_T hrbxi1qk1v ; real_T mlbbkxddra ; real_T j1ktoc2z4w ;
real_T b1haufhayo ; real_T huljek0oib ; } CStateAbsTol ; typedef struct {
real_T bkcuyngzrw ; real_T cjefnieqjk ; real_T nteby5pkz0 ; real_T cstdmiz3hi
; real_T hrbxi1qk1v ; real_T mlbbkxddra ; real_T j1ktoc2z4w ; real_T
b1haufhayo ; real_T huljek0oib ; } CXPtMin ; typedef struct { real_T
bkcuyngzrw ; real_T cjefnieqjk ; real_T nteby5pkz0 ; real_T cstdmiz3hi ;
real_T hrbxi1qk1v ; real_T mlbbkxddra ; real_T j1ktoc2z4w ; real_T b1haufhayo
; real_T huljek0oib ; } CXPtMax ; typedef struct { real_T mvyu2n24k0 ; real_T
fa1vpeb5nw ; real_T ck5bhvir2s ; real_T lmtcypjwz3 ; real_T n4phtibxxk ;
real_T nhhcjiigkk ; real_T hzosi0qciz ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T I ; real_T
K ; real_T L ; real_T R ; real_T Res ; real_T dl ; real_T m ; real_T t [ 22 ]
; real_T WrapToZero_Threshold ; real_T WrapToZero_Threshold_hg0h5yir2s ;
real_T WrapToZero_Threshold_cssuvfekcn ; real_T WrapToZero1_Threshold ;
real_T OutputSamplePoints_Value [ 202 ] ; real_T Integrator1_IC ; real_T
Integrator2_IC ; real_T Integrator1_IC_exjymra1sd ; real_T Integrator_IC ;
real_T PIdir2_A ; real_T PIdir2_C ; real_T PIdir1_A ; real_T PIdir1_C ;
real_T PIdir_A ; real_T PIdir_C ; real_T PIdir_D ; real_T Saturation_UpperSat
; real_T Saturation_LowerSat ; real_T PIesq_A ; real_T PIesq_C ; real_T
PIesq_D ; real_T Saturation1_UpperSat ; real_T Saturation1_LowerSat ; real_T
Gain_Gain ; real_T Gain1_Gain ; real_T Integrator_IC_la12cpfo5s ; real_T
Yp_Time0 [ 22 ] ; real_T Yp_Data0 [ 22 ] ; real_T Xp_Time0 [ 22 ] ; real_T
Xp_Data0 [ 22 ] ; real_T Gain_Gain_ejiryrm5j4 ; real_T Gain1_Gain_kooogsc14x
; real_T Step1_Y0 ; real_T Step1_YFinal ; real_T Md2_Gain ; real_T Fsr_Gain ;
real_T Fkr_Gain ; real_T Fsl_Gain ; real_T Fkl_Gain ; real_T
Gain1_Gain_i3zbnwm4y2 ; real_T Step1_Y0_j4y32wgs52 ; real_T
Step1_YFinal_a0sklnvnzc ; real_T Step2_Y0 ; real_T Step2_YFinal ; real_T
alphakR_Value ; real_T alphasR_Value ; real_T alphakL_Value ; real_T
alphasL_Value ; real_T Constant_Value ; real_T Constant_Value_ebq3giya5y ;
real_T Constant_Value_dtwdy0lnur ; real_T Constant_Value_gwwlgndyuo ; } ;
extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X
rtX ; extern DW rtDW ; extern P rtP ; extern mxArray *
mr_Fuzzy_Manobra_GetDWork ( ) ; extern void mr_Fuzzy_Manobra_SetDWork ( const
mxArray * ssDW ) ; extern mxArray *
mr_Fuzzy_Manobra_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Fuzzy_Manobra_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
