#ifndef PAGE8_VD_H
#define PAGE8_VD_H


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////   Page 8: VD  //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE8                                  0x08

#define _P8_VIDEO_CTRL0_A0                   	0xA0        // Video Control 0
#define _P8_VIDEO_CTRL1_A1                   	0xA1        // Video Control 1
#define _P8_CLAMP_UPDN_EN_A2                 	0xA2        // ADC Switch Control
#define _P8_AGC_GATE_TH_SWAP_A3          		0xA3        // AGC Gate TH Swap
#define _P8_INOUT_CTRL_A4                    	0xA4        // Inout Control
//#define _RESERVED_A5                       	0xA5        // P8 Reserved A5
//#define _RESERVED_A6                       	0xA6        // P8 Reserved A6
#define _P8_OUTPUT_CTRL_A7                  	0xA7        // Output Control
#define _P8_CONTRAST1_A8                     	0xA8        // Luma Contrast Adjust
#define _P8_BRIGHTNESS1_A9                   	0xA9        // Luma Brightness Adjust
#define _P8_SATURATION1_AA                   	0xAA        // Chroma Saturation Adjust
#define _P8_HUE_AB                          	0xAB        // Chroma Hue Phase Adjust
#define _P8_DC_HACTIVE_START_AC            		0xAC        // DC Hactive Start
#define _P8_DC_VACTIVE_START_AD            		0xAD        // DC Vactive Start
#define _P8_THRESHOLD_AE                     	0xAE        // DC Threshold
#define _P8_DC_POSITIVE_GAIN_AF             	0xAF        // DC Positive Gain
#define _P8_NEGATIVE_GAIN_B0                 	0xB0        // DC Negetive Gain
#define _P8_YDC_STATUS_B1                    	0xB1        // YDC Status
#define _P8_YDC_AVERAGE_STATUS_B2       		0xB2        // YDC Average Status
#define _P8_DC_BALANCE_CTRL0_B3            		0xB3        // DC Balance Control 0
#define _P8_DC_BALANCE_CTRL1_B4            		0xB4        // DC Balance Control 1
#define _P8_IRQ_MASK1_B5                     	0xB5        // IRQ Mask 1
#define _P8_IRQ_MASK2_B6                     	0xB6        // IRQ Mask 2
#define _P8_IRQ_STATUS1_B7                   	0xB7        // IRQ Status 1
#define _P8_IRQ_STATUS1_WCLR_B8           		0xB8        // IRQ Status 1 write 1 to clear
#define _P8_IRQ_STATUS2_B9                   	0xB9        // IRQ Status 2
#define _P8_IRQ_STATUS1_WCLR_BA           		0xBA        // IRQ Status 2write 1 to clear
#define _P8_ADC_LIMIT_TH_BB                  	0xBB        // ADC Limit Threshold
#define _P8_VD_STATUS1_BC                    	0xBC        // Video Status Register1
#define _P8_VD_STATUS2_BD                    	0xBD        // Video Status Register2
#define _P8_VD_STATUS3_BE                    	0xBE        // Video Status Register3
#define _P8_NOISE_TH_BF                      	0xBF        // Noise Threshold
#define _P8_HDTO_INC_STATUS4_C0           		0xC0        // HDTO Inc Status 4
#define _P8_HDTO_INC_STATUS3_C1           		0xC1        // HDTO Inc Status 3
#define _P8_HDTO_INC_STATUS2_C2           		0xC2        // HDTO Inc Status 2
#define _P8_HDTO_INC_STATUS1_C3           		0xC3        // HDTO Inc Status 1
#define _P8_CDTO_INC_STATUS4_C4           		0xC4        // CDTO Inc Status 4
#define _P8_CDTO_INC_STATUS3_C5           		0xC5        // CDTO Inc Status 3
#define _P8_CDTO_INC_STATUS2_C6           		0xC6        // CDTO Inc Status 2
#define _P8_CDTO_INC_STATUS1_C7           		0xC7        // CDTO Inc Status 1
#define _P8_AGAIN_STATUS_C8                  	0xC8        // Digital ADC Gain Value Hight byte
#define _P8_DGAIN_STATUS_C9                  	0xC9        // Digital ADC Gain Value Low byte
#define _P8_CMAG_STATUS_CA                   	0xCA        // Chroma Magnitude
#define _P8_CMAG_STATUS2_CB                  	0xCB        // Chroma Gain High Byte
#define _P8_CMAG_STATUS1_CC                  	0xCC        // Chroma Gain Low Byte
#define _P8_CORDIC_FREQ_STATUS_CD       		0xCD        // SECAM Cordic Frequency
#define _P8_NOISE_STATUS_CE                  	0xCE        // Noise Status
#define _P8_SOFT_RESET_CF                    	0xCF        // Video Soft Reset
#define _P8_PALM_COMP1_D0                    	0xD0        // Palm Flag Compensation Counter.
#define _P8_PALM_COMP2_D1                    	0xD1        // Palm Flag Compensation Threshold
#define _P8_MANUAL_MODE_D2                   	0xD2        // AUTO Manual Mode Setting
#define _P8_MODE_DET_STATUS_D3             		0xD3        // Mode Detect Status
#define _P8_STA_AND_DIS_MODE_D4          		0xD4        // Statistc and Disable Mode
#define _P8_PREFER_MODE_D5                   	0xD5        // Prefer Mode
#define _P8_STM_FIX_MODE_D6                  	0xD6        // State Machine Fix mode
#define _P8_ZORAN_REG_EN_D7                  	0xD7        // Zoran Register Enable
#define _P8_AUTO_MODE_STM_STA_D8       			0xD8        // AUTO Mode State Machine Statistic
//#define _RESERVED_D9                       	0xD9        // P8 Reserved D9
#define _P8_COMB_FLT_CONF_DA                 	0xDA        // COMB Filter Config
#define _P8_COMB_FLT_TH1_DB                  	0xDB        // COMB Filter Threshold 1
#define _P8_COMB_FLT_TH2_DC                  	0xDC        // COMB Filter Threshold 2
#define _P8_COMB_FLT_TH3_DD                  	0xDD        // COMB Filter Threshold 3
#define _P8_COMB_FLT_TH4_DE                  	0xDE        // COMB Filter Threshold 4
//#define _RESERVED_DF                       	0xDF        // P8 Reserved DF
#define _P8_YCSEP_CTRL_E0                    	0xE0        // YC Seperate Control
#define _P8_BPF_BW_SEL_Y_E1                  	0xE1        // BPF BandWidth Select Y
#define _P8_BPF_BW_SEL_C_E2                  	0xE2        // BPF BandWidth Select C
#define _P8_ADAP_BPF_C_TH1_E3                	0xE3        // Chroma Adaptive BPF Detection Threshold 1
#define _P8_ADAP_BPF_C_TH2_E4                	0xE4        // Chroma Adaptive BPF Detection Threshold 2
#define _P8_ADAP_BPF_C_TH3_E5                	0xE5        // Chroma Adaptive BPF Detection Threshold 3
#define _P8_ADAP_BPF_C_TH4_E6                	0xE6        // Chroma Adaptive BPF Detection Threshold 4
#define _P8_ADAP_BPF_Y_TH1_E7                	0xE7        // Threshold 1 for Y Adaptive BPF detection
#define _P8_ADAP_BPF_Y_TH2_E8                	0xE8        // Threshold 2 for Y Adaptive BPF detection
#define _P8_ADAP_BPF_Y_TH3_E9                	0xE9        // Threshold 3 for Y Adaptive BPF detection
#define _P8_YC_BW_CTRL_EA                    	0xEA        // YC BandWidth Control
#define _P8_2D_DEBUG_MODE_EB                 	0xEB        // 2D Debug Mode
#define _P8_RESOL_LP_TH_EC                   	0xEC        // RESOL LP TH
#define _P8_ENVELOPE_TH_ED                   	0xED        // ENVELOPE TH
#define _P8_COMB_FLT_TH5_EE                		0xEE        // Comb Filter THR5
//#define _RESERVED_EF                       	0xEF        // P8 Reserved EF
#define _P8_BW_DETECTION_F0                  	0xF0        // Band Width Detection
#define _P8_BW_EDGE_THR_F1                   	0xF1        // Band Width Edge Threshold
#define _P8_2D_ALPHA_MOD_ENABLE_F2   			0xF2        // 2D ALPHA Mode Enable
#define _P8_H2V_CORING_THR_F3               	0xF3        // H2V Coring Threshold
#define _P8_H2V_Y_NOISE_THR_F4             		0xF4        // H2V Y Noise Threshold
#define _P8_H2V_CVBS_NOISE_THR_F5       		0xF5        // H2V CVBS Noise Threshold
#define _P8_1D_BLEND_THR_F6                  	0xF6        // 1D Blend Threshold
#define _P8_1D_BLEND_BPF_SEL_Y_F7       		0xF7        // 1D Blend BPF Select for Y
#define _P8_1D_BLEND_BPF_SEL_C_F8       		0xF8        // 1D Blend BPF Select for C

//Address: P8-F9 ~ P8-FF Reserved


#endif // PAGE8_VD1_H
