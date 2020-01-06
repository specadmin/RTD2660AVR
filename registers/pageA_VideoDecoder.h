#ifndef PAGEA_VD_H
#define PAGEA_VD_H


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////   Page A: VD  /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGEA                                  0x0A

#define _PA_AUTO_MODE_TB1_A0                 	0xA0        //AutoMode Table 0
#define _PA_AUTO_MODE_TB2_A1                	0xA1        //AutoMode Table 1
#define _PA_AUTO_MODE_TB3_A2                 	0xA2        //AutoMode Table 2
#define _PA_AUTO_MODE_TB4_A3                 	0xA3        //AutoMode Table 3
#define _PA_AUTO_MODE_TB5_A4                 	0xA4        //AutoMode Table 4
#define _PA_AUTO_MODE_TB6_A5                 	0xA5        //AutoMode Table 5
#define _PA_AUTO_MODE_TB7_A6                 	0xA6        //AutoMode Table 6
#define _PA_AUTO_MODE_TB8_A7                 	0xA7        //AutoMode Table 7
#define _PA_AUTO_MODE_TB9_A8                 	0xA8        //AutoMode Table 8
#define _PA_625_FLAG_CNT_A9                  	0xA9        //625 Flag Counter
#define _PA_443_FLAG_CNT_AA                  	0xAA        //443 Flag Counter
#define _PA_SECAM_FLAG_CNT_AB                	0xAB        //SECAM Flag Counter
#define _PA_PALM_FLAG_CNT_AC                 	0xAC        //PALM Flag Counter
#define _PA_BURST_VLD_CNT_AD                 	0xAD        //Burst Magnitude not Vaild Counter
//Address: PA-AE ~ PA-AF Reserved
#define _PA_MIDPT_ADJ_B0                     	0xB0        //MidPoint adjustment
#define _PA_FREQ_FLAG_TH_B1                  	0xB1        //Frequence Flag Threshold
#define _PA_FREQ_VLD_MAX_B2                  	0xB2        //Frequence Valid Max
#define _PA_FREQ_VLD_INNER_B3                	0xB3        //Frequence Valid Inner
#define _PA_FREQ_VLD_MIN_B4                  	0xB4        //Frequence Valid Min
#define _PA_SECAM_FLAG_CNT_MAX_B5      			0xB5        //SECAM Flag Counter Max
#define _PA_SECAM_FLAG_CNT_MIN_B6      			0xB6        //SECAM Flag Counter Min
#define _PA_PALM_FLAG_PHASE_B7             		0xB7        //PALM Flag Phase
#define _PA_BURST_LOW_LIMIT_B8             		0xB8        //Burst Low Limit
#define _PA_BURST_MAG_CHOICE_B9           		0xB9        //Burst Magnitude Choice
#define _PA_BURST_MAG_STATUS_BA           		0xBA        //Burst Magnitude Status
#define _PA_FIFO_CTRL_BB                     	0xBB        //FIFO control
#define _PA_FIFO_STATUS_BC                   	0xBC        //FIFO Status
#define _PA_I_GAIN_CTRL_BD                   	0xBD        //I-Gain Control
#define _PA_MISC_CTRL_BE                     	0xBE        //Misc Control
#define _PA_FIFO_DEP_MIN_BF                 	0xBF        //FIFO Depth Min Status
#define _PA_FIFO_DEP_MAX_C0                  	0xC0        //FIFO Depth Max Status
#define _PA_HSYNC_PULSE_STA_C1             		0xC1        //Hsync Start Position
#define _PA_HSYNC_PULSE_WID_C2            		0xC2        //Hsync Width
#define _PA_CRESAMP_CTRL_C3                  	0xC3        //Chroma Hresampler Control
#define _PA_SECAM_CTRL_C4                    	0xC4        //SECAM Control
#define _PA_SECAM_DR_OFFSET_C5             		0xC5        //SECAM DR Offset
#define _PA_SECAM_DB_OFFSET_C6             		0xC6        //SECAM DB Offset
#define _PA_SECAM_HCOUNT_RST_C7          		0xC7        //Hcount Reset
#define _PA_PHASE_DIFF_DR_RST_C8          		0xC8        //Secam DR's Phase Diff from Cordic reset value
#define _PA_PHASE_DIFF_DB_RST_C9          		0xC9        //Secam DB's Phase Diff from Cordic reset value
#define _PA_DRDB_GAIN_TB_CA                  	0xCA        //Secam Gain DrDb Look Up Table
#define _PA_Y_GAIN_TB_CB                     	0xCB        //Secam Gain Y Look Up Table
#define _PA_SECAM_GAIN_DLY_CC               	0xCC        //Secam Y Delay For dr/db gain
#define _PA_SECAM_GAIN_TB_DBG_CD        		0xCD        //SECAM Gain Table Debug
//Address: PA-CE ~ PA-CF Reserved
#define _PA_LDPAUSE_CTL_D0                   	0xD0        //LD pause detected
#define _PA_VCR_OPT_D1                       	0xD1        //VCR Option
#define _PA_CEN_LINE_COUNT_D2                	0xD2        //Cenable Line Count
#define _PA_MEAS_1ST_V_HI_D3                 	0xD3        //Measure First V HI
#define _PA_MEAS_1ST_V_LOW_D4              		0xD4        //Measure First V LOW
#define _PA_MEAS_2ND_V_HI_D5                 	0xD5        //Measure Second V HI
#define _PA_MEAS_2ND_V_LOW_D6             		0xD6        //Measure Second V LOW
#define _PA_PORCH_HEIGHT_M_D7               	0xD7        //Porch Height Measurement MSB
#define _PA_PORCH_HEIGHT_L_D8               	0xD8        //Porch Height Measurement LSB
#define _PA_SINGAL_STM_CTL_D9                	0xD9        //Singal STM Conttrol
#define _PA_CDET_PHASE_ERR2_DA              	0xDA        //Chroma Detect Phase Error 2
#define _PA_CDET_PHASE_ERR1_DB              	0xDB        //Chroma Detect Phase Error 1
#define _PA_MV_DET_WIN_DC                    	0xDC        //MacroVision Detect Window
#define _PA_MV_BURST_STA_DD                  	0xDD        //MacroVision Burst Detect Window Start
#define _PA_MV_BURST_END_DE                  	0xDE        //MacroVision Burst Detect Window End
#define _PA_COLORSTRIPE_CTRL_DF            		0xDF        //ColorStripe Control
#define _PA_DBG_MUX_E0                       	0xE0        //Debug Mux
#define _PA_VD_DBG_ANALOG_E1                 	0xE1        //Video Debug Analog
#define _PA_VD_DBG_DIGITAL_E2                	0xE2        //Video Debug Digital
#define _PA_BIST_TEST1_E3                    	0xE3        //BIST Test 1
#define _PA_BIST_TEST2_E4                    	0xE4        //BIST Test 2
#define _RESERVED_E5                         	0xE5        //PA Reserved E5
#define _PA_PATTERN_CTRL_E6                  	0xE6        //Pattern Control
#define _PA_CRC_RLT2_E7                      	0xE7        //CRC Result 2
#define _PA_CRC_RLT1_E8                      	0xE8        //CRC Result 1
#define _PA_CRC_RLT0_E9                      	0xE9        //CRC Result 0
#define _RESERVED_EA                         	0xEA        //PA Reserved EA
#define _RESERVED_EB                         	0xEB        //PA Reserved EB
#define _PA_FPGA_TEST1_EC                    	0xEC        //FPGA Test1
#define _PA_FPGA_TEST2_ED                    	0xED        //FPGA Test2
#define _PA_FPGA_TEST3_EE                    	0xEE        //FPGA Test3
#define _PA_FPGA_TEST4_EF                    	0xEF        //FPGA Test4
#define _PA_CLAMP_TEST0_F0                   	0xF0        //Clamp Test Reg 0
#define _PA_CLAMP_TEST1_F1                   	0xF1        //Clamp Test Reg 1
#define _PA_CLAMP_TEST6_F2                   	0xF2        //Clamp Test Reg 6
#define _PA_CLAMP_TEST7_F3                   	0xF3        //Clamp Test Reg 7
#define _PA_CLAMP_TEST8_F4                   	0xF4        //Clamp Test Reg 8
#define _PA_CLAMP_TEST9_F5                   	0xF5        //Clamp Test Reg 9
#define _PA_CLAMP_TEST10_F6                  	0xF6        //Clamp Test Reg 10
#define _PA_CLAMP_TEST11_F7                  	0xF7        //Clamp Test Reg 11
#define _PA_CLAMP_TEST12_F8                  	0xF8        //Clamp Test Reg 12
#define _PA_CLAMP_TEST13_F9                  	0xF9        //Clamp Test Reg 13
#define _PA_CLAMP_TEST17_FA                  	0xFA        //Clamp Test Reg 17
#define _RESERVED_FB                         	0xFB        //PA Reserved FB
#define _RESERVED_FC                         	0xFC        //PA Reserved FC
#define _RESERVED_FD                         	0xFD        //PA Reserved FD
#define _PA_CHIP_VER1_FE                     	0xFE        //Chip Version MSB
#define _PA_CHIP_VER2_FF                     	0xFF        //Chip Version LSB


#endif // PAGEA_VD_H
