#ifndef LITTLE_ENDIAN_LSB_H
#define LITTLE_ENDIAN_LSB_H
//-----------------------------------------------------------------------------
#include <string.h>
//-----------------------------------------------------------------------------
/* Data structures for little-endian architectures and compillers that uses
   LSB (0...7) bit-fields order */
//-----------------------------------------------------------------------------
struct DisplayPLL
{
    union
    {
        BYTE CR_BF;
        BYTE DPLL_M;
        BYTE M;
    };
    union
    {
        BYTE CR_C0;
        BYTE DPLL_N;
        struct
        {
            BYTE N: 4;
            BYTE divider: 2;
            BYTE freeze: 1;
            BYTE powerDown: 1;
        };
    };
    union
    {
        BYTE CR_C1;
        BYTE DPLL_CRNT;
        struct
        {
            BYTE Ich: 4;
            BYTE : 2;
            BYTE filterResistor: 2;
        };
    };
    union
    {
        BYTE CR_C2;
        BYTE DPLL_WD;
        struct
        {
            BYTE LPF_mode: 1;
            BYTE enabled: 1;
            BYTE : 1;
            BYTE voltage: 2;
            BYTE set: 1;
            BYTE reset: 1;
            BYTE status: 1;
        };
    };
    union
    {
        BYTE CR_C3;
        BYTE DPLL_OTHER;
        struct
        {
            BYTE disableDividend: 1;
            BYTE VCO_enabled: 1;
            BYTE VCO_phaseMargin: 1;
            BYTE clockSource: 1;
            BYTE SSCG_mode: 1;
            BYTE : 3;
        };
    };
};
//-----------------------------------------------------------------------------
struct DisplayPLLFineTune
{
    union
    {
        struct
        {
            BYTE CR_C4;
            BYTE CR_C5;
        };
        struct
        {
            BYTE : 4;
            BYTE offsetDir: 1;
            BYTE EO: 1;
            BYTE EO_mode_enabled: 1;
            BYTE linearChange: 1;
        };
        struct
        {
        private:
            BYTE offset_MSB: 4;
            BYTE: 4;
            BYTE offset_LSB;
        public:
            void operator =(const WORD value)
            {
                offset_MSB = (value >> 8) & 0x0F;
                offset_LSB = value & 0xFF;
            }
            operator WORD()
            {
                return (offset_MSB << 8) | offset_LSB;
            }
        } offset;
    };
    union
    {
        BYTE CR_C6;
        BYTE DCLK_SPREAD_SPECTRUM;
        struct
        {
            BYTE offsetMultiplier: 2;
            BYTE reload: 1;
            BYTE FMDIV: 1;
            BYTE spreadingRange: 4;
        };
    };
};
//-----------------------------------------------------------------------------
struct DisplayFormat_2B
{
    union  // totalRows
    {
        struct
        {
            BYTE CR_2B_00;
            BYTE CR_2B_01;
        };
        struct
        {
            BYTE DH_TOTAL_H;
            BYTE DH_TOTAL_L;
        };
        struct
        {
            BYTE totalRows_H: 4;
            BYTE: 4;
            BYTE totalRows_L;
            void operator =(const WORD value)
            {
                totalRows_H = (value >> 8) & 0x0F;
                totalRows_L = value & 0xFF;
            }
            operator WORD()
            {
                return (totalRows_H << 8) | totalRows_L;
            }
        } totalRows;
    };
    union  // hSyncWidth
    {
        BYTE CR_2B_02;
        BYTE DH_HS_END;
        BYTE hSyncWidth;
    };
    union  // hBlankStart
    {
        struct
        {
            BYTE CR_2B_03;
            BYTE CR_2B_04;
        };
        struct
        {
            BYTE DH_BKGD_STA_H;
            BYTE DH_BKGD_STA_L;
        };
        struct
        {
            BYTE hBlankStart_H: 4;
            BYTE: 4;
            BYTE hBlankStart_L;
            void operator =(const WORD value)
            {
                hBlankStart_H = (value >> 8) & 0x0F;
                hBlankStart_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hBlankStart_H << 8) | hBlankStart_L;
            }
        } hBlankStart;
    };
    union  // hActiveStart
    {
        struct
        {
            BYTE CR_2B_05;
            BYTE CR_2B_06;
        };
        struct
        {
            BYTE DH_ACT_STA_H;
            BYTE DH_ACT_STA_L;
        };
        struct
        {
            BYTE hActiveStart_H: 4;
            BYTE: 4;
            BYTE hActiveStart_L;
            void operator =(const WORD value)
            {
                hActiveStart_H = (value >> 8) & 0x0F;
                hActiveStart_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hActiveStart_H << 8) | hActiveStart_L;
            }
        } hActiveStart;
    };
    union  // hActiveEnd
    {
        struct
        {
            BYTE CR_2B_07;
            BYTE CR_2B_08;
        };
        struct
        {
            BYTE DH_ACT_END_H;
            BYTE DH_ACT_END_L;
        };
        struct
        {
            BYTE hActiveEnd_H: 4;
            BYTE: 4;
            BYTE hActiveEnd_L;
            void operator =(const WORD value)
            {
                hActiveEnd_H = (value >> 8) & 0x0F;
                hActiveEnd_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hActiveEnd_H << 8) | hActiveEnd_L;
            }
        } hActiveEnd;
    };
    union  // hBlankEnd
    {
        struct
        {
            BYTE CR_2B_09;
            BYTE CR_2B_0A;
        };
        struct
        {
            BYTE DH_BKGD_END_H;
            BYTE DH_BKGD_END_L;
        };
        struct
        {
            BYTE hBlankEnd_H: 4;
            BYTE: 4;
            BYTE hBlankEnd_L;
            void operator =(const WORD value)
            {
                hBlankEnd_H = (value >> 8) & 0x0F;
                hBlankEnd_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hBlankEnd_H << 8) | hBlankEnd_L;
            }
        } hBlankEnd;
    };
    union  // totalLines
    {
        struct
        {
            BYTE CR_2B_0B;
            BYTE CR_2B_0C;
        };
        struct
        {
            BYTE DV_TOTAL_H;
            BYTE DV_TOTAL_L;
        };
        struct
        {
            BYTE totalLines_H: 4;
            BYTE: 4;
            BYTE totalLines_L;
            void operator=(const WORD value)
            {
                totalLines_H = (value >> 8) & 0x0F;
                totalLines_L = value & 0xFF;
            }
            operator WORD()
            {
                return (totalLines_H << 8) | totalLines_L;
            }
        } totalLines;
    };
    union  // vSyncWidth
    {
        BYTE CR_2B_0D;
        BYTE DVS_END;
        struct
        {
            BYTE vSyncWidth: 5;
            BYTE: 3;
        };
    };
    union  // vBlankStart
    {
        struct
        {
            BYTE CR_2B_0E;
            BYTE CR_2B_0F;
        };
        struct
        {
            BYTE DV_BKGD_STA_H;
            BYTE DV_BKGD_STA_L;
        };
        struct
        {
            BYTE vBlankStart_H: 4;
            BYTE: 4;
            BYTE vBlankStart_L;
            void operator =(const WORD value)
            {
                vBlankStart_H = (value >> 8) & 0x0F;
                vBlankStart_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vBlankStart_H << 8) | vBlankStart_L;
            }
        } vBlankStart;
    };
    union  // vActiveStart
    {
        struct
        {
            BYTE CR_2B_10;
            BYTE CR_2B_11;
        };
        struct
        {
            BYTE DV_ACT_STA_H;
            BYTE DV_ACT_STA_L;
        };
        struct
        {
            BYTE vActiveStart_H: 4;
            BYTE: 4;
            BYTE vActiveStart_L;
            void operator =(const WORD value)
            {
                vActiveStart_H = (value >> 8) & 0x0F;
                vActiveStart_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vActiveStart_H << 8) | vActiveStart_L;
            }
        } vActiveStart;
    };
    union  // vActiveEnd
    {
        struct
        {
            BYTE CR_2B_12;
            BYTE CR_2B_13;
        };
        struct
        {
            BYTE DV_ACT_END_H;
            BYTE DV_ACT_END_L;
        };
        struct
        {
            BYTE vActiveEnd_H: 4;
            BYTE: 4;
            BYTE vActiveEnd_L;
            void operator =(const WORD value)
            {
                vActiveEnd_H = (value >> 8) & 0x0F;
                vActiveEnd_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vActiveEnd_H << 8) | vActiveEnd_L;
            }
        } vActiveEnd;
    };
    union  // vBlankEnd
    {
        struct
        {
            BYTE CR_2B_14;
            BYTE CR_2B_15;
        };
        struct
        {
            BYTE DV_BKGD_END_H;
            BYTE DV_BKGD_END_L;
        };
        struct
        {
            BYTE vBlankEnd_H: 4;
            BYTE: 4;
            BYTE vBlankEnd_L;
            void operator =(const WORD value)
            {
                vBlankEnd_H = (value >> 8) & 0x0F;
                vBlankEnd_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vBlankEnd_H << 8) | vBlankEnd_L;
            }
        } vBlankEnd;
    };
    BYTE reserved[10];  // CR_2B_16 ... CR_2B_1F
    union  // DIS_TIMING
    {
        BYTE CR_2B_20;
        struct
        {
            BYTE DCLK_inverted: 1;
            BYTE DCLK_enabled: 1;
            BYTE: 2;
            BYTE dataClockDelay: 3;
            BYTE: 1;
        };
    };
    union  // OSD_REFERENCE__DEN
    {
        BYTE CR_2B_21;
        BYTE OSDReference;
    };
    union  // NEW_DV_CTRL
    {
        struct
        {
            BYTE CR_2B_22;
            BYTE CR_2B_23;
        };
        struct
        {
            BYTE: 4;
            BYTE: 1;
            BYTE pixelCompensation: 1;
            BYTE lineCompensation: 1;
            BYTE newTimingEnabled: 1;
            BYTE NEW_DV_DLY;
        };
        struct
        {
            BYTE DCLK_dealy_H: 4;
            BYTE: 4;
            BYTE DCLK_dealy_L;
            void operator =(const WORD value)
            {
                DCLK_dealy_H = (value >> 8) & 0x0F;
                DCLK_dealy_L = value & 0xFF;
            }
            operator WORD()
            {
                return (DCLK_dealy_H << 8) | DCLK_dealy_L;
            }
        } DCLK_delay;
    };
};
//-----------------------------------------------------------------------------
struct DisplayPLL_P1_C7
{
    union
    {
        struct
        {
            BYTE CR_P1_C7;
            BYTE CR_P1_C8;
            BYTE CR_P1_C9;
        };
        struct
        {
            BYTE DV_TOTAL_MSB: 4;
            BYTE DH_TOTAL_MSB: 4;
            BYTE DV_TOTAL_LSB;
            BYTE DH_TOTAL_LSB;
        };
        struct
        {
        private:
            BYTE DV_TOTAL_H: 4;
            BYTE: 4;
            BYTE DV_TOTAL_L;
        public:
            void operator =(const WORD value)
            {
                DV_TOTAL_H = (value >> 8) & 0x0F;
                DV_TOTAL_L = value & 0xFF;
            }
            operator WORD()
            {
                return (DV_TOTAL_H << 8) | DV_TOTAL_H;
            }
        } vTotal;
        struct
        {
        private:
            BYTE: 4;
            BYTE DH_TOTAL_H: 4;
            BYTE reserved;
            BYTE DH_TOTAL_L;
        public:
            void operator =(const WORD value)
            {
                DH_TOTAL_H = (value >> 8) & 0x0F;
                DH_TOTAL_L = value & 0xFF;
            }
            operator WORD()
            {
                return (DH_TOTAL_L << 8) | DH_TOTAL_H;
            }
        } hTotal;
    };
};
//-----------------------------------------------------------------------------
struct DisplayControl_28
{
    union
    {
        BYTE value;
        struct
        {
            BYTE clockEnabled: 1;
            BYTE outputEnabled: 1;
            BYTE doublePortOutput: 1;
            BYTE frameSyncMode: 1;
            BYTE RGB_18: 1;
            BYTE mode: 1;
            BYTE inverseData: 1;
            BYTE forceTiming: 1;
        };
    };
};
//-----------------------------------------------------------------------------
struct DisplayControl_29
{
    union
    {
        BYTE value;
        struct
        {
            BYTE DEN_inverted: 1;
            BYTE DHS_inverted: 1;
            BYTE DVS_inverted: 1;
            BYTE skewData: 1;
            BYTE swapDataPins: 1;
            BYTE swapRedAndBlue: 1;
            BYTE skipFirstDHS: 1;
        };
    };
};
//-----------------------------------------------------------------------------
struct OSD_address
{
    union
    {
        BYTE byte_H;
        struct
        {
            BYTE addr_H: 5;
            BYTE doubleBuffer: 1;
            BYTE mode: 2;
        };
    };
    union
    {
        BYTE byte_L;
        BYTE addr_L;
    };
    OSD_address() {}
    OSD_address(const WORD value)
    {
        addr_H = (value >> 8) & 0x1F;
        addr_L = value & 0xFF;
    }
    operator WORD()
    {
        return (addr_H << 8) | addr_L;
    }
};
//-----------------------------------------------------------------------------
struct OSD_window_data
{
    // byte 0-0
    union
    {
        struct
        {
            BYTE shadow_height: 3;
            BYTE shadow_width: 3;
            BYTE: 2;
        };
        struct
        {
            BYTE border_height: 3;
            BYTE border_width: 3;
            BYTE: 2;
        };
    };
    // byte 0-1
    union
    {
        struct
        {
            BYTE border_color: 4;
            BYTE shadow_color: 4;
        };
        struct
        {
            BYTE btnColor2: 4;
            BYTE btnColor1: 4;
        };
    };
    // byte 0-2
    union
    {
        BYTE gradient;
        struct
        {
            BYTE: 3;
            BYTE gradientStep_L: 2;
            BYTE: 3;
        };
    };
    // byte 1-0...2
    // start position
    union
    {
        struct
        {
        private:
            // byte 1-0
            BYTE: 2;
            BYTE X1_L: 6;
            // byte 1-1
            BYTE X1_H: 5;
            BYTE: 3;
            // byte 1-2
            BYTE: 8;
        public:
            void operator =(const WORD value)
            {
                X1_H = (value >> 6) & 0x1F;
                X1_L = value & 0x3F;
            }
            operator WORD()
            {
                return (X1_H << 6) | X1_L;
            }
        } X1;
        struct
        {
        private:
            // byte 1-0
            BYTE: 8;
            // byte 1-1
            BYTE: 5;
            BYTE Y1_L: 3;
            // byte 1-2
            BYTE Y1_H;
        public:
            void operator =(const WORD value)
            {
                Y1_H = (value >> 3);
                Y1_L = value & 0x07;
            }
            operator WORD()
            {
                return (Y1_H << 3) | Y1_L;
            }
        } Y1;
    };
    // byte 2-0...2
    // end position
    union
    {
        struct
        {
        private:
            // byte 2-0
            BYTE: 2;
            BYTE X2_L: 6;
            // byte 2-1
            BYTE X2_H: 5;
            BYTE: 3;
            // byte 2-2
            BYTE: 8;
        public:
            void operator =(const WORD value)
            {
                X2_H = (value >> 6) & 0x1F;
                X2_L = value & 0x3F;
            }
            operator WORD()
            {
                return (X2_H << 6) | X2_L;
            }
        } X2;
        struct
        {
        private:
            // byte 2-0
            BYTE: 8;
            // byte 2-1
            BYTE: 5;
            BYTE Y2_L: 3;
            // byte 2-2
            BYTE Y2_H;
        public:
            void operator =(const WORD value)
            {
                Y2_H = (value >> 3);
                Y2_L = value & 0x07;
            }
            operator WORD()
            {
                return (Y2_H << 3) | Y2_L;
            }
        } Y2;
    };
    // byte 3-0
    BYTE: 8;
    // byte 3-1
    BYTE bodyColor: 4;
    BYTE gradientStep_H: 3;
    BYTE: 1;
    // byte 3-2
    union
    {
        struct
        {
            BYTE enabled: 1;
            BYTE style: 4;
            BYTE gradientDirection: 1;
            BYTE gradientEnabled: 1;
            BYTE: 1;
        };
        struct
        {
            BYTE: 4;
            BYTE showBorder: 1;
            BYTE: 3;
        };
    };
    operator BYTE*()
    {
        return (BYTE*)this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_control0
{
    union
    {
        // X origin
        struct
        {
        private:
            // byte 0
            BYTE: 8;
            // byte 1
            BYTE X_delay_H;
            // byte 2
            BYTE: 3;
            BYTE: 3;
            BYTE X_delay_L: 2;
        public:
            void operator =(WORD value)
            {
                X_delay_L = value & 0x03;
                X_delay_H = (value >> 2) & 0xFF;
            }
        } X_delay;

        // Y origin
        struct
        {
        private:
            // byte 0
            BYTE Y_delay_H;
            // byte 1
            BYTE: 8;
            // byte 2
            BYTE: 3;
            BYTE Y_delay_L: 3;
            BYTE: 2;
        public:
            void operator =(WORD value)
            {
                Y_delay_L = value & 0x07;
                Y_delay_H = (value >> 3) & 0xFF;
            }
        } Y_delay;

        // control
        struct
        {
            BYTE: 8;
            BYTE: 8;
            BYTE enabled: 1;
            BYTE chAlignment: 2;
            BYTE: 5;
        };
    };
    operator BYTE*()
    {
        return (BYTE*) this;
    }
    BYTE* operator[] (int index)
    {
        return (BYTE*) this + index;
    }
};
//-----------------------------------------------------------------------------
struct OSD_control3
{
    // byte 0
    BYTE blendColor: 4;
    BYTE syncSource: 1;
    BYTE win7Func: 2;
    BYTE colorBlending: 1;
    // byte 1
    union
    {
        struct
        {
            BYTE wholeDoubleHeight: 1;
            BYTE wholeDoubleWidth: 1;
            BYTE alphaBlending: 2;
            BYTE borderColor: 4;
        };
        struct
        {
            BYTE: 4;
            BYTE shadowColor: 4;
        };
    };
    // byte 2
    BYTE rotation: 1;
    BYTE blinkingAllowed: 1;
    BYTE hwRotationEnabled: 1;
    BYTE bufReset: 1;
    BYTE bufBusy: 1;
    BYTE bufEmpty: 1;
    BYTE fontSwap: 2;
    operator BYTE*()
    {
        return (BYTE*) this;
    }
    BYTE* operator[] (int index)
    {
        return (BYTE*) this + index;
    }
};
//-----------------------------------------------------------------------------
struct OSD_Control4
{
    union
    {
        struct
        {
        private:
            BYTE chStart_L;
            BYTE: 4;
            BYTE chStart_H: 4;
            BYTE: 8;
        public:
            void operator =(WORD value)
            {
                chStart_H = (value >> 8);
                chStart_L = (value & 0xFF);
            }
            operator WORD()
            {
                return (chStart_H << 8) | chStart_L;
            }
        } charactersStart;
        struct
        {
        private:
            BYTE: 8;
            BYTE fontStart_L: 4;
            BYTE: 4;
            BYTE fontStart_H;
        public:
            void operator =(WORD value)
            {
                fontStart_H = (value >> 4);
                fontStart_L = (value & 0x0F);
            }
            operator WORD()
            {
                return (fontStart_H << 4) | fontStart_L;
            }
        } fontStart;
    };
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_control8
{
    // byte 0
    BYTE activeMap: 1;
    BYTE: 4;
    BYTE vCropEnabled: 1;
    BYTE specFunctionSelect: 1;
    BYTE specFunctionEnabled: 1;
    // byte 1
    BYTE rows1ConfigBase;
    // byte 2
    BYTE rows2ConfigBase;
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_control9
{
    union
    {
        struct
        {
        private:
            // byte 0
            BYTE: 4;
            BYTE chStart1_H: 4;
            // byte 1
            BYTE chStart1_L;
            // byte 2
            BYTE: 8;
        public:
            void operator =(WORD value)
            {
                chStart1_H = (value >> 8);
                chStart1_L = value & 0xFF;
            }
            operator WORD()
            {
                return (chStart1_H << 8) | chStart1_L;
            }
        } chStart1;
        struct
        {
        private:
            // byte 0
            BYTE chStart2_H: 4;
            BYTE: 4;
            // byte 1
            BYTE: 8;
            // byte 2
            BYTE chStart2_L;
        public:
            void operator =(WORD value)
            {
                chStart2_H = (value >> 8);
                chStart2_L = value & 0xFF;
            }
            operator WORD()
            {
                return (chStart2_H << 8) | chStart2_L;
            }
        } chStart2;
    };
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_controlA
{
    union
    {
        struct
        {
        private:
            // byte 0
            BYTE: 1;
            BYTE cropTop_H: 3;
            BYTE: 4;
            // byte 1
            BYTE cropTop_L;
            // byte 2
            BYTE: 8;
        public:
            void operator =(WORD value)
            {
                cropTop_H = (value >> 8);
                cropTop_L = value & 0xFF;
            }
        } cropTop;
        struct
        {
        private:
            // byte 0
            BYTE: 4;
            BYTE cropBottom_H: 4;
            // byte 1
            BYTE: 8;
            // byte 2
            BYTE cropBottom_L;
        public:
            void operator =(WORD value)
            {
                cropBottom_H = (value >> 8);
                cropBottom_L = value & 0xFF;
            }
        } cropBottom;
    };
};
//-----------------------------------------------------------------------------
struct OSD_row
{
    // byte 0
    union
    {
        BYTE byte0;
        struct
        {
            BYTE double_height: 1;
            BYTE double_width: 1;
            BYTE style: 3;
            BYTE: 1;
            BYTE VBI_enabled: 1;
            BYTE configured: 1;
        };
    };
    // byte 1
    BYTE tracking: 3;
    BYTE height: 5;
    // byte 2
    BYTE len;
    OSD_row()
    {
        memset(this, 0, sizeof(OSD_row));
    }
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_blank
{
    // byte 0
    BYTE: 6;
    BYTE blink: 1;
    BYTE notBlank: 1;
    // byte 1
    BYTE width;
    // byte 2
    BYTE color: 4;
    OSD_blank()
    {
        memset(this, 0, sizeof(OSD_blank));
    }
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};

//-----------------------------------------------------------------------------
#define FONT_TYPE_1BIT      0
#define FONT_TYPE_2BIT      2
#define FONT_TYPE_4BIT      1
#define COLOR_MODE_LUT      0
#define COLOR_MODE_RGB      1
//-----------------------------------------------------------------------------
struct OSD_char_1bit
{
    // byte 0
    union
    {
        // if VBI OSD disabled
        struct
        {
            BYTE width: 4;
            BYTE fontType: 2;
            BYTE blink: 1;
            BYTE notBlank: 1;
        };
        // if VBI OSD enabled
        struct
        {
            BYTE: 1;
            BYTE underlined: 1;
            BYTE fgBlink: 1;
            BYTE code8: 1;
            BYTE: 2;
            BYTE bgBlink: 1;
            BYTE: 1;
        };
    };
    // byte 1
    BYTE code;
    // byte 2
    BYTE bgColor: 4;
    BYTE color: 4;
    OSD_char_1bit()
    {
        notBlank = 1;
        code8 = 0;
        fontType = FONT_TYPE_1BIT;
    }
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct OSD_char_2bit
{
    // TODO: not implemented yet
};
//-----------------------------------------------------------------------------
struct OSD_char_4bit
{
    // byte 0
    union
    {
        struct
        {
            BYTE bgColor: 4;
            BYTE fontType: 2;
            BYTE blink: 1;
            BYTE notBlank: 1;
        };
        struct
        {
        private:
            BYTE red_H: 4;
            BYTE: 4;
            // red_L: 4 = 0xF always
        public:
            void operator =(BYTE value)
            {
                red_H = (value + 7) >> 4;    // round to 5-th bit
            }
        } red;
    };
    // byte 1
    BYTE code: 7;
    BYTE colorMode: 1;  // for 4BIT only
    // byte 2
    union
    {
        struct
        {
            BYTE color1: 4;
            BYTE color2: 4;
        };
        struct
        {
        private:
            BYTE blue_H: 4;
            BYTE: 4;
            // blue_L: 4 = 0xF always
        public:
            void operator =(BYTE value)
            {
                blue_H = (value + 7) >> 4;    // round to 5-th bit
            }
        } blue;
        struct
        {
        private:
            BYTE: 4;
            BYTE green_H: 4;
            // green_L: 4 = 0xF always
        public:
            void operator =(BYTE value)
            {
                green_H = (value + 7) >> 4;    // round to 5-th bit
            }
        } green;
    };
    OSD_char_4bit()
    {
        notBlank = 1;
        fontType = FONT_TYPE_4BIT;
    }
    operator BYTE*()
    {
        return (BYTE*) this;
    }
};
//-----------------------------------------------------------------------------
struct M2PLL_CTRL
{
    union
    {
        BYTE CR_E0;
        struct
        {
            BYTE WD_status: 1;
            BYTE N: 1;
            BYTE disabled: 1;
            BYTE M: 5;
        };
    };
    union
    {
        BYTE CR_E1;
        struct
        {
            BYTE WD_set: 1;
            BYTE WD_reset: 1;
            BYTE WD_voltage: 2;
            BYTE ch_current: 2;
            BYTE filterResistor: 2;
        };
    };
};
//-----------------------------------------------------------------------------
struct InputFrameConf
{
    union
    {
        struct
        {
            BYTE CR_14;
            BYTE CR_15;
        };
        struct
        {
        private:
            BYTE hActiveStart_H: 3;
            BYTE: 5;
            BYTE hActiveStart_L;
        public:
            void operator =(const WORD value)
            {
                hActiveStart_H = (value >> 8) & 0x07;
                hActiveStart_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hActiveStart_H << 8) | hActiveStart_L;
            }
        } hActiveStart;
    };
    union
    {
        struct
        {
            BYTE CR_16;
            BYTE CR_17;
        };
        union
        {
            struct
            {
                BYTE : 3;
                BYTE video8sw: 1;
                BYTE swap_R_G: 1;
                BYTE swap_R_B: 1;
                BYTE swap_G_B: 1;
                BYTE portCBitsOrder: 1;
                BYTE : 8;
            };
            struct
            {
            private:
                BYTE hActiveWidth_H: 3;
                BYTE: 5;
                BYTE hActiveWidth_L;
            public:
                void operator =(const WORD value)
                {
                    hActiveWidth_H = (value >> 8) & 0x07;
                    hActiveWidth_L = value & 0xFF;
                }
                operator WORD()
                {
                    return (hActiveWidth_H << 8) | hActiveWidth_L;
                }
            } hActiveWidth;
        };
    };
    union
    {
        struct
        {
            BYTE CR_18;
            BYTE CR_19;
        };
        union
        {
            struct
            {
                BYTE : 3;
                BYTE portYBitsOrder: 1;
                BYTE videoSource: 1;
                BYTE swap_Y_C: 1;
                BYTE video8_source: 2;
                BYTE : 8;
            };
            struct
            {
            private:
                BYTE vActiveStart_H: 3;
                BYTE: 5;
                BYTE vActiveStart_L;
            public:
                void operator =(const WORD value)
                {
                    vActiveStart_H = (value >> 8) & 0x07;
                    vActiveStart_L = value & 0xFF;
                }
                operator WORD()
                {
                    return (vActiveStart_H << 8) | vActiveStart_L;
                }
            } vActiveStart;
        };
    };
    union
    {
        struct
        {
            BYTE CR_1A;
            BYTE CR_1B;
        };
        struct
        {
        private:
            BYTE vActiveHeight_H: 3;
            BYTE: 5;
            BYTE vActiveHeight_L;
        public:
            void operator =(const WORD value)
            {
                vActiveHeight_H = (value >> 8) & 0x07;
                vActiveHeight_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vActiveHeight_H << 8) | vActiveHeight_L;
            }
        } vActiveHeight;
    };
    union
    {
        struct
        {
            BYTE CR_1C;
            BYTE CR_1D;
            BYTE CR_1E;
        };
        struct
        {
        private:
            BYTE vCaptureSyncDelay_L;
            BYTE : 8;
            BYTE : 1;
            BYTE vCaptureSyncDelay_H: 1;
            BYTE : 6;
        public:
            void operator =(const WORD value)
            {
                vCaptureSyncDelay_H = (value >> 8) & 0x01;
                vCaptureSyncDelay_L = value & 0xFF;
            }
            operator WORD()
            {
                return (vCaptureSyncDelay_H << 8) | vCaptureSyncDelay_L;
            }
        } vCaptureSyncDelay;
        struct
        {
        private:
            BYTE : 8;
            BYTE hCaptureSyncDelay_L;
            BYTE hCaptureSyncDelay_H: 1;
            BYTE : 7;
        public:
            void operator =(const WORD value)
            {
                hCaptureSyncDelay_H = (value >> 8) & 0x01;
                hCaptureSyncDelay_L = value & 0xFF;
            }
            operator WORD()
            {
                return (hCaptureSyncDelay_H << 8) | hCaptureSyncDelay_L;
            }
        } hCaptureSyncDelay;
        struct
        {
            BYTE : 2;
            BYTE VBI_clockSource: 2;
            BYTE vAutoSyncDelay: 2;
            BYTE hAutoSyncDelay: 2;
        };
    };
    union
    {
        struct
        {
            BYTE CR_1F;
            BYTE CR_20;
        };
        union
        {
            struct
            {
                BYTE : 3;
                BYTE I2D_source: 1;
                BYTE syncSource: 1;
                BYTE : 3;
                BYTE : 8;
            };
            struct
            {
            private:
                BYTE hPorch_H: 3;
                BYTE: 5;
                BYTE hPorch_L;
            public:
                void operator =(const WORD value)
                {
                    hPorch_H = (value >> 8) & 0x07;
                    hPorch_L = value & 0xFF;
                }
                operator WORD()
                {
                    return (hPorch_H << 8) | hPorch_L;
                }
            } hPorch;
        };
    };
    InputFrameConf()
    {
        memset(this, 0, sizeof(InputFrameConf));
    }
};
//-----------------------------------------------------------------------------
union DisplayFrameConf
{
    struct
    {
        BYTE CR_31_00;
        BYTE CR_31_01;
        BYTE CR_31_02;
    };
    struct
    {
    private:
        BYTE : 4;
        BYTE width_H: 3;
        BYTE : 1;
        BYTE width_L;
        BYTE : 8;
    public:
        void operator =(const WORD value)
        {
            width_H = (value >> 8) & 0x07;
            width_L = value & 0xFF;
        }
        operator WORD()
        {
            return (width_H << 8) | width_L;
        }
    } width;
    struct
    {
    private:
        BYTE height_H: 3;
        BYTE : 5;
        BYTE : 8;
        BYTE height_L;

    public:
        void operator =(const WORD value)
        {
            height_H = (value >> 8) & 0x07;
            height_L = value & 0xFF;
        }
        operator WORD()
        {
            return (height_H << 8) | height_L;
        }
    } height;
    DisplayFrameConf()
    {
        memset(this, 0, sizeof(DisplayFrameConf));
    }
};
//-----------------------------------------------------------------------------
struct ADCInputConfig
{
    BYTE clampVoltage: 3;
    BYTE PGA_gain: 3;
    BYTE bandWidth: 2;
    operator BYTE()
    {
        return *(BYTE*)this;
    }
    ADCInputConfig()
    {
        memset(this, 0, sizeof(ADCInputConfig));
    }
};

#define _BW_10_MHZ                                      0
#define _BW_25_MHZ                                      1
#define _BW_75_MHZ                                      2
#define _BW_200_MHZ                                     3

#define _PGA_GAIN_1                                     0
#define _PGA_GAIN_1D3                                   1
#define _PGA_GAIN_1D76                                  2
#define _PGA_GAIN_2                                     3
#define _PGA_GAIN_2D3                                   4
#define _PGA_GAIN_2D7                                   5
#define _PGA_GAIN_3D27                                  6
#define _PGA_GAIN_4D16                                  7
//-----------------------------------------------------------------------------
struct ScaleFactor
{
private:
    BYTE SF_H;
    BYTE SF_M;
    BYTE SF_L;
public:
    void operator =(const DWORD value)
    {
        SF_H = (value >> 16) & 0xFF;
        SF_M = (value >> 8) & 0xFF;
        SF_L = value & 0xFF;
    }
    operator DWORD()
    {
        return ((DWORD)SF_H << 16) | (SF_M << 8) | SF_L;
    }
    operator const void*()
    {
        return this;
    }
};
//-----------------------------------------------------------------------------
#endif
