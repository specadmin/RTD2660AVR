#ifndef RTD2660_SPI_H
#define RTD2660_SPI_H
//-----------------------------------------------------------------------------
#include "avr/pgmspace.h"
#include "config.h"
//-----------------------------------------------------------------------------
#define RTD_READ            1
#define RTD_WRITE           0
#define RTD_NO_AUTOINC      1
#define RTD_AUTOINC         0
#define RTD_ID_ADDRESS      0x00
#define RTD_ID_MAGIC        0xF1
#define RTD_RX_DATA         ((RTD_RX_PIN & _bit(RTD_RX_BIT)) >> RTD_RX_BIT)
#define RTD_enable()        clr_bit(RTD_CS_PORT, RTD_CS_BIT)
#define RTD_disable()       set_bit(RTD_CS_PORT, RTD_CS_BIT)
#define RTD_toggle_clk()    RTD_CLK_PORT = RTD_CLK_PORT ^ _bit(RTD_CLK_BIT)
//-----------------------------------------------------------------------------
__inline void RTD2660_SPI_init()
{
    set_bit(RTD_CLK_DDR, RTD_CLK_BIT);
    set_bit(RTD_TX_DDR, RTD_TX_BIT);
    set_bit(RTD_CS_PORT, RTD_CS_BIT);
    set_bit(RTD_CS_DDR, RTD_CS_BIT);
}
//-----------------------------------------------------------------------------
__inline void RTD2660_SPI_send_bit(BYTE value)
{
    if(value)
    {
        set_bit(RTD_TX_PORT, RTD_TX_BIT);
    }
    else
    {
        clr_bit(RTD_TX_PORT, RTD_TX_BIT);
    }
    RTD_toggle_clk();
}
//-----------------------------------------------------------------------------
__inline BYTE RTD2660_SPI_get_bit()
{
    static BYTE read;
    read = RTD_RX_DATA;
    RTD_toggle_clk();
    return read;
}
//-----------------------------------------------------------------------------
__inline void RTD2660_SPI_read(BYTE address, BYTE count, BYTE *data, bool auto_inc)
{
    register BYTE tmp = address;
    set_bit(RTD_CLK_PORT, RTD_CLK_BIT);
    RTD_enable();
    // address
    for(BYTE i = 0; i < 8; i++)
    {
        RTD2660_SPI_send_bit(tmp & 0x1);
        tmp >>= 1;
    }

    // command
    RTD2660_SPI_send_bit(RTD_READ);
    if(auto_inc && count>1)
        RTD2660_SPI_send_bit(RTD_AUTOINC);
    else
        RTD2660_SPI_send_bit(RTD_NO_AUTOINC);
    RTD2660_SPI_send_bit(1);

    // reply
    BYTE pos = 0;
    while(count--)
    {
        for(BYTE i = 0; i < 8; i++)
        {
            tmp = (tmp >> 1) | (RTD2660_SPI_get_bit() << 7);
        }
        data[pos++] = tmp;
    }
    RTD_disable();
}
//-----------------------------------------------------------------------------
__inline void RTD2660_SPI_write(const BYTE address, const BYTE count, const BYTE *data, const bool auto_inc)
{
    register BYTE tmp = address;
    register BYTE cnt = count;
    set_bit(RTD_CLK_PORT, RTD_CLK_BIT);
    RTD_enable();

    // address and command
    for(BYTE i = 0; i < 8; i++)
    {
        RTD2660_SPI_send_bit(tmp & 0x1);
        tmp >>= 1;
    }
    RTD2660_SPI_send_bit(RTD_WRITE);
    if(auto_inc && count > 1)
        RTD2660_SPI_send_bit(RTD_AUTOINC);
    else
        RTD2660_SPI_send_bit(RTD_NO_AUTOINC);

    // data
    BYTE pos = 0;
    while(cnt--)
    {
        tmp = data[pos++];
        for(BYTE i = 0; i < 8; i++)
        {
            RTD2660_SPI_send_bit(tmp & 0x1);
            tmp >>= 1;
        }
    }
    RTD_disable();
}
//-----------------------------------------------------------------------------
__inline void RTD2660_SPI_write_pgm(const BYTE address, const BYTE count, const BYTE *data, const bool auto_inc)
{
    register BYTE tmp = address;
    register BYTE cnt = count;
    set_bit(RTD_CLK_PORT, RTD_CLK_BIT);
    RTD_enable();

    // address and command
    for(BYTE i = 0; i < 8; i++)
    {
        RTD2660_SPI_send_bit(tmp & 0x1);
        tmp >>= 1;
    }
    RTD2660_SPI_send_bit(RTD_WRITE);
    if(auto_inc && count > 1)
        RTD2660_SPI_send_bit(RTD_AUTOINC);
    else
        RTD2660_SPI_send_bit(RTD_NO_AUTOINC);

    // data
    BYTE pos = 0;
    while(cnt--)
    {
        tmp = pgm_read_byte(data + pos++);
        for(BYTE i = 0; i < 8; i++)
        {
            RTD2660_SPI_send_bit(tmp & 0x1);
            tmp >>= 1;
        }
    }
    RTD_disable();
}
//-----------------------------------------------------------------------------
#endif
