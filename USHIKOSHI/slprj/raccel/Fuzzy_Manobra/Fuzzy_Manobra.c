#include "Fuzzy_Manobra.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include <string.h>
#include "Fuzzy_Manobra_private.h"
#include "rt_logging_mmi.h"
#include "Fuzzy_Manobra_capi.h"
#include "Fuzzy_Manobra_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 5 , &
stopRequested ) ; } rtExtModeShutdown ( 5 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 6 ; const char_T
* gbl_raccel_Version = "23.2 (R2023b) 01-Aug-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 ,
1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S ,
const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define lnfzuqv51n (-1)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T o1w24g03yp ( real_T x , const real_T params [ 4 ] )
; static real_T lzmotnl3qg ( real_T x , const real_T params [ 3 ] ) ; static
void jupuf4kt3o ( const real_T x [ 101 ] , const real_T params [ 4 ] , real_T
y [ 101 ] ) ; static void nuej5g1jmc ( const real_T x [ 101 ] , const real_T
params [ 3 ] , real_T y [ 101 ] ) ; static real_T o1w24g03yp ( real_T x ,
const real_T params [ 4 ] ) { real_T b_x ; real_T b_y ; b_x = 0.0 ; b_y = 0.0
; if ( x >= params [ 1 ] ) { b_x = 1.0 ; } if ( x < params [ 0 ] ) { b_x =
0.0 ; } if ( ( params [ 0 ] <= x ) && ( x < params [ 1 ] ) && ( params [ 0 ]
!= params [ 1 ] ) ) { b_x = 1.0 / ( params [ 1 ] - params [ 0 ] ) * ( x -
params [ 0 ] ) ; } if ( x <= params [ 2 ] ) { b_y = 1.0 ; } if ( x > params [
3 ] ) { b_y = 0.0 ; } if ( ( params [ 2 ] < x ) && ( x <= params [ 3 ] ) && (
params [ 2 ] != params [ 3 ] ) ) { b_y = 1.0 / ( params [ 3 ] - params [ 2 ]
) * ( params [ 3 ] - x ) ; } return muDoubleScalarMin ( b_x , b_y ) ; }
static real_T lzmotnl3qg ( real_T x , const real_T params [ 3 ] ) { real_T y
; y = 0.0 ; if ( ( params [ 0 ] != params [ 1 ] ) && ( params [ 0 ] < x ) &&
( x < params [ 1 ] ) ) { y = 1.0 / ( params [ 1 ] - params [ 0 ] ) * ( x -
params [ 0 ] ) ; } if ( ( params [ 1 ] != params [ 2 ] ) && ( params [ 1 ] <
x ) && ( x < params [ 2 ] ) ) { y = 1.0 / ( params [ 2 ] - params [ 1 ] ) * (
params [ 2 ] - x ) ; } if ( x == params [ 1 ] ) { y = 1.0 ; } return y ; }
static void jupuf4kt3o ( const real_T x [ 101 ] , const real_T params [ 4 ] ,
real_T y [ 101 ] ) { real_T a ; real_T b ; real_T b_y1 ; real_T c ; real_T d
; real_T x_p ; real_T y2 ; int32_T i ; a = params [ 0 ] ; b = params [ 1 ] ;
c = params [ 2 ] ; d = params [ 3 ] ; for ( i = 0 ; i < 101 ; i ++ ) { b_y1 =
0.0 ; y2 = 0.0 ; x_p = x [ i ] ; if ( x_p >= b ) { b_y1 = 1.0 ; } if ( x_p <
a ) { b_y1 = 0.0 ; } if ( ( a <= x_p ) && ( x_p < b ) ) { b_y1 = 1.0 / ( b -
a ) * ( x_p - a ) ; } if ( x_p <= c ) { y2 = 1.0 ; } if ( x_p > d ) { y2 =
0.0 ; } if ( ( c < x_p ) && ( x_p <= d ) ) { y2 = 1.0 / ( d - c ) * ( d - x_p
) ; } y [ i ] = muDoubleScalarMin ( b_y1 , y2 ) ; } } static void nuej5g1jmc
( const real_T x [ 101 ] , const real_T params [ 3 ] , real_T y [ 101 ] ) {
real_T a ; real_T b ; real_T c ; real_T x_p ; int32_T i ; a = params [ 0 ] ;
b = params [ 1 ] ; c = params [ 2 ] ; for ( i = 0 ; i < 101 ; i ++ ) { y [ i
] = 0.0 ; if ( a != b ) { x_p = x [ i ] ; if ( ( a < x_p ) && ( x_p < b ) ) {
y [ i ] = 1.0 / ( b - a ) * ( x_p - a ) ; } } if ( b != c ) { x_p = x [ i ] ;
if ( ( b < x_p ) && ( x_p < c ) ) { y [ i ] = 1.0 / ( c - b ) * ( c - x_p ) ;
} } if ( x [ i ] == b ) { y [ i ] = 1.0 ; } } } void MdlInitialize ( void ) {
rtX . bkcuyngzrw = rtP . Integrator1_IC ; rtX . cjefnieqjk = rtP .
Integrator2_IC ; rtX . nteby5pkz0 = rtP . Integrator1_IC_exjymra1sd ; rtX .
cstdmiz3hi = rtP . Integrator_IC ; rtDW . f5e2gopavh = ( rtInf ) ; rtDW .
adtef5njec = ( rtInf ) ; rtX . hrbxi1qk1v = 0.0 ; rtX . mlbbkxddra = 0.0 ;
rtX . j1ktoc2z4w = 0.0 ; rtX . b1haufhayo = 0.0 ; rtX . huljek0oib = rtP .
Integrator_IC_la12cpfo5s ; rtDW . knd1gqgkyt = false ; rtDW . dpg2qc3x1y =
lnfzuqv51n ; rtDW . garatixfd3 = false ; rtDW . lju2musbk0 = lnfzuqv51n ;
rtDW . olcxu21tfo = false ; rtDW . hfmnviw2hz = lnfzuqv51n ; } void MdlStart
( void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { int_T numCols = 2 ; rtDW . c3dr1neq03 . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "saix" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , (
int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.01 , 1
) ; if ( rtDW . c3dr1neq03 . LoggedData == ( NULL ) ) return ; } { int_T
numCols = 2 ; rtDW . oty2qpav4u . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "saiy" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , (
int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.01 , 1
) ; if ( rtDW . oty2qpav4u . LoggedData == ( NULL ) ) return ; } { int_T
numCols = 2 ; rtDW . kvmiotlkfk . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "dv" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , ( int_T
* ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if
( rtDW . kvmiotlkfk . LoggedData == ( NULL ) ) return ; } { int_T numCols = 2
; rtDW . d5hpzicwc5 . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS )
, ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus (
rtS ) ) , "ud" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , ( int_T * ) & numCols ,
NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW .
d5hpzicwc5 . LoggedData == ( NULL ) ) return ; } { int_T numCols = 2 ; rtDW .
jaq2k3c0ms . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "ue" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , ( int_T * ) & numCols ,
NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW .
jaq2k3c0ms . LoggedData == ( NULL ) ) return ; } { int_T numCols = 2 ; rtDW .
ithk2wjz3d . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "wd" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , ( int_T * ) & numCols ,
NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW .
ithk2wjz3d . LoggedData == ( NULL ) ) return ; } { int_T numCols = 2 ; rtDW .
me34h4u1wh . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "we" , SS_DOUBLE , 0 , 0 , 0 , 2 , 1 , ( int_T * ) & numCols ,
NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW .
me34h4u1wh . LoggedData == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ;
if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == (
NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[t y_pos]" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . Yp_Data0 ; fromwksInfo -> nDataPoints = 22 ;
fromwksInfo -> time = ( double * ) rtP . Yp_Time0 ; rtDW . c3wmjp50zt .
TimePtr = fromwksInfo -> time ; rtDW . c3wmjp50zt . DataPtr = fromwksInfo ->
data ; rtDW . c3wmjp50zt . RSimInfoPtr = fromwksInfo ; } rtDW . hs5jgacqs1 .
PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo
* ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus (
rtS , "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[t x_pos]" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . Xp_Data0 ; fromwksInfo -> nDataPoints = 22 ;
fromwksInfo -> time = ( double * ) rtP . Xp_Time0 ; rtDW . p0h3tkrxan .
TimePtr = fromwksInfo -> time ; rtDW . p0h3tkrxan . DataPtr = fromwksInfo ->
data ; rtDW . p0h3tkrxan . RSimInfoPtr = fromwksInfo ; } rtDW . denj1jmxfa .
PrevIndex = 0 ; } rtDW . djpwfvqboz = 0 ; MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T lttlhgttza ; real_T hgqt2wm4kb ; real_T
aymfzsgtuq [ 202 ] ; real_T tmp_e [ 101 ] ; real_T tmp_p [ 101 ] ; real_T
inputMFCache [ 9 ] ; real_T i5vbei3ug5 [ 8 ] ; real_T tmp [ 3 ] ; real_T
bhqctezedp [ 2 ] ; real_T afaxfqw1pt ; real_T d4p5zabp4k ; real_T eutgil4uho
; real_T g24mve5mtj ; real_T ixuljuor35 ; real_T maxValueInX ; real_T
nojqk5qdgj ; real_T ozg2sabd4s ; real_T pthut1oi4n ; real_T * lastU ; int32_T
idx ; int32_T sampleID ; int_T iy ; int8_T j ; static const real_T b [ 4 ] =
{ - 3.141 , - 2.844 , - 1.605 , - 1.57 } ; static const real_T c [ 4 ] = { -
1.606 , - 1.571 , - 0.4999 , - 0.01 } ; static const real_T d [ 4 ] = { 0.01
, 0.4999 , 1.57 , 1.606 } ; static const real_T e [ 4 ] = { 1.57 , 1.605 ,
2.844 , 3.141 } ; static const real_T f [ 3 ] = { - 3.149 , - 3.141 , - 3.0 }
; static const real_T g [ 3 ] = { 3.0 , 3.141 , 3.149 } ; static const real_T
h [ 4 ] = { - 1.8 , - 0.2 , 0.01 , 0.02 } ; static const real_T i [ 4 ] = {
0.01 , 0.02 , 7.0 , 7.5 } ; static const int8_T j_p [ 16 ] = { 0 , 6 , 1 , 2
, 3 , 4 , 5 , 7 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 } ; static const real_T b_p [
4 ] = { - 0.24 , - 0.1 , - 0.02 , 0.0 } ; static const real_T c_p [ 4 ] = {
0.0 , 0.02 , 0.1 , 0.24 } ; static const real_T d_p [ 3 ] = { - 1.18 , - 0.5
, - 0.0119 } ; static const real_T e_p [ 3 ] = { - 0.499 , 0.0 , 0.5014 } ;
static const real_T f_p [ 3 ] = { 0.0119 , 0.5 , 1.18 } ; static const int8_T
g_p [ 16 ] = { 3 , 1 , 3 , 3 , 2 , 3 , 3 , 1 , 2 , 2 , 3 , 1 , 2 , 3 , 1 , 2
} ; boolean_T exitg1 ; rtB . ha2gv25mhx = rtX . bkcuyngzrw ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . cdu4i3mgs3 = rtB . ha2gv25mhx ; if (
ssGetLogOutput ( rtS ) ) { real_T u [ 2 ] ; u [ 0 ] = ssGetTaskTime ( rtS , 2
) ; u [ 1 ] = rtB . cdu4i3mgs3 ; rt_UpdateLogVar ( ( LogVar * ) rtDW .
c3dr1neq03 . LoggedData , u , 0 ) ; } } rtB . npg2rgfpun = rtX . cjefnieqjk ;
if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . afgd0lhtf4 = rtB . npg2rgfpun ;
if ( ssGetLogOutput ( rtS ) ) { real_T u [ 2 ] ; u [ 0 ] = ssGetTaskTime (
rtS , 2 ) ; u [ 1 ] = rtB . afgd0lhtf4 ; rt_UpdateLogVar ( ( LogVar * ) rtDW
. oty2qpav4u . LoggedData , u , 0 ) ; } } ozg2sabd4s = rtX . nteby5pkz0 ;
d4p5zabp4k = rtX . cstdmiz3hi ; ixuljuor35 = rtP . L * rtX . cstdmiz3hi ;
nojqk5qdgj = 1.0 / rtP . R * ( rtX . nteby5pkz0 + ixuljuor35 ) ; g24mve5mtj =
nojqk5qdgj ; if ( nojqk5qdgj > rtP . WrapToZero_Threshold ) { g24mve5mtj =
rtP . Constant_Value ; } ixuljuor35 = 1.0 / rtP . R * ( rtX . nteby5pkz0 -
ixuljuor35 ) ; rtB . nm5omszfx3 = rtP . R / 2.0 * ( g24mve5mtj + ixuljuor35 )
; if ( ( rtDW . f5e2gopavh >= ssGetT ( rtS ) ) && ( rtDW . adtef5njec >=
ssGetT ( rtS ) ) ) { rtB . itsvmyrkai = 0.0 ; } else { afaxfqw1pt = rtDW .
f5e2gopavh ; lastU = & rtDW . lpx2pph21r ; if ( rtDW . f5e2gopavh < rtDW .
adtef5njec ) { if ( rtDW . adtef5njec < ssGetT ( rtS ) ) { afaxfqw1pt = rtDW
. adtef5njec ; lastU = & rtDW . khlsdoxige ; } } else if ( rtDW . f5e2gopavh
>= ssGetT ( rtS ) ) { afaxfqw1pt = rtDW . adtef5njec ; lastU = & rtDW .
khlsdoxige ; } rtB . itsvmyrkai = ( rtB . nm5omszfx3 - * lastU ) / ( ssGetT (
rtS ) - afaxfqw1pt ) ; } if ( ssGetLogOutput ( rtS ) ) { real_T u [ 2 ] ; u [
0 ] = ssGetTaskTime ( rtS , 0 ) ; u [ 1 ] = rtB . itsvmyrkai ;
rt_UpdateLogVar ( ( LogVar * ) rtDW . kvmiotlkfk . LoggedData , u , 0 ) ; }
pthut1oi4n = rtP . L / rtP . R * ( rtP . PIdir2_C * rtX . hrbxi1qk1v ) ;
eutgil4uho = 1.0 / rtP . R * ( rtP . PIdir1_C * rtX . mlbbkxddra ) ; rtB .
pg5kicv5em = ( pthut1oi4n + eutgil4uho ) - g24mve5mtj ; rtB . oe2lmsiz2a =
0.0 ; rtB . oe2lmsiz2a += rtP . PIdir_C * rtX . j1ktoc2z4w ; rtB . oe2lmsiz2a
+= rtP . PIdir_D * rtB . pg5kicv5em ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
rtDW . hobxq1jfh4 = rtB . oe2lmsiz2a >= rtP . Saturation_UpperSat ? 1 : rtB .
oe2lmsiz2a > rtP . Saturation_LowerSat ? 0 : - 1 ; } rtB . kogoh4ns5v = rtDW
. hobxq1jfh4 == 1 ? rtP . Saturation_UpperSat : rtDW . hobxq1jfh4 == - 1 ?
rtP . Saturation_LowerSat : rtB . oe2lmsiz2a ; if ( ssGetLogOutput ( rtS ) )
{ real_T u [ 2 ] ; u [ 0 ] = ssGetTaskTime ( rtS , 0 ) ; u [ 1 ] = rtB .
kogoh4ns5v ; rt_UpdateLogVar ( ( LogVar * ) rtDW . d5hpzicwc5 . LoggedData ,
u , 0 ) ; } rtB . kbrqy5f52m = ( eutgil4uho - pthut1oi4n ) - ixuljuor35 ; rtB
. dsmoak2jsv = 0.0 ; rtB . dsmoak2jsv += rtP . PIesq_C * rtX . b1haufhayo ;
rtB . dsmoak2jsv += rtP . PIesq_D * rtB . kbrqy5f52m ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . hxoxcp0gyq = rtB . dsmoak2jsv >=
rtP . Saturation1_UpperSat ? 1 : rtB . dsmoak2jsv > rtP .
Saturation1_LowerSat ? 0 : - 1 ; } rtB . ksxfj0gsfv = rtDW . hxoxcp0gyq == 1
? rtP . Saturation1_UpperSat : rtDW . hxoxcp0gyq == - 1 ? rtP .
Saturation1_LowerSat : rtB . dsmoak2jsv ; if ( ssGetLogOutput ( rtS ) ) {
real_T u [ 2 ] ; u [ 0 ] = ssGetTaskTime ( rtS , 0 ) ; u [ 1 ] = rtB .
ksxfj0gsfv ; rt_UpdateLogVar ( ( LogVar * ) rtDW . jaq2k3c0ms . LoggedData ,
u , 0 ) ; } rtB . h5uzudgb5w = rtP . Gain_Gain * g24mve5mtj ; if (
ssGetLogOutput ( rtS ) ) { real_T u [ 2 ] ; u [ 0 ] = ssGetTaskTime ( rtS , 0
) ; u [ 1 ] = rtB . h5uzudgb5w ; rt_UpdateLogVar ( ( LogVar * ) rtDW .
ithk2wjz3d . LoggedData , u , 0 ) ; } rtB . fapvpqm3of = rtP . Gain1_Gain *
ixuljuor35 ; if ( ssGetLogOutput ( rtS ) ) { real_T u [ 2 ] ; u [ 0 ] =
ssGetTaskTime ( rtS , 0 ) ; u [ 1 ] = rtB . fapvpqm3of ; rt_UpdateLogVar ( (
LogVar * ) rtDW . me34h4u1wh . LoggedData , u , 0 ) ; } rtB . ii0yohmyk1 =
rtP . R / ( 2.0 * rtP . L ) * ( g24mve5mtj - ixuljuor35 ) ; eutgil4uho = rtP
. R / 2.0 * ( g24mve5mtj + ixuljuor35 ) ; rtB . gavabcvo5r =
muDoubleScalarSin ( rtX . huljek0oib ) * eutgil4uho ; rtB . hv31qc3uzw =
muDoubleScalarCos ( rtX . huljek0oib ) * eutgil4uho ; { real_T * pDataValues
= ( real_T * ) rtDW . c3wmjp50zt . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . c3wmjp50zt . TimePtr ; int_T currTimeIndex = rtDW . hs5jgacqs1 .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . c3wmjp50zt . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . hs5jgacqs1 . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { lttlhgttza =
pDataValues [ currTimeIndex ] ; } else { lttlhgttza = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; lttlhgttza = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } afaxfqw1pt = lttlhgttza - rtB . npg2rgfpun ;
{ real_T * pDataValues = ( real_T * ) rtDW . p0h3tkrxan . DataPtr ; real_T *
pTimeValues = ( real_T * ) rtDW . p0h3tkrxan . TimePtr ; int_T currTimeIndex
= rtDW . denj1jmxfa . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
p0h3tkrxan . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . denj1jmxfa .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { hgqt2wm4kb = pDataValues [ currTimeIndex ] ; } else { hgqt2wm4kb =
pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2
- t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; hgqt2wm4kb = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } pthut1oi4n = hgqt2wm4kb - rtB . ha2gv25mhx ;
rtB . oevdxkeqby = muDoubleScalarAtan2 ( afaxfqw1pt , pthut1oi4n ) ;
bhqctezedp [ 0 ] = muDoubleScalarAtan ( muDoubleScalarTan ( ( rtB .
oevdxkeqby - rtX . huljek0oib ) * rtP . Gain_Gain_ejiryrm5j4 ) ) * rtP .
Gain1_Gain_kooogsc14x ; afaxfqw1pt = pthut1oi4n * pthut1oi4n + afaxfqw1pt *
afaxfqw1pt ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . djpwfvqboz != 0 )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
djpwfvqboz = 0 ; } pthut1oi4n = muDoubleScalarSqrt ( afaxfqw1pt ) ; } else if
( afaxfqw1pt < 0.0 ) { pthut1oi4n = - muDoubleScalarSqrt ( muDoubleScalarAbs
( afaxfqw1pt ) ) ; rtDW . djpwfvqboz = 1 ; } else { pthut1oi4n =
muDoubleScalarSqrt ( afaxfqw1pt ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtDW . hfipyfd2hy = ( ssGetTaskTime ( rtS , 1 ) >= rtP . t [ 20 ] ) ; if (
rtDW . hfipyfd2hy == 1 ) { rtB . pnt2f1gct3 = rtP . Step1_YFinal ; } else {
rtB . pnt2f1gct3 = rtP . Step1_Y0 ; } } afaxfqw1pt = pthut1oi4n + rtB .
pnt2f1gct3 ; if ( afaxfqw1pt > rtP . WrapToZero_Threshold_hg0h5yir2s ) {
bhqctezedp [ 1 ] = rtP . Constant_Value_ebq3giya5y ; } else { bhqctezedp [ 1
] = afaxfqw1pt ; } rtDW . dpg2qc3x1y = lnfzuqv51n ; eutgil4uho = 0.0 ;
inputMFCache [ 0 ] = o1w24g03yp ( bhqctezedp [ 0 ] , b ) ; inputMFCache [ 1 ]
= o1w24g03yp ( bhqctezedp [ 0 ] , c ) ; tmp [ 0 ] = - 0.141 ; tmp [ 1 ] = 0.0
; tmp [ 2 ] = 0.141 ; inputMFCache [ 2 ] = lzmotnl3qg ( bhqctezedp [ 0 ] ,
tmp ) ; inputMFCache [ 3 ] = o1w24g03yp ( bhqctezedp [ 0 ] , d ) ;
inputMFCache [ 4 ] = o1w24g03yp ( bhqctezedp [ 0 ] , e ) ; inputMFCache [ 5 ]
= lzmotnl3qg ( bhqctezedp [ 0 ] , f ) ; inputMFCache [ 6 ] = lzmotnl3qg (
bhqctezedp [ 0 ] , g ) ; inputMFCache [ 7 ] = o1w24g03yp ( bhqctezedp [ 1 ] ,
h ) ; inputMFCache [ 8 ] = o1w24g03yp ( bhqctezedp [ 1 ] , i ) ; for ( idx =
0 ; idx < 8 ; idx ++ ) { i5vbei3ug5 [ idx ] = 1.0 ; for ( iy = 0 ; iy < 2 ;
iy ++ ) { j = j_p [ ( iy << 3 ) + idx ] ; if ( j != 0 ) { bhqctezedp [ 1 ] =
inputMFCache [ ( 7 * iy + j ) - 1 ] ; if ( i5vbei3ug5 [ idx ] > bhqctezedp [
1 ] ) { i5vbei3ug5 [ idx ] = bhqctezedp [ 1 ] ; } } } eutgil4uho +=
i5vbei3ug5 [ idx ] ; } rtDW . lju2musbk0 = lnfzuqv51n ; memset ( & aymfzsgtuq
[ 0 ] , 0 , 202U * sizeof ( real_T ) ) ; for ( idx = 0 ; idx < 101 ; idx ++ )
{ tmp_p [ idx ] = rtP . OutputSamplePoints_Value [ idx << 1 ] ; } jupuf4kt3o
( tmp_p , b_p , tmp_e ) ; for ( idx = 0 ; idx < 101 ; idx ++ ) { rtB .
outputMFCache [ 6 * idx ] = tmp_e [ idx ] ; } for ( idx = 0 ; idx < 101 ; idx
++ ) { tmp_p [ idx ] = rtP . OutputSamplePoints_Value [ idx << 1 ] ; }
jupuf4kt3o ( tmp_p , c_p , tmp_e ) ; for ( idx = 0 ; idx < 101 ; idx ++ ) {
rtB . outputMFCache [ 6 * idx + 1 ] = tmp_e [ idx ] ; } for ( idx = 0 ; idx <
101 ; idx ++ ) { tmp_p [ idx ] = rtP . OutputSamplePoints_Value [ idx << 1 ]
; } tmp [ 0 ] = - 0.02 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] = 0.02 ; nuej5g1jmc (
tmp_p , tmp , tmp_e ) ; for ( idx = 0 ; idx < 101 ; idx ++ ) { rtB .
outputMFCache [ 6 * idx + 2 ] = tmp_e [ idx ] ; } for ( idx = 0 ; idx < 101 ;
idx ++ ) { tmp_p [ idx ] = rtP . OutputSamplePoints_Value [ ( idx << 1 ) + 1
] ; } nuej5g1jmc ( tmp_p , d_p , tmp_e ) ; for ( idx = 0 ; idx < 101 ; idx ++
) { rtB . outputMFCache [ 6 * idx + 3 ] = tmp_e [ idx ] ; } for ( idx = 0 ;
idx < 101 ; idx ++ ) { tmp_p [ idx ] = rtP . OutputSamplePoints_Value [ ( idx
<< 1 ) + 1 ] ; } nuej5g1jmc ( tmp_p , e_p , tmp_e ) ; for ( idx = 0 ; idx <
101 ; idx ++ ) { rtB . outputMFCache [ 6 * idx + 4 ] = tmp_e [ idx ] ; } for
( idx = 0 ; idx < 101 ; idx ++ ) { tmp_p [ idx ] = rtP .
OutputSamplePoints_Value [ ( idx << 1 ) + 1 ] ; } nuej5g1jmc ( tmp_p , f_p ,
tmp_e ) ; for ( idx = 0 ; idx < 101 ; idx ++ ) { rtB . outputMFCache [ 6 *
idx + 5 ] = tmp_e [ idx ] ; } for ( iy = 0 ; iy < 2 ; iy ++ ) { for ( idx = 0
; idx < 8 ; idx ++ ) { for ( sampleID = 0 ; sampleID < 101 ; sampleID ++ ) {
bhqctezedp [ 0 ] = rtB . outputMFCache [ ( ( g_p [ ( iy << 3 ) + idx ] + 3 *
iy ) + 6 * sampleID ) - 1 ] ; bhqctezedp [ 1 ] = i5vbei3ug5 [ idx ] ; if ( (
bhqctezedp [ 0 ] > bhqctezedp [ 1 ] ) || muDoubleScalarIsNaN ( bhqctezedp [ 0
] ) ) { afaxfqw1pt = bhqctezedp [ 1 ] ; } else { afaxfqw1pt = bhqctezedp [ 0
] ; } if ( aymfzsgtuq [ 101 * iy + sampleID ] < afaxfqw1pt ) { aymfzsgtuq [
sampleID + 101 * iy ] = afaxfqw1pt ; } } } } rtDW . hfmnviw2hz = lnfzuqv51n ;
if ( eutgil4uho == 0.0 ) { bhqctezedp [ 0 ] = 0.0 ; bhqctezedp [ 1 ] = 0.0 ;
} else { for ( iy = 0 ; iy < 2 ; iy ++ ) { if ( ! muDoubleScalarIsNaN (
aymfzsgtuq [ 101 * iy ] ) ) { idx = 1 ; } else { idx = 0 ; sampleID = 2 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( sampleID < 102 ) ) { if ( !
muDoubleScalarIsNaN ( aymfzsgtuq [ ( 101 * iy + sampleID ) - 1 ] ) ) { idx =
sampleID ; exitg1 = true ; } else { sampleID ++ ; } } } if ( idx == 0 ) {
afaxfqw1pt = aymfzsgtuq [ 101 * iy ] ; } else { afaxfqw1pt = aymfzsgtuq [ (
101 * iy + idx ) - 1 ] ; for ( sampleID = idx + 1 ; sampleID < 102 ; sampleID
++ ) { pthut1oi4n = aymfzsgtuq [ ( 101 * iy + sampleID ) - 1 ] ; if (
afaxfqw1pt < pthut1oi4n ) { afaxfqw1pt = pthut1oi4n ; } } } pthut1oi4n = 0.0
; eutgil4uho = 0.0 ; for ( idx = 0 ; idx < 101 ; idx ++ ) { maxValueInX = 0.0
; j = 0 ; if ( aymfzsgtuq [ 101 * iy + idx ] == afaxfqw1pt ) { maxValueInX =
rtP . OutputSamplePoints_Value [ ( idx << 1 ) + iy ] ; j = 1 ; } pthut1oi4n
+= maxValueInX ; eutgil4uho += ( real_T ) j ; } bhqctezedp [ iy ] = 1.0 /
eutgil4uho * pthut1oi4n ; } } nojqk5qdgj = ( ( rtP . K / rtP . Res * rtB .
kogoh4ns5v - rtP . Md2_Gain * g24mve5mtj ) - ( muDoubleScalarTanh (
nojqk5qdgj * rtP . alphasR_Value ) * rtP . Fsr_Gain - muDoubleScalarTanh (
nojqk5qdgj * rtP . alphakR_Value ) * rtP . Fkr_Gain ) ) * ( 1.0 / rtP . R ) ;
g24mve5mtj = nojqk5qdgj - ( ( rtP . K / rtP . Res * rtB . ksxfj0gsfv - rtP .
Gain1_Gain_i3zbnwm4y2 * ixuljuor35 ) - ( muDoubleScalarTanh ( ixuljuor35 *
rtP . alphasL_Value ) * rtP . Fsl_Gain - muDoubleScalarTanh ( ixuljuor35 *
rtP . alphakL_Value ) * rtP . Fkl_Gain ) ) * ( 1.0 / rtP . R ) ; rtB .
pq2bv34fsb = 1.0 / rtP . m * ( nojqk5qdgj + g24mve5mtj ) + d4p5zabp4k *
d4p5zabp4k * rtP . dl ; rtB . etvmuhuczs = ( rtP . L * g24mve5mtj - rtP . m *
rtP . dl * ( d4p5zabp4k * ozg2sabd4s ) ) * ( 1.0 / rtP . I ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . huwtgpmegi = ( ssGetTaskTime ( rtS ,
1 ) >= rtP . t [ 20 ] ) ; if ( rtDW . huwtgpmegi == 1 ) { rtB . pavpjlcqba =
rtP . Step1_YFinal_a0sklnvnzc ; } else { rtB . pavpjlcqba = rtP .
Step1_Y0_j4y32wgs52 ; } } ozg2sabd4s = bhqctezedp [ 0 ] + rtB . pavpjlcqba ;
if ( ozg2sabd4s > rtP . WrapToZero_Threshold_cssuvfekcn ) { rtB . p51nm1vilc
= rtP . Constant_Value_dtwdy0lnur ; } else { rtB . p51nm1vilc = ozg2sabd4s ;
} if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . ml4tiyctab = ( ssGetTaskTime
( rtS , 1 ) >= rtP . t [ 20 ] ) ; if ( rtDW . ml4tiyctab == 1 ) { rtB .
olhqar1g4d = rtP . Step2_YFinal ; } else { rtB . olhqar1g4d = rtP . Step2_Y0
; } } ozg2sabd4s = bhqctezedp [ 1 ] + rtB . olhqar1g4d ; if ( ozg2sabd4s >
rtP . WrapToZero1_Threshold ) { rtB . e5b5c1xnq0 = rtP .
Constant_Value_gwwlgndyuo ; } else { rtB . e5b5c1xnq0 = ozg2sabd4s ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID5 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
if ( rtDW . f5e2gopavh == ( rtInf ) ) { rtDW . f5e2gopavh = ssGetT ( rtS ) ;
lastU = & rtDW . lpx2pph21r ; } else if ( rtDW . adtef5njec == ( rtInf ) ) {
rtDW . adtef5njec = ssGetT ( rtS ) ; lastU = & rtDW . khlsdoxige ; } else if
( rtDW . f5e2gopavh < rtDW . adtef5njec ) { rtDW . f5e2gopavh = ssGetT ( rtS
) ; lastU = & rtDW . lpx2pph21r ; } else { rtDW . adtef5njec = ssGetT ( rtS )
; lastU = & rtDW . khlsdoxige ; } * lastU = rtB . nm5omszfx3 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID5 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> bkcuyngzrw = rtB .
hv31qc3uzw ; _rtXdot -> cjefnieqjk = rtB . gavabcvo5r ; _rtXdot -> nteby5pkz0
= rtB . pq2bv34fsb ; _rtXdot -> cstdmiz3hi = rtB . etvmuhuczs ; _rtXdot ->
hrbxi1qk1v = rtP . PIdir2_A * rtX . hrbxi1qk1v ; _rtXdot -> hrbxi1qk1v += rtB
. e5b5c1xnq0 ; _rtXdot -> mlbbkxddra = rtP . PIdir1_A * rtX . mlbbkxddra ;
_rtXdot -> mlbbkxddra += rtB . p51nm1vilc ; _rtXdot -> j1ktoc2z4w = rtP .
PIdir_A * rtX . j1ktoc2z4w ; _rtXdot -> j1ktoc2z4w += rtB . pg5kicv5em ;
_rtXdot -> b1haufhayo = rtP . PIesq_A * rtX . b1haufhayo ; _rtXdot ->
b1haufhayo += rtB . kbrqy5f52m ; _rtXdot -> huljek0oib = rtB . ii0yohmyk1 ; }
void MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> mvyu2n24k0 = rtB . oe2lmsiz2a - rtP . Saturation_UpperSat ; _rtZCSV ->
fa1vpeb5nw = rtB . oe2lmsiz2a - rtP . Saturation_LowerSat ; _rtZCSV ->
ck5bhvir2s = rtB . dsmoak2jsv - rtP . Saturation1_UpperSat ; _rtZCSV ->
lmtcypjwz3 = rtB . dsmoak2jsv - rtP . Saturation1_LowerSat ; _rtZCSV ->
n4phtibxxk = ssGetT ( rtS ) - rtP . t [ 20 ] ; _rtZCSV -> nhhcjiigkk = ssGetT
( rtS ) - rtP . t [ 20 ] ; _rtZCSV -> hzosi0qciz = ssGetT ( rtS ) - rtP . t [
20 ] ; } void MdlTerminate ( void ) { rt_FREE ( rtDW . c3wmjp50zt .
RSimInfoPtr ) ; rt_FREE ( rtDW . p0h3tkrxan . RSimInfoPtr ) ; } static void
mr_Fuzzy_Manobra_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_Fuzzy_Manobra_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Fuzzy_Manobra_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_Fuzzy_Manobra_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Fuzzy_Manobra_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_Fuzzy_Manobra_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T )
bitVal ) ) ; } static uint_T mr_Fuzzy_Manobra_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_Fuzzy_Manobra_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_Fuzzy_Manobra_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_Fuzzy_Manobra_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Fuzzy_Manobra_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_Fuzzy_Manobra_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_Fuzzy_Manobra_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_Fuzzy_Manobra_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_Fuzzy_Manobra_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Fuzzy_Manobra_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Fuzzy_Manobra_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB
) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 21 ] = {
"rtDW.f5e2gopavh" , "rtDW.lpx2pph21r" , "rtDW.adtef5njec" , "rtDW.khlsdoxige"
, "rtDW.lju2musbk0" , "rtDW.dpg2qc3x1y" , "rtDW.hfmnviw2hz" ,
"rtDW.hs5jgacqs1" , "rtDW.denj1jmxfa" , "rtDW.hobxq1jfh4" , "rtDW.hxoxcp0gyq"
, "rtDW.hfipyfd2hy" , "rtDW.huwtgpmegi" , "rtDW.ml4tiyctab" ,
"rtDW.djpwfvqboz" , "rtDW.de1hz3dcad" , "rtDW.bgdd3ewqlm" , "rtDW.maa5oi5ny5"
, "rtDW.garatixfd3" , "rtDW.knd1gqgkyt" , "rtDW.olcxu21tfo" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 21 , rtdwDataFieldNames ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
rtDW . f5e2gopavh ) , sizeof ( rtDW . f5e2gopavh ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . lpx2pph21r ) , sizeof ( rtDW . lpx2pph21r ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . adtef5njec ) , sizeof ( rtDW . adtef5njec ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . khlsdoxige ) , sizeof ( rtDW . khlsdoxige ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . lju2musbk0 ) , sizeof ( rtDW . lju2musbk0 ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . dpg2qc3x1y ) , sizeof ( rtDW . dpg2qc3x1y ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . hfmnviw2hz ) , sizeof ( rtDW . hfmnviw2hz ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . hs5jgacqs1 ) , sizeof ( rtDW . hs5jgacqs1 ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . denj1jmxfa ) , sizeof ( rtDW . denj1jmxfa ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . hobxq1jfh4 ) , sizeof ( rtDW . hobxq1jfh4 ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) &
( rtDW . hxoxcp0gyq ) , sizeof ( rtDW . hxoxcp0gyq ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) &
( rtDW . hfipyfd2hy ) , sizeof ( rtDW . hfipyfd2hy ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) &
( rtDW . huwtgpmegi ) , sizeof ( rtDW . huwtgpmegi ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) &
( rtDW . ml4tiyctab ) , sizeof ( rtDW . ml4tiyctab ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) &
( rtDW . djpwfvqboz ) , sizeof ( rtDW . djpwfvqboz ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) &
( rtDW . de1hz3dcad ) , sizeof ( rtDW . de1hz3dcad ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) &
( rtDW . bgdd3ewqlm ) , sizeof ( rtDW . bgdd3ewqlm ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) &
( rtDW . maa5oi5ny5 ) , sizeof ( rtDW . maa5oi5ny5 ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) &
( rtDW . garatixfd3 ) , sizeof ( rtDW . garatixfd3 ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) &
( rtDW . knd1gqgkyt ) , sizeof ( rtDW . knd1gqgkyt ) ) ;
mr_Fuzzy_Manobra_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) &
( rtDW . olcxu21tfo ) , sizeof ( rtDW . olcxu21tfo ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_Fuzzy_Manobra_SetDWork
( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0
, sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW ,
0 , 1 ) ; mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW .
f5e2gopavh ) , rtdwData , 0 , 0 , sizeof ( rtDW . f5e2gopavh ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . lpx2pph21r )
, rtdwData , 0 , 1 , sizeof ( rtDW . lpx2pph21r ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . adtef5njec )
, rtdwData , 0 , 2 , sizeof ( rtDW . adtef5njec ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . khlsdoxige )
, rtdwData , 0 , 3 , sizeof ( rtDW . khlsdoxige ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . lju2musbk0 )
, rtdwData , 0 , 4 , sizeof ( rtDW . lju2musbk0 ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . dpg2qc3x1y )
, rtdwData , 0 , 5 , sizeof ( rtDW . dpg2qc3x1y ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . hfmnviw2hz )
, rtdwData , 0 , 6 , sizeof ( rtDW . hfmnviw2hz ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . hs5jgacqs1 )
, rtdwData , 0 , 7 , sizeof ( rtDW . hs5jgacqs1 ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . denj1jmxfa )
, rtdwData , 0 , 8 , sizeof ( rtDW . denj1jmxfa ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . hobxq1jfh4 )
, rtdwData , 0 , 9 , sizeof ( rtDW . hobxq1jfh4 ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxoxcp0gyq )
, rtdwData , 0 , 10 , sizeof ( rtDW . hxoxcp0gyq ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . hfipyfd2hy )
, rtdwData , 0 , 11 , sizeof ( rtDW . hfipyfd2hy ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . huwtgpmegi )
, rtdwData , 0 , 12 , sizeof ( rtDW . huwtgpmegi ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . ml4tiyctab )
, rtdwData , 0 , 13 , sizeof ( rtDW . ml4tiyctab ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . djpwfvqboz )
, rtdwData , 0 , 14 , sizeof ( rtDW . djpwfvqboz ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . de1hz3dcad )
, rtdwData , 0 , 15 , sizeof ( rtDW . de1hz3dcad ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . bgdd3ewqlm )
, rtdwData , 0 , 16 , sizeof ( rtDW . bgdd3ewqlm ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . maa5oi5ny5 )
, rtdwData , 0 , 17 , sizeof ( rtDW . maa5oi5ny5 ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . garatixfd3 )
, rtdwData , 0 , 18 , sizeof ( rtDW . garatixfd3 ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . knd1gqgkyt )
, rtdwData , 0 , 19 , sizeof ( rtDW . knd1gqgkyt ) ) ;
mr_Fuzzy_Manobra_restoreDataFromMxArray ( ( void * ) & ( rtDW . olcxu21tfo )
, rtdwData , 0 , 20 , sizeof ( rtDW . olcxu21tfo ) ) ; } } mxArray *
mr_Fuzzy_Manobra_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 8 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 8 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , } ; static const char_T * blockPath [ 8 ] = {
"Fuzzy_Manobra/Xrobo" , "Fuzzy_Manobra/Yrobo" , "Fuzzy_Manobra/dv" ,
"Fuzzy_Manobra/ud" , "Fuzzy_Manobra/ue" , "Fuzzy_Manobra/wd_scope" ,
"Fuzzy_Manobra/we_scope" , "Fuzzy_Manobra/Subsystem1/d" , } ; static const
int reason [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0
; subs [ 0 ] < 8 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 9 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
5 ) ; ssSetNumBlocks ( rtS , 126 ) ; ssSetNumBlockIO ( rtS , 29 ) ;
ssSetNumBlockParams ( rtS , 366 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.01 ) ; ssSetSampleTime ( rtS , 3 , - 2.0 ) ;
ssSetSampleTime ( rtS , 4 , - 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1252585181U ) ;
ssSetChecksumVal ( rtS , 1 , 2528956502U ) ; ssSetChecksumVal ( rtS , 2 ,
3251025582U ) ; ssSetChecksumVal ( rtS , 3 , 418537064U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 2 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 28 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
Fuzzy_Manobra_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "Fuzzy_Manobra" ) ;
ssSetPath ( rtS , "Fuzzy_Manobra" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 117.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo
. loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo )
; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 } ; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [
] = { ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [
] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "Fuzzy_Manobra/Cinematico/Integrator1" ,
"Fuzzy_Manobra/Cinematico/Integrator2" , "Fuzzy_Manobra/Dinamico/Integrator1"
, "Fuzzy_Manobra/Dinamico/Integrator" , "Fuzzy_Manobra/Subsystem4/PI dir2" ,
"Fuzzy_Manobra/Subsystem4/PI dir1" , "Fuzzy_Manobra/PI dir" ,
"Fuzzy_Manobra/PI esq" , "Fuzzy_Manobra/Cinematico/Integrator" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" ,
"" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert
[ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 ,
2 , 3 , 4 , 5 , 6 , 7 , 8 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 9 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 9 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . bkcuyngzrw ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . cjefnieqjk ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . nteby5pkz0 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . cstdmiz3hi ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . hrbxi1qk1v ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . mlbbkxddra ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . j1ktoc2z4w ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . b1haufhayo ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . huljek0oib ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 9 ] ;
static real_T absTol [ 9 ] = { 1.0000000000000002E-12 ,
1.0000000000000002E-12 , 1.0000000000000002E-12 , 1.0000000000000002E-12 ,
1.0000000000000002E-12 , 1.0000000000000002E-12 , 1.0000000000000002E-12 ,
1.0000000000000002E-12 , 1.0000000000000002E-12 } ; static uint8_T
absTolControl [ 9 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static
real_T contStateJacPerturbBoundMinVec [ 9 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 9 ] ; static uint8_T zcAttributes [ 7 ] = {
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 3 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . olhqar1g4d ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . pavpjlcqba ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . pnt2f1gct3 ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i <
9 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 1.0E-9 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.01 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
3 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 7 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 7 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1252585181U ) ; ssSetChecksumVal ( rtS , 1 ,
2528956502U ) ; ssSetChecksumVal ( rtS , 2 , 3251025582U ) ; ssSetChecksumVal
( rtS , 3 , 418537064U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 5 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Fuzzy_Manobra_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP
( rtS , mr_Fuzzy_Manobra_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_Fuzzy_Manobra_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if
( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID5 ( tid ) ; }
