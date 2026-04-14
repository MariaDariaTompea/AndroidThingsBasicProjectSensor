# Smart Parking Barrier System (Arduino Project)

## Overview

This project simulates a smart parking entrance barrier using an Arduino board, an infrared obstacle sensor, a servo motor, and LED indicators.

The system mimics a real parking gate:

* Green LED indicates that access is free (no car detected)
* Red LED indicates that a car is detected
* The servo motor controls the barrier position

---

## Circuit Diagram

<p align="center">
  <img src="circuit.png.png" width="500"/>
</p>

---

## Demonstration Video

<p align="center">
  <video width="500" controls>
    <source src="circuitvideo.mp4" type="video/mp4">
  </video>
</p>

---

## Components Used

* Arduino UNO
* Servo Motor (used as barrier mechanism)
* Infrared Obstacle Sensor (proximity detection)
* 2 LEDs:

  * Green LED (free access)
  * Red LED (car detected)
* Resistors (for LEDs protection)
* Breadboard
* Jumper wires

---

## System Behavior

### No Obstacle Detected

* Sensor output is HIGH (1)
* Green LED blinks
* Red LED is OFF
* Servo moves to the closed position (barrier down)

### Obstacle Detected (Car Present)

* Sensor output is LOW (0)
* Red LED turns ON
* Green LED turns OFF
* Servo rotates to open the barrier

---

## Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------- |
| Infrared Sensor | 7           |
| Green LED       | 2           |
| Red LED         | 4           |
| Servo Motor     | A1          |

---

## Code Explanation

### Libraries

* `Servo.h`
  Used to control the servo motor.

### Variables

* `senzor` – input pin for infrared sensor
* `verde` – green LED pin
* `rosu` – red LED pin
* `rot` – state variable to prevent repeated rotation

### Functions

#### `setup()`

* Initializes pins
* Attaches servo to pin A1
* Sets initial servo position (90 degrees)
* Starts serial communication

#### `Roteste_Dreapta()`

* Rotates the servo gradually from 0 to 180 degrees
* Simulates opening the barrier
* Executes only once per detection using the `rot` flag

#### `Roteste_Stanga()`

* Moves servo back to initial position (0 degrees)
* Simulates closing the barrier

#### `Aprinde_Verde()`

* Blinks the green LED to indicate free access

#### `loop()`

* Continuously reads sensor value
* If obstacle is detected:

  * Turns ON red LED
  * Opens barrier
* If no obstacle:

  * Turns ON green LED (blinking)
  * Closes barrier

---

## Notes

* The project uses an infrared obstacle sensor instead of an ultrasonic distance sensor.
* The sensor detects objects based on reflected infrared light.
* Designed and simulated in Tinkercad.

---

## Possible Improvements

* Replace IR sensor with ultrasonic sensor for more accurate distance measurement
* Add buzzer for sound alerts
* Add LCD display for status messages
* Implement automatic closing delay after car passes

---

## Author

Maria-Daria Tompea

---
