#ifndef PAGE2_HDMI_H
#define PAGE2_HDMI_H


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  Page 2: TMDS/HDCP/HDMI  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE2                                  0x02

//--------------------------------------------------
// TMDS Receiver(Page 2)
//--------------------------------------------------
//#define _P2_RESERVED_A0                     	0xA0        // P2 Reserved A0
#define _P2_TMDS_MEAS_SELECT_A1           		0xA1        // TMDS Measure Select
#define _P2_TMDS_MEAS_RESULT0_A2         		0xA2        // TMDS Measure Result0
#define _P2_TMDS_MEAS_RESULT1_A3         		0xA3        // TMDS Measure Result1
#define _P2_TMDS_CTRL_A4                    	0xA4        // TMDS Control Register
#define _P2_CRC_OUTPUT_BYTE_2_A5         		0xA5        // CRC Output Byte2
#define _P2_TMDS_OUTPUT_CTRL_A6           		0xA6        // TMDS Output Control Register
#define _P2_POWER_ON_OFF_CTRL_A7       			0xA7        // TMDS Power On/Off Control Register
#define _P2_ANALOG_COMMON_CTRL0_A8  			0xA8        // Analog Common Control Register 0
#define _P2_ANALOG_COMMON_CTRL1_A9  			0xA9        // Analog Common Control Register 1
#define _P2_ANALOG_BIAS_CTRL_AA            		0xAA        // Analog Bias Control Register
#define _P2_ANALOG_COMMON_CTRL2_AB  			0xAB        // Analog Common Control Register 2
#define _P2_Z0_CALIBRATION_CTRL_AC       		0xAC        // Z0 Calibration Control Register
#define _P2_CLOCK_PLL_SETTING_AD          		0xAD        // Clock PLL Setting
#define _P2_RGB_PLL_SETTING_AE              	0xAE        // R/G/B PLL Setting
#define _P2_WATCH_DOG_CTRL_AF              		0xAF        // Watch Dog Control Register
#define _P2_CDR_CTRL0_B0                    	0xB0        // CDR Control Register 0
#define _P2_CDR_CTRL1_B1                    	0xB1        // CDR Control Register 1
#define _P2_CDR_CTRL2_B2                    	0xB2        // CDR Control Register 2
#define _P2_UP_DOWN_ADJUSTING1_B3     			0xB3        // Up/Down Adjusting 1
#define _P2_ADAPTIVE_EQUALIZER_B4         		0xB4        // Adaptive Equalizer
#define _P2_UP_DOWN_CTRL0_B5                	0xB5        // Up/Down Control Register 0
#define _P2_UP_DOWN_CTRL1_B6                	0xB6        // Up/Down Control Register 1
#define _P2_UP_DOWN_CTRL2_B7                	0xB7        // Up/Down Control Register 2
#define _P2_ADAPTIVE_EQUALIZER2_B8      		0xB8        // Adaptive Equalizer accumulative threshold (LPF1)//731301
//#define _P2_ADAPTIVE_EQUALIZER3_B9        	0xB9        // Adaptive Equalizer continuous threshold (LPF2)
//#define _P2_ADAPTIVE_EQUALIZE4_BA          	0xBA        // Adaptive Equalizer auto stop threshold

//--------------------------------------------------
// HDCP1.1(Port)
//--------------------------------------------------
#define _P2_HDCP_CTRL_C0                    	0xC0        // HDCP Control Register
#define _P2_DEVICE_KEY_ACCESS_PORT_C1   		0xC1        // Device Key Access Port
#define _P2_HDCP_PORT_CTRL_C2		        	0xC2        // HDCP Port Control Register
#define _P2_HDCP_ADDR_PORT_C3               	0xC3        // HDCP Address Port
#define _P2_HDCP_DATA_PORT_C4               	0xC4        // HDCP Data Port
//Address: P2-C5~P2-C6 Reserved

//--------------------------------------------------
// HDMI(Port)
//--------------------------------------------------
#define _P2_HDMI_APC_C8                     	0xC8        //
#define _P2_HDMI_ADDR_PORT_C9               	0xC9        // HDMI Address Port
#define _P2_HDMI_DATA_PORT_CA               	0xCA        // HDMI Data Port
/****** _P2_HDMI_DATA_PORT_CA port addresses ******/
#define _P2_HDMI_SCR_00                     	0x00        // HDMI Switch Control Register
//#define _P2_HDMI_N_VAL_01                   	0x01        // HDMI N Value Register
//#define _P2_HDMI_BCHCR_02                   	0x02        // HDMI BCH Control Register
#define _P2_HDMI_AFCR_03                      	0x03        // HDMI Audio FIFO Control Register
//#define _P2_HDMI_AFSR_04                    	0x04        // HDMI Audio FIFO BIST Start Register
//#define _P2_HDMI_MAGCR0_05                  	0x05        // HDMI Maunal Gain Control Register0
//#define _P2_HDMI_MAGCR1_06                  	0x06        // HDMI Maunal Gain Control Register1
//Address: 07...0F Reserved
#define _P2_HDMI_CMCR_10                      	0x10        // HDMI Input Clock MUX Control Register
#define _P2_HDMI_MCAPR_11                     	0x11        // HDMI M code
#define _P2_HDMI_SCAPR_12                     	0x12        // HDMI S code
#define _P2_HDMI_DCAPR0_13                    	0x13        // HDMI D code HByte
#define _P2_HDMI_DCAPR1_14                    	0x14        // HDMI D code LByte
#define _P2_HDMI_PSCR_15                      	0x15        // HDMI Phase Tracking Enable Control Register
#define _P2_HDMI_FTR_1A                       	0x1A        // HDMI Target Time For Summation Of One Trent To Decide The Trent
#define _P2_HDMI_FBR_1B                       	0x1B        // HDMI Target FIFO Depth and Boundary Address Distance
#define _P2_HDMI_ICTPSR1_21                   	0x21        // HDMI I Code of Trend
#define _P2_HDMI_ICBPSR1_25                   	0x25        // HDMI I Code of Boundary
#define _P2_HDMI_PCBPSR0_26                   	0x26        // HDMI P Code of Boundary HByte
#define _P2_HDMI_PCBPSR1_27                   	0x27        // HDMI P Code of Boundary LByte
#define _P2_HDMI_NTX1024TR0_28                	0x28        // HDMI Masure the length of 1024 TV by Crystal
#define _P2_HDMI_STBPR_2A                     	0x2A        // HDMI Boundary Tracking Update Response Time
#define _P2_HDMI_AAPNR_2D                     	0x2D        // HDMI Phase Swallow Enable Control Register
#define _P2_HDMI_AVMCR_30                     	0x30        // HDMI Audio/Video Mute Control Register
#define _P2_HDMI_WDCR0_31                     	0x31        // HDMI Watch Dog Control Register0
#define _P2_HDMI_WDCR1_32                     	0x32        // HDMI Watch Dog Control Register1
#define _P2_HDMI_DBCR_34                      	0x34        // HDMI Auto Load Double Buffer Enable
#define _P2_HDMI_DPCR0_38                     	0x38        // HDMI DPLL Control Register0
#define _P2_HDMI_DPCR1_39                     	0x39        // HDMI DPLL Control Register1
#define _P2_HDMI_DPCR3_3B                     	0x3B        // HDMI DPLL Control Register3
#define _P2_HDMI_VWDSR_41                     	0x41        // HDMI Video Watch Dog For Packet Variation Status
#define _P2_HDMI_PVGCR0_45                    	0x45        // HDMI Packet Variation Status Enable Control Register0
#define _P2_HDMI_VCR_50                       	0x50        // HDMI Video Mode Control Register
#define _P2_HDMI_ACRCR_51                     	0x51        // HDMI Color Space Control Register0
#define _P2_HDMI_ACRSR0_52                    	0x52        // HDMI CTS in usage Register(CTS[19:12])
#define _P2_HDMI_AOCR_62                      	0x62        // HDMI SPDIF/I2S Switch Control Register
/** end of _P2_HDMI_DATA_PORT_CA port addresses ***/
#define _P2_HDMI_SR_CB                      	0xCB        // HDMI Status Register
#define _P2_HDMI_GPVS_CC                    	0xCC        // HDMI Packet Variation Status Register
#define _P2_HDMI_PSAP_CD                    	0xCD        // HDMI Address For Packet Storage SRAM
#define _P2_HDMI_DSAP_CE                    	0xCE        // HDMI Data For Packet Storage SRAM
//Address: P2-CF ~ P2-FF Reserved


#endif
