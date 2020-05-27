#ifndef FONTS_H
#define FONTS_H
//-----------------------------------------------------------------------------
#include "fonts/font-basic.h"
#include "fonts/font-graphics.h"
//-----------------------------------------------------------------------------
#define ADD_FONT(ptr, firsCharacter)    (WORD) ptr, sizeof(ptr), (WORD) firsCharacter
//-----------------------------------------------------------------------------
const WORD fontsList[] =
{
    ADD_FONT(fontBasicChars, ' '),
    ADD_FONT(fontGraphicsChars, 1)
};
//-----------------------------------------------------------------------------
CFont* registeredFonts[sizeof(fontsList) / 6];
//-----------------------------------------------------------------------------
#endif
