#include "m10937.h"

/*** m10937_off - turns the disply off
*
*	parameters: none
*	returns: none
*	warnings: none
*
***/
void m10937_off()
{
	m10937_setdutycyc(M10937_DUTYCYCOFF);
}