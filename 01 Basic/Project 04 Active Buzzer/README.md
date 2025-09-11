# Arduino LED Blink Project

## Description
A simple Arduino project that blinks an LED connected to digital pin 13. This is the classic "Hello World" for Arduino beginners.

## Hardware Requirements
- Arduino Uno (or compatible board)
- LED
- 220Ω resistor
- Breadboard
- Jumper wires

## Connections
Based on the provided schematic:

| Arduino Pin | Component | Breadboard Connection |
|-------------|-----------|-----------------------|
| Digital 13 | Resistor (220Ω) | Positive rail via jumper |
| Resistor | LED (long leg/anode) | LED short leg (cathode) to ground rail |
| 5V | Breadboard | Positive power rail |
| GND | Breadboard | Ground rail |

- Connect the LED in series with the resistor between pin 13 and GND.
- Power the breadboard from Arduino's 5V and GND.

## Software Setup
1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Select your board and port in Tools > Board and Tools > Port.
3. Upload the sketch to your Arduino.

## Usage
1. Wire the circuit as shown.
2. Upload the sketch to your Arduino.
3. The onboard LED (or external LED) will blink every second.

## Troubleshooting
- LED not blinking? Check connections and resistor value.
- Upload errors? Verify board/port selection.

## License
MIT License - feel free to use and modify.