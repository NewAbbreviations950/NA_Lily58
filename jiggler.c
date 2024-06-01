/*set custom ketcode for mouse jiggler*/
enum custom_keycodes {
    KC_JIGG = SAFE_RANGE,
};

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

/*declare boolean for jiggler*/
bool is_jiggling = false;

/*timers*/
uint32_t idle_timeout = 30000; // (after 30s)
uint32_t mouse_interval = 10000; // (every 10s)

static uint32_t idle_callback(uint32_t trigger_time, void* cb_arg) {
    // now idle
    if (is_jiggling){
        SEND_STRING(SS_TAP(X_F15));
        return mouse_interval;
    }
}

/*listen for keypress*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
     // on every key event start or extend `idle_callback()` deferred execution after IDLE_TIMEOUT_MS
    static deferred_token idle_token = INVALID_DEFERRED_TOKEN;

    if (!extend_deferred_exec(idle_token, idle_timeout)) {
        idle_token = defer_exec(idle_timeout, idle_callback, NULL);
    }
    
    switch (keycode) {
        case KC_JIGG:
            if (record->event.pressed) {
                    is_jiggling = !is_jiggling; /*flip boolean to true*/
            }

            break;
    }

  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
            #ifdef OLED_ENABLE
            && process_record_oled(keycode, record)
            #endif
            ;
}

/*print status of jiggler to left screen under the logo*/
static void print_logo_narrow(void) {
    
    switch (is_jiggling) {
        case true:
            oled_set_cursor(0, 7);
            oled_write_P(PSTR("Jiggle"), false);
            break;
        default:
            oled_set_cursor(0, 7);
            oled_write_P(PSTR("      "), false);
   }
    
}
