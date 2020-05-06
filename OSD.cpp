//-----------------------------------------------------------------------------
#include <avr/pgmspace.h>
#include <avr/builtins.h>
#include <string.h>
#include "OSD.h"
#include "registers.h"
#include "scaler.h"
#include "avr-debug/debug.h"
//-----------------------------------------------------------------------------
#define _1BIT_FONT(width, \
                   v1a,v1b,v1c,v1d,v1e,v1f, \
                   v2a,v2b,v2c,v2d,v2e,v2f, \
                   v3a,v3b,v3c,v3d,v3e,v3f, \
                   v4a,v4b,v4c,v4d,v4e,v4f, \
                   v5a,v5b,v5c,v5d,v5e,v5f, \
                   v6a,v6b,v6c,v6d,v6e,v6f, \
                   v7a,v7b,v7c,v7d,v7e,v7f, \
                   v8a,v8b,v8c,v8d,v8e,v8f, \
                   v9a,v9b,v9c,v9d,v9e,v9f) \
                   width, \
                   0b##v1e##v1f, 0b##v1c##v1d, 0b##v1a##v1b, \
                   0b##v2e##v2f, 0b##v2c##v2d, 0b##v2a##v2b, \
                   0b##v3e##v3f, 0b##v3c##v3d, 0b##v3a##v3b, \
                   0b##v4e##v4f, 0b##v4c##v4d, 0b##v4a##v4b, \
                   0b##v5e##v5f, 0b##v5c##v5d, 0b##v5a##v5b, \
                   0b##v6e##v6f, 0b##v6c##v6d, 0b##v6a##v6b, \
                   0b##v7e##v7f, 0b##v7c##v7d, 0b##v7a##v7b, \
                   0b##v8e##v8f, 0b##v8c##v8d, 0b##v8a##v8b, \
                   0b##v9e##v9f, 0b##v9c##v9d, 0b##v9a##v9b
//-----------------------------------------------------------------------------
#include "fonts.h"
//-----------------------------------------------------------------------------
COSD OSD;
//-----------------------------------------------------------------------------
__inline void OSD_read(OSD_address address, const BYTE mode, const BYTE count, BYTE* data)
{
    address.mode = mode;
    address.doubleBuffer = 0;
    scaler_write(_OSD_ADDR_90, 2, &address);
    scaler_read(_OSD_DATA_92, count, data, false);
}
//-----------------------------------------------------------------------------
__inline void OSD_write(OSD_address address, const BYTE mode, const BYTE count, const BYTE* data)
{
    address.mode = mode;
    address.doubleBuffer = 0;
    scaler_write(_OSD_ADDR_90, 2, &address);
    scaler_write(_OSD_DATA_92, count, data, false);
}



/******************************************************************************
********************************* class CFont *********************************
******************************************************************************/
void* CFont::operator new(size_t size)
{
    return malloc(size);
}
//-----------------------------------------------------------------------------
CFont::CFont(BYTE _charsCount, char fChar)
{
    charsCount = _charsCount;
    chWidth = (BYTE*) malloc(_charsCount);
    firstChar = fChar;
}



/******************************************************************************
********************************* class COSD **********************************
******************************************************************************/
void COSD::init()
{
    scaler_set_bits(_OVERLAY_CTRL_6C, _bits(0));
    // set windows base addresses
    for(BYTE i = 0; i < 8; i++)
    {
        window[i].setAddress(_OSD_WINDOWS_BASE_ADDR_100 + i * 4);
    }
    control3.blinkingAllowed = 1;
    OSD_write(_OSD_CONTROL3_003, _OSD_BYTE_ALL, 3, control3);

/*  OSD FONT MAP
    -------------------------------------------------------
    Starts at _OSD_FONT_BASE_ADDR_1000
    -------------------------------------------------------
    1. Map 0 rows config (size = OSD_MAX_ROWS_COUNT triads)
    2. Map 0 rows config end (size = 1 triad)
    3. Map 1 rows config (size = OSD_MAX_ROWS_COUNT triads)
    4. Map 1 rows config end (size = 1 triad)
    5. Fonts
    6. Map 0 characters
    7. Map 1 characters                                  */

    // setup font maps (rows) base adresses
    OSD_control8 ctrl8;
    ctrl8.specFunctionEnabled = 1;
    ctrl8.specFunctionSelect = _OSD_POP_ON;
    ctrl8.rows1ConfigBase = maps[0].rowsConfigBase;
    ctrl8.rows2ConfigBase = maps[1].rowsConfigBase;
    OSD_write(_OSD_SPECIAL_FUNCTION_008, _OSD_BYTE_ALL, 3, ctrl8);

    // setup font base address
    RTDfontAddress = _OSD_FONT_BASE_ADDR_1000 + (OSD_MAX_ROWS_COUNT + 1) * 2;
    OSD_Control4 base;
    OSD_read(_OSD_BASE_ADDRESS_OFFSET_004, _OSD_BYTE_ALL, 3, base);
    base.fontStart = RTDfontAddress;
    OSD_write(_OSD_BASE_ADDRESS_OFFSET_004, _OSD_BYTE_ALL, 3, base);

    // register and upload fonts
    for(BYTE i = 0; i < sizeof(fontsList) / 6; i++)
    {
        registerFont(i, (BYTE*) fontsList[3 * i], fontsList[3 * i + 1], (char) fontsList[3 * i + 2]);
    }

    // setup characters base address
    maps[0].charactersBase = RTDfontAddress;
    // maps[1].charactersBase will be calculated dynamically in COSD::show()
}
//-----------------------------------------------------------------------------
void COSD::registerFont(BYTE id, const BYTE* flashPtr, WORD flashSize, char firstChar)
{
    BYTE tmp[3];
    BYTE fontCharsCount = flashSize / 28;
    BYTE* ptr = (BYTE*) flashPtr;
    registeredFonts[id] = new CFont(fontCharsCount, firstChar);
    registeredFonts[id]->baseOffset = 0;
    for(BYTE i = 0; i < id; i++)
    {
        registeredFonts[id]->baseOffset += registeredFonts[i]->charsCount;
    }
    for(BYTE i = 0; i < fontCharsCount; i++)
    {
        registeredFonts[id]->chWidth[i] = pgm_read_byte(ptr++);
        for(BYTE j=0; j<9; j++)
        {
            tmp[0] = pgm_read_byte(ptr++);
            tmp[1] = pgm_read_byte(ptr++);
            tmp[2] = pgm_read_byte(ptr++);
            OSD_write(RTDfontAddress++, _OSD_BYTE_ALL, 3, tmp);
        }
    }
}
//-----------------------------------------------------------------------------
void COSD::setOrigin(WORD X_start, WORD Y_start)
{
    // TODO: unknown "magic" origin offsets
    #define _UNKNOWN_ORIGIN_MAGIC_X 5
    #define _UNKNOWN_ORIGIN_MAGIC_Y 2
    control0.X_delay = X_start / 4 + _UNKNOWN_ORIGIN_MAGIC_X;
    control0.Y_delay = Y_start + DISP_V_BLANK_W - _UNKNOWN_ORIGIN_MAGIC_Y;
    control0.gliphAlignment = _GLIPH_ALIGNMENT_LEFT;
    OSD_write(_OSD_CONTROL0_000, _OSD_BYTE_ALL, 3, control0);
}
//-----------------------------------------------------------------------------
void COSD::setTransparency(BYTE value, BlendingType type)
{
    if(value > 7) value = 7;
    struct OverlayControl
    {
        BYTE portEnable: 1;
        BYTE dualHorSize: 1;
        BYTE alphaLevel: 3;
        BYTE bgColorAccess: 1;
        BYTE : 2;
    };
    OverlayControl ovl;
    scaler_read(_OVERLAY_CTRL_6C, 1, &ovl);
    ovl.portEnable = 1;
    ovl.alphaLevel = value;
    scaler_write(_OVERLAY_CTRL_6C, 1, &ovl);

    if(value)
    {
        BYTE tmp;
        OSD_read(_OSD_CONTROL3_003, _OSD_BYTE_1, 1, &tmp);
        tmp = (tmp & 0xF3) | (type << 2);
        OSD_write(_OSD_CONTROL3_003, _OSD_BYTE_1, 1, &tmp);
    }
}
//-----------------------------------------------------------------------------
void COSD::uploadColorPallete(const BYTE* pallete)
{
    scaler_write(_OVERLAY_LUT_ADDR_6E, 0x80);
    scaler_write_pgm(_COLOR_LUT_PORT_6F, 16 * 3, pallete, false);
}
//-----------------------------------------------------------------------------
void COSD::show(CFontMap *map)
{
    if(map->mapChanged)
    {
        if(map == &maps[1])
        {
            CFontMap* map1 = &maps[0];
            map->charactersBase = map1->charactersBase + map1->size();
        }
        map->update();
    }

    // choose active map
    OSD_control8 ctrl;
    OSD_read(_OSD_SPECIAL_FUNCTION_008, _OSD_BYTE_ALL, 3, ctrl);
    ctrl.activeMap = map->id;
    OSD_write(_OSD_SPECIAL_FUNCTION_008, _OSD_BYTE_ALL, 3, ctrl);

    // turn OSD on
    if(!control0.enabled)
    {
        control0.enabled = 1;
        OSD_write(_OSD_CONTROL0_000, _OSD_BYTE_2, 1, control0[2]);
    }
}
//-----------------------------------------------------------------------------
void COSD::hide()
{
    control0.enabled = 0;
    OSD_write(_OSD_CONTROL0_000, _OSD_BYTE_2, 1, control0[2]);
}



/******************************************************************************
******************************* class CFontMap ********************************
******************************************************************************/
CFontMap::CFontMap()
{
    // constructor for standby font maps
    id = -1;
    rows = NULL;
    rowsCount = 0;
}
//-----------------------------------------------------------------------------
CFontMap::CFontMap(BYTE _id)
{
    id = _id;
    rows = NULL;
    rowsCount = 0;
    mapChanged = 1;
    rowsConfigBase = _OSD_FONT_BASE_ADDR_1000 + (OSD_MAX_ROWS_COUNT + 1) * id;
}
//-----------------------------------------------------------------------------
__inline WORD CFontMap::size()
{
    WORD size = 0;
    for(BYTE i=0; i < rowsCount; i++)
    {
        size += rows[i]->config.len;
    }
    return size;
}
//-----------------------------------------------------------------------------
void CFontMap::update()
{
    if(id < 0)
    {
        // prevents an accidental refresh of standby characters map
        return;
    }
    CFontRow* pRow;
    CFontArea* pArea;
    CFontArea* pAreaPrev;
    OSD_blank blank;

    // setup characters base
    OSD_control9 base;
    OSD_read(_OSD_BASE_ADDRESS_SELECT_009, _OSD_BYTE_ALL, 3, base);
    if(id == 0)
    {
        base.chStart1 = charactersBase;
    }
    else
    {
        base.chStart2 = charactersBase;
    }
    OSD_write(_OSD_BASE_ADDRESS_SELECT_009, _OSD_BYTE_ALL, 3, base);

    // setup rows
    WORD rowBaseAddress = charactersBase;
    for(BYTE i = 0; i<rowsCount; i++)
    {
        pRow = rows[i];
        for(BYTE k = 0; k < pRow->areasCount; k++)
        {
            pArea = pRow->areas[k];

            if(k)
            {
                pAreaPrev = pRow->areas[k-1];
                pArea->address = pAreaPrev->address + pAreaPrev->len + pArea->ldBlanksCount;
            }
            else
            {
                pArea->address = rowBaseAddress + pArea->ldBlanksCount;
            }

            if(pArea->ldBlanksCount)
            {
                // put leading blank characters
                BYTE j = 0;
                blank.color = 0;    // 0 = transparent
                for(; j < (pArea->ldBlanksCount - 1); j++)
                {
                    blank.width = 255 - (pRow->config.tracking << pRow->config.double_width);
                    blank.width >>= pRow->config.double_width;    // double width doubles space width too
                    OSD_write(pArea->address - j - 1, _OSD_BYTE_ALL, 3, blank);
                }
                blank.width = pArea->ldLastBlankWidth - (pRow->config.tracking << pRow->config.double_width);
                blank.width >>= pRow->config.double_width;    // double width doubles space width too
                OSD_write(pArea->address - j - 1, _OSD_BYTE_ALL, 3, blank);
            }
            if(k == (pRow->areasCount - 1))
            {
                // the last area in the row
                pArea->isLast = 1;
            }
            pArea->output(pArea->str);
        }
        rowBaseAddress = rowBaseAddress + pRow->config.len;

        // put row configuration
        OSD_write(rowsConfigBase + i, _OSD_BYTE_ALL, 3, pRow->config);
    }

    // put rows-end command
    OSD_row rowsEnd;
    rowsEnd.configured = 0;
    OSD_write(rowsConfigBase + rowsCount, _OSD_BYTE_ALL, 3, rowsEnd);
    mapChanged = 0;
}
//-----------------------------------------------------------------------------
CFontRow* CFontMap::addRow(BYTE height, const FontRowStyle& style)
{
    if(rowsCount >= OSD_MAX_ROWS_COUNT)
    {
        DSTR("Fatal error: maximum rows count exceeded");
        DVAR(OSD_MAX_ROWS_COUNT);
        halt();
    }
    if(style.doubleHeight || style.doubleSize)
    {
        height = height / 2;
    }
    CFontRow* newRow = new CFontRow();
    rows = (CFontRow**) realloc(rows, sizeof(CFontRow*) * (rowsCount + 1));
    rows[rowsCount++] = newRow;
    newRow->areasCount = 0;
    newRow->config.len = 0;
    if(style.doubleHeight || style.doubleSize)
    {
        newRow->config.double_height = 1;
    }
    if(style.doubleWidth || style.doubleSize)
    {
        newRow->config.double_width = 1;
        newRow->config.tracking = style.tracking / 2;
    }
    else
    {
        newRow->config.tracking = style.tracking;
    }
    newRow->config.height = (height > 32) ? 31 : height - 1;
    newRow->config.VBI_enabled = style.VBI_enabled ? 1 : 0;
    newRow->config.configured = 1;
    mapChanged = 1;
    return newRow;
}
//-----------------------------------------------------------------------------
void CFontMap::addEmptyRow(WORD height)
{
    FontRowStyle style;
    style.doubleHeight = true;
    while(height > 64)
    {
        addRow(32, style);
        height -= 64;
    }
    style.doubleHeight = false;
    while(height > 32)
    {
        addRow(32, style);
        height -= 32;
    }
    if(height > 0)
    {
        addRow((BYTE) height, style);
    }
}



/******************************************************************************
******************************** class CFontRow *******************************
******************************************************************************/
CFontRow::CFontRow()
{
    areas = NULL;
    areasCount = 0;
}
//-----------------------------------------------------------------------------
void* CFontRow::operator new(size_t size)
{
    void* ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
//-----------------------------------------------------------------------------
CFontArea* CFontRow::addArea(WORD left, WORD width, BYTE charsCount, const FontAreaStyle& style)
{
/*
|<----------left--------->|
|            |<--offset-->|<---------width-------->|
|            | ld blanks  | prefix | text | suffix |
|             ------------ -------- ------ --------
0  prev area |        |   |========|A TEXT|========|
                         ^
                         start pos
*/
    if(width==0)
    {
        // minimum width prevents mulfunctions
        width = 1;
    }
    CFontArea* newArea = new CFontArea;
    areas = (CFontArea**) realloc(areas, sizeof(CFontArea*) * (areasCount + 1));
    areas[areasCount++] = newArea;
    WORD offset = 0;
    if(left < nextLeft)
    {
        // prevent overlaying with previous area - start new area right after the previous one
        left = nextLeft;
        offset = 0;
    }
    else
    {
        offset = left - nextLeft;
    }
    nextLeft = left + width * (config.double_width + 1);    // a start position for the next area
    newArea->rowConfig = &config;
    newArea->width = width;
    newArea->extraTracking = (style.tracking > config.tracking) ? (style.tracking - config.tracking) : 0;   // area tracking can not be less than row tracking
    newArea->alignment = style.alignment;
    newArea->font = registeredFonts[style.fontFace];
    newArea->isLast = 0;
    switch(newArea->alignment)
    {
    case ALIGN_JUSTIFY:
        newArea->len = charsCount;  // no prefix and no suffix
        break;
    case ALIGN_CENTER:
        newArea->len = charsCount + 2;  // + prefix and suffix
        break;
    default:
        newArea->len = charsCount + 1;  // + prefix or suffix
    }
    newArea->ldBlanksCount = 0;
    while(offset)
    {
        if(offset>255)
        {
            offset -= 255;
        }
        else
        {
            newArea->ldLastBlankWidth = offset;
            offset = 0;
        }
        newArea->ldBlanksCount++;
    }
    config.len += (newArea->ldBlanksCount + newArea->len);

    // setup font style
    if(config.VBI_enabled)
    {
        newArea->ch1.underlined = style.underlined;
        newArea->ch1.fgBlink = test_bits(style.blinkMode, BLINK_TEXT);
        newArea->ch1.bgBlink = test_bits(style.blinkMode, BLINK_BACKGROUND);
    }
    else
    {
        newArea->ch1.blink = test_bits(style.blinkMode, BLINK_TEXT);
    }
    newArea->visible = style.visible;
    newArea->ch1.color = style.fontColor;
    newArea->ch1.bgColor = style.bgColor;
    return newArea;
}
//-----------------------------------------------------------------------------
CFontArea* CFontRow::addArea(WORD left, WORD width, const char* str, const FontAreaStyle& style)
{
    CFontArea* area = addArea(left, width, strlen(str), style);
    area->str = (char*) str;
    area->isStatic = 1;
    return area;
}
//-----------------------------------------------------------------------------
CFontArea* CFontRow::addArea(WORD left, FontAreaStyle& style, BYTE charsCount, char bodyChar, char firstChar, char lastChar)
{
    CFont *font = registeredFonts[style.fontFace];
    WORD width = charsCount * (font->chWidth[(BYTE)bodyChar - font->firstChar] + config.tracking);
    style.alignment = ALIGN_JUSTIFY;    // alignment could not be applied in this wrapper
    if(firstChar)
    {
        width = width - font->chWidth[(BYTE)bodyChar - font->firstChar] + font->chWidth[(BYTE)firstChar - font->firstChar];
    }
    if(lastChar)
    {
        width = width - font->chWidth[(BYTE)bodyChar - font->firstChar] + font->chWidth[(BYTE)lastChar - font->firstChar];
    }
    CFontArea* area = addArea(left, width, charsCount, style);
    area->str = (char*) malloc(charsCount + 1);
    if(bodyChar)
    {
        memset(area->str, bodyChar, charsCount);
    }
    else
    {
        area->str[0] = '\0';
    }
    if(firstChar)
    {
        area->str[0] = firstChar;
    }
    if(lastChar)
    {
        area->str[charsCount - 1] = lastChar;
    }
    area->str[charsCount] = '\0';
    area->isStatic = 1;
    return area;
}



/******************************************************************************
******************************* class CFontArea *******************************
******************************************************************************/
void* CFontArea::operator new(size_t size)
{
    void* ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
//-----------------------------------------------------------------------------
void CFontArea::output(const char *_str)
{
    str = (char*) _str;
    if(!address)
    {
        // the area was not initialized yet, so we can't write to OSD
        return;
    }
    const char* ch = _str;
    WORD addr;
    WORD textAddr;
    BYTE prefixLen = 0;
    BYTE suffixLen = 0;
    WORD textWidth = 0;
    BYTE prefixWidth = 0;
    BYTE suffixWidth = 0;

    OSD_blank blank;
    if(visible)
    {
        blank.color = ch1.bgColor;
        blank.blink = ch1.bgBlink;
    }
    else
    {
        blank.color = 0;    // 0 = transparent
    }
    switch(alignment)
    {
    case ALIGN_CENTER:
        textAddr = address + (len - strlen(str)) / 2;
        break;
    case ALIGN_RIGHT:
        textAddr = address + len - strlen(str);
        break;
    case ALIGN_LEFT:
    case ALIGN_JUSTIFY:
        textAddr = address;
    }

    // fill string characters and calculate real text width
    WORD ptr = textAddr;
    while(*ch)
    {
        ch1.code = *ch - font->firstChar;
        if(visible)
        {
            if(!rowConfig->VBI_enabled)
            {
                ch1.width = (font->chWidth[ch1.code] + extraTracking) > OSD_FONT_MAX_CHAR_WIDTH ? OSD_FONT_MAX_CHAR_WIDTH : (font->chWidth[ch1.code] + extraTracking);
                textWidth += (ch1.width + rowConfig->tracking) << rowConfig->double_width;
            }
            else
            {
                textWidth += (12 + extraTracking + rowConfig->tracking) << rowConfig->double_width;
            }
            ch1.code += font->baseOffset;
            OSD_write(ptr++, _OSD_BYTE_ALL, 3, ch1);
        }
        else
        {
            blank.width = (font->chWidth[ch1.code] + extraTracking) > OSD_FONT_MAX_CHAR_WIDTH ? OSD_FONT_MAX_CHAR_WIDTH : (font->chWidth[ch1.code] + extraTracking);
            textWidth += (blank.width + rowConfig->tracking) << rowConfig->double_width;
            OSD_write(ptr++, _OSD_BYTE_ALL, 3, blank);
        }
        ch++;
    }

    switch(alignment)
    {
    case ALIGN_CENTER:
        prefixLen = (len - strlen(str)) / 2;
        prefixWidth = (width - textWidth) / 2 + (rowConfig->tracking << rowConfig->double_width);
        prefixWidth = (prefixWidth >> rowConfig->double_width) << rowConfig->double_width;          // round down to even value
        suffixLen = len - prefixLen - strlen(str);
        suffixWidth = width - prefixWidth - textWidth;
        break;
    case ALIGN_RIGHT:
        prefixLen = len - strlen(str);
        prefixWidth = width - textWidth;
        break;
    case ALIGN_LEFT:
        suffixLen = len - strlen(str);
        suffixWidth = width - textWidth;
        break;
    }
    addr = address;
    textAddr = address + prefixLen;

    // prefix
    if(prefixLen)
    {
        register BYTE prefixStep = prefixWidth / prefixLen;
        blank.width = (prefixStep >> rowConfig->double_width) - rowConfig->tracking;
        while(prefixLen--)
        {
            if(prefixLen > 0)
            {
                prefixWidth -= prefixStep;
            }
            else
            {
                // last blank corrects floor-ing
                blank.width = (prefixWidth >> rowConfig->double_width) - rowConfig->tracking;
            }
            OSD_write(addr++, _OSD_BYTE_ALL, 3, blank);
        }
    }

    // suffix
    if(suffixLen)
    {
        register BYTE suffixStep = suffixWidth / suffixLen;
        blank.width = (suffixStep >> rowConfig->double_width) - rowConfig->tracking;
        while(suffixLen--)
        {
            if(suffixLen > 0)
            {
                suffixWidth -= suffixStep;
            }
            else
            {
                // last blank corrects floor-ing
                if(isLast)
                {
                    // last area in the row has no tracking space
                    blank.width = (suffixWidth >> rowConfig->double_width);
                }
                else
                {
                    blank.width = (suffixWidth >> rowConfig->double_width) - rowConfig->tracking;
                }
            }
            OSD_write(ptr++, _OSD_BYTE_ALL, 3, blank);
        }
    }
    #ifdef DEBUG
    if(textWidth > width)
    {
        DSTR("!===");
        DSTR("Text width exceeds area width");
        DVAR(width);
        DVAR(textWidth);
    }
    #endif
}
//-----------------------------------------------------------------------------
void CFontArea::print(const char *_str, char newFontFace)
{
    if(newFontFace >= 0)
    {
        font = registeredFonts[(BYTE)newFontFace];
    }
    str = (char*) realloc(str, strlen(_str) + 1);
    strcpy(str, _str);
    output((const char*)str);
}
//-----------------------------------------------------------------------------
void CFontArea::hide()
{
    visible = 0;
    ch1.blink = 0;
    output(str);
}
//-----------------------------------------------------------------------------
void CFontArea::blink()
{
    visible = 1;
    ch1.blink = 1;
    output(str);
}
//-----------------------------------------------------------------------------
void CFontArea::show()
{
    visible = 1;
    ch1.blink = 0;
    output(str);
}



/******************************************************************************
***************************** class CFontAreaSet ******************************
******************************************************************************/
CFontAreaSet::CFontAreaSet()
{
    areas = NULL;
    areasCount = 0;
}
//-----------------------------------------------------------------------------
CFontArea* CFontAreaSet::add(CFontArea* area)
{
    areas = (CFontArea**) realloc(areas, sizeof(CFontArea*) * (areasCount + 1));
    areas[areasCount++] = area;
    return area;
}
//-----------------------------------------------------------------------------
CFontAreaSet* CFontAreaSet::add(CFontAreaSet& set)
{
    sets = (CFontAreaSet**) realloc(sets, sizeof(CFontAreaSet*) * (setsCount + 1));
    sets[setsCount++] = &set;
    return this;
}
//-----------------------------------------------------------------------------
void CFontAreaSet::hide()
{
    for(BYTE i=0; i < areasCount; i++)
    {
        areas[i]->hide();
    }

    for(BYTE i=0; i < setsCount; i++)
    {
        sets[i]->hide();
    }
}
//-----------------------------------------------------------------------------
void CFontAreaSet::show()
{
    for(BYTE i=0; i < areasCount; i++)
    {
        areas[i]->show();
    }

    for(BYTE i=0; i < setsCount; i++)
    {
        sets[i]->show();
    }
}
//-----------------------------------------------------------------------------
void CFontAreaSet::blink()
{
    for(BYTE i=0; i < areasCount; i++)
    {
        areas[i]->blink();
    }

    for(BYTE i=0; i < setsCount; i++)
    {
        sets[i]->blink();
    }
}
//-----------------------------------------------------------------------------
__inline void setWindowGradient(OSD_window_data &data, WORD gradientStyle, BYTE gradientStep)
{
    if(gradientStyle && gradientStep)
    {
        data.gradientEnabled = 1;
        data.gradient = gradientStyle & 0xFF;
        data.gradientDirection = (gradientStyle & 0x100) >> 8;
        if(gradientStep<12)
        {
            data.gradientStep_L = gradientStep<5 ? 3 - ((gradientStep-1) & 0x03) : 0;
            data.gradientStep_H = gradientStep<5 ? 1 : gradientStep-3;
        }
        else
        {
            data.gradientStep_L = 0;
            data.gradientStep_H = 0;
        }
    }
    else
    {
        data.gradientEnabled = 0;
    }
}
//-----------------------------------------------------------------------------
hWnd* createWindow(const WindowConfig& config)
{
    hWnd* wnd = new hWnd;
    wnd->configure(config);
    return wnd;
}
//-----------------------------------------------------------------------------
hWnd* createButton(const ButtonConfig& config)
{
    hWnd* wnd = new hWnd;
    wnd->configure(config);
    return wnd;
}



/******************************************************************************
********************************* class hWnd **********************************
******************************************************************************/
hWnd* hWnd::configure(const WindowConfig& config)
{
    WORD width = config.width;
    WORD height = config.height;
    data.bodyColor = config.bodyColor;
    if(config.shadowType)
    {
        // window with shadow
        data.shadow_width = config.shadowWidth - 1;
        data.shadow_height = config.shadowHeight - 1;
        width -= config.shadowWidth;
        height -= config.shadowHeight;
        data.shadow_color = config.shadowColor;
        data.style = config.shadowType;
        data.enabled = config.visible;
    }
    else
    {
        if(config.borderWidth)
        {
            // window with border
            BYTE borderWidth = config.borderWidth;
            data.border_color = config.borderColor;
            if((borderWidth * 2) > config.width)
            {
                borderWidth = config.width / 2;
            }
            if((borderWidth * 2) > config.height)
            {
                borderWidth = config.height / 2;
            }
            data.border_width = borderWidth - 1;
            data.border_height = borderWidth - 1;
            width -= borderWidth;
            height -= borderWidth;
            if(config.bodyColor == 0)
            {
                // transparent window with borders
                data.btnColor1 = config.borderColor;
                data.btnColor2 = config.borderColor;
                data.style = WS_BUTTON;
                data.enabled = 0;
            }
            else
            {
                data.style = WS_BORDER;
                data.enabled = config.visible;
            }
        }
        else
        {
            plainStyle = true;
            data.style = WS_PLAIN;
            data.enabled = config.visible;
        }
    }
    setWindowGradient(data, config.gradientStyle, config.gradientStep);
    data.X1 = config.left;
    data.X2 = config.left + width;
    data.Y1 = config.top;
    data.Y2 = config.top + height;
    apply();
    return this;
}
//-----------------------------------------------------------------------------
hWnd* hWnd::configure(const ButtonConfig& config)
{
    BYTE depth = config.depth;
    data.bodyColor = config.colorSet;
    if(config.pushed)
    {
        data.btnColor1 = config.colorSet + 2;
        data.btnColor2 = config.colorSet + 1;
        pushed = true;
    }
    else
    {
        data.btnColor1 = config.colorSet + 1;
        data.btnColor2 = config.colorSet + 2;
        pushed = false;
    }
    setWindowGradient(data, config.gradientStyle, config.gradientStep);
    data.border_width = depth - 1;
    data.border_height = depth - 1;
    data.X1 = config.left;
    data.X2 = config.left + config.width - depth;
    data.Y1 = config.top;
    data.Y2 = config.top + config.height - depth;
    data.style = WS_BUTTON;
    data.enabled = config.visible;
    apply();
    return this;
}
//-----------------------------------------------------------------------------
void hWnd::setAddress(WORD addr)
{
    address = addr;
}
//-----------------------------------------------------------------------------
void hWnd::show()
{
    if(!plainStyle)
    {
        data.showBorder = 1;
    }
    data.enabled = 1;
    apply();
}
//-----------------------------------------------------------------------------
void hWnd::hide()
{
    data.showBorder = 0;
    data.enabled = 0;
    apply();
}
//-----------------------------------------------------------------------------
void hWnd::operator=(const hWnd* win)
{
    OSD_address addr = address;
    memcpy(this, win, sizeof(hWnd));
    address = addr;
    apply();
}
//-----------------------------------------------------------------------------
void hWnd::apply()
{
    if((address & 0x0FFF) >= _OSD_WINDOWS_BASE_ADDR_100)
    {
        // apply settings for real windows only
        OSD_write(address, _OSD_BYTE_ALL, 4 * 3, data);
    }
}
//-----------------------------------------------------------------------------
void hWnd::pushButton()
{
    if(!pushed)
    {
        BYTE tmp = data.btnColor1;
        data.btnColor1 = data.btnColor2;
        data.btnColor2 = tmp;
        pushed = true;
        apply();
    }
}
//-----------------------------------------------------------------------------
void hWnd::releaseButton()
{
    if(pushed)
    {
        BYTE tmp = data.btnColor1;
        data.btnColor1 = data.btnColor2;
        data.btnColor2 = tmp;
        pushed = false;
        apply();
    }
}
//-----------------------------------------------------------------------------
