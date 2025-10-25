import serial
import numpy as np
import matplotlib.pyplot as plt
from collections import deque
import time

# -------------------------
# CONFIG
# -------------------------
SERIAL_PORT = 'COM5'        # Arduino serial port
BAUD_RATE = 9600
BUFFER_SIZE = 200           # Number of recent readings to keep
CLASSIFIER_THRESHOLD = 0.5  # Logistic regression threshold

# -------------------------
# SETUP SERIAL
# -------------------------
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT}")
except Exception as e:
    print(f"Error connecting to {SERIAL_PORT}: {e}")
    exit()

time.sleep(2)  # Give Arduino time to reset

# -------------------------
# INITIALIZE DATA STORAGE
# -------------------------
data_buffer = deque(maxlen=BUFFER_SIZE)
time_buffer = deque(maxlen=BUFFER_SIZE)
classification_buffer = deque(maxlen=BUFFER_SIZE)

# -------------------------
# SIMPLE NUMPY-BASED CLASSIFIER
# Logistic regression example: y_hat = sigmoid(w*x + b)
# For demonstration, w=0.01, b=-5 (roughly tuned)
# -------------------------
w = 0.01
b = -5

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def classify(reading):
    z = w * reading + b
    y_hat = sigmoid(z)
    return 1 if y_hat > CLASSIFIER_THRESHOLD else 0  # 1 = Healthy, 0 = Unhealthy

# -------------------------
# SETUP MATPLOTLIB
# -------------------------
plt.ion()
fig, ax = plt.subplots(figsize=(10, 4))
line_data, = ax.plot([], [], label='Pulse Sensor')
line_class, = ax.plot([], [], label='Classification')
ax.set_ylim(0, 1025)
ax.set_xlabel("Sample")
ax.set_ylabel("Analog Reading")
ax.set_title("Pulse Sensor Readings & Health Classification")
ax.legend()

# Add a dynamic text label for classification
status_text = ax.text(0.02, 0.95, "", transform=ax.transAxes, fontsize=14,
                      color='green', weight='bold', bbox=dict(facecolor='white', alpha=0.7))

# -------------------------
# MAIN LOOP
# -------------------------
try:
    while True:
        # Read a line from Serial
        line = ser.readline().decode('utf-8').strip()
        if not line:
            continue
        try:
            reading = int(line)
        except ValueError:
            continue  # Skip invalid lines

        # Store in buffers
        data_buffer.append(reading)
        classification_buffer.append(classify(reading))
        time_buffer.append(len(time_buffer))

        # Update plot lines
        line_data.set_xdata(time_buffer)
        line_data.set_ydata(data_buffer)
        line_class.set_xdata(time_buffer)
        # Map classification 0->200, 1->800 for visualization
        line_class.set_ydata([800 if c == 1 else 200 for c in classification_buffer])
        ax.set_xlim(max(0, time_buffer[0]), time_buffer[-1]+1)

        # Update dynamic status text (green = Healthy, red = Unhealthy)
        current_status = "Healthy" if classify(reading) == 1 else "Unhealthy"
        status_text.set_text(current_status)
        status_text.set_color('green' if current_status == "Healthy" else 'red')

        plt.pause(0.001)

except KeyboardInterrupt:
    print("\nExiting...")
finally:
    ser.close()
