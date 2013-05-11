#include "m10937.h"

/*** m10937_wrstr() - writes a string to the m10937
*	
*	parameters
*		str: null terminated string
*
*	returns: none
*	warnings:
*		the m10937 does not handle adjacent '.' or ',' chars.
*
***/

void m10937_wrstr(char *str)
{
	uint8_t size = 0;
	
	// ignore anything longer than the display, 
	// but check for a final PNT or TAIL after the 16th char
	while(*str && size < 17) 
	{
		// don't count PNT or TAIL chars towards size
		if( (*str != '.') && (*str != ',') ) size++;	
		m10937_wrchar(*str++);		
	}
	
	m10937_setdigctr(size);
}
