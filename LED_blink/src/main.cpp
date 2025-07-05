#include <Arduino.h> // remove this line if you are using Arduino IDE

/* 
Simple LED Blink Example
This code will blink an LED connected to pin 8 on the Arduino Uno.
You can modify the pin number and delay time as needed.

If you complete this activity early play around with the following:
- Change the pin number to another digital pin.
- Change the delay time to make the LED blink faster or slower.
- Add a second LED on another pin and make it blink in sync or out of sync with
  the first LED.
- Add a button to the cicuit to control the LED state (on/off).
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT); // Set pin 8 as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH); // Turn the LED on
  delay(1000);          // Wait for a second
  digitalWrite(8, LOW);  // Turn the LED off
  delay(1000);          // Wait for a second
}
