#ifndef PAGE6_DEINTERLACE_H
#define PAGE6_DEINTERLACE_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////   Page 6: De-interlace  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE6                                  0x06


//--------------------------------------------------
// De-interlace
//--------------------------------------------------
#define _P6_ENABLE_BIST_CTRL_A0             	0xA0        // Enable and Bist Control Register
#define _P6_INTERPOLATION_CTRL_A1           	0xA1        // Interpolation Control Register
#define _P6_PIXEL_DIFF_THRESHOLD_A2         	0xA2        // Pixel Difference Threshold
#define _P6_PIXEL_REF_DIFF_THRESHOLD_A3   		0xA3        // Pixel Reference Difference Threshold
#define _P6_GRADIENT_THRESHOLD_POS_A4      		0xA4        // Pixel Gradient Threshold Positive
#define _P6_GRADIENT_THRESHOLD_NEG_A5       	0xA5        // Pixel Gradient Threshold Negative

//--------------------------------------------------
// Post Processing Control
//--------------------------------------------------
#define _P6_SMOOTHING_ERROR_CORR_CTRL_A6 		0xA6        // Smoothing and Error Correction Control Register
#define _P6_DELETE_LINE_PIXEL_ENABLE_A7     	0xA7        // Delete Line and Pixel Enable
#define _P6_MEDIAN_FILTER_THRESHOLD_A8      	0xA8        // Median Filter Threshold

//--------------------------------------------------
// Noise Estimation
//--------------------------------------------------
#define _P6_HORIZONTAL_ACTIVE_SIZE_MSB_A9 		0xA9        // Horizontal Active Size MSB
#define _P6_HORIZONTAL_ACTIVE_SIZE_LSB_AA  		0xAA        // Horizontal Active Size LSB
#define _P6_VERTICAL_ACTIVE_SIZE_MSB_AB     	0xAB        // Vertical Active Size MSB
#define _P6_VERTICAL_ACTIVE_SIZE_LSB_AC     	0xAC        // Vertical Active Size LSB
#define _P6_CALCULATED_REGION_CTRL_AD       	0xAD        // Calculated Region Control Register
#define _P6_H1_ACTIVE_START_POINT_MSB_AE    	0xAE        // Horizontal Active Start Point 1 MSB
#define _P6_H1_ACTIVE_START_POINT_LSB_AF    	0xAF        // Horizontal Active Start Point 1 LSB
#define _P6_H1_ACTIVE_END_POINT_MSB_B0      	0xB0        // Horizontal Active End Point 1 MSB
#define _P6_H1_ACTIVE_END_POINT_LSB_B1      	0xB1        // Horizontal Active End Point 1 LSB
#define _P6_H2_ACTIVE_START_POINT_MSB_B2    	0xB2        // Horizontal Active Start Point 2 MSB
#define _P6_H2_ACTIVE_START_POINT_LSB_B3   		0xB3        // Horizontal Active Start Point 2 LSB
#define _P6_H2_ACTIVE_END_POINT_MSB_B4      	0xB4        // Horizontal Active End Point 2 MSB
#define _P6_H2_ACTIVE_END_POINT_LSB_B5      	0xB5        // Horizontal Active End Point 2 LSB
#define _P6_H3_ACTIVE_START_POINT_MSB_B6    	0xB6        // Horizontal Active Start Point 3 MSB
#define _P6_H3_ACTIVE_START_POINT_LSB_B7    	0xB7        // Horizontal Active Start Point 3 LSB
#define _P6_H3_ACTIVE_END_POINT_MSB_B8      	0xB8        // Horizontal Active End Point 3 MSB
#define _P6_H3_ACTIVE_END_POINT_LSB_B9      	0xB9        // Horizontal Active End Point 3 LSB
#define _P6_MIN_SPA_NOISE_VALUE_BIN1_BA     	0xBA        // Minimum Spatial Noise Value Within Bin1
#define _P6_MIN_SPA_NOISE_VALUE_BIN2_BB     	0xBB        // Minimum Spatial Noise Value Within Bin2
#define _P6_MIN_SPA_NOISE_VALUE_BIN3_BC     	0xBC        // Minimum Spatial Noise Value Within Bin3
#define _P6_MIN_SPA_NOISE_VALUE_BIN4_BD    		0xBD        // Minimum Spatial Noise Value Within Bin4
#define _P6_MIN_SPA_NOISE_VALUE_BIN5_BE     	0xBE        // Minimum Spatial Noise Value Within Bin5
#define _P6_MIN_SPA_NOISE_VALUE_BIN6_BF     	0xBF        // Minimum Spatial Noise Value Within Bin6
#define _P6_MIN_SPA_NOISE_VALUE_BIN7_C0     	0xC0        // Minimum Spatial Noise Value Within Bin7

//--------------------------------------------------
// Peaking and Coring and EMF/Chroma Lowpass
//--------------------------------------------------
#define _P6_PEAKING_ENABLE_C1               	0xC1        // Peaking Enable
#define _P6_PEAKING_DATA00_C2               	0xC2        // Peaking Data 00
#define _P6_PEAKING_DATA01_C3               	0xC3        // Peaking Data 01
#define _P6_PEAKING_DATA02_C4               	0xC4        // Peaking Data 02
#define _P6_PEAKING_DATA03_C5               	0xC5        // Peaking Data 03
#define _P6_PEAKING_DATA04_C6               	0xC6        // Peaking Data 04
#define _P6_PEAKING_DATA05_C7               	0xC7        // Peaking Data 05
#define _P6_PEAKING_DATA06_C8               	0xC8        // Peaking Data 06
#define _P6_PEAKING_DATA07_C9               	0xC9        // Peaking Data 07
#define _P6_PEAKING_DATA08_CA               	0xCA        // Peaking Data 08
#define _P6_PEAKING_DATA09_CB               	0xCB        // Peaking Data 09
#define _P6_PEAKING_DATA0A_CC               	0xCC        // Peaking Data 0A
#define _P6_PEAKING_DATA0B_CD               	0xCD        // Peaking Data 0B
#define _P6_CHROMA_LOWPASS_FACTOR_CE        	0xCE        // Peaking Chroma Lowpass Factor

//--------------------------------------------------
// YUV422 to YUV444 Conversion & 2 to 1 Setup
//--------------------------------------------------
#define _P6_YUV422_TO_YUV444_D4             	0xD4        // YUV422 to YUV444 Control Register
#define _P6_ACTIVE_BLANK_WINDOW_CTRL_MSB_D5 	0xD5        // Active Window & Blanking Window Control Register MSB
#define _P6_ACTIVE_WINDOW_CTRL_LSB_D6       	0xD6        // Active Window Control Register LSB
#define _P6_BLANK_WINDOW_CTRL_LSB_D7        	0xD7        // Blanking Window Control Register LSB

//--------------------------------------------------
// DCTi in I-Domain
//--------------------------------------------------
#define _P6_DCTI_1ST_GAIN_D8                	0xD8        // DCTi 1st Gain
#define _P6_DCTI_1ST_GAIN_THRESHOLD_D9      	0xD9        // DCTi 1st Gain Threshold

//--------------------------------------------------
// Noise Reduction in I-domain
//--------------------------------------------------
#define _P6_CP_CTRL_DA                      	0xDA        // CP Control Register
#define _P6_SPATIAL_CTRL_DB                 	0xDB        // Spatial Control Register
#define _P6_SPATIAL_THLY_DC                 	0xDC        // Spatial Threshold for Luma
#define _P6_SPATIAL_THLC_DD                 	0xDD        // Spatial Threshold for Chroma
#define _P6_IMPULSE_PIXEL_DIFF_THL_DE       	0xDE        // Impulse Pixel Diff Threshold
#define _P6_IMPULSE_THLY_DF                 	0xDF        // Impulse Threshold for Luma
#define _P6_IMPULSE_THLC_E0                 	0xE0        // Impulse Threshold for Chroma
#define _P6_IMPULSE_SMOOTH_THLY_E1          	0xE1        // Impulse Smooth Threshold for Luma
#define _P6_IMPULSE_SMOOTH_THLC_E2          	0xE2        // Impulse Smooth Threshold for Chroma

//--------------------------------------------------
// Scale Down
//--------------------------------------------------
#define _P6_UZD_CTRL0_E3                    	0xE3        // UZD Control Register 0
#define _P6_UZD_CTRL1_E4                    	0xE4        // UZD Control Register 1

#define _P6_UZD_SCALE_HOR_FACTOR_E5         	0xE5
#define _P6_UZD_SCALE_HOR_FACTOR_H_E5       	0xE5        // Horizontal Scale Factor HByte
#define _P6_UZD_SCALE_HOR_FACTOR_M_E6       	0xE6        // Horizontal Scale Factor MByte
#define _P6_UZD_SCALE_HOR_FACTOR_L_E7       	0xE7        // Horizontal Scale Factor LByte

#define _P6_UZD_SCALE_VER_FACTOR_E8       	    0xE8        // Vertical Scale Factor
#define _P6_UZD_SCALE_VER_FACTOR_H_E8       	0xE8        // Vertical Scale Factor HByte
#define _P6_UZD_SCALE_VER_FACTOR_M_E9       	0xE9        // Vertical Scale Factor MByte
#define _P6_UZD_SCALE_VER_FACTOR_L_EA       	0xEA        // Vertical Scale Factor LByte

#define _P6_UZD_HOR_DELTA1_H_EB             	0xEB        // Horizontal Non-Linear Delta1 HByte
#define _P6_UZD_HOR_DELTA1_L_EC             	0xEC        // Horizontal Non-Linear Delta1 LByte
#define _P6_UZD_HOR_SEGMENT1_H_ED           	0xED        // Horizontal Non-Linear Segment1 HByte
#define _P6_UZD_HOR_SEGMENT1_L_EE           	0xEE        // Horizontal Non-Linear Segment1 LByte
#define _P6_UZD_HOR_SEGMENT2_H_EF           	0xEF        // Horizontal Non-Linear Segment2 HByte
#define _P6_UZD_HOR_SEGMENT2_L_F0           	0xF0        // Horizontal Non-Linear Segment2 LByte
#define _P6_UZD_HOR_INITIAL_VALUE_F1        	0xF1        // Horizontal Scaling Initial Value
#define _P6_UZD_VER_INITIAL_VALUE_F2        	0xF2        // Vertical Scaling Initial Value
#define _P6_UZD_FIR_COEF_INDEX_F3           	0xF3        // Filter Coefficient Index
#define _P6_UZD_FIR_COEF_PORT_F4            	0xF4        // Filter Coefficient Port
#define _P6_UZD_CRC_CTRL_F5                 	0xF5        // CRC Control Register
#define _P6_UZD_CRC_HH_F6                   	0xF6        // CRC HHByte
#define _P6_UZD_CRC_H_F7                    	0xF7        // CRC HByte
#define _P6_UZD_CRC_M_F8                    	0xF8        // CRC MByte
#define _P6_UZD_CRC_L_F9                    	0xF9        // CRC LByte


#endif
