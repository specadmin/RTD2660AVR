#ifndef SCALER_H
#define SCALER_H
//----------------------------------------------------------------------------
#include "avr-misc/avr-misc.h"
//----------------------------------------------------------------------------
BYTE scaler_init();

BYTE scaler_read(BYTE address);
void scaler_read(BYTE address, BYTE count, void* data, bool auto_inc = true);

void scaler_write(const BYTE address, const BYTE value);
void scaler_write(const BYTE address, const BYTE count, const void* data, const bool auto_inc = true);
void scaler_write_pgm(const BYTE address, const BYTE count, const void* data, const bool auto_inc = true);

BYTE scaler_get_bit(BYTE address, BYTE bit);
void scaler_set_bits(BYTE address, BYTE bits);
void scaler_clr_bits(BYTE address, BYTE bits);
void scaler_change_bits(BYTE address, BYTE clr_bits, BYTE set_bits);

BYTE scaler_read_port(BYTE port, BYTE address);
void scaler_read_port(BYTE port, BYTE address, BYTE count, void* data);

void scaler_write_port(BYTE port, BYTE address, BYTE value);
void scaler_write_port(BYTE port, BYTE address, BYTE count, const void* data);

BYTE scaler_get_port_bit(BYTE port, BYTE address, BYTE bit);
void scaler_set_port_bits(BYTE port, BYTE address, BYTE bits);
void scaler_clr_port_bits(BYTE port, BYTE address, BYTE bits);

#define scaler_select_page(page) scaler_write(_PAGE_SELECT_9F, page)
//----------------------------------------------------------------------------
#endif
