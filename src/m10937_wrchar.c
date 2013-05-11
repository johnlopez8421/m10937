#include "m10937.h"

/*** m10937_wrchar - writes a char to the display
*
*	parameters:
*		ch: char to write
*	returns: none
*	warnings: none
*
***/
void m10937_wrchar(char ch)
{
	ch &= ~M10937_COMMAND;	// force command bit off
	if(isalpha(ch))
	{
		// m10937 expects upper case ASCII
		ch = toupper(ch);
	}
	m10937_wrbyte(ch);
	
}
