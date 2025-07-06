#include <Arduino.h>
#include <Servo.h>

// Declarations for servo motors
Servo leftServo;
Servo rightServo;

// put function declarations here:
void straight(int);
void turn(int, double);

void setup() {
  leftServo.attach(13);  // Attach left servo to pin 13
  rightServo.attach(12); // Attach right servo to pin 12
  leftServo.writeMicroseconds(1500);  // Set left servo to neutral position
  rightServo.writeMicroseconds(1500); // Set right servo to neutral position
  delay(500); // Wait for 1/2 second

  // Car movments based on the function inputs go here
  straight(1); // Move straight with 100% effort for 1 second
  delay(500); // Wait for 1/2 second
  turn(1, 0.6); // Turn right for 0.6 seconds (90 degrees)    

   // Stop the motors
   leftServo.detach();
   rightServo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
void straight(int seconds) {
  // This function moves the car straight for a specified distance
  // experimentally determined speed is about 6 inches per second
  int speed = -600; 
  int time = seconds * 1000; // Convert seconds to milliseconds

  leftServo.writeMicroseconds(1500 + speed);  
  rightServo.writeMicroseconds(1550 - speed); 
  delay(time); 
  leftServo.writeMicroseconds(1500);  
  rightServo.writeMicroseconds(1500);
}

void turn(int direction, double seconds) {
  // This function turns the car in place for a specified time
  // experimentally determined 90 degree rotation takes about 0.6 seconds
  // direction: 1 for right, -1 for left
  if (direction != 1 && direction != -1) {
    Serial.println("Invalid direction. Use 1 for right or -1 for left.");
    return;
  }

  int speed = 600*direction; 
  double time = seconds * 1000; // Convert seconds to milliseconds

  leftServo.writeMicroseconds(1500 + speed);  
  rightServo.writeMicroseconds(1500 + speed); 
  delay(time); 
  leftServo.writeMicroseconds(1500);  
  rightServo.writeMicroseconds(1500);
}

