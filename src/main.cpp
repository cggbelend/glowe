#include <Arduino.h>
#include <ArduinoLog.h>
#include <leds.h>
#include <buttons.h>

void setup() {
Serial.begin(9600);
Log.begin(LOG_LEVEL_VERBOSE, &Serial);
buttons::begin;
leds::Begin();
}

void loop() {
buttons::update(150);
}

