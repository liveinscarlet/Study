#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_vXKyqKJ8YdvIHwuI2WRLe" , 17 , 112 } , { "uint8_T" , 18 , 1 } , {
"cqb32sjpki" , 19 , 2600 } , { "uint8_T" , 20 , 1 } , { "uint64_T" , 21 , 8 }
, { "int64_T" , 22 , 8 } , { "uint_T" , 23 , 32 } , { "char_T" , 24 , 8 } , {
"uchar_T" , 25 , 8 } , { "time_T" , 26 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_vXKyqKJ8YdvIHwuI2WRLe ) , sizeof ( uint8_T ) ,
sizeof ( cqb32sjpki ) , sizeof ( uint8_T ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_vXKyqKJ8YdvIHwuI2WRLe" , "uint8_T" , "cqb32sjpki" , "uint8_T" ,
"uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" , "time_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
oiagjxsfua ) , 0 , 0 , 33 } , { ( char_T * ) ( & rtB . iaqfq2eapm ) , 18 , 0
, 1 } , { ( char_T * ) ( & rtB . aes5bhgd15 ) , 8 , 0 , 1 } , { ( char_T * )
( & rtDW . b2pi4gudhv ) , 19 , 0 , 1 } , { ( char_T * ) ( & rtDW . khu2zdxbs4
[ 0 ] ) , 0 , 0 , 10232 } , { ( char_T * ) ( & rtDW . om2ho3dulj ) , 15 , 0 ,
1 } , { ( char_T * ) ( & rtDW . mvgx1jbk50 . modelTStart ) , 0 , 0 , 2 } , {
( char_T * ) ( & rtDW . bo3muh5enu . TUbufferPtrs [ 0 ] ) , 11 , 0 , 5 } , {
( char_T * ) ( & rtDW . ezlg5otozk ) , 6 , 0 , 8 } , { ( char_T * ) ( & rtDW
. iqp54sidls ) , 7 , 0 , 633 } , { ( char_T * ) ( & rtDW . gttvq41aan . Tail
) , 10 , 0 , 2 } , { ( char_T * ) ( & rtDW . nxrgsy2c2w [ 0 ] ) , 3 , 0 , 19
} , { ( char_T * ) ( & rtDW . ngrrkreo2f ) , 2 , 0 , 10 } , { ( char_T * ) (
& rtDW . agygzdruc0 ) , 3 , 0 , 6 } , { ( char_T * ) ( & rtDW . pemmcx3bjg )
, 8 , 0 , 8 } } ; static DataTypeTransitionTable rtBTransTable = { 15U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . AWGNChannel_SNR ) , 0 , 0 , 106 } , { ( char_T * ) ( &
rtP . Gain_Gain_c0wzfxwapi ) , 6 , 0 , 6 } , { ( char_T * ) ( & rtP .
AnalogFilterDesign_A_ir [ 0 ] ) , 7 , 0 , 117 } , { ( char_T * ) ( & rtP .
CombinatorialLogic_table [ 0 ] ) , 8 , 0 , 4 } , { ( char_T * ) ( & rtP .
DiscreteTimeIntegrator_IC ) , 18 , 0 , 1 } } ; static DataTypeTransitionTable
rtPTransTable = { 5U , rtPTransitions } ;
