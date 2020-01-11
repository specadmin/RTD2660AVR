//-----------------------------------------------------------------------------
#include "panel.h"
#include <avr/pgmspace.h>
#include "avr-misc/avr-misc.h"
#include "avr-debug/debug.h"
#include "scaler.h"
#include "registers.h"
#include "structure.h"
#include "display.h"
#include "PLL.h"
//-----------------------------------------------------------------------------
#define MODE_VIDEO          0
#define MODE_BACKGROUND     1
#define UNKNOWN_MAGIC_WIDTH 640
#define DISP_H_ACTIVE_S     DISP_H_BLANK_W
#define DISP_H_ACTIVE_E     (DISP_H_BLANK_W + DISPLAY_WIDTH + UNKNOWN_MAGIC_WIDTH)
#define DISP_H_TOTAL_W      (DISP_H_BLANK_W + DISPLAY_WIDTH + UNKNOWN_MAGIC_WIDTH + DISP_H_PORCH_W)
#define DISP_V_ACTIVE_S     DISP_V_BLANK_W
#define DISP_V_ACTIVE_E     (DISP_V_BLANK_W + DISPLAY_HEIGHT)
#define DISP_V_TOTAL_W      (DISP_V_BLANK_W + DISPLAY_HEIGHT + DISP_V_PORCH_W)
//-----------------------------------------------------------------------------
CDisplay display;
//-----------------------------------------------------------------------------
const PROGMEM BYTE dither_sequence[] =
{
    /*  dithering sequence table  */
    0xe4, 0xa2, 0x05, 0x37, 0xf6, 0x31, 0x69, 0xcb,
    0x1f, 0xd2, 0xb0, 0xe6, 0x45, 0x1b, 0x87, 0xc6,
    0x9e, 0xb4, 0xc6, 0x38, 0xd4, 0xdb, 0x12, 0x1b
};
//-----------------------------------------------------------------------------
const PROGMEM BYTE dither_10_to_8[] =
{
    /*  24 bit color dithering table  */
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10
};
//-----------------------------------------------------------------------------
const PROGMEM BYTE dither_10_to_6[] =
{
    /*  18 bit color dithering table  */
    0x07, 0xf8, 0x69, 0x1e, 0xad, 0x52, 0xc3, 0xb4,
    0xad, 0x52, 0xc3, 0xb4, 0x07, 0xf8, 0x69, 0x1e,
    0xad, 0x52, 0x69, 0x1e, 0xc3, 0xb4, 0x07, 0xf8
};
//-----------------------------------------------------------------------------
const PROGMEM WORD YUV2RGB_CCIR601[] =
{
    /*  YUV to RGB conversion coefficients
    R = K11 * Y + K13 * V
    G = K11 * Y - K22 * U - K23 * V
    B = K11 * Y + K32 * U               */
    0x0400,     // K11 = 1
    0x059C,     // K13 = 1.403
    0x0160,     // K22 = 0.344
    0x02DB,     // K23 = 0.714
    0x0714      // K32 = 1.770
};
//-----------------------------------------------------------------------------
extern void LCDPowerOn();
extern void LCDPowerOff();
extern void backlightOn();
extern void backlightOff();
extern void setOrientation(BYTE value);
//-----------------------------------------------------------------------------
__inline void ADC_power_on(ADC_index index)
{
    scaler_select_page(_PAGE0);
    scaler_set_bits(_P0_VADC_SWITCH_AF, 1 << index);
    scaler_set_bits(_P0_VADC_SWITCH_AF, _bits(0));
    scaler_write(_P0_ADC_POWER_C6, 0x08);
}
//-----------------------------------------------------------------------------
__inline void ADC_power_off()
{
    scaler_select_page(_PAGE0);
    scaler_clr_bits(_P0_VADC_SWITCH_AF, _bits(0,1));
    scaler_write(_P0_VADC_CLAMP_POWER_AE, 0x00);
}
//-----------------------------------------------------------------------------
void CDisplay::chipSoftwareReset()
{
    scaler_set_bits(_HOST_CTRL_01, _RESET_CHECK);
    scaler_set_bits(_HOST_CTRL_01, _WHOLE_CHIP_RESET);
    mdelay(20);
    scaler_clr_bits(_HOST_CTRL_01, _WHOLE_CHIP_RESET);
}
//-----------------------------------------------------------------------------
void CDisplay::videoSoftwareReset()
{
    scaler_select_page(_PAGE8);
    scaler_set_bits(_P8_SOFT_RESET_CF, _bits(0));
    mdelay(20);
    scaler_clr_bits(_P8_SOFT_RESET_CF, _bits(0));
}
//-----------------------------------------------------------------------------
void CDisplay::configurePins()
{
    scaler_select_page(_PAGEE);
    scaler_write(_PE_PIN96_PIN97_CONFIG, _PIN96_DCLK | _PIN97_DVS);
    scaler_write(_PIN50_PIN97_DRIVING_FFA6, _PIN74_PIN95_DRIVING_HIGH | _PIN96_PIN97_DRIVING_HIGH);
}
//-----------------------------------------------------------------------------
void CDisplay::configurePanel()
{
    DisplayPLL_P1_C7 dispPLL;
    DisplayFormat_2B dispFormat;
    scaler_read_port(_DISP_DATA_PORT_2B, _DISP_FORMAT_00, sizeof(dispFormat), &dispFormat);

    // setup horizontal timings
    dispPLL.hTotal = DISP_H_TOTAL_W;
    dispFormat.totalRows = DISP_H_TOTAL_W - 4;
    dispFormat.hSyncWidth = DISP_H_PULSE_W;
    dispFormat.hBlankStart = DISP_H_ACTIVE_S - 10;
    dispFormat.hActiveStart = DISP_H_ACTIVE_S - 10;
    dispFormat.hActiveEnd = DISP_H_ACTIVE_E - 10;
    dispFormat.hBlankEnd = DISP_H_ACTIVE_E - 10;

    // setup vertical timings
    dispPLL.vTotal = DISP_V_TOTAL_W;
    dispFormat.totalLines = DISP_V_TOTAL_W;
    dispFormat.vSyncWidth = DISP_V_PULSE_W;
    dispFormat.vBlankStart = DISP_V_ACTIVE_S;
    dispFormat.vActiveStart = DISP_V_ACTIVE_S;
    dispFormat.vActiveEnd = DISP_V_ACTIVE_E;
    dispFormat.vBlankEnd = DISP_V_ACTIVE_E;

    // setup display signals
    DisplayControl_29 dispSignals;
    dispFormat.DCLK_inverted = DCLK_INVERTED;
    dispFormat.DCLK_enabled = 1;
    dispSignals.skewData = 0;
    dispSignals.skipFirstDHS = 0;
    dispSignals.swapRedAndBlue = RED_BLUE_SWAP;
    dispSignals.swapDataPins = CHANGE_BITS_ORDER;
    dispSignals.DEN_inverted = DEN_INVERTED;
    dispSignals.DHS_inverted = DHS_INVERTED;
    dispSignals.DVS_inverted = DVS_INVERTED;

    // apply settings
    scaler_write_port(_DISP_DATA_PORT_2B, _DISP_FORMAT_00, sizeof(dispFormat), &dispFormat);
    scaler_write(_VDISP_SIGINV_29, 1, &dispSignals);
    scaler_select_page(_PAGE1);
    scaler_write(_P1_EVEN_FIX_LASTLINE_M_C7, sizeof(dispPLL), &dispPLL);
    scaler_write_port(_TCON_DATA_PORT_8C, _TCON_CTRL0_00, DISP_TYPE);

    set_DCLK_frequency();
}
//-----------------------------------------------------------------------------
void CDisplay::setPowerMode(PowerMode mode)
{
    switch(mode)
    {
    case POWER_MODE_FULL:
        scaler_clr_bits(_HOST_CTRL_01, _POWER_DOWN_MODE_ENABLED | _POWER_SAVING_MODE_ENABLED);
        scaler_select_page(_PAGE1);
        scaler_write(_P1_MULTIPLY_POWER_DOWN_E4, 0x00); // power up M2PLL
        break;
    case POWER_MODE_SAVING:
        // not implemented completely yet
        scaler_change_bits(_HOST_CTRL_01, _bits(_POWER_DOWN_MODE_ENABLED), _bits(_POWER_SAVING_MODE_ENABLED));
        scaler_select_page(_PAGE1);
        scaler_write(_P1_MULTIPLY_POWER_DOWN_E4, 0x01); // power down M2PLL
        break;
    case POWER_MODE_DOWN:
        // not implemented completely yet
        scaler_change_bits(_HOST_CTRL_01, _bits(_POWER_SAVING_MODE_ENABLED), _bits(_POWER_DOWN_MODE_ENABLED));
        scaler_select_page(_PAGE1);
        scaler_write(_P1_MULTIPLY_POWER_DOWN_E4, 0x01); // power down M2PLL
        break;
    case POWER_MODE_OFF:
        // not implemented completely yet
        scaler_set_bits(_HOST_CTRL_01, _POWER_DOWN_MODE_ENABLED | _POWER_SAVING_MODE_ENABLED);
        break;
    }
}
//-----------------------------------------------------------------------------
__inline void CDisplay::setupColorConversions(const WORD *RGB2YUV_table, const WORD *YUV2RGB_table)
{
    BYTE coeff[2];
    if(RGB2YUV_table)
    {
        // RGB -> YUV conversion
        // not implemented yet
    }
    else
    {
        // disable RGB -> YUV conversion
        scaler_write(_YUV2RGB_CTRL_9C, 0x00);
    }

    // YUV -> RGB conversion
    scaler_select_page(_PAGE7);
    scaler_write(_P7_YUV2RGB_CTRL_BF, 0x02);
    for(BYTE i = 0; i < 5; i++)
    {
        WORD tmp = pgm_read_word(YUV2RGB_table + i);
        coeff[0] = (i * 2) << 4;
        coeff[1] = tmp >> 8;
        scaler_write(_P7_YUV2RGB_ACCESS_C0, 2, coeff);
        coeff[0] = (i * 2 + 1) << 4;
        coeff[1] = tmp & 0xFF;
        scaler_write(_P7_YUV2RGB_ACCESS_C0, 2, coeff);
    }
    for(BYTE i = 5; i < 8; i++)
    {
        coeff[0] = (i * 2) << 4;
        coeff[1] = 0x00;
        scaler_write(_P7_YUV2RGB_ACCESS_C0, 2, coeff);
        coeff[0] = (i * 2 + 1) << 4;
        coeff[1] = 0x00;
        scaler_write(_P7_YUV2RGB_ACCESS_C0, 2, coeff);
    }
    scaler_write(_P7_YUV2RGB_ACCESS_C0, 0x0C);
    scaler_write(_P7_YUV2RGB_CTRL_BF, 0x01);
}
//-----------------------------------------------------------------------------
void CDisplay::setVideoBrightness(BYTE value)
{
    BYTE data[3];
    memset(data, value, sizeof(data));
    scaler_set_bits(_COLOR_CTRL_62, _bits(0));
    scaler_write_port(_CB_DATA_PORT_65, 0x80, sizeof(data), data);
}
//-----------------------------------------------------------------------------
void CDisplay::setVideoContrast(BYTE value)
{
    BYTE data[6];
    memset(data + 3, value, 3);
    scaler_set_bits(_COLOR_CTRL_62, _bits(1));
    scaler_read_port(_CB_DATA_PORT_65, 0x00, 3, data);
    scaler_write_port(_CB_DATA_PORT_65, 0x80, sizeof(data), data);   // port data should be written continuously from 0x00
}
//-----------------------------------------------------------------------------
void CDisplay::setVideoHue(BYTE value)
{
    scaler_select_page(_PAGE8);
    scaler_write(_P8_HUE_AB, value);
}
//-----------------------------------------------------------------------------
void CDisplay::setVideoSaturation(BYTE value)
{
    scaler_select_page(_PAGE8);
    scaler_write(_P8_SATURATION1_AA, value);
}
//-----------------------------------------------------------------------------
__inline void CDisplay::setupDithering()
{
    scaler_change_bits(_DITHERING_CTRL_6A, _bits(7), _bits(6));
    scaler_write_pgm(_DITHERING_DATA_ACCESS_69, sizeof(dither_sequence), dither_sequence, false);
    scaler_change_bits(_DITHERING_CTRL_6A, _bits(6), _bits(7));
    scaler_write_pgm(_DITHERING_DATA_ACCESS_69, sizeof(dither_10_to_8), dither_10_to_8, false);
    scaler_write(_DITHERING_CTRL_6A, 0x38);
}
//-----------------------------------------------------------------------------
void CDisplay::init(DisplayConfig& config)
{
    backlightOff();
    scaler_init();
    chipSoftwareReset();
    configurePins();
    configurePanel();
    setOrientation(2);
    setPowerMode(POWER_MODE_FULL);
    OSD.init();

    // video capture config
    scaler_set_bits(_VGIP_CTRL_10, _bits(2,3));     // input format = video decoder input (video 16)
    InputFrameConf videoConfig;
    videoConfig.vCaptureSyncDelay = 19;     // 19
    videoConfig.vActiveStart = 6;           // 8, min 6
    videoConfig.vActiveHeight = 232;        // 232
    videoConfig.hCaptureSyncDelay = 100;    // 110
    videoConfig.hActiveStart = 34;          // 34
    videoConfig.hActiveWidth = 720;         // 696
    videoConfig.videoSource = 1;            // _VIDEO16
    scaler_write(_INPUT_FRAME_CONFIG_14, sizeof(videoConfig), &videoConfig);
    DisplayFrameConf dispVideoFrame;
    dispVideoFrame.width = 720;
    dispVideoFrame.height = 232;
    scaler_write_port(_FIFO_DATA_PORT_31, 0x00, sizeof(dispVideoFrame), &dispVideoFrame);

    // ADC config
    scaler_select_page(_PAGE0);
    ADCInputConfig inputConfig;
    inputConfig.bandWidth = _BW_75_MHZ;
    inputConfig.PGA_gain = _PGA_GAIN_1;
    inputConfig.clampVoltage = 4;                           // * 100 mV
    scaler_write(_P0_VADC0_INPUT_PGA_A7, inputConfig);      // ADC0
    scaler_write(_P0_VADC1_INPUT_PGA_A6, inputConfig);      // ADC1

    // PLL config
    scaler_select_page(_PAGE1);
    scaler_set_bits(_P1_LOOP_FILTER_CAPACITOR_EB, _bits(4));    // enable PLL2X

    // color space config
    setupColorConversions(NULL, YUV2RGB_CCIR601);
    scaler_select_page(_PAGE6);
    scaler_set_bits(_P6_YUV422_TO_YUV444_D4, _bits(5,7));   // enable YUV422 to YUV44 conversion and swap UV
    setupDithering();

    // apply startup picture settings
    setVideoBrightness(config.videoBrightness);
    setVideoContrast(config.videoContrast);
    setVideoHue(config.videoHue);
    setVideoSaturation(config.videoSaturation);

    // set background color
    scaler_set_bits(_OVERLAY_CTRL_6C, _BGND_COLOR_ACCESS_ENABLED);
    scaler_write(_BGND_COLOR_CTRL_6D, 3, config.backgroundColor, false);
    scaler_clr_bits(_OVERLAY_CTRL_6C, _BGND_COLOR_ACCESS_ENABLED);
}
//-----------------------------------------------------------------------------
void CDisplay::on()
{
    LCDPowerOn();
    DisplayControl_28 disp;
    scaler_set_port_bits(_TCON_DATA_PORT_8C, _TCON_LVDS_CTRL0_A0, _PWR_UP_EVEN_PORT | _PWR_UP_ODD_PORT);
    scaler_read(_VDISP_CTRL_28, 1, &disp);
    disp.doublePortOutput = 0;
    disp.clockEnabled = 1;
    disp.outputEnabled = 1;
    if(disp.mode == MODE_BACKGROUND)
    {
        disp.frameSyncMode = 0;
        disp.forceTiming = 1;
    }
    scaler_write(_VDISP_CTRL_28, 1, &disp);
    mdelay(100);
    backlightOn();
}
//-----------------------------------------------------------------------------
void CDisplay::off()
{
    backlightOff();
    // do not change following commands order, see Manual page 31 for details
    scaler_clr_bits(_VDISP_CTRL_28, _OUTPUT_ENABLED);
    scaler_set_bits(_VDISP_CTRL_28, _DISPLAY_INVERSE);
    scaler_clr_bits(_VDISP_CTRL_28, _TCLOCK_ENABLED);
    scaler_clr_port_bits(_TCON_DATA_PORT_8C, _TCON_LVDS_CTRL0_A0, _PWR_UP_EVEN_PORT | _PWR_UP_ODD_PORT);
    LCDPowerOff();
}
//-----------------------------------------------------------------------------
void CDisplay::hideVideo()
{
    DisplayControl_28 disp;
    scaler_read(_VDISP_CTRL_28, 1, &disp);
    disp.mode = MODE_BACKGROUND;
    disp.frameSyncMode = 0;
    disp.forceTiming = 1;
    scaler_write(_VDISP_CTRL_28, 1, &disp);
}
//-----------------------------------------------------------------------------
void CDisplay::showVideo(VideoSource source)
{
    switch(source)
    {
    case VS_AV0:
        scaler_select_page(_PAGE0);
        scaler_write(_P0_VADC_CLAMP_POWER_AE, 0x0F);
        scaler_clr_bits(_P0_VADC_CTRL_A1, _bits(4));        // Vin0 source
        scaler_select_page(_PAGE8);
        scaler_write(_P8_CLAMP_UPDN_EN_A2, 0x40);           // ADC0
        ADC_power_on(_ADC0);
        break;
    case VS_AV1:
        scaler_select_page(_PAGE0);
        scaler_write(_P0_VADC_CLAMP_POWER_AE, 1 << 1);
        scaler_clr_bits(_P0_VADC_CTRL_A1, _bits(5));        // Vin1 source
        scaler_select_page(_PAGE8);
        scaler_write(_P8_CLAMP_UPDN_EN_A2, 0x12);           // ADC1
        ADC_power_on(_ADC0);
        ADC_power_on(_ADC1);
        break;
    case VS_AV2:
        scaler_select_page(_PAGE0);
        scaler_write(_P0_VADC_CLAMP_POWER_AE, 1 << 2);
        scaler_set_bits(_P0_VADC_CTRL_A1, _bits(4));        // Vin2 source
        scaler_select_page(_PAGE8);
        scaler_write(_P8_CLAMP_UPDN_EN_A2, 0x40);           // ADC0
        ADC_power_on(_ADC0);
        break;
    case VS_AV3:
        scaler_select_page(_PAGE0);
        scaler_write(_P0_VADC_CLAMP_POWER_AE, 1 << 3);
        scaler_set_bits(_P0_VADC_CTRL_A1, _bits(5));        // Vin3 source
        scaler_select_page(_PAGE8);
        scaler_write(_P8_CLAMP_UPDN_EN_A2, 0x12);           // ADC1
        ADC_power_on(_ADC0);
        ADC_power_on(_ADC1);
        break;
    case VS_VGA0:
        // not implemented yet
        break;
    case VS_VGA1:
        // not implemented yet
        break;
    case VS_HDMI0:
        // not implemented yet
        break;
    case VS_HDMI1:
        // not implemented yet
        break;
    }

    // enable video capture
    scaler_set_bits(_VGIP_CTRL_10, _bits(0));
    videoSoftwareReset();

    // enter frame sync mode
    DisplayControl_28 disp;
    scaler_read(_VDISP_CTRL_28, 1, &disp);
    disp.mode = MODE_VIDEO;
    disp.frameSyncMode = 1;
    scaler_write(_VDISP_CTRL_28, 1, &disp);
}
//-----------------------------------------------------------------------------
#include "LCD_power.h"
//-----------------------------------------------------------------------------
