#ifndef HIGHGAIN
#define HIGHGAIN
#include <Arduino.h>
const unsigned int pinDigitalFcLedR = 9;
const unsigned int pinDigitalFcLedG = 10;
const unsigned int pinDigitalFcLedB = 11;
const unsigned int pinDigitalPiezoSpk = 8;
const unsigned int pinDigitalServo2 = 6;
const unsigned int pinDigitalServo1 = 5;
const unsigned int pinDigitalSwInt1 = 3;
const unsigned int pinDigitalSwInt0 = 2;
const unsigned int pinDigitalSsTrig = 3;
const unsigned int pinDigitalSsEcho = 2;
const unsigned int pinAnalogMic = A0;
const unsigned int pinAnalogRv1 = A1;
const unsigned int pinAnalogRv2 = A2;
const unsigned int pinAnalogRv3 = A3;
const unsigned int pinAnalogRv4 = A6;
const unsigned int pinAnalogVolDiv = A7;
const unsigned int numColors = 3;
const unsigned int pwmLevelMax = 255;
const unsigned int analogReadMax = 1023;

const unsigned int pinDigitalFcLed[numColors] = {pinDigitalFcLedR, pinDigitalFcLedG, pinDigitalFcLedB};
const unsigned int pinAnalogRvRgb[numColors] = {pinAnalogRv1, pinAnalogRv2, pinAnalogRv3};

#define SERIAL_DEBUG_BAUD_RATE 115200
#endif