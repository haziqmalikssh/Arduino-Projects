#include <IRremote.h>

int RECV_PIN = 11;       // Pin where the IR receiver is connected (use any digital pin)
IRrecv irrecv(RECV_PIN); // Create IR receiver object
decode_results results;  // Store results from remote

void setup() {
  Serial.begin(9600);    // Start serial monitor
  irrecv.enableIRIn();   // Start the receiver
  irrecv.blink13(true);  // Blink onboard LED when receiving
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the HEX code received
    Serial.print("IR Code: ");
    Serial.println(results.value, HEX);

    // Example: take action based on specific button codes
    switch (results.value) {
      case 0xFFA25D:  // Example: Power button
        Serial.println("Power button pressed");
        break;
      case 0xFFE21D:  // Example: Play/Pause
        Serial.println("Play/Pause button pressed");
        break;
      case 0xFF629D:  // Example: Volume Up
        Serial.println("Volume Up button pressed");
        break;
      case 0xFFA857:  // Example: Volume Down
        Serial.println("Volume Down button pressed");
        break;
      default:
        Serial.println("Other button");
        break;
    }

    // Handle key hold (repeat)
    if (results.repeat) {
      Serial.println("Key is being held down...");
    }

    irrecv.resume(); // Receive the next value
  }
}
