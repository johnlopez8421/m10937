#ifndef _m10937_h
#define _m10937_h
 
#include <ctype.h>
#include <avr/io.h>

/*** TODO verify these settings for your hardware ***/
//#warning "You need to verify the below settings for your hardware then comment this line"
// reset line
#define M10937_PINRST PC3
#define M10937_PORTRST PORTC
#define M10937_DDRRST DDRC
#define M10937_DDRRSTLINE DDC3

// SDA line
#define M10937_PINSDA PC5
#define M10937_PORTSDA PORTC
#define M10937_DDRSDA DDRC
#define M10937_DDRSDALINE DDC5

// SCK line
#define M10937_PINSCK PC4
#define M10937_PORTSCK PORTC
#define M10937_DDRSCK DDRC
#define M10937_DDRSCKLINE DDC4

/*******************************************************/

// command bit
#define M10937_COMMAND 0x80

// buffer pointer control
#define M10937_CTRLPTR	(M10937_COMMAND | 0x20)
#define M10937_MASKPTR	0x0F

// character count control
#define M10937_CTRLCNT	(M10937_COMMAND | 0x40)
#define M10937_MASKCNT	0x0F

// duty cycle control
#define M10937_CTRLDCY	(M10937_COMMAND | 0x60)
#define M10937_MASKDCY	0x1F

// test mode
#define M10937_CTRLTST	(M10937_COMMAND | 0x00)
#define M10937_MASKTST	0x1F

// character mode
#define M10937_MASKCHR  0x3F

/* helper #defines */
// Character positions
#define M10937_CHRPOS01	0x0F
#define M10937_CHRPOS02	0x00
#define M10937_CHRPOS03	0x01
#define M10937_CHRPOS04	0x02
#define M10937_CHRPOS05	0x03
#define M10937_CHRPOS06	0x04
#define M10937_CHRPOS07	0x05
#define M10937_CHRPOS08	0x06
#define M10937_CHRPOS09	0x07
#define M10937_CHRPOS10	0x08
#define M10937_CHRPOS11	0x09
#define M10937_CHRPOS12	0x0A
#define M10937_CHRPOS13	0x0B
#define M10937_CHRPOS14	0x0C
#define M10937_CHRPOS15	0x0D
#define M10937_CHRPOS16	0x0E

//duty cycle
#define M10937_DUTYCYCFULL	0x1F
#define M10937_DUTYCYCHALF	0x0F
#define M10937_DUTYCYCOFF	0x00

// test mode
#define M10937_TESTMSTART	0x00
#define M10937_TESTMEND		0x1F

// installation specific
void m10937_setup(void);	// sets RST, SCK, SDA to initial states

// low level
void m10937_wrbit(uint8_t bit);		// writes a single bit to m10937 using SDA and SCK
void m10937_wrbyte(uint8_t byte);	// writes 8 bits to m10937 using wrbit()

// normal API
void m10937_reset(void);				// initiates m10937 reset
void m10937_setbufpos(uint8_t pos);		// sets buffer position
void m10937_setdigctr(uint8_t count);	// sets digit counter
void m10937_setdutycyc(uint8_t rate);	// sets duty cycle
void m10937_settest(uint8_t testval);	// sets into test mode
void m10937_wrchar(char ch);			// writes a char
void m10937_wrstr(char *str);			// writes a string of >=1 and <= 16 chars
void m10937_chartestall(char ch);		// sets all 16 digits to the specified char with PNT and TAIL set as well
void m10937_fadein(void);				// does a fade in of display
void m10937_fadeout(void);				// does a fade out of display
void m10937_off(void);					// turns the display off
void m10937_on(void);					// turns the display on (full duty cycle)

#endif // _m10937_h