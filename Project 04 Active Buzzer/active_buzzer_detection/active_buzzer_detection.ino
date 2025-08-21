const int pwmPin = 3;       // PWM output pin
const int buzzerPin = 4;    // Detects active buzzer
const int ledPin = 9;       // LED indicates buzzer is active

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(buzzerPin, INPUT); // Read buzzer state
  pinMode(ledPin, OUTPUT);

  // Start PWM at 50% duty cycle
  analogWrite(pwmPin, 128);

  Serial.begin(9600); // For debugging/plotting
}

void loop() {
  int buzzerState = digitalRead(buzzerPin); // HIGH if buzzer is active

  if (buzzerState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  Serial.println(buzzerState); // Plot in Serial Plotter
  delay(100);
}
