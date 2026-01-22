# DHT11 Sensor with LED Indicator

---

## Project Description
This Arduino project reads **temperature and humidity** from a DHT11 sensor and visually indicates the sensor's status using an LED. The system detects sensor failures using multiple checks, including **read errors** and **timeout detection**. The LED remains ON when the sensor is working and turns OFF if the sensor fails or does not respond for a defined period.

---

## Features
- Reads **temperature (°C)** and **humidity (%)** using a DHT11 sensor.  
- Detects temporary and long-term **sensor failures**.  
- Visual feedback via **LED**:  
  - LED ON → sensor operating correctly  
  - LED OFF → sensor failed or timeout occurred  
- Timeout logic: If the sensor does not respond for **10 seconds**, it is considered dead.  
- Robust against occasional read errors from DHT11.

---

## Components Needed
- Arduino board (Uno, Nano, etc.)  
- DHT11 temperature & humidity sensor (2-pin or 3-pin module)  
- LED (any color)  
- 220–330Ω resistor for LED  
- Breadboard and jumper wires

---
## Installation

1. Install **Arduino IDE**.  
2. Install the **Adafruit DHT library**:  
   - Arduino IDE → Sketch → Include Library → Manage Libraries...  
   - Search for `DHT sensor library by Adafruit` and install it.  
3. Connect the sensor and LED according to the wiring above.  
4. Upload the provided Arduino sketch.

---

## Usage

1. Open Serial Monitor at **9600 baud**.  
2. The console will display:  
   - Temperature in °C  
   - Humidity in %  
   - Sensor errors when reading fails  
3. LED behavior:  
   - ON → sensor working correctly  
   - OFF → sensor failed or timeout detected

---

## Arduino Sketch Overview
- **DHT11 read** every 2 seconds  
- **Error check**: Detects `NaN` values  
- **Timeout detection**: Marks sensor as dead if no valid reading for 10 seconds  
- **LED update**: Reflects sensor state; changes only on state transition to avoid flicker

---

## Optional Improvements
- Blink LED on temporary read errors  
- Store last N readings for moving average  
- Add buzzer or IoT alert when sensor fails  
- Support multiple sensors on the same Arduino
