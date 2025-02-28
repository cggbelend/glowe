#include <Arduino.h>
#include <ArduinoLog.h>
#include <config.h>
#include <leds.h>
#include <bluetooth/bluetooth.h>

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);
  ledstripp::begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  bluetooth::listen();
}

// put function definitions here:
