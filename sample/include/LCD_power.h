#ifndef LCD_POWER_H
#define LCD_POWER_H
//-----------------------------------------------------------------------------
void LCDPowerOn()
{
    scaler_select_page(_PAGEE);
    scaler_write(_PE_PIN113_CONFIG, _PIN113_OUTPUT_OD);
    scaler_select_page(_PAGEF);
    scaler_clr_bits(_GPIO_P3, _bits(6));
}
//-----------------------------------------------------------------------------
void LCDPowerOff()
{
    scaler_select_page(_PAGEF);
    scaler_set_bits(_GPIO_P3, _bits(6));
}
//-----------------------------------------------------------------------------
void backlightOn()
{
    // PCB800809.V6 board has no LCD backlight control (always on)
}
//-----------------------------------------------------------------------------
void backlightOff()
{
    // PCB800809.V6 board has no LCD backlight control (always on)
}
//-----------------------------------------------------------------------------
void setOrientation(BYTE value)
{
    scaler_select_page(_PAGEE);
    scaler_write(_PE_PIN_SHARE_CTRL07_FF9D, _PIN99_OUTPUT);
    scaler_write(_PE_PIN98_CONFIG, _PIN98_OUTPUT_OD);

    scaler_select_page(_PAGEF);
    scaler_write(_PIN98, value & 0x01);
    scaler_write(_PIN99, (value & 0x02) >> 1);
}
//-----------------------------------------------------------------------------
#endif
