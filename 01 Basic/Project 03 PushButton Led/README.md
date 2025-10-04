# Arduino Pushbutton LED Project

## Overview
This project demonstrates how to control an LED using a pushbutton with an Arduino microcontroller. The LED turns on when the button is pressed and turns off when released, providing a basic introduction to digital input and output.

## Hardware Requirements
- Arduino Uno (or compatible board)
- LED (e.g., red, 5mm)
- 220Ω Resistor (for LED)
- Pushbutton
- 10kΩ Resistor (pull-down resistor for button)
- Breadboard
- Jumper wires
- USB cable for Arduino

## Circuit Diagram
-The circuit diagram is shown above
## Software Requirements
- Arduino IDE (latest version recommended)

## Installation
1. Assemble the hardware according to the circuit diagram.
2. Open the Arduino IDE.
3. Upload the provided sketch (`pushbuttonDetectled.ino`) to the Arduino board.
4. Ensure the correct board and port are selected in the IDE.

## Usage
- Press the pushbutton to turn the LED on.
- Release the button to turn the LED off.
- Modify the code to add debouncing or additional functionality as needed.

## Code
The accompanying ino file contains the Arduino sketch to control the LED with the pushbutton. Place it in the same directory as this README for proper project structure.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For questions or support, please open an issue in the repository or contact the maintainer.