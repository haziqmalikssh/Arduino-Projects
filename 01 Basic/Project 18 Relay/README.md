# Arduino Mega Relay Control

Control multiple relays with an **Arduino Mega** using the included code and schematics.

## Features
- Supports **up to 16 relays** (expandable).
- Simple ON/OFF control via digital pins.
- Well-commented Arduino code for easy customization.
- Includes wiring schematics.

## Hardware Required
- Arduino Mega 2560  
- Relay Module(s)  
- Jumper Wires  
- Power Supply (sized for your relays)

## Setup
1. Connect the relays to the pins shown in the schematic.
2. Upload the provided `.ino` file to the Arduino Mega.
3. Power the system and test relay switching.

## Usage
Modify the sketch to:
- Change pin assignments  
- Add custom logic (timers, sensors, etc.)  

Upload again to apply changes.

## Notes
- Use external power for high-current relays.
- Add flyback diodes if using bare relays.

## License
MIT License – see [LICENSE](LICENSE) for details.
