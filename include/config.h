#include <FastLED.h>

// leds
#define LEDS_NUM 30
#define LEDS_PIN 6
#define LEDS_TYPE WS2812B
CRGB leds[LEDS_NUM];

// light sensor
#define LIGHT_S_PIN 5
#define LIGHT_TRESHHOLD 2

//buttons
#define FWD_BTN_PIN 3
#define BWD_BTN_PIN 3
#define BTN_DOUBLE_CLICK_TIMEOUT 2000 
// other stuff)
#define MOTION_S_PIN 3