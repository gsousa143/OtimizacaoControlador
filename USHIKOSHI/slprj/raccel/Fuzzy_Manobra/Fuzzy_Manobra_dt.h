#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_4pAUz1yyACRB9R6qbwf2qG" , 17 , 48 } , {
"struct_nDiNttezQ8pHMZv76leKsH" , 18 , 56 } , {
"struct_lMtpFmLOVR7rlweqgH5LGF" , 19 , 400 } , {
"struct_6VzYiVW2hAWQCI9jAYOVeF" , 20 , 176 } , {
"struct_KT8JU2t1iaSu0Bn0Rl6dbG" , 21 , 3336 } , { "uint64_T" , 22 , 8 } , {
"int64_T" , 23 , 8 } , { "uint_T" , 24 , 32 } , { "char_T" , 25 , 8 } , {
"uchar_T" , 26 , 8 } , { "time_T" , 27 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( int32_T ) , sizeof ( int32_T ) , sizeof ( int32_T ) ,
sizeof ( int32_T ) , sizeof ( int32_T ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_4pAUz1yyACRB9R6qbwf2qG" , "struct_nDiNttezQ8pHMZv76leKsH" ,
"struct_lMtpFmLOVR7rlweqgH5LGF" , "struct_6VzYiVW2hAWQCI9jAYOVeF" ,
"struct_KT8JU2t1iaSu0Bn0Rl6dbG" , "uint64_T" , "int64_T" , "uint_T" ,
"char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . ha2gv25mhx ) , 0 , 0 , 25 } , { ( char_T * )
( & rtDW . f5e2gopavh ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtDW . c3dr1neq03
. LoggedData ) , 11 , 0 , 10 } , { ( char_T * ) ( & rtDW . lju2musbk0 ) , 6 ,
0 , 3 } , { ( char_T * ) ( & rtDW . hs5jgacqs1 . PrevIndex ) , 10 , 0 , 7 } ,
{ ( char_T * ) ( & rtDW . djpwfvqboz ) , 2 , 0 , 1 } , { ( char_T * ) ( &
rtDW . de1hz3dcad ) , 3 , 0 , 3 } , { ( char_T * ) ( & rtDW . garatixfd3 ) ,
8 , 0 , 3 } } ; static DataTypeTransitionTable rtBTransTable = { 8U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . I ) , 0 , 0 , 366 } } ; static DataTypeTransitionTable
rtPTransTable = { 1U , rtPTransitions } ;
