#ifndef PAGE1_PLL_H
#define PAGE1_PLL_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      Page 1: PLL     //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE1                                  0x01

//--------------------------------------------------
// DDS Setting For ADC PLL (Page1)
//--------------------------------------------------
#define _P1_PLL_DIV_CTRL_A0                 	0xA0        // PLL DIV Control Register
#define _P1_I_CODE_M_A1                     	0xA1        // I Code MByte
#define _P1_I_CODE_L_A2                     	0xA2        // I Code LByte
#define _P1_P_CODE_A3                       	0xA3        // P Code
//#define _P1_PFD_CALIBRATED_RESULTS_H_A4     	0xA4        // PFD Calibrated Result HByte
//#define _P1_PFD_CALIBRATED_RESULTS_L_A5     	0xA5        // PFD Calibrated Result LByte
//#define _P1_PE_MEASURE_H_A6                 	0xA6        // Phase Error Measure HByte
//#define _P1_PE_MEASURE_L_A7                 	0xA7        // Phase Error Measure LByte
//#define _P1_PE_MAX_MEASURE_H_A8             	0xA8        // Phase Error Max MEasure HByte
//#define _P1_PE_MAX_MEASURE_L_A9             	0xA9        // Phase Error Max MEasure LByte
#define _P1_FAST_PLL_CTRL_AA                	0xAA        // Fast PLL Control Register
#define _P1_FAST_PLL_ISUM_AB                	0xAB        // Fast PLL I_SUM

//--------------------------------------------------
// ADC PLL (Page1)
//--------------------------------------------------
#define _P1_PLL_M_AC                        	0xAC        // PLL M code
#define _P1_PLL_N_AD                        	0xAD        // PLL N Code
#define _P1_PLL_CRNT_AE                     	0xAE        // PLL Current/Resistor Register
#define _P1_PLL_WD_AF                       	0xAF        // PLL Watch Dog Register
#define _P1_MIX_B0                          	0xB0        // PLL Mix Register
#define _P1_PLLDIV_H_B1                     	0xB1        // PLL DIV HByte
#define _P1_PLLDIV_L_B2                     	0xB2        // PLL DIV LByte
//#define _P1_PLLPHASE_CTRL0_B3               	0xB3        // PLL Phase Control Register0
#define _P1_PLLPHASE_CTRL1_B4               	0xB4        // PLL Phase Control Register1
#define _P1_PLL_PHASE_INTERPOLATION_B5     		0xB5        // PLL Phase Interpolation
#define _P1_P_CODE_MAPPING_METHOD_B6      		0xB6        // P Code Mapping Method
#define _P1_PE_TRACKING_METHOD_B7           	0xB7        // PE Tracking Method
#define _P1_DDS_MIX_1_B8                    	0xB8        // DDS Mix 1
#define _P1_DDS_MIX_2_B9                    	0xB9        // DDS Mix 2
#define _P1_DDS_MIX_3_BA                    	0xBA        // DDS Mix 3
//#define _P1_DDS_MIX_4_BB                    	0xBB        // DDS Mix 4
//#define _P1_DDS_MIX_5_BC                    	0xBC        // DDS Mix 5
//#define _P1_DDS_MIX_6_BD                    	0xBD        // DDS Mix 6
//#define _P1_DDS_MIX_7_BE                    	0xBE        // DDS Mix 7
//--------------------------------------------------
// DPLL (Page1)
//--------------------------------------------------
#define _P1_DPLL_M_BF                       	0xBF        // DPLL M Divider

#define _P1_DPLL_N_C0                       	0xC0        // DPLL N Divider
#define _DPLL_DIV_1                             0
#define _DPLL_DIV_2                             1
#define _DPLL_DIV_4                             2
#define _DPLL_DIV_8                             3

#define _P1_DPLL_CRNT_C1                   	 	0xC1        // DPLL Current/Resistor Register
#define _DPLLVR_16K                             0
#define _DPLLVR_18K                             1
#define _DPLLVR_20K                             2
#define _DPLLVR_22K                             3

//--------------------------------------------------
// DCLK Spread Spectrum (Page1)
//--------------------------------------------------
#define _P1_DPLL_WD_C2                      	0xC2        // DPLL Watch Dog Register

#define _P1_DPLL_OTHER_C3                   	0xC3        // DPLL Other Register
#define _DPLL_REF_SOURCE_XTAL                   0
#define _DPLL_REF_SOURCE_M2PLL                  1

#define _P1_DCLK_FINE_C4                     	0xC4
#define _P1_DCLK_FINE_TUNE_OFFSET_MSB_C4    	0xC4        // Display Clock Fine Tune Offset MSB
#define _FREQ_UP                                0
#define _FREQ_DOWN                              1

#define _P1_DCLK_FINE_TUNE_OFFSET_LSB_C5    	0xC5        // Display Clock Fine Tune Offset LSB
#define _P1_DCLK_SPREAD_SPECTRUM_C6         	0xC6        // Display Clock Spread Spectrum
#define _P1_EVEN_FIX_LASTLINE_M_C7          	0xC7        // Even Fixed Last Line MSB
#define _P1_EVEN_FIX_LASTLINE_DVTOTAL_L_C8 		0xC8        // Even Fixed Last Line DVTotal LSB
#define _P1_EVEN_FIX_LASTLINE_LENGTH_L_C9   	0xC9        // Even Fixed Last Line Length LSB

#define _P1_EVEN_FIXED_LAST_LINE_CTRL_CA    	0xCA        // Fixed Last Line Control Register
#define _DPLL_OFFSET_ENABLED                    _bit(0)

//Address: P1-C4 ~ P1-CF Reserved

//--------------------------------------------------
// Multiply PLL For Input Crystal (Page1)
//--------------------------------------------------
#define _P1_MULTIPLY_PLL_CTRL0_E0           	0xE0        // M2PLL Control Register0
#define _P1_MULTIPLY_PLL_CTRL1_E1           	0xE1        // M2PLL Control Register1
#define _M2PLLVR_15K                             0
#define _M2PLLVR_18K                             1
#define _M2PLLVR_21K                             2
#define _M2PLLVR_24K                             3

#define _M2PLLWDV_0V8                            0
#define _M2PLLWDV_1V0                            1
#define _M2PLLWDV_1V2                            2
#define _M2PLLWDV_1V4                            3

//#define _P1_RESERVED_E2                     	0xE2        // P1 Reserved E2
//#define _P1_RESERVED_E3                     	0xE3        // P1 Reserved E3
#define _P1_MULTIPLY_POWER_DOWN_E4          	0xE4        // M2PLL Power Down
//Address: P1-E5 ~ P1-E9 Reserved
//#define _P1_PLL_CHARGE_PUMP_CURRENT_0_EA     	0xEA        // PLL Charge Pump Current 0
#define _P1_LOOP_FILTER_CAPACITOR_EB            0xEB        // PLL Loop Filter Capacitor
//#define _P1_PLL_CHARGE_PUMP_CURRENT_2_EC     	0xEC        // PLL Charge Pump Current 2
//Address: P1-ED ~ P1-FF Reserved


#endif // PAGE1_PLL_H
