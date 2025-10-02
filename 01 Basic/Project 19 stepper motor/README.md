# Arduino Mega Stepper Motor Project

## Overview
This project uses an Arduino Mega to control a stepper motor for precise motion control. The code and schematic are included in this repository.

## Requirements
- Arduino Mega 2560
- Stepper motor (e.g., NEMA 17)
- Stepper motor driver (e.g., A4988 or DRV8825)
- Jumper wires
- External power supply for the motor
- Arduino IDE

## Setup
1. Connect the stepper motor and driver to the Arduino Mega as shown in the provided schematic.
2. Upload the included code to the Arduino Mega using the Arduino IDE.
3. Ensure the motor and driver are powered by an appropriate external power supply.

## Code
The code (`stepper_control.ino`) configures the Arduino Mega to control the stepper motor via the driver. It includes functions for:
- Setting motor speed and direction
- Controlling steps or rotations
- Optional microstepping (if supported by the driver)

## Schematic
The schematic (`stepper_schematic.png`) illustrates the wiring between the Arduino Mega, stepper motor driver, and motor.

## Usage
- Open the code in the Arduino IDE.
- Adjust pin assignments, steps per revolution, or speed in the code as needed.
- Upload the code to the Arduino Mega.
- Monitor motor operation via the Serial Monitor (if enabled).

## Notes
- Verify the stepper motor driver’s current limit and microstepping settings.
- Ensure the external power supply matches the motor’s voltage and current requirements.
- Test in a safe environment to avoid overheating or mechanical issues.

## License
MIT License - feel free to use and modify this project.