//-----------------------------------------------------------------------------
#include "avr/pgmspace.h"
#include "avr-misc/avr-misc.h"
#include "avr-debug/debug.h"
#include "RTD2660AVR/display.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
//-----------------------------------------------------------------------------
enum OSD_pallete
{
    CL_TRANSPARENT = 0,
    CL_BLACK,
    CL_WHITE,
    CL_GREY,
    CL_RED,
    CL_GREEN,
    CL_YELLOW,
    CL_BLUE,
    CL_CYAN,
    CL_BUTTON_GREEN,
    CL_BUTTON_GREEN_LIGHT,
    CL_BUTTON_GREEN_DARK,
    CL_BUTTON_RED,
    CL_BUTTON_RED_LIGHT,
    CL_BUTTON_RED_DARK,
    CL_SIZE
};
//-----------------------------------------------------------------------------
const PROGMEM BYTE pallete[CL_SIZE][3]=
{
    {0, 120, 60},       // CL_TRANSPARENT
    {0, 0, 0},          // CL_BLACK
    {255, 255, 255},    // CL_WHITE
    {100, 100, 100},    // CL_GREY
    {255, 0, 0},        // CL_RED
    {0, 255, 0},        // CL_GREEN
    {255, 255, 0},      // CL_YELLOW
    {0, 0, 255},        // CL_BLUE
    {0, 255, 255},      // CL_CYAN
    {0, 160, 0},        // CL_BUTTON_GREEN
    {0, 240, 0},
    {0, 90, 0},
    {140, 0, 0},        // CL_BUTTON_RED
    {240, 0, 0},
    {70, 0, 0}
};
//-----------------------------------------------------------------------------

int main()
{
    DEBUG_INIT();

    DisplayConfig config;
    config.backgroundColor = 0x000000;
    display.init(config);

    display.showVideo(VS_AV2);
    display.on();

    OSD.setOrigin(0,0);
    OSD.setTransparency(5, BLEND_WINDOWS_AND_BACKGROUNDS);
    OSD.uploadColorPallete((BYTE*)pallete);

    FontRowStyle rowStyle;
    FontAreaStyle fontStyle;

    CFontMap* map1 = &OSD.maps[0];
    CFontMap* map2 = &OSD.maps[1];

    map1->addEmptyRow(24);
    rowStyle.doubleSize = true;
    rowStyle.tracking = 5;
    CFontRow* row1 = map1->addRow(8, rowStyle);
    CFontRow* row2 = map1->addRow(40, rowStyle);
    map1->addEmptyRow(10);
    rowStyle.doubleSize = false;
    rowStyle.tracking = 2;
    CFontRow* row3 = map1->addRow(4, rowStyle);
    CFontRow* row4 = map1->addRow(20, rowStyle);
    map1->addEmptyRow(50);
    CFontRow* row5 = map1->addRow(24, rowStyle);
    CFontRow* row6 = map1->addRow(24, rowStyle);
    CFontRow* row7 = map1->addRow(24, rowStyle);
    CFontRow* row8 = map1->addRow(24, rowStyle);
    CFontRow* row9 = map1->addRow(24, rowStyle);
    CFontRow* row10 = map1->addRow(24, rowStyle);
    CFontRow* row11 = map1->addRow(24, rowStyle);
    CFontRow* row12 = map1->addRow(24, rowStyle);
    CFontRow* row13 = map1->addRow(24, rowStyle);
    map1->addEmptyRow(101);
    CFontRow* btnRow = map1->addRow(18, rowStyle);

    // yellow box
    WindowConfig wndConf;
    wndConf.left = 0;
    wndConf.top = 10;
    wndConf.width = 270;
    wndConf.height = 109;
    wndConf.bodyColor = CL_YELLOW;
    wndConf.borderColor = CL_RED;
    wndConf.borderWidth = 0;
    OSD.window[0].configure(wndConf);

    // scale line
    wndConf.left = 140;
    wndConf.top = 145;
    wndConf.width = 4;
    wndConf.height = 240;
    wndConf.bodyColor = CL_CYAN;
    wndConf.borderWidth = 0;
    wndConf.shadowType = WINDOW_SHADOW_NONE;
    wndConf.gradientStyle = GRAD_NONE;
    OSD.window[1].configure(wndConf);

    // pointing frame
    wndConf.left = 347;
    wndConf.top = 306;
    wndConf.width = 24;
    wndConf.height = 24;
    wndConf.bodyColor = CL_TRANSPARENT;
    wndConf.borderColor = CL_CYAN;
    wndConf.borderWidth = 2;
    OSD.window[2].configure(wndConf);

    // button 1
    ButtonConfig btnConf;
    btnConf.left = 60;
    btnConf.top = 425;
    btnConf.width = 130;
    btnConf.height = 48;
    btnConf.colorSet = CL_BUTTON_GREEN;
    btnConf.pushed = true;
    hWnd* btn1 = OSD.window[3].configure(btnConf);

    // button 2
    btnConf.left = 240;
    btnConf.top = 425;
    btnConf.pushed = false;
    OSD.window[4] .configure(btnConf);

    // button 3
    btnConf.left = 420;
    btnConf.top = 425;
    btnConf.colorSet = CL_BUTTON_RED;
    OSD.window[5].configure(btnConf);

    // button 4
    btnConf.left = 600;
    btnConf.top = 425;
    btnConf.colorSet = CL_BUTTON_GREEN;
    OSD.window[6].configure(btnConf);

    // dialog window
    wndConf.left = 550;
    wndConf.top = 80;
    wndConf.width = 200;
    wndConf.height = 250;
    wndConf.bodyColor = CL_CYAN;
    wndConf.shadowColor = CL_GREY;
    wndConf.shadowType = WINDOW_SHADOW_RB;
    wndConf.gradientStyle = GRAD_BLUE_LESS | GRAD_VERTICAL;
    wndConf.gradientStep = 4;
    hWnd* wDialog = createWindow(wndConf);  // another way to create windows
    OSD.window[7] = wDialog;                // and to assign it when needed

    fontStyle.alignment = ALIGN_CENTER;
    fontStyle.fontColor = CL_YELLOW;
    fontStyle.bgColor = CL_BLUE;
    fontStyle.fontFace = 0;
    row1->addArea(0, 250, " ", fontStyle);
    row2->addArea(0, 250, "OK", fontStyle);

    fontStyle.blinkMode = BLINK_ALL;
    fontStyle.fontColor = CL_RED;
    fontStyle.bgColor = CL_GREEN;
    row3->addArea(0, 250, "", fontStyle);
    row4->addArea(0, 250, "LOOK AROUND", fontStyle);

    // scale labels
    fontStyle.alignment = ALIGN_RIGHT;
    fontStyle.blinkMode = BLINK_NONE;
    fontStyle.fontColor = CL_CYAN;
    fontStyle.bgColor = CL_TRANSPARENT;
    row5->addArea(80, 40, "600", fontStyle);
    row7->addArea(80, 40, "500", fontStyle);
    row9->addArea(80, 40, "400", fontStyle);
    row11->addArea(80, 40, "300", fontStyle);
    row13->addArea(80, 40, "200", fontStyle);

    // scale dashes
    fontStyle.fontFace = 1;
    row5->addArea(120, fontStyle, 1, 3);
    row6->addArea(120, fontStyle, 1, 4);
    row7->addArea(120, fontStyle, 1, 3);
    row8->addArea(120, fontStyle, 1, 4);
    row9->addArea(120, fontStyle, 1, 3);
    row10->addArea(120, fontStyle, 1, 4);
    row11->addArea(120, fontStyle, 1, 3);
    row12->addArea(120, fontStyle, 1, 4);
    row13->addArea(120, fontStyle, 1, 3);
    fontStyle.fontFace = 0;

    // text in the window with shadow
    fontStyle.alignment = ALIGN_LEFT;
    fontStyle.fontColor = CL_BLACK;
    row5->addArea(555, 180, "THIS WINDOW HAS", fontStyle);
    row6->addArea(555, 180, "A SHADOW. YOU", fontStyle);
    row7->addArea(555, 180, "CAN USE IT TO", fontStyle);
    row8->addArea(555, 180, "CREATE DIALOGS", fontStyle);

    // buttons text
    fontStyle.alignment = ALIGN_CENTER;
    fontStyle.fontColor = CL_WHITE;
    CFontArea* btn1Text = btnRow->addArea(60, 110, " PUSHED ", fontStyle);
    btnRow->addArea(240, 110, "HOLD", fontStyle);
    btnRow->addArea(420, 110, "GRAB!", fontStyle);
    btnRow->addArea(600, 110, "LET IT GO", fontStyle);
    OSD.show(map1);

    mdelay(2000);
    btn1->releaseButton();
    btn1Text->print("RELEASED");
    mdelay(2000);
    btn1->pushButton();
    btn1Text->print("PUSHED");


    heap_info();
    memory_usage();

    return 0;
}
//-----------------------------------------------------------------------------
