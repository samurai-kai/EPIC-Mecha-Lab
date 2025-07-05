#include <Arduino.h> // remove this line if you are using Arduino IDE

/* 
Simple 2 tone buzzer circuit
This code will sound a buzzer for 6 seconds,
first with a 500 Hz tone for 80 cycles, then with a 250 Hz tone for 100 cycles.

If you complete this activity early play around with the following:
- Change the delay times in the for loops and see how it affects the sound.
- Change the number of cycles in the for loops and see how it affects the sound.
- Try to combine the LED and buzzer circuits to make a light and sound circuit.
*/

unsigned long second = 1000; // 1 second in milliseconds
const int buzzerPin = 7; // Pin connected to the buzzer
const unsigned long buzzerDuration = 6 * second; // 6 seconds in milliseconds

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  if (millis() < buzzerDuration) {  // Check if 6 seconds have passed
    unsigned char i;

    for (i = 0; i < 80; i++) // loops 80 times
    {  
      digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
      delay(1);                     // Wait for 1 milliseconds
      digitalWrite(buzzerPin, LOW);  // Turn the buzzer off
      delay(1);                     // Wait for 1 milliseconds
      }
    
    for ( i = 0; i < 100; i++) // loops 100 times
    {  
      digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
      delay(2);                     // Wait for 1 milliseconds
      digitalWrite(buzzerPin, LOW);  // Turn the buzzer off
      delay(2);                     // Wait for 1 milliseconds
      }

    } 
}

void loop() {
  // The loop function is intentionally left empty
  // as the buzzer will only sound once in setup
}


