#include "m10937.h"

/*** m10937_settest - sets test mode and writes a test value
*
*	parameters: 
*		testval: value to write
*	returns: none
*	warnings: 
*		not really sure what test mode does
*
***/
void m10937_settest(uint8_t testval)
{
	testval &= M10937_MASKTST;
	testval |= M10937_CTRLTST;
	m10937_wrbyte(testval);
}
