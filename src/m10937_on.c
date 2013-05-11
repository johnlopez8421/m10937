#include "m10937.h"
/*** m10937_on - turns the display on (full duty cycle)
*	
*	paramters: none
*	returns: none
*	warnings: none
*
***/
void m10937_on()
{
	m10937_setdutycyc(M10937_DUTYCYCFULL);
}