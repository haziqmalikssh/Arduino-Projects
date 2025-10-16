//library for keypad
#include <Keypad.h>

// Define keypad size
const byte ROWS = 4; 
const byte COLS = 4;  

// Define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2, ROW3 to Arduino pins
byte rowPins[ROWS] = {9, 8, 7, 6}; // D9, D8, D7, D6

// Connect keypad COL0, COL1, COL2, COL3 to Arduino pins
byte colPins[COLS] = {5, 4, 3, 2}; // D5, D4, D3, D2

// Create keypad object that maps key input to rown pina and columns
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Test: Press keys...");
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) { // If a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
