# Embedded Project: Ultrasonic Distance Measurement System

## Introduction
The **Ultrasonic Distance Measurement System** is designed to accurately measure distances using the HC-SR04 ultrasonic sensor in conjunction with the **ATmega16 microcontroller**. This project involves creating drivers for various peripherals and utilizing libraries to streamline the functionality.

## Components Used
- HC-SR04 Ultrasonic Sensor
- ATmega16 Microcontroller
- 2x16 LCD Display
- Breadboard and Jumper Wires

## Required Drivers and Libraries
- **Drivers:**
  - `std_types` - Library for standard data types
  - `common_macros` - Macros for common operations
  
- **MCAL (Microcontroller Abstraction Layer):**
  - `GPIO` - Manages General Purpose Input/Output pins
  - `ICU` (Input Capture Unit) - Captures input signals
  - `Timer` - Manages time measurement and generation
  
- **HAL (Hardware Abstraction Layer):**
  - `Ultrasonic` - Abstraction for interfacing with the HC-SR04 sensor
  - `LCD` - Abstraction for interfacing with a 2x16 LCD display
  
## System Workflow
1. Initialize necessary peripherals including GPIO pins, ICU, Timers, and the 2x16 LCD display.
2. Set up the Ultrasonic HAL to interface with the HC-SR04 sensor.
3. Display user instructions on the LCD.
4. Continuously measure distance using the Ultrasonic sensor:
   - Trigger the sensor by sending a pulse from a GPIO pin.
   - Capture the rising edge of the echo signal using the ICU.
   - Calculate the time taken for the pulse to travel to the target object and back.
   - Convert the time to distance using the speed of sound.
   - Display the measured distance on the LCD.
5. Repeat the measurement process at regular intervals.

## Implementation Steps
1. Include necessary headers for the drivers and libraries.
2. Configure GPIO pins for trigger and echo.
3. Initialize ICU and Timer peripherals.
4. Set up the LCD display and initialize it using the LCD HAL.
5. Implement Ultrasonic HAL to control the sensor:
   - Trigger the sensor by sending a short pulse.
   - Capture the time of the rising edge using the ICU.
   - Calculate the time difference.
   - Convert time to distance.
6. Implement LCD HAL to display distance readings.
7. Set up a loop to continuously measure and display distance on the LCD.
8. Compile and upload the firmware to the ATmega16 microcontroller.

## proteus
<img src="Sim.png">

## Conclusion
The Ultrasonic Distance Measurement System effectively combines the HC-SR04 ultrasonic sensor, the ATmega16 microcontroller, and a 2x16 LCD display to accurately measure distances. By developing the necessary drivers and libraries, the microcontroller can proficiently interact with the sensor, capture signals, and exhibit results on the LCD screen.

For comprehensive project documentation and a deeper understanding, please refer to the project source files and documentation provided in the repository.
