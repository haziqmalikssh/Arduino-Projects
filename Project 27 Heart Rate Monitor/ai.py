# ======================================
#  HEART RATE AI CLASSIFIER (All-in-One)
#  Collects data, trains model, predicts
#  Requires: heartpy, numpy, matplotlib,
#            scikit-learn, pandas, joblib
# ======================================

import serial
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import heartpy as hp
import pandas as pd
import joblib
import os
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# ----- SETTINGS -----
SERIAL_PORT = 'COM5'     # change to your Arduino port
BAUD_RATE = 9600
NUM_SAMPLES = 10000      # ~10s at 1000Hz
PLOT_WINDOW = 1000
SAMPLE_RATE = 1000.0
DATA_PATH = 'heart_data.csv'
MODEL_PATH = 'heart_model.pkl'
MIN_SAMPLES_TO_TRAIN = 20   # how many rows needed before training

# ----- SERIAL INIT -----
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
data, plot_data = [], []

# ----- LIVE PLOT -----
fig, ax = plt.subplots()
line, = ax.plot([], [])
ax.set_xlim(0, PLOT_WINDOW)
ax.set_ylim(0, 1024)
ax.set_xlabel('Sample')
ax.set_ylabel('ECG Signal (ADC Value)')
ax.set_title('Real-Time ECG Signal')

def init():
    line.set_data([], [])
    return (line,)

def update(frame):
    global plot_data
    try:
        line_data = ser.readline().decode('utf-8').strip()
        if line_data and line_data != '!':
            value = int(line_data)
            data.append(value)
            plot_data.append(value)
            if len(plot_data) > PLOT_WINDOW:
                plot_data.pop(0)
            line.set_data(range(len(plot_data)), plot_data)
            if len(data) >= NUM_SAMPLES:
                ani.event_source.stop()
        return (line,)
    except (ValueError, UnicodeDecodeError):
        return (line,)

print("Collecting ECG data from Arduino...")
ani = FuncAnimation(fig, update, init_func=init, blit=True, interval=1, cache_frame_data=False)
plt.show()
ser.close()

if len(data) < NUM_SAMPLES:
    print("Not enough data collected. Try again.")
    exit()

# ----- PROCESS ECG DATA -----
print("\nProcessing ECG data...")
try:
    data = np.array(data[:NUM_SAMPLES])
    working_data, measures = hp.process(data, SAMPLE_RATE)
except Exception as e:
    print(f"HeartPy processing failed: {e}")
    exit()

print("\nExtracted Features:")
for k, v in measures.items():
    if isinstance(v, (int, float)):
        print(f"{k}: {v:.2f}")

# ----- EXTRACT FEATURES -----
features = {
    'bpm': measures['bpm'],
    'ibi': measures['ibi_mean'],
    'sdnn': measures['sdnn'],
    'rmssd': measures['rmssd'],
    'pnn20': measures['pnn20'],
    'pnn50': measures['pnn50']
}

# ----- LABEL SAMPLE -----
label = int(input("\nLabel this sample (1 = Healthy, 0 = Unhealthy): "))
features['label'] = label

# ----- SAVE TO CSV -----
df = pd.DataFrame([features])
df.to_csv(DATA_PATH, mode='a', header=not os.path.exists(DATA_PATH), index=False)
print(f"Sample saved to {DATA_PATH}")

# ----- TRAIN MODEL IF ENOUGH DATA -----
df = pd.read_csv(DATA_PATH)
if len(df) >= MIN_SAMPLES_TO_TRAIN:
    print(f"\nTraining AI model on {len(df)} samples...")

    X = df[['bpm', 'ibi', 'sdnn', 'rmssd', 'pnn20', 'pnn50']]
    y = df['label']

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    model = RandomForestClassifier(n_estimators=100, random_state=42)
    model.fit(X_train, y_train)
    preds = model.predict(X_test)

    acc = accuracy_score(y_test, preds)
    joblib.dump(model, MODEL_PATH)
    print(f"✅ Model trained and saved ({MODEL_PATH}) with accuracy: {acc*100:.2f}%")
else:
    print(f"\nCollected {len(df)} samples so far. Need {MIN_SAMPLES_TO_TRAIN} before training a model.")

# ----- LOAD MODEL (if exists) -----
if os.path.exists(MODEL_PATH):
    model = joblib.load(MODEL_PATH)
    X_new = [[
        features['bpm'],
        features['ibi'],
        features['sdnn'],
        features['rmssd'],
        features['pnn20'],
        features['pnn50']
    ]]
    prediction = model.predict(X_new)[0]
    prob = model.predict_proba(X_new)[0][1]
    print("\n--- AI Classification ---")
    print(f"Prediction: {'HEALTHY ❤️' if prediction == 1 else 'UNHEALTHY ⚠️'}")
    print(f"Confidence: {prob*100:.1f}%")
else:
    print("\nNo model yet. Collect more samples to train automatically!")
