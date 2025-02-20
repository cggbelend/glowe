#include <FastLED.h>

namespace config
{
    namespace leds
    {
        const extern uint8_t PIN = 3;
        const extern uint8_t NUM = 8;
        const extern ESPIChipsets TYPE = WS2801;
        extern CRGB LEDSS[NUM];
    } // namespace leds

    namespace buttons
    {
        const extern uint8_t FWD_PIN = 3;
        const extern uint8_t BWD_PIN = 3;
    } // namespace buttons
    
    namespace light
    {
        const extern int MIN_TRESHOLD;
        const extern int MAX_TRESHOLD;
    } // namespace light
    
    namespace bluetooth
    {
        const extern uint8_t RX;
        const extern uint8_t TX;
    } // namespace bluetooth
    
    
} // namespace config
