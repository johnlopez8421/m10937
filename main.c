#include <avr/io.h>
#include "src/m10937.h"
#include <util/delay.h>

/*** library/hardware selftest code for M10937 
*
* This code excercises almost all of the functions in the m10937
* library. An exception is m10937_settest - I haven't figured out
* any way to get useful feedback out of test mode. 
*
* Note that many of the functions are implicitly tested by the first
* m10937_wrstr call. Many of the wrstr's are just documenting this.
*
***/

int main(void)
{
	int j;

	m10937_setup();
	m10937_reset();
	m10937_on();
	m10937_wrstr("setup");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("reset");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("wrstr");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("setdigctr");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("wrbitbyte");
	_delay_ms(1000);
	
	m10937_reset();
	m10937_on();
	m10937_wrstr("wrchar");
	_delay_ms(1000);
	
	m10937_reset();
	m10937_on();
	m10937_wrstr("fadeout");
	m10937_fadeout();
	_delay_ms(1000);

	m10937_reset();
	m10937_wrstr("fadein");
	m10937_fadein();
	_delay_ms(1000);

	m10937_reset();
	m10937_setdutycyc(M10937_DUTYCYCFULL);
	m10937_wrstr("setdutycyc");

	m10937_reset();
	m10937_off();
	m10937_wrstr("off");
	_delay_ms(1000);
	m10937_on();
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("on");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("dead segmnt test");
	_delay_ms(1000);
	
	m10937_reset();
	m10937_on();
	m10937_wrstr("look 4 * missing");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("then 4 o missing");
	_delay_ms(1000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("chartestall: *");
	m10937_chartestall('*');
	_delay_ms(3000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("chartestall: o");
	m10937_chartestall('o');
	_delay_ms(3000);

	m10937_reset();
	m10937_on();
	m10937_wrstr("overstrike");
	_delay_ms(1000);
	
	for(j=1; j<11; j++)
	{
		m10937_setbufpos(j);
		m10937_wrchar('*');
		_delay_ms(300);
	}
	
	m10937_reset();
	m10937_on();
	m10937_wrstr("setbufpos");
	_delay_ms(1000);
	

	m10937_reset();
	m10937_on();
	m10937_wrstr("test complete");

	return 0;
}