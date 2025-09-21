# Arduino Mega Passive IR Sensor Project

## Overview
This project uses an Arduino Mega to interface with a passive infrared (PIR) sensor for motion detection. The code and schematics are included in this repository.

## Features
- Detects motion using a PIR sensor.
- Outputs detection status to the Serial Monitor.
- Configurable sensitivity and delay settings.

## Requirements
- Arduino Mega 2560
- Passive Infrared (PIR) Sensor (e.g., HC-SR501)
- Jumper wires
- Arduino IDE

## Setup
1. **Hardware**: Connect the PIR sensor to the Arduino Mega as shown in the schematics (`/schematics` folder).
   - VCC to 5V
   - GND to GND
   - OUT to a digital pin (defined in code)
2. **Software**: Install the Arduino IDE and open the `.ino` file from the `/code` folder.
3. Upload the code to the Arduino Mega.

## Usage
- Power the Arduino Mega.
- Open the Serial Monitor (9600 baud) to view motion detection status.
- Adjust PIR sensor sensitivity and delay using onboard potentiometers if needed.

## Repository Contents
- `/code`: Arduino sketch (`.ino`) for the PIR sensor.
- `/schematics`: Wiring diagram for the setup.

## Notes
- Ensure the PIR sensor has a clear line of sight for optimal detection.
- Modify the code (e.g., pin assignments, delay) as needed for your application.

## License
MIT License. See `LICENSE` file for details.