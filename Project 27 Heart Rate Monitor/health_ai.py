import serial
import heartpy as hp
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Configure serial port (replace 'COM5' with your Arduino Mega's port)
ser = serial.Serial('COM5', 9600, timeout=1)

# Parameters
num_samples = 10000  # ~10 seconds at 1000 Hz
plot_window = 1000   # Number of samples to show in real-time plot
data = []            # Full data for heart rate analysis
plot_data = []       # Buffer for real-time plotting
sample_rate = 1000.0 # Approximate sampling rate from Arduino

# Set up the plot
fig, ax = plt.subplots()
line, = ax.plot([], [])
ax.set_xlim(0, plot_window)
ax.set_ylim(0, 1024)  # Arduino ADC range
ax.set_xlabel('Sample')
ax.set_ylabel('ECG Signal (ADC Value)')
ax.set_title('Real-Time ECG Signal')

def init():
    line.set_data([], [])
    return (line,)  # Return a tuple of artists

def update(frame):
    global plot_data
    try:
        line_data = ser.readline().decode('utf-8').strip()
        if line_data and line_data != '!':  # Ignore leads-off indicator
            value = int(line_data)
            data.append(value)      # Store for heart rate analysis
            plot_data.append(value) # Store for plotting
            if len(plot_data) > plot_window:
                plot_data.pop(0)    # Keep only the latest plot_window samples
            # Update plot
            line.set_data(range(len(plot_data)), plot_data)
            if len(data) >= num_samples:
                ani.event_source.stop()  # Stop animation after collecting enough data
        return (line,)  # Always return a tuple of artists
    except (ValueError, UnicodeDecodeError):
        return (line,)  # Return artist even if data is invalid

# Start real-time plotting
ani = FuncAnimation(fig, update, init_func=init, blit=True, interval=1, cache_frame_data=False)
print("Collecting data and plotting...")

# Show plot and collect data
plt.show()

# Close serial port
ser.close()

# Process data with HeartPy
if len(data) >= num_samples:
    try:
        data = np.array(data[:num_samples])  # Ensure exact number of samples
        working_data, measures = hp.process(data, sample_rate)
        bpm = measures['bpm']
        print(f"Calculated heart rate")
        if 60 <= bpm <= 100:
            print("Heart rate is at a healthy level.")
        else:
            print("Heart rate is not at a healthy level (too low or too high).")
    except Exception as e:
        print(f"Error processing data: {e}. Ensure good signal quality and try again.")
else:
    print("Not enough data collected. Check connections and try again.")