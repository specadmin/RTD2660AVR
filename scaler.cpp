//----------------------------------------------------------------------------
#include <string.h>
#include "avr-debug/debug.h"
#include "scaler.h"
#include "RTD2660_SPI.h"
//-----------------------------------------------------------------------------
BYTE scaler_init()
{
    RTD2660_SPI_init();
    if(scaler_read(RTD_ID_ADDRESS) != RTD_ID_MAGIC)
    {
        return 1;
    }
    return 0;
}
//-----------------------------------------------------------------------------
void scaler_read(BYTE address, BYTE count, void* data, bool auto_inc)
{
    RTD2660_SPI_read(address, count, (BYTE*) data, auto_inc);
}
//-----------------------------------------------------------------------------
BYTE scaler_read(BYTE address)
{
    BYTE result=0;
    scaler_read(address, 1, &result);
    return result;
}
//-----------------------------------------------------------------------------
void scaler_write(const BYTE address, const BYTE count, const void* data, const bool auto_inc)
{
    RTD2660_SPI_write(address, count, (BYTE*) data, auto_inc);
}
//-----------------------------------------------------------------------------
void scaler_write_pgm(const BYTE address, const BYTE count, const void* data, const bool auto_inc)
{
    RTD2660_SPI_write_pgm(address, count, (BYTE*) data, auto_inc);
}
//-----------------------------------------------------------------------------
void scaler_write(const BYTE address, const BYTE value)
{
    scaler_write(address, 1, &value, false);
}
//-----------------------------------------------------------------------------
BYTE scaler_get_bit(BYTE address, BYTE bit)
{
    return (scaler_read(address) & _bit(bit)) >> bit;
}
//-----------------------------------------------------------------------------
void scaler_set_bits(BYTE address, BYTE bits)
{
    BYTE tmp = scaler_read(address);
    scaler_write(address, tmp | bits);
}
//-----------------------------------------------------------------------------
void scaler_clr_bits(BYTE address, BYTE bits)
{
    BYTE tmp = scaler_read(address);
    scaler_write(address, tmp & ~bits);
}
//-----------------------------------------------------------------------------
void scaler_change_bits(BYTE address, BYTE clr_bits, BYTE set_bits)
{
    BYTE tmp = scaler_read(address);
    scaler_write(address, (tmp & (~clr_bits)) | set_bits);
}
//-----------------------------------------------------------------------------
BYTE scaler_read_port(BYTE port, BYTE address)
{
    scaler_write(port-1, address);
    return scaler_read(port);
}
//-----------------------------------------------------------------------------
void scaler_read_port(BYTE port, BYTE address, BYTE count, void* data)
{
    scaler_write(port-1, address);
    scaler_read(port, count, data, false);
}
//-----------------------------------------------------------------------------
void scaler_write_port(BYTE port, BYTE address, BYTE value)
{
    scaler_write(port-1, address);
    scaler_write(port, 1, &value, false);
}
//-----------------------------------------------------------------------------
void scaler_write_port(BYTE port, BYTE address, BYTE count, const void* data)
{
    scaler_write(port-1, address);
    scaler_write(port, count, data, false);
}
//-----------------------------------------------------------------------------
BYTE scaler_get_port_bit(BYTE port, BYTE address, BYTE bit)
{
    return (scaler_read_port(port, address) & _bit(bit)) >> bit;
}
//-----------------------------------------------------------------------------
void scaler_set_port_bits(BYTE port, BYTE address, BYTE bits)
{
    BYTE tmp=scaler_read_port(port, address);
    scaler_write_port(port, address, tmp | bits);
}
//-----------------------------------------------------------------------------
void scaler_clr_port_bits(BYTE port, BYTE address, BYTE bits)
{
    BYTE tmp=scaler_read_port(port, address);
    scaler_write_port(port, address, tmp & ~bits);
}
//-----------------------------------------------------------------------------


