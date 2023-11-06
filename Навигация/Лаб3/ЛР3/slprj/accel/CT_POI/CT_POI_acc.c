#include "CT_POI_acc.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include <float.h>
#include "CT_POI_acc_private.h"
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
boolean_T CT_POI_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T
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
CT_POI_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T
* uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
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
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } real_T
CT_POI_acc_rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T
bufSz , int_T head , int_T tail , int_T * pLast , real_T t , real_T tStart ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput , real_T
initOutput , real_T * appliedDelay ) { int_T n , k ; real_T f ; int_T kp1 ;
real_T tminustD , tL , tR , uD , uL , uR , fU ; real_T * tBuf = uBuf + bufSz
; real_T * xBuf = uBuf + 2 * bufSz ; if ( minorStepAndTAtLastMajorOutput ) {
if ( * pLast == head ) { * pLast = ( * pLast == 0 ) ? bufSz - 1 : * pLast - 1
; } head = ( head == 0 ) ? bufSz - 1 : head - 1 ; } if ( x <= 1 ) { return
initOutput ; } k = * pLast ; n = 0 ; for ( ; ; ) { n ++ ; if ( n > bufSz )
break ; if ( x - xBuf [ k ] > 1.0 ) { if ( k == head ) { int_T km1 ; f = ( x
- 1.0 - xBuf [ k ] ) / ( x - xBuf [ k ] ) ; tminustD = ( 1.0 - f ) * tBuf [ k
] + f * t ; km1 = k - 1 ; if ( km1 < 0 ) km1 = bufSz - 1 ; tL = tBuf [ km1 ]
; tR = tBuf [ k ] ; uL = uBuf [ km1 ] ; uR = uBuf [ k ] ; break ; } kp1 = k +
1 ; if ( kp1 == bufSz ) kp1 = 0 ; if ( x - xBuf [ kp1 ] <= 1.0 ) { f = ( x -
1.0 - xBuf [ k ] ) / ( xBuf [ kp1 ] - xBuf [ k ] ) ; tL = tBuf [ k ] ; tR =
tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ; tminustD = ( 1.0 - f ) *
tL + f * tR ; break ; } k = kp1 ; } else { if ( k == tail ) { f = ( x - 1.0 )
/ xBuf [ k ] ; if ( discrete ) { return ( uBuf [ tail ] ) ; } kp1 = k + 1 ;
if ( kp1 == bufSz ) kp1 = 0 ; tminustD = ( 1 - f ) * tStart + f * tBuf [ k ]
; tL = tBuf [ k ] ; tR = tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ;
break ; } k = k - 1 ; if ( k < 0 ) k = bufSz - 1 ; } } * pLast = k ; if ( tR
== tL ) { fU = 1.0 ; } else { fU = ( tminustD - tL ) / ( tR - tL ) ; } if (
discrete ) { uD = ( fU > ( 1.0 - fU ) ) ? uR : uL ; } else { uD = ( 1.0 - fU
) * uL + fU * uR ; } * appliedDelay = t - tminustD ; return uD ; } void
rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * *
path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * castedS = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( castedS ) ) {
_ssSet_slErrMsg ( castedS , diag ) ; } else { _ssDiscardDiagnostic ( castedS
, diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S , void * diag )
{ _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } static void
mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_1_19_0 ; B_CT_POI_T *
_rtB ; DW_CT_POI_T * _rtDW ; P_CT_POI_T * _rtP ; X_CT_POI_T * _rtX ; real_T
ratio ; real_T rtb_B_1_16_0 ; real_T rtb_B_1_17_0 ; real_T rtb_B_1_27_0 ;
real_T rtb_B_1_36_0 ; real_T rtb_B_1_3_0 ; real_T rtb_B_1_43_0 ; real_T
rtb_B_1_46_0 ; real_T rtb_B_1_8_0 ; int32_T currentOffset ; int32_T i ;
int32_T isHit ; int32_T uyIdx ; uint32_T numCycles ; uint32_T sigIdx ;
uint8_T tmp ; uint8_T tmp2 ; boolean_T rtb_B_1_47_0 ; _rtDW = ( ( DW_CT_POI_T
* ) ssGetRootDWork ( S ) ) ; _rtX = ( ( X_CT_POI_T * ) ssGetContStates ( S )
) ; _rtP = ( ( P_CT_POI_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_CT_POI_T *
) _ssGetModelBlockIO ( S ) ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> VariableTransportDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T appliedDelay ; appliedDelay = _rtB -> B_1_1_0_m ; if (
appliedDelay > _rtP -> P_0 ) { appliedDelay = _rtP -> P_0 ; } if (
appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_1_0_0 =
CT_POI_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , * uBuffer ,
_rtDW -> VariableTransportDelay1_IWORK . CircularBufSize , & _rtDW ->
VariableTransportDelay1_IWORK . Last , _rtDW -> VariableTransportDelay1_IWORK
. Tail , _rtDW -> VariableTransportDelay1_IWORK . Head , _rtP -> P_1 , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
VariableTransportDelay1_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay1_IWORK . Head ] == ssGetT ( S ) ) ) ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_1_1_0 = _rtB ->
B_1_0_0 ; isHit = 5110 ; uyIdx = _rtDW -> Buffer1_inBufPtrIdx ; if ( _rtDW ->
Buffer1_inBufPtrIdx > 5109 ) { for ( i = 0 ; i < 5110 - _rtDW ->
Buffer1_inBufPtrIdx ; i ++ ) { _rtDW -> Buffer1_CircBuf [ _rtDW ->
Buffer1_inBufPtrIdx + i ] = _rtB -> B_1_1_0 ; } uyIdx = 0 ; isHit = _rtDW ->
Buffer1_inBufPtrIdx ; } for ( i = 0 ; i < isHit - 5109 ; i ++ ) { _rtDW ->
Buffer1_CircBuf [ uyIdx + i ] = _rtB -> B_1_1_0 ; } _rtDW ->
Buffer1_inBufPtrIdx ++ ; if ( _rtDW -> Buffer1_inBufPtrIdx >= 5110 ) { _rtDW
-> Buffer1_inBufPtrIdx -= 5110 ; } _rtDW -> Buffer1_bufferLength ++ ; if (
_rtDW -> Buffer1_bufferLength > 5110 ) { _rtDW -> Buffer1_outBufPtrIdx = (
_rtDW -> Buffer1_outBufPtrIdx + _rtDW -> Buffer1_bufferLength ) - 5110 ; if (
_rtDW -> Buffer1_outBufPtrIdx > 5110 ) { _rtDW -> Buffer1_outBufPtrIdx -=
5110 ; } _rtDW -> Buffer1_bufferLength = 5110 ; } } isHit = ssIsSampleHit ( S
, 4 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Buffer1_bufferLength -= 2555 ; if (
_rtDW -> Buffer1_bufferLength < 0 ) { _rtDW -> Buffer1_outBufPtrIdx += _rtDW
-> Buffer1_bufferLength ; if ( _rtDW -> Buffer1_outBufPtrIdx < 0 ) { _rtDW ->
Buffer1_outBufPtrIdx += 5110 ; } _rtDW -> Buffer1_bufferLength = 0 ; } uyIdx
= 0 ; currentOffset = _rtDW -> Buffer1_outBufPtrIdx ; isHit = 2555 ; if (
_rtDW -> Buffer1_outBufPtrIdx > 2555 ) { for ( i = 0 ; i < 5110 - _rtDW ->
Buffer1_outBufPtrIdx ; i ++ ) { _rtB -> B_1_2_0_c [ i ] = _rtDW ->
Buffer1_CircBuf [ _rtDW -> Buffer1_outBufPtrIdx + i ] ; } uyIdx = 5110 -
_rtDW -> Buffer1_outBufPtrIdx ; isHit = _rtDW -> Buffer1_outBufPtrIdx - 2555
; currentOffset = 0 ; } for ( i = 0 ; i < isHit ; i ++ ) { _rtB -> B_1_2_0_c
[ uyIdx + i ] = _rtDW -> Buffer1_CircBuf [ currentOffset + i ] ; }
currentOffset += isHit ; if ( currentOffset == 5110 ) { currentOffset = 0 ; }
_rtDW -> Buffer1_outBufPtrIdx = currentOffset ; for ( i = 0 ; i < 1 ; i ++ )
{ _rtDW -> Variance1_AccVal = _rtB -> B_1_2_0_c [ i ] ; _rtDW ->
Variance1_SqData = _rtB -> B_1_2_0_c [ i ] * _rtB -> B_1_2_0_c [ i ] ;
currentOffset = 1 ; for ( isHit = 2553 ; isHit >= 0 ; isHit -- ) { uyIdx = i
+ currentOffset ; _rtDW -> Variance1_AccVal += _rtB -> B_1_2_0_c [ uyIdx ] ;
_rtDW -> Variance1_SqData += _rtB -> B_1_2_0_c [ uyIdx ] * _rtB -> B_1_2_0_c
[ uyIdx ] ; currentOffset ++ ; } rtb_B_1_3_0 = ( _rtDW -> Variance1_SqData -
_rtDW -> Variance1_AccVal * _rtDW -> Variance1_AccVal / 2555.0 ) / 2554.0 ; }
if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtDW -> Fcn1_DWORK1 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; _rtDW ->
Fcn1_DWORK1 = 0 ; } } else if ( rtb_B_1_3_0 < 0.0 ) { rtb_B_1_3_0 = 0.0 ;
_rtDW -> Fcn1_DWORK1 = 1 ; } rtb_B_1_3_0 = 10.0 * muDoubleScalarLog10 (
rtb_B_1_3_0 ) ; } _rtB -> B_1_5_0 = 0.0 ; for ( numCycles = 0U ; numCycles <
20U ; numCycles ++ ) { for ( sigIdx = _rtP -> P_48 [ numCycles ] ; sigIdx <
_rtP -> P_48 [ numCycles + 1U ] ; sigIdx ++ ) { _rtB -> B_1_5_0 += _rtP ->
P_5 [ sigIdx ] * _rtX -> AnalogFilterDesign_CSTATE [ numCycles ] ; } } for (
sigIdx = _rtP -> P_50 [ 0U ] ; sigIdx < _rtP -> P_50 [ 1U ] ; sigIdx ++ ) {
_rtB -> B_1_5_0 += _rtP -> P_6 * 0.0 ; } isHit = ssIsSampleHit ( S , 2 , 0 )
; if ( isHit != 0 ) { _rtB -> B_1_6_0 = _rtB -> B_1_5_0 ; isHit = 5110 ;
uyIdx = _rtDW -> Buffer3_inBufPtrIdx ; if ( _rtDW -> Buffer3_inBufPtrIdx >
5109 ) { for ( i = 0 ; i < 5110 - _rtDW -> Buffer3_inBufPtrIdx ; i ++ ) {
_rtDW -> Buffer3_CircBuf [ _rtDW -> Buffer3_inBufPtrIdx + i ] = _rtB ->
B_1_6_0 ; } uyIdx = 0 ; isHit = _rtDW -> Buffer3_inBufPtrIdx ; } for ( i = 0
; i < isHit - 5109 ; i ++ ) { _rtDW -> Buffer3_CircBuf [ uyIdx + i ] = _rtB
-> B_1_6_0 ; } _rtDW -> Buffer3_inBufPtrIdx ++ ; if ( _rtDW ->
Buffer3_inBufPtrIdx >= 5110 ) { _rtDW -> Buffer3_inBufPtrIdx -= 5110 ; }
_rtDW -> Buffer3_bufferLength ++ ; if ( _rtDW -> Buffer3_bufferLength > 5110
) { _rtDW -> Buffer3_outBufPtrIdx = ( _rtDW -> Buffer3_outBufPtrIdx + _rtDW
-> Buffer3_bufferLength ) - 5110 ; if ( _rtDW -> Buffer3_outBufPtrIdx > 5110
) { _rtDW -> Buffer3_outBufPtrIdx -= 5110 ; } _rtDW -> Buffer3_bufferLength =
5110 ; } } isHit = ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Buffer3_bufferLength -= 2555 ; if ( _rtDW -> Buffer3_bufferLength < 0 ) {
_rtDW -> Buffer3_outBufPtrIdx += _rtDW -> Buffer3_bufferLength ; if ( _rtDW
-> Buffer3_outBufPtrIdx < 0 ) { _rtDW -> Buffer3_outBufPtrIdx += 5110 ; }
_rtDW -> Buffer3_bufferLength = 0 ; } uyIdx = 0 ; currentOffset = _rtDW ->
Buffer3_outBufPtrIdx ; isHit = 2555 ; if ( _rtDW -> Buffer3_outBufPtrIdx >
2555 ) { for ( i = 0 ; i < 5110 - _rtDW -> Buffer3_outBufPtrIdx ; i ++ ) {
_rtB -> B_1_2_0_c [ i ] = _rtDW -> Buffer3_CircBuf [ _rtDW ->
Buffer3_outBufPtrIdx + i ] ; } uyIdx = 5110 - _rtDW -> Buffer3_outBufPtrIdx ;
isHit = _rtDW -> Buffer3_outBufPtrIdx - 2555 ; currentOffset = 0 ; } for ( i
= 0 ; i < isHit ; i ++ ) { _rtB -> B_1_2_0_c [ uyIdx + i ] = _rtDW ->
Buffer3_CircBuf [ currentOffset + i ] ; } currentOffset += isHit ; if (
currentOffset == 5110 ) { currentOffset = 0 ; } _rtDW -> Buffer3_outBufPtrIdx
= currentOffset ; for ( i = 0 ; i < 1 ; i ++ ) { _rtDW -> Variance2_AccVal =
_rtB -> B_1_2_0_c [ i ] ; _rtDW -> Variance2_SqData = _rtB -> B_1_2_0_c [ i ]
* _rtB -> B_1_2_0_c [ i ] ; currentOffset = 1 ; for ( isHit = 2553 ; isHit >=
0 ; isHit -- ) { uyIdx = i + currentOffset ; _rtDW -> Variance2_AccVal +=
_rtB -> B_1_2_0_c [ uyIdx ] ; _rtDW -> Variance2_SqData += _rtB -> B_1_2_0_c
[ uyIdx ] * _rtB -> B_1_2_0_c [ uyIdx ] ; currentOffset ++ ; } rtb_B_1_8_0 =
( _rtDW -> Variance2_SqData - _rtDW -> Variance2_AccVal * _rtDW ->
Variance2_AccVal / 2555.0 ) / 2554.0 ; } if ( ssIsMajorTimeStep ( S ) != 0 )
{ if ( _rtDW -> Fcn3_DWORK1 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; _rtDW ->
Fcn3_DWORK1 = 0 ; } } else if ( rtb_B_1_8_0 < 0.0 ) { rtb_B_1_8_0 = 0.0 ;
_rtDW -> Fcn3_DWORK1 = 1 ; } _rtB -> B_1_10_0 = rtb_B_1_3_0 - 10.0 *
muDoubleScalarLog10 ( rtb_B_1_8_0 ) ; ssCallAccelRunBlock ( S , 1 , 11 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_1_12_0 = _rtDW -> DiscreteTimeIntegrator_DSTATE_k ;
ssCallAccelRunBlock ( S , 1 , 13 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_1_14_0 =
_rtP -> P_9 ; } rtb_B_1_8_0 = _rtB -> B_1_0_0 + _rtB -> B_1_5_0 ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_1_16_0 =
ssGetTaskTime ( S , 2 ) ; rtb_B_1_17_0 = _rtP -> P_10 * rtb_B_1_16_0 ; _rtB
-> B_1_18_0 = muDoubleScalarSin ( rtb_B_1_17_0 ) ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> VariableTransportDelay_PWORK . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; real_T appliedDelay ; B_1_19_0 =
CT_POI_acc_rt_VTDelayfindtDInterpolate ( ( ( X_CT_POI_T * ) ssGetContStates (
S ) ) -> VariableTransportDelay_CSTATE , * uBuffer , _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK . Head , _rtDW -> VariableTransportDelay_IWORK .
Tail , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime , 0.0 , 1 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] == ssGetT ( S ) ) ) , _rtP -> P_12 , &
appliedDelay ) ; } _rtB -> B_1_20_0 = rtb_B_1_8_0 * _rtB -> B_1_18_0 *
B_1_19_0 ; isHit = ssIsSampleHit ( S , 6 , 0 ) ; if ( isHit != 0 ) {
rtb_B_1_3_0 = ssGetTaskTime ( S , 6 ) ; if ( ssGetTNextWasAdjusted ( S , 6 )
!= 0 ) { _rtDW -> nextTime = _ssGetVarNextHitTime ( S , 0 ) ; } if ( _rtDW ->
justEnabled != 0 ) { _rtDW -> justEnabled = 0 ; if ( rtb_B_1_3_0 >= _rtP ->
P_16 ) { ratio = ( rtb_B_1_3_0 - _rtP -> P_16 ) / _rtP -> P_14 ; numCycles =
( uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( (
real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++
; } _rtDW -> numCompleteCycles = numCycles ; ratio = ( ( real_T ) numCycles *
_rtP -> P_14 + _rtP -> P_16 ) + _rtP -> P_15 * _rtP -> P_14 / 100.0 ; if (
rtb_B_1_3_0 < ratio ) { _rtDW -> currentValue = 1 ; _rtDW -> nextTime = ratio
; } else { _rtDW -> currentValue = 0 ; _rtDW -> nextTime = ( real_T ) (
numCycles + 1U ) * _rtP -> P_14 + _rtP -> P_16 ; } } else { _rtDW ->
numCompleteCycles = _rtP -> P_16 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue = 0
; _rtDW -> nextTime = _rtP -> P_16 ; } } else if ( _rtDW -> nextTime <=
rtb_B_1_3_0 ) { if ( _rtDW -> currentValue == 1 ) { _rtDW -> currentValue = 0
; _rtDW -> nextTime = ( real_T ) ( _rtDW -> numCompleteCycles + 1LL ) * _rtP
-> P_14 + _rtP -> P_16 ; } else { _rtDW -> numCompleteCycles ++ ; _rtDW ->
currentValue = 1 ; _rtDW -> nextTime = ( _rtP -> P_15 * _rtP -> P_14 * 0.01 +
( real_T ) _rtDW -> numCompleteCycles * _rtP -> P_14 ) + _rtP -> P_16 ; } }
_ssSetVarNextHitTime ( S , 0 , _rtDW -> nextTime ) ; if ( _rtDW ->
currentValue == 1 ) { _rtB -> B_1_21_0 = _rtP -> P_13 ; } else { _rtB ->
B_1_21_0 = 0.0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 )
{ if ( _rtDW -> DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0 ) { _rtB ->
B_1_22_0 = _rtDW -> DiscreteTimeIntegrator1_DSTATE ; } else if ( ( _rtB ->
B_1_21_0 <= 0.0 ) && ( _rtDW -> DiscreteTimeIntegrator1_PrevResetState == 1 )
) { _rtDW -> DiscreteTimeIntegrator1_DSTATE = _rtP -> P_18 ; _rtB -> B_1_22_0
= _rtDW -> DiscreteTimeIntegrator1_DSTATE ; } else { _rtB -> B_1_22_0 = _rtP
-> P_17 * _rtB -> B_1_20_0 + _rtDW -> DiscreteTimeIntegrator1_DSTATE ; } _rtB
-> B_1_23_0 = muDoubleScalarCos ( rtb_B_1_17_0 ) ; } _rtB -> B_1_24_0 =
rtb_B_1_8_0 * _rtB -> B_1_23_0 * B_1_19_0 ; isHit = ssIsSampleHit ( S , 2 , 0
) ; if ( isHit != 0 ) { if ( _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE
!= 0 ) { _rtB -> B_1_25_0 = _rtDW -> DiscreteTimeIntegrator2_DSTATE ; } else
if ( ( _rtB -> B_1_21_0 <= 0.0 ) && ( _rtDW ->
DiscreteTimeIntegrator2_PrevResetState == 1 ) ) { _rtDW ->
DiscreteTimeIntegrator2_DSTATE = _rtP -> P_20 ; _rtB -> B_1_25_0 = _rtDW ->
DiscreteTimeIntegrator2_DSTATE ; } else { _rtB -> B_1_25_0 = _rtP -> P_19 *
_rtB -> B_1_24_0 + _rtDW -> DiscreteTimeIntegrator2_DSTATE ; } _rtB ->
B_1_26_0 = muDoubleScalarHypot ( _rtB -> B_1_22_0 , _rtB -> B_1_25_0 ) ; }
isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { rtb_B_1_27_0 = _rtB
-> B_1_26_0 ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { tmp
= 0U ; tmp2 = 0U ; for ( i = 0 ; i < 9 ; i ++ ) { tmp = ( uint8_T ) ( (
uint32_T ) ( uint8_T ) ( ( uint32_T ) CT_POI_rtConstP . pooled1 [ i + 1 ] *
_rtDW -> shiftReg [ i ] ) + tmp ) ; tmp2 = ( uint8_T ) ( ( uint32_T ) (
uint8_T ) ( ( uint32_T ) _rtDW -> shiftReg [ i ] * CT_POI_rtConstP . pooled2
[ i ] ) + tmp2 ) ; } tmp &= 1 ; for ( i = 7 ; i >= 0 ; i -- ) { _rtDW ->
shiftReg [ i + 1 ] = _rtDW -> shiftReg [ i ] ; } _rtDW -> shiftReg [ 0U ] =
tmp ; _rtB -> B_1_33_0 = ( ( ( tmp2 & 1U ) != 0U ) * _rtP -> P_37 + _rtP ->
P_38 ) * _rtP -> P_39 ; } _rtB -> B_1_34_0 = _rtB -> B_1_18_0 * _rtB ->
B_1_33_0 * rtb_B_1_8_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { if ( _rtDW -> DiscreteTimeIntegrator5_SYSTEM_ENABLE != 0 ) { _rtB ->
B_1_35_0 = _rtDW -> DiscreteTimeIntegrator5_DSTATE ; } else if ( ( _rtB ->
B_1_21_0 <= 0.0 ) && ( _rtDW -> DiscreteTimeIntegrator5_PrevResetState == 1 )
) { _rtDW -> DiscreteTimeIntegrator5_DSTATE = _rtP -> P_22 ; _rtB -> B_1_35_0
= _rtDW -> DiscreteTimeIntegrator5_DSTATE ; } else { _rtB -> B_1_35_0 = _rtP
-> P_21 * _rtB -> B_1_34_0 + _rtDW -> DiscreteTimeIntegrator5_DSTATE ; }
rtb_B_1_36_0 = _rtB -> B_1_35_0 * _rtB -> B_1_35_0 ; } _rtB -> B_1_37_0 =
_rtB -> B_1_23_0 * _rtB -> B_1_33_0 * rtb_B_1_8_0 ; isHit = ssIsSampleHit ( S
, 2 , 0 ) ; if ( isHit != 0 ) { if ( _rtDW ->
DiscreteTimeIntegrator6_SYSTEM_ENABLE != 0 ) { _rtB -> B_1_38_0 = _rtDW ->
DiscreteTimeIntegrator6_DSTATE ; } else if ( ( _rtB -> B_1_21_0 <= 0.0 ) && (
_rtDW -> DiscreteTimeIntegrator6_PrevResetState == 1 ) ) { _rtDW ->
DiscreteTimeIntegrator6_DSTATE = _rtP -> P_24 ; _rtB -> B_1_38_0 = _rtDW ->
DiscreteTimeIntegrator6_DSTATE ; } else { _rtB -> B_1_38_0 = _rtP -> P_23 *
_rtB -> B_1_37_0 + _rtDW -> DiscreteTimeIntegrator6_DSTATE ; } rtb_B_1_17_0 =
_rtB -> B_1_38_0 * _rtB -> B_1_38_0 + rtb_B_1_36_0 ; if ( rtb_B_1_17_0 < 0.0
) { rtb_B_1_17_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_1_17_0 )
) ; } else { rtb_B_1_17_0 = muDoubleScalarSqrt ( rtb_B_1_17_0 ) ; } _rtB ->
B_1_42_0 = rtb_B_1_17_0 * _rtB -> B_1_2_0 ; } isHit = ssIsSampleHit ( S , 5 ,
0 ) ; if ( isHit != 0 ) { rtb_B_1_43_0 = _rtB -> B_1_42_0 ; rtb_B_1_46_0 =
_rtP -> P_25 ; rtb_B_1_47_0 = ( muDoubleScalarSign ( rtb_B_1_27_0 - _rtB ->
B_1_42_0 ) > _rtP -> P_25 ) ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if (
isHit != 0 ) { tmp = 0U ; tmp2 = 0U ; for ( i = 0 ; i < 9 ; i ++ ) { tmp = (
uint8_T ) ( ( uint32_T ) ( uint8_T ) ( ( uint32_T ) CT_POI_rtConstP . pooled1
[ i + 1 ] * _rtDW -> shiftReg_h [ i ] ) + tmp ) ; tmp2 = ( uint8_T ) ( (
uint32_T ) ( uint8_T ) ( ( uint32_T ) _rtDW -> shiftReg_h [ i ] *
CT_POI_rtConstP . pooled2 [ i ] ) + tmp2 ) ; } tmp &= 1 ; for ( i = 7 ; i >=
0 ; i -- ) { _rtDW -> shiftReg_h [ i + 1 ] = _rtDW -> shiftReg_h [ i ] ; }
_rtDW -> shiftReg_h [ 0U ] = tmp ; _rtB -> B_1_53_0 = ( ( ( tmp2 & 1U ) != 0U
) * _rtP -> P_40 + _rtP -> P_41 ) * _rtP -> P_42 ; } _rtB -> B_1_54_0 = _rtB
-> B_1_53_0 * rtb_B_1_8_0 * _rtB -> B_1_18_0 ; isHit = ssIsSampleHit ( S , 2
, 0 ) ; if ( isHit != 0 ) { if ( _rtDW ->
DiscreteTimeIntegrator3_SYSTEM_ENABLE != 0 ) { _rtB -> B_1_55_0 = _rtDW ->
DiscreteTimeIntegrator3_DSTATE ; } else if ( ( _rtB -> B_1_21_0 <= 0.0 ) && (
_rtDW -> DiscreteTimeIntegrator3_PrevResetState == 1 ) ) { _rtDW ->
DiscreteTimeIntegrator3_DSTATE = _rtP -> P_27 ; _rtB -> B_1_55_0 = _rtDW ->
DiscreteTimeIntegrator3_DSTATE ; } else { _rtB -> B_1_55_0 = _rtP -> P_26 *
_rtB -> B_1_54_0 + _rtDW -> DiscreteTimeIntegrator3_DSTATE ; } } _rtB ->
B_1_56_0 = _rtB -> B_1_23_0 * _rtB -> B_1_53_0 * rtb_B_1_8_0 ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { if ( _rtDW ->
DiscreteTimeIntegrator4_SYSTEM_ENABLE != 0 ) { _rtB -> B_1_57_0 = _rtDW ->
DiscreteTimeIntegrator4_DSTATE ; } else if ( ( _rtB -> B_1_21_0 <= 0.0 ) && (
_rtDW -> DiscreteTimeIntegrator4_PrevResetState == 1 ) ) { _rtDW ->
DiscreteTimeIntegrator4_DSTATE = _rtP -> P_29 ; _rtB -> B_1_57_0 = _rtDW ->
DiscreteTimeIntegrator4_DSTATE ; } else { _rtB -> B_1_57_0 = _rtP -> P_28 *
_rtB -> B_1_56_0 + _rtDW -> DiscreteTimeIntegrator4_DSTATE ; } _rtB ->
B_1_58_0 = muDoubleScalarHypot ( _rtB -> B_1_55_0 , _rtB -> B_1_57_0 ) ; }
isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_1_63_0 =
_rtP -> P_51 [ ( muDoubleScalarSign ( _rtB -> B_1_58_0 - rtb_B_1_43_0 ) >
rtb_B_1_46_0 ) + ( ( uint32_T ) rtb_B_1_47_0 << 1 ) ] ; _rtB -> B_1_64_0 =
_rtDW -> DiscreteTimeIntegrator_DSTATE ; ssCallAccelRunBlock ( S , 1 , 65 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_1_66_0 = _rtP -> P_31 ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_1_67_0 = _rtP ->
P_32 * rtb_B_1_16_0 ; } isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0
) { _rtB -> B_1_68_0 = _rtP -> P_33 * _rtB -> B_1_64_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_1_71_0 =
muDoubleScalarCos ( _rtB -> B_1_67_0 + _rtB -> B_1_68_0 ) * _rtB -> B_1_53_0
; _rtB -> B_1_72_0 = _rtP -> P_34 ; ssCallAccelRunBlock ( S , 0 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID7 ( SimStruct * S , int_T tid ) { B_CT_POI_T * _rtB ;
DW_CT_POI_T * _rtDW ; P_CT_POI_T * _rtP ; real_T tmp ; _rtDW = ( (
DW_CT_POI_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_CT_POI_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_CT_POI_T * ) _ssGetModelBlockIO ( S ) )
; _rtB -> B_1_1_0_m = _rtP -> P_36 ; tmp = 1.0 / _rtP -> P_35 ; if (
ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtDW -> Fcn1_DWORK1_a != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; _rtDW ->
Fcn1_DWORK1_a = 0 ; } } else if ( tmp < 0.0 ) { tmp = 0.0 ; _rtDW ->
Fcn1_DWORK1_a = 1 ; } tmp = 2.0 * muDoubleScalarLog ( tmp ) ; if ( tmp < 0.0
) { _rtB -> B_1_2_0 = - muDoubleScalarSqrt ( - tmp ) ; } else { _rtB ->
B_1_2_0 = muDoubleScalarSqrt ( tmp ) ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_CT_POI_T * _rtB ;
DW_CT_POI_T * _rtDW ; P_CT_POI_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_CT_POI_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_CT_POI_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_CT_POI_T * ) _ssGetModelBlockIO ( S ) )
; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
VariableTransportDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT
( S ) ; _rtDW -> VariableTransportDelay1_IWORK . Head = ( ( _rtDW ->
VariableTransportDelay1_IWORK . Head < ( _rtDW ->
VariableTransportDelay1_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay1_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay1_IWORK . Head == _rtDW ->
VariableTransportDelay1_IWORK . Tail ) { if ( !
CT_POI_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay1_IWORK . CircularBufSize , & _rtDW ->
VariableTransportDelay1_IWORK . Tail , & _rtDW ->
VariableTransportDelay1_IWORK . Head , & _rtDW ->
VariableTransportDelay1_IWORK . Last , simTime - _rtP -> P_0 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW -> VariableTransportDelay1_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTransportDelay1_IWORK .
CircularBufSize ) [ _rtDW -> VariableTransportDelay1_IWORK . Head ] = simTime
; ( * uBuffer ) [ _rtDW -> VariableTransportDelay1_IWORK . Head ] = _rtB ->
B_1_71_0 ; } isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { _rtDW
-> DiscreteTimeIntegrator_DSTATE_k = ( uint8_T ) ( ( uint32_T ) _rtDW ->
DiscreteTimeIntegrator_DSTATE_k + _rtB -> B_1_63_0 ) ; } { real_T * * uBuffer
= ( real_T * * ) & _rtDW -> VariableTransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( S ) ; _rtDW -> VariableTransportDelay_IWORK .
Head = ( ( _rtDW -> VariableTransportDelay_IWORK . Head < ( _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay_IWORK . Head == _rtDW -> VariableTransportDelay_IWORK
. Tail ) { if ( ! CT_POI_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK . Tail , & _rtDW -> VariableTransportDelay_IWORK
. Head , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime - _rtP ->
P_11 , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW ->
VariableTransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"vtdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = simTime ; ( * uBuffer + 2 * _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = ( ( X_CT_POI_T * ) ssGetContStates (
S ) ) -> VariableTransportDelay_CSTATE ; ( * uBuffer ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = _rtB -> B_1_53_0 ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator1_DSTATE = _rtP -> P_17 * _rtB -> B_1_20_0 + _rtB ->
B_1_22_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator1_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator1_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator1_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator1_PrevResetState = 2 ; } _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE = _rtP -> P_19 * _rtB -> B_1_24_0 + _rtB ->
B_1_25_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator2_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator2_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator2_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator2_PrevResetState = 2 ; } _rtDW ->
DiscreteTimeIntegrator5_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator5_DSTATE = _rtP -> P_21 * _rtB -> B_1_34_0 + _rtB ->
B_1_35_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator5_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator5_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator5_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator5_PrevResetState = 2 ; } _rtDW ->
DiscreteTimeIntegrator6_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator6_DSTATE = _rtP -> P_23 * _rtB -> B_1_37_0 + _rtB ->
B_1_38_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator6_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator6_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator6_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator6_PrevResetState = 2 ; } _rtDW ->
DiscreteTimeIntegrator3_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator3_DSTATE = _rtP -> P_26 * _rtB -> B_1_54_0 + _rtB ->
B_1_55_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator3_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator3_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator3_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator3_PrevResetState = 2 ; } _rtDW ->
DiscreteTimeIntegrator4_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator4_DSTATE = _rtP -> P_28 * _rtB -> B_1_56_0 + _rtB ->
B_1_57_0 ; if ( _rtB -> B_1_21_0 > 0.0 ) { _rtDW ->
DiscreteTimeIntegrator4_PrevResetState = 1 ; } else if ( _rtB -> B_1_21_0 <
0.0 ) { _rtDW -> DiscreteTimeIntegrator4_PrevResetState = - 1 ; } else if (
_rtB -> B_1_21_0 == 0.0 ) { _rtDW -> DiscreteTimeIntegrator4_PrevResetState =
0 ; } else { _rtDW -> DiscreteTimeIntegrator4_PrevResetState = 2 ; } } isHit
= ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
DiscreteTimeIntegrator_DSTATE += _rtP -> P_30 * _rtB -> B_1_66_0 ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID7 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_CT_POI_T * _rtB ;
DW_CT_POI_T * _rtDW ; P_CT_POI_T * _rtP ; XDot_CT_POI_T * _rtXdot ;
X_CT_POI_T * _rtX ; int_T is ; uint32_T ri ; _rtDW = ( ( DW_CT_POI_T * )
ssGetRootDWork ( S ) ) ; _rtXdot = ( ( XDot_CT_POI_T * ) ssGetdX ( S ) ) ;
_rtX = ( ( X_CT_POI_T * ) ssGetContStates ( S ) ) ; _rtP = ( ( P_CT_POI_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_CT_POI_T * ) _ssGetModelBlockIO ( S ) )
; { } for ( is = 0 ; is < 20 ; is ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE
[ is ] = 0.0 ; } for ( is = 0 ; is < 20 ; is ++ ) { for ( ri = _rtP -> P_44 [
( uint32_T ) is ] ; ri < _rtP -> P_44 [ is + 1U ] ; ri ++ ) { _rtXdot ->
AnalogFilterDesign_CSTATE [ _rtP -> P_43 [ ri ] ] += _rtP -> P_3 [ ri ] *
_rtX -> AnalogFilterDesign_CSTATE [ ( uint32_T ) is ] ; } } for ( ri = _rtP
-> P_46 [ 0U ] ; ri < _rtP -> P_46 [ 1U ] ; ri ++ ) { _rtXdot ->
AnalogFilterDesign_CSTATE [ _rtP -> P_45 [ ri ] ] += _rtP -> P_4 [ ri ] * 0.0
; } { real_T instantDelay ; instantDelay = _rtB -> B_1_72_0 ; if (
instantDelay > _rtP -> P_11 ) { instantDelay = _rtP -> P_11 ; } if (
instantDelay < 0.0 ) { ( ( XDot_CT_POI_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE = 0 ; } else { ( ( XDot_CT_POI_T * ) ssGetdX (
S ) ) -> VariableTransportDelay_CSTATE = 1.0 / instantDelay ; } } } static
void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
4096766575U ) ; ssSetChecksumVal ( S , 1 , 1452117647U ) ; ssSetChecksumVal (
S , 2 , 1659148135U ) ; ssSetChecksumVal ( S , 3 , 3105068811U ) ; { mxArray
* slVerStructMat = ( NULL ) ; mxArray * slStrMat = mxCreateString (
"simulink" ) ; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , &
slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray *
slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == (
NULL ) ) { status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar
, 10 ) ; } } mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat )
; if ( ( status == 1 ) || ( strcmp ( slVerChar , "10.5" ) != 0 ) ) { return ;
} } ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if (
ssGetSizeofDWork ( S ) != sizeof ( DW_CT_POI_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_CT_POI_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_CT_POI_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & CT_POI_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID7 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
