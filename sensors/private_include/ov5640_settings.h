#ifndef _OV5640_SETTINGS_H_
#define _OV5640_SETTINGS_H_

#include <stdint.h>
#include <stdbool.h>
#include "esp_attr.h"
#include "ov5640_regs.h"

static const ratio_settings_t ratio_table[] = {
    //  mw,   mh,  sx,  sy,   ex,   ey, ox, oy,   tx,   ty
    { 2560, 1920,   0,   0, 2623, 1951, 32, 16, 2844, 1968 }, //4x3
    { 2560, 1704,   0, 110, 2623, 1843, 32, 16, 2844, 1752 }, //3x2
    { 2560, 1600,   0, 160, 2623, 1791, 32, 16, 2844, 1648 }, //16x10
    { 2560, 1536,   0, 192, 2623, 1759, 32, 16, 2844, 1584 }, //5x3
    { 2560, 1440,   0, 240, 2623, 1711, 32, 16, 2844, 1488 }, //16x9
    { 2560, 1080,   0, 420, 2623, 1531, 32, 16, 2844, 1128 }, //21x9
    { 2400, 1920,  80,   0, 2543, 1951, 32, 16, 2684, 1968 }, //5x4
    { 1920, 1920, 320,   0, 2543, 1951, 32, 16, 2684, 1968 }  //1x1
};

#define REG_DLY 0xffff
#define REGLIST_TAIL 0x0000

static const DRAM_ATTR uint16_t sensor_default_regs[][2] = {
    {SYSTEM_CTROL0, 0x82},  // software reset
    {REG_DLY, 10}, // delay 10ms
    {SYSTEM_CTROL0, 0x42},  // power down

    //enable pll
    {0x3103, 0x13},

    //io direction
    {0x3017, 0xff},
    {0x3018, 0xff},

    {DRIVE_CAPABILITY, 0xc3},
    {CLOCK_POL_CONTROL, 0x21},

    {0x4713, 0x02},//jpg mode select

    {ISP_CONTROL_01, 0x83}, // turn color matrix, awb and SDE

    //sys reset
    {0x3000, 0x00},
    {0x3002, 0x1c},

    //clock enable
    {0x3004, 0xff},
    {0x3006, 0xc3},

    //isp control
    {0x5000, 0xa7},
    {ISP_CONTROL_01, 0xa3},//+scaling?
    {0x5003, 0x08},//special_effect

    //unknown
    {0x370c, 0x02},//!!IMPORTANT
    {0x3634, 0x40},//!!IMPORTANT

    //AEC/AGC
    {0x3a02, 0x03},
    {0x3a03, 0xd8},
    {0x3a08, 0x01},
    {0x3a09, 0x27},
    {0x3a0a, 0x00},
    {0x3a0b, 0xf6},
    {0x3a0d, 0x04},
    {0x3a0e, 0x03},
    {0x3a0f, 0x30},//ae_level
    {0x3a10, 0x28},//ae_level
    {0x3a11, 0x60},//ae_level
    {0x3a13, 0x43},
    {0x3a14, 0x03},
    {0x3a15, 0xd8},
    {0x3a18, 0x00},//gainceiling
    {0x3a19, 0xf8},//gainceiling
    {0x3a1b, 0x30},//ae_level
    {0x3a1e, 0x26},//ae_level
    {0x3a1f, 0x14},//ae_level

    //vcm debug
    {0x3600, 0x08},
    {0x3601, 0x33},

    //50/60Hz
    {0x3c01, 0xa4},
    {0x3c04, 0x28},
    {0x3c05, 0x98},
    {0x3c06, 0x00},
    {0x3c07, 0x08},
    {0x3c08, 0x00},
    {0x3c09, 0x1c},
    {0x3c0a, 0x9c},
    {0x3c0b, 0x40},

    {0x460c, 0x22},//disable jpeg footer

    //BLC
    {0x4001, 0x02},
    {0x4004, 0x02},

    //color matrix (Saturation)
    {0x5381, 0x1e},
    {0x5382, 0x5b},
    {0x5383, 0x08},
    {0x5384, 0x0a},
    {0x5385, 0x7e},
    {0x5386, 0x88},
    {0x5387, 0x7c},
    {0x5388, 0x6c},
    {0x5389, 0x10},
    {0x538a, 0x01},
    {0x538b, 0x98},

    //CIP control (Sharpness)
    {0x5300, 0x10},//sharpness
    {0x5301, 0x10},//sharpness
    {0x5302, 0x18},//sharpness
    {0x5303, 0x19},//sharpness
    {0x5304, 0x10},
    {0x5305, 0x10},
    {0x5306, 0x08},//denoise
    {0x5307, 0x16},
    {0x5308, 0x40},
    {0x5309, 0x10},//sharpness
    {0x530a, 0x10},//sharpness
    {0x530b, 0x04},//sharpness
    {0x530c, 0x06},//sharpness

    {0x5480, 0x01},//0x00

    //Special Digital Effects (SDE) (UV adjust)
    {0x5580, 0x06},//enable brightness and contrast
    {0x5583, 0x40},//special_effect
    {0x5584, 0x10},//special_effect
    {0x5586, 0x20},//contrast
    {0x5587, 0x00},//brightness
    {0x5588, 0x00},//brightness
    {0x5589, 0x10},
    {0x558a, 0x00},
    {0x558b, 0xf8},
    {0x501d, 0x40},// enable manual offset of contrast

    //power on
    {0x3008, 0x02},

    //50Hz
    {0x3c00, 0x04},
    
    {REG_DLY, 300},
    {REGLIST_TAIL, 0x00}, // tail
};

static const DRAM_ATTR uint16_t sensor_fmt_jpeg[][2] = {
    {FORMAT_CTRL, 0x00}, // YUV422
    {FORMAT_CTRL00, 0x30}, // YUYV
    {0x3002, 0x00},//0x1c to 0x00 !!!
    {0x3006, 0xff},//0xc3 to 0xff !!!
    {0x471c, 0x50},//0xd0 to 0x50 !!!
    {REGLIST_TAIL, 0x00}, // tail
};

static const DRAM_ATTR uint16_t sensor_fmt_raw[][2] = {
    {FORMAT_CTRL, 0x03}, // RAW (DPC)
    {FORMAT_CTRL00, 0x00}, // RAW
    {REGLIST_TAIL, 0x00}
};

static const DRAM_ATTR uint16_t sensor_fmt_grayscale[][2] = {
    {FORMAT_CTRL, 0x00}, // YUV422
    {FORMAT_CTRL00, 0x10}, // Y8
    {REGLIST_TAIL, 0x00}
};

static const DRAM_ATTR uint16_t sensor_fmt_yuv422[][2] = {
    {FORMAT_CTRL, 0x00}, // YUV422
    {FORMAT_CTRL00, 0x30}, // YUYV
    {REGLIST_TAIL, 0x00}
};

static const DRAM_ATTR uint16_t sensor_fmt_rgb565[][2] = {
    {FORMAT_CTRL, 0x01}, // RGB
    {FORMAT_CTRL00, 0x61}, // RGB565 (BGR)
    {REGLIST_TAIL, 0x00}
};

static const DRAM_ATTR uint8_t sensor_saturation_levels[9][11] = {
    {0x1d, 0x60, 0x03, 0x07, 0x48, 0x4f, 0x4b, 0x40, 0x0b, 0x01, 0x98},//-4
    {0x1d, 0x60, 0x03, 0x08, 0x54, 0x5c, 0x58, 0x4b, 0x0d, 0x01, 0x98},//-3
    {0x1d, 0x60, 0x03, 0x0a, 0x60, 0x6a, 0x64, 0x56, 0x0e, 0x01, 0x98},//-2
    {0x1d, 0x60, 0x03, 0x0b, 0x6c, 0x77, 0x70, 0x60, 0x10, 0x01, 0x98},//-1
    {0x1d, 0x60, 0x03, 0x0c, 0x78, 0x84, 0x7d, 0x6b, 0x12, 0x01, 0x98},//0
    {0x1d, 0x60, 0x03, 0x0d, 0x84, 0x91, 0x8a, 0x76, 0x14, 0x01, 0x98},//+1
    {0x1d, 0x60, 0x03, 0x0e, 0x90, 0x9e, 0x96, 0x80, 0x16, 0x01, 0x98},//+2
    {0x1d, 0x60, 0x03, 0x10, 0x9c, 0xac, 0xa2, 0x8b, 0x17, 0x01, 0x98},//+3
    {0x1d, 0x60, 0x03, 0x11, 0xa8, 0xb9, 0xaf, 0x96, 0x19, 0x01, 0x98},//+4
};

static const DRAM_ATTR uint8_t sensor_special_effects[7][4] = {
    {0x06, 0x40, 0x2c, 0x08},//Normal
    {0x46, 0x40, 0x28, 0x08},//Negative
    {0x1e, 0x80, 0x80, 0x08},//Grayscale
    {0x1e, 0x80, 0xc0, 0x08},//Red Tint
    {0x1e, 0x60, 0x60, 0x08},//Green Tint
    {0x1e, 0xa0, 0x40, 0x08},//Blue Tint
    {0x1e, 0x40, 0xa0, 0x08},//Sepia
};

static const DRAM_ATTR uint16_t sensor_regs_gamma0[][2] = {
    {0x5480, 0x01},
    {0x5481, 0x08},
    {0x5482, 0x14},
    {0x5483, 0x28},
    {0x5484, 0x51},
    {0x5485, 0x65},
    {0x5486, 0x71},
    {0x5487, 0x7d},
    {0x5488, 0x87},
    {0x5489, 0x91},
    {0x548a, 0x9a},
    {0x548b, 0xaa},
    {0x548c, 0xb8},
    {0x548d, 0xcd},
    {0x548e, 0xdd},
    {0x548f, 0xea},
    {0x5490, 0x1d}
};

static const DRAM_ATTR uint16_t sensor_regs_gamma1[][2] = {
    {0x5480, 0x1},
    {0x5481, 0x0},
    {0x5482, 0x1e},
    {0x5483, 0x3b},
    {0x5484, 0x58},
    {0x5485, 0x66},
    {0x5486, 0x71},
    {0x5487, 0x7d},
    {0x5488, 0x83},
    {0x5489, 0x8f},
    {0x548a, 0x98},
    {0x548b, 0xa6},
    {0x548c, 0xb8},
    {0x548d, 0xca},
    {0x548e, 0xd7},
    {0x548f, 0xe3},
    {0x5490, 0x1d}
};

static const DRAM_ATTR uint16_t sensor_regs_awb0[][2] = {
    {0x5180, 0xff},
    {0x5181, 0xf2},
    {0x5182, 0x00},
    {0x5183, 0x14},
    {0x5184, 0x25},
    {0x5185, 0x24},
    {0x5186, 0x09},
    {0x5187, 0x09},
    {0x5188, 0x09},
    {0x5189, 0x75},
    {0x518a, 0x54},
    {0x518b, 0xe0},
    {0x518c, 0xb2},
    {0x518d, 0x42},
    {0x518e, 0x3d},
    {0x518f, 0x56},
    {0x5190, 0x46},
    {0x5191, 0xf8},
    {0x5192, 0x04},
    {0x5193, 0x70},
    {0x5194, 0xf0},
    {0x5195, 0xf0},
    {0x5196, 0x03},
    {0x5197, 0x01},
    {0x5198, 0x04},
    {0x5199, 0x12},
    {0x519a, 0x04},
    {0x519b, 0x00},
    {0x519c, 0x06},
    {0x519d, 0x82},
    {0x519e, 0x38}
};

#endif
