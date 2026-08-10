/* This software is licensed under the MIT License: https://github.com/spacehuhntech/esp8266_deauther */

/* Modified for the Orbit hardware platform
   https://github.com/shasradha/Orbit
   Original firmware (c) spacehuhn, used under MIT License */

#pragma once

#include <cstdint>

enum LED_MODE {
    OFF,
    SCAN,
    ATTACK,
    IDLE
};

namespace led {
    void setup();
    void update();
    void setMode(LED_MODE new_mode, bool force = false);
    void setColor(uint8_t r, uint8_t g, uint8_t b);
}