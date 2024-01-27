#include "CT_POI.h"
#include "CT_POI_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include <float.h>
#include "CT_POI_private.h"
#include <time.h>
#include <stddef.h>
#include "rt_logging_mmi.h"
#include "CT_POI_capi.h"
#include "multiword_types.h"
#include "CT_POI_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 7 , & stopRequested ) ; }
rtExtModeShutdown ( 7 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 8 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T g51clj51xc ( void ) ; static real_T ifzdaitbfy (
real_T x ) ; static void ocbk0qxro31 ( uint32_T mt [ 625 ] , uint32_T seed )
; static void ih4ns52cn2 ( cqb32sjpki * obj ) ; static void d1js1a3jby3 (
uint32_T mt [ 625 ] , uint32_T u [ 2 ] ) ; static real_T mlav212mvxk (
uint32_T mt [ 625 ] ) ; static real_T ieteoqusqe ( void ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * uBuf ,
int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T
initOutput , boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput )
{ int_T i ; real_T yout , t1 , t2 , u1 , u2 ; real_T * tBuf = uBuf + bufSz ;
if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
real_T rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T bufSz ,
int_T head , int_T tail , int_T * pLast , real_T t , real_T tStart ,
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
) * uL + fU * uR ; } * appliedDelay = t - tminustD ; return uD ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } static real_T
g51clj51xc ( void ) { time_t rawtime ; struct tm expl_temp ; real_T dDateNum
; int32_T r ; int16_T cDaysMonthWise [ 12 ] ; boolean_T guard1 = false ;
cDaysMonthWise [ 0 ] = 0 ; cDaysMonthWise [ 1 ] = 31 ; cDaysMonthWise [ 2 ] =
59 ; cDaysMonthWise [ 3 ] = 90 ; cDaysMonthWise [ 4 ] = 120 ; cDaysMonthWise
[ 5 ] = 151 ; cDaysMonthWise [ 6 ] = 181 ; cDaysMonthWise [ 7 ] = 212 ;
cDaysMonthWise [ 8 ] = 243 ; cDaysMonthWise [ 9 ] = 273 ; cDaysMonthWise [ 10
] = 304 ; cDaysMonthWise [ 11 ] = 334 ; time ( & rawtime ) ; expl_temp = *
localtime ( & rawtime ) ; dDateNum = ( ( ( ( ( real_T ) ( expl_temp . tm_year
+ 1900 ) * 365.0 + muDoubleScalarCeil ( ( real_T ) ( expl_temp . tm_year +
1900 ) / 4.0 ) ) - muDoubleScalarCeil ( ( real_T ) ( expl_temp . tm_year +
1900 ) / 100.0 ) ) + muDoubleScalarCeil ( ( real_T ) ( expl_temp . tm_year +
1900 ) / 400.0 ) ) + ( real_T ) cDaysMonthWise [ expl_temp . tm_mon ] ) + (
real_T ) expl_temp . tm_mday ; if ( expl_temp . tm_mon + 1 > 2 ) { if (
expl_temp . tm_year + 1900 == 0 ) { r = 0 ; } else { r = ( int32_T )
muDoubleScalarRem ( expl_temp . tm_year + 1900 , 4.0 ) ; if ( r == 0 ) { r =
0 ; } else if ( expl_temp . tm_year + 1900 < 0 ) { r += 4 ; } } guard1 =
false ; if ( r == 0 ) { if ( expl_temp . tm_year + 1900 == 0 ) { r = 0 ; }
else { r = ( int32_T ) muDoubleScalarRem ( expl_temp . tm_year + 1900 , 100.0
) ; if ( r == 0 ) { r = 0 ; } else if ( expl_temp . tm_year + 1900 < 0 ) { r
+= 100 ; } } if ( r != 0 ) { dDateNum ++ ; } else { guard1 = true ; } } else
{ guard1 = true ; } if ( guard1 ) { if ( expl_temp . tm_year + 1900 == 0 ) {
r = 0 ; } else { r = ( int32_T ) muDoubleScalarRem ( expl_temp . tm_year +
1900 , 400.0 ) ; if ( r == 0 ) { r = 0 ; } else if ( expl_temp . tm_year +
1900 < 0 ) { r += 400 ; } } if ( r == 0 ) { dDateNum ++ ; } } } return ( ( (
real_T ) expl_temp . tm_hour * 3600.0 + ( real_T ) expl_temp . tm_min * 60.0
) + ( real_T ) expl_temp . tm_sec ) / 86400.0 + dDateNum ; } static real_T
ifzdaitbfy ( real_T x ) { real_T r ; if ( muDoubleScalarIsNaN ( x ) ||
muDoubleScalarIsInf ( x ) ) { r = ( rtNaN ) ; } else if ( x == 0.0 ) { r =
0.0 ; } else { r = muDoubleScalarRem ( x , 2.147483647E+9 ) ; if ( r == 0.0 )
{ r = 0.0 ; } else if ( x < 0.0 ) { r += 2.147483647E+9 ; } } return r ; }
static void ocbk0qxro31 ( uint32_T mt [ 625 ] , uint32_T seed ) { int32_T
b_mti ; uint32_T r ; r = seed ; mt [ 0 ] = seed ; for ( b_mti = 0 ; b_mti <
623 ; b_mti ++ ) { r = ( ( r >> 30U ^ r ) * 1812433253U + ( uint32_T ) b_mti
) + 1U ; mt [ b_mti + 1 ] = r ; } mt [ 624 ] = 624U ; } static void
ih4ns52cn2 ( cqb32sjpki * obj ) { time_t eTime ; time_t eTime_p ; j3latrcolp
varSizes ; real_T s ; real_T x ; int32_T b_statei ; int32_T exitg1 ; uint32_T
r ; obj -> isInitialized = 1 ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ]
= 1U ; for ( b_statei = 0 ; b_statei < 6 ; b_statei ++ ) { varSizes . f1 [
b_statei + 2 ] = 1U ; } obj -> inputVarSize = varSizes ; x = g51clj51xc ( ) *
8.64E+6 ; s = ifzdaitbfy ( muDoubleScalarFloor ( x ) ) ; eTime = time ( NULL
) ; do { exitg1 = 0 ; eTime_p = time ( NULL ) ; if ( ( int32_T ) eTime_p <= (
int32_T ) eTime + 1 ) { x = g51clj51xc ( ) * 8.64E+6 ; if ( s != ifzdaitbfy (
muDoubleScalarFloor ( x ) ) ) { exitg1 = 1 ; } } else { exitg1 = 1 ; } }
while ( exitg1 == 0 ) ; x = muDoubleScalarRound ( s ) ; if ( x <
4.294967296E+9 ) { if ( x >= 0.0 ) { rtDW . m14sbehec2 = ( uint32_T ) x ; }
else { rtDW . m14sbehec2 = 0U ; } } else if ( x >= 4.294967296E+9 ) { rtDW .
m14sbehec2 = MAX_uint32_T ; } else { rtDW . m14sbehec2 = 0U ; } ocbk0qxro31 (
rtDW . g0ulyhynln , rtDW . m14sbehec2 ) ; obj -> pStream . MtGenerator . Seed
= 67U ; r = obj -> pStream . MtGenerator . Seed ; obj -> pStream .
MtGenerator . State [ 0 ] = r ; for ( b_statei = 0 ; b_statei < 623 ;
b_statei ++ ) { r = ( ( r >> 30U ^ r ) * 1812433253U + ( uint32_T ) b_statei
) + 1U ; obj -> pStream . MtGenerator . State [ b_statei + 1 ] = r ; } obj ->
pStream . MtGenerator . State [ 624 ] = 624U ; obj -> pStream . Generator = &
obj -> pStream . MtGenerator ; obj -> pNumChanFromProp = 1.0 ; x = obj -> SNR
/ 10.0 ; x = obj -> SignalPower / muDoubleScalarPower ( 10.0 , x ) ; obj ->
pStd = 0.0 ; obj -> pStd = muDoubleScalarSqrt ( x ) ; obj ->
pFirstInputNumChan = 1.0 ; obj -> pIsVarChannel = false ; obj ->
TunablePropsChanged = false ; } static void d1js1a3jby3 ( uint32_T mt [ 625 ]
, uint32_T u [ 2 ] ) { int32_T b_j ; int32_T b_kk ; uint32_T mti ; uint32_T y
; for ( b_j = 0 ; b_j < 2 ; b_j ++ ) { mti = mt [ 624 ] + 1U ; if ( mt [ 624
] + 1U >= 625U ) { for ( b_kk = 0 ; b_kk < 227 ; b_kk ++ ) { y = ( mt [ b_kk
+ 1 ] & 2147483647U ) | ( mt [ b_kk ] & 2147483648U ) ; if ( ( y & 1U ) == 0U
) { mti = y >> 1U ; } else { mti = y >> 1U ^ 2567483615U ; } mt [ b_kk ] = mt
[ b_kk + 397 ] ^ mti ; } for ( b_kk = 0 ; b_kk < 396 ; b_kk ++ ) { y = ( mt [
b_kk + 227 ] & 2147483648U ) | ( mt [ b_kk + 228 ] & 2147483647U ) ; if ( ( y
& 1U ) == 0U ) { mti = y >> 1U ; } else { mti = y >> 1U ^ 2567483615U ; } mt
[ b_kk + 227 ] = mt [ b_kk ] ^ mti ; } y = ( mt [ 623 ] & 2147483648U ) | (
mt [ 0 ] & 2147483647U ) ; if ( ( y & 1U ) == 0U ) { mti = y >> 1U ; } else {
mti = y >> 1U ^ 2567483615U ; } mt [ 623 ] = mt [ 396 ] ^ mti ; mti = 1U ; }
y = mt [ ( int32_T ) mti - 1 ] ; mt [ 624 ] = mti ; y ^= y >> 11U ; y ^= y <<
7U & 2636928640U ; y ^= y << 15U & 4022730752U ; u [ b_j ] = y >> 18U ^ y ; }
} static real_T mlav212mvxk ( uint32_T mt [ 625 ] ) { real_T r ; int32_T
exitg1 ; int32_T k ; uint32_T b_u [ 2 ] ; uint32_T r_p ; boolean_T b_isvalid
; boolean_T exitg2 ; do { exitg1 = 0 ; d1js1a3jby3 ( mt , b_u ) ; r = ( (
real_T ) ( b_u [ 0 ] >> 5U ) * 6.7108864E+7 + ( real_T ) ( b_u [ 1 ] >> 6U )
) * 1.1102230246251565E-16 ; if ( r == 0.0 ) { if ( ( mt [ 624 ] >= 1U ) && (
mt [ 624 ] < 625U ) ) { b_isvalid = false ; k = 0 ; exitg2 = false ; while (
( ! exitg2 ) && ( k + 1 < 625 ) ) { if ( mt [ k ] == 0U ) { k ++ ; } else {
b_isvalid = true ; exitg2 = true ; } } } else { b_isvalid = false ; } if ( !
b_isvalid ) { r_p = 5489U ; mt [ 0 ] = 5489U ; for ( k = 0 ; k < 623 ; k ++ )
{ r_p = ( ( r_p >> 30U ^ r_p ) * 1812433253U + ( uint32_T ) k ) + 1U ; mt [ k
+ 1 ] = r_p ; } mt [ 624 ] = 624U ; } } else { exitg1 = 1 ; } } while (
exitg1 == 0 ) ; return r ; } static real_T ieteoqusqe ( void ) { real_T xi [
257 ] ; real_T d_u ; real_T r ; real_T x ; int32_T i ; uint32_T u32 [ 2 ] ;
static const real_T tmp [ 257 ] = { 1.0 , 0.977101701267673 ,
0.959879091800108 , 0.9451989534423 , 0.932060075959231 , 0.919991505039348 ,
0.908726440052131 , 0.898095921898344 , 0.887984660755834 , 0.878309655808918
, 0.869008688036857 , 0.860033621196332 , 0.851346258458678 ,
0.842915653112205 , 0.834716292986884 , 0.826726833946222 , 0.818929191603703
, 0.811307874312656 , 0.803849483170964 , 0.796542330422959 ,
0.789376143566025 , 0.782341832654803 , 0.775431304981187 , 0.768637315798486
, 0.761953346836795 , 0.755373506507096 , 0.748892447219157 ,
0.742505296340151 , 0.736207598126863 , 0.729995264561476 , 0.72386453346863
, 0.717811932630722 , 0.711834248878248 , 0.705928501332754 ,
0.700091918136512 , 0.694321916126117 , 0.688616083004672 , 0.682972161644995
, 0.677388036218774 , 0.671861719897082 , 0.66639134390875 ,
0.660975147776663 , 0.655611470579697 , 0.650298743110817 , 0.645035480820822
, 0.639820277453057 , 0.634651799287624 , 0.629528779924837 ,
0.624450015547027 , 0.619414360605834 , 0.614420723888914 , 0.609468064925773
, 0.604555390697468 , 0.599681752619125 , 0.594846243767987 ,
0.590047996332826 , 0.585286179263371 , 0.580559996100791 , 0.575868682972354
, 0.571211506735253 , 0.566587763256165 , 0.561996775814525 ,
0.557437893618766 , 0.552910490425833 , 0.548413963255266 , 0.543947731190026
, 0.539511234256952 , 0.535103932380458 , 0.530725304403662 ,
0.526374847171684 , 0.522052074672322 , 0.517756517229756 , 0.513487720747327
, 0.509245245995748 , 0.505028667943468 , 0.500837575126149 ,
0.49667156905249 , 0.492530263643869 , 0.488413284705458 , 0.484320269426683
, 0.480250865909047 , 0.476204732719506 , 0.47218153846773 ,
0.468180961405694 , 0.464202689048174 , 0.460246417812843 , 0.456311852678716
, 0.452398706861849 , 0.448506701507203 , 0.444635565395739 ,
0.440785034665804 , 0.436954852547985 , 0.433144769112652 , 0.429354541029442
, 0.425583931338022 , 0.421832709229496 , 0.418100649837848 ,
0.414387534040891 , 0.410693148270188 , 0.407017284329473 , 0.403359739221114
, 0.399720314980197 , 0.396098818515832 , 0.392495061459315 ,
0.388908860018789 , 0.385340034840077 , 0.381788410873393 , 0.378253817245619
, 0.374736087137891 , 0.371235057668239 , 0.367750569779032 ,
0.364282468129004 , 0.360830600989648 , 0.357394820145781 , 0.353974980800077
, 0.350570941481406 , 0.347182563956794 , 0.343809713146851 ,
0.340452257044522 , 0.337110066637006 , 0.333783015830718 , 0.330470981379163
, 0.327173842813601 , 0.323891482376391 , 0.320623784956905 ,
0.317370638029914 , 0.314131931596337 , 0.310907558126286 , 0.307697412504292
, 0.30450139197665 , 0.301319396100803 , 0.298151326696685 ,
0.294997087799962 , 0.291856585617095 , 0.288729728482183 , 0.285616426815502
, 0.282516593083708 , 0.279430141761638 , 0.276356989295668 ,
0.273297054068577 , 0.270250256365875 , 0.267216518343561 , 0.264195763997261
, 0.261187919132721 , 0.258192911337619 , 0.255210669954662 ,
0.252241126055942 , 0.249284212418529 , 0.246339863501264 , 0.24340801542275
, 0.240488605940501 , 0.237581574431238 , 0.23468686187233 ,
0.231804410824339 , 0.228934165414681 , 0.226076071322381 , 0.223230075763918
, 0.220396127480152 , 0.217574176724331 , 0.214764175251174 ,
0.211966076307031 , 0.209179834621125 , 0.206405406397881 , 0.203642749310335
, 0.200891822494657 , 0.198152586545776 , 0.195425003514135 ,
0.192709036903589 , 0.190004651670465 , 0.187311814223801 , 0.1846304924268 ,
0.181960655599523 , 0.179302274522848 , 0.176655321443735 , 0.174019770081839
, 0.171395595637506 , 0.168782774801212 , 0.166181285764482 ,
0.163591108232366 , 0.161012223437511 , 0.158444614155925 , 0.15588826472448
, 0.153343161060263 , 0.150809290681846 , 0.148286642732575 ,
0.145775208005994 , 0.143274978973514 , 0.140785949814445 , 0.138308116448551
, 0.135841476571254 , 0.133386029691669 , 0.130941777173644 , 0.12850872228 ,
0.126086870220186 , 0.123676228201597 , 0.12127680548479 , 0.11888861344291 ,
0.116511665625611 , 0.114145977827839 , 0.111791568163838 , 0.109448457146812
, 0.107116667774684 , 0.104796225622487 , 0.102487158941935 ,
0.10018949876881 , 0.0979032790388625 , 0.095628536713009 , 0.093365311912691
, 0.0911136480663738 , 0.0888735920682759 , 0.0866451944505581 ,
0.0844285095703535 , 0.082223595813203 , 0.0800305158146631 ,
0.0778493367020961 , 0.0756801303589272 , 0.0735229737139814 ,
0.0713779490588905 , 0.0692451443970068 , 0.0671246538277886 ,
0.065016577971243 , 0.0629210244377582 , 0.06083810834954 ,
0.0587679529209339 , 0.0567106901062031 , 0.0546664613248891 ,
0.0526354182767924 , 0.0506177238609479 , 0.0486135532158687 ,
0.0466230949019305 , 0.0446465522512946 , 0.0426841449164746 ,
0.0407361106559411 , 0.0388027074045262 , 0.0368842156885674 ,
0.0349809414617162 , 0.0330932194585786 , 0.0312214171919203 ,
0.0293659397581334 , 0.0275272356696031 , 0.0257058040085489 ,
0.0239022033057959 , 0.0221170627073089 , 0.0203510962300445 ,
0.0186051212757247 , 0.0168800831525432 , 0.0151770883079353 ,
0.0134974506017399 , 0.0118427578579079 , 0.0102149714397015 ,
0.00861658276939875 , 0.00705087547137324 , 0.00552240329925101 ,
0.00403797259336304 , 0.00260907274610216 , 0.0012602859304986 ,
0.000477467764609386 } ; const real_T * fitab ; int32_T exitg1 ; xi [ 0 ] =
0.0 ; xi [ 1 ] = 0.215241895984875 ; xi [ 2 ] = 0.286174591792068 ; xi [ 3 ]
= 0.335737519214422 ; xi [ 4 ] = 0.375121332878378 ; xi [ 5 ] =
0.408389134611989 ; xi [ 6 ] = 0.43751840220787 ; xi [ 7 ] = 0.46363433679088
; xi [ 8 ] = 0.487443966139235 ; xi [ 9 ] = 0.50942332960209 ; xi [ 10 ] =
0.529909720661557 ; xi [ 11 ] = 0.549151702327164 ; xi [ 12 ] =
0.567338257053817 ; xi [ 13 ] = 0.584616766106378 ; xi [ 14 ] =
0.601104617755991 ; xi [ 15 ] = 0.61689699000775 ; xi [ 16 ] =
0.63207223638606 ; xi [ 17 ] = 0.646695714894993 ; xi [ 18 ] =
0.660822574244419 ; xi [ 19 ] = 0.674499822837293 ; xi [ 20 ] =
0.687767892795788 ; xi [ 21 ] = 0.700661841106814 ; xi [ 22 ] =
0.713212285190975 ; xi [ 23 ] = 0.725446140909999 ; xi [ 24 ] =
0.737387211434295 ; xi [ 25 ] = 0.749056662017815 ; xi [ 26 ] =
0.760473406430107 ; xi [ 27 ] = 0.771654424224568 ; xi [ 28 ] =
0.782615023307232 ; xi [ 29 ] = 0.793369058840623 ; xi [ 30 ] =
0.80392911698997 ; xi [ 31 ] = 0.814306670135215 ; xi [ 32 ] =
0.824512208752291 ; xi [ 33 ] = 0.834555354086381 ; xi [ 34 ] =
0.844444954909153 ; xi [ 35 ] = 0.854189171008163 ; xi [ 36 ] =
0.863795545553308 ; xi [ 37 ] = 0.87327106808886 ; xi [ 38 ] =
0.882622229585165 ; xi [ 39 ] = 0.891855070732941 ; xi [ 40 ] =
0.900975224461221 ; xi [ 41 ] = 0.909987953496718 ; xi [ 42 ] =
0.91889818364959 ; xi [ 43 ] = 0.927710533401999 ; xi [ 44 ] =
0.936429340286575 ; xi [ 45 ] = 0.945058684468165 ; xi [ 46 ] =
0.953602409881086 ; xi [ 47 ] = 0.96206414322304 ; xi [ 48 ] =
0.970447311064224 ; xi [ 49 ] = 0.978755155294224 ; xi [ 50 ] =
0.986990747099062 ; xi [ 51 ] = 0.99515699963509 ; xi [ 52 ] =
1.00325667954467 ; xi [ 53 ] = 1.01129241744 ; xi [ 54 ] = 1.01926671746548 ;
xi [ 55 ] = 1.02718196603564 ; xi [ 56 ] = 1.03504043983344 ; xi [ 57 ] =
1.04284431314415 ; xi [ 58 ] = 1.05059566459093 ; xi [ 59 ] =
1.05829648333067 ; xi [ 60 ] = 1.06594867476212 ; xi [ 61 ] =
1.07355406579244 ; xi [ 62 ] = 1.0811144097034 ; xi [ 63 ] = 1.08863139065398
; xi [ 64 ] = 1.09610662785202 ; xi [ 65 ] = 1.10354167942464 ; xi [ 66 ] =
1.11093804601357 ; xi [ 67 ] = 1.11829717411934 ; xi [ 68 ] =
1.12562045921553 ; xi [ 69 ] = 1.13290924865253 ; xi [ 70 ] =
1.14016484436815 ; xi [ 71 ] = 1.14738850542085 ; xi [ 72 ] =
1.15458145035993 ; xi [ 73 ] = 1.16174485944561 ; xi [ 74 ] =
1.16887987673083 ; xi [ 75 ] = 1.17598761201545 ; xi [ 76 ] =
1.18306914268269 ; xi [ 77 ] = 1.19012551542669 ; xi [ 78 ] =
1.19715774787944 ; xi [ 79 ] = 1.20416683014438 ; xi [ 80 ] = 1.2111537262437
; xi [ 81 ] = 1.21811937548548 ; xi [ 82 ] = 1.22506469375653 ; xi [ 83 ] =
1.23199057474614 ; xi [ 84 ] = 1.23889789110569 ; xi [ 85 ] =
1.24578749554863 ; xi [ 86 ] = 1.2526602218949 ; xi [ 87 ] = 1.25951688606371
; xi [ 88 ] = 1.26635828701823 ; xi [ 89 ] = 1.27318520766536 ; xi [ 90 ] =
1.27999841571382 ; xi [ 91 ] = 1.28679866449324 ; xi [ 92 ] =
1.29358669373695 ; xi [ 93 ] = 1.30036323033084 ; xi [ 94 ] =
1.30712898903073 ; xi [ 95 ] = 1.31388467315022 ; xi [ 96 ] =
1.32063097522106 ; xi [ 97 ] = 1.32736857762793 ; xi [ 98 ] =
1.33409815321936 ; xi [ 99 ] = 1.3408203658964 ; xi [ 100 ] =
1.34753587118059 ; xi [ 101 ] = 1.35424531676263 ; xi [ 102 ] =
1.36094934303328 ; xi [ 103 ] = 1.36764858359748 ; xi [ 104 ] =
1.37434366577317 ; xi [ 105 ] = 1.38103521107586 ; xi [ 106 ] =
1.38772383568998 ; xi [ 107 ] = 1.39441015092814 ; xi [ 108 ] =
1.40109476367925 ; xi [ 109 ] = 1.4077782768464 ; xi [ 110 ] =
1.41446128977547 ; xi [ 111 ] = 1.42114439867531 ; xi [ 112 ] =
1.42782819703026 ; xi [ 113 ] = 1.43451327600589 ; xi [ 114 ] =
1.44120022484872 ; xi [ 115 ] = 1.44788963128058 ; xi [ 116 ] =
1.45458208188841 ; xi [ 117 ] = 1.46127816251028 ; xi [ 118 ] =
1.46797845861808 ; xi [ 119 ] = 1.47468355569786 ; xi [ 120 ] =
1.48139403962819 ; xi [ 121 ] = 1.48811049705745 ; xi [ 122 ] =
1.49483351578049 ; xi [ 123 ] = 1.50156368511546 ; xi [ 124 ] =
1.50830159628131 ; xi [ 125 ] = 1.51504784277671 ; xi [ 126 ] =
1.521803020761 ; xi [ 127 ] = 1.52856772943771 ; xi [ 128 ] =
1.53534257144151 ; xi [ 129 ] = 1.542128153229 ; xi [ 130 ] =
1.54892508547417 ; xi [ 131 ] = 1.55573398346918 ; xi [ 132 ] =
1.56255546753104 ; xi [ 133 ] = 1.56939016341512 ; xi [ 134 ] =
1.57623870273591 ; xi [ 135 ] = 1.58310172339603 ; xi [ 136 ] =
1.58997987002419 ; xi [ 137 ] = 1.59687379442279 ; xi [ 138 ] =
1.60378415602609 ; xi [ 139 ] = 1.61071162236983 ; xi [ 140 ] =
1.61765686957301 ; xi [ 141 ] = 1.62462058283303 ; xi [ 142 ] =
1.63160345693487 ; xi [ 143 ] = 1.63860619677555 ; xi [ 144 ] =
1.64562951790478 ; xi [ 145 ] = 1.65267414708306 ; xi [ 146 ] =
1.65974082285818 ; xi [ 147 ] = 1.66683029616166 ; xi [ 148 ] =
1.67394333092612 ; xi [ 149 ] = 1.68108070472517 ; xi [ 150 ] =
1.68824320943719 ; xi [ 151 ] = 1.69543165193456 ; xi [ 152 ] =
1.70264685479992 ; xi [ 153 ] = 1.7098896570713 ; xi [ 154 ] =
1.71716091501782 ; xi [ 155 ] = 1.72446150294804 ; xi [ 156 ] =
1.73179231405296 ; xi [ 157 ] = 1.73915426128591 ; xi [ 158 ] =
1.74654827828172 ; xi [ 159 ] = 1.75397532031767 ; xi [ 160 ] =
1.76143636531891 ; xi [ 161 ] = 1.76893241491127 ; xi [ 162 ] =
1.77646449552452 ; xi [ 163 ] = 1.78403365954944 ; xi [ 164 ] =
1.79164098655216 ; xi [ 165 ] = 1.79928758454972 ; xi [ 166 ] =
1.80697459135082 ; xi [ 167 ] = 1.81470317596628 ; xi [ 168 ] =
1.82247454009388 ; xi [ 169 ] = 1.83028991968276 ; xi [ 170 ] =
1.83815058658281 ; xi [ 171 ] = 1.84605785028518 ; xi [ 172 ] =
1.8540130597602 ; xi [ 173 ] = 1.86201760539967 ; xi [ 174 ] =
1.87007292107127 ; xi [ 175 ] = 1.878180486293 ; xi [ 176 ] =
1.88634182853678 ; xi [ 177 ] = 1.8945585256707 ; xi [ 178 ] =
1.90283220855043 ; xi [ 179 ] = 1.91116456377125 ; xi [ 180 ] =
1.91955733659319 ; xi [ 181 ] = 1.92801233405266 ; xi [ 182 ] =
1.93653142827569 ; xi [ 183 ] = 1.94511656000868 ; xi [ 184 ] =
1.95376974238465 ; xi [ 185 ] = 1.96249306494436 ; xi [ 186 ] =
1.97128869793366 ; xi [ 187 ] = 1.98015889690048 ; xi [ 188 ] =
1.98910600761744 ; xi [ 189 ] = 1.99813247135842 ; xi [ 190 ] =
2.00724083056053 ; xi [ 191 ] = 2.0164337349062 ; xi [ 192 ] =
2.02571394786385 ; xi [ 193 ] = 2.03508435372962 ; xi [ 194 ] =
2.04454796521753 ; xi [ 195 ] = 2.05410793165065 ; xi [ 196 ] =
2.06376754781173 ; xi [ 197 ] = 2.07353026351874 ; xi [ 198 ] =
2.0833996939983 ; xi [ 199 ] = 2.09337963113879 ; xi [ 200 ] =
2.10347405571488 ; xi [ 201 ] = 2.11368715068665 ; xi [ 202 ] =
2.12402331568952 ; xi [ 203 ] = 2.13448718284602 ; xi [ 204 ] =
2.14508363404789 ; xi [ 205 ] = 2.15581781987674 ; xi [ 206 ] =
2.16669518035431 ; xi [ 207 ] = 2.17772146774029 ; xi [ 208 ] =
2.18890277162636 ; xi [ 209 ] = 2.20024554661128 ; xi [ 210 ] =
2.21175664288416 ; xi [ 211 ] = 2.22344334009251 ; xi [ 212 ] =
2.23531338492992 ; xi [ 213 ] = 2.24737503294739 ; xi [ 214 ] =
2.25963709517379 ; xi [ 215 ] = 2.27210899022838 ; xi [ 216 ] =
2.28480080272449 ; xi [ 217 ] = 2.29772334890286 ; xi [ 218 ] =
2.31088825060137 ; xi [ 219 ] = 2.32430801887113 ; xi [ 220 ] =
2.33799614879653 ; xi [ 221 ] = 2.35196722737914 ; xi [ 222 ] =
2.36623705671729 ; xi [ 223 ] = 2.38082279517208 ; xi [ 224 ] =
2.39574311978193 ; xi [ 225 ] = 2.41101841390112 ; xi [ 226 ] =
2.42667098493715 ; xi [ 227 ] = 2.44272531820036 ; xi [ 228 ] =
2.4592083743347 ; xi [ 229 ] = 2.47614993967052 ; xi [ 230 ] =
2.49358304127105 ; xi [ 231 ] = 2.51154444162669 ; xi [ 232 ] =
2.53007523215985 ; xi [ 233 ] = 2.54922155032478 ; xi [ 234 ] =
2.56903545268184 ; xi [ 235 ] = 2.58957598670829 ; xi [ 236 ] =
2.61091051848882 ; xi [ 237 ] = 2.63311639363158 ; xi [ 238 ] =
2.65628303757674 ; xi [ 239 ] = 2.68051464328574 ; xi [ 240 ] =
2.70593365612306 ; xi [ 241 ] = 2.73268535904401 ; xi [ 242 ] =
2.76094400527999 ; xi [ 243 ] = 2.79092117400193 ; xi [ 244 ] =
2.82287739682644 ; xi [ 245 ] = 2.85713873087322 ; xi [ 246 ] =
2.89412105361341 ; xi [ 247 ] = 2.93436686720889 ; xi [ 248 ] =
2.97860327988184 ; xi [ 249 ] = 3.02783779176959 ; xi [ 250 ] =
3.08352613200214 ; xi [ 251 ] = 3.147889289518 ; xi [ 252 ] = 3.2245750520478
; xi [ 253 ] = 3.32024473383983 ; xi [ 254 ] = 3.44927829856143 ; xi [ 255 ]
= 3.65415288536101 ; xi [ 256 ] = 3.91075795952492 ; fitab = & tmp [ 0 ] ; do
{ exitg1 = 0 ; d1js1a3jby3 ( rtDW . g0ulyhynln , u32 ) ; i = ( int32_T ) ( (
u32 [ 1 ] >> 24U ) + 1U ) ; r = ( ( ( real_T ) ( u32 [ 0 ] >> 3U ) *
1.6777216E+7 + ( real_T ) ( ( int32_T ) u32 [ 1 ] & 16777215 ) ) *
2.2204460492503131E-16 - 1.0 ) * xi [ i ] ; if ( muDoubleScalarAbs ( r ) <=
xi [ i - 1 ] ) { exitg1 = 1 ; } else if ( i < 256 ) { x = mlav212mvxk ( rtDW
. g0ulyhynln ) ; if ( ( fitab [ i - 1 ] - fitab [ i ] ) * x + fitab [ i ] <
muDoubleScalarExp ( - 0.5 * r * r ) ) { exitg1 = 1 ; } } else { do { x =
mlav212mvxk ( rtDW . g0ulyhynln ) ; x = muDoubleScalarLog ( x ) *
0.273661237329758 ; d_u = mlav212mvxk ( rtDW . g0ulyhynln ) ; } while ( ! ( -
2.0 * muDoubleScalarLog ( d_u ) > x * x ) ) ; if ( r < 0.0 ) { r = x -
3.65415288536101 ; } else { r = 3.65415288536101 - x ; } exitg1 = 1 ; } }
while ( exitg1 == 0 ) ; return r ; } void MdlInitialize ( void ) { bpe5vltzhc
* obj ; int32_T i ; uint32_T nseed ; for ( i = 0 ; i < 5110 ; i ++ ) { rtDW .
khu2zdxbs4 [ i ] = rtP . Buffer1_ic ; } rtDW . ezlg5otozk = 2555 ; rtDW .
ee5qp1cpiz = 2555 ; rtDW . heqq1kpetm = 0 ; for ( i = 0 ; i < 20 ; i ++ ) {
rtX . ci3hspupv1 [ i ] = rtP . AnalogFilterDesign_InitialCondition ; } for (
i = 0 ; i < 5110 ; i ++ ) { rtDW . degrhjleyo [ i ] = rtP . Buffer3_ic ; }
rtDW . mjvxwfupof = 2555 ; rtDW . g5lav3j02c = 2555 ; rtDW . brknn13uxf = 0 ;
rtDW . adldhalszk = rtP . DiscreteTimeIntegrator_IC ; rtX . oxih0zc14u = 0.0
; rtDW . iifnymjse2 = rtP . DiscreteTimeIntegrator1_IC ; rtDW . bu5tr1pdox =
2 ; rtDW . ecfe4qopis = rtP . DiscreteTimeIntegrator2_IC ; rtDW . ma50gapxoa
= 2 ; rtDW . hqdcazynvm = rtP . DiscreteTimeIntegrator5_IC ; rtDW .
ornpy4cdl1 = 2 ; rtDW . n4yx1rctfr = rtP . DiscreteTimeIntegrator6_IC ; rtDW
. c0rsnhvxge = 2 ; for ( i = 0 ; i < 9 ; i ++ ) { rtDW . nxrgsy2c2w [ i ] =
rtConstP . ep40zoormj [ i ] ; rtDW . opvzyiyp3j [ i ] = 1U ; } rtDW .
petkjqwhb5 = rtP . DiscreteTimeIntegrator3_IC ; rtDW . hlh4o42oo3 = 2 ; rtDW
. icjheye5eq = rtP . DiscreteTimeIntegrator4_IC ; rtDW . hr04pilmac = 2 ;
rtDW . ow0o42gfhu = rtB . h00tanbm5k ; nseed = rtDW . b2pi4gudhv . pStream .
Generator -> Seed ; obj = rtDW . b2pi4gudhv . pStream . Generator ; if (
nseed == 0U ) { obj -> Seed = 5489U ; } else { obj -> Seed = nseed ; } nseed
= obj -> Seed ; obj -> State [ 0 ] = nseed ; for ( i = 0 ; i < 623 ; i ++ ) {
nseed = ( ( nseed >> 30U ^ nseed ) * 1812433253U + ( uint32_T ) i ) + 1U ;
obj -> State [ i + 1 ] = nseed ; } obj -> State [ 624 ] = 624U ; } void
MdlEnable ( void ) { rtDW . cgru1gwg0r = 1 ; _ssSetSampleHit ( rtS , 6 , 1 )
; _ssSetTaskTime ( rtS , 6 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS ,
0 , ssGetT ( rtS ) ) ; ; rtDW . agygzdruc0 = 1U ; rtDW . co4yicnm0d = 1U ;
rtDW . m1ai31i3so = 1U ; rtDW . psbicvw1tn = 1U ; rtDW . kko144v51w = 1U ;
rtDW . grbbrolnqo = 1U ; } void MdlStart ( void ) { boolean_T flag ; static
const uint32_T tmp [ 625 ] = { 5489U , 1301868182U , 2938499221U ,
2950281878U , 1875628136U , 751856242U , 944701696U , 2243192071U ,
694061057U , 219885934U , 2066767472U , 3182869408U , 485472502U ,
2336857883U , 1071588843U , 3418470598U , 951210697U , 3693558366U ,
2923482051U , 1793174584U , 2982310801U , 1586906132U , 1951078751U ,
1808158765U , 1733897588U , 431328322U , 4202539044U , 530658942U ,
1714810322U , 3025256284U , 3342585396U , 1937033938U , 2640572511U ,
1654299090U , 3692403553U , 4233871309U , 3497650794U , 862629010U ,
2943236032U , 2426458545U , 1603307207U , 1133453895U , 3099196360U ,
2208657629U , 2747653927U , 931059398U , 761573964U , 3157853227U ,
785880413U , 730313442U , 124945756U , 2937117055U , 3295982469U ,
1724353043U , 3021675344U , 3884886417U , 4010150098U , 4056961966U ,
699635835U , 2681338818U , 1339167484U , 720757518U , 2800161476U ,
2376097373U , 1532957371U , 3902664099U , 1238982754U , 3725394514U ,
3449176889U , 3570962471U , 4287636090U , 4087307012U , 3603343627U ,
202242161U , 2995682783U , 1620962684U , 3704723357U , 371613603U ,
2814834333U , 2111005706U , 624778151U , 2094172212U , 4284947003U ,
1211977835U , 991917094U , 1570449747U , 2962370480U , 1259410321U ,
170182696U , 146300961U , 2836829791U , 619452428U , 2723670296U ,
1881399711U , 1161269684U , 1675188680U , 4132175277U , 780088327U ,
3409462821U , 1036518241U , 1834958505U , 3048448173U , 161811569U ,
618488316U , 44795092U , 3918322701U , 1924681712U , 3239478144U , 383254043U
, 4042306580U , 2146983041U , 3992780527U , 3518029708U , 3545545436U ,
3901231469U , 1896136409U , 2028528556U , 2339662006U , 501326714U ,
2060962201U , 2502746480U , 561575027U , 581893337U , 3393774360U ,
1778912547U , 3626131687U , 2175155826U , 319853231U , 986875531U ,
819755096U , 2915734330U , 2688355739U , 3482074849U , 2736559U , 2296975761U
, 1029741190U , 2876812646U , 690154749U , 579200347U , 4027461746U ,
1285330465U , 2701024045U , 4117700889U , 759495121U , 3332270341U ,
2313004527U , 2277067795U , 4131855432U , 2722057515U , 1264804546U ,
3848622725U , 2211267957U , 4100593547U , 959123777U , 2130745407U ,
3194437393U , 486673947U , 1377371204U , 17472727U , 352317554U , 3955548058U
, 159652094U , 1232063192U , 3835177280U , 49423123U , 3083993636U , 733092U
, 2120519771U , 2573409834U , 1112952433U , 3239502554U , 761045320U ,
1087580692U , 2540165110U , 641058802U , 1792435497U , 2261799288U ,
1579184083U , 627146892U , 2165744623U , 2200142389U , 2167590760U ,
2381418376U , 1793358889U , 3081659520U , 1663384067U , 2009658756U ,
2689600308U , 739136266U , 2304581039U , 3529067263U , 591360555U ,
525209271U , 3131882996U , 294230224U , 2076220115U , 3113580446U ,
1245621585U , 1386885462U , 3203270426U , 123512128U , 12350217U , 354956375U
, 4282398238U , 3356876605U , 3888857667U , 157639694U , 2616064085U ,
1563068963U , 2762125883U , 4045394511U , 4180452559U , 3294769488U ,
1684529556U , 1002945951U , 3181438866U , 22506664U , 691783457U ,
2685221343U , 171579916U , 3878728600U , 2475806724U , 2030324028U ,
3331164912U , 1708711359U , 1970023127U , 2859691344U , 2588476477U ,
2748146879U , 136111222U , 2967685492U , 909517429U , 2835297809U ,
3206906216U , 3186870716U , 341264097U , 2542035121U , 3353277068U ,
548223577U , 3170936588U , 1678403446U , 297435620U , 2337555430U ,
466603495U , 1132321815U , 1208589219U , 696392160U , 894244439U ,
2562678859U , 470224582U , 3306867480U , 201364898U , 2075966438U ,
1767227936U , 2929737987U , 3674877796U , 2654196643U , 3692734598U ,
3528895099U , 2796780123U , 3048728353U , 842329300U , 191554730U ,
2922459673U , 3489020079U , 3979110629U , 1022523848U , 2202932467U ,
3583655201U , 3565113719U , 587085778U , 4176046313U , 3013713762U ,
950944241U , 396426791U , 3784844662U , 3477431613U , 3594592395U ,
2782043838U , 3392093507U , 3106564952U , 2829419931U , 1358665591U ,
2206918825U , 3170783123U , 31522386U , 2988194168U , 1782249537U ,
1105080928U , 843500134U , 1225290080U , 1521001832U , 3605886097U ,
2802786495U , 2728923319U , 3996284304U , 903417639U , 1171249804U ,
1020374987U , 2824535874U , 423621996U , 1988534473U , 2493544470U ,
1008604435U , 1756003503U , 1488867287U , 1386808992U , 732088248U ,
1780630732U , 2482101014U , 976561178U , 1543448953U , 2602866064U ,
2021139923U , 1952599828U , 2360242564U , 2117959962U , 2753061860U ,
2388623612U , 4138193781U , 2962920654U , 2284970429U , 766920861U ,
3457264692U , 2879611383U , 815055854U , 2332929068U , 1254853997U ,
3740375268U , 3799380844U , 4091048725U , 2006331129U , 1982546212U ,
686850534U , 1907447564U , 2682801776U , 2780821066U , 998290361U ,
1342433871U , 4195430425U , 607905174U , 3902331779U , 2454067926U ,
1708133115U , 1170874362U , 2008609376U , 3260320415U , 2211196135U ,
433538229U , 2728786374U , 2189520818U , 262554063U , 1182318347U ,
3710237267U , 1221022450U , 715966018U , 2417068910U , 2591870721U ,
2870691989U , 3418190842U , 4238214053U , 1540704231U , 1575580968U ,
2095917976U , 4078310857U , 2313532447U , 2110690783U , 4056346629U ,
4061784526U , 1123218514U , 551538993U , 597148360U , 4120175196U ,
3581618160U , 3181170517U , 422862282U , 3227524138U , 1713114790U ,
662317149U , 1230418732U , 928171837U , 1324564878U , 1928816105U ,
1786535431U , 2878099422U , 3290185549U , 539474248U , 1657512683U ,
552370646U , 1671741683U , 3655312128U , 1552739510U , 2605208763U ,
1441755014U , 181878989U , 3124053868U , 1447103986U , 3183906156U ,
1728556020U , 3502241336U , 3055466967U , 1013272474U , 818402132U ,
1715099063U , 2900113506U , 397254517U , 4194863039U , 1009068739U ,
232864647U , 2540223708U , 2608288560U , 2415367765U , 478404847U ,
3455100648U , 3182600021U , 2115988978U , 434269567U , 4117179324U ,
3461774077U , 887256537U , 3545801025U , 286388911U , 3451742129U ,
1981164769U , 786667016U , 3310123729U , 3097811076U , 2224235657U ,
2959658883U , 3370969234U , 2514770915U , 3345656436U , 2677010851U ,
2206236470U , 271648054U , 2342188545U , 4292848611U , 3646533909U ,
3754009956U , 3803931226U , 4160647125U , 1477814055U , 4043852216U ,
1876372354U , 3133294443U , 3871104810U , 3177020907U , 2074304428U ,
3479393793U , 759562891U , 164128153U , 1839069216U , 2114162633U ,
3989947309U , 3611054956U , 1333547922U , 835429831U , 494987340U ,
171987910U , 1252001001U , 370809172U , 3508925425U , 2535703112U ,
1276855041U , 1922855120U , 835673414U , 3030664304U , 613287117U ,
171219893U , 3423096126U , 3376881639U , 2287770315U , 1658692645U ,
1262815245U , 3957234326U , 1168096164U , 2968737525U , 2655813712U ,
2132313144U , 3976047964U , 326516571U , 353088456U , 3679188938U ,
3205649712U , 2654036126U , 1249024881U , 880166166U , 691800469U ,
2229503665U , 1673458056U , 4032208375U , 1851778863U , 2563757330U ,
376742205U , 1794655231U , 340247333U , 1505873033U , 396524441U , 879666767U
, 3335579166U , 3260764261U , 3335999539U , 506221798U , 4214658741U ,
975887814U , 2080536343U , 3360539560U , 571586418U , 138896374U ,
4234352651U , 2737620262U , 3928362291U , 1516365296U , 38056726U ,
3599462320U , 3585007266U , 3850961033U , 471667319U , 1536883193U ,
2310166751U , 1861637689U , 2530999841U , 4139843801U , 2710569485U ,
827578615U , 2012334720U , 2907369459U , 3029312804U , 2820112398U ,
1965028045U , 35518606U , 2478379033U , 643747771U , 1924139484U ,
4123405127U , 3811735531U , 3429660832U , 3285177704U , 1948416081U ,
1311525291U , 1183517742U , 1739192232U , 3979815115U , 2567840007U ,
4116821529U , 213304419U , 4125718577U , 1473064925U , 2442436592U ,
1893310111U , 4195361916U , 3747569474U , 828465101U , 2991227658U ,
750582866U , 1205170309U , 1409813056U , 678418130U , 1171531016U ,
3821236156U , 354504587U , 4202874632U , 3882511497U , 1893248677U ,
1903078632U , 26340130U , 2069166240U , 3657122492U , 3725758099U ,
831344905U , 811453383U , 3447711422U , 2434543565U , 4166886888U ,
3358210805U , 4142984013U , 2988152326U , 3527824853U , 982082992U ,
2809155763U , 190157081U , 3340214818U , 2365432395U , 2548636180U ,
2894533366U , 3474657421U , 2372634704U , 2845748389U , 43024175U ,
2774226648U , 1987702864U , 3186502468U , 453610222U , 4204736567U ,
1392892630U , 2471323686U , 2470534280U , 3541393095U , 4269885866U ,
3909911300U , 759132955U , 1482612480U , 667715263U , 1795580598U ,
2337923983U , 3390586366U , 581426223U , 1515718634U , 476374295U ,
705213300U , 363062054U , 2084697697U , 2407503428U , 2292957699U ,
2426213835U , 2199989172U , 1987356470U , 4026755612U , 2147252133U ,
270400031U , 1367820199U , 2369854699U , 2844269403U , 79981964U , 624U } ; {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . ficexzqbh2 = 1 ; { int_T j ; char ptrKey [ 1024 ] ; { real_T *
pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ;
if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . gttvq41aan . Tail = 0
; rtDW . gttvq41aan . Head = 0 ; rtDW . gttvq41aan . Last = 0 ; rtDW .
gttvq41aan . CircularBufSize = 1024 ; for ( j = 0 ; j < 1024 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTransportDelay1_InitOutput ; pBuffer [ 1024 + j
] = ssGetT ( rtS ) ; } rtDW . bo3muh5enu . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; sprintf ( ptrKey ,
"CT_POI/Subsystem2/Variable\nTransport Delay1_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
bo3muh5enu . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } rtDW . ngrrkreo2f = 1 ; rtDW . m14sbehec2 = 0U ; rtDW .
dypy444pvq = true ; rtDW . iqp54sidls = 7U ; rtDW . acu0fobbd3 = true ;
memcpy ( & rtDW . g0ulyhynln [ 0 ] , & tmp [ 0 ] , 625U * sizeof ( uint32_T )
) ; rtDW . eshgyurwuf = true ; rtDW . dc1nkzv5gn = true ; rtDW . f2oac5wnal =
1144108930U ; rtDW . hp4k1chfue = true ; rtDW . jx3alr4qwb = 0U ; rtDW .
hdirjwpdhq = true ; rtDW . jken4w0gjf [ 0 ] = 362436069U ; rtDW . jdgjatsyrt
[ 0 ] = 362436069U ; rtDW . jken4w0gjf [ 1 ] = 521288629U ; rtDW . jdgjatsyrt
[ 1 ] = 521288629U ; rtDW . kzklpmmpnf = true ; rtDW . b2pi4gudhv .
isInitialized = 0 ; rtDW . pemmcx3bjg = true ; flag = ( rtDW . b2pi4gudhv .
isInitialized == 1 ) ; if ( flag ) { rtDW . b2pi4gudhv . TunablePropsChanged
= true ; } rtDW . b2pi4gudhv . SNR = rtP . AWGNChannel_SNR ; flag = ( rtDW .
b2pi4gudhv . isInitialized == 1 ) ; if ( flag ) { rtDW . b2pi4gudhv .
TunablePropsChanged = true ; } rtDW . b2pi4gudhv . SignalPower = rtP .
AWGNChannel_SignalPower ; ih4ns52cn2 ( & rtDW . b2pi4gudhv ) ; rtDW .
enivbnqm2z = 1 ; rtB . h00tanbm5k = rtP . Constant4_Value ; { int_T j ; char
ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 3 ,
1024 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus (
rtS , "vtdelay memory allocation error" ) ; return ; } rtDW . cazujz0icx .
Tail = 0 ; rtDW . cazujz0icx . Head = 0 ; rtDW . cazujz0icx . Last = 0 ; rtDW
. cazujz0icx . CircularBufSize = 1024 ; for ( j = 0 ; j < 1024 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTransportDelay_InitOutput ; pBuffer [ 1024 + j
] = ssGetT ( rtS ) ; } pBuffer [ 2 * 1024 ] = 0.0 ; rtDW . mrxxjsj4ey .
TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf ( ptrKey ,
"CT_POI/Subsystem5/Subsystem/Variable\nTransport Delay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
mrxxjsj4ey . TUbufferPtrs [ 0 ] ) , 3 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } MdlInitialize ( ) ; MdlEnable ( ) ; } void MdlOutputs (
int_T tid ) { real_T n11tzemop2 ; real_T b_std ; real_T cnpnke4xkl ; real_T
lhghlhuxfq ; real_T ls1zcvev04 ; real_T lvvedgn1ru ; real_T nmtvjohhom ;
real_T randData ; int32_T currentOffset ; int32_T i ; int32_T n ; int32_T
uyIdx ; uint32_T numCycles ; uint32_T sigIdx ; uint8_T nxrgsy2c2w ; uint8_T
tmp ; uint8_T tmp2 ; boolean_T exitg1 ; boolean_T g2jz5phf2n ; boolean_T
k3j1oor53h ; { real_T * * uBuffer = ( real_T * * ) & rtDW . bo3muh5enu .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ;
appliedDelay = rtP . Constant2_Value ; if ( appliedDelay > rtP .
VariableTransportDelay1_MaxDelay ) { appliedDelay = rtP .
VariableTransportDelay1_MaxDelay ; } if ( appliedDelay < 0.0 ) { appliedDelay
= 0.0 ; } rtB . oiagjxsfua = rt_TDelayInterpolate ( simTime - appliedDelay ,
0.0 , * uBuffer , rtDW . gttvq41aan . CircularBufSize , & rtDW . gttvq41aan .
Last , rtDW . gttvq41aan . Tail , rtDW . gttvq41aan . Head , rtP .
VariableTransportDelay1_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ( * uBuffer + rtDW . gttvq41aan . CircularBufSize ) [ rtDW .
gttvq41aan . Head ] == ssGetT ( rtS ) ) ) ) ; } if ( ssIsSampleHit ( rtS , 2
, 0 ) ) { rtB . ptxjsacnuh = rtB . oiagjxsfua ; n = 5110 ; uyIdx = rtDW .
ezlg5otozk ; if ( rtDW . ezlg5otozk > 5109 ) { for ( i = 0 ; i < 5110 - rtDW
. ezlg5otozk ; i ++ ) { rtDW . khu2zdxbs4 [ rtDW . ezlg5otozk + i ] = rtB .
ptxjsacnuh ; } uyIdx = 0 ; n = rtDW . ezlg5otozk ; } for ( i = 0 ; i < n -
5109 ; i ++ ) { rtDW . khu2zdxbs4 [ uyIdx + i ] = rtB . ptxjsacnuh ; } rtDW .
ezlg5otozk ++ ; if ( rtDW . ezlg5otozk >= 5110 ) { rtDW . ezlg5otozk -= 5110
; } rtDW . ee5qp1cpiz ++ ; if ( rtDW . ee5qp1cpiz > 5110 ) { rtDW .
heqq1kpetm = ( rtDW . heqq1kpetm + rtDW . ee5qp1cpiz ) - 5110 ; if ( rtDW .
heqq1kpetm > 5110 ) { rtDW . heqq1kpetm -= 5110 ; } rtDW . ee5qp1cpiz = 5110
; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtDW . ee5qp1cpiz -= 2555 ; if (
rtDW . ee5qp1cpiz < 0 ) { rtDW . heqq1kpetm += rtDW . ee5qp1cpiz ; if ( rtDW
. heqq1kpetm < 0 ) { rtDW . heqq1kpetm += 5110 ; } rtDW . ee5qp1cpiz = 0 ; }
uyIdx = 0 ; currentOffset = rtDW . heqq1kpetm ; n = 2555 ; if ( rtDW .
heqq1kpetm > 2555 ) { for ( i = 0 ; i < 5110 - rtDW . heqq1kpetm ; i ++ ) {
rtB . k1bdv0g0en_mbvzarwird [ i ] = rtDW . khu2zdxbs4 [ rtDW . heqq1kpetm + i
] ; } uyIdx = 5110 - rtDW . heqq1kpetm ; n = rtDW . heqq1kpetm - 2555 ;
currentOffset = 0 ; } for ( i = 0 ; i < n ; i ++ ) { rtB .
k1bdv0g0en_mbvzarwird [ uyIdx + i ] = rtDW . khu2zdxbs4 [ currentOffset + i ]
; } currentOffset += n ; if ( currentOffset == 5110 ) { currentOffset = 0 ; }
rtDW . heqq1kpetm = currentOffset ; rtDW . i1izcj3aqn = rtB .
k1bdv0g0en_mbvzarwird [ 0 ] ; rtDW . crayuk1lir = rtB . k1bdv0g0en_mbvzarwird
[ 0 ] * rtB . k1bdv0g0en_mbvzarwird [ 0 ] ; currentOffset = 1 ; for ( n =
2553 ; n >= 0 ; n -- ) { rtDW . i1izcj3aqn += rtB . k1bdv0g0en_mbvzarwird [
currentOffset ] ; rtDW . crayuk1lir += rtB . k1bdv0g0en_mbvzarwird [
currentOffset ] * rtB . k1bdv0g0en_mbvzarwird [ currentOffset ] ;
currentOffset ++ ; } lhghlhuxfq = ( rtDW . crayuk1lir - rtDW . i1izcj3aqn *
rtDW . i1izcj3aqn / 2555.0 ) / 2554.0 ; if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtDW . ngrrkreo2f != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ngrrkreo2f = 0 ; } } else if ( lhghlhuxfq < 0.0 ) { lhghlhuxfq = 0.0 ; rtDW .
ngrrkreo2f = 1 ; } lhghlhuxfq = 10.0 * muDoubleScalarLog10 ( lhghlhuxfq ) ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtDW . b2pi4gudhv . SNR != rtP .
AWGNChannel_SNR ) { k3j1oor53h = ( rtDW . b2pi4gudhv . isInitialized == 1 ) ;
if ( k3j1oor53h ) { rtDW . b2pi4gudhv . TunablePropsChanged = true ; } rtDW .
b2pi4gudhv . SNR = rtP . AWGNChannel_SNR ; } if ( rtDW . b2pi4gudhv .
SignalPower != rtP . AWGNChannel_SignalPower ) { k3j1oor53h = ( rtDW .
b2pi4gudhv . isInitialized == 1 ) ; if ( k3j1oor53h ) { rtDW . b2pi4gudhv .
TunablePropsChanged = true ; } rtDW . b2pi4gudhv . SignalPower = rtP .
AWGNChannel_SignalPower ; } if ( rtDW . b2pi4gudhv . TunablePropsChanged ) {
rtDW . b2pi4gudhv . TunablePropsChanged = false ; rtDW . b2pi4gudhv .
pNumChanFromProp = 1.0 ; b_std = rtDW . b2pi4gudhv . SNR / 10.0 ; b_std =
rtDW . b2pi4gudhv . SignalPower / muDoubleScalarPower ( 10.0 , b_std ) ; rtDW
. b2pi4gudhv . pStd = muDoubleScalarSqrt ( b_std ) ; } i = 0 ; exitg1 = false
; while ( ( ! exitg1 ) && ( i < 8 ) ) { if ( rtDW . b2pi4gudhv . inputVarSize
. f1 [ i ] != 1U ) { for ( n = 0 ; n < 8 ; n ++ ) { rtDW . b2pi4gudhv .
inputVarSize . f1 [ n ] = 1U ; } exitg1 = true ; } else { i ++ ; } } if ( (
rtDW . b2pi4gudhv . pIsVarChannel || ( ( ! rtDW . b2pi4gudhv . pIsVarChannel
) && ( rtDW . b2pi4gudhv . pFirstInputNumChan != 1.0 ) ) ) && ( ! rtDW .
b2pi4gudhv . pIsVarChannel ) ) { rtDW . b2pi4gudhv . pIsVarChannel = true ; }
b_std = rtDW . b2pi4gudhv . pStd ; randData = ieteoqusqe ( ) ; rtB .
cns4fjew02 = b_std * randData ; } rtB . aeq5ruscfh = 0.0 ; for ( numCycles =
0U ; numCycles < 20U ; numCycles ++ ) { for ( sigIdx = rtP .
AnalogFilterDesign_C_jc [ numCycles ] ; sigIdx < rtP .
AnalogFilterDesign_C_jc [ numCycles + 1U ] ; sigIdx ++ ) { rtB . aeq5ruscfh
+= rtP . AnalogFilterDesign_C_pr [ sigIdx ] * rtX . ci3hspupv1 [ numCycles ]
; } } for ( sigIdx = rtP . AnalogFilterDesign_D_jc [ 0U ] ; sigIdx < rtP .
AnalogFilterDesign_D_jc [ 1U ] ; sigIdx ++ ) { rtB . aeq5ruscfh += rtP .
AnalogFilterDesign_D_pr * rtB . cns4fjew02 ; } if ( ssIsSampleHit ( rtS , 2 ,
0 ) ) { rtB . pnfujicrav = rtB . aeq5ruscfh ; n = 5110 ; uyIdx = rtDW .
mjvxwfupof ; if ( rtDW . mjvxwfupof > 5109 ) { for ( i = 0 ; i < 5110 - rtDW
. mjvxwfupof ; i ++ ) { rtDW . degrhjleyo [ rtDW . mjvxwfupof + i ] = rtB .
pnfujicrav ; } uyIdx = 0 ; n = rtDW . mjvxwfupof ; } for ( i = 0 ; i < n -
5109 ; i ++ ) { rtDW . degrhjleyo [ uyIdx + i ] = rtB . pnfujicrav ; } rtDW .
mjvxwfupof ++ ; if ( rtDW . mjvxwfupof >= 5110 ) { rtDW . mjvxwfupof -= 5110
; } rtDW . g5lav3j02c ++ ; if ( rtDW . g5lav3j02c > 5110 ) { rtDW .
brknn13uxf = ( rtDW . brknn13uxf + rtDW . g5lav3j02c ) - 5110 ; if ( rtDW .
brknn13uxf > 5110 ) { rtDW . brknn13uxf -= 5110 ; } rtDW . g5lav3j02c = 5110
; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtDW . g5lav3j02c -= 2555 ; if (
rtDW . g5lav3j02c < 0 ) { rtDW . brknn13uxf += rtDW . g5lav3j02c ; if ( rtDW
. brknn13uxf < 0 ) { rtDW . brknn13uxf += 5110 ; } rtDW . g5lav3j02c = 0 ; }
uyIdx = 0 ; currentOffset = rtDW . brknn13uxf ; n = 2555 ; if ( rtDW .
brknn13uxf > 2555 ) { for ( i = 0 ; i < 5110 - rtDW . brknn13uxf ; i ++ ) {
rtB . l4jx0r12q0_cl54gopm0x [ i ] = rtDW . degrhjleyo [ rtDW . brknn13uxf + i
] ; } uyIdx = 5110 - rtDW . brknn13uxf ; n = rtDW . brknn13uxf - 2555 ;
currentOffset = 0 ; } for ( i = 0 ; i < n ; i ++ ) { rtB .
l4jx0r12q0_cl54gopm0x [ uyIdx + i ] = rtDW . degrhjleyo [ currentOffset + i ]
; } currentOffset += n ; if ( currentOffset == 5110 ) { currentOffset = 0 ; }
rtDW . brknn13uxf = currentOffset ; rtDW . ltl5bvjttg = rtB .
l4jx0r12q0_cl54gopm0x [ 0 ] ; rtDW . dyxjcdc4bi = rtB . l4jx0r12q0_cl54gopm0x
[ 0 ] * rtB . l4jx0r12q0_cl54gopm0x [ 0 ] ; currentOffset = 1 ; for ( n =
2553 ; n >= 0 ; n -- ) { rtDW . ltl5bvjttg += rtB . l4jx0r12q0_cl54gopm0x [
currentOffset ] ; rtDW . dyxjcdc4bi += rtB . l4jx0r12q0_cl54gopm0x [
currentOffset ] * rtB . l4jx0r12q0_cl54gopm0x [ currentOffset ] ;
currentOffset ++ ; } randData = ( rtDW . dyxjcdc4bi - rtDW . ltl5bvjttg *
rtDW . ltl5bvjttg / 2555.0 ) / 2554.0 ; if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtDW . enivbnqm2z != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
enivbnqm2z = 0 ; } } else if ( randData < 0.0 ) { randData = 0.0 ; rtDW .
enivbnqm2z = 1 ; } rtB . fo3o0qx3rk = lhghlhuxfq - 10.0 * muDoubleScalarLog10
( randData ) ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { rtB . iaqfq2eapm =
rtDW . adldhalszk ; rtB . h00tanbm5k = rtP . Constant4_Value ; } randData =
rtB . oiagjxsfua + rtB . aeq5ruscfh ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
cnpnke4xkl = ssGetTaskTime ( rtS , 2 ) ; lvvedgn1ru = rtP . Gain_Gain *
cnpnke4xkl ; rtB . abu2iacvsb = muDoubleScalarSin ( lvvedgn1ru ) ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . mrxxjsj4ey . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ; n11tzemop2 =
rt_VTDelayfindtDInterpolate ( rtX . oxih0zc14u , * uBuffer , rtDW .
cazujz0icx . CircularBufSize , rtDW . cazujz0icx . Head , rtDW . cazujz0icx .
Tail , & rtDW . cazujz0icx . Last , simTime , 0.0 , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + rtDW . cazujz0icx .
CircularBufSize ) [ rtDW . cazujz0icx . Head ] == ssGetT ( rtS ) ) ) , rtP .
VariableTransportDelay_InitOutput , & appliedDelay ) ; } rtB . hcqcgye2fg =
randData * rtB . abu2iacvsb * n11tzemop2 ; if ( ssIsSampleHit ( rtS , 6 , 0 )
) { lhghlhuxfq = ssGetTaskTime ( rtS , 6 ) ; if ( ssGetTNextWasAdjusted ( rtS
, 6 ) ) { rtDW . bobq1qesgz = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW
. cgru1gwg0r != 0 ) { rtDW . cgru1gwg0r = 0 ; if ( lhghlhuxfq >= rtP .
PulseGenerator1_PhaseDelay ) { b_std = ( lhghlhuxfq - rtP .
PulseGenerator1_PhaseDelay ) / rtP . PulseGenerator1_Period ; numCycles = (
uint32_T ) muDoubleScalarFloor ( b_std ) ; if ( muDoubleScalarAbs ( ( real_T
) ( numCycles + 1U ) - b_std ) < DBL_EPSILON * b_std ) { numCycles ++ ; }
rtDW . om2ho3dulj = numCycles ; b_std = ( ( real_T ) numCycles * rtP .
PulseGenerator1_Period + rtP . PulseGenerator1_PhaseDelay ) + rtP .
PulseGenerator1_Duty * rtP . PulseGenerator1_Period / 100.0 ; if ( lhghlhuxfq
< b_std ) { rtDW . hrj4u4frdf = 1 ; rtDW . bobq1qesgz = b_std ; } else { rtDW
. hrj4u4frdf = 0 ; rtDW . bobq1qesgz = ( real_T ) ( numCycles + 1U ) * rtP .
PulseGenerator1_Period + rtP . PulseGenerator1_PhaseDelay ; } } else { rtDW .
om2ho3dulj = rtP . PulseGenerator1_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW .
hrj4u4frdf = 0 ; rtDW . bobq1qesgz = rtP . PulseGenerator1_PhaseDelay ; } }
else if ( rtDW . bobq1qesgz <= lhghlhuxfq ) { if ( rtDW . hrj4u4frdf == 1 ) {
rtDW . hrj4u4frdf = 0 ; rtDW . bobq1qesgz = ( real_T ) ( rtDW . om2ho3dulj +
1LL ) * rtP . PulseGenerator1_Period + rtP . PulseGenerator1_PhaseDelay ; }
else { rtDW . om2ho3dulj ++ ; rtDW . hrj4u4frdf = 1 ; rtDW . bobq1qesgz = (
rtP . PulseGenerator1_Duty * rtP . PulseGenerator1_Period * 0.01 + ( real_T )
rtDW . om2ho3dulj * rtP . PulseGenerator1_Period ) + rtP .
PulseGenerator1_PhaseDelay ; } } _ssSetVarNextHitTime ( rtS , 0 , rtDW .
bobq1qesgz ) ; if ( rtDW . hrj4u4frdf == 1 ) { rtB . jx13nwj10i = rtP .
PulseGenerator1_Amp ; } else { rtB . jx13nwj10i = 0.0 ; } } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtDW . agygzdruc0 != 0 ) { rtB .
i50ghe5lm1 = rtDW . iifnymjse2 ; } else if ( ( rtB . jx13nwj10i <= 0.0 ) && (
rtDW . bu5tr1pdox == 1 ) ) { rtDW . iifnymjse2 = rtP .
DiscreteTimeIntegrator1_IC ; rtB . i50ghe5lm1 = rtDW . iifnymjse2 ; } else {
rtB . i50ghe5lm1 = rtP . DiscreteTimeIntegrator1_gainval * rtB . hcqcgye2fg +
rtDW . iifnymjse2 ; } rtB . nym1g1yulh = muDoubleScalarCos ( lvvedgn1ru ) ; }
rtB . eue4pzm2um = randData * rtB . nym1g1yulh * n11tzemop2 ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtDW . co4yicnm0d != 0 ) { rtB .
nxismlfsz2 = rtDW . ecfe4qopis ; } else if ( ( rtB . jx13nwj10i <= 0.0 ) && (
rtDW . ma50gapxoa == 1 ) ) { rtDW . ecfe4qopis = rtP .
DiscreteTimeIntegrator2_IC ; rtB . nxismlfsz2 = rtDW . ecfe4qopis ; } else {
rtB . nxismlfsz2 = rtP . DiscreteTimeIntegrator2_gainval * rtB . eue4pzm2um +
rtDW . ecfe4qopis ; } rtB . nbzdbx43y2 = muDoubleScalarHypot ( rtB .
i50ghe5lm1 , rtB . nxismlfsz2 ) ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) {
ls1zcvev04 = rtB . nbzdbx43y2 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { tmp
= 0U ; tmp2 = 0U ; for ( i = 0 ; i < 9 ; i ++ ) { nxrgsy2c2w = rtDW .
nxrgsy2c2w [ i ] ; tmp += ( uint8_T ) ( rtConstP . ejilaj33zh [ i + 1 ] *
nxrgsy2c2w ) ; tmp2 += ( uint8_T ) ( nxrgsy2c2w * rtConstP . nmkf01nuia [ i ]
) ; } tmp &= 1 ; for ( i = 7 ; i >= 0 ; i -- ) { rtDW . nxrgsy2c2w [ i + 1 ]
= rtDW . nxrgsy2c2w [ i ] ; } rtDW . nxrgsy2c2w [ 0U ] = tmp ; rtB .
cskkp1pbit = ( ( ( tmp2 & 1U ) != 0U ) * rtP . Gain_Gain_c0wzfxwapi + rtP .
Bias_Bias ) * rtP . Gain1_Gain_jhwyhxq2zq ; } rtB . ekkv4odda4 = rtB .
abu2iacvsb * rtB . cskkp1pbit * randData ; rtB . bunz1k115f = rtB .
nym1g1yulh * rtB . cskkp1pbit * randData ; if ( ssIsSampleHit ( rtS , 2 , 0 )
) { if ( rtDW . m1ai31i3so != 0 ) { rtB . he1lzb12tu = rtDW . hqdcazynvm ; }
else if ( ( rtB . jx13nwj10i <= 0.0 ) && ( rtDW . ornpy4cdl1 == 1 ) ) { rtDW
. hqdcazynvm = rtP . DiscreteTimeIntegrator5_IC ; rtB . he1lzb12tu = rtDW .
hqdcazynvm ; } else { rtB . he1lzb12tu = rtP .
DiscreteTimeIntegrator5_gainval * rtB . ekkv4odda4 + rtDW . hqdcazynvm ; } if
( rtDW . psbicvw1tn != 0 ) { rtB . i5jmft20v3 = rtDW . n4yx1rctfr ; } else if
( ( rtB . jx13nwj10i <= 0.0 ) && ( rtDW . c0rsnhvxge == 1 ) ) { rtDW .
n4yx1rctfr = rtP . DiscreteTimeIntegrator6_IC ; rtB . i5jmft20v3 = rtDW .
n4yx1rctfr ; } else { rtB . i5jmft20v3 = rtP .
DiscreteTimeIntegrator6_gainval * rtB . bunz1k115f + rtDW . n4yx1rctfr ; }
lvvedgn1ru = rtB . i5jmft20v3 * rtB . i5jmft20v3 + rtB . he1lzb12tu * rtB .
he1lzb12tu ; if ( lvvedgn1ru < 0.0 ) { lhghlhuxfq = - muDoubleScalarSqrt (
muDoubleScalarAbs ( lvvedgn1ru ) ) ; } else { lhghlhuxfq = muDoubleScalarSqrt
( lvvedgn1ru ) ; } rtB . c1hzatsvvq = lhghlhuxfq * rtB . mh3qnuillk ; } if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { nmtvjohhom = rtB . c1hzatsvvq ; g2jz5phf2n
= ( muDoubleScalarSign ( ls1zcvev04 - rtB . c1hzatsvvq ) > rtP .
Constant3_Value ) ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { tmp = 0U ; tmp2
= 0U ; for ( i = 0 ; i < 9 ; i ++ ) { nxrgsy2c2w = rtDW . opvzyiyp3j [ i ] ;
tmp += ( uint8_T ) ( rtConstP . ejilaj33zh [ i + 1 ] * nxrgsy2c2w ) ; tmp2 +=
( uint8_T ) ( nxrgsy2c2w * rtConstP . nmkf01nuia [ i ] ) ; } tmp &= 1 ; for (
i = 7 ; i >= 0 ; i -- ) { rtDW . opvzyiyp3j [ i + 1 ] = rtDW . opvzyiyp3j [ i
] ; } rtDW . opvzyiyp3j [ 0U ] = tmp ; rtB . ahaloitnql = ( ( ( tmp2 & 1U )
!= 0U ) * rtP . Gain_Gain_hnwxniojmd + rtP . Bias_Bias_fafg04n1yq ) * rtP .
Gain1_Gain_lhfiaw3lod ; } rtB . cqncnt5j3w = rtB . ahaloitnql * randData *
rtB . abu2iacvsb ; rtB . p3kz0eppb3 = rtB . nym1g1yulh * rtB . ahaloitnql *
randData ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtDW . kko144v51w != 0
) { rtB . et3ss0ypwk = rtDW . petkjqwhb5 ; } else if ( ( rtB . jx13nwj10i <=
0.0 ) && ( rtDW . hlh4o42oo3 == 1 ) ) { rtDW . petkjqwhb5 = rtP .
DiscreteTimeIntegrator3_IC ; rtB . et3ss0ypwk = rtDW . petkjqwhb5 ; } else {
rtB . et3ss0ypwk = rtP . DiscreteTimeIntegrator3_gainval * rtB . cqncnt5j3w +
rtDW . petkjqwhb5 ; } if ( rtDW . grbbrolnqo != 0 ) { rtB . eatzl3wsw1 = rtDW
. icjheye5eq ; } else if ( ( rtB . jx13nwj10i <= 0.0 ) && ( rtDW . hr04pilmac
== 1 ) ) { rtDW . icjheye5eq = rtP . DiscreteTimeIntegrator4_IC ; rtB .
eatzl3wsw1 = rtDW . icjheye5eq ; } else { rtB . eatzl3wsw1 = rtP .
DiscreteTimeIntegrator4_gainval * rtB . p3kz0eppb3 + rtDW . icjheye5eq ; }
rtB . lydxvhyrns = muDoubleScalarHypot ( rtB . et3ss0ypwk , rtB . eatzl3wsw1
) ; rtB . lrjqprgrv3 = rtP . Gain_Gain_donlcyw5bh * cnpnke4xkl ; } if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { rtB . aes5bhgd15 = rtP .
CombinatorialLogic_table [ ( uint32_T ) ( muDoubleScalarSign ( rtB .
lydxvhyrns - nmtvjohhom ) > rtP . Constant3_Value ) + ( ( uint32_T )
g2jz5phf2n << 1 ) ] ; rtB . f2shyu0rcb = rtDW . ow0o42gfhu ; rtB . ka0zgragyp
= rtP . Gain1_Gain * rtB . f2shyu0rcb ; } if ( ssIsSampleHit ( rtS , 1 , 0 )
) { rtB . k42ztcl2nd = muDoubleScalarCos ( rtB . lrjqprgrv3 + rtB .
ka0zgragyp ) * rtB . ahaloitnql ; rtB . gzm3dlplwu = rtP . Constant1_Value ;
} UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID7 ( int_T tid ) { real_T tmp
; tmp = 1.0 / rtP . Constant_Value ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . ficexzqbh2 != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ficexzqbh2 = 0 ; } } else if ( tmp < 0.0 ) { tmp = 0.0 ; rtDW . ficexzqbh2 =
1 ; } tmp = 2.0 * muDoubleScalarLog ( tmp ) ; if ( tmp < 0.0 ) { rtB .
mh3qnuillk = - muDoubleScalarSqrt ( - tmp ) ; } else { rtB . mh3qnuillk =
muDoubleScalarSqrt ( tmp ) ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { { real_T * * uBuffer = ( real_T * * ) & rtDW . bo3muh5enu .
TUbufferPtrs [ 0 ] ; int numBuffers = 2 ; real_T simTime = ssGetT ( rtS ) ;
rtDW . gttvq41aan . Head = ( ( rtDW . gttvq41aan . Head < ( rtDW . gttvq41aan
. CircularBufSize - 1 ) ) ? ( rtDW . gttvq41aan . Head + 1 ) : 0 ) ; if (
rtDW . gttvq41aan . Head == rtDW . gttvq41aan . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . gttvq41aan . CircularBufSize , & rtDW
. gttvq41aan . Tail , & rtDW . gttvq41aan . Head , & rtDW . gttvq41aan . Last
, simTime - rtP . VariableTransportDelay1_MaxDelay , uBuffer , ( boolean_T )
0 , ( boolean_T ) 0 , & rtDW . gttvq41aan . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"CT_POI/Subsystem2/Variable\nTransport Delay1_TUbuffer0" , ( void * * ) ( &
uBuffer [ 0 ] ) , numBuffers * rtDW . gttvq41aan . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . gttvq41aan .
CircularBufSize ) [ rtDW . gttvq41aan . Head ] = simTime ; ( * uBuffer ) [
rtDW . gttvq41aan . Head ] = rtB . k42ztcl2nd ; } if ( ssIsSampleHit ( rtS ,
5 , 0 ) ) { rtDW . adldhalszk = ( uint8_T ) ( ( uint32_T ) rtDW . adldhalszk
+ rtB . aes5bhgd15 ) ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
mrxxjsj4ey . TUbufferPtrs [ 0 ] ; int numBuffers = 2 ; numBuffers = 3 ;
real_T simTime = ssGetT ( rtS ) ; rtDW . cazujz0icx . Head = ( ( rtDW .
cazujz0icx . Head < ( rtDW . cazujz0icx . CircularBufSize - 1 ) ) ? ( rtDW .
cazujz0icx . Head + 1 ) : 0 ) ; if ( rtDW . cazujz0icx . Head == rtDW .
cazujz0icx . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
cazujz0icx . CircularBufSize , & rtDW . cazujz0icx . Tail , & rtDW .
cazujz0icx . Head , & rtDW . cazujz0icx . Last , simTime - rtP .
VariableTransportDelay_MaxDelay , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 1
, & rtDW . cazujz0icx . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"CT_POI/Subsystem5/Subsystem/Variable\nTransport Delay_TUbuffer0" , ( void *
* ) ( & uBuffer [ 0 ] ) , numBuffers * rtDW . cazujz0icx . CircularBufSize *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . cazujz0icx
. CircularBufSize ) [ rtDW . cazujz0icx . Head ] = simTime ; ( * uBuffer + 2
* rtDW . cazujz0icx . CircularBufSize ) [ rtDW . cazujz0icx . Head ] = rtX .
oxih0zc14u ; ( * uBuffer ) [ rtDW . cazujz0icx . Head ] = rtB . ahaloitnql ;
} if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . agygzdruc0 = 0U ; rtDW .
iifnymjse2 = rtP . DiscreteTimeIntegrator1_gainval * rtB . hcqcgye2fg + rtB .
i50ghe5lm1 ; if ( rtB . jx13nwj10i > 0.0 ) { rtDW . bu5tr1pdox = 1 ; } else
if ( rtB . jx13nwj10i < 0.0 ) { rtDW . bu5tr1pdox = - 1 ; } else if ( rtB .
jx13nwj10i == 0.0 ) { rtDW . bu5tr1pdox = 0 ; } else { rtDW . bu5tr1pdox = 2
; } rtDW . co4yicnm0d = 0U ; rtDW . ecfe4qopis = rtP .
DiscreteTimeIntegrator2_gainval * rtB . eue4pzm2um + rtB . nxismlfsz2 ; if (
rtB . jx13nwj10i > 0.0 ) { rtDW . ma50gapxoa = 1 ; } else if ( rtB .
jx13nwj10i < 0.0 ) { rtDW . ma50gapxoa = - 1 ; } else if ( rtB . jx13nwj10i
== 0.0 ) { rtDW . ma50gapxoa = 0 ; } else { rtDW . ma50gapxoa = 2 ; } rtDW .
m1ai31i3so = 0U ; rtDW . hqdcazynvm = rtP . DiscreteTimeIntegrator5_gainval *
rtB . ekkv4odda4 + rtB . he1lzb12tu ; if ( rtB . jx13nwj10i > 0.0 ) { rtDW .
ornpy4cdl1 = 1 ; } else if ( rtB . jx13nwj10i < 0.0 ) { rtDW . ornpy4cdl1 = -
1 ; } else if ( rtB . jx13nwj10i == 0.0 ) { rtDW . ornpy4cdl1 = 0 ; } else {
rtDW . ornpy4cdl1 = 2 ; } rtDW . psbicvw1tn = 0U ; rtDW . n4yx1rctfr = rtP .
DiscreteTimeIntegrator6_gainval * rtB . bunz1k115f + rtB . i5jmft20v3 ; if (
rtB . jx13nwj10i > 0.0 ) { rtDW . c0rsnhvxge = 1 ; } else if ( rtB .
jx13nwj10i < 0.0 ) { rtDW . c0rsnhvxge = - 1 ; } else if ( rtB . jx13nwj10i
== 0.0 ) { rtDW . c0rsnhvxge = 0 ; } else { rtDW . c0rsnhvxge = 2 ; } rtDW .
kko144v51w = 0U ; rtDW . petkjqwhb5 = rtP . DiscreteTimeIntegrator3_gainval *
rtB . cqncnt5j3w + rtB . et3ss0ypwk ; if ( rtB . jx13nwj10i > 0.0 ) { rtDW .
hlh4o42oo3 = 1 ; } else if ( rtB . jx13nwj10i < 0.0 ) { rtDW . hlh4o42oo3 = -
1 ; } else if ( rtB . jx13nwj10i == 0.0 ) { rtDW . hlh4o42oo3 = 0 ; } else {
rtDW . hlh4o42oo3 = 2 ; } rtDW . grbbrolnqo = 0U ; rtDW . icjheye5eq = rtP .
DiscreteTimeIntegrator4_gainval * rtB . p3kz0eppb3 + rtB . eatzl3wsw1 ; if (
rtB . jx13nwj10i > 0.0 ) { rtDW . hr04pilmac = 1 ; } else if ( rtB .
jx13nwj10i < 0.0 ) { rtDW . hr04pilmac = - 1 ; } else if ( rtB . jx13nwj10i
== 0.0 ) { rtDW . hr04pilmac = 0 ; } else { rtDW . hr04pilmac = 2 ; } } if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { rtDW . ow0o42gfhu += rtP .
DiscreteTimeIntegrator_gainval * rtP . Constant3_Value_naltalopjl ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID7 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
int_T is ; uint32_T ri ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; { } for (
is = 0 ; is < 20 ; is ++ ) { _rtXdot -> ci3hspupv1 [ is ] = 0.0 ; } for ( is
= 0 ; is < 20 ; is ++ ) { for ( ri = rtP . AnalogFilterDesign_A_jc [ (
uint32_T ) is ] ; ri < rtP . AnalogFilterDesign_A_jc [ ( uint32_T ) is + 1U ]
; ri ++ ) { _rtXdot -> ci3hspupv1 [ rtP . AnalogFilterDesign_A_ir [ ri ] ] +=
rtP . AnalogFilterDesign_A_pr [ ri ] * rtX . ci3hspupv1 [ ( uint32_T ) is ] ;
} } for ( ri = rtP . AnalogFilterDesign_B_jc [ 0U ] ; ri < rtP .
AnalogFilterDesign_B_jc [ 1U ] ; ri ++ ) { _rtXdot -> ci3hspupv1 [ rtP .
AnalogFilterDesign_B_ir [ ri ] ] += rtP . AnalogFilterDesign_B_pr [ ri ] *
rtB . cns4fjew02 ; } { real_T instantDelay ; instantDelay = rtB . gzm3dlplwu
; if ( instantDelay > rtP . VariableTransportDelay_MaxDelay ) { instantDelay
= rtP . VariableTransportDelay_MaxDelay ; } if ( instantDelay < 0.0 ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> oxih0zc14u = 0 ; } else { ( ( XDot * ) ssGetdX
( rtS ) ) -> oxih0zc14u = 1.0 / instantDelay ; } } } void MdlProjection (
void ) { } void MdlTerminate ( void ) { rt_TDelayFreeBuf ( rtDW . bo3muh5enu
. TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . mrxxjsj4ey . TUbufferPtrs
[ 0 ] ) ; } static void mr_CT_POI_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_CT_POI_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_CT_POI_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_CT_POI_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_CT_POI_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_CT_POI_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_CT_POI_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_CT_POI_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_CT_POI_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_CT_POI_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T
* varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j
) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const
uint8_T * ) srcData , numBytes ) ; } static void
mr_CT_POI_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_CT_POI_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_CT_POI_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_CT_POI_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_CT_POI_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_CT_POI_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal
= ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j
) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray *
mr_CT_POI_GetDWork ( ) { static const char_T * ssDWFieldNames [ 3 ] = { "rtB"
, "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1
, 3 , ssDWFieldNames ) ; mr_CT_POI_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 62 ] = { "rtDW.b2pi4gudhv" , "rtDW.khu2zdxbs4" ,
"rtDW.degrhjleyo" , "rtDW.iifnymjse2" , "rtDW.ecfe4qopis" , "rtDW.hqdcazynvm"
, "rtDW.n4yx1rctfr" , "rtDW.petkjqwhb5" , "rtDW.icjheye5eq" ,
"rtDW.ow0o42gfhu" , "rtDW.i1izcj3aqn" , "rtDW.crayuk1lir" , "rtDW.ltl5bvjttg"
, "rtDW.dyxjcdc4bi" , "rtDW.bobq1qesgz" , "rtDW.om2ho3dulj" ,
"rtDW.mvgx1jbk50" , "rtDW.mskfm2nwhx" , "rtDW.ezlg5otozk" , "rtDW.heqq1kpetm"
, "rtDW.ee5qp1cpiz" , "rtDW.mjvxwfupof" , "rtDW.brknn13uxf" ,
"rtDW.g5lav3j02c" , "rtDW.cgru1gwg0r" , "rtDW.hrj4u4frdf" , "rtDW.iqp54sidls"
, "rtDW.g0ulyhynln" , "rtDW.jken4w0gjf" , "rtDW.jx3alr4qwb" ,
"rtDW.m14sbehec2" , "rtDW.f2oac5wnal" , "rtDW.jdgjatsyrt" , "rtDW.gttvq41aan"
, "rtDW.cazujz0icx" , "rtDW.nxrgsy2c2w" , "rtDW.opvzyiyp3j" ,
"rtDW.adldhalszk" , "rtDW.ngrrkreo2f" , "rtDW.enivbnqm2z" , "rtDW.bu5tr1pdox"
, "rtDW.ma50gapxoa" , "rtDW.ornpy4cdl1" , "rtDW.c0rsnhvxge" ,
"rtDW.imgxzfpyet" , "rtDW.hlh4o42oo3" , "rtDW.hr04pilmac" , "rtDW.ficexzqbh2"
, "rtDW.agygzdruc0" , "rtDW.co4yicnm0d" , "rtDW.m1ai31i3so" ,
"rtDW.psbicvw1tn" , "rtDW.kko144v51w" , "rtDW.grbbrolnqo" , "rtDW.pemmcx3bjg"
, "rtDW.acu0fobbd3" , "rtDW.kzklpmmpnf" , "rtDW.hdirjwpdhq" ,
"rtDW.dypy444pvq" , "rtDW.hp4k1chfue" , "rtDW.dc1nkzv5gn" , "rtDW.eshgyurwuf"
, } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 62 ,
rtdwDataFieldNames ) ; mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 0 , (
const void * ) & ( rtDW . b2pi4gudhv ) , sizeof ( rtDW . b2pi4gudhv ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW .
khu2zdxbs4 ) , sizeof ( rtDW . khu2zdxbs4 ) ) ; mr_CT_POI_cacheDataAsMxArray
( rtdwData , 0 , 2 , ( const void * ) & ( rtDW . degrhjleyo ) , sizeof ( rtDW
. degrhjleyo ) ) ; mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const
void * ) & ( rtDW . iifnymjse2 ) , sizeof ( rtDW . iifnymjse2 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW .
ecfe4qopis ) , sizeof ( rtDW . ecfe4qopis ) ) ; mr_CT_POI_cacheDataAsMxArray
( rtdwData , 0 , 5 , ( const void * ) & ( rtDW . hqdcazynvm ) , sizeof ( rtDW
. hqdcazynvm ) ) ; mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const
void * ) & ( rtDW . n4yx1rctfr ) , sizeof ( rtDW . n4yx1rctfr ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW .
petkjqwhb5 ) , sizeof ( rtDW . petkjqwhb5 ) ) ; mr_CT_POI_cacheDataAsMxArray
( rtdwData , 0 , 8 , ( const void * ) & ( rtDW . icjheye5eq ) , sizeof ( rtDW
. icjheye5eq ) ) ; mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const
void * ) & ( rtDW . ow0o42gfhu ) , sizeof ( rtDW . ow0o42gfhu ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & ( rtDW
. i1izcj3aqn ) , sizeof ( rtDW . i1izcj3aqn ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & ( rtDW
. crayuk1lir ) , sizeof ( rtDW . crayuk1lir ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & ( rtDW
. ltl5bvjttg ) , sizeof ( rtDW . ltl5bvjttg ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & ( rtDW
. dyxjcdc4bi ) , sizeof ( rtDW . dyxjcdc4bi ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW
. bobq1qesgz ) , sizeof ( rtDW . bobq1qesgz ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & ( rtDW
. om2ho3dulj ) , sizeof ( rtDW . om2ho3dulj ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & ( rtDW
. mvgx1jbk50 ) , sizeof ( rtDW . mvgx1jbk50 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & ( rtDW
. mskfm2nwhx ) , sizeof ( rtDW . mskfm2nwhx ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & ( rtDW
. ezlg5otozk ) , sizeof ( rtDW . ezlg5otozk ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & ( rtDW
. heqq1kpetm ) , sizeof ( rtDW . heqq1kpetm ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & ( rtDW
. ee5qp1cpiz ) , sizeof ( rtDW . ee5qp1cpiz ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & ( rtDW
. mjvxwfupof ) , sizeof ( rtDW . mjvxwfupof ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & ( rtDW
. brknn13uxf ) , sizeof ( rtDW . brknn13uxf ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & ( rtDW
. g5lav3j02c ) , sizeof ( rtDW . g5lav3j02c ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & ( rtDW
. cgru1gwg0r ) , sizeof ( rtDW . cgru1gwg0r ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & ( rtDW
. hrj4u4frdf ) , sizeof ( rtDW . hrj4u4frdf ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & ( rtDW
. iqp54sidls ) , sizeof ( rtDW . iqp54sidls ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & ( rtDW
. g0ulyhynln ) , sizeof ( rtDW . g0ulyhynln ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & ( rtDW
. jken4w0gjf ) , sizeof ( rtDW . jken4w0gjf ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & ( rtDW
. jx3alr4qwb ) , sizeof ( rtDW . jx3alr4qwb ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & ( rtDW
. m14sbehec2 ) , sizeof ( rtDW . m14sbehec2 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & ( rtDW
. f2oac5wnal ) , sizeof ( rtDW . f2oac5wnal ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & ( rtDW
. jdgjatsyrt ) , sizeof ( rtDW . jdgjatsyrt ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & ( rtDW
. gttvq41aan ) , sizeof ( rtDW . gttvq41aan ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & ( rtDW
. cazujz0icx ) , sizeof ( rtDW . cazujz0icx ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & ( rtDW
. nxrgsy2c2w ) , sizeof ( rtDW . nxrgsy2c2w ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) & ( rtDW
. opvzyiyp3j ) , sizeof ( rtDW . opvzyiyp3j ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) & ( rtDW
. adldhalszk ) , sizeof ( rtDW . adldhalszk ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & ( rtDW
. ngrrkreo2f ) , sizeof ( rtDW . ngrrkreo2f ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & ( rtDW
. enivbnqm2z ) , sizeof ( rtDW . enivbnqm2z ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) & ( rtDW
. bu5tr1pdox ) , sizeof ( rtDW . bu5tr1pdox ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) & ( rtDW
. ma50gapxoa ) , sizeof ( rtDW . ma50gapxoa ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) & ( rtDW
. ornpy4cdl1 ) , sizeof ( rtDW . ornpy4cdl1 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) & ( rtDW
. c0rsnhvxge ) , sizeof ( rtDW . c0rsnhvxge ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) & ( rtDW
. imgxzfpyet ) , sizeof ( rtDW . imgxzfpyet ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) & ( rtDW
. hlh4o42oo3 ) , sizeof ( rtDW . hlh4o42oo3 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) & ( rtDW
. hr04pilmac ) , sizeof ( rtDW . hr04pilmac ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) & ( rtDW
. ficexzqbh2 ) , sizeof ( rtDW . ficexzqbh2 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void * ) & ( rtDW
. agygzdruc0 ) , sizeof ( rtDW . agygzdruc0 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void * ) & ( rtDW
. co4yicnm0d ) , sizeof ( rtDW . co4yicnm0d ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) & ( rtDW
. m1ai31i3so ) , sizeof ( rtDW . m1ai31i3so ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void * ) & ( rtDW
. psbicvw1tn ) , sizeof ( rtDW . psbicvw1tn ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void * ) & ( rtDW
. kko144v51w ) , sizeof ( rtDW . kko144v51w ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void * ) & ( rtDW
. grbbrolnqo ) , sizeof ( rtDW . grbbrolnqo ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void * ) & ( rtDW
. pemmcx3bjg ) , sizeof ( rtDW . pemmcx3bjg ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void * ) & ( rtDW
. acu0fobbd3 ) , sizeof ( rtDW . acu0fobbd3 ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void * ) & ( rtDW
. kzklpmmpnf ) , sizeof ( rtDW . kzklpmmpnf ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void * ) & ( rtDW
. hdirjwpdhq ) , sizeof ( rtDW . hdirjwpdhq ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const void * ) & ( rtDW
. dypy444pvq ) , sizeof ( rtDW . dypy444pvq ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void * ) & ( rtDW
. hp4k1chfue ) , sizeof ( rtDW . hp4k1chfue ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 60 , ( const void * ) & ( rtDW
. dc1nkzv5gn ) , sizeof ( rtDW . dc1nkzv5gn ) ) ;
mr_CT_POI_cacheDataAsMxArray ( rtdwData , 0 , 61 , ( const void * ) & ( rtDW
. eshgyurwuf ) , sizeof ( rtDW . eshgyurwuf ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_CT_POI_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_CT_POI_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_CT_POI_restoreDataFromMxArray ( (
void * ) & ( rtDW . b2pi4gudhv ) , rtdwData , 0 , 0 , sizeof ( rtDW .
b2pi4gudhv ) ) ; mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW .
khu2zdxbs4 ) , rtdwData , 0 , 1 , sizeof ( rtDW . khu2zdxbs4 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . degrhjleyo ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . degrhjleyo ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . iifnymjse2 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . iifnymjse2 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ecfe4qopis ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . ecfe4qopis ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hqdcazynvm ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . hqdcazynvm ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . n4yx1rctfr ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . n4yx1rctfr ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . petkjqwhb5 ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . petkjqwhb5 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . icjheye5eq ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . icjheye5eq ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ow0o42gfhu ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . ow0o42gfhu ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . i1izcj3aqn ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . i1izcj3aqn ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . crayuk1lir ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . crayuk1lir ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ltl5bvjttg ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . ltl5bvjttg ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . dyxjcdc4bi ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . dyxjcdc4bi ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . bobq1qesgz ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . bobq1qesgz ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . om2ho3dulj ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . om2ho3dulj ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . mvgx1jbk50 ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . mvgx1jbk50 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . mskfm2nwhx ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . mskfm2nwhx ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ezlg5otozk ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . ezlg5otozk ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . heqq1kpetm ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . heqq1kpetm ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ee5qp1cpiz ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . ee5qp1cpiz ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . mjvxwfupof ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . mjvxwfupof ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . brknn13uxf ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . brknn13uxf ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . g5lav3j02c ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . g5lav3j02c ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . cgru1gwg0r ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . cgru1gwg0r ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hrj4u4frdf ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . hrj4u4frdf ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . iqp54sidls ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . iqp54sidls ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . g0ulyhynln ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . g0ulyhynln ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . jken4w0gjf ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . jken4w0gjf ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . jx3alr4qwb ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . jx3alr4qwb ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . m14sbehec2 ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . m14sbehec2 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . f2oac5wnal ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . f2oac5wnal ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . jdgjatsyrt ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . jdgjatsyrt ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . gttvq41aan ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . gttvq41aan ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . cazujz0icx ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . cazujz0icx ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . nxrgsy2c2w ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . nxrgsy2c2w ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . opvzyiyp3j ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . opvzyiyp3j ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . adldhalszk ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . adldhalszk ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ngrrkreo2f ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . ngrrkreo2f ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . enivbnqm2z ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . enivbnqm2z ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . bu5tr1pdox ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . bu5tr1pdox ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ma50gapxoa ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . ma50gapxoa ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ornpy4cdl1 ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . ornpy4cdl1 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . c0rsnhvxge ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . c0rsnhvxge ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . imgxzfpyet ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . imgxzfpyet ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hlh4o42oo3 ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . hlh4o42oo3 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hr04pilmac ) ,
rtdwData , 0 , 46 , sizeof ( rtDW . hr04pilmac ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . ficexzqbh2 ) ,
rtdwData , 0 , 47 , sizeof ( rtDW . ficexzqbh2 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . agygzdruc0 ) ,
rtdwData , 0 , 48 , sizeof ( rtDW . agygzdruc0 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . co4yicnm0d ) ,
rtdwData , 0 , 49 , sizeof ( rtDW . co4yicnm0d ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . m1ai31i3so ) ,
rtdwData , 0 , 50 , sizeof ( rtDW . m1ai31i3so ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . psbicvw1tn ) ,
rtdwData , 0 , 51 , sizeof ( rtDW . psbicvw1tn ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . kko144v51w ) ,
rtdwData , 0 , 52 , sizeof ( rtDW . kko144v51w ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . grbbrolnqo ) ,
rtdwData , 0 , 53 , sizeof ( rtDW . grbbrolnqo ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . pemmcx3bjg ) ,
rtdwData , 0 , 54 , sizeof ( rtDW . pemmcx3bjg ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . acu0fobbd3 ) ,
rtdwData , 0 , 55 , sizeof ( rtDW . acu0fobbd3 ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . kzklpmmpnf ) ,
rtdwData , 0 , 56 , sizeof ( rtDW . kzklpmmpnf ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hdirjwpdhq ) ,
rtdwData , 0 , 57 , sizeof ( rtDW . hdirjwpdhq ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . dypy444pvq ) ,
rtdwData , 0 , 58 , sizeof ( rtDW . dypy444pvq ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . hp4k1chfue ) ,
rtdwData , 0 , 59 , sizeof ( rtDW . hp4k1chfue ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . dc1nkzv5gn ) ,
rtdwData , 0 , 60 , sizeof ( rtDW . dc1nkzv5gn ) ) ;
mr_CT_POI_restoreDataFromMxArray ( ( void * ) & ( rtDW . eshgyurwuf ) ,
rtdwData , 0 , 61 , sizeof ( rtDW . eshgyurwuf ) ) ; } } mxArray *
mr_CT_POI_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 1 ] = { "MATLABSystem" , } ; static const char_T *
blockPath [ 1 ] = { "CT_POI/AWGN Channel" , } ; static const int reason [ 1 ]
= { 6 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 1 ; ++ ( subs [ 0 ] ) ) {
subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 21 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 7 ) ; ssSetNumBlocks ( rtS , 78 ) ;
ssSetNumBlockIO ( rtS , 35 ) ; ssSetNumBlockParams ( rtS , 234 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 1.955E-7 ) ;
ssSetSampleTime ( rtS , 3 , 1.955E-6 ) ; ssSetSampleTime ( rtS , 4 ,
0.0004995025 ) ; ssSetSampleTime ( rtS , 5 , 0.001 ) ; ssSetSampleTime ( rtS
, 6 , - 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1
, 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0
) ; ssSetOffsetTime ( rtS , 4 , 0.0 ) ; ssSetOffsetTime ( rtS , 5 , 0.0 ) ;
ssSetOffsetTime ( rtS , 6 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2059667716U ) ; ssSetChecksumVal ( rtS , 1 ,
822817126U ) ; ssSetChecksumVal ( rtS , 2 , 3881375U ) ; ssSetChecksumVal (
rtS , 3 , 2437997414U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; { rtB .
oiagjxsfua = 0.0 ; rtB . ptxjsacnuh = 0.0 ; rtB . aeq5ruscfh = 0.0 ; rtB .
pnfujicrav = 0.0 ; rtB . fo3o0qx3rk = 0.0 ; rtB . h00tanbm5k = 0.0 ; rtB .
abu2iacvsb = 0.0 ; rtB . hcqcgye2fg = 0.0 ; rtB . jx13nwj10i = 0.0 ; rtB .
i50ghe5lm1 = 0.0 ; rtB . nym1g1yulh = 0.0 ; rtB . eue4pzm2um = 0.0 ; rtB .
nxismlfsz2 = 0.0 ; rtB . nbzdbx43y2 = 0.0 ; rtB . cskkp1pbit = 0.0 ; rtB .
ekkv4odda4 = 0.0 ; rtB . he1lzb12tu = 0.0 ; rtB . bunz1k115f = 0.0 ; rtB .
i5jmft20v3 = 0.0 ; rtB . c1hzatsvvq = 0.0 ; rtB . ahaloitnql = 0.0 ; rtB .
cqncnt5j3w = 0.0 ; rtB . et3ss0ypwk = 0.0 ; rtB . p3kz0eppb3 = 0.0 ; rtB .
eatzl3wsw1 = 0.0 ; rtB . lydxvhyrns = 0.0 ; rtB . f2shyu0rcb = 0.0 ; rtB .
lrjqprgrv3 = 0.0 ; rtB . ka0zgragyp = 0.0 ; rtB . k42ztcl2nd = 0.0 ; rtB .
gzm3dlplwu = 0.0 ; rtB . mh3qnuillk = 0.0 ; rtB . cns4fjew02 = 0.0 ; } } {
real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; { int32_T i ; for ( i = 0 ; i < 5110 ; i ++ ) { rtDW . khu2zdxbs4
[ i ] = 0.0 ; } } { int32_T i ; for ( i = 0 ; i < 5110 ; i ++ ) { rtDW .
degrhjleyo [ i ] = 0.0 ; } } rtDW . iifnymjse2 = 0.0 ; rtDW . ecfe4qopis =
0.0 ; rtDW . hqdcazynvm = 0.0 ; rtDW . n4yx1rctfr = 0.0 ; rtDW . petkjqwhb5 =
0.0 ; rtDW . icjheye5eq = 0.0 ; rtDW . ow0o42gfhu = 0.0 ; rtDW . i1izcj3aqn =
0.0 ; rtDW . crayuk1lir = 0.0 ; rtDW . ltl5bvjttg = 0.0 ; rtDW . dyxjcdc4bi =
0.0 ; rtDW . bobq1qesgz = 0.0 ; rtDW . mvgx1jbk50 . modelTStart = 0.0 ; rtDW
. mskfm2nwhx . modelTStart = 0.0 ; } { static DataTypeTransInfo dtInfo ; (
void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 27 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } CT_POI_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"CT_POI" ) ; ssSetPath ( rtS , "CT_POI" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 0.10101 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 20 , 1
, 5110 , 5110 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 9 , 9 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 20 , 1 , 5110 , 5110 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 9 , 9 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32
, SS_INT32 , SS_UINT8 , SS_UINT8 } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CircBuf" , "CircBuf" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "inBufPtrIdx" , "outBufPtrIdx"
, "bufferLength" , "inBufPtrIdx" , "outBufPtrIdx" , "bufferLength" ,
"shiftReg" , "shiftReg" } ; static const char_T * rt_LoggedStateBlockNames [
] = { "CT_POI/Analog\nFilter Design" ,
"CT_POI/Subsystem5/Subsystem/Variable\nTransport Delay" ,
"CT_POI/Subsystem4/Buffer1" , "CT_POI/Subsystem4/Buffer3" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator1" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator2" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator5" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator6" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator3" ,
"CT_POI/Subsystem5/Discrete-Time\nIntegrator4" ,
"CT_POI/Subsystem2/Discrete-Time\nIntegrator" , "CT_POI/Subsystem4/Buffer1" ,
"CT_POI/Subsystem4/Buffer1" , "CT_POI/Subsystem4/Buffer1" ,
"CT_POI/Subsystem4/Buffer3" , "CT_POI/Subsystem4/Buffer3" ,
"CT_POI/Subsystem4/Buffer3" , "CT_POI/Subsystem5/PN Sequence\nGenerator2" ,
"CT_POI/Subsystem2/PN Sequence\nGenerator2" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "shiftReg" , "shiftReg" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32
, 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 ,
0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_UINT8 , SS_UINT8
, 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_UINT8 , SS_UINT8 , 0 , 0 , 0 , 1.0 ,
0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 1 , 2 , 3 ,
4 , 5 , 6 , 7 , 8 , 9 , 20 , 21 , 22 , 23 , 24 , 25 , 37 , 38 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 19 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 19 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ci3hspupv1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . oxih0zc14u ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . khu2zdxbs4 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . degrhjleyo ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . iifnymjse2 ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . ecfe4qopis ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtDW . hqdcazynvm ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . n4yx1rctfr ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . petkjqwhb5 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . icjheye5eq ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . ow0o42gfhu ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtDW . ezlg5otozk ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtDW . heqq1kpetm ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtDW . ee5qp1cpiz ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtDW . mjvxwfupof ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtDW . brknn13uxf ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtDW . g5lav3j02c ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) rtDW . nxrgsy2c2w ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) rtDW . opvzyiyp3j ; }
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
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 21 ] ;
static real_T absTol [ 21 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 21 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static
real_T contStateJacPerturbBoundMinVec [ 21 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 21 ] ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cns4fjew02 ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 21 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS ,
1.955E-7 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor (
rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS ,
0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2059667716U ) ; ssSetChecksumVal ( rtS , 1 ,
822817126U ) ; ssSetChecksumVal ( rtS , 2 , 3881375U ) ; ssSetChecksumVal (
rtS , 3 , 2437997414U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_CT_POI_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_CT_POI_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_CT_POI_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 7 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID7 ( tid ) ; }
