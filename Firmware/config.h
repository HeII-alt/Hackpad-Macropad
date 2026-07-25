#pragma once

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    HackClubber
#define PRODUCT         Custom Macropad

/* Matrix Pins */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { GP26, GP27, GP28 }
#define MATRIX_COL_PINS { GP29, GP0, GP1 }
#define DIODE_DIRECTION COL2ROW

/* Encoder Pins */
#define ENCODERS_PAD_A { GP2 }
#define ENCODERS_PAD_B { GP3 }
#define ENCODER_RESOLUTION 4

/* OLED Pins */
#define OLED_DISPLAY_128X32
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

/* Vial Settings */
#define VIAL_KEYBOARD_UID {0x4D, 0x61, 0x63, 0x72, 0x6F, 0x31, 0x32, 0x33}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }