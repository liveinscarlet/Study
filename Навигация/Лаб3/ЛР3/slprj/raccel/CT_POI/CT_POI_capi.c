#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "CT_POI_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 21
#endif
#ifndef SS_INT64
#define SS_INT64 22
#endif
#else
#include "builtin_typeid_types.h"
#include "CT_POI.h"
#include "CT_POI_capi.h"
#include "CT_POI_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"CT_POI/Constant4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "CT_POI/Discrete-Time Integrator" ) , TARGET_STRING ( "" ) ,
0 , 1 , 0 , 1 , 0 } , { 2 , 0 , TARGET_STRING ( "CT_POI/Analog Filter Design"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 1 , TARGET_STRING (
"CT_POI/AWGN Channel" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 4 ,
0 , TARGET_STRING ( "CT_POI/Subsystem1/Combinatorial  Logic" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"CT_POI/Subsystem2/Discrete-Time Integrator" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "CT_POI/Subsystem2/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 7 , 0 , TARGET_STRING (
"CT_POI/Subsystem2/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
8 , 0 , TARGET_STRING ( "CT_POI/Subsystem2/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 2 } , { 9 , 0 , TARGET_STRING (
"CT_POI/Subsystem2/Variable Transport Delay1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING ( "CT_POI/Subsystem4/Sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 11 , 0 , TARGET_STRING (
"CT_POI/Subsystem4/Zero-Order Hold1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 3 } , { 12 , 0 , TARGET_STRING ( "CT_POI/Subsystem4/Zero-Order Hold2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 13 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 14 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 15 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator3" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 16 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator4" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 17 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator5" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 18 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator6" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 19 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Pulse Generator1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 5 } , { 20 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Fcn1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 6 } , { 21 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Math Function1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
3 } , { 22 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Math Function2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 23 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 24 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Product1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Product2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 26 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Product3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Product4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 28 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Product5" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Product6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } ,
{ 30 , 0 , TARGET_STRING ( "CT_POI/Subsystem5/Trigonometric Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 31 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Trigonometric Function1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 32 , 0 , TARGET_STRING (
"CT_POI/Subsystem2/Unipolar to Bipolar Converter/Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 7 } , { 33 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Subsystem/Constant1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 34 , 0 , TARGET_STRING (
"CT_POI/Subsystem5/Unipolar to Bipolar Converter/Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 7 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 35 , TARGET_STRING ( "CT_POI/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"CT_POI/Constant4" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 37 ,
TARGET_STRING ( "CT_POI/Discrete-Time Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 1 , 0 , 1 } , { 38 , TARGET_STRING (
"CT_POI/Analog Filter Design" ) , TARGET_STRING ( "A_pr" ) , 0 , 1 , 0 } , {
39 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) , TARGET_STRING ( "A_ir"
) , 3 , 1 , 0 } , { 40 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) ,
TARGET_STRING ( "A_jc" ) , 3 , 2 , 0 } , { 41 , TARGET_STRING (
"CT_POI/Analog Filter Design" ) , TARGET_STRING ( "B_pr" ) , 0 , 3 , 0 } , {
42 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) , TARGET_STRING ( "B_ir"
) , 3 , 3 , 0 } , { 43 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) ,
TARGET_STRING ( "B_jc" ) , 3 , 4 , 0 } , { 44 , TARGET_STRING (
"CT_POI/Analog Filter Design" ) , TARGET_STRING ( "C_pr" ) , 0 , 5 , 0 } , {
45 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) , TARGET_STRING ( "C_ir"
) , 3 , 5 , 0 } , { 46 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) ,
TARGET_STRING ( "C_jc" ) , 3 , 2 , 0 } , { 47 , TARGET_STRING (
"CT_POI/Analog Filter Design" ) , TARGET_STRING ( "D_pr" ) , 0 , 0 , 0 } , {
48 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) , TARGET_STRING ( "D_ir"
) , 3 , 0 , 0 } , { 49 , TARGET_STRING ( "CT_POI/Analog Filter Design" ) ,
TARGET_STRING ( "D_jc" ) , 3 , 4 , 0 } , { 50 , TARGET_STRING (
"CT_POI/Analog Filter Design" ) , TARGET_STRING ( "InitialCondition" ) , 0 ,
0 , 0 } , { 51 , TARGET_STRING ( "CT_POI/AWGN Channel" ) , TARGET_STRING (
"SNR" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING ( "CT_POI/AWGN Channel" ) ,
TARGET_STRING ( "SignalPower" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"CT_POI/Subsystem1/Combinatorial  Logic" ) , TARGET_STRING ( "TruthTable" ) ,
2 , 6 , 0 } , { 54 , TARGET_STRING ( "CT_POI/Subsystem1/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"CT_POI/Subsystem2/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
56 , TARGET_STRING ( "CT_POI/Subsystem2/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"CT_POI/Subsystem2/Discrete-Time Integrator" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 58 , TARGET_STRING ( "CT_POI/Subsystem2/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"CT_POI/Subsystem2/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 60 ,
TARGET_STRING ( "CT_POI/Subsystem2/Variable Transport Delay1" ) ,
TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"CT_POI/Subsystem2/Variable Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"CT_POI/Subsystem4/Buffer1" ) , TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 63 ,
TARGET_STRING ( "CT_POI/Subsystem4/Buffer3" ) , TARGET_STRING ( "ic" ) , 0 ,
0 , 0 } , { 64 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator1" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 65 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator2" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 67 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator3" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 69 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator4" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 71 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator5" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 73 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator5" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator6" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 75 , TARGET_STRING (
"CT_POI/Subsystem5/Discrete-Time Integrator6" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"CT_POI/Subsystem5/Pulse Generator1" ) , TARGET_STRING ( "Amplitude" ) , 0 ,
0 , 0 } , { 77 , TARGET_STRING ( "CT_POI/Subsystem5/Pulse Generator1" ) ,
TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"CT_POI/Subsystem5/Pulse Generator1" ) , TARGET_STRING ( "PulseWidth" ) , 0 ,
0 , 0 } , { 79 , TARGET_STRING ( "CT_POI/Subsystem5/Pulse Generator1" ) ,
TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
"CT_POI/Subsystem5/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 81 ,
TARGET_STRING ( "CT_POI/Subsystem2/Unipolar to Bipolar Converter/Bias" ) ,
TARGET_STRING ( "Bias" ) , 4 , 0 , 0 } , { 82 , TARGET_STRING (
"CT_POI/Subsystem2/Unipolar to Bipolar Converter/Gain" ) , TARGET_STRING (
"Gain" ) , 4 , 0 , 0 } , { 83 , TARGET_STRING (
"CT_POI/Subsystem2/Unipolar to Bipolar Converter/Gain1" ) , TARGET_STRING (
"Gain" ) , 4 , 0 , 0 } , { 84 , TARGET_STRING (
"CT_POI/Subsystem5/Subsystem/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 85 , TARGET_STRING (
"CT_POI/Subsystem5/Subsystem/Variable Transport Delay" ) , TARGET_STRING (
"MaximumDelay" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"CT_POI/Subsystem5/Subsystem/Variable Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"CT_POI/Subsystem5/Unipolar to Bipolar Converter/Bias" ) , TARGET_STRING (
"Bias" ) , 4 , 0 , 0 } , { 88 , TARGET_STRING (
"CT_POI/Subsystem5/Unipolar to Bipolar Converter/Gain" ) , TARGET_STRING (
"Gain" ) , 4 , 0 , 0 } , { 89 , TARGET_STRING (
"CT_POI/Subsystem5/Unipolar to Bipolar Converter/Gain1" ) , TARGET_STRING (
"Gain" ) , 4 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . h00tanbm5k , & rtB . iaqfq2eapm ,
& rtB . aeq5ruscfh , & rtB . cns4fjew02 , & rtB . aes5bhgd15 , & rtB .
f2shyu0rcb , & rtB . lrjqprgrv3 , & rtB . ka0zgragyp , & rtB . k42ztcl2nd , &
rtB . oiagjxsfua , & rtB . fo3o0qx3rk , & rtB . pnfujicrav , & rtB .
ptxjsacnuh , & rtB . i50ghe5lm1 , & rtB . nxismlfsz2 , & rtB . et3ss0ypwk , &
rtB . eatzl3wsw1 , & rtB . he1lzb12tu , & rtB . i5jmft20v3 , & rtB .
jx13nwj10i , & rtB . mh3qnuillk , & rtB . nbzdbx43y2 , & rtB . lydxvhyrns , &
rtB . hcqcgye2fg , & rtB . eue4pzm2um , & rtB . cqncnt5j3w , & rtB .
p3kz0eppb3 , & rtB . ekkv4odda4 , & rtB . bunz1k115f , & rtB . c1hzatsvvq , &
rtB . nym1g1yulh , & rtB . abu2iacvsb , & rtB . ahaloitnql , & rtB .
gzm3dlplwu , & rtB . cskkp1pbit , & rtP . Constant_Value , & rtP .
Constant4_Value , & rtP . DiscreteTimeIntegrator_IC , & rtP .
AnalogFilterDesign_A_pr [ 0 ] , & rtP . AnalogFilterDesign_A_ir [ 0 ] , & rtP
. AnalogFilterDesign_A_jc [ 0 ] , & rtP . AnalogFilterDesign_B_pr [ 0 ] , &
rtP . AnalogFilterDesign_B_ir [ 0 ] , & rtP . AnalogFilterDesign_B_jc [ 0 ] ,
& rtP . AnalogFilterDesign_C_pr [ 0 ] , & rtP . AnalogFilterDesign_C_ir [ 0 ]
, & rtP . AnalogFilterDesign_C_jc [ 0 ] , & rtP . AnalogFilterDesign_D_pr , &
rtP . AnalogFilterDesign_D_ir , & rtP . AnalogFilterDesign_D_jc [ 0 ] , & rtP
. AnalogFilterDesign_InitialCondition , & rtP . AWGNChannel_SNR , & rtP .
AWGNChannel_SignalPower , & rtP . CombinatorialLogic_table [ 0 ] , & rtP .
Constant3_Value , & rtP . Constant2_Value , & rtP .
Constant3_Value_naltalopjl , & rtP . DiscreteTimeIntegrator_gainval , & rtP .
Gain_Gain_donlcyw5bh , & rtP . Gain1_Gain , & rtP .
VariableTransportDelay1_MaxDelay , & rtP . VariableTransportDelay1_InitOutput
, & rtP . Buffer1_ic , & rtP . Buffer3_ic , & rtP .
DiscreteTimeIntegrator1_gainval , & rtP . DiscreteTimeIntegrator1_IC , & rtP
. DiscreteTimeIntegrator2_gainval , & rtP . DiscreteTimeIntegrator2_IC , &
rtP . DiscreteTimeIntegrator3_gainval , & rtP . DiscreteTimeIntegrator3_IC ,
& rtP . DiscreteTimeIntegrator4_gainval , & rtP . DiscreteTimeIntegrator4_IC
, & rtP . DiscreteTimeIntegrator5_gainval , & rtP .
DiscreteTimeIntegrator5_IC , & rtP . DiscreteTimeIntegrator6_gainval , & rtP
. DiscreteTimeIntegrator6_IC , & rtP . PulseGenerator1_Amp , & rtP .
PulseGenerator1_Period , & rtP . PulseGenerator1_Duty , & rtP .
PulseGenerator1_PhaseDelay , & rtP . Gain_Gain , & rtP . Bias_Bias_fafg04n1yq
, & rtP . Gain_Gain_hnwxniojmd , & rtP . Gain1_Gain_lhfiaw3lod , & rtP .
Constant1_Value , & rtP . VariableTransportDelay_MaxDelay , & rtP .
VariableTransportDelay_InitOutput , & rtP . Bias_Bias , & rtP .
Gain_Gain_c0wzfxwapi , & rtP . Gain1_Gain_jhwyhxq2zq , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "unsigned char" , "boolean_T" , 0 , 0 , sizeof (
boolean_T ) , ( uint8_T ) SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned int" ,
"uint32_T" , 0 , 0 , sizeof ( uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0
} , { "int" , "int32_T" , 0 , 0 , sizeof ( int32_T ) , ( uint8_T ) SS_INT32 ,
0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 55 , 1 , 21 , 1 , 5 , 1 , 2 , 1 , 10 , 1 , 4 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.001 , 0.0 , 1.28 , 1.0 , 1.955E-7 ,
0.0004995025 , - 2.0 , 1.955E-6 } ; static const rtwCAPI_FixPtMap rtFixPtMap
[ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T )
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , rtwCAPI_FIX_UNIFORM_SCALING , 8 , - 7 , (
boolean_T ) 0 } } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] =
{ { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 5 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1
] , ( const void * ) & rtcapiStoredFloats [ 3 ] , ( int8_T ) 1 , ( uint8_T )
0 } , { ( const void * ) & rtcapiStoredFloats [ 4 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 2 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 5 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 4 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 6
] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 6 , ( uint8_T )
0 } , { ( NULL ) , ( NULL ) , 7 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 7 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 3 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 35 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 55 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2059667716U , 822817126U , 3881375U ,
2437997414U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * CT_POI_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void CT_POI_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void CT_POI_host_InitializeDataMapInfo ( CT_POI_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
