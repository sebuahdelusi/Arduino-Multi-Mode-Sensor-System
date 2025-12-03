# Arduino Multi-Mode Sensor System

This project is an Arduino-based monitoring system that integrates Temperature and Ultrasonic sensors with an I2C LCD interface. It features an interrupt-based state machine allowing users to switch between different monitoring modes using a physical button or Serial commands.

## 📋 Features

* **Multi-State System:** 5 distinct modes of operation.
* **Interrupt Handling:** Uses hardware interrupts for responsive button inputs.
* **Visual Feedback:** RGB LED indicators change color based on the active mode.
* **Dual Control:** Mode switching available via Push Button or Serial Monitor.
* **Sensors:**
    * Distance measurement (Ultrasonic).
    * Temperature measurement (Analog).
* **Display:** 16x2 LCD via I2C communication.

## ⚙️ Functionality Modes

| Mode | Description | LED Color |
| :--- | :--- | :--- |
| **0** | **Identity/Idle:** Displays User Name & ID (Backlight Off). | Off |
| **1** | **Temperature:** Shows real-time temperature in °C. | 🔴 Red |
| **2** | **Distance:** Shows distance in cm. | 🟣 Purple (R+B) |
| **3** | **Dual View:** Shows both Temperature and Distance. | 🟡 Yellow (R+G) |
| **4** | **Demo:** Cycles through RGB colors and displays text. | Cycle (RGB) |

## 🔌 Hardware Pin Configuration

Based on the source code, connect your components to the following pins on the Arduino:

| Component | Pin / Type | Variable Name |
| :--- | :--- | :--- |
| **RGB LED (Red)** | Digital 11 | `ledR` |
| **RGB LED (Green)** | Digital 8 | `ledG` |
| **RGB LED (Blue)** | Digital 9 | `ledB` |
| **Ultrasonic Trig** | Digital 5 | `trig` |
| **Ultrasonic Echo** | Digital 4 | `echo` |
| **Push Button** | Digital 3 | `butt` (Interrupt) |
| **Temp Sensor** | Analog A0 | `tempPin` |
| **LCD (I2C)** | SDA/SCL | Address: `0x20` (32) |

*> **Note:** The Temperature calculation in the code `(volt - 0.5) * 100.0` suggests the use of a **TMP36** sensor. If using an LM35, you may need to adjust the formula.*

## 🚀 How to Use

1.  **Wiring:** Connect the components according to the table above.
2.  **Libraries:** Ensure you have the `LiquidCrystal_I2C` library installed in your Arduino IDE.
3.  **Upload:** Upload the `.ino` sketch to your Arduino board.
4.  **Controls:**
    * **Button:** Press the button connected to Pin 3 to cycle through modes (0-4).
    * **Serial Monitor:** Open Serial Monitor (Baud 9600) and type `0`, `1`, `2`, `3`, or `4` to jump to a specific mode immediately.
