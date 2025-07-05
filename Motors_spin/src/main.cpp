#include <Arduino.h>
#include <Servo.h>

// Declarations for servo motors
Servo leftServo;
Servo rightServo;

/*
Example code to spin two motors using Arduino and Servo library.
This code spins the left motor forward and the right motor backward for 
2 seconds, repeating this process 4 times.

If done early, play around with the following:
- Change the "writeMicroseconds" values and observe how the motors behave.
- Try using the "write" method instead of "writeMicroseconds" to see how it 
  affects the servos.

*/

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  leftServo.attach(13);  // Attach left servo to pin 13
  rightServo.attach(12); // Attach right servo to pin 12
  leftServo.writeMicroseconds(1500);  // Set left servo to neutral position
  rightServo.writeMicroseconds(1500); // Set right servo to neutral position
  delay(1000); // Wait for 1 second

  for (int index = 1; index <= 4; index++)  // Loop 4 times (8 seconds total)
    {
    Serial.print("Iteration: ");
    Serial.println(index); // Print the current iteration number
    leftServo.writeMicroseconds(1700);  // Spin left servo forward
    rightServo.writeMicroseconds(1300); // Spin right servo backward
    delay(2000); // Spin for 2 second
  }

  // Stop the motors
  leftServo.detach();  // Detach left servo
  rightServo.detach(); // Detach right servo
}

void loop() {
  // put your main code here, to run repeatedly:
}
