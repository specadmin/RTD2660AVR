#ifndef PAGE7_VIVIDCOLOR_H
#define PAGE7_VIVIDCOLOR_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////   Page 7: Vivid Color  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE7                                  0x07

//--------------------------------------------------
// Vivid Color - DLTi/DCTi
//--------------------------------------------------
//#define _P7_RESERVED_A0                     	0xA0        // P7 Reserved A0
#define _P7_DLTI_DCTI_ENABLE_A1             	0xA1        // DLTi DCTi Enable
#define _P7_DLTI_HF_THRESHOLD_A2            	0xA2        // DLTi HF Threshold
#define _P7_DLTI_GAIN_A3                    	0xA3        // DLTi Gain
#define _P7_DLTI_GAIN_THRESHOLD_A4       		0xA4        // DLTi Gain Threshold
#define _P7_DLTI_OPTIONS_A5                 	0xA5        // DLTi Options
#define _P7_DCTI_1ST_GAIN_A6                	0xA6        // DCTi 1st Gain
#define _P7_DCTI_1ST_GAIN_THRESHOLD_A7    		0xA7        // DCTi 1st Gain Threshold
//#define _P7_RESERVED_A8                     	0xA8        // P7 Reserved A0

//--------------------------------------------------
// Peaking and Coring and EMF/Chroma Lowpass
//--------------------------------------------------
#define _P7_PEAKING_ENABLE_A9               	0xA9        // Peaking Enable
#define _P7_PEAKING_DATA00_AA               	0xAA        // Peaking Data 00
#define _P7_PEAKING_DATA01_AB               	0xAB        // Peaking Data 01
#define _P7_PEAKING_DATA02_AC               	0xAC        // Peaking Data 02
#define _P7_PEAKING_DATA03_AD               	0xAD        // Peaking Data 03
#define _P7_PEAKING_DATA04_AE               	0xAE        // Peaking Data 04
#define _P7_PEAKING_DATA05_AF               	0xAF        // Peaking Data 05
#define _P7_PEAKING_DATA06_B0               	0xB0        // Peaking Data 06
#define _P7_PEAKING_DATA07_B1               	0xB1        // Peaking Data 07
#define _P7_PEAKING_DATA08_B2               	0xB2        // Peaking Data 08
#define _P7_PEAKING_DATA09_B3               	0xB3        // Peaking Data 09
#define _P7_PEAKING_DATA0A_B4               	0xB4        // Peaking Data 0A
#define _P7_PEAKING_DATA0B_B5               	0xB5        // Peaking Data 0B
#define _P7_CHROMA_LOWPASS_FACTOR_B6     		0xB6        // Peaking Chroma Lowpass Factor

//--------------------------------------------------
// Auto Sharpness
//--------------------------------------------------
#define _P7_AUTO_SHP_CTRL_B7                	0xB7        // Auto Sharpness Control Register
#define _P7_AUTO_SHP_ADDR_B8                	0xB8        // Noise Reduction and Sharpness Port Address
#define _P7_AUTO_SHP_DATA_B9                	0xB9        // Auto Sharpness DATA Port

//Address: P7-BA ~ P7-BE Reserved

//--------------------------------------------------
// Vivid Color - Video Color Space Conversion
//--------------------------------------------------
#define _P7_YUV2RGB_CTRL_BF                 	0xBF        // YUV2RGB Control Register
#define _P7_YUV2RGB_ACCESS_C0               	0xC0        // YUV2RGB Access Port
#define _P7_YUV2RGB_DATA_C1                 	0xC1        // YUV2RGB Data Port

//Address: P7-C2 ~ P7-C6 Reserved

//--------------------------------------------------
// Vivid Color - DCC
//--------------------------------------------------
#define _P7_DCC_CTRL0_C7                    	0xC7        // DCC Control Register 0
#define _P7_DCC_CTRL1_C8                    	0xC8        // DCC Control Register 1
#define _P7_DCC_ACCESS_PORT_C9              	0xC9        // DCC Access Port
#define _P7_DCC_DATA_PORT_CA                	0xCA        // DCC Data Port

//Address: P7-CB ~ P7-CF Reserved

//--------------------------------------------------
// Vivid Color - ICM
//--------------------------------------------------
#define _P7_ICM_CTRL_D0                     	0xD0        // ICM Control Register
#define _P7_ICM_SEL_D1                      	0xD1        // ICM Accessing Through Data Port Select
#define _P7_ICM_ACCESS_PORT_D2              	0xD2        // ICM Access Port
#define _P7_ICM_DATA_PORT_D3                	0xD3        // ICM Data Port
#define _P7_PC_ACCESS_PORT_D6					0xD6		 //peaking & coring Access Port
#define _P7_PC_DATA_PORT_D7						0xD7		//peaking & coring Access data Port


#endif
