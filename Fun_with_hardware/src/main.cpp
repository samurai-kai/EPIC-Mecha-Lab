#include <Arduino.h>
#include <LiquidCrystal.h>

// ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

const int Green = 8; // Pin for the green LED
const int Red = 6; // Pin for the red LED
const int speakerPin = 7; // Pin for the speaker

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Function declaration
float ultrasonic();
void printDistance(float distance);
void printDistanceLCD(float distance);
void LEDBlink(int pin, int delayTime);
void LED_ON(int pin);
void LED_OFF(int pin);  
void startSiren();
void updateSiren();

unsigned long sirenLastToggle = 0;
int sirenState = 0;
bool sirenActive = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial communication started");
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  LEDBlink(Green, 1000); // Blink the green LED for 1 second
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2); // 16 columns, 2 rows
  lcd.print("Hello, world!");
}

void loop() {
  float distance = ultrasonic();
  if(distance > 2.54 * 12) {
    LED_ON(Green);
    LED_OFF(Red); 
  } else {
    LED_OFF(Green);
    LED_ON(Red);
    if (!sirenActive) startSiren(); // Only start if not already running
  }
  printDistance(distance);
  printDistanceLCD(distance);
  updateSiren(); // Always call this
  delay(500); // Shorter delay for responsiveness
}

// Function definition
float ultrasonic() {
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; //speed of sound is 0.034 cm/us
  // divide by 2 because the signal travels to the object and back

  return distance;
}

void printDistance(float distance) {
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print(distance / 2.54);
  Serial.println(" in");
}

void printDistanceLCD(float distance) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance / 2.54, 2); // 2 decimal places
  lcd.print(" in");
}

void LEDBlink(int pin, int delayTime) {
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
  delay(delayTime);
}

void LED_ON(int pin) {
  digitalWrite(pin, HIGH);
}

void LED_OFF(int pin) {
  digitalWrite(pin, LOW);
}

void startSiren() {
  if (!sirenActive) {
    sirenActive = true;
    sirenLastToggle = millis();
    sirenState = 0;
    tone(speakerPin, 1000);
  }
}

void updateSiren() {
  if (!sirenActive) return;
  unsigned long now = millis();
  if (now - sirenLastToggle >= 500) {
    sirenLastToggle = now;
    if (sirenState % 2 == 0) {
      noTone(speakerPin);
    } else {
      tone(speakerPin, 1000);
    }
    sirenState++;
    if (sirenState >= 6) { // 3 cycles (on/off)
      noTone(speakerPin);
      sirenActive = false;
    }
  }
}