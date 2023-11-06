#include "CT_POI_acc.h"
#include "CT_POI_acc_private.h"
P_CT_POI_T CT_POI_rtDefaultP = { 511.0 , 0.0 , 0.0 , { -
2.0718413303013191E+7 , 1.0897054066830145E+7 , - 2.0718413303013191E+7 , -
2.0718413303013191E+7 , - 2.0718413303013191E+7 , - 2.0718413303013191E+7 , -
1.5390597961942369E+7 , - 1.089705406683014E+7 , 1.3714522022604591E+8 ,
1.3714522022604591E+8 , 1.3714522022604591E+8 , 1.3714522022604591E+8 , -
1.5390597961942369E+7 , - 1.2086865425403988E+7 , 8.7630890374057181E+6 , -
1.2086865425403988E+7 , - 1.2086865425403988E+7 , - 1.2086865425403988E+7 , -
1.5390597961942369E+7 , - 8.7630890374057181E+6 , 1.3094838538886307E+7 ,
1.3094838538886307E+7 , 1.3094838538886307E+7 , - 1.5390597961942369E+7 , -
6.1031939160699891E+6 , 6.9899956654894138E+6 , - 6.1031939160699891E+6 , -
6.1031939160699891E+6 , - 1.5390597961942369E+7 , - 6.9899956654894119E+6 ,
4.3056959182029562E+6 , 4.3056959182029562E+6 , - 1.5390597961942369E+7 , -
2.8733568497559531E+6 , 5.9856624691029442E+6 , - 2.8733568497559531E+6 , -
1.5390597961942369E+7 , - 5.9856624691029452E+6 , 2.3221320277152634E+6 , -
1.5390597961942369E+7 , - 849979.634361413 , 5.545987193609016E+6 , -
1.5390597961942369E+7 , - 5.5459871936090151E+6 , - 1.5390597961942369E+7 ,
1.5390597961942369E+7 , 1.5390597961942369E+7 , 1.5390597961942369E+7 ,
1.5390597961942369E+7 , 1.5390597961942369E+7 , 1.5390597961942369E+7 ,
1.5390597961942369E+7 , 1.5390597961942369E+7 , 1.5390597961942369E+7 ,
1.5390597961942369E+7 } , { 6.283185307179587E+6 , 6.283185307179587E+6 ,
6.283185307179587E+6 , 6.283185307179587E+6 , 6.283185307179587E+6 } , { -
0.032974378901954267 , 0.21827339720401751 , - 0.019236843789395656 ,
0.020841082824540048 , - 0.0097135348039091938 , 0.0068527278883259643 , -
0.0045730894590561566 , 0.0036957879072288969 , - 0.0013527846033606046 ,
0.0027867344929751723 } , 0.0099999999999999846 , 0.0 , 0.0 , 0.0 ,
1.5707963267948966E+7 , 2.0 , 0.0 , 1.0 , 0.001 , 50.0 , 0.0005 ,
9.7847358121330727E-5 , 0.0 , 9.7847358121330727E-5 , 0.0 ,
9.7847358121330727E-5 , 0.0 , 9.7847358121330727E-5 , 0.0 , 0.0 ,
9.7847358121330727E-5 , 0.0 , 9.7847358121330727E-5 , 0.0 , 1.0 , 0.01 ,
1.5707963267948966E+7 , 6.2831853071795862 , 1.955E-6 , 1.0E-5 , 1.955E-6 , 2
, - 1 , 1 , 2 , - 1 , 1 , { 0U , 1U , 2U , 4U , 6U , 8U , 10U , 0U , 2U , 4U
, 6U , 8U , 11U , 2U , 3U , 4U , 6U , 8U , 12U , 2U , 4U , 6U , 8U , 13U , 4U
, 5U , 6U , 8U , 14U , 4U , 6U , 8U , 15U , 6U , 7U , 8U , 16U , 6U , 8U ,
17U , 8U , 9U , 18U , 8U , 19U , 0U , 1U , 2U , 3U , 4U , 5U , 6U , 7U , 8U ,
9U } , { 0U , 7U , 13U , 19U , 24U , 29U , 33U , 37U , 40U , 43U , 45U , 46U
, 47U , 48U , 49U , 50U , 51U , 52U , 53U , 54U , 55U } , { 0U , 2U , 4U , 6U
, 8U } , { 0U , 5U } , { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ,
{ 0U , 1U , 2U , 3U , 4U , 5U , 6U , 7U , 8U , 9U , 10U , 10U , 10U , 10U ,
10U , 10U , 10U , 10U , 10U , 10U , 10U } , 0U , { 0U , 1U } , { false ,
false , true , false } , 0U , { 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' } } ;
const ConstP_CT_POI_T CT_POI_rtConstP = { { 1U , 0U , 0U , 0U , 0U , 1U , 0U
, 0U , 0U , 1U } , { 1U , 0U , 1U , 1U , 1U , 0U , 1U , 1U , 1U } , { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 1U } , { 1U , 1U , 1U , 1U , 1U , 1U , 1U ,
1U , 1U } , { 'a' , 'a' , 'a' } } ;
