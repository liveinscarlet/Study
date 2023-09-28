#ifndef RTW_HEADER_AKF_CT1_acc_h_
#define RTW_HEADER_AKF_CT1_acc_h_
#ifndef AKF_CT1_acc_COMMON_INCLUDES_
#define AKF_CT1_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "AKF_CT1_acc_types.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_0_5_0 ; real_T B_0_6_0 ; real_T B_0_7_0 ; real_T
B_0_8_0 ; real_T B_0_10_0 ; real_T B_0_11_0 ; real_T B_0_12_0 ; real_T
B_0_14_0 ; real_T B_0_16_0 ; real_T B_0_20_0 ; real_T B_0_26_0 ; real_T
B_0_27_0 ; real_T B_0_0_0 ; real_T B_0_1_0 ; real_T B_0_13_0 [ 1022 ] ; }
B_AKF_CT1_T ; typedef struct { real_T DiscreteTimeIntegrator_DSTATE ; real_T
DiscreteTimeIntegrator1_DSTATE ; real_T Buffer1_CircBuf [ 2044 ] ; real_T
nextTime ; real_T nextTime_e ; real_T Mean1_AccVal ; int64_T
numCompleteCycles ; int64_T numCompleteCycles_l ; struct { real_T modelTStart
; } VariableTimeDelay_RWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
VariableTimeDelay_PWORK ; void * Scope_PWORK ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace_PWORK ; int32_T Buffer1_inBufPtrIdx ;
int32_T Buffer1_outBufPtrIdx ; int32_T Buffer1_bufferLength ; int32_T
justEnabled ; int32_T currentValue ; int32_T justEnabled_k ; int32_T
currentValue_o ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } VariableTimeDelay_IWORK ; uint8_T
shiftReg [ 9 ] ; uint8_T shiftReg_i [ 9 ] ; int8_T
DiscreteTimeIntegrator1_PrevResetState ; uint8_T
DiscreteTimeIntegrator1_SYSTEM_ENABLE ; char_T
pad_DiscreteTimeIntegrator1_SYSTEM_ENABLE [ 4 ] ; } DW_AKF_CT1_T ; typedef
struct { uint8_T PNSequenceGenerator1_Polynomial [ 10 ] ; uint8_T
PNSequenceGenerator1_IniState [ 9 ] ; uint8_T pooled1 [ 9 ] ; uint8_T
PNSequenceGenerator2_Polynomial [ 10 ] ; uint8_T
PNSequenceGenerator2_IniState [ 9 ] ; char pad_PNSequenceGenerator2_IniState
; } ConstP_AKF_CT1_T ; struct P_AKF_CT1_T_ { real_T P_0 ; real_T P_1 ; real_T
P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T
P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ;
real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; int32_T P_20 ; int32_T P_21 ; int32_T P_22 ; int32_T P_23 ; int32_T
P_24 ; int32_T P_25 ; } ; extern P_AKF_CT1_T AKF_CT1_rtDefaultP ; extern
const ConstP_AKF_CT1_T AKF_CT1_rtConstP ;
#endif
