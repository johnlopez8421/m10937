#include "m10937.h"

/*** m10937_setdigctr - sets the digit counter
*
*	parameters:
*		count: counter value
*	returns: none
*	warnings: none
*
***/

void m10937_setdigctr(uint8_t count)
{
	count &= M10937_MASKCNT;
	if(count==16) count = 0;	// 0 means all digits
	
	count |= M10937_CTRLCNT;
	
	m10937_wrbyte(count);
}