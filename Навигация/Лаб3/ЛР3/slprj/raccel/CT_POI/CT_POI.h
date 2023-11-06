#ifndef RTW_HEADER_CT_POI_h_
#define RTW_HEADER_CT_POI_h_
#ifndef CT_POI_COMMON_INCLUDES_
#define CT_POI_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "CT_POI_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include "rtGetNaN.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#define MODEL_NAME CT_POI
#define NSAMPLE_TIMES (8) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (35) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (21)   
#elif NCSTATES != 21
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T k1bdv0g0en_mbvzarwird [ 2555 ] ; real_T
l4jx0r12q0_cl54gopm0x [ 2555 ] ; real_T oiagjxsfua ; real_T ptxjsacnuh ;
real_T aeq5ruscfh ; real_T pnfujicrav ; real_T fo3o0qx3rk ; real_T h00tanbm5k
; real_T abu2iacvsb ; real_T hcqcgye2fg ; real_T jx13nwj10i ; real_T
i50ghe5lm1 ; real_T nym1g1yulh ; real_T eue4pzm2um ; real_T nxismlfsz2 ;
real_T nbzdbx43y2 ; real_T cskkp1pbit ; real_T ekkv4odda4 ; real_T he1lzb12tu
; real_T bunz1k115f ; real_T i5jmft20v3 ; real_T c1hzatsvvq ; real_T
ahaloitnql ; real_T cqncnt5j3w ; real_T et3ss0ypwk ; real_T p3kz0eppb3 ;
real_T eatzl3wsw1 ; real_T lydxvhyrns ; real_T f2shyu0rcb ; real_T lrjqprgrv3
; real_T ka0zgragyp ; real_T k42ztcl2nd ; real_T gzm3dlplwu ; real_T
mh3qnuillk ; real_T cns4fjew02 ; uint8_T iaqfq2eapm ; boolean_T aes5bhgd15 ;
} B ; typedef struct { cqb32sjpki b2pi4gudhv ; real_T khu2zdxbs4 [ 5110 ] ;
real_T degrhjleyo [ 5110 ] ; real_T iifnymjse2 ; real_T ecfe4qopis ; real_T
hqdcazynvm ; real_T n4yx1rctfr ; real_T petkjqwhb5 ; real_T icjheye5eq ;
real_T ow0o42gfhu ; real_T i1izcj3aqn ; real_T crayuk1lir ; real_T ltl5bvjttg
; real_T dyxjcdc4bi ; real_T bobq1qesgz ; int64_T om2ho3dulj ; struct {
real_T modelTStart ; } mvgx1jbk50 ; struct { real_T modelTStart ; }
mskfm2nwhx ; struct { void * TUbufferPtrs [ 2 ] ; } bo3muh5enu ; struct {
void * TUbufferPtrs [ 3 ] ; } mrxxjsj4ey ; int32_T ezlg5otozk ; int32_T
heqq1kpetm ; int32_T ee5qp1cpiz ; int32_T mjvxwfupof ; int32_T brknn13uxf ;
int32_T g5lav3j02c ; int32_T cgru1gwg0r ; int32_T hrj4u4frdf ; uint32_T
iqp54sidls ; uint32_T g0ulyhynln [ 625 ] ; uint32_T jken4w0gjf [ 2 ] ;
uint32_T jx3alr4qwb ; uint32_T m14sbehec2 ; uint32_T f2oac5wnal ; uint32_T
jdgjatsyrt [ 2 ] ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } gttvq41aan ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
cazujz0icx ; uint8_T nxrgsy2c2w [ 9 ] ; uint8_T opvzyiyp3j [ 9 ] ; uint8_T
adldhalszk ; int8_T ngrrkreo2f ; int8_T enivbnqm2z ; int8_T bu5tr1pdox ;
int8_T ma50gapxoa ; int8_T ornpy4cdl1 ; int8_T c0rsnhvxge ; int8_T imgxzfpyet
; int8_T hlh4o42oo3 ; int8_T hr04pilmac ; int8_T ficexzqbh2 ; uint8_T
agygzdruc0 ; uint8_T co4yicnm0d ; uint8_T m1ai31i3so ; uint8_T psbicvw1tn ;
uint8_T kko144v51w ; uint8_T grbbrolnqo ; boolean_T pemmcx3bjg ; boolean_T
acu0fobbd3 ; boolean_T kzklpmmpnf ; boolean_T hdirjwpdhq ; boolean_T
dypy444pvq ; boolean_T hp4k1chfue ; boolean_T dc1nkzv5gn ; boolean_T
eshgyurwuf ; } DW ; typedef struct { real_T ci3hspupv1 [ 20 ] ; real_T
oxih0zc14u ; } X ; typedef struct { real_T ci3hspupv1 [ 20 ] ; real_T
oxih0zc14u ; } XDot ; typedef struct { boolean_T ci3hspupv1 [ 20 ] ;
boolean_T oxih0zc14u ; } XDis ; typedef struct { real_T ci3hspupv1 [ 20 ] ;
real_T oxih0zc14u ; } CStateAbsTol ; typedef struct { real_T ci3hspupv1 [ 20
] ; real_T oxih0zc14u ; } CXPtMin ; typedef struct { real_T ci3hspupv1 [ 20 ]
; real_T oxih0zc14u ; } CXPtMax ; typedef struct { uint8_T ejilaj33zh [ 10 ]
; uint8_T ep40zoormj [ 9 ] ; uint8_T nmkf01nuia [ 9 ] ; } ConstP ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
AWGNChannel_SNR ; real_T AWGNChannel_SignalPower ; real_T
VariableTransportDelay1_MaxDelay ; real_T VariableTransportDelay1_InitOutput
; real_T Buffer1_ic ; real_T AnalogFilterDesign_A_pr [ 55 ] ; real_T
AnalogFilterDesign_B_pr [ 5 ] ; real_T AnalogFilterDesign_C_pr [ 10 ] ;
real_T AnalogFilterDesign_D_pr ; real_T AnalogFilterDesign_InitialCondition ;
real_T Buffer3_ic ; real_T Constant4_Value ; real_T Gain_Gain ; real_T
VariableTransportDelay_MaxDelay ; real_T VariableTransportDelay_InitOutput ;
real_T PulseGenerator1_Amp ; real_T PulseGenerator1_Period ; real_T
PulseGenerator1_Duty ; real_T PulseGenerator1_PhaseDelay ; real_T
DiscreteTimeIntegrator1_gainval ; real_T DiscreteTimeIntegrator1_IC ; real_T
DiscreteTimeIntegrator2_gainval ; real_T DiscreteTimeIntegrator2_IC ; real_T
DiscreteTimeIntegrator5_gainval ; real_T DiscreteTimeIntegrator5_IC ; real_T
DiscreteTimeIntegrator6_gainval ; real_T DiscreteTimeIntegrator6_IC ; real_T
Constant3_Value ; real_T DiscreteTimeIntegrator3_gainval ; real_T
DiscreteTimeIntegrator3_IC ; real_T DiscreteTimeIntegrator4_gainval ; real_T
DiscreteTimeIntegrator4_IC ; real_T DiscreteTimeIntegrator_gainval ; real_T
Constant3_Value_naltalopjl ; real_T Gain_Gain_donlcyw5bh ; real_T Gain1_Gain
; real_T Constant1_Value ; real_T Constant_Value ; real_T Constant2_Value ;
int32_T Gain_Gain_c0wzfxwapi ; int32_T Bias_Bias ; int32_T
Gain1_Gain_jhwyhxq2zq ; int32_T Gain_Gain_hnwxniojmd ; int32_T
Bias_Bias_fafg04n1yq ; int32_T Gain1_Gain_lhfiaw3lod ; uint32_T
AnalogFilterDesign_A_ir [ 55 ] ; uint32_T AnalogFilterDesign_A_jc [ 21 ] ;
uint32_T AnalogFilterDesign_B_ir [ 5 ] ; uint32_T AnalogFilterDesign_B_jc [ 2
] ; uint32_T AnalogFilterDesign_C_ir [ 10 ] ; uint32_T
AnalogFilterDesign_C_jc [ 21 ] ; uint32_T AnalogFilterDesign_D_ir ; uint32_T
AnalogFilterDesign_D_jc [ 2 ] ; boolean_T CombinatorialLogic_table [ 4 ] ;
uint8_T DiscreteTimeIntegrator_IC ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const ConstP rtConstP ; extern mxArray *
mr_CT_POI_GetDWork ( ) ; extern void mr_CT_POI_SetDWork ( const mxArray *
ssDW ) ; extern mxArray * mr_CT_POI_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * CT_POI_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
