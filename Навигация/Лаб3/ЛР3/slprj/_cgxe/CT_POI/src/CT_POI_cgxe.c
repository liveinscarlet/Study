/* Include files */

#include "CT_POI_cgxe.h"
#include "m_IMv9yOrM7PumNuduIww3wH.h"

unsigned int cgxe_CT_POI_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 3941296312 &&
      ssGetChecksum1(S) == 1750535636 &&
      ssGetChecksum2(S) == 1447777257 &&
      ssGetChecksum3(S) == 2433364046) {
    method_dispatcher_IMv9yOrM7PumNuduIww3wH(S, method, data);
    return 1;
  }

  return 0;
}
