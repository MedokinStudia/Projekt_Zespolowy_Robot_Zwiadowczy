/*
 * camera.h
 *
 */

#ifndef INC_CAMERA_H_
#define INC_CAMERA_H_

#include "main.h"

/* READ/WRITE ADDRESS*/
#define OV2640_DEVICE_WRITE_ADDRESS 0x60
#define OV2640_DEVICE_READ_ADDRESS 0x61

/* Device ID */
#define  OV2640_ID    0x26

/* OV2640 Registers definition when DSP bank selected (0xFF = 0x00) */
#define OV2640_DSP_R_BYPASS             0x05
#define OV2640_DSP_Qs                   0x44
#define OV2640_DSP_CTRL                 0x50
#define OV2640_DSP_HSIZE1               0x51
#define OV2640_DSP_VSIZE1               0x52
#define OV2640_DSP_XOFFL                0x53
#define OV2640_DSP_YOFFL                0x54
#define OV2640_DSP_VHYX                 0x55
#define OV2640_DSP_DPRP                 0x56
#define OV2640_DSP_TEST                 0x57
#define OV2640_DSP_ZMOW                 0x5A
#define OV2640_DSP_ZMOH                 0x5B
#define OV2640_DSP_ZMHH                 0x5C
#define OV2640_DSP_BPADDR               0x7C
#define OV2640_DSP_BPDATA               0x7D
#define OV2640_DSP_CTRL2                0x86
#define OV2640_DSP_CTRL3                0x87
#define OV2640_DSP_SIZEL                0x8C
#define OV2640_DSP_HSIZE2               0xC0
#define OV2640_DSP_VSIZE2               0xC1
#define OV2640_DSP_CTRL0                0xC2
#define OV2640_DSP_CTRL1                0xC3
#define OV2640_DSP_R_DVP_SP             0xD3
#define OV2640_DSP_IMAGE_MODE           0xDA
#define OV2640_DSP_RESET                0xE0
#define OV2640_DSP_MS_SP                0xF0
#define OV2640_DSP_SS_ID                0x7F
#define OV2640_DSP_SS_CTRL              0xF8
#define OV2640_DSP_MC_BIST              0xF9
#define OV2640_DSP_MC_AL                0xFA
#define OV2640_DSP_MC_AH                0xFB
#define OV2640_DSP_MC_D                 0xFC
#define OV2640_DSP_P_STATUS             0xFE
#define OV2640_DSP_RA_DLMT              0xFF

/* OV2640 Registers definition when sensor bank selected (0xFF = 0x01) */
#define OV2640_SENSOR_GAIN              0x00
#define OV2640_SENSOR_COM1              0x03
#define OV2640_SENSOR_REG04             0x04
#define OV2640_SENSOR_REG08             0x08
#define OV2640_SENSOR_COM2              0x09
#define OV2640_SENSOR_PIDH              0x0A
#define OV2640_SENSOR_PIDL              0x0B
#define OV2640_SENSOR_COM3              0x0C
#define OV2640_SENSOR_COM4              0x0D
#define OV2640_SENSOR_AEC               0x10
#define OV2640_SENSOR_CLKRC             0x11
#define OV2640_SENSOR_COM7              0x12
#define OV2640_SENSOR_COM8              0x13
#define OV2640_SENSOR_COM9              0x14
#define OV2640_SENSOR_COM10             0x15
#define OV2640_SENSOR_HREFST            0x17
#define OV2640_SENSOR_HREFEND           0x18
#define OV2640_SENSOR_VSTART            0x19
#define OV2640_SENSOR_VEND              0x1A
#define OV2640_SENSOR_MIDH              0x1C
#define OV2640_SENSOR_MIDL              0x1D
#define OV2640_SENSOR_AEW               0x24
#define OV2640_SENSOR_AEB               0x25
#define OV2640_SENSOR_W                 0x26
#define OV2640_SENSOR_REG2A             0x2A
#define OV2640_SENSOR_FRARL             0x2B
#define OV2640_SENSOR_ADDVSL            0x2D
#define OV2640_SENSOR_ADDVHS            0x2E
#define OV2640_SENSOR_YAVG              0x2F
#define OV2640_SENSOR_REG32             0x32
#define OV2640_SENSOR_ARCOM2            0x34
#define OV2640_SENSOR_REG45             0x45
#define OV2640_SENSOR_FLL               0x46
#define OV2640_SENSOR_FLH               0x47
#define OV2640_SENSOR_COM19             0x48
#define OV2640_SENSOR_ZOOMS             0x49
#define OV2640_SENSOR_COM22             0x4B
#define OV2640_SENSOR_COM25             0x4E
#define OV2640_SENSOR_BD50              0x4F
#define OV2640_SENSOR_BD60              0x50
#define OV2640_SENSOR_REG5D             0x5D
#define OV2640_SENSOR_REG5E             0x5E
#define OV2640_SENSOR_REG5F             0x5F
#define OV2640_SENSOR_REG60             0x60
#define OV2640_SENSOR_HISTO_LOW         0x61
#define OV2640_SENSOR_HISTO_HIGH        0x62

enum imgResolution{RES_320x240, RES_800x600, RES_1024x768, RES_1280x960};
enum movieStandard{QVGA, VGA};

int SCCB_Read(uint8_t reg_addrs, uint8_t *data);
int SCCB_Write(uint8_t reg_addrs, uint8_t data);

void camera_Init(I2C_HandleTypeDef *hi2c, DCMI_HandleTypeDef *dcmi);
void camera_setI2C(I2C_HandleTypeDef *hi2c);
void camera_setDCMI(DCMI_HandleTypeDef *dcmi);
void camera_setUART(UART_HandleTypeDef *huart);
void camera_Reset(void);
void camera_Configuration(const char arr[][2]);
void camera_ResolutionConfiguration(enum imgResolution res);
void camera_configureResolution(const char arr[][2]);
void camera_StopDCMI(void);
void camera_CaptureSnapshot();
void camera_CaptureContinuous();
uint8_t camera_ReadID(void);

#endif /* INC_CAMERA_H_ */
