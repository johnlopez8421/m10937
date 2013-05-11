#include "m10937.h"
#include <util/delay.h>

/*** m10937_wrbyte - writes a raw byte to the m10937
*
*	parameters:
*		byte: data to write
*	returns: none
*	warnings:
*		this is a low-level function, intended to be used by higher-layer
*		functions. 
*
***/
void m10937_wrbyte(uint8_t byte)
{
	int8_t j;
	uint8_t bit;

	for(j=7; j>=0; j--)
	{
		bit = byte & (1<<j);
		bit >>= j;
		m10937_wrbit(bit);
	}
	_delay_us(40.0);
}


/*** m10937_wrbit - writes a single bit to the m10937
*
*	parameters:
*		bit: bit to write (lowest-order bit is used)
*	returns:
*		none:
*	warnings:
*		the only intended use of this function is as a part of 
*		m10937_wrbyte()
***/
void m10937_wrbit(uint8_t bit)
{
	bit &= 0x01; 
	if(bit)
	{
		M10937_PORTSDA |= 1<<M10937_PINSDA;	// data high
		
		_delay_us(0.5);
		
		M10937_PORTSCK |= 1<<M10937_PINSCK;// clock high
		
		_delay_us(10.0);

		M10937_PORTSCK &= ~(1<<M10937_PINSCK);	// clock low
		
	}
	else
	{
		M10937_PORTSDA &= ~(1<<M10937_PINSDA);	// data low
		
		_delay_us(0.5);	
		
		M10937_PORTSCK |= 1<<M10937_PINSCK;// clock high
		
		_delay_us(10.0);

		M10937_PORTSCK &= ~(1<<M10937_PINSCK);	// clock low
		
	}
}
