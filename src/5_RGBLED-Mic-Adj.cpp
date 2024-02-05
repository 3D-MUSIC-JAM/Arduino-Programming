#include <PinConstantDefinition.h>
#include <Arduino.h>

#define SERIAL_DEBUG_ENABLED false



const int maxAmplitudeForMap = 500;





//internally used
bool firstSpikeDetected;
unsigned long timeOfLastColorChange;
unsigned long timeOfLastValidSampleOrDimming;
bool inDimming = false;
int arrRgbColor[numColors] = {0, 0, 0};
int dimmedIntencity;
unsigned long dimmingInterval;
unsigned long dimmingStartAfter;

void setNewLedColorOnBeat(int signalLevel) {
  unsigned int i;
  for (i=0; i<numColors; i++){
    arrRgbColor[i]=random(signalLevel);
  }
  timeOfLastColorChange = millis();
  if (!firstSpikeDetected){
    firstSpikeDetected = true;
  }
}

void setDutyCycleOfRgbLed(int dutyCycle[numColors], int intencity255, bool isSmallSignal) {
  unsigned int i;
  long dutyCycleWithIntencity[numColors];
  for (i = 0; i < numColors; i++) {
    dutyCycleWithIntencity[i]=dutyCycle[i];
  }
  if (isSmallSignal){
    for (i = 0; i < numColors; i++) {
      dutyCycleWithIntencity[i]=dutyCycleWithIntencity[i]*intencity255/pwmLevelMax;
    }
  }
  for (i = 0; i < numColors; i++) {
    analogWrite(pinDigitalFcLed[i], dutyCycleWithIntencity[i]);
  }
  timeOfLastValidSampleOrDimming = millis();
  if(SERIAL_DEBUG_ENABLED){
    Serial.print(">arrRgbColor[0]:");
    Serial.println(arrRgbColor[0]);
    Serial.print(">arrRgbColor[1]:");
    Serial.println(arrRgbColor[1]);
    Serial.print(">arrRgbColor[2]:");
    Serial.println(arrRgbColor[2]);
    Serial.print(">dutyCycleWithIntencity[0]:");
    Serial.println(dutyCycleWithIntencity[0]);  
    Serial.print(">dutyCycleWithIntencity[1]:");
    Serial.println(dutyCycleWithIntencity[1]);  
    Serial.print(">dutyCycleWithIntencity[2]:");
    Serial.println(dutyCycleWithIntencity[2]);  
  }
}

void dimLedOnSilence() {
  if (
    ((!inDimming)&&(millis() - timeOfLastValidSampleOrDimming > dimmingStartAfter)&&(dimmedIntencity > 0)) ||
    ((inDimming)&&(millis() - timeOfLastValidSampleOrDimming > dimmingInterval)&&(dimmedIntencity > 0))
  ){
      dimmedIntencity -= 10; // About 5% reduction (13/255)
      setDutyCycleOfRgbLed(arrRgbColor, dimmedIntencity, true);
      inDimming = true;
  }
}

void setup() {
  unsigned int i;
  analogReference(EXTERNAL);
  pinMode(LED_BUILTIN,OUTPUT);
  if(SERIAL_DEBUG_ENABLED){
    Serial.begin(SERIAL_DEBUG_BAUD_RATE);
  }
  // Initialize pins
  for (i = 0; i < numColors; i++) {
    pinMode(pinDigitalFcLed[i], OUTPUT);
  }
  firstSpikeDetected = false;
  timeOfLastColorChange = millis();
  timeOfLastValidSampleOrDimming = millis();
}


void loop() {
  int micInputRaw = abs(map(analogRead(pinAnalogMic),0,analogReadMax,-(maxAmplitudeForMap),maxAmplitudeForMap));
  int micInputMapped = map(micInputRaw,0,maxAmplitudeForMap,0,pwmLevelMax);
  int thresholdRawLow = map(analogRead(pinAnalogRv1),0,analogReadMax,0,maxAmplitudeForMap);
  int thresholdRawHigh = map(analogRead(pinAnalogRv2),0,analogReadMax,0,maxAmplitudeForMap);
  int timeMinimumBetweenColorChange = map(analogRead(pinAnalogRv3),0,analogReadMax,0,100);
  unsigned long dimmingInterval = analogRead(pinAnalogRv4);
  unsigned long dimmingStartAfter = dimmingInterval * 5;
  
  if (thresholdRawLow >= thresholdRawHigh){
    thresholdRawHigh = thresholdRawLow;
  }

  if (micInputRaw > thresholdRawLow){
    if(SERIAL_DEBUG_ENABLED){
      Serial.print(">Loop activated at:");
      Serial.println(micInputRaw);
    } 
    if (micInputRaw >= thresholdRawHigh){
        if ((!firstSpikeDetected)||(millis() - timeOfLastColorChange >= timeMinimumBetweenColorChange)){
          setNewLedColorOnBeat(micInputMapped);
          setDutyCycleOfRgbLed(arrRgbColor,micInputMapped,false);
          digitalWrite(LED_BUILTIN,HIGH);
        }
        if(SERIAL_DEBUG_ENABLED){
          Serial.print(">Spike detected:");
          Serial.println(micInputRaw);
        }
    } else {
      setDutyCycleOfRgbLed(arrRgbColor, micInputMapped,true);
      digitalWrite(LED_BUILTIN,LOW);
      if(SERIAL_DEBUG_ENABLED){
        Serial.print(">Spike detected:");
        Serial.println("0");
      }
    }
    dimmedIntencity = micInputMapped;
    inDimming = false;
  } else {
    dimLedOnSilence();
    if(SERIAL_DEBUG_ENABLED){
      Serial.print(">Loop activated at:");
      Serial.println("0");
    } 
  } 
}
