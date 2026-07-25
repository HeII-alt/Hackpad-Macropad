#include QMK_KEYBOARD_H

enum custom_layers {
    _L0 = 0,
    _L1
};

static uint32_t oled_timer = 0;
static uint8_t  volume_level = 50;
static bool     show_vol_bar = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_L0] = LAYOUT(
        KC_P7, KC_P8, KC_P9,
        KC_P4, KC_P5, KC_P6,
        TG(_L1), KC_P2, KC_P3
    ),
    [_L1] = LAYOUT(
        KC_MPRV, KC_MNXT, KC_MPLY,
        KC_LCTRL, KC_C,   KC_V,
        TG(_L1), KC_F14,  KC_F15
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    oled_timer = timer_read32();
    show_vol_bar = true;

    if (get_highest_layer(layer_state) == _L0) {
        if (clockwise) {
            volume_level = (volume_level < 100) ? volume_level + 5 : 100;
            tap_code(KC_VOLU);
        } else {
            volume_level = (volume_level > 0) ? volume_level - 5 : 0;
            tap_code(KC_VOLD);
        }
    } else {
        tap_code(clockwise ? KC_PGDN : KC_PGUP);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read32();
        show_vol_bar = false;
    }
    return true;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 3000) {
        // Screensaver display
        oled_write_P(PSTR("  [L0]  08:08  [100%]\n\n Menu        QQ \n"), false);
    } else if (show_vol_bar) {
        // Volume popup bar
        oled_write_P(PSTR("     VOLUME     \n["), false);
        uint8_t filled = (volume_level * 14) / 100;
        for (uint8_t i = 0; i < 14; i++) {
            oled_write_P(i < filled ? PSTR("=") : PSTR(" "), false);
        }
        oled_write_P(PSTR("]\n"), false);
    } else {
        oled_write_P(PSTR("  MACROPAD ACTIVE \n"), false);
    }
    return false;
}
#endif