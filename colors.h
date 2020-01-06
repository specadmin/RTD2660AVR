#ifndef COLORS_H
#define COLORS_H
//-----------------------------------------------------------------------------
class RGB_color
{
public:
    BYTE red;
    BYTE green;
    BYTE blue;
    operator BYTE*()
    {
        return &red;
    }
    RGB_color() {}
    RGB_color(const DWORD value)
    {
        DWORD tmp = value;
        blue = tmp & 0xFF; tmp >>= 8;
        green = tmp & 0xFF; tmp >>= 8;
        red = tmp & 0xFF;
    }
};
//-----------------------------------------------------------------------------
#endif
