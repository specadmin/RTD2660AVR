#ifndef PAGE9_VD_H
#define PAGE9_VD_H


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////   Page 9: VD  //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


#define _PAGE9                                  0x09

#define _P9_AGC_PEAK_NOM_A0                  	0xA0        //AGC Peak Nominal
#define _P9_AGC_PEAK_GATE_CTRL_A1       		0xA1        //AGC Peak and Gate Control
#define _P9_AGC_PEAK_CTRL_A2                 	0xA2        //AGC Peak Control
#define _P9_VIDEO_CTRL2_A3                   	0xA3        //Video Control
#define _P9_LUMA_AGC_VALUE_A4               	0xA4        //Luma AGC Value
#define _P9_AGC_GATE_STA_M_A5               	0xA5        //Rough Gate Generator MSB
#define _P9_AGC_GATE_STA_L_A6                	0xA6        //Rough Gate Generator LSB
#define _P9_AGC_GATE_WID_A7                  	0xA7        //Rough Gate Width
#define _P9_AGC_BP_DELAY_A8                  	0xA8        //Sync Tip To Backproch Delay
#define _P9_CLAMP_COMP_NEW_TH2_A9    			0xA9        //ClampAGC CompLuma Threshold2
#define _P9_CLAMP_COMP_NEW_TH1_AA    			0xAA        //ClampAGC CompLuma Threshold1
#define _P9_CLAMP_COMP_NEW_CTRL_AB  			0xAB        //ClampAGC CompLuma New Control
#define _P9_VS_AGC_MIN_AC                    	0xAC        //Vsync AGC minimun
#define _P9_VS_AGC_LOCK_END_AD            		0xAD        //Vsync AGC LockOut End
#define _RESERVED_AE                         	0xAE        //P9 Reserved AE
#define _RESERVED_AF                         	0xAF        //P9 Reserved AF
#define _P9_CPUMP_DLY_CTRL_B0               	0xB0        //Charge Pump Delay Control
#define _P9_CPUMP_ADJ_B1                     	0xB1        //Charge Pump Delay Adjustment
#define _P9_CPUMP_DELAY_B2                   	0xB2        //Charge Pump Delay
#define _RESERVED_B3                         	0xB3        //P9 Reserved B3
#define _P9_CAGC_B4                          	0xB4        //Chrona AGC
#define _P9_CKILL_B5                         	0xB5        //Chroma Kill
#define _P9_C_LOCK_CONF_B6                   	0xB6        //Chroma Lock Configuation
#define _P9_CLOOP_GAIN_B7                    	0xB7        //Chroma LoopFilter Gain
#define _P9_CLOOP_STATE_B8                   	0xB8        //Chroma LoopFilter State
#define _P9_CAUTOPOS_B9                      	0xB9        //Chroma AutoPosition
//Address: P9-BA ~ P9-BF Reserved
#define _P9_LOCK_COUNT_C0                    	0xC0        //Lock Count
#define _P9_HLOOP_MAXSTATE_C1               	0xC1        //H Loop MaxState
#define _P9_CLAMP_CTRL0_C2                   	0xC2        //ClampAGC Control 0
#define _P9_CLAMP_NEWSYNC_STA_C3       			0xC3        //ClampAGC New Coarse Sync Start Position
#define _P9_CLAMP_NEWSYNC_END_C4      			0xC4        //ClampAGC New Coarse Sync End Position
#define _P9_CLAMP_NEWBP_STA_C5            		0xC5        //ClampAGC New Coarse Back Porch Start Position
#define _P9_CLAMP_NEWBP_END_C6           		0xC6        //ClampAGC New Coarse Back Porch End Position
#define _P9_HDET_PHASE_SEL_C7                	0xC7        //H Detect Phase Select
#define _P9_HDET_CNT_TIP_STA_C8           		0xC8        //H Detect Counter Tip Start
#define _P9_HDET_CNT_TIP_END_C9            		0xC9        //H Detect Counter Tip End
#define _P9_HDET_CNT_BP_STA_CA            		0xCA        //H Detect Counter Back Porch Start
#define _P9_HDET_CNT_BP_END_CB            		0xCB        //H Detect Counter Back Porch End
#define _P9_HPLL_INT_CTRL_CC                 	0xCC        //HPLL Integral Ctrl
#define _P9_HPHASE_ERR_STATUS_H_CD    			0xCD        //H Detect Phase Error Status High Byte
#define _P9_HPHASE_ERR_STATUS_L_CE     			0xCE        //H Detect Phase Error Status Low Byte
#define _RESERVED_CF                         	0xCF        //P9 Reserved CF
#define _P9_HS_RISING_D0                     	0xD0        //Hsync Rising Position
#define _P9_HS_PHASE_OFFSET_D1             		0xD1        //Hsync Phase Offset
#define _P9_HS_GATE_STA_D2                   	0xD2        //Hsync Gate Detect Window Start
#define _P9_HS_GATE_END_D3                   	0xD3        //Hsync Gate Detect Window End
#define _P9_HS_TIP_STA_D4                    	0xD4        //Hsync Tip Detect Window Start
#define _P9_HS_TIP_END_D5                    	0xD5        //Hsync Tip Detect Window End
#define _P9_HS_RISING_STA_D6                 	0xD6        //Hsync Rising Detect Window Start
#define _P9_HS_RISING_END_D7                 	0xD7        //Hsync rising Detect Window End
#define _P9_BP_START_D8                      	0xD8        //BackPorch Detect Window Start
#define _P9_BP_END_D9                        	0xD9        //BackPorch Detect Window End
#define _P9_HBLANK_STA_DA                    	0xDA        //Hblank Window Start
#define _P9_HBLANK_END_DB                    	0xDB        //Hblank Window End
#define _P9_BURST_GATE_STA_DC                	0xDC        //Burst Gate Window Start
#define _P9_BURST_GATE_END_DD               	0xDD        //Burst Gate Window End
#define _P9_HACT_STA_DE                      	0xDE        //Hactive Start
#define _P9_HACT_WID_DF                      	0xDF        //Hactive Width
#define _P9_VACT_STA_E0                      	0xE0        //Vactive Start
#define _P9_VACT_HEIGHT_E1                   	0xE1        //Vactive Height
#define _P9_VS_H_MIN_E2                      	0xE2        //HalfLine After Vsync Detect Max
#define _P9_VS_H_MAX_E3                      	0xE3        //HalfLine After Vsync Detect Min
#define _P9_VS_VBI_MIN_E4                    	0xE4        //HalfLine After Vsync Detect Min When VBI Data is vaild
#define _P9_VS_VBI_LOCK_END_E5              	0xE5        //VBI LockOut End
#define _P9_VS_CTRL_E6                       	0xE6        //Vsync Control
#define _P9_VS_TC_E7                         	0xE7        //Vsync Time Constant
#define _P9_VS_TC2_E8                        	0xE8        //Vsync Time Constant 2
#define _P9_VS_TC1_E9                        	0xE9        //Vsync Time Constant 1
#define _P9_SERR_TH_EA                       	0xEA        //Serration Detection Threshold
#define _P9_NO_SINGAL_DEC_EB                 	0xEB        //No Singal Counter Decrement Value
//Address: P9-EC ~ P9-EF Reserved
#define _P9_CDTO_INC4_F0                     	0xF0        //Chroma DTO INC4
#define _P9_CDTO_INC3_F1                     	0xF1        //Chroma DTO INC3
#define _P9_CDTO_INC2_F2                     	0xF2        //Chroma DTO INC2
#define _P9_CDTO_INC1_F3                     	0xF3        //Chroma DTO INC1
#define _P9_HDTO_INC4_F4                     	0xF4        //Hsync  DTO INC4
#define _P9_HDTO_INC3_F5                     	0xF5        //Hsync  DTO INC3
#define _P9_HDTO_INC2_F6                     	0xF6        //Hsync  DTO INC2
#define _P9_HDTO_INC1_F7                     	0xF7        //Hsync  DTO INC1
//Address: P9-F8 ~ P9-FF Reserved

#endif // PAGE9_VD1_H
