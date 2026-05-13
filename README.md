## Arduino Line Follower Robot

This project features a two-sensor **Line Follower Robot** powered by an Arduino. The robot uses infrared (IR) sensors to detect a dark line on a light surface (or vice versa) and adjusts its motors in real-time to stay on track. It includes logic for forward movement, directional correction, and an "in-place" pivot to handle sharp turns or line-loss scenarios.

<img width="6000" height="8000" alt="2" src="https://github.com/user-attachments/assets/dbd981f1-897e-4109-b7ea-3dd6cf3043a6" />
<img width="6000" height="8000" alt="3" src="https://github.com/user-attachments/assets/8d148665-89e3-4c8b-9752-188d85098a9f" />
<img width="6000" height="8000" alt="4" src="https://github.com/user-attachments/assets/c707e6f5-e85c-4653-ba9f-84a2138edcc4" />
<img width="6000" height="8000" alt="5" src="https://github.com/user-attachments/assets/3309aaad-7839-48f1-88e6-c0921917c3a7" />
<img width="6000" height="8000" alt="1" src="https://github.com/user-attachments/assets/fcd45568-e16c-4656-b215-d88473f1c3ae" />



## Hardware Components

To build this project, you will need:

* **Microcontroller:** Arduino Uno (or compatible)
* **Motor Driver:** L298N Dual H-Bridge
* **Sensors:** 2x IR Line Tracking Sensors
* **Chassis:** 2WD Robot Chassis kit
* **Power:** 7.4V - 12V Li-ion battery or AA battery pack

## Pin Mapping

| Component | Arduino Pin | Description |
| --- | --- | --- |
| **Right Sensor** | 2 | IR Digital Input |
| **Left Sensor** | 3 | IR Digital Input |
| **Motor A (Left) IN1** | 8 | Direction Control |
| **Motor A (Left) IN2** | 7 | Direction Control |
| **Motor B (Right) IN3** | 6 | Direction Control |
| **Motor B (Right) IN4** | 5 | Direction Control |
| **ENA** | 9 | PWM Speed Control (Left) |
| **ENB** | 10 | PWM Speed Control (Right) |

## Logic Flow

The robot operates based on four primary states determined by the IR sensors:

1. **Both Sensors on White (0, 0):** The line is centered between the sensors. The robot moves **Forward**.
2. **Left Sensor on Black (0, 1):** The robot has drifted right. It initiates a **Left Turn** to correct.
3. **Right Sensor on Black (1, 0):** The robot has drifted left. It initiates a **Right Turn** to correct.
4. **Both Sensors on Black (1, 1):** Often interpreted as a junction or line loss. The robot **stops**, performs a **Pivot Right**, and attempts to re-acquire the line.

> **Note:** The `speedMotor` variable is set to **130** (out of 255). You can adjust this value in the code to find the balance between speed and tracking accuracy.

## Setup & Installation

1. **Wiring:** Connect your components according to the Pin Mapping table above.
2. **Calibration:** Use a screwdriver to adjust the sensitivity potentiometers on your IR sensors so they reliably trigger on your specific track surface.
3. **Upload:**
* Open the `.ino` file in the Arduino IDE.
* Select your board and port.
* Click **Upload**.


## Functions Overview

* `moveForward()`: Drives both motors forward at the defined speed.
* `turnLeft()` / `turnRight()`: Slows down one motor while reversing the other slightly for a smooth steering motion.
* `turnRightInPlace()`: Reverses one motor and drives the other forward for a tight 360-degree capable pivot.
* `stopMotors()`: Cuts power to all motor pins.

---

### ## Future Improvements

* **PID Control:** Implementing a PID algorithm for smoother, non-jittery movement.
* **Speed Ramping:** Gradually increasing speed to prevent wheel slippage.
* **Obstacle Avoidance:** Adding an Ultrasonic sensor to stop the robot if an object is in the path.
