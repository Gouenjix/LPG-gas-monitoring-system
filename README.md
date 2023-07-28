# LPG-gas-monitoring-system

Continuous monitoring and alerting for LPG gas cylinder weight and leakage

## Description
The objective of the proposed LPG Gas Monitoring System is to continuously measure the weight of the gas cylinder and automatically send an alert to the user when it reaches the minimum threshold. The system uses a load cell and an Hx711 load cell amplifier to measure the cylinder's weight accurately. When the weight falls below the threshold, alerts are generated using a buzzer, LED light indicators, and mobile phone notifications via the ESP8266 (WIFI-Module).

Additionally, the system is equipped with an MQ4 gas sensor that detects LPG gases such as propane and butane. It can sense gas leakage (high LPG concentration in the air) and promptly alert the consumer with SMS, buzzer, and LCD display. This feature helps users take necessary actions to prevent accidents or mishaps due to gas leakage.

## Components Used
The following components were used in the project:

- Arduino Uno
- ESP8266 (WIFI-Module)
- Hx711 Load Cell Amplifier
- MQ4 Gas Sensor
- Strain Gauge-Load Cell
- LCD-16x2
- Buzzer

## Load Cell Calibration
Calibrating the load cell ensures accurate weight measurements. Follow these steps to calibrate the load cell:
- Place a known weight (e.g., 1 kg) on the load cell.
- Record the raw sensor value output by the Hx711 amplifier for this weight.
- Calculate the calibration factor using the following formula:
{ Calibration Factor = Known Weight / Raw Sensor Value }
- This factor will be used to convert raw sensor readings to actual weight values.
- Update the calibration factor in the Arduino sketch (`lpg_gas_monitoring_system.ino`) by setting the value of the `calibrationFactor` variable.

## Installation and Setup
To set up the LPG Gas Monitoring System, follow these steps:

### Hardware Connection

- Connect the load cell and Hx711 amplifier to the Arduino Uno to measure the gas cylinder's weight accurately.
- Connect the MQ4 gas sensor to the Arduino Uno for detecting LPG gas leakage.
- Connect the LCD-16x2, buzzer, and LED lights to the Arduino Uno for displaying alerts.
- Make sure all the connections are secure and correctly wired.

### Software Setup

- Install the Arduino IDE on your computer if you haven't already.
- Open the Arduino sketch file (lpg_gas_monitoring_system.ino) in the Arduino IDE.
- Upload the sketch to your Arduino Uno board.

### Threshold Configuration

- In the Arduino sketch, locate the variable thresholdWeight and set the minimum weight threshold for the gas cylinder.
- Adjust other parameters as needed, such as gas sensor sensitivity or alert timings.

### Power Up

- Power up the Arduino Uno and ensure the gas cylinder is placed on the load cell.
- The system will continuously monitor the weight and gas concentration.

### Alert and Notifications
- When the weight of the cylinder falls below the threshold, the buzzer will sound, LED lights will flash, and the ESP8266 module will send a mobile phone notification to the user via Wi-Fi.
- If gas leakage is detected, the buzzer will sound, and the LCD display will show a gas leakage alert.

## Result
The LPG Gas Monitoring System provides real-time monitoring of the gas cylinder weight and alerts the user when the weight reaches the minimum threshold. It also promptly detects gas leakage and notifies the user through various alert mechanisms. The system ensures safety and provides timely alerts to take necessary precautions, preventing accidents and potential hazards due to gas leakage.
