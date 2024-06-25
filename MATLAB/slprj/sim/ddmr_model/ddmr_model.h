#ifndef RTW_HEADER_ddmr_model_h_
#define RTW_HEADER_ddmr_model_h_
#ifndef ddmr_model_COMMON_INCLUDES_
#define ddmr_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "ddmr_model_types.h"
#include <string.h>
#include "model_reference_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <stddef.h>
typedef struct { real_T gbthkaqigl ; real_T aei13j5ook ; real_T eapwhc1h5h ;
real_T msnwbuinml ; real_T ih3j1abmxn ; real_T drfiacmwy2 ; real_T pwweqf5ezw
; real_T mk2bq1deqo ; real_T hkvnd31gfr ; real_T fwm3bqoayn ; real_T
ejkh522khh ; } gtkzuhqsou ; typedef struct { int_T lj2kgekpia ; int_T
p41fjzyuly ; } kwiki5iogk ; typedef struct { real_T pzv2rcd5p3 ; real_T
pksuptpva2 ; real_T jiu3tiosns ; real_T oeihruex2h ; real_T gcwq0rzs0x ;
real_T anftbq5ld3 ; real_T mjkavuo234 ; } gecj2ndo0o ; typedef struct {
real_T pzv2rcd5p3 ; real_T pksuptpva2 ; real_T jiu3tiosns ; real_T oeihruex2h
; real_T gcwq0rzs0x ; real_T anftbq5ld3 ; real_T mjkavuo234 ; } dzlksfmbtn ;
typedef struct { boolean_T pzv2rcd5p3 ; boolean_T pksuptpva2 ; boolean_T
jiu3tiosns ; boolean_T oeihruex2h ; boolean_T gcwq0rzs0x ; boolean_T
anftbq5ld3 ; boolean_T mjkavuo234 ; } pxzwxnxvl0 ; typedef struct { real_T
pzv2rcd5p3 ; real_T pksuptpva2 ; real_T jiu3tiosns ; real_T oeihruex2h ;
real_T gcwq0rzs0x ; real_T anftbq5ld3 ; real_T mjkavuo234 ; } hqonyamb22 ;
typedef struct { real_T pzv2rcd5p3 ; real_T pksuptpva2 ; real_T jiu3tiosns ;
real_T oeihruex2h ; real_T gcwq0rzs0x ; real_T anftbq5ld3 ; real_T mjkavuo234
; } hctcpa1dhr ; typedef struct { real_T pzv2rcd5p3 ; real_T pksuptpva2 ;
real_T jiu3tiosns ; real_T oeihruex2h ; real_T gcwq0rzs0x ; real_T anftbq5ld3
; real_T mjkavuo234 ; } lp3zh40upu ; typedef struct { real_T kzr1i03iga ;
real_T jyawckbuv0 ; real_T eoe10dbqd5 ; real_T j0eh0muaok ; } ontpm2umoe ;
struct icpuq4fzb4u_ { real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ;
real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T
P_29 ; real_T P_30 ; } ; struct g2entzosis { struct SimStruct_tag *
_mdlRefSfcnS ; struct { real_T mr_nonContSig0 [ 1 ] ; real_T mr_nonContSig1 [
1 ] ; } NonContDerivMemory ; ssNonContDerivSigInfo nonContDerivSignal [ 2 ] ;
const rtTimingBridge * timingBridge ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; void * dataAddress [
7 ] ; int32_T * vardimsAddress [ 7 ] ; RTWLoggingFcnPtr loggingPtrs [ 7 ] ;
sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ;
struct { int_T mdlref_GlobalTID [ 2 ] ; time_T tStart ; } Timing ; } ;
typedef struct { gtkzuhqsou rtb ; kwiki5iogk rtdw ; nbfwhaflif rtm ; }
fy3lu2f2ujv ; extern real_T rtP_K_ce ; extern real_T rtP_K_t ; extern real_T
rtP_L ; extern real_T rtP_Md ; extern real_T rtP_Mn1 ; extern real_T rtP_Mn2
; extern real_T rtP_N ; extern real_T rtP_R ; extern real_T rtP_R_a ; extern
real_T rtP_alpha_k ; extern real_T rtP_alpha_s ; extern real_T rtP_b ; extern
real_T rtP_d ; extern real_T rtP_f_k ; extern real_T rtP_f_s ; extern real_T
rtP_g ; extern real_T rtP_k_i ; extern real_T rtP_k_p ; extern real_T rtP_m ;
extern real_T rtP_m_c ; extern void mp5i2ytrlb ( SimStruct * _mdlRefSfcnS ,
int_T mdlref_TID0 , int_T mdlref_TID1 , nbfwhaflif * const jn2o1o01kt ,
gtkzuhqsou * localB , kwiki5iogk * localDW , gecj2ndo0o * localX , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern
void mr_ddmr_model_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_ddmr_model_GetDWork (
const fy3lu2f2ujv * mdlrefDW ) ; extern void mr_ddmr_model_SetDWork (
fy3lu2f2ujv * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_ddmr_model_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray *
mr_ddmr_model_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ddmr_model_GetCAPIStaticMap ( void ) ;
extern void ccsiudf4i2 ( gecj2ndo0o * localX ) ; extern void etglvvkmke (
gecj2ndo0o * localX ) ; extern void ejme0r5xti ( gtkzuhqsou * localB ,
dzlksfmbtn * localXdot ) ; extern void ogkmeckrq1 ( gtkzuhqsou * localB ,
ontpm2umoe * localZCSV ) ; extern void fbm5qosqr1 ( nbfwhaflif * const
jn2o1o01kt ) ; extern void ddmr_model ( nbfwhaflif * const jn2o1o01kt , const
real_T * itj0jtrp1k , const real_T * j0nttcg11i , real_T * mwayn2s3kl ,
real_T * db10o5i42b , real_T * iphrzrjdxk , real_T * ofasstfylr , real_T *
jgzbs513aw , gtkzuhqsou * localB , kwiki5iogk * localDW , gecj2ndo0o * localX
) ; extern void g5clpc2dtg ( nbfwhaflif * const jn2o1o01kt ) ;
#endif
