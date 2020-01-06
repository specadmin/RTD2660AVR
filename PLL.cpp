//-----------------------------------------------------------------------------
#include "avr-misc/avr-misc.h"
#include "avr-debug/debug.h"
#include "scaler.h"
#include "registers.h"
#include "structure.h"
#include "panel.h"
#include "PLL.h"
//-----------------------------------------------------------------------------
#define REF_FREQUENCY                   RTD_XTAL
//-----------------------------------------------------------------------------
#if (DCLK_FREQUENCY<3*MHZ)
    #error TOO LOW DCLK_FREQUENCY
#elif (DCLK_FREQUENCY<10*MHZ)
    #define DPN 5
    #define DIV _DPLL_DIV_8
#elif (DCLK_FREQUENCY<40*MHZ)
    #define DPN 5
    #define DIV _DPLL_DIV_2
#elif (DCLK_FREQUENCY<100*MHZ)
    #define DPN 6
    #define DIV _DPLL_DIV_2
#else
    #define DPN 12
    #define DIV _DPLL_DIV_1
#endif
//-----------------------------------------------------------------------------
void set_DCLK_frequency()
{
    static DisplayPLL DPLL;
    static DisplayPLLFineTune fTune;
    BYTE Ich = 0;
    WORD DPM = 2 * (1 << DIV) * DCLK_FREQUENCY * DPN / REF_FREQUENCY;
    scaler_select_page(_PAGE1);
    scaler_read(_P1_DPLL_M_BF, sizeof(DPLL), &DPLL);
    DPLL.clockSource = _DPLL_REF_SOURCE_XTAL;
    DPLL.M = DPM - 2;
    DPLL.N = DPN - 2;
    DPLL.filterResistor = _DPLLVR_20K;
    DPLL.divider = DIV;
    DPLL.VCO_enabled = 0;
    DPLL.powerDown = 0;
    if(DPN <= 5)
    {
        DPLL.LPF_mode = 0;
        Ich = DPM * 100 / 511;
    }
    else
    {
        DPLL.LPF_mode = 1;
        Ich = DPM * 100 / 3667;
    }
    DPLL.Ich = (Ich < 16) ? Ich - 1 : 15;     // maximum charge current = 16 uA
    scaler_write(_P1_DPLL_M_BF, sizeof(DPLL), &DPLL);

    // frequency offset correction
    DWORD freq = REF_FREQUENCY * DPM / DPN / 2 / (1 << DIV);
    DWORD offset = (DCLK_FREQUENCY - freq) / (freq >> 15);
    scaler_read(_P1_DCLK_FINE_C4, sizeof(fTune), &fTune);
    fTune.offsetDir = _FREQ_UP;
    fTune.offset = (offset < 0x0FFF) ? offset : 0x0FFF;
    fTune.reload = 1;
    scaler_write(_P1_DCLK_FINE_C4, sizeof(fTune), &fTune);
    scaler_set_bits(_P1_EVEN_FIXED_LAST_LINE_CTRL_CA, _DPLL_OFFSET_ENABLED);
}
//-----------------------------------------------------------------------------
