#include "m10937.h"
#include <util/delay.h>

/*** m10937_reset - resets the display (POR line) of the m10937
*
*	parameters: none
*	returns: none
*	warnings: 
*	warnings:
*		the header file #defines need to be verified/modified before
*		using this function. do NOT modify this code, modify the header
*
***/
void m10937_reset(void)
{
	M10937_DDRRST |= (1<<M10937_DDRRSTLINE);	// reset line as output
	M10937_PORTRST &= ~(1<<M10937_PINRST);		// active
	_delay_ms(5);								// hold
	M10937_DDRRST &= ~(1<<M10937_DDRRSTLINE);	// inactive

}