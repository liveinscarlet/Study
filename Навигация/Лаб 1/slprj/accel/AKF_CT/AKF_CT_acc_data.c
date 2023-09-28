#include "AKF_CT_acc.h"
#include "AKF_CT_acc_private.h"
P_AKF_CT_T AKF_CT_rtDefaultP = { 1.0 , 0.002 , 50.0 , 0.0 , 0.0 , 1.0 , 0.0 ,
1024.0 , 0.0 , 1.0 , 0.001 , 50.0 , 0.0005 , 0.00097847358121330719 , 0.0 ,
0.0 , 1.955E-6 , 0.0 , 2 , - 1 , 1 , { 'a' , 'a' , 'a' , 'a' } } ; const
ConstP_AKF_CT_T AKF_CT_rtConstP = { { 1U , 0U , 0U , 0U , 1U , 0U , 0U , 0U ,
0U , 1U } , { 1U , 1U , 1U , 1U , 1U , 1U , 1U , 1U , 1U } , { 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 1U } , { 'a' , 'a' , 'a' , 'a' } } ;
