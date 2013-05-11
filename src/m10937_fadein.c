#include <util/delay.h>
#include "m10937.h"

/*** m10937_fadein - does a fade in of the display
*
*	parameters: none
*	returns: none
*	warnings: none
*
***/
void m10937_fadein(void)
{
	uint8_t j;
	for(j=M10937_DUTYCYCOFF; j<=M10937_DUTYCYCFULL; j++)
	{
		m10937_setdutycyc(j);
		_delay_ms(50);
	}
}