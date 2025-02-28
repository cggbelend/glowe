#include <FastLED.h>
#include <bluetooth/parser.cpp>

#pragma once
namespace ledstripp
{
void begin();

void rainbow(uint16_t speed = BTParer::jsonDoc["params"]["speed"]);
void moving_rainbow(uint16_t speed = BTParer::jsonDoc["params"]["speed"], int strange_thing = BTParer::jsonDoc["params"]["strange_thing"]);
void random_gradient(int base_color_hue = BTParer::jsonDoc["params"]["base_color_hue"], int value_min = BTParer::jsonDoc["params"]["value_min"], int value_max = BTParer::jsonDoc["params"]["value_max"]);
void moving_palette(CRGBPalette16 palete, uint8_t brightness, uint16_t speed = BTParer::jsonDoc["params"]["speed"]);
void fading_palette(CRGBPalette16 palette = BTParer::jsonDoc["params"]["palette"], uint16_t freeqency = BTParer::jsonDoc["params"]["freeqency"], uint16_t fade_time = BTParer::jsonDoc["params"]["fade_time"]);
void kometa(uint16_t speed = BTParer::jsonDoc["params"]["speed"], uint8_t lenght = BTParer::jsonDoc["params"]["lenght"], uint8_t noise_scale = BTParer::jsonDoc["params"]["noise_scale"], uint8_t blur = BTParer::jsonDoc["params"]["blur"]);

    
} // namespace ledstripp

