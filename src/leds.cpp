#include <FastLED.h>
#include <config.h>
#include <Arduino.h>
#include <ArduinoLog.h>
namespace ledstripp
{
    void begin(){
        FastLED.addLeds<LEDS_TYPE, LEDS_PIN, GRB>(leds, LEDS_NUM);
        FastLED.setBrightness(50);
    
        for (int i = 0; i < LEDS_NUM; i++)
        {
            leds[i] = CHSV(random8(), 255, 255);
            FastLED.show();
        }
    
        delay(500);
    
        for (int i = 0; i < LEDS_NUM; i++)
            {
                leds[i] = CRGB::Black;
            }
            FastLED.show();
    
        Log.info("init was SUCKsefull :)))");
}

    void rainbow(uint16_t speed = 1){
        uint8_t hue;

        for (size_t i = 0; i < LEDS_NUM; i++)
        {
            leds[i] = CHSV(255,255,hue);
            hue += speed;

            FastLED.show();
        }

    }

    void moving_rainbow(uint16_t speed = 1, int strange_thing = 13){
        uint8_t hue;

        for (size_t i = 0; i < LEDS_NUM; i++)
        {
            leds[i] = CHSV(255,255,hue+(i * strange_thing));

            EVERY_N_MILLISECONDS(speed){
                hue ++;
            }

            FastLED.show();
        }
    }

    void random_gradient(int base_color_hue = 50, int value_min = 3, int value_max = 253){
        leds[0] = CHSV(base_color_hue, random8(), random8(value_min, value_max));

        for (int i = LEDS_NUM - 1; i > 0; i--){
        leds [i] = leds [i - 1];
        }

    FastLED.show();
    }

    void fill_with_palette(CRGBPalette16 palete, uint8_t brightness){
        fill_palette(leds, LEDS_NUM, 0, 255/LEDS_NUM, palete, brightness,LINEARBLEND);
    }

    void moving_palette(CRGBPalette16 palete, uint8_t brightness, uint16_t speed){
        int palette_index;

        fill_palette(leds, LEDS_NUM, palette_index, 255/LEDS_NUM, palete, brightness,LINEARBLEND);
        palette_index += speed;

        FastLED.show();
    }

    void fading_palette(CRGBPalette16 palette, uint16_t freeqency, uint16_t fade_time){

        EVERY_N_MILLISECONDS (freeqency) {

            //Switch on an LED at random, choosing a random color from the palette 
            leds[random8 (0, LEDS_NUM - 1)] = ColorFromPalette (palette, random8 (), 255, LINEARBLEND);
            }
            // Fade all LEDs down by 1 in brightness each time this is called 
            fadeToBlackBy (leds, LEDS_NUM, fade_time);

            FastLED.show();
            }

    void kometa(uint8_t speed = 1, uint8_t lenght = 15, uint8_t noise_scale = 30, uint8_t blur = 10){
        for (int i = 0; i < LEDS_NUM; i++)
        {
            uint8_t pos = map(beat8(speed, 0), 0, 255, 0, LEDS_NUM -1);
            uint8_t noise = inoise8 (i*noise_scale ,0);
            uint8_t hue = map (noise, 50, 190, 0, 255);

            leds[pos] = CHSV(hue,255,255);
            fadeToBlackBy(leds, LEDS_NUM, lenght);
        }

        EVERY_N_MILLISECONDS(1){
            for (int i = 0; i < LEDS_NUM; i++)
            {
                blur1d(leds, LEDS_NUM, blur);
            }
        }
    }

    uint8_t count = 7;
} 

