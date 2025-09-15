# Ultrasonic Sensor Arduino Mega Project

## Overview
This project demonstrates how to use an ultrasonic sensor with an Arduino Mega to measure distances. The sensor sends out ultrasonic waves and calculates the distance to an object based on the time it takes for the waves to return. The code and schematic for this project are provided in the repository.

## Hardware Requirements
- Arduino Mega 2560
- Ultrasonic Sensor (e.g., HC-SR04)
- Jumper wires
- Breadboard (optional)

## Software Requirements
- Arduino IDE (latest version recommended)
- No additional libraries are required for the provided code.

## Setup
1. **Wiring**: Connect the ultrasonic sensor to the Arduino Mega as shown in the schematic provided in the repository (`schematic.png`).
   - VCC to 5V
   - GND to GND
   - Trig pin to a digital pin (e.g., D9)
   - Echo pin to a digital pin (e.g., D10)
2. **Code**: Upload the provided Arduino code (`ultrasonic_sensor.ino`) to your Arduino Mega using the Arduino IDE.
3. **Serial Monitor**: Open the Serial Monitor in the Arduino IDE (set to 9600 baud) to view the distance measurements.

## How It Works
- The ultrasonic sensor sends a high-frequency sound pulse via the Trig pin.
- The sensor measures the time it takes for the echo to return via the Echo pin.
- The Arduino calculates the distance using the speed of sound (approximately 343 m/s) and displays it in the Serial Monitor.

## Repository Contents
- `ultrasonic_sensor.ino`: The Arduino code for reading distance data from the ultrasonic sensor.
- `schematic.png`: A diagram showing the wiring connections between the ultrasonic sensor and Arduino Mega.

## Usage
1. Clone or download this repository.
2. Open `ultrasonic_sensor.ino` in the Arduino IDE.
3. Connect the hardware as shown in `schematic.png`.
4. Upload the code to the Arduino Mega.
5. Open the Serial Monitor to view real-time distance measurements in centimeters.

## Example Output
The Serial Monitor will display output like:
```
Distance: 25.4 cm
```
This indicates the distance to the nearest object detected by the sensor.

## Troubleshooting
- **No output in Serial Monitor**: Ensure the baud rate is set to 9600 and the correct COM port is selected.
- **Inaccurate readings**: Check the wiring connections and ensure the sensor is facing a solid, reflective surface.
- **Sensor not responding**: Verify the VCC and GND connections, and ensure the Trig and Echo pins are correctly connected.

## Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Suggestions for enhancing the code or schematic are welcome!

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.