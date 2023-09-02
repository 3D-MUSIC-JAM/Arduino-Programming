#include <Arduino.h>
#include <PinConstantDefinition.h>

void setup(){
  unsigned int i;
  while(!Serial);
  Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  /*
  for (i = 0; i < numColors; i++){
    pinMode(pinDigitalFcLed[i],OUTPUT);
    digitalWrite(pinDigitalFcLed[i],LOW);
  }
  */
  Serial.println("Starting...");
  delay(3000);
}

void loop() {
  //unsigned int i;
  unsigned long second;
  unsigned int t_hour;
  unsigned int t_minute;
  unsigned int t_second;
  unsigned long t_lastcount=millis();
  unsigned int interval_ms = 1000;
  for (second=0; second<=86400; second++){
    while (millis()-t_lastcount<interval_ms);
    t_hour = second / 3600;
    t_minute = (second - t_hour * 3600) / 60;
    t_second = second % 60;
    if (second % 2 == 1){
      digitalWrite(LED_BUILTIN,HIGH);
    } else {
      digitalWrite(LED_BUILTIN,LOW);
    }
    /*
    for (i = 0; i < numColors; i++){
      digitalWrite(pinDigitalFcLed[i],LOW);
    }
    digitalWrite(pinDigitalFcLed[(second % numColors)],HIGH);
    */
    Serial.print(second);
    Serial.print(":\t");
    if (t_hour > 0){
      Serial.print(t_hour);
      Serial.print("h");
    }
    if ((t_minute > 0)||(t_hour > 0)){
      Serial.print(t_minute);
      Serial.print("m");
    }
    Serial.print(t_second);
    Serial.println("s");
    t_lastcount=millis();
  }
}
