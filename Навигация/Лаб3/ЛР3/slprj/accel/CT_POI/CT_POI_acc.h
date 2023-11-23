#ifndef RTW_HEADER_CT_POI_acc_h_
#define RTW_HEADER_CT_POI_acc_h_
#ifndef CT_POI_acc_COMMON_INCLUDES_
#define CT_POI_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "CT_POI_acc_types.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_0_0_0 ; real_T B_0_1_0 ; real_T B_0_5_0 ; real_T
B_0_6_0 ; real_T B_0_7_0 ; real_T B_0_8_0 ; real_T B_0_12_0 ; real_T B_0_16_0
; real_T B_0_20_0 ; real_T B_0_22_0 ; real_T B_0_23_0 ; real_T B_0_24_0 ;
real_T B_0_25_0 ; real_T B_0_26_0 ; real_T B_0_27_0 ; real_T B_0_28_0 ;
real_T B_0_35_0 ; real_T B_0_36_0 ; real_T B_0_37_0 ; real_T B_0_39_0 ;
real_T B_0_40_0 ; real_T B_0_44_0 ; real_T B_0_55_0 ; real_T B_0_56_0 ;
real_T B_0_57_0 ; real_T B_0_58_0 ; real_T B_0_59_0 ; real_T B_0_60_0 ;
real_T B_0_66_0 ; real_T B_0_68_0 ; real_T B_0_69_0 ; real_T B_0_70_0 ;
real_T B_0_73_0 ; real_T B_0_74_0 ; real_T B_0_1_0_m ; real_T B_0_2_0 ;
real_T B_0_2_0_c [ 2555 ] ; uint8_T B_0_14_0 ; boolean_T B_0_65_0 ; char_T
pad_B_0_65_0 [ 6 ] ; } B_CT_POI_T ; typedef struct { real_T Buffer1_CircBuf [
5110 ] ; real_T Buffer3_CircBuf [ 5110 ] ; real_T
DiscreteTimeIntegrator1_DSTATE ; real_T DiscreteTimeIntegrator2_DSTATE ;
real_T DiscreteTimeIntegrator5_DSTATE ; real_T DiscreteTimeIntegrator6_DSTATE
; real_T DiscreteTimeIntegrator3_DSTATE ; real_T
DiscreteTimeIntegrator4_DSTATE ; real_T DiscreteTimeIntegrator_DSTATE ;
real_T Variance1_AccVal ; real_T Variance1_SqData ; real_T STDDEV ; real_T
Variance2_AccVal ; real_T Variance2_SqData ; real_T nextTime ; int64_T
numCompleteCycles ; struct { real_T modelTStart ; }
VariableTransportDelay1_RWORK ; struct { real_T modelTStart ; }
VariableTransportDelay_RWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
VariableTransportDelay1_PWORK ; struct { void * TUbufferPtrs [ 3 ] ; }
VariableTransportDelay_PWORK ; int32_T Buffer1_inBufPtrIdx ; int32_T
Buffer1_outBufPtrIdx ; int32_T Buffer1_bufferLength ; int32_T
Buffer3_inBufPtrIdx ; int32_T Buffer3_outBufPtrIdx ; int32_T
Buffer3_bufferLength ; int32_T justEnabled ; int32_T currentValue ; uint32_T
RandomSource_SEED_DWORK ; uint32_T RandomSource_STATE_DWORK [ 2 ] ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } VariableTransportDelay1_IWORK ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
VariableTransportDelay_IWORK ; uint8_T shiftReg [ 9 ] ; uint8_T shiftReg_h [
9 ] ; uint8_T DiscreteTimeIntegrator_DSTATE_k ; int8_T Fcn1_DWORK1 ; int8_T
Fcn3_DWORK1 ; int8_T DiscreteTimeIntegrator1_PrevResetState ; int8_T
DiscreteTimeIntegrator2_PrevResetState ; int8_T
DiscreteTimeIntegrator5_PrevResetState ; int8_T
DiscreteTimeIntegrator6_PrevResetState ; int8_T MathFunction6_DWORK1 ; int8_T
DiscreteTimeIntegrator3_PrevResetState ; int8_T
DiscreteTimeIntegrator4_PrevResetState ; int8_T Fcn1_DWORK1_a ; uint8_T
DiscreteTimeIntegrator1_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator5_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator6_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator3_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator4_SYSTEM_ENABLE ; char_T
pad_DiscreteTimeIntegrator4_SYSTEM_ENABLE [ 1 ] ; } DW_CT_POI_T ; typedef
struct { real_T AnalogFilterDesign_CSTATE [ 20 ] ; real_T
VariableTransportDelay_CSTATE ; } X_CT_POI_T ; typedef struct { real_T
AnalogFilterDesign_CSTATE [ 20 ] ; real_T VariableTransportDelay_CSTATE ; }
XDot_CT_POI_T ; typedef struct { boolean_T AnalogFilterDesign_CSTATE [ 20 ] ;
boolean_T VariableTransportDelay_CSTATE ; } XDis_CT_POI_T ; typedef struct {
real_T AnalogFilterDesign_CSTATE [ 20 ] ; real_T
VariableTransportDelay_CSTATE ; } CStateAbsTol_CT_POI_T ; typedef struct {
real_T AnalogFilterDesign_CSTATE [ 20 ] ; real_T
VariableTransportDelay_CSTATE ; } CXPtMin_CT_POI_T ; typedef struct { real_T
AnalogFilterDesign_CSTATE [ 20 ] ; real_T VariableTransportDelay_CSTATE ; }
CXPtMax_CT_POI_T ; typedef struct { uint8_T pooled1 [ 10 ] ; uint8_T
PNSequenceGenerator2_IniState [ 9 ] ; uint8_T pooled2 [ 9 ] ; uint8_T
PNSequenceGenerator2_IniState_b [ 9 ] ; char
pad_PNSequenceGenerator2_IniState_b [ 3 ] ; } ConstP_CT_POI_T ; struct
P_CT_POI_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4
; real_T P_5 ; real_T P_6 ; real_T P_7 [ 55 ] ; real_T P_8 [ 5 ] ; real_T P_9
[ 10 ] ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14
; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ;
real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; int32_T P_41 ;
int32_T P_42 ; int32_T P_43 ; int32_T P_44 ; int32_T P_45 ; int32_T P_46 ;
uint32_T P_47 ; uint32_T P_48 ; uint32_T P_49 [ 55 ] ; uint32_T P_50 [ 21 ] ;
uint32_T P_51 [ 5 ] ; uint32_T P_52 [ 2 ] ; uint32_T P_53 [ 10 ] ; uint32_T
P_54 [ 21 ] ; uint32_T P_55 ; uint32_T P_56 [ 2 ] ; boolean_T P_57 [ 4 ] ;
uint8_T P_58 ; char_T pad_P_58 [ 7 ] ; } ; extern P_CT_POI_T
CT_POI_rtDefaultP ; extern const ConstP_CT_POI_T CT_POI_rtConstP ;
#endif
