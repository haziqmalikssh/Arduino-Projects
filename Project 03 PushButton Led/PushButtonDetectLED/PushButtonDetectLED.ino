const int pwmPin = 3;    
const int buttonPin = 28; 
const int ledPin = 9;    

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  analogWrite(pwmPin, 128); // 50% PWM

  Serial.begin(9600); // Start serial communication
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  Serial.print("Button state: ");
  Serial.println(buttonState);

  delay(200); // Slow down serial output
}
