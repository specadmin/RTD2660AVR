#ifndef CONFIG_H
#define CONFIG_H
//----------------------------------------------------------------------------
#include <avr/io.h>
//----------------------------------------------------------------------------

#define LCD_MODEL       TM060RDH01

#define RTD_CS_PORT     PORTD
#define RTD_CS_DDR      DDRD
#define RTD_CS_BIT      6

#define RTD_CLK_PORT    PORTD
#define RTD_CLK_DDR     DDRD
#define RTD_CLK_BIT     7

#define RTD_TX_PORT     PORTD
#define RTD_TX_DDR      DDRD
#define RTD_TX_BIT      5

#define RTD_RX_PIN      PIND
#define RTD_RX_BIT      4

#define DEBUG_PORT      PORTD
#define DEBUG_DDR       DDRD
#define DEBUG_BIT       1
#define DEBUG_BAUD_RATE 1152000
//#define DEBUG_BUF_SIZE  200
//#define DEBUG_EXTENDED_DUMP

#define RAM_GUARD_ENABLED

//----------------------------------------------------------------------------
#endif

