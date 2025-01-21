#include <Arduino.h>
#include <math.h> // For sin() and M_PI
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

// Debug toggle
#define ENABLE_DEBUG true

// Pins for rotary encoder
const int pinRotEnc_A = 2; // Encoder pin A
const int pinRotEnc_B = 3; // Encoder pin B
volatile int posRotEnc = 0; // Track rotary encoder position

// Pins for RGB-LEDs
const int pinRed_Top = 9;       // Top-half Red
const int pinGreen_Top = 10;    // Top-half Green
const int pinBlue_Top = 11;     // Top-half Blue
const int pinRed_Bottom = 6;      // Bottom-half Red
const int pinGreen_Bottom = 5;    // Bottom-half Green
const int bluePin_Bottom = 3;     // Bottom-half Blue

// Pin for toggle switch
const int pinSwLedMode = 4;    // Digital input for toggle switch

// Pins for HC-SR04
const int pinSr04Trig = 7;
const int pinSr04Echo = 8;

// LSM9DS1 setup (G-sensor)
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

// Interrupt handler for rotary encoder
void handlerRotEnc() {
  static int stateLastRotEnc_A = LOW;
  int stateCurrentRotEnc_A = digitalRead(pinRotEnc_A);
  if (stateCurrentRotEnc_A != stateLastRotEnc_A) {
    if (digitalRead(pinRotEnc_B) != stateCurrentRotEnc_A) {
      posRotEnc++; // Clockwise
    } else {
      posRotEnc--; // Counterclockwise
    }
  }
  stateLastRotEnc_A = stateCurrentRotEnc_A;
}

// Function to get distance from HC-SR04
long handlerDistance() {
  digitalWrite(pinSr04Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinSr04Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinSr04Trig, LOW);
  long duration = pulseIn(pinSr04Echo, HIGH);
  return duration * 0.034 / 2; // Distance in cm
}

// Function to calculate sinusoidal brightness with dynamic inputs
void calculateSinusoidalBrightness(int angle, int baseR, int baseG, int baseB, int phaseOffset, int &rOut, int &gOut, int &bOut) {
  // Normalize angle to 0-360 degrees
  angle = (angle + phaseOffset) % 360;
  if (angle < 0) angle += 360;

  // Convert angle to radians
  float radAngle = angle * M_PI / 180.0;

  // Calculate sinusoidal brightness for each color
  rOut = (int)(((sin(radAngle) + 1) / 2.0) * baseR);
  gOut = (int)(((sin(radAngle - 2 * M_PI / 3) + 1) / 2.0) * baseG); // 120° offset
  bOut = (int)(((sin(radAngle - 4 * M_PI / 3) + 1) / 2.0) * baseB); // 240° offset
}

void setup() {
  Serial.begin(9600);

  // Initialize rotary encoder pins
  pinMode(pinRotEnc_A, INPUT_PULLUP);
  pinMode(pinRotEnc_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinRotEnc_A), handlerRotEnc, CHANGE);

  // Initialize RGB LED pins
  pinMode(pinRed_Top, OUTPUT);
  pinMode(pinGreen_Top, OUTPUT);
  pinMode(pinBlue_Top, OUTPUT);
  pinMode(pinRed_Bottom, OUTPUT);
  pinMode(pinGreen_Bottom, OUTPUT);
  pinMode(bluePin_Bottom, OUTPUT);

  // Initialize toggle switch pin
  pinMode(pinSwLedMode, INPUT_PULLUP); // Assuming toggle switch is normally HIGH

  // Initialize HC-SR04 pins
  pinMode(pinSr04Trig, OUTPUT);
  pinMode(pinSr04Echo, INPUT);

  // Initialize LSM9DS1 (G-sensor)
  if (!lsm.begin()) {
    if (ENABLE_DEBUG) Serial.println("Failed to initialize LSM9DS1!");
    while (1);
  }
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_8G);
}

void loop() {
  // Get dynamic brightness inputs
  lsm.read(); // Read G-sensor data
  float accelX = lsm.accelData.x;
  float accelY = lsm.accelData.y;
  float accelZ = lsm.accelData.z;
  long distance = handlerDistance();
  if (distance > 100) distance = 100; // Cap distance for scaling

  // Calculate base brightness values from G-sensor and distance
  int baseR = (int)(map(abs(accelX * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));
  int baseG = (int)(map(abs(accelY * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));
  int baseB = (int)(map(abs(accelZ * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));

  // Calculate sinusoidal rotation
  int angle = (posRotEnc * 360) / 24; // Map encoder position to 0-360°

  // Check toggle switch state
  bool isSwitched = digitalRead(pinSwLedMode) == LOW; // Assuming LOW when toggled

  // Phase offset for the second LED
  int phaseOffset = isSwitched ? 180 : 0;

  // Calculate blended brightness for top and bottom LEDs
  int blendedR1, blendedG1, blendedB1;
  int blendedR2, blendedG2, blendedB2;
  calculateSinusoidalBrightness(angle, baseR, baseG, baseB, 0, blendedR1, blendedG1, blendedB1);
  calculateSinusoidalBrightness(angle, baseR, baseG, baseB, phaseOffset, blendedR2, blendedG2, blendedB2);

  // Set brightness for top-half LED
  analogWrite(pinRed_Top, blendedR1);
  analogWrite(pinGreen_Top, blendedG1);
  analogWrite(pinBlue_Top, blendedB1);

  // Set brightness for bottom-half LED
  analogWrite(pinRed_Bottom, blendedR2);
  analogWrite(pinGreen_Bottom, blendedG2);
  analogWrite(bluePin_Bottom, blendedB2);

  // Debug output
  if (ENABLE_DEBUG) {
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" | Toggle: ");
    Serial.print(isSwitched ? "ON" : "OFF");
    Serial.print(" | Top R: ");
    Serial.print(blendedR1);
    Serial.print(" G: ");
    Serial.print(blendedG1);
    Serial.print(" B: ");
    Serial.print(blendedB1);
    Serial.print(" | Bottom R: ");
    Serial.print(blendedR2);
    Serial.print(" G: ");
    Serial.print(blendedG2);
    Serial.print(" B: ");
    Serial.println(blendedB2);
  }

  delay(50); // Small delay for stability
}
