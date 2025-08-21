// Define Pins 
#define BLUE 3 
#define GREEN 5 
#define RED 6

void setup() {
  // Initialize pins as outputs
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BLUE, OUTPUT); 
}

void loop() {
  // Example: fade red from 0 to 255
  for (int redValue = 0; redValue <= 255; redValue++) {
    int greenValue = 0; 
    int blueValue = 0;

    // Set LED color
    analogWrite(RED, redValue); 
    analogWrite(GREEN, greenValue); 
    analogWrite(BLUE, blueValue); 

    delay(10); // small delay for visible fading effect
  }

  // Example: fade green from 0 to 255
  for (int greenValue = 0; greenValue <= 255; greenValue++) {
    int redValue = 0; 
    int blueValue = 0;

    analogWrite(RED, redValue); 
    analogWrite(GREEN, greenValue); 
    analogWrite(BLUE, blueValue); 

    delay(10);
  }

  // Example: fade blue from 0 to 255
  for (int blueValue = 0; blueValue <= 255; blueValue++) {
    int redValue = 0; 
    int greenValue = 0;

    analogWrite(RED, redValue); 
    analogWrite(GREEN, greenValue); 
    analogWrite(BLUE, blueValue); 

    delay(10);
  }
}
