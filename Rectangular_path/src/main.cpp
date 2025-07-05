#include <Arduino.h>
#include <Servo.h>

// Declarations for servo motors
Servo leftServo;
Servo rightServo;

// Constants for servo positions
const int turnRight = 850; // Right turn position in microseconds

/*
Example Arduino code to move a car in a rectangular path.
Adjust values for motor speed and run duration as needed.

Was your code repeatable? How can we improve it?

How can we make the code more modular and reusable?
*/

void setup() {
  leftServo.attach(13);  // Attach left servo to pin 13
  rightServo.attach(12); // Attach right servo to pin 12
  leftServo.writeMicroseconds(1500);  // Set left servo to neutral position
  rightServo.writeMicroseconds(1500); // Set right servo to neutral position
  delay(1000); // Wait for 1 second

  for (int i = 0; i < 2; i++) { // Two long sides
    // Move forward (adjust time for your car's rectangle length)
    leftServo.writeMicroseconds(1700);
    rightServo.writeMicroseconds(1300);
    delay(2000);

    // Turn 90 degrees (pivot right, adjust time for your car's turn)
    leftServo.writeMicroseconds(1700);
    rightServo.writeMicroseconds(1700);
    delay(turnRight);

    // Move forward (short side)
    leftServo.writeMicroseconds(1700);
    rightServo.writeMicroseconds(1300);
    delay(1000);

    // Turn 90 degrees (pivot right)
    leftServo.writeMicroseconds(1700);
    rightServo.writeMicroseconds(1700);
    delay(turnRight);
  }

  // Stop the motors
  leftServo.detach();
  rightServo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
}
