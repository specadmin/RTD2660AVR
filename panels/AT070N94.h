#ifndef AT070N94_H
#define AT070N94_H
//-----------------------------------------------------------------------------
#define DISPLAY_WIDTH       800     // pixels
#define DISPLAY_HEIGHT      480     // pixels

// display connection type
#define DISP_TYPE           _TTL

// display clock
#define DCLK_FREQUENCY      40 * MHZ
#define DCLK_INVERTED       FALSE
#define DHS_INVERTED        TRUE
#define DVS_INVERTED        TRUE
#define DEN_INVERTED        FALSE
#define CHANGE_BITS_ORDER   TRUE
#define RED_BLUE_SWAP       TRUE    // swap red pins with blue pins

// horizontal timings (in clock cycles)
#define DISP_H_PULSE_W      64
#define DISP_H_BLANK_W      86
#define DISP_H_PORCH_W      14

// vertical timings (in horizontal cycles)
#define DISP_V_PULSE_W      3
#define DISP_V_BLANK_W      36
#define DISP_V_PORCH_W      9

//-----------------------------------------------------------------------------
#endif
