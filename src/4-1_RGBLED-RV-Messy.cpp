#include <PinConstantDefinition.h>
#include <Arduino.h>

#define SERIAL_DEBUG_ENABLED false


void setup() {
  analogReference(EXTERNAL);
  if(SERIAL_DEBUG_ENABLED){
    Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  }
  // Initialize pins
  pinMode(pinDigitalFcLedR, OUTPUT);
  pinMode(pinDigitalFcLedG, OUTPUT);
  pinMode(pinDigitalFcLedB, OUTPUT);
}


void loop() {
  unsigned int brightnessPerRvR = map(analogRead(pinAnalogRv1),0,analogReadMax,0,pwmLevelMax);
  unsigned int brightnessPerRvG = map(analogRead(pinAnalogRv2),0,analogReadMax,0,pwmLevelMax);
  unsigned int brightnessPerRvB = map(analogRead(pinAnalogRv3),0,analogReadMax,0,pwmLevelMax);
  unsigned int brightnessOverall = map(analogRead(pinAnalogRv4),0,analogReadMax,0,pwmLevelMax);

  unsigned int brightnessResultantR = brightnessPerRvR * brightnessOverall / pwmLevelMax;
  unsigned int brightnessResultantG = brightnessPerRvG * brightnessOverall / pwmLevelMax;
  unsigned int brightnessResultantB = brightnessPerRvB * brightnessOverall / pwmLevelMax;

  analogWrite(pinDigitalFcLedR,brightnessResultantR);
  analogWrite(pinDigitalFcLedG,brightnessResultantG);
  analogWrite(pinDigitalFcLedB,brightnessResultantB);

  if(SERIAL_DEBUG_ENABLED){
    Serial.print(">brightnessPerRvR:");
    Serial.println(brightnessPerRvR);
    Serial.print(">brightnessPerRvG:");
    Serial.println(brightnessPerRvG);
    Serial.print(">brightnessPerRvB:");
    Serial.println(brightnessPerRvB);
    Serial.print(">brightnessOverall:");
    Serial.println(brightnessOverall);
    Serial.print(">brightnessResultantR:");
    Serial.println(brightnessResultantR);
    Serial.print(">brightnessResultantG:");
    Serial.println(brightnessResultantG);
    Serial.print(">brightnessResultantB:");
    Serial.println(brightnessResultantB);
  }
}
