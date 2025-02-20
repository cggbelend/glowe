#include <config.h>
#include <FastLED.h>
#include <ArduinoLog.h>
#include <leds.h>


namespace leds
{
    void Begin(){
        FastLED.addLeds<NEOPIXEL, config::leds::PIN>(config::leds::LEDSS, config::leds::NUM);
        Log.infoln("Leds Began");
    }

    void filll_solid(CRGB color){
        fill_solid(config::leds::LEDSS, config::leds::NUM, color);  // Change to your desired color
        FastLED.show();
    }

    void color_wipe(uint8_t speed = 500, CRGB color = CRGB::Green){
        for (int i = 0; i < config::leds::NUM; i++) {
        config::leds::LEDSS[i] = color;  // Change to your desired color
        FastLED.show();
        delay(speed);  // Speed of the wipe
    }

    // Clear the strip after the wipe
    fill_solid(config::leds::LEDSS, config::leds::NUM, CRGB::Black);
    FastLED.show();
    }

    void rainbow(uint8_t speed = 500){
        static uint8_t hue = 0;
        for (int i = 0; i < config::leds::NUM; i++) {
            config::leds::LEDSS[i] = CHSV(hue + (i * 256 / config::leds::NUM), 255, 255);
        }
        FastLED.show();
        hue++;  // Increment the hue for the next frame
        delay(speed);
    }

    void fade(uint8_t speed = 500){
        for (int j = 0; j < 256; j++) {
            for (int i = 0; i < config::leds::NUM; i++) {
                config::leds::LEDSS[i] = CHSV(j, 255, 255);
            }
        FastLED.show();
        delay(10);
        }
    }
    void twinkle(uint8_t speed = 500,CRGB color = CRGB::Green){
        // Clear all LEDs
        uint8_t pos;
        fill_solid(config::leds::LEDSS, config::leds::NUM, CRGB::Black);

        // Set the current position to color
        config::leds::LEDSS[pos] = color;

        // Move to the next position
        pos = (pos + 1) % config::leds::NUM;

        FastLED.show();
        delay(speed);
        }
} // namespace leds

