#include <Arduino.h>
#include <math.h> // For sin() and M_PI
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

// Debug toggle
#define ENABLE_DEBUG true

// Pins for rotary encoder
const int pinA = 2; // Encoder pin A
const int pinB = 3; // Encoder pin B
volatile int encoderPosition = 0; // Track rotary encoder position

// Pins for RGB-LEDs
const int redPin = 9;       // Top-half Red
const int greenPin = 10;    // Top-half Green
const int bluePin = 11;     // Top-half Blue
const int redPin2 = 6;      // Bottom-half Red
const int greenPin2 = 5;    // Bottom-half Green
const int bluePin2 = 3;     // Bottom-half Blue

// Pin for toggle switch
const int switchPin = 4;    // Digital input for toggle switch

// Pins for HC-SR04
const int trigPin = 7;
const int echoPin = 8;

// LSM9DS1 setup (G-sensor)
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

// Interrupt handler for rotary encoder
void encoderISR() {
  static int lastAState = LOW;
  int currentAState = digitalRead(pinA);
  if (currentAState != lastAState) {
    if (digitalRead(pinB) != currentAState) {
      encoderPosition++; // Clockwise
    } else {
      encoderPosition--; // Counterclockwise
    }
  }
  lastAState = currentAState;
}

// Function to get distance from HC-SR04
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
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
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), encoderISR, CHANGE);

  // Initialize RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);

  // Initialize toggle switch pin
  pinMode(switchPin, INPUT_PULLUP); // Assuming toggle switch is normally HIGH

  // Initialize HC-SR04 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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
  long distance = getDistance();
  if (distance > 100) distance = 100; // Cap distance for scaling

  // Calculate base brightness values from G-sensor and distance
  int baseR = (int)(map(abs(accelX * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));
  int baseG = (int)(map(abs(accelY * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));
  int baseB = (int)(map(abs(accelZ * 100), 0, 800, 0, 255) * (1.0 - distance / 100.0));

  // Calculate sinusoidal rotation
  int angle = (encoderPosition * 360) / 24; // Map encoder position to 0-360°

  // Check toggle switch state
  bool isSwitched = digitalRead(switchPin) == LOW; // Assuming LOW when toggled

  // Phase offset for the second LED
  int phaseOffset = isSwitched ? 180 : 0;

  // Calculate blended brightness for top and bottom LEDs
  int blendedR1, blendedG1, blendedB1;
  int blendedR2, blendedG2, blendedB2;
  calculateSinusoidalBrightness(angle, baseR, baseG, baseB, 0, blendedR1, blendedG1, blendedB1);
  calculateSinusoidalBrightness(angle, baseR, baseG, baseB, phaseOffset, blendedR2, blendedG2, blendedB2);

  // Set brightness for top-half LED
  analogWrite(redPin, blendedR1);
  analogWrite(greenPin, blendedG1);
  analogWrite(bluePin, blendedB1);

  // Set brightness for bottom-half LED
  analogWrite(redPin2, blendedR2);
  analogWrite(greenPin2, blendedG2);
  analogWrite(bluePin2, blendedB2);

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
