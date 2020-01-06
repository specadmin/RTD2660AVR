#ifndef PANEL_H
#define PANEL_H
//-----------------------------------------------------------------------------
#define _MSB                0
#define _LSB                1
#define _RGB                0
#define _BGR                1
//-----------------------------------------------------------------------------
// known LCD panels
#define    TM060RDH01       1
//-----------------------------------------------------------------------------
#include "config.h"
//-----------------------------------------------------------------------------
#if(LCD_MODEL == TM060RDH01)
#include "panels/TM060RDH01.h"

// #elif(LCD_MODEL == ABCD)
// #include "panels/ABCD.h"

#else
#error LCD_MODEL is not supported or was not defined. Check config.h file
#endif
//-----------------------------------------------------------------------------
#endif
