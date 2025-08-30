# Arduino Radio Project

## Overview
Wireless comms between 2 Arduinos using radio modules (e.g., NRF24L01).

## Requirements
- 2 x Arduino Uno
- 2 x NRF24L01
- Breadboard, jumper wires, USB cables
- Optional: 3.3V power supply

## Setup
- Connect radio VCC to 3.3V, GND to GND
- Wire CE, CSN, SCK, MOSI, MISO to pins (e.g., 7, 8, 13, 11, 12)
- Attach antenna securely

## Install
- Use Arduino IDE
- Add RF24 library via Library Manager

## Usage
- Upload `transmitter.ino` and `receiver.ino`
- Power boards, open Serial Monitor (Ctrl+Shift+M)

## Troubleshoot
- Use 3.3V for radio
- Check wire connections
- Match pin configs in code

## License
Open-source, modify freely