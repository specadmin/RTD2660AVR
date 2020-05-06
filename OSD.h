#ifndef OSD_H
#define OSD_H
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include "panel.h"
#include "config.h"
#include "avr-misc/avr-misc.h"
#include "structure.h"
#include "colors.h"
//-----------------------------------------------------------------------------
#define _OSD_CONTROL0_000               0x0000
// reserved                             0x0001
// reserved                             0x0002
#define _OSD_CONTROL3_003               0x0003
#define _OSD_BASE_ADDRESS_OFFSET_004    0x0004
#define _OSD_COMPRESSION0_005           0x0005
#define _OSD_COMPRESSION1_006           0x0006
#define _OSD_COMPRESSION2_007           0x0007
#define _OSD_SPECIAL_FUNCTION_008       0x0008
#define _OSD_BASE_ADDRESS_SELECT_009    0x0009
#define _OSD_VERT_BOUNDARY_00A          0x000A
#define _OSD_WINDOWS_BASE_ADDR_100      0x0100
#define _OSD_FONT_BASE_ADDR_1000        0x1000
#define _OSD_FONT_END                   0x1EFF
//-----------------------------------------------------------------------------
#define _OSD_BYTE_0                     0
#define _OSD_BYTE_1                     1
#define _OSD_BYTE_2                     2
#define _OSD_BYTE_ALL                   3
//-----------------------------------------------------------------------------
#define _OSD_ROLL_UP                    0
#define _OSD_POP_ON                     1
//-----------------------------------------------------------------------------
#define _GLIPH_ALIGNMENT_CENTER         0
#define _GLIPH_ALIGNMENT_LEFT           1
#define _GLIPH_ALIGNMENT_RIGHT          2
//-----------------------------------------------------------------------------

#define GRAD_NONE                       0
#define GRAD_BLUE_LESS                  0x01    // B-
#define GRAD_GREEN_LESS                 0x02    // G-
#define GRAD_RED_KEEP                   0x03    // B- G-
#define GRAD_RED_LESS                   0x04    // R-
#define GRAD_GREEN_KEEP                 0x05    // B- R-
#define GRAD_BLUE_KEEP                  0x06    // G- R-
#define GRAD_BLACK_MORE                 0x07    // B- G- R-

#define GRAD_BLUE_MORE                  0x21    // B+
#define GRAD_GREEN_MORE                 0x42    // G+
#define GRAD_RED_MORE                   0x84    // R+

#define GRAD_CYAN_MORE                  0x63    // B+ G+
#define GRAD_MAGENTA_MORE               0xA5    // B+ R+
#define GRAD_YELLOW_MORE                0xC6

#define GRAD_WHITE_MORE                 0xE7    // B+ G+ R+

#define GRAD_HORIZONTAL                 0x000
#define GRAD_VERTICAL                   0x100

//-----------------------------------------------------------------------------
#define OSD_FONT_CHAR_WIDTH         12
#define OSD_FONT_CHAR_HEIGHT        18
#define OSD_FONT_MIN_BLANK_WIDTH    4
#define OSD_FONT_MAX_BLANK_WIDTH    255
#define OSD_FONT_MIN_CHAR_WIDTH     4
#define OSD_FONT_MAX_CHAR_WIDTH     14

#define OSD_MAX_ROWS_COUNT          24
//-----------------------------------------------------------------------------
// row styles
#define RS_DOUBLE_HEIGHT    _bits(0)
#define RS_DOUBLE_WIDTH     _bits(1)
#define RS_DOUBLE_SIZE      _bits(0,1)
#define RS_BOLD             _bits(2)
#define RS_SHADOW_LT        _bits(4)
#define RS_SHADOW_LB        _bits(4,2)
#define RS_SHADOW_RT        _bits(4,3)
#define RS_SHADOW_RB        _bits(4,3,2)
#define RS_VBI              _bits(6)

// row chars shadows
#define CHAR_SHADOW_NONE    0
#define CHAR_SHADOW_LT      4
#define CHAR_SHADOW_LB      5
#define CHAR_SHADOW_RT      6
#define CHAR_SHADOW_RB      7

// area blinking modes
#define BLINK_NONE          _0
#define BLINK_TEXT          _bits(0)
#define BLINK_BACKGROUND    _bits(1)
#define BLINK_ALL           _bits(0,1)

// area text alignment
#define ALIGN_LEFT          0          // default alignment
#define ALIGN_RIGHT         1
#define ALIGN_CENTER        2
#define ALIGN_JUSTIFY       3
//-----------------------------------------------------------------------------
enum WindowStyle
{
    WS_PLAIN = 0,
    WS_BUTTON = 12,
    WS_BORDER = 15
};
//-----------------------------------------------------------------------------
enum ShadowType
{
    WINDOW_SHADOW_NONE = 0,
    WINDOW_SHADOW_RB = 8,
    WINDOW_SHADOW_LB = 9,
    WINDOW_SHADOW_RT = 10,
    WINDOW_SHADOW_LT = 11,
};
//-----------------------------------------------------------------------------
enum BlendingType
{
    BLEND_NONE = 0,
    BLEND_WINDOWS = 1,
    BLEND_ALL = 2,
    BLEND_WINDOWS_AND_BACKGROUNDS = 3
};
//-----------------------------------------------------------------------------
struct WindowConfig
{
    WORD left = 0;
    WORD top = 0;
    WORD width = 100;
    WORD height = 100;
    BYTE bodyColor;
    BYTE borderColor;
    BYTE borderWidth = 0;
    ShadowType shadowType = WINDOW_SHADOW_NONE;
    BYTE shadowWidth = 5;
    BYTE shadowHeight = 5;
    BYTE shadowColor;
    WORD gradientStyle = 0;
    BYTE gradientStep = 4;
    bool visible = true;
};
//-----------------------------------------------------------------------------
struct ButtonConfig
{
    WORD left = 0;
    WORD top = 0;
    WORD width = 100;
    WORD height = 100;
    BYTE colorSet;
    BYTE depth = 5;
    WORD gradientStyle = 0;
    BYTE gradientStep = 4;
    bool pushed = false;
    bool visible = true;
};
//-----------------------------------------------------------------------------
struct FontRowStyle
{
    BYTE VBI_enabled = 0;
    BYTE charBold = 0;
    BYTE charShadow = 0;
    BYTE doubleWidth = 0;
    BYTE doubleHeight = 0;
    BYTE doubleSize = 0;
    BYTE tracking = 0;
};
//-----------------------------------------------------------------------------
struct FontAreaStyle
{
    BYTE alignment = ALIGN_LEFT;
    BYTE bgColor = 0;
    BYTE fontColor = 1;
    BYTE visible = 1;
    BYTE underlined = 0;
    BYTE tracking = 0;
    BYTE blinkMode = BLINK_NONE;
    BYTE fontFace;
};
//-----------------------------------------------------------------------------
class COSD;
class CFontMap;
//-----------------------------------------------------------------------------
class hWnd
{
private:
    OSD_address address;
    OSD_window_data data;
    bool plainStyle: 1;
    bool pushed: 1;
    void apply();
public:
    void setAddress(WORD addr);
    void show();
    void hide();
    void pushButton();
    void releaseButton();
    hWnd* configure(const WindowConfig& config);
    hWnd* configure(const ButtonConfig& config);
    friend hWnd* createWindow(const WindowConfig& config);
    friend hWnd* createButton(const ButtonConfig& config);
    void operator=(const hWnd* win);
    void* operator new(size_t size) { return malloc(size); }
    void operator delete(void *ptr) { free (ptr); };
    hWnd() {}
};
//-----------------------------------------------------------------------------
class CFont
{
public:
    BYTE baseOffset;
    BYTE charsCount;
    BYTE* chWidth;
    char firstChar;
    void* operator new(size_t count);
    CFont(BYTE charsCount, char fChar);
};
//-----------------------------------------------------------------------------
class CFontArea
{
private:
    void output(const char *_str);
public:
    WORD address;
    OSD_row* rowConfig;
    CFont* font;
    BYTE len;                                       // active characters count
    char* str;                                      // stored text
    OSD_char_1bit ch1;
    WORD width;
    BYTE extraTracking;
    BYTE visible: 1;
    BYTE isStatic: 1;
    BYTE isLast: 1;
    BYTE alignment: 2;
    BYTE ldBlanksCount: 3;                          // leading blank characters count
    BYTE ldLastBlankWidth;                          // last leading blank character width
    void* operator new(size_t count);
    void clear();
    void hide();
    void show();
    void blink();
    void print(const char *_str, char newFontFace = -1);
    friend CFontMap;
};
//-----------------------------------------------------------------------------
class CFontAreaSet
{
protected:
    CFontArea** areas;
    CFontAreaSet** sets;
    BYTE areasCount;
    BYTE setsCount;
public:
    CFontAreaSet();
    CFontArea* add(CFontArea* area);
    CFontAreaSet* add(CFontAreaSet& set);
    void hide();
    void show();
    void blink();
};
//-----------------------------------------------------------------------------
class CFontRow
{
public:
    BYTE areasCount;
    WORD nextLeft;      // absolete next area left position in px
    CFontArea** areas;
    OSD_row config;
    CFontRow();
    void* operator new(size_t count);
    CFontArea* addArea(WORD left, WORD width, const char* str, const FontAreaStyle& style);
    CFontArea* addArea(WORD left, WORD width, BYTE charsCount, const FontAreaStyle& style);
    CFontArea* addArea(WORD left, FontAreaStyle& style, BYTE charsCount, char bodyChar, char firstChar = 0, char lastChar = 0);
};
//-----------------------------------------------------------------------------
class CFontMap
{
private:
    char id;
    BYTE mapChanged;
    WORD rowsConfigBase;
    WORD charactersBase;
    CFontRow** rows;
    BYTE rowsCount;
    void update();
    WORD size();
public:
    CFontMap();
    CFontMap(BYTE _id);
    CFontRow* addRow(BYTE height, const FontRowStyle& style);
    void addEmptyRow(WORD height);
    friend COSD;
};
//-----------------------------------------------------------------------------
class COSD
{
private:
    OSD_control0 control0;
    OSD_control3 control3;
    WORD RTDfontAddress;
    void registerFont(BYTE id, const BYTE* flashPtr, WORD flashSize, char firstChar);
public:
    CFontMap maps[2] = {0,1};
    void init();
    void show(CFontMap* map);
    void hide();
    void setOrigin(WORD X_start, WORD Y_start);
    void setTransparency(BYTE value, BlendingType type);
    void uploadColorPallete(const BYTE* pallete);
    CFontMap* nextMap();
    hWnd window[8];
};
//-----------------------------------------------------------------------------
hWnd* createWindow(const WindowConfig& config);
hWnd* createButton(const ButtonConfig& config);
//-----------------------------------------------------------------------------
#endif
