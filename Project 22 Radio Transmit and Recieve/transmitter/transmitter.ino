#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// CE, CSN pins
RF24 radio(9, 10);  
const byte address[6] = "00001";  

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);  
  radio.stopListening();  // Set as transmitter
}

void loop() {
  const char text[] = "Hello from Arduino!";
  radio.write(&text, sizeof(text));
  Serial.println("Message Sent: Hello from Arduino!");
  delay(1000);
}
