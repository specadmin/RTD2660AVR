#ifndef TM060RDH01_H
#define TM060RDH01_H
//-----------------------------------------------------------------------------
#define DISPLAY_WIDTH       800     // pixels
#define DISPLAY_HEIGHT      480     // pixels

// display connection type
#define DISP_TYPE           _TTL

// display clock
#define DCLK_FREQUENCY      50 * MHZ
#define DCLK_INVERTED       FALSE
#define DHS_INVERTED        FALSE
#define DVS_INVERTED        FALSE
#define DEN_INVERTED        FALSE
#define CHANGE_BITS_ORDER   FALSE
#define RED_BLUE_SWAP       FALSE    // swap red pins with blue pins

// horizontal timings (in clock cycles)
#define DISP_H_PULSE_W      48
#define DISP_H_BLANK_W      29  //29 // 88
#define DISP_H_PORCH_W      40

// vertical timings (in horizontal cycles)
#define DISP_V_PULSE_W      3
#define DISP_V_BLANK_W      19 //32
#define DISP_V_PORCH_W      13

//-----------------------------------------------------------------------------
#endif
