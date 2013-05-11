#include "m10937.h"

/*** m10937_setbufpos - sets the buffer position
*
*	parameters:
*		pos: position to set (actual position)
*	returns: none
*	warnings: this function includes logic to account for the hardware's
*		'off by two' functionality. This should be used to overwrite an 
*		existing string, or '@' chars will appear in the lower-order unused
*		locations.
*
***/
void m10937_setbufpos(uint8_t pos)
{
	pos &= M10937_MASKPTR;
	
	if(pos==1) 
	{
		pos = 15;
	}
	else 
	{
		pos -= 2;
	}
	pos |= M10937_CTRLPTR;
	m10937_wrbyte(pos);
}