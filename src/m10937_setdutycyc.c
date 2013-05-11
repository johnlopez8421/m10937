#include "m10937.h"

/*** m10937_setdutycyc - sets the display duty cycle
*
*	parameters:
*		dcyc: duty cycle (0 to 31)
*	returns: none
*	warnings: none
*
***/
void m10937_setdutycyc(uint8_t dcyc)
{
	dcyc &= M10937_MASKDCY;
	dcyc |= M10937_CTRLDCY;
	
	m10937_wrbyte(dcyc);
}
