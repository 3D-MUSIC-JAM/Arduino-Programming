#include <PinConstantDefinition.h>
#include <Arduino.h>

void setup(){
  pinMode(pinDigitalFcLedR, OUTPUT); 
  pinMode(pinDigitalFcLedG, OUTPUT);
  pinMode(pinDigitalFcLedB, OUTPUT); 
}

void loop() {
  digitalWrite(pinDigitalFcLedR, HIGH);
  delay(1000);
  digitalWrite(pinDigitalFcLedR, LOW);
  digitalWrite(pinDigitalFcLedG, HIGH);
  delay(1000);
  digitalWrite(pinDigitalFcLedG, LOW);
  digitalWrite(pinDigitalFcLedB, HIGH);
  delay(1000);
  digitalWrite(pinDigitalFcLedB, LOW);
}
