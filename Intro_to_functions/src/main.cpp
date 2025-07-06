#include <Arduino.h>

// put function declarations here:
int add(int, int);
double multiply(double, double);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int result = add(2, 3);
  Serial.print("The result of adding 2 and 3 is: ");
  Serial.println(result);

  double product = multiply(2.5, 4.0);
  Serial.print("The product of 2.5 and 4.0 is: ");    
  Serial.println(product);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int add(int x, int y) {
  // This function takes two integers and returns their sum.
  return x + y;
}

double multiply(double a, double b) {
  // This function takes two doubles and returns their product.
  return a * b;
}