/*
    ARDUINO RGB LED TUTORIAL: RAINBOW COLOR
    By: TheGeekPub.com
    More Arduino Tutorials: https://www.thegeekpub.com/arduino-tutorials/
*/
#include <PinConstantDefinition.h>
#include <Arduino.h>

#define SERIAL_DEBUG_ENABLED false

int r_intencity = 254;
int g_intencity = 1;
int b_intencity = 127;
int r_increment = -1;
int g_increment = 1;
int b_increment = -1;
 
/* This function "Set Color" will set the color of the LED
   rather than doing it over and over in the loop above. */
void setColor(int intencity_r, int intencity_g, int intencity_b) {
  analogWrite(pinDigitalFcLedR, intencity_r);
  analogWrite(pinDigitalFcLedG, intencity_g);
  analogWrite(pinDigitalFcLedB, intencity_b);
}
 
void setup() {
  //set all three pins to output mode
  pinMode(pinDigitalFcLedR, OUTPUT);
  pinMode(pinDigitalFcLedG, OUTPUT);
  pinMode(pinDigitalFcLedB, OUTPUT);
}
 
 
void loop() {
  r_intencity = r_intencity + r_increment;   //changing values of LEDs
  g_intencity = g_intencity + g_increment;
  b_intencity = b_intencity + b_increment;
 
  //now change direction for each color if it reaches 255
  if (r_intencity >= 255 || r_intencity <= 0) {
    r_increment = r_increment * -1;
  }

  if (g_intencity >= 255 || g_intencity <= 0) {
    g_increment = g_increment * -1;
  }

  if (b_intencity >= 255 || b_intencity <= 0) {
    b_increment = b_increment * -1;
  }
  setColor(r_intencity, g_intencity, b_intencity);
  delay(10);    //a little delay is needed so you can see the change
}