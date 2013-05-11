#include "m10937.h"

/*** m10937_setup - initializes the SCK and SDA lines for the display
*
*	parameters: none
*	returns: none
*	warnings:
*		the header file #defines need to be verified/modified before
*		using this function. do NOT modify this code, modify the header
*
***/
void m10937_setup(void)
{
	M10937_DDRSDA |= 1<<M10937_DDRSDALINE;
	M10937_DDRSCK |= 1<<M10937_DDRSCKLINE;
	M10937_PORTSDA &= ~(1<<M10937_PINSDA);
	M10937_PORTSCK &= ~(1<<M10937_PINSCK);
}

