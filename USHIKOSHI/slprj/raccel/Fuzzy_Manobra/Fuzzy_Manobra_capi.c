#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Fuzzy_Manobra_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 22
#endif
#ifndef SS_INT64
#define SS_INT64 23
#endif
#else
#include "builtin_typeid_types.h"
#include "Fuzzy_Manobra.h"
#include "Fuzzy_Manobra_capi.h"
#include "Fuzzy_Manobra_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Derivative" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Saturation" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
4 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Saturation1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Erro wMd" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Erro wMe" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7
, 0 , TARGET_STRING ( "Fuzzy_Manobra/PI dir" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING ( "Fuzzy_Manobra/PI esq" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Zero-Order Hold" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 10 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Zero-Order Hold1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Cinematico/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 12 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Cinematico/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Cinematico/Integrator2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 14 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Cinematico/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Cinematico/Product1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 16 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Controlador fuzzy/Defuzzify Outputs/is_active_c14_fuzwiz" ) ,
TARGET_STRING ( "is_active_c14_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 17 , 0 ,
TARGET_STRING (
"Fuzzy_Manobra/Controlador fuzzy/Evaluate Rule Antecedents/is_active_c11_fuzwiz"
) , TARGET_STRING ( "is_active_c11_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 18 , 0
, TARGET_STRING (
"Fuzzy_Manobra/Controlador fuzzy/Evaluate Rule Consequents/is_active_c15_fuzwiz"
) , TARGET_STRING ( "is_active_c15_fuzwiz" ) , 0 , 1 , 0 , 0 , 0 } , { 19 , 0
, TARGET_STRING ( "Fuzzy_Manobra/Dinamico/gain3" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Add5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem1/Trigonometric Function1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem2/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 23 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem3/Step1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 24 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Step1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2
} , { 25 , 0 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/Step2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Wrap To Zero/FixPt Switch" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Wrap To Zero1/FixPt Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 }
} ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 28 ,
TARGET_STRING ( "Fuzzy_Manobra/Xp" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0
} , { 29 , TARGET_STRING ( "Fuzzy_Manobra/Xp" ) , TARGET_STRING ( "Data0" ) ,
0 , 1 , 0 } , { 30 , TARGET_STRING ( "Fuzzy_Manobra/Yp" ) , TARGET_STRING (
"Time0" ) , 0 , 1 , 0 } , { 31 , TARGET_STRING ( "Fuzzy_Manobra/Yp" ) ,
TARGET_STRING ( "Data0" ) , 0 , 1 , 0 } , { 32 , TARGET_STRING (
"Fuzzy_Manobra/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 33 ,
TARGET_STRING ( "Fuzzy_Manobra/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 34 , TARGET_STRING ( "Fuzzy_Manobra/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"Fuzzy_Manobra/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 36 , TARGET_STRING ( "Fuzzy_Manobra/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"Fuzzy_Manobra/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 38 , TARGET_STRING ( "Fuzzy_Manobra/PI dir" ) , TARGET_STRING ( "A" ) , 0
, 0 , 0 } , { 39 , TARGET_STRING ( "Fuzzy_Manobra/PI dir" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING ( "Fuzzy_Manobra/PI dir" ) ,
TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"Fuzzy_Manobra/PI esq" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 42 ,
TARGET_STRING ( "Fuzzy_Manobra/PI esq" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0
} , { 43 , TARGET_STRING ( "Fuzzy_Manobra/PI esq" ) , TARGET_STRING ( "D" ) ,
0 , 0 , 0 } , { 44 , TARGET_STRING ( "Fuzzy_Manobra/Cinematico/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"Fuzzy_Manobra/Cinematico/Integrator1" ) , TARGET_STRING ( "InitialCondition"
) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"Fuzzy_Manobra/Cinematico/Integrator2" ) , TARGET_STRING ( "InitialCondition"
) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"Fuzzy_Manobra/Controlador fuzzy/Output Sample Points" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 48 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Integrator" ) , TARGET_STRING ( "InitialCondition" )
, 0 , 0 , 0 } , { 49 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Integrator1" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"Fuzzy_Manobra/S5/Md2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 51 ,
TARGET_STRING ( "Fuzzy_Manobra/S6/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 52 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem1/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem1/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 54 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem3/Wrap To Zero" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem3/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 }
, { 56 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem3/Step1" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Wrap To Zero" ) , TARGET_STRING ( "Threshold" ) , 0
, 0 , 0 } , { 58 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/Wrap To Zero1" )
, TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 }
, { 60 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/Step1" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Step2" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 }
, { 62 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/Step2" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/PI dir1" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } ,
{ 64 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/PI dir1" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/PI dir2" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } ,
{ 66 , TARGET_STRING ( "Fuzzy_Manobra/Subsystem4/PI dir2" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Atrito/alphakL" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 68 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Atrito/alphakR" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Atrito/alphasL" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 70 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Atrito/alphasR" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Atrito/Fkl" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 72 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Atrito/Fkr" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Atrito/Fsl" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 74 , TARGET_STRING ( "Fuzzy_Manobra/Dinamico/Atrito/Fsr" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Subsystem/Wrap To Zero" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem3/Wrap To Zero/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Wrap To Zero/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"Fuzzy_Manobra/Subsystem4/Wrap To Zero1/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
"Fuzzy_Manobra/Dinamico/Subsystem/Wrap To Zero/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 80 , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 81 ,
TARGET_STRING ( "K" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING ( "L" ) , 0 , 0 ,
0 } , { 83 , TARGET_STRING ( "R" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING (
"Res" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING ( "dl" ) , 0 , 0 , 0 } , { 86 ,
TARGET_STRING ( "m" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING ( "t" ) , 0 , 1 ,
0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . itsvmyrkai , & rtB . h5uzudgb5w ,
& rtB . fapvpqm3of , & rtB . kogoh4ns5v , & rtB . ksxfj0gsfv , & rtB .
pg5kicv5em , & rtB . kbrqy5f52m , & rtB . oe2lmsiz2a , & rtB . dsmoak2jsv , &
rtB . cdu4i3mgs3 , & rtB . afgd0lhtf4 , & rtB . ii0yohmyk1 , & rtB .
ha2gv25mhx , & rtB . npg2rgfpun , & rtB . gavabcvo5r , & rtB . hv31qc3uzw , &
rtDW . maa5oi5ny5 , & rtDW . bgdd3ewqlm , & rtDW . de1hz3dcad , & rtB .
etvmuhuczs , & rtB . pq2bv34fsb , & rtB . oevdxkeqby , & rtB . nm5omszfx3 , &
rtB . pnt2f1gct3 , & rtB . pavpjlcqba , & rtB . olhqar1g4d , & rtB .
p51nm1vilc , & rtB . e5b5c1xnq0 , & rtP . Xp_Time0 [ 0 ] , & rtP . Xp_Data0 [
0 ] , & rtP . Yp_Time0 [ 0 ] , & rtP . Yp_Data0 [ 0 ] , & rtP . Gain_Gain , &
rtP . Gain1_Gain , & rtP . Saturation_UpperSat , & rtP . Saturation_LowerSat
, & rtP . Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
PIdir_A , & rtP . PIdir_C , & rtP . PIdir_D , & rtP . PIesq_A , & rtP .
PIesq_C , & rtP . PIesq_D , & rtP . Integrator_IC_la12cpfo5s , & rtP .
Integrator1_IC , & rtP . Integrator2_IC , & rtP . OutputSamplePoints_Value [
0 ] , & rtP . Integrator_IC , & rtP . Integrator1_IC_exjymra1sd , & rtP .
Md2_Gain , & rtP . Gain1_Gain_i3zbnwm4y2 , & rtP . Gain_Gain_ejiryrm5j4 , &
rtP . Gain1_Gain_kooogsc14x , & rtP . WrapToZero_Threshold_hg0h5yir2s , & rtP
. Step1_Y0 , & rtP . Step1_YFinal , & rtP . WrapToZero_Threshold_cssuvfekcn ,
& rtP . WrapToZero1_Threshold , & rtP . Step1_Y0_j4y32wgs52 , & rtP .
Step1_YFinal_a0sklnvnzc , & rtP . Step2_Y0 , & rtP . Step2_YFinal , & rtP .
PIdir1_A , & rtP . PIdir1_C , & rtP . PIdir2_A , & rtP . PIdir2_C , & rtP .
alphakL_Value , & rtP . alphakR_Value , & rtP . alphasL_Value , & rtP .
alphasR_Value , & rtP . Fkl_Gain , & rtP . Fkr_Gain , & rtP . Fsl_Gain , &
rtP . Fsr_Gain , & rtP . WrapToZero_Threshold , & rtP .
Constant_Value_ebq3giya5y , & rtP . Constant_Value_dtwdy0lnur , & rtP .
Constant_Value_gwwlgndyuo , & rtP . Constant_Value , & rtP . I , & rtP . K ,
& rtP . L , & rtP . R , & rtP . Res , & rtP . dl , & rtP . m , & rtP . t [ 0
] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 22 , 1 , 2 , 101 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 0.01 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 0
] , ( const void * ) & rtcapiStoredFloats [ 2 ] , ( int8_T ) 1 , ( uint8_T )
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 28 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 52 ,
rtModelParameters , 8 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1252585181U , 2528956502U , 3251025582U , 418537064U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Fuzzy_Manobra_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Fuzzy_Manobra_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Fuzzy_Manobra_host_InitializeDataMapInfo (
Fuzzy_Manobra_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
