/*
  Blink Example for Arduino Mega
*/

const int ledPin = 13; // Onboard LED pin on Arduino Mega

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(250);                // Wait 0.25 second
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(250);                // Wait 0.25 second
}
