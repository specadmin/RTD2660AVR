#ifndef PAGEF_H
#define PAGEF_H

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////   Page F: MCU Registers 3  //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGEF                      0x0F
#define __XFR_F_(addr)              (addr-0xFF20)

//--------------------------------------------------
// GPIO Control
//--------------------------------------------------
#define _PF_PORT_READ_CONTROL_FFC0  __XFR_F_(0xFFC0)


//--------------------------------------------------
// GPIO
//--------------------------------------------------
#define _GPIO52                     __XFR_F_(0xFFC1)
#define _GPIO53                     __XFR_F_(0xFFC2)
#define _GPIO54                     __XFR_F_(0xFFC3)
#define _GPIO55                     __XFR_F_(0xFFC4)
#define _GPIO56                     __XFR_F_(0xFFC5)
#define _GPIO57                     __XFR_F_(0xFFC6)
#define _GPIO_P3                    __XFR_F_(0xFFE3)

#define _PIN96                      _GPIO52
#define _PIN97                      _GPIO53
#define _PIN98                      _GPIO54
#define _PIN99                      _GPIO55
#define _PIN100                     _GPIO56
#define _PIN101                     _GPIO57
#define _PIN102                     _GPIO76
#define _PIN103                     _GPIO75
#define _PIN104                     _GPIO74
#define _PIN105                     _GPIO80
#define _PIN108                     _GPIO81
/* P3 has now pin-control registers
#define _PIN109
#define _PIN110
#define _PIN111
#define _PIN112
#define _PIN113
#define _PIN114
*/
#define _PIN121                     _GPIO73
#define _PIN122                     _GPIO72
#define _PIN123                     _GPIO71

#endif
