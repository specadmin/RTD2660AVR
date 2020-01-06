#ifndef PAGEE_H
#define PAGEE_H

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////   Page E: MCU Registers 2  //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGEE                      0x0E
#define __XFR_E_(addr)              (addr-0xFEC0)

//--------------------------------------------------
// Pin Shares
//--------------------------------------------------
#define _PE_PIN_SHARE_CTRL00_FF96   __XFR_E_(0xFF96)
#define _PE_PIN50_PIN58_PIN59_CONFIG    _PE_PIN_SHARE_CTRL00_FF96
#define _PIN_50_AVOUT               _bits(2)


#define _PE_PIN_SHARE_CTRL01_FF97   __XFR_E_(0xFF97)


#define _PE_PIN_SHARE_CTRL02_FF98   __XFR_E_(0xFF98)


#define _PE_PIN_SHARE_CTRL03_FF99   __XFR_E_(0xFF99)


#define _PE_PIN_SHARE_CTRL04_FF9A   __XFR_E_(0xFF9A)


#define _PE_PIN_SHARE_CTRL05_FF9B   __XFR_E_(0xFF9B)
#define _PE_PIN68_PIN71_CONFIG      _PE_PIN_SHARE_CTRL05_FF9B
#define _PIN_68_INPUT               _0
#define _PIN_68_OUTPUT_OD           _bits(4)
#define _PIN_68_OUTPUT              _bits(5)
#define _PIN_68_SD0                 _bits(4,5)
#define _PIN_68_TCON3               _bits(6)
#define _PIN_68_TCON13              _bits(4,6)
#define _PIN_68_SPDIF               _bits(5,6)
#define _PIN_71_INPUT               _0
#define _PIN_71_OUTPUT_OD           _bits(0)
#define _PIN_71_OUTPUT              _bits(1)
#define _PIN_71_SD3                 _bits(0,1)
#define _PIN_71_TCON8               _bits(2)
#define _PIN_71_TCON10              _bits(0,2)
#define _PIN_71_SPDIF3              _bits(1,2)
#define _PIN_71_PWM1                _bits(0,1,2)
#define _PIN_71_PWM5                _bits(3)


#define _PE_PIN_SHARE_CTRL06_FF9C   __XFR_E_(0xFF9C)
#define _PE_PIN96_PIN97_CONFIG      _PE_PIN_SHARE_CTRL06_FF9C
#define _PIN54_INPUT                _0
#define _PIN54_OUTPUT_OD            _bits(6)
#define _PIN54_OUTPUT               _bits(7)
#define _PIN54_ADCA4                _bits(6,7)
#define _PIN96_INPUT                _0
#define _PIN96_OUTPUT_OD            _bits(3)
#define _PIN96_OUTPUT               _bits(4)
#define _PIN96_PWM0                 _bits(3,4)
#define _PIN96_DCLK                 _bits(5)
#define _PIN97_INPUT                _0
#define _PIN97_OUTPUT_OD            _bits(0)
#define _PIN97_OUTPUT               _bits(1)
#define _PIN97_PWM1                 _bits(0,1)
#define _PIN97_DVS                  _bits(2)


#define _PE_PIN_SHARE_CTRL07_FF9D   __XFR_E_(0xFF9D)
#define _PE_PIN99_CONFIG            _PE_PIN_SHARE_CTRL07_FF9D
#define _PE_PIN78_83_CONFIG         _PE_PIN_SHARE_CTRL07_FF9D
#define _PE_PIN100_CONFIG            _PE_PIN_SHARE_CTRL07_FF9D
#define _PIN99_INPUT                _0
#define _PIN99_OUTPUT_OD            _bits(3)
#define _PIN99_OUTPUT               _bits(4)
#define _PIN99_PWM3                 _bits(4,3)
#define _PIN99_TCON6                _bits(5)
#define _PIN99_TCON11               _bits(5,3)

#define _PE_PIN_SHARE_CTRL08_FF9E   __XFR_E_(0xFF9E)


#define _PE_PIN_SHARE_CTRL09_FF9F   __XFR_E_(0xFF9F)
#define _PE_PIN98_CONFIG            _PE_PIN_SHARE_CTRL09_FF9F
#define _PE_PIN101_CONFIG           _PE_PIN_SHARE_CTRL09_FF9F
#define _PE_PIN108_CONFIG           _PE_PIN_SHARE_CTRL09_FF9F
#define _PIN98_INPUT                _0
#define _PIN98_OUTPUT_OD            _bits(6)
#define _PIN98_OUTPUT               _bits(7)
#define _PIN98_PWM2                 _bits(7,6)


#define _PE_PIN_SHARE_CTRL0A_FFA0   __XFR_E_(0xFFA0)


#define _PE_PIN_SHARE_CTRL0B_FFA1   __XFR_E_(0xFFA1)


#define _PE_PIN_SHARE_CTRL0C_FFA2   __XFR_E_(0xFFA2)


#define _PE_PIN_SHARE_CTRL0D_FFA3   __XFR_E_(0xFFA3)
#define _PE_PIN113_CONFIG           _PE_PIN_SHARE_CTRL0D_FFA3
#define _PIN113_INPUT               _0
#define _PIN113_OUTPUT_OD           _bits(4)
#define _PIN113_OUTPUT              _bits(5)
#define _PIN113_TCON1               _bits(4,5)
#define _PIN113_SD2                 _bits(6)
#define _PIN113_SPDIF2              _bits(4,6)
#define _PIN113_IRDA                _bits(4,5)


#define _PE_PIN_SHARE_CTRL0E_FFA4   __XFR_E_(0xFFA4)


//--------------------------------------------------
// Pin Driving
//--------------------------------------------------
#define _PIN50_PIN97_DRIVING_FFA6   __XFR_E_ (0xFFA6)
#define _PIN74_PIN95_DRIVING_HIGH   _bits(1,2)
#define _PIN96_PIN97_DRIVING_HIGH   _bits(0)

#define _PIN98_PIN124_DRIVING_FFA7  __XFR_E_ (0xFFA7)

//--------------------------------------------------
// Pins Pull Up
//--------------------------------------------------
#define _PIN_PULLUP_CTRL20_FFA8     __XFR_E_ (0xFFA8)
#define _PIN50_PIN54_PULLUP         _bits(7)
#define _PIN55_PIN57_PULLUP         _bits(6)
#define _PIN58_PIN59_PULLUP         _bits(5)
#define _PIN64_PIN67_PULLUP         _bits(4)
#define _PIN68_PIN71_PULLUP         _bits(3)
// reserved                         _bits(2)
// reserved                         _bits(1)
#define _PIN96_PIN97_PULLUP         _bits(0)


#define _PIN_PULLUP_CTRL21_FFA9     __XFR_E_ (0xFFA9)
#define _PIN98_PIN103_PULLUP        _bits(7)
#define _PIN104_PIN105_PULLUP       _bits(6)
#define _PIN108_PIN114_PULLUP       _bits(5)
// reserved                         _bits(4)
#define _PIN121_PIN124_PULLUP       _bits(3)
// reserved                         _bits(2)
#define _XCLK_OEN                   _bits(1)
#define _CKT_PLL27X_OEN             _bits(0)

//-------------------------------------------------------------------------------------------
#endif
