# Project 27: Heart Rate Monitor

## Overview
This project implements a heart rate monitor using an Arduino Mega and an AD8232 ECG module. The system collects ECG data, sends it over a serial connection, and processes it using a Python script (`health_ai.py`) to calculate the heart rate (BPM) and determine if it’s within a healthy range (60–100 BPM for resting adults). The Python script also displays a real-time ECG plot using Matplotlib.

**Demo**: Watch a demonstration of the project on YouTube: [Heart Rate Monitor Demo](https://youtu.be/-T7qUnhZs14)

<!-- HTML embed for platforms that support it -->
<p align="center">
  <a href="https://youtu.be/96P55DM7WIA">
    <img src="https://img.youtube.com/vi/96P55DM7WIA/0.jpg" alt="Heart Rate Monitor Demo" width="560" height="315">
  </a>
</p>

## Repository Contents
- Arduino code for reading data from the AD8232 module.
- Python script (`health_ai.py`) for processing ECG data and plotting.
- Schematics for wiring the AD8232 to the Arduino Mega.

## Requirements
- **Hardware**:
  - Arduino Mega 2560
  - AD8232 ECG module
  - USB cable for Arduino
  - ECG electrodes and leads
- **Software**:
  - Arduino IDE (for uploading code)
  - Python 3.6 or higher
  - A virtual environment (e.g., `myenv`) is recommended

## Python Library Dependencies
The `health_ai.py` script requires the following Python libraries:
- `pyserial`: For serial communication with the Arduino.
- `heartpy`: For ECG signal processing and heart rate calculation.
- `numpy`: For numerical operations and data handling.
- `matplotlib`: For real-time ECG plotting.
- `setuptools`: Required by `heartpy` for resource management (use version <81 to avoid deprecation warnings).

Install these libraries in your virtual environment:
```bash
pip install pyserial heartpy numpy matplotlib "setuptools<81"
```

## Setup Instructions
1. **Wire the AD8232 to the Arduino Mega**:
   - OUTPUT → A0
   - LO+ → Pin 10
   - LO- → Pin 11
   - 3.3V → 3.3V
   - GND → GND
   - Attach ECG electrodes to the body (e.g., chest or arms) with good skin contact.

2. **Upload Arduino Code**:
   - Open the Arduino code in the Arduino IDE.
   - Select `Arduino Mega 2560` under Tools > Board.
   - Choose the correct serial port (e.g., `COM4`) under Tools > Port.
   - Upload the code and verify data (0–1023 or `!` for leads-off) in the Serial Monitor (9600 baud).

3. **Set Up the Python Environment**:
   - Create and activate a virtual environment:
     ```bash
     cd C:\Users\n\Documents\GitHub\Arduino-Projects\Project 27 Heart Rate Monitor
     python -m venv myenv
     myenv\Scripts\activate
     ```
   - Install the required libraries:
     ```bash
     pip install pyserial heartpy numpy matplotlib "setuptools<81"
     ```

4. **Update Serial Port in `health_ai.py`**:
   - Open `health_ai.py` and ensure the serial port matches your Arduino’s port (e.g., `COM4`):
     ```python
     ser = serial.Serial('COM4', 9600, timeout=1)
     ```
   - Save the file.

5. **Run the Python Script**:
   - Close the Arduino IDE’s Serial Monitor to free the serial port.
   - Run the script:
     ```bash
     python health_ai.py
     ```
   - The script displays a real-time ECG plot. After ~10 seconds, it prints the heart rate (BPM) and whether it’s healthy (60–100 BPM) to the console.

## Usage
- The real-time ECG plot shows the raw signal (0–1023) from the AD8232.
- After collecting ~10 seconds of data, the plot closes, and the console displays:
  - Calculated heart rate (e.g., `Calculated heart rate: 75.23 BPM`).
  - Health assessment (e.g., `Heart rate is at a healthy level.`).
- Ensure good electrode contact to avoid `!` (leads-off) signals, which may result in insufficient data.

## Troubleshooting
- **Serial Port Error**: If you see `PermissionError: could not open port`, ensure the Serial Monitor or other programs are closed. Verify the port in the Arduino IDE.
- **No Plot Data**: Check AD8232 wiring and electrode placement. Confirm the Serial Monitor shows numbers (0–1023) and not `!`.
- **Library Errors**: Verify all libraries are installed with `pip list` in `myenv`. Reinstall if needed.
- **Noisy Signal**: Adjust electrode placement for better skin contact.

## Notes
- The heart rate analysis uses `heartpy`’s signal processing algorithms, not a machine learning model. Consult a medical professional for accurate health assessments.
- The `pkg_resources` deprecation warning from `heartpy` is harmless but can be suppressed by pinning `setuptools<81`.