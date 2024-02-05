#include <PinConstantDefinition.h>
#include <Arduino.h>
#include <Servo.h>

#define SERIAL_DEBUG_ENABLED true
#define SERVO_ADJUST_MODE_ENABLED false
Servo FT90B;  // create a servo object

int servoAngle = 0;
unsigned long waitBetweenAngleChanges = 0;
double distanceToObject;
double sensorCapabilityMinInMm = 20;
double sensorCapabilityMaxInMm = 4000;
unsigned long lastAngleChangeTime;

void measureLengthInMm(){
  double durationRoundtrip = 0;
  double durationOneway = 0;
  double distanceToTargetedObject = 512;
  double speedOfSound = 331.5 + 0.6 * 25;
  digitalWrite(pinDigitalSsTrig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(pinDigitalSsTrig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(pinDigitalSsTrig, LOW);
  durationRoundtrip = pulseIn(pinDigitalSsEcho, HIGH);

  if (durationRoundtrip > 0) {
    durationOneway = durationRoundtrip / 2;
    distanceToTargetedObject = durationOneway * speedOfSound * 100 / 100000;
  }
  if ((distanceToTargetedObject >= sensorCapabilityMinInMm)&&(distanceToTargetedObject <= sensorCapabilityMaxInMm)){
    distanceToObject = distanceToTargetedObject;
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void sendAngleToServo(int servoAngle){
  int servoAngleShifted=map(servoAngle, 90, -90, 0, 180);
  FT90B.write(servoAngleShifted);
  lastAngleChangeTime = millis();
}

void setup() {
  if(SERIAL_DEBUG_ENABLED){
    Serial.begin(SERIAL_DEBUG_BAUD_RATE);  // open a serial connection to your computer
  }
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinDigitalSsEcho, INPUT);
  pinMode(pinDigitalSsTrig, OUTPUT);
  FT90B.attach(pinDigitalServo1);   // attaches the servo on pin 9 to the servo object
  sendAngleToServo(servoAngle);
  if(SERVO_ADJUST_MODE_ENABLED){
    delay(300000);
  }
  for (servoAngle = 0; servoAngle >= -90; servoAngle -= 1){
    while (waitBetweenAngleChanges >= millis() - lastAngleChangeTime);
    sendAngleToServo(servoAngle);
    if(SERIAL_DEBUG_ENABLED){
      Serial.print(">servoAngle:");
      Serial.println(servoAngle);
    }
  }
}

void loop() {
  for (servoAngle = -90; servoAngle <= 90; servoAngle += 1){
    while (waitBetweenAngleChanges >= millis() - lastAngleChangeTime);
    sendAngleToServo(servoAngle);
    measureLengthInMm();
    if(SERIAL_DEBUG_ENABLED){
      Serial.print(">servoAngle:");
      Serial.println(servoAngle);
      Serial.print(">distanceToObject:");
      Serial.println(distanceToObject);
    }
  }

  for (servoAngle = 90; servoAngle >= -90; servoAngle -= 1){
    while (waitBetweenAngleChanges >= millis() - lastAngleChangeTime);
    sendAngleToServo(servoAngle);
    measureLengthInMm();
    if(SERIAL_DEBUG_ENABLED){
      Serial.print(">servoAngle:");
      Serial.println(servoAngle);
      Serial.print(">distanceToObject:");
      Serial.println(distanceToObject);
    }
  }
}
