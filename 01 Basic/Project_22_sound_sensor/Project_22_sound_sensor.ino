// Pin configuration
const int soundAnalogPin = A0;   // Analog output from sound sensor
const int soundDigitalPin = 2;   // Digital output from sound sensor (connected to D2)
const int ledPin = 13;           // Onboard LED for indication

void setup() {
  Serial.begin(9600);              // Initialize serial communication
  pinMode(soundDigitalPin, INPUT); // Set digital pin as input
  pinMode(ledPin, OUTPUT);         // Set LED pin as output
}

void loop() {
  // Read analog value (sound level)
  int soundLevel = analogRead(soundAnalogPin);
  
  // Read digital value (threshold trigger)
  int soundDetected = digitalRead(soundDigitalPin);
  
  // Print values to Serial Monitor
  Serial.print("Analog Sound Level: ");
  Serial.print(soundLevel);
  Serial.print(" | Digital: ");
  Serial.println(soundDetected);

  // Control LED based on digital output
  if (soundDetected == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on LED if sound detected
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED otherwise
  }
  
  delay(100); // Small delay to make output readable
}
