#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN pins
const byte address[6] = "00001"; // communication pipe

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello from A";
  radio.write(&text, sizeof(text));
  Serial.println("Sent: Hello from A");
  delay(1000);
}
