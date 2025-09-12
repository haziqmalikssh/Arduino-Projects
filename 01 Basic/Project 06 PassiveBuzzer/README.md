# Passive Buzzer Arduino Mega Projects

## Overview
This repository contains example projects for using a passive buzzer with an Arduino Mega to create sounds, including single tones, melodies, and button-controlled buzzing.

## Hardware Requirements
- Arduino Mega 2560
- Passive buzzer module (e.g., KY-006)
- Pushbutton (for button-controlled project)
- 10kΩ resistor (for button-controlled project)
- Jumper wires
- Breadboard (optional)

## Software Requirements
- Arduino IDE (latest version)

## Setup
1. Connect the buzzer's positive pin to a PWM-capable pin (e.g., pin 9) and negative pin to GND.
2. For button-controlled project, connect a pushbutton to a digital pin (e.g., pin 2) with a 10kΩ pull-down resistor to GND.
3. Open the project code in the Arduino IDE, select Arduino Mega 2560, and upload.

## Projects
- **Simple Tone Generator**: Plays a single 440 Hz tone.
- **Playing a Melody**: Plays a sequence of notes (e.g., Twinkle Twinkle Little Star).
- **Button-Controlled Buzzer**: Plays a tone when a button is pressed.
## Installation
1. Clone or download this repository.
2. Open the `.ino` file for the desired project in the Arduino IDE.
3. Connect your Arduino Mega via USB.
4. Select the correct board and port, then upload the code.

## Usage
Refer to the schematic in the repository for wiring. Upload the code for the desired project and follow the comments in the code for specific behavior.

## Troubleshooting
- **No sound**: Check buzzer wiring, ensure it’s a passive buzzer, and verify the correct PWM pin.
- **Button issues**: Confirm pull-down resistor and correct pin in code.
- **Upload errors**: Check board/port selection and USB connection.

## License
MIT License. See the [LICENSE](LICENSE) file for details.