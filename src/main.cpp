#include <Arduino.h>
#include <ArduinoLog.h>
#include <config.h>
#include <leds.cpp>
#include <buttons.cpp>
#include <bluetooth/bluetooth.cpp>

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);
  Buttons::Begin();
  ledstripp::begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  Buttons::FwdBtn.read();
  Buttons::BwdBtn.read();
  bluetooth::listen();
}

// put function definitions here:
