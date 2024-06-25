#include "ddmr_model.h"
#include "rtwtypes.h"
#include "ddmr_model_private.h"
#include "mwmathutil.h"
#include "ddmr_model_capi.h"
#include <string.h>
#include "rt_nonfinite.h"
static RegMdlInfo rtMdlInfo_ddmr_model [ 43 ] = { { "fy3lu2f2ujv" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "ddmr_model" } , {
"ontpm2umoe" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "lp3zh40upu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "hctcpa1dhr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"hqonyamb22" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "pxzwxnxvl0" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "dzlksfmbtn" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"gecj2ndo0o" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "c1psxaodxu" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "cdpaxobejl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"d10di5dwnm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "hw4wdbuq1y" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "kwiki5iogk" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"gtkzuhqsou" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "fua4ad5tsa" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "g5clpc2dtg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"jpmrxpceej" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "ogkmeckrq1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "ejme0r5xti" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"fbm5qosqr1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "etglvvkmke" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "ccsiudf4i2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mp5i2ytrlb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "mgp3cekyeg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "csc5xjskqr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"ddmr_model" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , {
"bfzo2ow50v" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ddmr_model" } , { "g2entzosis" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1
, ( void * ) "ddmr_model" } , { "nbfwhaflif" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_GetSimStateDisallowedBlocks" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_restoreDataFromMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "ddmr_model" } , { "mr_ddmr_model_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1
, ( void * ) "ddmr_model" } , { "mr_ddmr_model_cacheDataAsMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "ddmr_model" } , { "mr_ddmr_model_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "ddmr_model" } , {
"mr_ddmr_model_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"ddmr_model" } , { "ddmr_model.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
NULL ) } , { "ddmr_model.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"ddmr_model" } } ; icpuq4fzb4u icpuq4fzb4 = { 0.0 , 0.0 , 0.0 , 0.0 , 12.0 ,
- 12.0 , 12.0 , - 12.0 , 0.0 , 0.0 , 0.0 } ; void ccsiudf4i2 ( gecj2ndo0o *
localX ) { localX -> pzv2rcd5p3 = icpuq4fzb4 . P_22 ; localX -> pksuptpva2 =
icpuq4fzb4 . P_23 ; localX -> jiu3tiosns = icpuq4fzb4 . P_20 ; localX ->
oeihruex2h = icpuq4fzb4 . P_21 ; localX -> gcwq0rzs0x = icpuq4fzb4 . P_28 ;
localX -> anftbq5ld3 = icpuq4fzb4 . P_29 ; localX -> mjkavuo234 = icpuq4fzb4
. P_30 ; } void etglvvkmke ( gecj2ndo0o * localX ) { localX -> pzv2rcd5p3 =
icpuq4fzb4 . P_22 ; localX -> pksuptpva2 = icpuq4fzb4 . P_23 ; localX ->
jiu3tiosns = icpuq4fzb4 . P_20 ; localX -> oeihruex2h = icpuq4fzb4 . P_21 ;
localX -> gcwq0rzs0x = icpuq4fzb4 . P_28 ; localX -> anftbq5ld3 = icpuq4fzb4
. P_29 ; localX -> mjkavuo234 = icpuq4fzb4 . P_30 ; } void ddmr_model (
nbfwhaflif * const jn2o1o01kt , const real_T * itj0jtrp1k , const real_T *
j0nttcg11i , real_T * mwayn2s3kl , real_T * db10o5i42b , real_T * iphrzrjdxk
, real_T * ofasstfylr , real_T * jgzbs513aw , gtkzuhqsou * localB ,
kwiki5iogk * localDW , gecj2ndo0o * localX ) { real_T avq4gptqzm_p ; real_T
b4w0nxqur4_p ; real_T d311h3ajxd_p ; real_T d311h3ajxd_tmp ; real_T
d311h3ajxd_tmp_p ; real_T fszl0y11u3_p ; real_T kjpxpwr0qd_p ; real_T
kul5kdondd_p ; real_T kul5kdondd_tmp ; real_T pxmiiniq3s_p ; * ofasstfylr =
localX -> pzv2rcd5p3 ; * jgzbs513aw = localX -> pksuptpva2 ; kul5kdondd_tmp =
* ofasstfylr - * jgzbs513aw ; pxmiiniq3s_p = ( rtP_b - rtP_K_ce * rtP_K_t /
rtP_R_a ) / rtP_N ; avq4gptqzm_p = pxmiiniq3s_p * * ofasstfylr ;
kul5kdondd_tmp *= rtP_R / ( 2.0 * rtP_L ) ; d311h3ajxd_p =
0.0011165420999780646 * rtP_d * rtP_m_c / 0.060024999999999995 ; b4w0nxqur4_p
= d311h3ajxd_p * * jgzbs513aw ; d311h3ajxd_p *= * ofasstfylr ; pxmiiniq3s_p
*= * jgzbs513aw ; kul5kdondd_p = * j0nttcg11i - * jgzbs513aw ; localB ->
gbthkaqigl = ( kul5kdondd_p + localX -> jiu3tiosns ) * rtP_k_p ; if (
ssIsModeUpdateTimeStep ( jn2o1o01kt -> _mdlRefSfcnS ) ) { localDW ->
lj2kgekpia = localB -> gbthkaqigl >= icpuq4fzb4 . P_24 ? 1 : localB ->
gbthkaqigl > icpuq4fzb4 . P_25 ? 0 : - 1 ; } kjpxpwr0qd_p = rtP_alpha_s * *
jgzbs513aw ; fszl0y11u3_p = rtP_alpha_k * * jgzbs513aw ; d311h3ajxd_tmp =
rtP_K_t / rtP_R_a ; d311h3ajxd_tmp_p = rtP_m * rtP_g ; d311h3ajxd_p = ( (
localDW -> lj2kgekpia == 1 ? icpuq4fzb4 . P_24 : localDW -> lj2kgekpia == - 1
? icpuq4fzb4 . P_25 : localB -> gbthkaqigl ) * d311h3ajxd_tmp - (
pxmiiniq3s_p - d311h3ajxd_p * kul5kdondd_tmp ) ) + ( rtP_f_k *
muDoubleScalarTanh ( fszl0y11u3_p ) - rtP_f_s * muDoubleScalarTanh (
kjpxpwr0qd_p ) ) * d311h3ajxd_tmp_p ; pxmiiniq3s_p = * itj0jtrp1k - *
ofasstfylr ; localB -> aei13j5ook = ( pxmiiniq3s_p + localX -> oeihruex2h ) *
rtP_k_p ; if ( ssIsModeUpdateTimeStep ( jn2o1o01kt -> _mdlRefSfcnS ) ) {
localDW -> p41fjzyuly = localB -> aei13j5ook >= icpuq4fzb4 . P_26 ? 1 :
localB -> aei13j5ook > icpuq4fzb4 . P_27 ? 0 : - 1 ; } kjpxpwr0qd_p =
rtP_alpha_s * * ofasstfylr ; fszl0y11u3_p = rtP_alpha_k * * ofasstfylr ;
avq4gptqzm_p = ( ( localDW -> p41fjzyuly == 1 ? icpuq4fzb4 . P_26 : localDW
-> p41fjzyuly == - 1 ? icpuq4fzb4 . P_27 : localB -> aei13j5ook ) *
d311h3ajxd_tmp - ( kul5kdondd_tmp * b4w0nxqur4_p + avq4gptqzm_p ) ) + (
rtP_f_k * muDoubleScalarTanh ( fszl0y11u3_p ) - rtP_f_s * muDoubleScalarTanh
( kjpxpwr0qd_p ) ) * d311h3ajxd_tmp_p ; localB -> eapwhc1h5h = rtP_k_i *
pxmiiniq3s_p ; localB -> msnwbuinml = rtP_k_i * kul5kdondd_p ; b4w0nxqur4_p =
* ofasstfylr + * jgzbs513aw ; localB -> ih3j1abmxn = kul5kdondd_tmp ;
kul5kdondd_p = rtP_R / 2.0 * b4w0nxqur4_p ; if ( rtmIsMajorTimeStep (
jn2o1o01kt ) && rtmIsSampleHit ( jn2o1o01kt , 1 , 0 ) ) { * iphrzrjdxk =
localX -> gcwq0rzs0x ; localB -> drfiacmwy2 = muDoubleScalarSin ( *
iphrzrjdxk ) ; localB -> mk2bq1deqo = muDoubleScalarCos ( * iphrzrjdxk ) ; }
localB -> pwweqf5ezw = localB -> drfiacmwy2 * kul5kdondd_p ; localB ->
hkvnd31gfr = localB -> mk2bq1deqo * kul5kdondd_p ; localB -> fwm3bqoayn = (
rtP_Mn1 * avq4gptqzm_p + rtP_Mn2 * d311h3ajxd_p ) * ( 1.0 / rtP_Md ) ; localB
-> ejkh522khh = ( rtP_Mn1 * d311h3ajxd_p + rtP_Mn2 * avq4gptqzm_p ) * ( 1.0 /
rtP_Md ) ; if ( rtmIsMajorTimeStep ( jn2o1o01kt ) && rtmIsSampleHit (
jn2o1o01kt , 1 , 0 ) ) { * mwayn2s3kl = localX -> anftbq5ld3 ; * db10o5i42b =
localX -> mjkavuo234 ; } } void fbm5qosqr1 ( nbfwhaflif * const jn2o1o01kt )
{ if ( rtmIsMajorTimeStep ( jn2o1o01kt ) ) { if ( memcmp ( jn2o1o01kt ->
nonContDerivSignal [ 0 ] . pCurrVal , jn2o1o01kt -> nonContDerivSignal [ 0 ]
. pPrevVal , jn2o1o01kt -> nonContDerivSignal [ 0 ] . sizeInBytes ) != 0 ) {
( void ) memcpy ( jn2o1o01kt -> nonContDerivSignal [ 0 ] . pPrevVal ,
jn2o1o01kt -> nonContDerivSignal [ 0 ] . pCurrVal , jn2o1o01kt ->
nonContDerivSignal [ 0 ] . sizeInBytes ) ; ssSetSolverNeedsReset ( jn2o1o01kt
-> _mdlRefSfcnS ) ; } if ( memcmp ( jn2o1o01kt -> nonContDerivSignal [ 1 ] .
pCurrVal , jn2o1o01kt -> nonContDerivSignal [ 1 ] . pPrevVal , jn2o1o01kt ->
nonContDerivSignal [ 1 ] . sizeInBytes ) != 0 ) { ( void ) memcpy (
jn2o1o01kt -> nonContDerivSignal [ 1 ] . pPrevVal , jn2o1o01kt ->
nonContDerivSignal [ 1 ] . pCurrVal , jn2o1o01kt -> nonContDerivSignal [ 1 ]
. sizeInBytes ) ; ssSetSolverNeedsReset ( jn2o1o01kt -> _mdlRefSfcnS ) ; } }
} void ejme0r5xti ( gtkzuhqsou * localB , dzlksfmbtn * localXdot ) {
localXdot -> pzv2rcd5p3 = localB -> fwm3bqoayn ; localXdot -> pksuptpva2 =
localB -> ejkh522khh ; localXdot -> jiu3tiosns = localB -> msnwbuinml ;
localXdot -> oeihruex2h = localB -> eapwhc1h5h ; localXdot -> gcwq0rzs0x =
localB -> ih3j1abmxn ; localXdot -> anftbq5ld3 = localB -> hkvnd31gfr ;
localXdot -> mjkavuo234 = localB -> pwweqf5ezw ; } void ogkmeckrq1 (
gtkzuhqsou * localB , ontpm2umoe * localZCSV ) { localZCSV -> kzr1i03iga =
localB -> gbthkaqigl - icpuq4fzb4 . P_24 ; localZCSV -> jyawckbuv0 = localB
-> gbthkaqigl - icpuq4fzb4 . P_25 ; localZCSV -> eoe10dbqd5 = localB ->
aei13j5ook - icpuq4fzb4 . P_26 ; localZCSV -> j0eh0muaok = localB ->
aei13j5ook - icpuq4fzb4 . P_27 ; } void g5clpc2dtg ( nbfwhaflif * const
jn2o1o01kt ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( jn2o1o01kt -> _mdlRefSfcnS , "ddmr_model" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void mp5i2ytrlb (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , nbfwhaflif
* const jn2o1o01kt , gtkzuhqsou * localB , kwiki5iogk * localDW , gecj2ndo0o
* localX , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( (
void * ) jn2o1o01kt , 0 , sizeof ( nbfwhaflif ) ) ; jn2o1o01kt -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; jn2o1o01kt -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; jn2o1o01kt -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( jn2o1o01kt -> _mdlRefSfcnS , "ddmr_model" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> gbthkaqigl = 0.0
; localB -> aei13j5ook = 0.0 ; localB -> eapwhc1h5h = 0.0 ; localB ->
msnwbuinml = 0.0 ; localB -> ih3j1abmxn = 0.0 ; localB -> drfiacmwy2 = 0.0 ;
localB -> pwweqf5ezw = 0.0 ; localB -> mk2bq1deqo = 0.0 ; localB ->
hkvnd31gfr = 0.0 ; localB -> fwm3bqoayn = 0.0 ; localB -> ejkh522khh = 0.0 ;
} ( void ) memset ( ( void * ) localDW , 0 , sizeof ( kwiki5iogk ) ) ;
ddmr_model_InitializeDataMapInfo ( jn2o1o01kt , localDW , localX , sysRanPtr
, contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != (
NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
jn2o1o01kt -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( jn2o1o01kt ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
jn2o1o01kt -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } jn2o1o01kt ->
nonContDerivSignal [ 0 ] . pPrevVal = ( char_T * ) jn2o1o01kt ->
NonContDerivMemory . mr_nonContSig0 ; jn2o1o01kt -> nonContDerivSignal [ 0 ]
. sizeInBytes = ( 1 * sizeof ( real_T ) ) ; jn2o1o01kt -> nonContDerivSignal
[ 0 ] . pCurrVal = ( char_T * ) ( & localB -> mk2bq1deqo ) ; ; jn2o1o01kt ->
nonContDerivSignal [ 1 ] . pPrevVal = ( char_T * ) jn2o1o01kt ->
NonContDerivMemory . mr_nonContSig1 ; jn2o1o01kt -> nonContDerivSignal [ 1 ]
. sizeInBytes = ( 1 * sizeof ( real_T ) ) ; jn2o1o01kt -> nonContDerivSignal
[ 1 ] . pCurrVal = ( char_T * ) ( & localB -> drfiacmwy2 ) ; ; } void
mr_ddmr_model_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName ,
int_T * retVal ) { * retVal = 0 ; { boolean_T regSubmodelsMdlinfo = false ;
ssGetRegSubmodelsMdlinfo ( mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if (
regSubmodelsMdlinfo ) { } } * retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS
, modelName , rtMdlInfo_ddmr_model , 43 ) ; * retVal = 1 ; } static void
mr_ddmr_model_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_ddmr_model_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_ddmr_model_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_ddmr_model_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_ddmr_model_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_ddmr_model_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_ddmr_model_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) ; static uint_T
mr_ddmr_model_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex
i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_ddmr_model_cacheDataToMxArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_ddmr_model_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_ddmr_model_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_ddmr_model_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ddmr_model_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_ddmr_model_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_ddmr_model_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_ddmr_model_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_ddmr_model_GetDWork ( const fy3lu2f2ujv * mdlrefDW ) {
static const char_T * ssDWFieldNames [ 3 ] = { "rtb" , "rtdw" , "NULL->rtzce"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_ddmr_model_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; { static const char_T *
rtdwDataFieldNames [ 2 ] = { "mdlrefDW->rtdw.lj2kgekpia" ,
"mdlrefDW->rtdw.p41fjzyuly" , } ; mxArray * rtdwData = mxCreateStructMatrix (
1 , 1 , 2 , rtdwDataFieldNames ) ; mr_ddmr_model_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( mdlrefDW -> rtdw . lj2kgekpia ) ,
sizeof ( mdlrefDW -> rtdw . lj2kgekpia ) ) ; mr_ddmr_model_cacheDataAsMxArray
( rtdwData , 0 , 1 , ( const void * ) & ( mdlrefDW -> rtdw . p41fjzyuly ) ,
sizeof ( mdlrefDW -> rtdw . p41fjzyuly ) ) ; mxSetFieldByNumber ( ssDW , 0 ,
1 , rtdwData ) ; } ( void ) mdlrefDW ; return ssDW ; } void
mr_ddmr_model_SetDWork ( fy3lu2f2ujv * mdlrefDW , const mxArray * ssDW ) { (
void ) ssDW ; ( void ) mdlrefDW ; mr_ddmr_model_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) )
; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_ddmr_model_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
lj2kgekpia ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw . lj2kgekpia ) )
; mr_ddmr_model_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw .
p41fjzyuly ) , rtdwData , 0 , 1 , sizeof ( mdlrefDW -> rtdw . p41fjzyuly ) )
; } } void mr_ddmr_model_RegisterSimStateChecksum ( SimStruct * S ) { const
uint32_T chksum [ 4 ] = { 289010433U , 3294119579U , 512964631U , 4042525247U
, } ; slmrModelRefRegisterSimStateChecksum ( S , "ddmr_model" , & chksum [ 0
] ) ; } mxArray * mr_ddmr_model_GetSimStateDisallowedBlocks ( ) { return (
NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
