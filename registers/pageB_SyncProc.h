#ifndef PAGEB_SYNCPROC_H
#define PAGEB_SYNCPROC_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////   Page B: Off Line Sync Processor & Auto SOY  /////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGEB                                  0x0B

//--------------------------------------------------
// Off Line Sync Processor
//--------------------------------------------------
#define _PB_SYNC_SELECT_A0                  	0xA0        // Sync Select Control Register
#define _PB_SYNC_INVERT_A1                  	0xA1        // Sync Invert Control Register
#define _PB_SYNC_CTRL_A2                    	0xA2        // Sync Processor Control Register
#define _PB_STABLE_HIGH_PERIOD_H_A3       		0xA3        // Stable High Period HByte
#define _PB_STABLE_HIGH_PERIOD_L_A4         	0xA4        // Stable High Period LByte
#define _PB_VSYNC_COUNTER_LEVEL_MSB_A5   		0xA5        // Vertical Sync Counter Level MSB
#define _PB_VSYNC_COUNTER_LEVEL_LSB_A6      	0xA6        // Vertical Sync Counter Level LSB
#define _PB_HSYNC_TYPE_DETECTION_FLAG_A7   		0xA7        // Hsync Type Detection Flag
#define _PB_STABLE_MEASURE_A8               	0xA8        // Stable Measure
#define _PB_STABLE_PERIOD_H_A9              	0xA9        // Stable Period HByte
#define _PB_STABLE_PERIOD_L_AA              	0xAA        // Stable Period LByte
#define _PB_MEAS_HS_PERIOD_H_AB             	0xAB        // HSync Period Measured Result HByte
#define _PB_MEAS_HS_PERIOD_L_AC             	0xAC        // HSync Period Measured Result LByte
#define _PB_MEAS_VS_PERIOD_H_AD             	0xAD        // VSync Period Measured Result HByte
#define _PB_MEAS_VS_PERIOD_L_AE             	0xAE        // VSync Period Measured Result LByte
#define _PB_MEAS_HS_VS_HIGH_PERIOD_H_AF     	0xAF        // HSync and VSync High Period Measured Results HByte
#define _PB_MEAS_HS_VS_HIGH_PERIOD_L_B0     	0xB0        // HSync and VSync High Period Measured Results LByte
#define _PB_MEAS_HS_VS_HI_SEL_B1            	0xB1        // HSync and VSync High Period Measured Select
//#define _PB_RESERVED_B2                     					0xB2        // PB Reserved B2
#define _PB_SYNC_TEST_MISC_B3               	0xB3        // Sync Test MISC Register
#define _PB_G_CLAMP_START_B4                	0xB4        // Clamp Signal Output Start of G Channel
#define _PB_G_CLAMP_END_B5                  	0xB5        // Clamp Signal Output End of G Channel
#define _PB_BR_CLAMP_START_B6               	0xB6        // Clamp Signal Output Start of R/B Channel
#define _PB_BR_CLAMP_END_B7                 	0xB7        // Clamp Signal Output End of R/B Channel
#define _PB_CLAMP_CTRL0_B8                  	0xB8        // Clamp Signal Control Register 0
#define _PB_CLAMP_CTRL1_B9                  	0xB9        // Clamp Signal Control Register 1
#define _PB_CLAMP_CTRL2_BA                  	0xBA        // Clamp Signal Control Register 2
#define _PB_CLAMP_CTRL3_BB                  	0xBB        // Clamp Signal Control Register 3
#define _PB_COAST_CTRL_BC                   	0xBC        // Coast Control Register
#define _PB_CAPTURE_WINDOW_SETTING_BD       	0xBD        // Capture Window Setting
#define _PB_DETECT_TOLERANCE_SETTING_BE     	0xBE        // Detection Tolerance Setting
#define _PB_SKIP_LINE_CTRL_BF               	0xBF        // Skip Line Control Register
#define _PB_SOYCH0_CFG3_C3						0xC3//eric 20070530
//-------------------------------------------------------
// SOG definition
//-------------------------------------------------------
#define _SOY_LEVEL					            0x20
#define _SOY_RESISTER				            2		// 0 ~ 3


//--------------------------------------------------
// Dynamic Contrast Control(Port)
//--------------------------------------------------
#define _DCC_CTRL0_E4                       	0xE4        // DCC Control Register0
#define _DCC_CTRL1_E5                       	0xE5        // DCC Control Register1
#define _DCC_ACCESS_PORT_E6                		0xE6        // DCC Access Port
#define _DCC_DATA_PORT_E7                   	0xE7        // DCC Data Port
//Address: E8~EF Reserved

//--------------------------------------------------
// CMDI(Port)
//--------------------------------------------------
#define _CMDI_ACCESS_PORT_F0                	0xF0        // CMDI Access Port
#define _CMDI_DATA_PORT_F1                  	0xF1        // CMDI Data Port

//--------------------------------------------------
// Cyclic Redundant Check(CRC)
//--------------------------------------------------
//#define _OP_CRC_CTRL_F2                     	0xF2        // Output CRC Control Register
//#define _OP_CRC_CHECKSUM_F3                 	0xF3        // Output CRC Checksum

//--------------------------------------------------
// DDC Special Function Access(DDC/CI)
//--------------------------------------------------
#define _DDC_SET_SLAVE_F4                   	0xF4        // DDC Set Slave Address
#define _DDC_SUB_IN_F5                      	0xF5        // DDC Sub Address Received
#define _DDC_DATA_IN_F6                     	0xF6        // DDC Data Received
#define _DDC_CTRL_F7                        	0xF7        // DDC Control Register
#define _DDC_STATUS_F8                      	0xF8        // DDC Status
#define _DDC_IRQ_CTRL_F9                    	0xF9        // DDC IRQ Control Register

//--------------------------------------------------
// DDC Channel (ADC/DVI)
//--------------------------------------------------
#define _DDC_ENABLE_FA                      	0xFA        // DDC Channel Enable Control Register
#define _DDC_INDEX_FB                       	0xFB        // DDC SRAM R/W Index Register
#define _DDC_ACCESS_PORT_FC                 	0xFC        // DDC Channel Access Port
#define _DDC_DVI_ENABLE_FD                  	0xFD        // DDC DVI Channel Enable Control Register
#define _DDC_DVI_INDEX_FE                   	0xFE        // DDC DVI SRAM R/W Index Register
#define _DDC_DVI_ACCESS_PORT_FF           		0xFF        // DDC DVI Channel Access Port



#endif
