#include "AKF_CT1_acc.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include <float.h>
#include "AKF_CT1_acc_private.h"
#include "multiword_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T AKF_CT1_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T
* tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T *
* uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = *
bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ;
int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf = *
uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0
; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
AKF_CT1_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } static void
mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_0_9_0 ; B_AKF_CT1_T *
_rtB ; DW_AKF_CT1_T * _rtDW ; P_AKF_CT1_T * _rtP ; real_T ratio ; real_T
taskTimeV ; int32_T currentOffset ; int32_T i ; int32_T isHit ; int32_T uyIdx
; uint32_T numCycles ; uint8_T tmp ; uint8_T tmp2 ; _rtDW = ( ( DW_AKF_CT1_T
* ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_AKF_CT1_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_AKF_CT1_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { tmp = 0U ; tmp2 = 0U ; for
( i = 0 ; i < 9 ; i ++ ) { tmp = ( uint8_T ) ( ( uint32_T ) ( uint8_T ) ( (
uint32_T ) AKF_CT1_rtConstP . PNSequenceGenerator1_Polynomial [ i + 1 ] *
_rtDW -> shiftReg [ i ] ) + tmp ) ; tmp2 = ( uint8_T ) ( ( uint32_T ) (
uint8_T ) ( ( uint32_T ) _rtDW -> shiftReg [ i ] * AKF_CT1_rtConstP . pooled1
[ i ] ) + tmp2 ) ; } tmp &= 1 ; for ( i = 7 ; i >= 0 ; i -- ) { _rtDW ->
shiftReg [ i + 1 ] = _rtDW -> shiftReg [ i ] ; } _rtDW -> shiftReg [ 0U ] =
tmp ; _rtB -> B_0_5_0 = ( ( ( tmp2 & 1U ) != 0U ) * _rtP -> P_20 + _rtP ->
P_21 ) * _rtP -> P_22 ; } isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit !=
0 ) { taskTimeV = ssGetTaskTime ( S , 5 ) ; if ( ssGetTNextWasAdjusted ( S ,
5 ) != 0 ) { _rtDW -> nextTime = _ssGetVarNextHitTime ( S , 0 ) ; } if (
_rtDW -> justEnabled != 0 ) { _rtDW -> justEnabled = 0 ; if ( taskTimeV >=
_rtP -> P_3 ) { ratio = ( taskTimeV - _rtP -> P_3 ) / _rtP -> P_1 ; numCycles
= ( uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( (
real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++
; } _rtDW -> numCompleteCycles = numCycles ; ratio = ( ( real_T ) numCycles *
_rtP -> P_1 + _rtP -> P_3 ) + _rtP -> P_2 * _rtP -> P_1 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue = 1 ; _rtDW -> nextTime = ratio ;
} else { _rtDW -> currentValue = 0 ; _rtDW -> nextTime = ( real_T ) (
numCycles + 1U ) * _rtP -> P_1 + _rtP -> P_3 ; } } else { _rtDW ->
numCompleteCycles = _rtP -> P_3 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue = 0
; _rtDW -> nextTime = _rtP -> P_3 ; } } else if ( _rtDW -> nextTime <=
taskTimeV ) { if ( _rtDW -> currentValue == 1 ) { _rtDW -> currentValue = 0 ;
_rtDW -> nextTime = ( real_T ) ( _rtDW -> numCompleteCycles + 1LL ) * _rtP ->
P_1 + _rtP -> P_3 ; } else { _rtDW -> numCompleteCycles ++ ; _rtDW ->
currentValue = 1 ; _rtDW -> nextTime = ( _rtP -> P_2 * _rtP -> P_1 * 0.01 + (
real_T ) _rtDW -> numCompleteCycles * _rtP -> P_1 ) + _rtP -> P_3 ; } }
_ssSetVarNextHitTime ( S , 0 , _rtDW -> nextTime ) ; if ( _rtDW ->
currentValue == 1 ) { _rtB -> B_0_6_0 = _rtP -> P_0 ; } else { _rtB ->
B_0_6_0 = 0.0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( _rtB -> B_0_6_0 > _rtP -> P_4 ) { _rtB -> B_0_7_0 = _rtB -> B_0_5_0 ; }
else { _rtB -> B_0_7_0 = _rtB -> B_0_1_0 ; } } isHit = ssIsSampleHit ( S , 3
, 0 ) ; if ( isHit != 0 ) { _rtB -> B_0_8_0 = _rtDW ->
DiscreteTimeIntegrator_DSTATE ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> VariableTimeDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T appliedDelay ; appliedDelay = _rtB -> B_0_8_0 ; if (
appliedDelay > _rtP -> P_7 ) { appliedDelay = _rtP -> P_7 ; } if (
appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } B_0_9_0 =
AKF_CT1_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , * uBuffer ,
_rtDW -> VariableTimeDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay_IWORK . Last , _rtDW -> VariableTimeDelay_IWORK . Tail ,
_rtDW -> VariableTimeDelay_IWORK . Head , _rtP -> P_8 , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> VariableTimeDelay_IWORK .
CircularBufSize ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] == ssGetT ( S )
) ) ) ; } _rtB -> B_0_10_0 = _rtB -> B_0_7_0 * B_0_9_0 ; isHit =
ssIsSampleHit ( S , 6 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime (
S , 6 ) ; if ( ssGetTNextWasAdjusted ( S , 6 ) != 0 ) { _rtDW -> nextTime_e =
_ssGetVarNextHitTime ( S , 1 ) ; } if ( _rtDW -> justEnabled_k != 0 ) { _rtDW
-> justEnabled_k = 0 ; if ( taskTimeV >= _rtP -> P_12 ) { ratio = ( taskTimeV
- _rtP -> P_12 ) / _rtP -> P_10 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_l = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_10 + _rtP -> P_12 ) + _rtP -> P_11 * _rtP -> P_10 / 100.0 ; if ( taskTimeV
< ratio ) { _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_e = ratio ; }
else { _rtDW -> currentValue_o = 0 ; _rtDW -> nextTime_e = ( real_T ) (
numCycles + 1U ) * _rtP -> P_10 + _rtP -> P_12 ; } } else { _rtDW ->
numCompleteCycles_l = _rtP -> P_12 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue_o
= 0 ; _rtDW -> nextTime_e = _rtP -> P_12 ; } } else if ( _rtDW -> nextTime_e
<= taskTimeV ) { if ( _rtDW -> currentValue_o == 1 ) { _rtDW ->
currentValue_o = 0 ; _rtDW -> nextTime_e = ( real_T ) ( _rtDW ->
numCompleteCycles_l + 1LL ) * _rtP -> P_10 + _rtP -> P_12 ; } else { _rtDW ->
numCompleteCycles_l ++ ; _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_e =
( _rtP -> P_11 * _rtP -> P_10 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_l * _rtP -> P_10 ) + _rtP -> P_12 ; } }
_ssSetVarNextHitTime ( S , 1 , _rtDW -> nextTime_e ) ; if ( _rtDW ->
currentValue_o == 1 ) { _rtB -> B_0_11_0 = _rtP -> P_9 ; } else { _rtB ->
B_0_11_0 = 0.0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 )
{ if ( _rtDW -> DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0 ) { _rtB ->
B_0_12_0 = _rtDW -> DiscreteTimeIntegrator1_DSTATE ; } else if ( ( _rtB ->
B_0_11_0 <= 0.0 ) && ( _rtDW -> DiscreteTimeIntegrator1_PrevResetState == 1 )
) { _rtDW -> DiscreteTimeIntegrator1_DSTATE = _rtP -> P_14 ; _rtB -> B_0_12_0
= _rtDW -> DiscreteTimeIntegrator1_DSTATE ; } else { _rtB -> B_0_12_0 = _rtP
-> P_13 * _rtB -> B_0_10_0 + _rtDW -> DiscreteTimeIntegrator1_DSTATE ; }
isHit = 2044 ; uyIdx = _rtDW -> Buffer1_inBufPtrIdx ; if ( _rtDW ->
Buffer1_inBufPtrIdx > 2043 ) { for ( i = 0 ; i < 2044 - _rtDW ->
Buffer1_inBufPtrIdx ; i ++ ) { _rtDW -> Buffer1_CircBuf [ _rtDW ->
Buffer1_inBufPtrIdx + i ] = _rtB -> B_0_12_0 ; } uyIdx = 0 ; isHit = _rtDW ->
Buffer1_inBufPtrIdx ; } for ( i = 0 ; i < isHit - 2043 ; i ++ ) { _rtDW ->
Buffer1_CircBuf [ uyIdx + i ] = _rtB -> B_0_12_0 ; } _rtDW ->
Buffer1_inBufPtrIdx ++ ; if ( _rtDW -> Buffer1_inBufPtrIdx >= 2044 ) { _rtDW
-> Buffer1_inBufPtrIdx -= 2044 ; } _rtDW -> Buffer1_bufferLength ++ ; if (
_rtDW -> Buffer1_bufferLength > 2044 ) { _rtDW -> Buffer1_outBufPtrIdx = (
_rtDW -> Buffer1_outBufPtrIdx + _rtDW -> Buffer1_bufferLength ) - 2044 ; if (
_rtDW -> Buffer1_outBufPtrIdx > 2044 ) { _rtDW -> Buffer1_outBufPtrIdx -=
2044 ; } _rtDW -> Buffer1_bufferLength = 2044 ; } } isHit = ssIsSampleHit ( S
, 4 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Buffer1_bufferLength -= 1022 ; if (
_rtDW -> Buffer1_bufferLength < 0 ) { _rtDW -> Buffer1_outBufPtrIdx += _rtDW
-> Buffer1_bufferLength ; if ( _rtDW -> Buffer1_outBufPtrIdx < 0 ) { _rtDW ->
Buffer1_outBufPtrIdx += 2044 ; } _rtDW -> Buffer1_bufferLength = 0 ; } uyIdx
= 0 ; currentOffset = _rtDW -> Buffer1_outBufPtrIdx ; isHit = 1022 ; if (
_rtDW -> Buffer1_outBufPtrIdx > 1022 ) { for ( i = 0 ; i < 2044 - _rtDW ->
Buffer1_outBufPtrIdx ; i ++ ) { _rtB -> B_0_13_0 [ i ] = _rtDW ->
Buffer1_CircBuf [ _rtDW -> Buffer1_outBufPtrIdx + i ] ; } uyIdx = 2044 -
_rtDW -> Buffer1_outBufPtrIdx ; isHit = _rtDW -> Buffer1_outBufPtrIdx - 1022
; currentOffset = 0 ; } for ( i = 0 ; i < isHit ; i ++ ) { _rtB -> B_0_13_0 [
uyIdx + i ] = _rtDW -> Buffer1_CircBuf [ currentOffset + i ] ; }
currentOffset += isHit ; if ( currentOffset == 2044 ) { currentOffset = 0 ; }
_rtDW -> Buffer1_outBufPtrIdx = currentOffset ; for ( currentOffset = 0 ;
currentOffset < 1 ; currentOffset ++ ) { _rtDW -> Mean1_AccVal = _rtB ->
B_0_13_0 [ currentOffset ] ; i = 1 ; for ( isHit = 1020 ; isHit >= 0 ; isHit
-- ) { _rtDW -> Mean1_AccVal += _rtB -> B_0_13_0 [ currentOffset + i ] ; i ++
; } _rtB -> B_0_14_0 = _rtDW -> Mean1_AccVal / 1022.0 ; } ssCallAccelRunBlock
( S , 0 , 15 , SS_CALL_MDL_OUTPUTS ) ; i = 1 ; _rtB -> B_0_16_0 = _rtB ->
B_0_13_0 [ 0 ] ; for ( currentOffset = 0 ; currentOffset < 1021 ;
currentOffset ++ ) { if ( _rtB -> B_0_13_0 [ i ] > _rtB -> B_0_16_0 ) { _rtB
-> B_0_16_0 = _rtB -> B_0_13_0 [ i ] ; } i ++ ; } ssCallAccelRunBlock ( S , 0
, 17 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 0 , 18 , SS_CALL_MDL_OUTPUTS ) ; {
if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles , ssGetTaskTime ( S ,
3 ) , ( char * ) & _rtB -> B_0_12_0 + 0 ) ; } } _rtB -> B_0_20_0 = _rtP ->
P_16 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { tmp = 0U ;
tmp2 = 0U ; for ( i = 0 ; i < 9 ; i ++ ) { tmp = ( uint8_T ) ( ( uint32_T ) (
uint8_T ) ( ( uint32_T ) AKF_CT1_rtConstP . PNSequenceGenerator2_Polynomial [
i + 1 ] * _rtDW -> shiftReg_i [ i ] ) + tmp ) ; tmp2 = ( uint8_T ) ( (
uint32_T ) ( uint8_T ) ( ( uint32_T ) _rtDW -> shiftReg_i [ i ] *
AKF_CT1_rtConstP . pooled1 [ i ] ) + tmp2 ) ; } tmp &= 1 ; for ( i = 7 ; i >=
0 ; i -- ) { _rtDW -> shiftReg_i [ i + 1 ] = _rtDW -> shiftReg_i [ i ] ; }
_rtDW -> shiftReg_i [ 0U ] = tmp ; _rtB -> B_0_26_0 = ( ( ( tmp2 & 1U ) != 0U
) * _rtP -> P_23 + _rtP -> P_24 ) * _rtP -> P_25 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { if ( _rtB -> B_0_6_0 > _rtP -> P_17 ) {
_rtB -> B_0_27_0 = _rtB -> B_0_26_0 ; } else { _rtB -> B_0_27_0 = _rtB ->
B_0_0_0 ; } } UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID7 (
SimStruct * S , int_T tid ) { B_AKF_CT1_T * _rtB ; P_AKF_CT1_T * _rtP ; _rtP
= ( ( P_AKF_CT1_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_AKF_CT1_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_0_0_0 = _rtP -> P_18 ; _rtB -> B_0_1_0
= _rtP -> P_19 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_AKF_CT1_T * _rtB ;
DW_AKF_CT1_T * _rtDW ; P_AKF_CT1_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_AKF_CT1_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_AKF_CT1_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_AKF_CT1_T * ) _ssGetModelBlockIO ( S ) )
; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
DiscreteTimeIntegrator_DSTATE += _rtP -> P_5 * _rtB -> B_0_20_0 ; } { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> VariableTimeDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
VariableTimeDelay_IWORK . Head = ( ( _rtDW -> VariableTimeDelay_IWORK . Head
< ( _rtDW -> VariableTimeDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTimeDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTimeDelay_IWORK . Head == _rtDW -> VariableTimeDelay_IWORK . Tail ) {
if ( ! AKF_CT1_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTimeDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay_IWORK . Tail , & _rtDW -> VariableTimeDelay_IWORK . Head ,
& _rtDW -> VariableTimeDelay_IWORK . Last , simTime - _rtP -> P_7 , uBuffer ,
( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW -> VariableTimeDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTimeDelay_IWORK .
CircularBufSize ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] = _rtB -> B_0_27_0 ; }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator1_DSTATE = _rtP -> P_13 * _rtB -> B_0_10_0 + _rtB ->
B_0_12_0 ; if ( _rtB -> B_0_11_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator1_PrevResetState = 1 ; } else if ( _rtB -> B_0_11_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator1_PrevResetState = - 1 ; } else if (
_rtB -> B_0_11_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator1_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator1_PrevResetState = 2 ; } }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID7 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3894789305U ) ; ssSetChecksumVal ( S , 1 , 2045712910U ) ;
ssSetChecksumVal ( S , 2 , 1122361625U ) ; ssSetChecksumVal ( S , 3 ,
2221845762U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_AKF_CT1_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_AKF_CT1_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_AKF_CT1_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & AKF_CT1_rtDefaultP ) ; } static void mdlInitializeSampleTimes ( SimStruct
* S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID7 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
