
#include <FastLED.h>
#pragma once

namespace leds
{
    void Begin();
    void filll_solid(CRGB color);

    void color_wipe(uint8_t speed = 500, CRGB color = CRGB::Green);
    void rainbow(uint8_t speed = 500);
    void fade(uint8_t speed = 500);
    void twinkle(uint8_t speed = 500,CRGB color = CRGB::Green);
    
    uint8_t ModesCount = 4;
} // namespace leds

