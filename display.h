#ifndef DISPLAY_H
#define DISPLAY_H
//-----------------------------------------------------------------------------
#include "OSD.h"
//-----------------------------------------------------------------------------
enum PowerMode
{
    POWER_MODE_FULL,
    POWER_MODE_SAVING,
    POWER_MODE_DOWN,
    POWER_MODE_OFF
};
//-----------------------------------------------------------------------------
enum VideoSource
{
    VS_AV0,
    VS_AV1,
    VS_AV2,
    VS_AV3,
    VS_VGA0,
    VS_VGA1,
    VS_HDMI0,
    VS_HDMI1,
};
//-----------------------------------------------------------------------------
enum ADC_index
{
    _ADC0 = 1,
    _ADC1 = 2
};
//-----------------------------------------------------------------------------
struct DisplayConfig
{
    RGB_color backgroundColor = 0x000080;
    BYTE videoBrightness = 128;
    BYTE videoContrast = 128;
    BYTE videoHue = 0;
    BYTE videoSaturation = 180;
};
//-----------------------------------------------------------------------------
class CDisplay
{
private:
    void chipSoftwareReset();
    void videoSoftwareReset();
    void configurePins();
    void configurePanel();
    void setupColorConversions(const WORD* RGB2YUV_table, const WORD* YUV2RGB_table);
    void setupDithering();
public:
    void init(DisplayConfig& config);
    void setPowerMode(PowerMode mode);
    void on();
    void off();
    void hideVideo();
    void showVideo(VideoSource source);
    void setVideoBrightness(BYTE value);
    void setVideoContrast(BYTE value);
    void setVideoHue(BYTE value);
    void setVideoSaturation(BYTE value);
};
//-----------------------------------------------------------------------------
#endif

extern CDisplay display;
extern COSD OSD;
