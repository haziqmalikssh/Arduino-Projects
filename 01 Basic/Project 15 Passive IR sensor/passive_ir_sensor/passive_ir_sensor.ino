const int pirPin = 10; // PIR sensor connected to digital pin 10
const int ledPin = 13; // LED connected to digital pin 13

void setup() {
  pinMode(pirPin, INPUT);    // Set PIR pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Start serial communication
}

void loop() {
  int pirState = digitalRead(pirPin); // Read PIR sensor state
  
  if (pirState == HIGH) {            // If motion is detected
    digitalWrite(ledPin, HIGH);      // Turn LED on
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);       // Turn LED off
    Serial.println("No motion");
  }
  
  delay(1000); // Delay 1 second between readings
}