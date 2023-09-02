#include <Arduino.h>
#include <PinConstantDefinition.h>

void setup(){
  Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  while(!Serial);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.println("Starting...");
  delay(3000);
}

void loop() {
  Serial.println("Hello!");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  Serial.println("Goodbye!");
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
