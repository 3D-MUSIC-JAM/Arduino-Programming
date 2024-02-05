#include <PinConstantDefinition.h>
#include <Arduino.h>

#define SERIAL_DEBUG_ENABLED false


void setup() {
  int i;
  analogReference(EXTERNAL);
  if(SERIAL_DEBUG_ENABLED){
    Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  }
  // Initialize pins
  for (i = 0; i < numColors; i++) {
    pinMode(pinDigitalFcLed[i], OUTPUT);
  }
}


void loop() {
  unsigned int i;
  int brightnessPerRv[numColors];
  int brightnessOverall;
  int brightnessResultant[numColors];
  
  brightnessOverall = map(analogRead(pinAnalogRv4),0,analogReadMax,0,pwmLevelMax);
  for (i=0; i<numColors; i++){
    brightnessPerRv[i] = map(analogRead(pinAnalogRvRgb[i]),0,analogReadMax,0,pwmLevelMax);
    brightnessResultant[i] = brightnessPerRv[i] * brightnessOverall / pwmLevelMax;
    analogWrite(pinDigitalFcLed[i],brightnessResultant[i]);
  }

  if(SERIAL_DEBUG_ENABLED){
    Serial.print(">R(Rv):");
    Serial.println(brightnessPerRv[0]);
    Serial.print(">G(Rv):");
    Serial.println(brightnessPerRv[1]);
    Serial.print(">B(Rv):");
    Serial.println(brightnessPerRv[2]);
    Serial.print(">brightnessOverall:");
    Serial.println(brightnessOverall);
    Serial.print(">R:");
    Serial.println(brightnessResultant[0]);
    Serial.print(">G:");
    Serial.println(brightnessResultant[1]);
    Serial.print(">B:");
    Serial.println(brightnessResultant[2]);
  }
}
