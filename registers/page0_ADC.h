#ifndef PAGE0_ADC_H
#define PAGE0_ADC_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      Page 0: ADC     //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE0                                  0x00

//--------------------------------------------------
// Video ADC (Page0)
//--------------------------------------------------
#define _P0_VADC_SOY_COMPAR_A0           		0xA0        // VADC SOY Comparator Select
#define _P0_VADC_CTRL_A1                     	0xA1        // VADC Control Register
#define _P0_VADC_CLOCK_A2                    	0xA2        // VADC Clock Source
#define _P0_VADC_OUTPUT_DELAY_A3      			0xA3        // VADC Output Delay
//#define _P0_RESERVED_A4                     	0xA4        // P0 Reserved A4
#define _P0_VADC_INPUT_BW_A5                 	0xA5        // VADC Input BW
#define _P0_VADC1_INPUT_PGA_A6             		0xA6        // VADC1 Input PGA
#define _P0_VADC0_INPUT_PGA_A7             		0xA7        // VADC0 Input PGA
#define _P0_VADC_CLAMP_A8                    	0xA8        // VADC Clamp
#define _P0_VADC_INRANGE_A9                  	0xA9        // VADC Input Range
//#define _P0_RESERVED_AA                     		0xAA        // P0 Reserved AA
#define _P0_VADC1_SOY_BIAS_CUR_AB      			0xAB        // VADC1 SOY Bias Current
#define _P0_VADC_IN_CH_BIAS_CUR_AC     			0xAC        // VADC Input Channel Bias Current
#define _P0_VADC_POS_IN_SOY_RES_AD  			0xAD        // VADC Posive Input SOY Restore Resistor
#define _P0_VADC_CLAMP_POWER_AE         		0xAE        // VADC Clamp Power
#define _P0_VADC_SWITCH_AF                   	0xAF        // VADC/Video8 Switch

//--------------------------------------------------
// YPbPr ADC (Page0)
//--------------------------------------------------
#define _P0_RED_GAIN_C0                     	0xC0        // ADC Red Channel Gain Adjust
#define _P0_GRN_GAIN_C1                     	0xC1        // ADC Green Channel Gain Adjust
#define _P0_BLU_GAIN_C2                     	0xC2        // ADC Blue Channel Gain Adjust
#define _P0_RED_OFFSET_C3                 	 	0xC3        // ADC Red Channel Offset Adjust
#define _P0_GRN_OFFSET_C4                   	0xC4        // ADC Green Channel Offset Adjust
#define _P0_BLU_OFFSET_C5                   	0xC5        // ADC Blue Channel Offset Adjust
#define _P0_ADC_POWER_C6                   		0xC6        // ADC Power Control Register
#define _P0_ADC_I_BAIS0_C7                  	0xC7        // ADC Bais Current Control Register0
#define _P0_ADC_I_BAIS1_C8                  	0xC8        // ADC Bais Current Control Register1
#define _P0_ADC_I_BAIS2_C9                  	0xC9        // ADC Bais Current Control Register2
#define _P0_ADC_V_BAIS0_CA                  	0xCA        // ADC Bais Voltage Control Register0
#define _P0_ADC_V_BAIS1_CB                  	0xCB        // ADC Bais Voltage Control Register1
#define _P0_ADC_CLOCK_CTRL_CC               	0xCC        // ADC Clock Control Register
#define _P0_ADC_TEST_CTRL_CD                	0xCD        // ADC Test Control Register
#define _P0_ADC_RGB_CTRL_CE                 	0xCE        // ADC RGB Control Register
#define _P0_ADC_RED_CTL_CF                  	0xCF        // ADC Red Channel Control Register
#define _P0_ADC_GREEN_CTL_D0                	0xD0        // ADC Green Channel Control Register
#define _P0_ADC_BLUE_CTL_D1                 	0xD1        // ADC Blue Channel Control Register
#define _P0_ADC_SOG0_CTRL_D2               		0xD2        // ADC SOG0 Reference Control Register
#define _P0_ADC_DCR_CTRL_D3                 	0xD3        // ADC DCR Reference Control Register
#define _P0_ADC_CLAMP_CTRL0_D4             		0xD4        // ADC Clamp Control Register0
#define _P0_ADC_CLAMP_CTRL1_D5             		0xD5        // ADC Clamp Control Register1
#define _P0_ADC_SOG_CTRL_D6                 	0xD6        // ADC SOG Control Register
//#define _P0_TEST_PTN_POS_H_D7              	0xD7        // Test Pattern H/V Position HByte
//#define _P0_TEST_PTN_VPOS_L_D8              	0xD8        // Assign the test pattern digitized position(LByte) in line after V_Start.
//#define _P0_TEST_PTN_HPOS_L_D9              	0xD9        // Assign the test pattern digitized position(LByte) in line after H_Start.
//#define _P0_TEST_PTN_RD_DA                  	0xDA        // Test Pattern Red Channel Digitized Result
//#define _P0_TEST_PTN_GD_DB                  	0xDB        // Test Pattern Green Channel Digitized Result
//#define _P0_TEST_PTN_BD_DC                  	0xDC        // Test Pattern Blue Channel Digitized Result

//--------------------------------------------------
// Auto Black Level (Page0)
//--------------------------------------------------
#define _P0_ABL_CTRL1_E2                    	0xE2        // Auto Black Level Control Register1
#define _P0_ABL_CTRL2_E3                    	0xE3        // Auto Black Level Control Register2
#define _P0_ABL_CTRL3_E4                    	0xE4        // Auto Black Level Control Register3
#define _P0_ABL_CTRL4_E5                    	0xE5        // Auto Black Level Control Register4
#define _P0_ABL_CTRL5_E6                    	0xE6        // Auto Black Level Control Register5
#define _P0_ABL_CTRL6_E7                    	0xE7        // Auto Black Level Control Register6
#define _P0_ABL_CTRL7_E8                    	0xE8        // Auto Black Level Control Register6
//#define _P0_ABL_R_VALUE_E9                  	0xE9        // Auto Black Level Value of Red Channel in Test Mode
//#define _P0_ABL_G_VALUE_EA                  	0xEA        // Auto Black Level Value of Green Channel in Test Mode
//#define _P0_ABL_B_VALUE_EB                  	0xEB        // Auto Black Level Value of Blue Channel in Test Mode
//#define _P0_ABL_R_NOISE_VALUE_EC           	0xEC        // Auto Black Level Noise Value of Red Channel in Test Mode
//#define _P0_ABL_G_NOISE_VALUE_ED           	0xED        // Auto Black Level Noise Value of Green Channel in Test Mode
//#define _P0_ABL_B_NOISE_VALUE_EE           	0xEE        // Auto Black Level Noise Value of Blue Channel in Test Mode

//Address: P0-EF ~ P0-F2 Reserved

//--------------------------------------------------
// Low Voltage Reset (Page0)
//--------------------------------------------------
#define _P0_POWER_ON_RESET_F3               	0xF3        // Negative Threshold Value For Power On Reset

//--------------------------------------------------
// Schmitt Trigger Control (Page0)
//--------------------------------------------------
#define _P0_HS_SCHMITT_TRIGGER_CTRL_F4     		0xF4        // Schmitt Trigger Control Register
//Address: P0-F5 ~ P0-FF Reserved


#endif
