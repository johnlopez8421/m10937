#include "m10937.h"
#include <util/delay.h>

/*** m10937_fadeout - does a fade out of the display
*
*	parameters: none
*	returns: none
*	warnings: none
*
***/
void m10937_fadeout(void)
{
	uint8_t j;
	for(j=M10937_DUTYCYCFULL; j!=M10937_DUTYCYCOFF; j--)
	{
		m10937_setdutycyc(j);
		_delay_ms(50);
	}
	m10937_setdutycyc(M10937_DUTYCYCOFF);
}
			
