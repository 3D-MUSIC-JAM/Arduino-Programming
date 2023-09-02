#include <PinConstantDefinition.h>
#include <Arduino.h>

#define SERIAL_DEBUG_ENABLED true

unsigned int whiteComponent = 1;
const unsigned int increment = 3;


void setup() {
  analogReference(DEFAULT);
  if(SERIAL_DEBUG_ENABLED){
    Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  }
}


void loop() {
  unsigned int i,j,k;
  unsigned int realincrement = whiteComponent * whiteComponent;
  if (whiteComponent<=256){
    for (i=whiteComponent; i < whiteComponent+realincrement; i++){
      for (j=whiteComponent; j < whiteComponent+realincrement; j++){
        for (k=whiteComponent; k < whiteComponent+realincrement; k++){
          analogWrite(pinDigitalFcLedR,i);
          analogWrite(pinDigitalFcLedG,j);
          analogWrite(pinDigitalFcLedB,k);
          if(SERIAL_DEBUG_ENABLED){
            Serial.print(">N:");
            Serial.println(whiteComponent);
            Serial.print(">R:");
            Serial.println(i);
            Serial.print(">G:");
            Serial.println(j);
            Serial.print(">B:");
            Serial.println(k);
          }
          delay(250/realincrement);
        }
      }
    }
    whiteComponent = whiteComponent + realincrement;
  }
}
