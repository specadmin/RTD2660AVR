#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////   Common registers  //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------
// Global Event Flag
//--------------------------------------------------
#define _ID_REG_00                          	0x00        // ID Code Register
#define _HOST_CTRL_01                       	0x01        // Host Control Register
// reserved                                     _bits(7)
#define _RESET_CHECK                            _bits(6)
// reserved                                     _bits(5)
// reserved                                     _bits(4)
// reserved                                     _bits(3)
#define _POWER_DOWN_MODE_ENABLED                _bits(2)
#define _POWER_SAVING_MODE_ENABLED              _bits(1)
#define _WHOLE_CHIP_RESET                       _bits(0)


#define _STATUS0_02                         	0x02        // Status0 Register
#define _STATUS1_03                         	0x03        // Status1 Register
#define _IRQ_CTRL0_04                       	0x04        // IRQ Control Register0
#define _HDMI_STATUS0_05                    	0x05        // HDMI Status0 Register

#define _NEW_ADDED_STATUS0_07        			0x07        // NEW Added Status0 Register
#define _NEW_ADDED_STATUS1_08					0x08        // NEW Added Status1 Register


//#define _HDMI_STATUS1_06                    		0x06        // HDMI Status1 Register
//Address: 07~0B Reserved
#define _WATCH_DOG_CTRL0_0C              		0x0C        // Watch Dog Control Register0
#define _WATCH_DOG_CTRL1_0D         			0x0D        // Watch Dog Control Register1
//Address: 0E~0F Reserved
#define _VGIP_CTRL_10                       	0x10        // Video Graphic Input Port(VGIP) Control Register
#define _VGIP_SIGINV_11                     	0x11        // Input Control Signal Inverted Register
#define _VGIP_DELAY_CTRL_12                 	0x12        // VGIP Delay Control Register
#define _VGIP_ODD_CTRL_13                   	0x13        // VGIP Odd Control Register

//--------------------------------------------------
// Input Frame Window
//-------------------------------------------------
#define _INPUT_FRAME_CONFIG_14                  0x14
#define _IPH_ACT_STA_H_14                   	0x14        // Input Horizontal Active Start HByte
#define _IPH_ACT_STA_L_15                   	0x15        // Input Horizontal Active Start LByte
#define _IPH_ACT_WID_H_16                   	0x16        // Input Horizontal Active Width HByte
#define _IPH_ACT_WID_L_17                   	0x17        // Input Horizontal Active Width LByte
#define _IPV_ACT_STA_H_18                   	0x18        // Input Vertical Active Start HByte
#define _IPV_ACT_STA_L_19                   	0x19        // Input Vertical Active Start LByte
#define _IPV_ACT_LEN_H_1A                   	0x1A        // Input Vertical Active Length HByte
#define _IPV_ACT_LEN_L_1B                   	0x1B        // Input Vertical Active Length LByte
#define _IVS_DELAY_1C                       	0x1C        // Internal Input Vertical Sync(VS) Delay Control Register
#define _IHS_DELAY_1D                       	0x1D        // Internal Input Horizontal Sync(HS) Delay Control Register
#define _VGIP_HV_DELAY_1E                   	0x1E        // VGIP HS/VS Delay
#define _IPH_PORCH_NUM_H_1F         			0x1F        // Input Video Horizontal Porch HByte
#define _IPH_PORCH_NUM_L_20                		0x20        // Input Video Horizontal Porch LByte


//--------------------------------------------------
// FIFO Frequency
//--------------------------------------------------
#define _FIFO_FREQUENCY_22                  	0x22        // FIFO Frequency

//--------------------------------------------------
// Input Pattern Generator
//--------------------------------------------------
#define _FIFO_BIST_CTRL_23                  	0x23        // FIFO BIST Control Register
#define _INPUT_PAT_GEN_ACCESS_PORT_24  			0x24        // Input Pattern Generator Access Port
#define _INPUT_PAT_GEN_DATA_PORT_25      		0x25        // Input Pattern Generator Data Port
//#define _RESERVED_26                          0x26        // Reserved 26
//#define _RESERVED_27                          0x27        // Reserved 27
#define _VDISP_CTRL_28                      	0x28        // Video Display Control Register
#define _FREE_RUNNING                           _bits(7)
#define _DISPLAY_INVERSE                        _bits(6)
#define _VIDEO_OUTPUT                           _0
#define _BG_COLOR_OUTPUT                        _bits(5)    // Display output is forced to the color as selected by background color
#define _18BIT_MODE                             _bits(4)    // Truncate output to 18-bit RGB (set 2 LSB to 0)
#define _FRAME_SYNC_MODE                        _bits(3)
#define _DOUBLE_PORT                            _bits(2)
#define _OUTPUT_ENABLED                         _bits(1)    // Enables DHS, DVS, DEN & DATA signals
#define _TCLOCK_ENABLED                         _bits(0)    // Runs timing generator

#define _VDISP_SIGINV_29                    	0x29        // Display Control Signal Inverted Register

//--------------------------------------------------
// Display Format(Port)
//--------------------------------------------------
#define _DISP_ACCESS_PORT_2A              		0x2A        // Display Format Access Port
#define _DISP_DATA_PORT_2B                  	0x2B        // Display Format Data Port

#define _DISP_FORMAT_00                         0x00        // Display Format Base
#define _DISP_DH_TOTAL_H_00                 	0x00        // Display Horizontal Total Pixels HByte
#define _DISP_DH_TOTAL_L_01                 	0x01        // Display Horizontal Total Pixels LByte
#define _DISP_DHS_END_02                    	0x02        // Display Horizontal Sync End Pixels
#define _DISP_DH_BKGD_STA_H_03            		0x03        // Display Horizontal Background Start HByte
#define _DISP_DH_BKGD_STA_L_04           		0x04        // Display Horizontal Background Start LByte
#define _DISP_DH_ACT_STA_H_05               	0x05        // Display Horizontal Active Start HByte
#define _DISP_DH_ACT_STA_L_06               	0x06        // Display Horizontal Active Start LByte
#define _DISP_DH_ACT_END_H_07          			0x07        // Display Horizontal Active End HByte
#define _DISP_DH_ACT_END_L_08               	0x08        // Display Horizontal Active End LByte
#define _DISP_DH_BKGD_END_H_09        			0x09        // Display Horizontal Background End HByte
#define _DISP_DH_BKGD_END_L_0A        			0x0A        // Display Horizontal Background End LByte
#define _DISP_DV_TOTAL_H_0B                 	0x0B        // Display Vertical Total Lines HByte
#define _DISP_DV_TOTAL_L_0C                 	0x0C        // Display Vertical Total Lines LByte
#define _DISP_DVS_END_0D                    	0x0D        // Display Vertical Sync End Lines
#define _DISP_DV_BKGD_STA_H_0E       			0x0E        // Display Vertical Background Start HByte
#define _DISP_DV_BKGD_STA_L_0F       			0x0F        // Display Vertical Background Start LByte
#define _DISP_DV_ACT_STA_H_10               	0x10        // Display Vertical Active Start HByte
#define _DISP_DV_ACT_STA_L_11               	0x11        // Display Vertical Active Start LByte
#define _DISP_DV_ACT_END_H_12               	0x12        // Display Vertical Active End HByte
#define _DISP_DV_ACT_END_L_13               	0x13        // Display Vertical Active End LByte
#define _DISP_DV_BKGD_END_H_14      			0x14        // Display Vertical Background End HByte
#define _DISP_DV_BKGD_END_L_15       			0x15        // Display Vertical Background End LByte

#define _DISP_TIMING_20                     	0x20        // Display Clock Fine Tuning Register
// reserved                                     _bits(7)
#define _DCLK_NO_DELAY                          _0          // DCLK rising edge correspondents with output display data
#define _DCLK_1NS_DELAY                         _bits(4)    // 1ns delay
#define _DCLK_2NS_DELAY                         _bits(5)    // 2ns delay
#define _DCLK_3NS_DELAY                         _bits(4,5)  // 3ns delay
#define _DCLK_4NS_DELAY                         _bits(6)    // 4ns delay
#define _DCLK_5NS_DELAY                         _bits(4,6)  // 5ns delay
#define _DCLK_6NS_DELAY                         _bits(5,6)  // 6ns delay
#define _DCLK_7NS_DELAY                         _bits(4,5,6) // 7ns delay
// reserved                                     _bits(3)
// reserved                                     _bits(2)
#define _DCLK_ENABLED                           _bits(1)    // DCLK Output Enable
#define _DCLK_NOT_INVERTED                      _0
#define _DCLK_INVERTED                          _bits(0)    // DCLK Polarity Inverted

#define _DISP_OSD_REFERENCE_DEN_21 				0x21        // Position Of Reference DEN for OSD
#define _DISP_NEW_DV_CTRL_22                	0x22        // New DV Control Register
#define _DISP_NEW_DV_DLY_23                 	0x23        // New DV Delay

#define _OP_CRC_CTRL_2C                     	0x2C        // Output CRC Control Register
#define _OP_CRC_CHECKSUM_2D               		0x2D        // Output CRC Checksum
//Address: 2C~2F Reserved

//--------------------------------------------------
// FIFO Window(Port)
//--------------------------------------------------
#define _FIFO_ACCESS_PORT_30                	0x30        // FIFO Window Address Port
#define _FIFO_DATA_PORT_31                  	0x31        // FIFO Window Data Port

//--------------------------------------------------
// Scale Up Function(Port)
//--------------------------------------------------
#define _SCALE_CTRL_32                      	0x32        // Scale Control Register
#define _SU_ACCESS_PORT_33                  	0x33        // Scale Up Factor Access Port
#define _SU_DATA_PORT_34                    	0x34        // Scale Up Factor Data Port
#define _FILTER_CTRL_35                     	0x35        // Filter Control Register
#define _FILTER_ACCESS_PORT_36              	0x36        // User Defined Filter Access Port
//Address: 37~3F Reserved

//--------------------------------------------------
// Frame Sync Fine Tune
//--------------------------------------------------
#define _FRAME_SYNC_FINE_TUNE_40                0x40
#define _IVS2DVS_DELAY_LINES_40             	0x40        // IVS to DVS Delay Lines
#define _IV_DV_DELAY_CLK_ODD_41           		0x41        // Frame Sync Delay Fine Tuning ODD
#define _IV_DV_DELAY_CLK_EVEN_42         		0x42        // Frame Sync Delay Fine Tuning EVEN
#define _FS_DELAY_FINE_TUNING_43        		0x43        // Frame Sync Delay Fine Tuning Control Register
#define _LAST_LINE_H_44                     	0x44        // Last Line HByte
#define _LAST_LINE_L_45                     	0x45        // Last Line LByte
//Address: 46 Reserved

//--------------------------------------------------
// Sync Processor(Port)
//--------------------------------------------------
#define _SYNC_SELECT_47                     	0x47        // Sync Select Control Register
#define _SYNC_INVERT_48                     	0x48        // Sync Invert Control Register
#define _SYNC_CTRL_49                       	0x49        // Sync Processor Control Register
#define _STABLE_HIGH_PERIOD_H_4A         		0x4A        // Stable High Period HByte
#define _STABLE_HIGH_PERIOD_L_4B         		0x4B        // Stable High Period LByte
#define _VSYNC_COUNTER_LEVEL_MSB_4C  			0x4C        // Vertical Sync Counter Level MSB
#define _VSYNC_COUNTER_LEVEL_LSB_4D 			0x4D        // Vertical Sync Counter Level LSB
#define _HSYNC_TYPE_DETECTION_FLAG_4E			0x4E        // Hsync Type Detection Flag
#define _STABLE_MEASURE_4F                  	0x4F        // Stable Measure
#define _STABLE_PERIOD_H_50                 	0x50        // Stable Period HByte
#define _STABLE_PERIOD_L_51                 	0x51        // Stable Period LByte
#define _MEAS_HS_PERIOD_H_52               		0x52        // HSync Period Measured Result HByte
#define _MEAS_HS_PERIOD_L_53                	0x53        // HSync Period Measured Result LByte
#define _MEAS_VS_PERIOD_H_54                	0x54        // VSync Period Measured Result HByte
#define _MEAS_VS_PERIOD_L_55                	0x55        // VSync Period Measured Result LByte
#define _MEAS_HS_VS_HIGH_PERIOD_H_56			0x56        // HSync and VSync High Period Measured Results HByte
#define _MEAS_HS_HIGH_PERIOD_L_57       		0x57        // HSync High Period Measured Results LByte
#define _MEAS_HS_VS_HI_SEL_58               	0x58        // HSync and VSync High Period Measured Select
#define _MEAS_ACTIVE_REGION_59              	0x59        // Active Region Measured by Crystal Clock
//#define _SYNC_TEST_MISC_5A                  	0x5A        // Sync Test MISC Register
//Address: 5B Reserved
#define _SYNC_PROC_ACCESS_PORT_5C     			0x5C        // Sync Processor Access Port Address
#define _SYNC_PROC_DATA_PORT_5D          		0x5D        // Sync Processor Access Port Data

//--------------------------------------------------
// Sync Processor Port
//--------------------------------------------------
#define _SYNC_G_CLAMP_START_00              	0x00        // G/Y Channle Clamp Signal Output Start
#define _SYNC_G_CLAMP_END_01                	0x01        // G/Y Channle Clamp Signal Output End
#define _SYNC_BR_CLAMP_START_02           		0x02        // B/Pb & R/Pr Channle Clamp Signal Output Start
#define _SYNC_BR_CLAMP_END_03               	0x03        // B/Pb & R/Pr Channle Clamp Signal Output End
#define _SYNC_CLAMP_CTRL0_04                	0x04        // Clamp Signal Control Register 0
#define _SYNC_CLAMP_CTRL1_05                	0x05        // Clamp Signal Control Register 1
#define _SYNC_CLAMP_CTRL2_06                	0x06        // Clamp Signal Control Register 2
#define _SYNC_CAPTURE_WINDOW_SET_07    			0x07        // Capture Window Setting
#define _SYNC_DETECT_TOLERANCE_SET_08   		0x08        // Detection Tolerance Setting
//Address: 09...0F Reserved
#define _SYNC_MACRO_VISION_CTRL_10       		0x10        // Macro Vision Control Register
#define _SYNC_MV_START_LINE_EVEN_11      		0x11        // Macro Vision Start Line in Even Field
#define _SYNC_MV_END_LINE_EVEN_12           	0x12        // Macro Vision End Line in Even Field
#define _SYNC_MV_START_LINE_ODD_13        		0x13        // Macro Vision Start Line in Odd Field
#define _SYNC_MV_END_LINE_ODD_14            	0x14        // Macro Vision End Line in Odd Field

//Address: 5E~5F Reserved

//--------------------------------------------------
// Hightlight Window(Port)
//--------------------------------------------------
#define _HW_ACCESS_PORT_60                  	0x60        // Highlight Window Access Port
#define _HW_DATA_PORT_61                    	0x61        // Highlight Window Data Port

//--------------------------------------------------
// Color Processor Control(Port)
//--------------------------------------------------
#define _COLOR_CTRL_62                      	0x62        // Color Processor Control Register
#define _SRGB_ACCESS_PORT_63                	0x63        // sRGB Access Port
#define _CB_ACCESS_PORT_64                  	0x64        // Contrast/Brightness Access Port
#define _CB_DATA_PORT_65                    	0x65        // Contrast/Brightness Data Port

//--------------------------------------------------
// Gamma Control
//--------------------------------------------------
#define _GAMMA_PORT_66                      	0x66        // Gamma Access Port
#define _GAMMA_CTRL_67                      	0x67        // Gamma Control Register
#define _GAMMA_BIST_68                      	0x68        // Gamma BIST Control Register

//--------------------------------------------------
// Dithering Control
//--------------------------------------------------
#define _DITHERING_DATA_ACCESS_69          		0x69        // Dithering Table DATA ACCESS
#define _DITHERING_CTRL_6A                 		0x6A        // Dithering Control Register
//#define _RESERVED_6B                      	0x6B        // Reserved 6B


//--------------------------------------------------
// Overlay/Color Palette/Background Color Control
//--------------------------------------------------
#define _OVERLAY_CTRL_6C                    	0x6C        // Overlay Display Control Register
#define _BGND_COLOR_ACCESS_ENABLED              _bits(5)

#define _BGND_COLOR_CTRL_6D                 	0x6D        // Background Color Control Register
#define _OVERLAY_LUT_ADDR_6E                	0x6E        // Overlay Look Up Table (LUT) Address
#define _COLOR_LUT_PORT_6F                  	0x6F        // Color LUT Access Port

//--------------------------------------------------
// Image Auto Function
//--------------------------------------------------
#define _AUTO_ADJUSTMENT_70                     0x70
#define _H_BOUNDARY_H_70                    	0x70        // Horizontal Start/End Boundary HByte
#define _H_BOUNDARY_STA_L_71                	0x71        // Horizontal Start Boundary HByte
#define _H_BOUNDARY_END_L_72                	0x72        // Horizontal End Boundary HByte
#define _V_BOUNDARY_H_73                    	0x73        // Vertical Start/End Boundary HByte
#define _V_BOUNDARY_STA_L_74                	0x74        // Vertical Start Boundary LByte
#define _V_BOUNDARY_END_L_75                	0x75        // Vertical End Boundary LByte
#define _RED_NOISE_MARGIN_76                	0x76        // Red Noise Margin Control Register
#define _GRN_NOISE_MARGIN_77                	0x77        // Green Noise Margin Control Register
#define _BLU_NOISE_MARGIN_78                	0x78        // Blue Noise Margin Control Register
#define _DIFF_THRESHOLD_79                  	0x79        // Difference Threshold
#define _AUTO_ADJ_CTRL0_7A                  	0x7A        // Auto Adjusting Control Register 0
#define _HW_AUTO_PHASE_CTRL0_7B          		0x7B        // Hardware Auto Phase Control Register 0
#define _HW_AUTO_PHASE_CTRL1_7C          		0x7C        // Hardware Auto Phase Control Register 1
#define _AUTO_ADJ_CTRL1_7D                  	0x7D        // Auto Adjusting Control Register 1
#define _V_START_END_H_7E                   	0x7E        // Actuve Region Vertical Start/End HByte
#define _V_START_L_7F                       	0x7F        // Actuve Region Vertical Start LByte
#define _V_END_L_80                         	0x80        // Actuve Region Vertical End LByte
#define _H_START_END_H_81                   	0x81        // Actuve Region Horizontal Start/End HByte
#define _H_START_L_82                       	0x82        // Actuve Region Horizontal Start LByte
#define _H_END_L_83                         	0x83        // Actuve Region Horizontal End LByte
#define _AUTO_PHASE_3_84                   		0x84        // Auto Phase Result Register Byte 3
#define _AUTO_PHASE_2_85                    	0x85        // Auto Phase Result Register Byte 2
#define _AUTO_PHASE_1_86                    	0x86        // Auto Phase Result Register Byte 1
#define _AUTO_PHASE_0_87                    	0x87        // Auto Phase Result Register Byte 0
//Address: 88~8A Reserved


//--------------------------------------------------
// Embedded Timing Controller (port)
//--------------------------------------------------
#define _TCON_ADDR_PORT_8B                  	0x8B        // TCON Address Port for Embedded TCON Access
#define _TCON_DATA_PORT_8C                  	0x8C        // TCON Data Port for Embedded TCON Access

#define _TCON_CTRL0_00                      	0x00        // Timing Controller Control Register0
#define _TCON_ENABLE                            _bits(7)


#define _TCON_CTRL1_01                      	0x01        // Timing Controller Control Register1
#define _TCON_PIXEL_THRESHOLD_MSB_02      		0x02        // Pixel Threshold High Value for Smart Polarity
#define _TCON_PIXEL_THRESHOLD1_LSB_03     		0x03        // 2 Line Sum of Difference Threshold 1 Value: bit [7:0], ie:TH1 (Also refer to CR8C-02[7])
#define _TCON_PIXEL_THRESHOLD2_LSB_04     		0x04        // 2 Line Sum of Difference Threshold 2 Value: bit [7:0], ie:TH2 (Also refer to CR8C-02[6])
#define _TCON_LINE_THRESHOLD_05             	0x05        // Line Threshold Value for Smart Polarity
#define _TCON_TCON0_V_STA_LSB_08            	0x08        // TCON[0] Vertical Start LSB Register
#define _TCON_TCON0_V_SE_MSB_09             	0x09        // TCON[0] Vertical Start/End MSB Register
#define _TCON_TCON0_V_END_LSB_0A            	0x0A        // TCON[0] Vertical End LSB Register
#define _TCON_TCON0_H_STA_LSB_0B            	0x0B        // TCON[0] Horizontal Start LSB Register
#define _TCON_TCON0_H_SE_MSB_0C             	0x0C        // TCON[0] Horizontal Start/End MSB Register
#define _TCON_TCON0_H_END_LSB_0D            	0x0D        // TCON[0] Horizontal End LSB Register
#define _TCON_TCON0_CTRL_0E                 	0x0E        // TCON[0] Control Register
#define _TCON_TCON0_RESERVED_0F             	0x0F        // TCON[0] Reserved Register(TCON[0]~TCON[9] Have This Register)
#define _TCON_TCON1_V_STA_LSB_10            	0x10        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON2_V_STA_LSB_18            	0x18        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON3_V_STA_LSB_20            	0x20        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON4_V_STA_LSB_28            	0x28        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON5_V_STA_LSB_30            	0x30        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON6_V_STA_LSB_38            	0x38        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON7_V_STA_LSB_40            	0x40        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON8_V_STA_LSB_48            	0x48        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON9_V_STA_LSB_50            	0x50        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON10_V_STA_LSB_58        		0x58        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON11_V_STA_LSB_60          		0x60        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON12_V_STA_LSB_68          		0x68        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON13_V_STA_LSB_70          		0x70        // TCON[13] Vertical Start LSB Register
#define _TCON_TCON10_DOT_MASK_CTRL_5F     	    0x5F        // TCON[10] Dot Masking Control Register
#define _TCON_TCON11_DOT_MASK_CTRL_67     	    0x67        // TCON[11] Dot Masking Control Register
#define _TCON_TCON12_DOT_MASK_CTRL_6F     	    0x6F        // TCON[12] Dot Masking Control Register
#define _TCON_TCON13_DOT_MASK_CTRL_77     	    0x77        // TCON[13] Dot Masking Control Register

#define _TCON_LVDS_CTRL0_A0                 	0xA0        // LVDS Control Register0
#define _PWR_UP_EVEN_PORT                       _bits(5)
#define _PWR_UP_ODD_PORT                        _bits(4)
#define _TTL                                    _0
#define _LVDS                                   _bits(0)

#define _TCON_LVDS_CTRL1_A1                 	0xA1        // LVDS Control Register1
#define _TCON_LVDS_CTRL2_A2                 	0xA2        // LVDS Control Register2
#define _TCON_LVDS_CTRL3_A3                 	0xA3        // LVDS Control Register3
#define _TCON_LVDS_CTRL4_A4                 	0xA4        // LVDS Control Register4
#define _TCON_LVDS_CTRL5_A5                 	0xA5        // LVDS Control Register5

#define _TCON_RSDS_OUTPUT_CTRL0_C0          	0xC0        // RSDS Output Control Register
#define _TCON_RSDS_INTERLEAVING_H_C1        	0xC1        // RSDS Display Data Bus Interleaving Line Buffer Length High Byte
#define _TCON_RSDS_INTERLEAVING_L_C2        	0xC2        // RSDS Display Data Bus Interleaving Line Buffer Length Low Byte

//--------------------------------------------------
// Embedded OSD
//--------------------------------------------------
#define _OSD_ADDR_90                            0x90
#define _OSD_ADDR_MSB_90                    	0x90        // OSD Address MSB
#define _OSD_ADDR_LSB_91                    	0x91        // OSD Address LSB
#define _OSD_DATA_92                   	        0x92
#define _OSD_DATA_PORT_92                   	0x92        // OSD Data Port
#define _OSD_SCRAMBLE_93                    	0x93        // OSD Scramble
#define _OSD_TEST_94                        	0x94        // OSD Test
//Address: 95~97 Reserved

//--------------------------------------------------
// Digital Filter
//--------------------------------------------------
#define _DIGITAL_FILTER_CTRL_98            		0x98        // Digital Filter Control Register
#define _DIGITAL_FILTER_PORT_99             	0x99        // Digital Filter Port

//--------------------------------------------------
// Peaking Filter and Coring Control(Port)
//--------------------------------------------------
#define _PC_ACCESS_PORT_9A                  	0x9A        // Peaking/Coring Access Port
#define _PC_DATA_PORT_9B                    	0x9B        // Peaking/Coring Data Port

//--------------------------------------------------
// Video Color Space Conversion
//--------------------------------------------------
#define _YUV2RGB_CTRL_9C                    	0x9C        // YUV to RGB Control Register
#define _YUV_RGB_COEF_DATA_9D               	0x9D        // YUV to RGB Coefficient Data Port
//Address:9E~9F Reserved



//--------------------------------------------------
// VBI(Port)
//--------------------------------------------------
#define _VBI_ACCESS_PORT_9A                 	0x9A        // VBI Access Port
#define _VBI_DATA_PORT_9B                   	0x9B        // VBI Data Port



//--------------------------------------------------
// Paged Control Register
//--------------------------------------------------
#define _PAGE_SELECT_9F                     	0x9F        // Page Selector (CRA0~CRFF)


#endif
