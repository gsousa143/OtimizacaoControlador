#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ddmr_model_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "ddmr_model.h"
#include "ddmr_model_capi.h"
#include "ddmr_model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , 0 ,
TARGET_STRING ( "ddmr_model/Integrator" ) , TARGET_STRING ( "" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 1 , 1 ,
TARGET_STRING ( "ddmr_model/Integrator1" ) , TARGET_STRING ( "" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 2 , 4 ,
TARGET_STRING ( "ddmr_model/Cinematico/Integrator" ) , TARGET_STRING ( "" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 3 , 5 ,
TARGET_STRING ( "ddmr_model/Cinematico/Integrator1" ) , TARGET_STRING ( "" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 4 , 6 ,
TARGET_STRING ( "ddmr_model/Cinematico/Integrator2" ) , TARGET_STRING ( "" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 5 , 3 ,
TARGET_STRING (
"ddmr_model/B_tau/PID Controller/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0
} , { 6 , 2 , TARGET_STRING (
"ddmr_model/B_tau/PID Controller1/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0
} , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1
, 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 4 , 5 , 6 , 3 ,
2 } ;
#ifndef HOST_CAPI_BUILD
static void ddmr_model_InitializeDataAddr ( void * dataAddr [ ] , kwiki5iogk
* localDW , gecj2ndo0o * localX ) { dataAddr [ 0 ] = ( void * ) ( & localX ->
pzv2rcd5p3 ) ; dataAddr [ 1 ] = ( void * ) ( & localX -> pksuptpva2 ) ;
dataAddr [ 2 ] = ( void * ) ( & localX -> gcwq0rzs0x ) ; dataAddr [ 3 ] = (
void * ) ( & localX -> anftbq5ld3 ) ; dataAddr [ 4 ] = ( void * ) ( & localX
-> mjkavuo234 ) ; dataAddr [ 5 ] = ( void * ) ( & localX -> oeihruex2h ) ;
dataAddr [ 6 ] = ( void * ) ( & localX -> jiu3tiosns ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void ddmr_model_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ] ) {
vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void ddmr_model_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3 ] = ( NULL ) ; loggingPtrs
[ 4 ] = ( NULL ) ; loggingPtrs [ 5 ] = ( NULL ) ; loggingPtrs [ 6 ] = ( NULL
) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } } ; static int_T rtContextSystems [ 2 ] ; static
rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 2 ,
rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL )
} , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 7 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
{ 3319140656U , 7147416U , 3800149527U , 1552120772U } , &
mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * ddmr_model_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void ddmr_model_InitializeSystemRan ( nbfwhaflif * const jn2o1o01kt ,
sysRanDType * systemRan [ ] , kwiki5iogk * localDW , int_T systemTid [ ] ,
void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( jn2o1o01kt ) ;
UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = jn2o1o01kt ->
Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ;
rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void ddmr_model_InitializeDataMapInfo ( nbfwhaflif * const jn2o1o01kt ,
kwiki5iogk * localDW , gecj2ndo0o * localX , void * sysRanPtr , int
contextTid ) { rtwCAPI_SetVersion ( jn2o1o01kt -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( jn2o1o01kt -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( jn2o1o01kt -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; ddmr_model_InitializeDataAddr ( jn2o1o01kt ->
DataMapInfo . dataAddress , localDW , localX ) ; rtwCAPI_SetDataAddressMap (
jn2o1o01kt -> DataMapInfo . mmi , jn2o1o01kt -> DataMapInfo . dataAddress ) ;
ddmr_model_InitializeVarDimsAddr ( jn2o1o01kt -> DataMapInfo . vardimsAddress
) ; rtwCAPI_SetVarDimsAddressMap ( jn2o1o01kt -> DataMapInfo . mmi ,
jn2o1o01kt -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath ( jn2o1o01kt
-> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( jn2o1o01kt ->
DataMapInfo . mmi , ( NULL ) ) ; ddmr_model_InitializeLoggingFunctions (
jn2o1o01kt -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs (
jn2o1o01kt -> DataMapInfo . mmi , jn2o1o01kt -> DataMapInfo . loggingPtrs ) ;
rtwCAPI_SetInstanceLoggingInfo ( jn2o1o01kt -> DataMapInfo . mmi , &
jn2o1o01kt -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
jn2o1o01kt -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
jn2o1o01kt -> DataMapInfo . mmi , 0 ) ; ddmr_model_InitializeSystemRan (
jn2o1o01kt , jn2o1o01kt -> DataMapInfo . systemRan , localDW , jn2o1o01kt ->
DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan (
jn2o1o01kt -> DataMapInfo . mmi , jn2o1o01kt -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( jn2o1o01kt -> DataMapInfo . mmi , jn2o1o01kt ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( jn2o1o01kt ->
DataMapInfo . mmi , & jn2o1o01kt -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ddmr_model_host_InitializeDataMapInfo ( ddmr_model_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
