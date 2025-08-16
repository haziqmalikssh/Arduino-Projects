int buzzerPin = 8;

// Notes frequencies (in Hz)
int noteC = 262;
int noteD = 294;
int noteE = 330;
int noteG = 392;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Mary had a little lamb (first few notes)
  tone(buzzerPin, noteE, 400);  // E
  delay(500);

  tone(buzzerPin, noteD, 400);  // D
  delay(500);

  tone(buzzerPin, noteC, 400);  // C
  delay(500);

  tone(buzzerPin, noteD, 400);  // D
  delay(500);

  tone(buzzerPin, noteE, 400);  // E
  delay(500);

  tone(buzzerPin, noteE, 400);  // E
  delay(500);

  tone(buzzerPin, noteE, 600);  // E (longer)
  delay(700);

  noTone(buzzerPin); // stop sound
  delay(2000);       // pause before repeating
}
