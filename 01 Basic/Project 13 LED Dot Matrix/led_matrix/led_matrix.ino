#include <LedControl.h>

// Pin configuration for Mega2560
// DIN = 12, CLK = 10, CS =11
LedControl lc = LedControl(12, 10, 11, 1); // (DIN, CLK, CS, number of devices)

void setup() {
  // Initialize the MAX7219
  lc.shutdown(0, false);   // Wake up display
  lc.setIntensity(0, 8);   // Brightness (0–15)
  lc.clearDisplay(0);      // Clear display
}

void loop() {
  // Example: Draw a simple pattern (diagonal line)
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, i, true);   // Turn on LED at (row, column)
    delay(200);
  }

  delay(1000);

  lc.clearDisplay(0);  // Clear display
  delay(500);

  // Example: Show a smiley face
  byte smiley[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };

  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, smiley[row]);
  }

  delay(2000);

  lc.clearDisplay(0);  // Clear display
}
