#include "m10937.h"

/*** m10937_chartestall - fills display with specified char
*
*	parameters: 
*		ch: char to write
*	returns: none
*	warnings: none
***/
void m10937_chartestall(char ch)
{
	uint8_t j;

	m10937_setbufpos(M10937_CHRPOS01);
	m10937_setdigctr(16);
	m10937_setdutycyc(M10937_DUTYCYCFULL);
	
	for(j=0; j<16; j++)
	{
		m10937_wrchar(ch);
		m10937_wrchar('.');
		m10937_wrchar(',');
	}
}
